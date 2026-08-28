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

/* HAL Drivers */
#include "timer.h"
#include "kde.h"
#include "kde_helper.h"

/* Middleware */
#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"


extern SemaphoreHandle_t mutex_mav;

// Queues
extern QueueHandle_t queue_comm;
extern QueueHandle_t queue_resp;
extern QueueHandle_t queue_mav_hb;
extern QueueHandle_t queue_esc_rx;

// QueueSets
extern QueueSetHandle_t queueset_mav;

// Handlers
extern TaskHandle_t xTaskBridgeHandle;

extern SemaphoreHandle_t mutex_mav;

/*******************************************************************************
 * Defines
 ******************************************************************************/

/*******************************************************************************
 * Typedefs
 ******************************************************************************/


/*******************************************************************************
 * Variables
 ******************************************************************************/

static uint32_t esc_rx_lost_cnt = 0;

extern QueueHandle_t queue_esc_rx;

esc_instance_t esc_fleet[KDE_MAX_ESC]={
    {.esc_id = 2, .activate = true},
    {.esc_id = 3, .activate = true},
    {.esc_id = 4, .activate = true},
    {.esc_id = 5, .activate = true},
};

// Static Messages
static lStatus_t s;

uint8_t resp_id = 0;

esc_comm_msg_t resp_msg;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

void  timer_100hz_cb(tim_hal_ch_t ch, tim_hal_int_type_t type);

static inline lStatus_t ProcessComm(esc_comm_msg_t *cmd);

static inline lStatus_t ReSendResp(esc_comm_msg_t *cmd);

static esc_instance_t *find_esc(uint8_t id);



/*******************************************************************************
 * Code
 ******************************************************************************/

void task_bridge(void *arg){

    esc_comm_msg_t  cmd;
    can_hal_msg_t   rx;

    for(;;){
        if(xQueueReceive(queue_comm, &cmd, 0) == pdPASS){

            s = ProcessComm(&cmd);
            if(s == lStatus_Success) ReSendResp(&cmd);
        }

        if(xQueueReceive(queue_esc_rx, &rx, 0) == pdPASS){
            /* KDE extended ID: [SRC:8][DST:8][OBJ:8]*/
   
            if (GET_DST(rx.messageId) != MINE_CAN_ID) continue;
            uint8_t obj = GET_OBJ(rx.messageId);
            uint8_t id  = GET_SRC(rx.messageId);

            esc_instance_t *v = find_esc(id);

            if(!v) continue;

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
                    v->msg_2    = v->throttle;
                    xQueueSend(v->queue_status_2, &v->msg_2, 0);
                    break;

                case CAN_OBJECT_GET_THROTTLE_IN:
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

/****************************** static functions ******************************/

__attribute__((always_inline))
static inline lStatus_t ProcessComm(esc_comm_msg_t *cmd){


    switch (cmd->obj_id){

        case CAN_OBJECT_SET_PWM:
            return kde_set_pwm(cmd->esc_id, (int16_t)cmd->comm_phar);

        case CAN_OBJECT_SET_DIRECTION:
            return kde_set_direction(cmd->esc_id, (uint8_t)cmd->comm_phar);

        case CAN_OBJECT_TURN_OFF:
            return kde_shutdown(cmd->esc_id);

        case CAN_OBJECT_RESTART:
            return kde_reset(cmd->esc_id);

        case CAN_OBJECT_START_ENUM:
            return kde_start_enum((uint16_t)cmd->comm_phar);

        default:
            return lStatus_Fail;
    }
}

//
__attribute__((always_inline))
static inline lStatus_t ReSendResp(esc_comm_msg_t *cmd){
    switch (cmd->obj_id){

        case CAN_OBJECT_SET_PWM:
        case CAN_OBJECT_SET_DIRECTION:
        case CAN_OBJECT_TURN_OFF:
        case CAN_OBJECT_RESTART:
        case CAN_OBJECT_START_ENUM:
            return lStatus_Success;

        default:
            return lStatus_Fail;
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


/****************************** global functions ******************************/

void init_esc_fleet(void){
    for(int i = 0; i<KDE_MAX_ESC; i++){
        esc_instance_t *v = &esc_fleet[i];
        if (!v->activate) continue;

        memset(&v-> msg_1, 0, sizeof(v-> msg_1));
        memset(&v-> msg_2, 0, sizeof(v-> msg_2));

        v->queue_status_1 = xQueueCreate(15, sizeof(v->msg_1));
        v->queue_status_2 = xQueueCreate(15, sizeof(v->msg_2));

        v->queueset = xQueueCreateSet(40);

        xQueueAddToSet(v->queue_status_1, v->queueset);
        xQueueAddToSet(v->queue_status_2, v->queueset);
    }
}

/********************************** callbacks *********************************/

void kdecan_cb(void *usr_arg, int32_t int_status){
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

/********************************* End Of File ********************************/