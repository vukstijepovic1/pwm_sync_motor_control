/**
 * @file    task_work.h
 * @brief   Task work - process background tasks
 * @version 1.0.0
 * @date    26.02.2025
 * @author  LisumLab
 */

#ifndef TASK_WORK_H
#define TASK_WORK_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <stdint.h>
#include "kde.h"
#include "vesc.h"

/*******************************************************************************
 * Typedefs
 ******************************************************************************/

typedef struct esc_comm_msg_t{
    uint8_t esc_id;
    object_numbers_e obj_id;
    float  comm_phar;
} esc_comm_msg_t;

/* Result of one esc_comm_msg_t, sent back by task_bridge (queue_resp) so
 * task_mav can answer the ground station with a COMMAND_ACK. */
typedef struct esc_comm_resp_t{
    esc_comm_msg_t cmd;
    lStatus_t      status;
} esc_comm_resp_t;

/* Command bridged from the ground station towards a VESC on the VESC CAN bus.
 * Produced by task_mav (one per LISUM_VESC_SET_* / LISUM_VESC_PING message),
 * consumed by task_bridge (ProcessCommand). */
typedef struct vesc_command_message_t{
    uint8_t           vesc_id;
    command_numbers_e command_id;
    float             command_param;
} vesc_command_message_t;

/*******************************************************************************
 * API
 ******************************************************************************/

void task_work(void *arg);

#ifdef __cplusplus
}
#endif

#endif /* TASK_WORK_H */