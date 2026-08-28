/**
 * @file    ulog_attitude_quaternion_cov.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_ATTITUDE_QUATERNION_COV_H
#define ULOG_ATTITUDE_QUATERNION_COV_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_attitude_quaternion_cov_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t time_usec; /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    float q[4]; /* Quaternion components, w, x, y, z (1 0 0 0 is the null-rotation) */
    float rollspeed; /* Roll angular speed [rad/s] */
    float pitchspeed; /* Pitch angular speed [rad/s] */
    float yawspeed; /* Yaw angular speed [rad/s] */
    float covariance[9]; /* Row-major representation of a 3x3 attitude covariance matrix (states: roll, pitch, yaw; first three entries are the first ROW, next three entries are the second row, etc.). If unknown, assign NaN value to first element in the array. */
    
} ulog_attitude_quaternion_cov_t;

/**
 * Defines Attitude Quaternion Cov message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_attitude_quaternion_cov(ulog_t *log);

/**
 * Subscribe Attitude Quaternion Cov message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_attitude_quaternion_cov(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Attitude Quaternion Cov message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_attitude_quaternion_cov(ulog_t *log, ulog_msg_id_t id, const ulog_attitude_quaternion_cov_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_ATTITUDE_QUATERNION_COV_H */