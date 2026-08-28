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
#include "types.h"
#include "kde.h"

/* Middleware */
#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"

/*******************************************************************************
 * Defines
 ******************************************************************************/

/*******************************************************************************
 * Typedefs
 ******************************************************************************/

typedef struct{
    float voltage;
    float current;
    float rpm;
    uint8_t warnning;
    uint8_t temp;
}base_state_t;

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

    /* Outgoing CAN message structs */
    base_state_t msg_1;
    uint16_t     msg_2;

    /* queue handle */
    QueueHandle_t queue_status_1;
    QueueHandle_t queue_status_2;

    QueueSetHandle_t queueset;

}esc_instance_t;

extern esc_instance_t esc_fleet[KDE_MAX_ESC];

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * API
 ******************************************************************************/

void init_esc_fleet(void);

void task_bridge(void *arg);

#ifdef __cplusplus
}
#endif

#endif /* TASK_BRIDGE_H */