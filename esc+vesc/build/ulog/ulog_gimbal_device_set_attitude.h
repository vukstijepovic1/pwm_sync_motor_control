/**
 * @file    ulog_gimbal_device_set_attitude.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_GIMBAL_DEVICE_SET_ATTITUDE_H
#define ULOG_GIMBAL_DEVICE_SET_ATTITUDE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_gimbal_device_set_attitude_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t target_system; /* System ID */
    uint8_t target_component; /* Component ID */
    uint16_t flags; /* Low level gimbal flags. */
    float q[4]; /* Quaternion components, w, x, y, z (1 0 0 0 is the null-rotation). The frame is described in the message description. Set fields to NaN to be ignored. */
    float angular_velocity_x; /* X component of angular velocity (positive: rolling to the right). The frame is described in the message description. NaN to be ignored. [rad/s] */
    float angular_velocity_y; /* Y component of angular velocity (positive: pitching up). The frame is described in the message description. NaN to be ignored. [rad/s] */
    float angular_velocity_z; /* Z component of angular velocity (positive: yawing to the right). The frame is described in the message description. NaN to be ignored. [rad/s] */
    
} ulog_gimbal_device_set_attitude_t;

/**
 * Defines Gimbal Device Set Attitude message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_gimbal_device_set_attitude(ulog_t *log);

/**
 * Subscribe Gimbal Device Set Attitude message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_gimbal_device_set_attitude(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Gimbal Device Set Attitude message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_gimbal_device_set_attitude(ulog_t *log, ulog_msg_id_t id, const ulog_gimbal_device_set_attitude_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_GIMBAL_DEVICE_SET_ATTITUDE_H */