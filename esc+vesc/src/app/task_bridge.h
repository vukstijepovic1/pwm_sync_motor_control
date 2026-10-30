/**
 * @file    template.h
 * @brief   Library used as template.
 * @version	x.y.z
 * @date    xx.yy.zzzz
 * @author  LisumLab
 */

#ifndef TASK_BRIDGE_H
#define TASK_BRIDGE_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <stdint.h>
#include <stdbool.h>
#include "types.h"

/* Middleware */
#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"

/*******************************************************************************
 * Defines
 ******************************************************************************/
#define KDE_MAX_ESC 3
#define VESC_MAX_VESC 8
/*******************************************************************************
 * Typedefs
 ******************************************************************************/

typedef struct{
    /* --- Interface --- */
    uint8_t vesc_id;
    bool active;

    /* --- Status values populated by request_vesc_status_X() --- */
    float duty;
    float currtot;
    float erpm;
    float ah;
    float ahc;
    float wh;
    float whc;
    float currin;
    float tempfet;
    float tempmotor;
    float pos;
    float tacho;
    float vin;
    float adc1;
    float adc2;
    float adc3;
    float ppm;

    /* --- Outgoing CAN message structs --- */
    mavlink_lisum_vesc_status_1_t msg_1;
    mavlink_lisum_vesc_status_2_t msg_2;
    mavlink_lisum_vesc_status_3_t msg_3;
    mavlink_lisum_vesc_status_4_t msg_4;
    mavlink_lisum_vesc_status_5_t msg_5;
    mavlink_lisum_vesc_status_6_t msg_6;

    /* --- Per-instance queue handles (all fed into the shared queueset_status
     *     that task_mav waits on) --- */
    QueueHandle_t queue_status_1;
    QueueHandle_t queue_status_2;
    QueueHandle_t queue_status_3;
    QueueHandle_t queue_status_4;
    QueueHandle_t queue_status_5;
    QueueHandle_t queue_status_6;

}vesc_instance_t;

typedef struct{
    float voltage;
    float current;
    float rpm;
    uint8_t warnning;
    uint8_t temp;
}base_state_t;

/* Arm state machine. Status polling (kde_get_base_stat) runs in every state
 * except ESC_ARM_STATE_ARMING - during the arm sequence the ESCs get no
 * status requests, only the uninterrupted minimum-throttle stream. */
typedef enum{
    ESC_ARM_STATE_DISARM = 0,
    ESC_ARM_STATE_ARMING,
    ESC_ARM_STATE_ARM,
}esc_arm_state_t;

typedef struct{
    /*Interface*/
    uint8_t esc_id;
    bool activate;

    /* Status values */
    float voltage;
    float current;
    float rpm;
    uint8_t warning;
    uint8_t temp;
    uint16_t throttle;

    /* Raw readbacks of objects 6 (THROTTLE_IN) and 7 (THROTTLE_OUT): what
     * the ESC itself reads on its throttle input and drives out. Debug only,
     * forwarded as NAMED_VALUE_INT by task_mav. */
    uint16_t pwm_in;
    uint16_t pwm_out;

    /* Outgoing CAN message structs */
    base_state_t msg_1;
    uint16_t     msg_2;

    /* queue handles (fed into the shared queueset_status task_mav waits on) */
    QueueHandle_t queue_status_1;
    QueueHandle_t queue_status_2;

}esc_instance_t;

extern esc_instance_t  esc_fleet[KDE_MAX_ESC];
extern vesc_instance_t vesc_fleet[VESC_MAX_VESC];

/* Every active KDE/VESC per-instance status queue is a member of this set.
 * task_bridge fills the queues on CAN RX; task_mav selects from the set and
 * forwards each update as a MAVLink message over UDP. */
extern QueueSetHandle_t queueset_status;

/*******************************************************************************
 * API
 ******************************************************************************/

/* Create queueset_status. Call from main() before the scheduler starts and
 * before task_bridge's init_esc_fleet()/init_vesc_fleet() run. */
void init_status_queueset(void);

void init_esc_fleet(void);

void init_vesc_fleet(void);

void task_bridge(void *arg);

/* Current arm state machine state (see esc_arm_state_t). */
esc_arm_state_t bridge_arm_state(void);

#ifdef __cplusplus
}
#endif

#endif /* TASK_BRIDGE_H */