/**
 * @file    ulog_gimbal_manager_information.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_GIMBAL_MANAGER_INFORMATION_H
#define ULOG_GIMBAL_MANAGER_INFORMATION_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_gimbal_manager_information_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint32_t time_boot_ms; /* Timestamp (time since system boot). [ms] */
    uint32_t cap_flags; /* Bitmap of gimbal capability flags. */
    uint8_t gimbal_device_id; /* Gimbal device ID that this gimbal manager is responsible for. Component ID of gimbal device (or 1-6 for non-MAVLink gimbal). */
    float roll_min; /* Minimum hardware roll angle (positive: rolling to the right, negative: rolling to the left) [rad] */
    float roll_max; /* Maximum hardware roll angle (positive: rolling to the right, negative: rolling to the left) [rad] */
    float pitch_min; /* Minimum pitch angle (positive: up, negative: down) [rad] */
    float pitch_max; /* Maximum pitch angle (positive: up, negative: down) [rad] */
    float yaw_min; /* Minimum yaw angle (positive: to the right, negative: to the left) [rad] */
    float yaw_max; /* Maximum yaw angle (positive: to the right, negative: to the left) [rad] */
    
} ulog_gimbal_manager_information_t;

/**
 * Defines Gimbal Manager Information message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_gimbal_manager_information(ulog_t *log);

/**
 * Subscribe Gimbal Manager Information message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_gimbal_manager_information(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Gimbal Manager Information message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_gimbal_manager_information(ulog_t *log, ulog_msg_id_t id, const ulog_gimbal_manager_information_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_GIMBAL_MANAGER_INFORMATION_H */