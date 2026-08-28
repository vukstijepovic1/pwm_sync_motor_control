/**
 * @file    ulog_gimbal_manager_set_attitude.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_GIMBAL_MANAGER_SET_ATTITUDE_H
#define ULOG_GIMBAL_MANAGER_SET_ATTITUDE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_gimbal_manager_set_attitude_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t target_system; /* System ID */
    uint8_t target_component; /* Component ID */
    uint32_t flags; /* High level gimbal manager flags to use. */
    uint8_t gimbal_device_id; /* Component ID of gimbal device to address (or 1-6 for non-MAVLink gimbal), 0 for all gimbal device components. Send command multiple times for more than one gimbal (but not all gimbals). */
    float q[4]; /* Quaternion components, w, x, y, z (1 0 0 0 is the null-rotation, the frame is depends on whether the flag GIMBAL_MANAGER_FLAGS_YAW_LOCK is set) */
    float angular_velocity_x; /* X component of angular velocity, positive is rolling to the right, NaN to be ignored. [rad/s] */
    float angular_velocity_y; /* Y component of angular velocity, positive is pitching up, NaN to be ignored. [rad/s] */
    float angular_velocity_z; /* Z component of angular velocity, positive is yawing to the right, NaN to be ignored. [rad/s] */
    
} ulog_gimbal_manager_set_attitude_t;

/**
 * Defines Gimbal Manager Set Attitude message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_gimbal_manager_set_attitude(ulog_t *log);

/**
 * Subscribe Gimbal Manager Set Attitude message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_gimbal_manager_set_attitude(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Gimbal Manager Set Attitude message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_gimbal_manager_set_attitude(ulog_t *log, ulog_msg_id_t id, const ulog_gimbal_manager_set_attitude_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_GIMBAL_MANAGER_SET_ATTITUDE_H */