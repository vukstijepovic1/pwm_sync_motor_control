/**
 * @file    ulog_local_position_ned_cov.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_LOCAL_POSITION_NED_COV_H
#define ULOG_LOCAL_POSITION_NED_COV_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_local_position_ned_cov_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t time_usec; /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    uint8_t estimator_type; /* Class id of the estimator this estimate originated from. */
    float x; /* X Position [m] */
    float y; /* Y Position [m] */
    float z; /* Z Position [m] */
    float vx; /* X Speed [m/s] */
    float vy; /* Y Speed [m/s] */
    float vz; /* Z Speed [m/s] */
    float ax; /* X Acceleration [m/s/s] */
    float ay; /* Y Acceleration [m/s/s] */
    float az; /* Z Acceleration [m/s/s] */
    float covariance[45]; /* Row-major representation of position, velocity and acceleration 9x9 cross-covariance matrix upper right triangle (states: x, y, z, vx, vy, vz, ax, ay, az; first nine entries are the first ROW, next eight entries are the second row, etc.). If unknown, assign NaN value to first element in the array. */
    
} ulog_local_position_ned_cov_t;

/**
 * Defines Local Position Ned Cov message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_local_position_ned_cov(ulog_t *log);

/**
 * Subscribe Local Position Ned Cov message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_local_position_ned_cov(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Local Position Ned Cov message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_local_position_ned_cov(ulog_t *log, ulog_msg_id_t id, const ulog_local_position_ned_cov_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_LOCAL_POSITION_NED_COV_H */