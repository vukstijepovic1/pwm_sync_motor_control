/**
 * @file    ulog_gimbal_device_attitude_status.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_GIMBAL_DEVICE_ATTITUDE_STATUS_H
#define ULOG_GIMBAL_DEVICE_ATTITUDE_STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_gimbal_device_attitude_status_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t target_system; /* System ID */
    uint8_t target_component; /* Component ID */
    uint32_t time_boot_ms; /* Timestamp (time since system boot). [ms] */
    uint16_t flags; /* Current gimbal flags set. */
    float q[4]; /* Quaternion components, w, x, y, z (1 0 0 0 is the null-rotation). The frame is described in the message description. */
    float angular_velocity_x; /* X component of angular velocity (positive: rolling to the right). The frame is described in the message description. NaN if unknown. [rad/s] */
    float angular_velocity_y; /* Y component of angular velocity (positive: pitching up). The frame is described in the message description. NaN if unknown. [rad/s] */
    float angular_velocity_z; /* Z component of angular velocity (positive: yawing to the right). The frame is described in the message description. NaN if unknown. [rad/s] */
    uint32_t failure_flags; /* Failure flags (0 for no failure) */
    float delta_yaw; /* Yaw angle relating the quaternions in earth and body frames (see message description). NaN if unknown. [rad] */
    float delta_yaw_velocity; /* Yaw angular velocity relating the angular velocities in earth and body frames (see message description). NaN if unknown. [rad/s] */
    uint8_t gimbal_device_id; /* This field is to be used if the gimbal manager and the gimbal device are the same component and hence have the same component ID. This field is then set a number between 1-6. If the component ID is separate, this field is not required and must be set to 0. */
    
} ulog_gimbal_device_attitude_status_t;

/**
 * Defines Gimbal Device Attitude Status message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_gimbal_device_attitude_status(ulog_t *log);

/**
 * Subscribe Gimbal Device Attitude Status message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_gimbal_device_attitude_status(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Gimbal Device Attitude Status message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_gimbal_device_attitude_status(ulog_t *log, ulog_msg_id_t id, const ulog_gimbal_device_attitude_status_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_GIMBAL_DEVICE_ATTITUDE_STATUS_H */