/**
 * @file    ulog_trajectory_representation_bezier.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_TRAJECTORY_REPRESENTATION_BEZIER_H
#define ULOG_TRAJECTORY_REPRESENTATION_BEZIER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_trajectory_representation_bezier_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t time_usec; /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    uint8_t valid_points; /* Number of valid control points (up-to 5 points are possible) */
    float pos_x[5]; /* X-coordinate of bezier control points. Set to NaN if not being used [m] */
    float pos_y[5]; /* Y-coordinate of bezier control points. Set to NaN if not being used [m] */
    float pos_z[5]; /* Z-coordinate of bezier control points. Set to NaN if not being used [m] */
    float delta[5]; /* Bezier time horizon. Set to NaN if velocity/acceleration should not be incorporated [s] */
    float pos_yaw[5]; /* Yaw. Set to NaN for unchanged [rad] */
    
} ulog_trajectory_representation_bezier_t;

/**
 * Defines Trajectory Representation Bezier message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_trajectory_representation_bezier(ulog_t *log);

/**
 * Subscribe Trajectory Representation Bezier message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_trajectory_representation_bezier(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Trajectory Representation Bezier message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_trajectory_representation_bezier(ulog_t *log, ulog_msg_id_t id, const ulog_trajectory_representation_bezier_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_TRAJECTORY_REPRESENTATION_BEZIER_H */