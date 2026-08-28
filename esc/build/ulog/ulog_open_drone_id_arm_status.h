/**
 * @file    ulog_open_drone_id_arm_status.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_OPEN_DRONE_ID_ARM_STATUS_H
#define ULOG_OPEN_DRONE_ID_ARM_STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_open_drone_id_arm_status_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t status; /* Status level indicating if arming is allowed. */
    char error[50]; /* Text error message, should be empty if status is good to arm. Fill with nulls in unused portion. */
    
} ulog_open_drone_id_arm_status_t;

/**
 * Defines Open Drone Id Arm Status message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_open_drone_id_arm_status(ulog_t *log);

/**
 * Subscribe Open Drone Id Arm Status message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_open_drone_id_arm_status(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Open Drone Id Arm Status message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_open_drone_id_arm_status(ulog_t *log, ulog_msg_id_t id, const ulog_open_drone_id_arm_status_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_OPEN_DRONE_ID_ARM_STATUS_H */