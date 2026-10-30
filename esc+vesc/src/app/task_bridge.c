/**
 * @file    template.c
 * @brief   Library used as template.
 * @version	x.y.z
 * @date    xx.yy.zzzz
 * @author  LisumLab
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "task_bridge.h"
#include "task_work.h"
#include "types.h"
#include <string.h>

/* HAL Drivers */
#include "timer.h"
#include "kde.h"
#include "kde_helper.h"
#include "vesc.h"
#include "vesc_helper.h"

/* Middleware */
#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"

// Queues
extern QueueHandle_t queue_cmd;
extern QueueHandle_t queue_vesc_cmd;
extern QueueHandle_t queue_resp;
extern QueueHandle_t queue_mav_hb;
extern QueueHandle_t queue_esc_rx;
extern QueueHandle_t queue_vesc_rx;

// Handlers
extern TaskHandle_t xTaskBridgeHandle;

/*******************************************************************************
 * Defines
 ******************************************************************************/

/* Timer instance used to pace the periodic ESC status poll (TIMER0 is taken
 * by HAL_DevTimeInit). */
#define BRIDGE_STATUS_TIM_INSTANCE TIM_HAL_INSTANCE_1

/* Status poll period [us] -> 100 ms = 10 Hz. The KDECAN protocol documents
 * object 11 (GET_BASE_STAT) as a 10 Hz telemetry item, which is also what
 * ArduPilot's AP_KDECAN uses. Polling at 100 Hz only multiplied CAN load and
 * the outgoing UDP status stream. */
#define BRIDGE_STATUS_PERIOD_US 100000U

/* Depth of every per-instance status queue (kept in one place so the shared
 * queue set can be sized to match). */
#define STATUS_Q_LEN 15U

/* VESC that follows every KDE SET_PWM with a proportional duty cycle:
 * KDE_MINIMUM_PWM -> 0, VESC_MIRROR_PWM_MAX -> VESC_MIRROR_MAX_DUTY. */
#define VESC_MIRROR_ID          58
#define VESC_MIRROR_PWM_MAX     1900    /* same upper bound task_mav accepts */
#define VESC_MIRROR_MAX_DUTY    0.95f   /* VESC's default l_max_duty */

/*******************************************************************************
 * Variables
 ******************************************************************************/

static uint32_t esc_rx_lost_cnt = 0;

static uint32_t vesc_rx_lost_cnt = 0;

/* Arm state machine. Starts disarmed; the status poll below skips the
 * status requests while this is ESC_ARM_STATE_ARMING. */
static esc_arm_state_t arm_state = ESC_ARM_STATE_DISARM;

extern QueueHandle_t queue_esc_rx;

esc_instance_t esc_fleet[KDE_MAX_ESC]={
    {.esc_id = 2, .activate = true},
    {.esc_id = 3, .activate = true},
    {.esc_id = 4, .activate = true},
};

/* Shared queue set: every active KDE/VESC per-instance status queue is a member.
 * Created in task_bridge() before the fleets are initialised, drained by
 * task_mav. */
QueueSetHandle_t queueset_status;

/* Instance every device */
vesc_instance_t vesc_fleet[VESC_MAX_VESC]={
    { .vesc_id = 58,  .active = true },
    { .vesc_id = 59,  .active = false },
    { .vesc_id = 60,  .active = false },
    { .vesc_id = 61,  .active = false },    
    { .vesc_id = 124, .active = false },
    { .vesc_id = 125, .active = false },
    { .vesc_id = 126, .active = false },
    { .vesc_id = 127, .active = false },  
};

/* --- debug counters for the arm path (see task_mav.c for the link side) --- */
volatile uint32_t dbg_arm_req    = 0;   /* CAN_OBJECT_ARM reached ProcessCmd */
volatile uint32_t dbg_arm_busy   = 0;   /* rejected: arm_state was not DISARM */
volatile uint32_t dbg_arm_done   = 0;   /* kde_arm_all()/kde_arming() returned */
volatile int32_t  dbg_arm_status = -1;  /* ...with this lStatus_t             */

// Static Messages
static lStatus_t s;

uint8_t resp_id = 0;

esc_comm_msg_t resp_msg;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

void  timer_status_cb(tim_hal_ch_t ch, tim_hal_int_type_t type);

static void bridge_status_timer_init(void);

static inline lStatus_t ProcessCmd(esc_comm_msg_t *cmd);

static inline lStatus_t ProcessCommand(vesc_command_message_t *cmd);

static inline void ReSendResp(esc_comm_msg_t *cmd, lStatus_t status);

static esc_instance_t *find_esc(uint8_t id);

static vesc_instance_t *find_vesc(uint8_t id);

static float pwm_to_vesc_duty(float pwm);

/*******************************************************************************
 * Code
 ******************************************************************************/

void task_bridge(void *arg){

    esc_comm_msg_t         cmd;
    vesc_command_message_t vcmd;
    can_hal_msg_t          rx;

    /* allocate per-ESC status queues before the poll timer can fire
     * (queueset_status is created in main() before the scheduler starts) */
    init_esc_fleet();

    /* allocate per-VESC status queues before the poll timer can fire */
    init_vesc_fleet();

    /* start the status-poll tick */
    bridge_status_timer_init();

    for(;;){
        /* Tick from timer_status_cb: request base status from every
         * active ESC. Replies arrive asynchronously on queue_esc_rx below. */
        if(ulTaskNotifyTake(pdTRUE, 0) > 0){
            /* Poll in every state except ARMING, so nothing on the bus
             * competes with the idle stream during the arm sequence.
             * Polling only once armed meant a lost or failed ARM command
             * left the KDE telemetry silent until the next successful arm. */
            if(arm_state != ESC_ARM_STATE_ARMING){
                /* One object per tick, rotating (base stat / throttle in /
                 * throttle out), so a tick never queues more frames than the
                 * CAN controller's 3 TX buffers hold. */
                static uint8_t poll_obj = 0;

                for(int i = 0; i < KDE_MAX_ESC; i++){
                    if(!esc_fleet[i].activate) continue;

                    switch(poll_obj){
                        case 0:  kde_get_base_stat(esc_fleet[i].esc_id);    break;
                        case 1:  kde_get_throttle_in(esc_fleet[i].esc_id);  break;
                        default: kde_get_throttle_out(esc_fleet[i].esc_id); break;
                    }
                }
                poll_obj = (poll_obj + 1) % 3;
            }
        }

        if(xQueueReceive(queue_cmd, &cmd, 0) == pdPASS){
            s = ProcessCmd(&cmd);
            ReSendResp(&cmd, s);
        }

        if(xQueueReceive(queue_vesc_cmd, &vcmd, 0) == pdPASS){
            ProcessCommand(&vcmd);
        }

        if(xQueueReceive(queue_esc_rx, &rx, 0) == pdPASS){
            /* KDE extended ID: [SRC:8][DST:8][OBJ:8] */
            if(GET_DST(rx.messageId) == MINE_CAN_ID){

                uint8_t obj = GET_OBJ(rx.messageId);
                uint8_t id  = GET_SRC(rx.messageId);

                esc_instance_t *v = find_esc(id);
                if(v){

                    /* Payload byte order mirrors what kde.c used to parse inline. */
                    switch (obj){

                        case CAN_OBJECT_GET_BASE_STAT: {
                            uint16_t raw_v = ((uint16_t)rx.data[0] << 8) | rx.data[1];
                            uint16_t raw_c = ((uint16_t)rx.data[2] << 8) | rx.data[3];
                            uint16_t raw_s = ((uint16_t)rx.data[4] << 8) | rx.data[5];

                            v->msg_1.voltage  = (float)raw_v / 100.0f;
                            v->msg_1.current  = (float)raw_c / 100.0f;
                            v->msg_1.rpm      = (float)raw_s * 120.0f / KDE_MOTOR_POLES_NUMBER;
                            v->msg_1.temp     = rx.data[6];
                            v->msg_1.warnning = rx.data[7];

                            v->voltage = v->msg_1.voltage;
                            v->current = v->msg_1.current;
                            v->rpm     = v->msg_1.rpm;
                            v->temp    = rx.data[6];
                            v->warning = rx.data[7];

                            xQueueSend(v->queue_status_1, &v->msg_1, 0);
                            break;
                        }

                        case CAN_OBJECT_GET_THROTTLE_OUT:
                            v->throttle = rx.data[0];
                            v->pwm_out  = (rx.length >= 2)
                                        ? (((uint16_t)rx.data[0] << 8) | rx.data[1])
                                        : rx.data[0];
                            v->msg_2    = v->throttle;
                            xQueueSend(v->queue_status_2, &v->msg_2, 0);
                            break;

                        case CAN_OBJECT_GET_THROTTLE_IN:
                            v->pwm_in = (rx.length >= 2)
                                      ? (((uint16_t)rx.data[0] << 8) | rx.data[1])
                                      : rx.data[0];
                            break;

                        case CAN_OBJECT_GET_VOLTAGE:
                            v->voltage = (float)(((uint16_t)rx.data[0] << 8) | rx.data[1]) / 100.0f;
                            break;

                        case CAN_OBJECT_GET_CURRENT:
                            v->current = (float)(((uint16_t)rx.data[0] << 8) | rx.data[1]) / 100.0f;
                            break;

                        case CAN_OBJECT_GET_RPM: {
                            uint16_t raw = ((uint16_t)rx.data[0] << 8) | rx.data[1];
                            v->rpm = (float)raw * 120.0f / KDE_MOTOR_POLES_NUMBER;
                            break;
                        }

                        case CAN_OBJECT_GET_TEMP:
                            v->temp = rx.data[0];
                            break;

                        default: break;
                    }
                }
            }
        }

        if (xQueueReceive(queue_vesc_rx, &rx, 0)==pdPASS) {
            uint8_t command = (rx.messageId >> 8) & 0xFF;
            uint8_t vesc_id = rx.messageId & 0xFF;

            vesc_instance_t *v = find_vesc(vesc_id);
            if (!v) continue;

            switch (command)
            {
                case CAN_PACKET_STATUS:
                    parse_vesc_status_1_from_mav(&rx, &v->msg_1);
                    v->msg_1.vesc_id = vesc_id;
                    xQueueSend(v->queue_status_1, &v->msg_1, 0);
                    break;

                case CAN_PACKET_STATUS_2:
                    parse_vesc_status_2_from_mav(&rx, &v->msg_2);
                    v->msg_2.vesc_id = vesc_id;
                    xQueueSend(v->queue_status_2, &v->msg_2, 0);
                    break;

                case CAN_PACKET_STATUS_3:
                    parse_vesc_status_3_from_mav(&rx, &v->msg_3);
                    v->msg_3.vesc_id = vesc_id;
                    xQueueSend(v->queue_status_3, &v->msg_3, 0);
                    break;

                case CAN_PACKET_STATUS_4:
                    parse_vesc_status_4_from_mav(&rx, &v->msg_4);
                    v->msg_4.vesc_id = vesc_id;
                    xQueueSend(v->queue_status_4, &v->msg_4, 0);
                    break;

                case CAN_PACKET_STATUS_5:
                    parse_vesc_status_5_from_mav(&rx, &v->msg_5);
                    v->msg_5.vesc_id = vesc_id;
                    xQueueSend(v->queue_status_5, &v->msg_5, 0);
                    break;

                case CAN_PACKET_STATUS_6: {
                    parse_vesc_status_6_from_mav(&rx, &v->msg_6);
                    v->msg_6.vesc_id = vesc_id;
                    xQueueSend(v->queue_status_6, &v->msg_6, 0);
                    break;
                }
                default:
                    break;
            }
        }


        vTaskDelay(pdMS_TO_TICKS(1));
    }
}

/****************************** static functions ******************************/

__attribute__((always_inline))
static inline lStatus_t ProcessCmd(esc_comm_msg_t *cmd){


    switch (cmd->obj_id){

        case CAN_OBJECT_SET_PWM: {
            lStatus_t pwm = kde_set_pwm(cmd->esc_id, (int16_t)cmd->comm_phar);
            vesc_set_duty(VESC_MIRROR_ID, pwm_to_vesc_duty(cmd->comm_phar));
            return pwm;
        }

        case CAN_OBJECT_SET_DIRECTION:
            return kde_set_direction(cmd->esc_id, (uint8_t)cmd->comm_phar);

        case CAN_OBJECT_TURN_OFF: {
            lStatus_t off;

            if(cmd->esc_id == KDE_BROADCAST_ID){
                
                off = lStatus_Success;
                for(int i = 0; i < KDE_MAX_ESC; i++){
                    lStatus_t r;
                    if(!esc_fleet[i].activate) continue;
                    r = kde_shutdown(esc_fleet[i].esc_id);
                    if(r != lStatus_Success) off = r;
                }
            } else {
                off = kde_shutdown(cmd->esc_id);
            }
            vesc_set_duty(VESC_MIRROR_ID, 0.0f);

            if(off == lStatus_Success) arm_state = ESC_ARM_STATE_DISARM;
            return off;
        }

        case CAN_OBJECT_RESTART:
            return kde_reset(cmd->esc_id);

        case CAN_OBJECT_START_ENUM:
            return kde_start_enum((uint16_t)cmd->comm_phar);

        /* NOTE: the arm sequence keeps this task inside ProcessCmd for its
         * whole duration (~5 s: 2 s restart settle + 3 s idle hold). It
         * sleeps between frames (vTaskDelay via
         * local_delay_ms), so task_work/task_mav keep running, but
         * queue_esc_rx is not drained and the status poll is held off.
         * Acceptable for a deliberate arm command.
         *
         * esc_id == KDE_BROADCAST_ID arms the whole fleet; any other id arms
         * only that single ESC. */
        case CAN_OBJECT_ARM: {
            lStatus_t arm;

            dbg_arm_req++;

            if(arm_state == ESC_ARM_STATE_ARMING){
                dbg_arm_busy++;
                return lStatus_Busy;
            }

            arm_state = ESC_ARM_STATE_ARMING;

            /* Broadcast id arms every ESC that has a PWM channel mapped;
             * any other id arms just that one. A single pass: arming the
             * broadcast id and then ESC 2 again took ~10 s, long enough for
             * the ground station to give up on the ACK and re-send ARM. */
            arm = (cmd->esc_id == KDE_BROADCAST_ID) ? kde_arm_all()
                                                    : kde_arming(cmd->esc_id);

            dbg_arm_status = (int32_t)arm;
            dbg_arm_done++;

            arm_state = (arm == lStatus_Success) ? ESC_ARM_STATE_ARM
                                                 : ESC_ARM_STATE_DISARM;
            return arm;
        }

        default:
            return lStatus_Fail;
    }
}

/* Bridge a single ground-station VESC command onto the VESC CAN bus. */
__attribute__((always_inline))
static inline lStatus_t ProcessCommand(vesc_command_message_t *cmd){

    switch(cmd->command_id){

        case CAN_PACKET_SET_DUTY:
            return vesc_set_duty(cmd->vesc_id, cmd->command_param);

        case CAN_PACKET_SET_CURRENT:
            return vesc_set_current(cmd->vesc_id, cmd->command_param);

        case CAN_PACKET_SET_CURRENT_BRAKE:
            return vesc_set_current_brake(cmd->vesc_id, cmd->command_param);

        case CAN_PACKET_SET_RPM:
            return vesc_set_rpm(cmd->vesc_id, cmd->command_param);

        case CAN_PACKET_SET_POS:
            return vesc_set_pos(cmd->vesc_id, cmd->command_param);

        case CAN_PACKET_PING: {
            uint8_t response_id = 0;
            return vesc_ping(cmd->vesc_id, MINE_CAN_ID, &response_id);
        }

        default:
            return lStatus_Fail;
    }
}

/* Hand the result of a ground-station command to task_mav, which answers
 * with a COMMAND_ACK. Sent for failures too, so the ground station can tell
 * a rejected arm from a lost one. SET_PWM is deliberately not acknowledged:
 * it streams at 50+ Hz per ESC and an ACK for each would flood the link. */
__attribute__((always_inline))
static inline void ReSendResp(esc_comm_msg_t *cmd, lStatus_t status){
    esc_comm_resp_t resp;

    switch (cmd->obj_id){

        case CAN_OBJECT_SET_DIRECTION:
        case CAN_OBJECT_TURN_OFF:
        case CAN_OBJECT_ARM:
            resp.cmd    = *cmd;
            resp.status = status;
            xQueueSend(queue_resp, &resp, 0);
            break;

        default:
            break;
    }
}

static esc_instance_t *find_esc(uint8_t id){

    for(int i = 0; i< KDE_MAX_ESC; i++){
        if(esc_fleet[i].activate && esc_fleet[i].esc_id == id){
            return &esc_fleet[i];
        }
    }
    return NULL;
}

static vesc_instance_t *find_vesc(uint8_t id){
    for (int i = 0; i < VESC_MAX_VESC; i++) {
        if (vesc_fleet[i].active && vesc_fleet[i].vesc_id == id) {
            return &vesc_fleet[i];
        }
    }
    return NULL;
}

/* KDE throttle [us] -> VESC duty, linear and clamped to [0, max duty]. */
static float pwm_to_vesc_duty(float pwm){
    float duty = (pwm - KDE_MINIMUM_PWM) * VESC_MIRROR_MAX_DUTY
               / (VESC_MIRROR_PWM_MAX - KDE_MINIMUM_PWM);

    if(duty < 0.0f)                 duty = 0.0f;
    if(duty > VESC_MIRROR_MAX_DUTY) duty = VESC_MIRROR_MAX_DUTY;
    return duty;
}

static void bridge_status_timer_init(void){
    tim_hal_cfg_t tim_cfg = {
        .Prescale      = TIM_HAL_PRESCALE_US,
        .PrescaleValue = 1,
    };
    tim_hal_match_cfg_t match_cfg = {
        .MatchChannel = TIM_HAL_CH_0,
        .MatchValue   = BRIDGE_STATUS_PERIOD_US,
        .StopOnMatch  = lFunctionalState_Disable,
        .ResetOnMatch = lFunctionalState_Enable,
    };

    HAL_TIM_Init(BRIDGE_STATUS_TIM_INSTANCE, &tim_cfg);
    HAL_TIM_MatchCfg(BRIDGE_STATUS_TIM_INSTANCE, &match_cfg);
    HAL_TIM_EnableInterrupt(BRIDGE_STATUS_TIM_INSTANCE, timer_status_cb);
}

void init_status_queueset(void){
    uint32_t len = 0;

    for(int i = 0; i < KDE_MAX_ESC; i++)
        if(esc_fleet[i].activate)
            len += STATUS_Q_LEN * 2;        /* base stat + throttle */

    for(int i = 0; i < VESC_MAX_VESC; i++)
        if(vesc_fleet[i].active)
            len += STATUS_Q_LEN * 6;        /* status 1..6 */

    queueset_status = xQueueCreateSet(len);
}

void init_vesc_fleet(void){
    for(int i = 0 ;i < VESC_MAX_VESC;i++){
        vesc_instance_t *v= &vesc_fleet[i];

        if (!v->active){
            continue;
        }

        /* Clear all message structs */
        memset(&v->msg_1, 0, sizeof(v->msg_1));
        memset(&v->msg_2, 0, sizeof(v->msg_2));
        memset(&v->msg_3, 0, sizeof(v->msg_3));
        memset(&v->msg_4, 0, sizeof(v->msg_4));
        memset(&v->msg_5, 0, sizeof(v->msg_5));
        memset(&v->msg_6, 0, sizeof(v->msg_6));

        /* Create a dedicated queue for each status message type */
        v->queue_status_1 = xQueueCreate(STATUS_Q_LEN, sizeof(v->msg_1));
        v->queue_status_2 = xQueueCreate(STATUS_Q_LEN, sizeof(v->msg_2));
        v->queue_status_3 = xQueueCreate(STATUS_Q_LEN, sizeof(v->msg_3));
        v->queue_status_4 = xQueueCreate(STATUS_Q_LEN, sizeof(v->msg_4));
        v->queue_status_5 = xQueueCreate(STATUS_Q_LEN, sizeof(v->msg_5));
        v->queue_status_6 = xQueueCreate(STATUS_Q_LEN, sizeof(v->msg_6));

        xQueueAddToSet(v->queue_status_1, queueset_status);
        xQueueAddToSet(v->queue_status_2, queueset_status);
        xQueueAddToSet(v->queue_status_3, queueset_status);
        xQueueAddToSet(v->queue_status_4, queueset_status);
        xQueueAddToSet(v->queue_status_5, queueset_status);
        xQueueAddToSet(v->queue_status_6, queueset_status);
    }
}
/****************************** global functions ******************************/

esc_arm_state_t bridge_arm_state(void){
    return arm_state;
}

void init_esc_fleet(void){
    for(int i = 0; i<KDE_MAX_ESC; i++){
        esc_instance_t *v = &esc_fleet[i];
        if (!v->activate) continue;

        memset(&v-> msg_1, 0, sizeof(v-> msg_1));
        memset(&v-> msg_2, 0, sizeof(v-> msg_2));

        v->queue_status_1 = xQueueCreate(STATUS_Q_LEN, sizeof(v->msg_1));
        v->queue_status_2 = xQueueCreate(STATUS_Q_LEN, sizeof(v->msg_2));

        xQueueAddToSet(v->queue_status_1, queueset_status);
        xQueueAddToSet(v->queue_status_2, queueset_status);
    }
}

/********************************** callbacks *********************************/

void timer_status_cb(tim_hal_ch_t ch, tim_hal_int_type_t type){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    (void)ch;
    (void)type;

    /* wake task_bridge to issue the status requests outside ISR context */
    vTaskNotifyGiveFromISR(xTaskBridgeHandle, &xHigherPriorityTaskWoken);

    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

void kdecan_cb(void *usr_arg, uint32_t int_status){
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    if(int_status & CAN_HAL_INT_MASK_RI) {
        can_hal_msg_t rx;

        while(HAL_CAN_ReceiveMessage(
            KDE_CAN_HAL_INSTANCE, &rx, 0) == lStatus_Success){
            if(xQueueSendFromISR(
                queue_esc_rx, &rx, &xHigherPriorityTaskWoken) != pdPASS){
                esc_rx_lost_cnt ++;
            }
        }
    }

    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

void vesccan_cb(void* usr_arg, uint32_t int_status)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    
    if (int_status & CAN_HAL_INT_MASK_RI) {
        can_hal_msg_t rx;
        
        while (HAL_CAN_ReceiveMessage(
            VESC_CAN_HAL_INSTANCE, &rx, 0) == lStatus_Success) {
            if (xQueueSendFromISR(
                queue_vesc_rx, &rx, &xHigherPriorityTaskWoken) != pdPASS){
                vesc_rx_lost_cnt++;
            }
        }
    }
    
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}


/********************************* End Of File ********************************/