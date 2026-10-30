/**
 * @file    ulog_trajectory_representation_waypoints.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_TRAJECTORY_REPRESENTATION_WAYPOINTS_H
#define ULOG_TRAJECTORY_REPRESENTATION_WAYPOINTS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_trajectory_representation_waypoints_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t time_usec; /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    uint8_t valid_points; /* Number of valid points (up-to 5 waypoints are possible) */
    float pos_x[5]; /* X-coordinate of waypoint, set to NaN if not being used [m] */
    float pos_y[5]; /* Y-coordinate of waypoint, set to NaN if not being used [m] */
    float pos_z[5]; /* Z-coordinate of waypoint, set to NaN if not being used [m] */
    float vel_x[5]; /* X-velocity of waypoint, set to NaN if not being used [m/s] */
    float vel_y[5]; /* Y-velocity of waypoint, set to NaN if not being used [m/s] */
    float vel_z[5]; /* Z-velocity of waypoint, set to NaN if not being used [m/s] */
    float acc_x[5]; /* X-acceleration of waypoint, set to NaN if not being used [m/s/s] */
    float acc_y[5]; /* Y-acceleration of waypoint, set to NaN if not being used [m/s/s] */
    float acc_z[5]; /* Z-acceleration of waypoint, set to NaN if not being used [m/s/s] */
    float pos_yaw[5]; /* Yaw angle, set to NaN if not being used [rad] */
    float vel_yaw[5]; /* Yaw rate, set to NaN if not being used [rad/s] */
    uint16_t command[5]; /* MAV_CMD command id of waypoint, set to UINT16_MAX if not being used. */
    
} ulog_trajectory_representation_waypoints_t;

/**
 * Defines Trajectory Representation Waypoints message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_trajectory_representation_waypoints(ulog_t *log);

/**
 * Subscribe Trajectory Representation Waypoints message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_trajectory_representation_waypoints(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Trajectory Representation Waypoints message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_trajectory_representation_waypoints(ulog_t *log, ulog_msg_id_t id, const ulog_trajectory_representation_waypoints_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_TRAJECTORY_REPRESENTATION_WAYPOINTS_H */