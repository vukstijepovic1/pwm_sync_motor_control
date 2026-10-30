/**
 * @file    ulog_odometry.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_ODOMETRY_H
#define ULOG_ODOMETRY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_odometry_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t time_usec; /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    uint8_t frame_id; /* Coordinate frame of reference for the pose data. */
    uint8_t child_frame_id; /* Coordinate frame of reference for the velocity in free space (twist) data. */
    float x; /* X Position [m] */
    float y; /* Y Position [m] */
    float z; /* Z Position [m] */
    float q[4]; /* Quaternion components, w, x, y, z (1 0 0 0 is the null-rotation) */
    float vx; /* X linear speed [m/s] */
    float vy; /* Y linear speed [m/s] */
    float vz; /* Z linear speed [m/s] */
    float rollspeed; /* Roll angular speed [rad/s] */
    float pitchspeed; /* Pitch angular speed [rad/s] */
    float yawspeed; /* Yaw angular speed [rad/s] */
    float pose_covariance[21]; /* Row-major representation of a 6x6 pose cross-covariance matrix upper right triangle (states: x, y, z, roll, pitch, yaw; first six entries are the first ROW, next five entries are the second ROW, etc.). If unknown, assign NaN value to first element in the array. */
    float velocity_covariance[21]; /* Row-major representation of a 6x6 velocity cross-covariance matrix upper right triangle (states: vx, vy, vz, rollspeed, pitchspeed, yawspeed; first six entries are the first ROW, next five entries are the second ROW, etc.). If unknown, assign NaN value to first element in the array. */
    uint8_t reset_counter; /* Estimate reset counter. This should be incremented when the estimate resets in any of the dimensions (position, velocity, attitude, angular speed). This is designed to be used when e.g an external SLAM system detects a loop-closure and the estimate jumps. */
    uint8_t estimator_type; /* Type of estimator that is providing the odometry. */
    int8_t quality; /* Optional odometry quality metric as a percentage. -1 = odometry has failed, 0 = unknown/unset quality, 1 = worst quality, 100 = best quality [%] */
    
} ulog_odometry_t;

/**
 * Defines Odometry message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_odometry(ulog_t *log);

/**
 * Subscribe Odometry message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_odometry(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Odometry message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_odometry(ulog_t *log, ulog_msg_id_t id, const ulog_odometry_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_ODOMETRY_H */