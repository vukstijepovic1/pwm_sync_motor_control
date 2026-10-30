/**
 * @file    ulog_attitude_quaternion.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_ATTITUDE_QUATERNION_H
#define ULOG_ATTITUDE_QUATERNION_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_attitude_quaternion_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint32_t time_boot_ms; /* Timestamp (time since system boot). [ms] */
    float q1; /* Quaternion component 1, w (1 in null-rotation) */
    float q2; /* Quaternion component 2, x (0 in null-rotation) */
    float q3; /* Quaternion component 3, y (0 in null-rotation) */
    float q4; /* Quaternion component 4, z (0 in null-rotation) */
    float rollspeed; /* Roll angular speed [rad/s] */
    float pitchspeed; /* Pitch angular speed [rad/s] */
    float yawspeed; /* Yaw angular speed [rad/s] */
    float repr_offset_q[4]; /* Rotation offset by which the attitude quaternion and angular speed vector should be rotated for user display (quaternion with [w, x, y, z] order, zero-rotation is [1, 0, 0, 0], send [0, 0, 0, 0] if field not supported). This field is intended for systems in which the reference attitude may change during flight. For example, tailsitters VTOLs rotate their reference attitude by 90 degrees between hover mode and fixed wing mode, thus repr_offset_q is equal to [1, 0, 0, 0] in hover mode and equal to [0.7071, 0, 0.7071, 0] in fixed wing mode. */
    
} ulog_attitude_quaternion_t;

/**
 * Defines Attitude Quaternion message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_attitude_quaternion(ulog_t *log);

/**
 * Subscribe Attitude Quaternion message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_attitude_quaternion(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Attitude Quaternion message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_attitude_quaternion(ulog_t *log, ulog_msg_id_t id, const ulog_attitude_quaternion_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_ATTITUDE_QUATERNION_H */