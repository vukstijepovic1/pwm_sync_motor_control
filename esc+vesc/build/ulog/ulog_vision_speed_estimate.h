/**
 * @file    ulog_vision_speed_estimate.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_VISION_SPEED_ESTIMATE_H
#define ULOG_VISION_SPEED_ESTIMATE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_vision_speed_estimate_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t usec; /* Timestamp (UNIX time or time since system boot) [us] */
    float x; /* Global X speed [m/s] */
    float y; /* Global Y speed [m/s] */
    float z; /* Global Z speed [m/s] */
    float covariance[9]; /* Row-major representation of 3x3 linear velocity covariance matrix (states: vx, vy, vz; 1st three entries - 1st row, etc.). If unknown, assign NaN value to first element in the array. */
    uint8_t reset_counter; /* Estimate reset counter. This should be incremented when the estimate resets in any of the dimensions (position, velocity, attitude, angular speed). This is designed to be used when e.g an external SLAM system detects a loop-closure and the estimate jumps. */
    
} ulog_vision_speed_estimate_t;

/**
 * Defines Vision Speed Estimate message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_vision_speed_estimate(ulog_t *log);

/**
 * Subscribe Vision Speed Estimate message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_vision_speed_estimate(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Vision Speed Estimate message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_vision_speed_estimate(ulog_t *log, ulog_msg_id_t id, const ulog_vision_speed_estimate_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_VISION_SPEED_ESTIMATE_H */