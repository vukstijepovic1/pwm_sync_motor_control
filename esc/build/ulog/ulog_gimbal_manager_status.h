/**
 * @file    ulog_gimbal_manager_status.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_GIMBAL_MANAGER_STATUS_H
#define ULOG_GIMBAL_MANAGER_STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_gimbal_manager_status_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint32_t time_boot_ms; /* Timestamp (time since system boot). [ms] */
    uint32_t flags; /* High level gimbal manager flags currently applied. */
    uint8_t gimbal_device_id; /* Gimbal device ID that this gimbal manager is responsible for. Component ID of gimbal device (or 1-6 for non-MAVLink gimbal). */
    uint8_t primary_control_sysid; /* System ID of MAVLink component with primary control, 0 for none. */
    uint8_t primary_control_compid; /* Component ID of MAVLink component with primary control, 0 for none. */
    uint8_t secondary_control_sysid; /* System ID of MAVLink component with secondary control, 0 for none. */
    uint8_t secondary_control_compid; /* Component ID of MAVLink component with secondary control, 0 for none. */
    
} ulog_gimbal_manager_status_t;

/**
 * Defines Gimbal Manager Status message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_gimbal_manager_status(ulog_t *log);

/**
 * Subscribe Gimbal Manager Status message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_gimbal_manager_status(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Gimbal Manager Status message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_gimbal_manager_status(ulog_t *log, ulog_msg_id_t id, const ulog_gimbal_manager_status_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_GIMBAL_MANAGER_STATUS_H */