/**
 * @file    ulog_trajectory_representation_waypoints.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_trajectory_representation_waypoints.h"
#include "ulog_def.h"

const char ulog_trajectory_representation_waypoints_format[] = "trajectory_representation_waypoints:uint64_t timestamp;uint64_t time_usec;uint8_t valid_points;float[5] pos_x;float[5] pos_y;float[5] pos_z;float[5] vel_x;float[5] vel_y;float[5] vel_z;float[5] acc_x;float[5] acc_y;float[5] acc_z;float[5] pos_yaw;float[5] vel_yaw;uint16_t[5] command;";
const char ulog_trajectory_representation_waypoints_name[] = "trajectory_representation_waypoints";

int32_t ulog_format_trajectory_representation_waypoints(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_trajectory_representation_waypoints_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_trajectory_representation_waypoints_format, sizeof(ulog_trajectory_representation_waypoints_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_trajectory_representation_waypoints(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_trajectory_representation_waypoints_name) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_SUBSCRIPTION,
    };

    if(log->state == ULOG_STATE_DEFINITIONS_CREATED)
        log->state = ULOG_STATE_WRITING_DATA;

    if(log->state != ULOG_STATE_WRITING_DATA)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, &multi_id, sizeof(multi_id)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, &log->msg_cnt, sizeof(log->msg_cnt)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_trajectory_representation_waypoints_name, sizeof(ulog_trajectory_representation_waypoints_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_trajectory_representation_waypoints(ulog_t *log, ulog_msg_id_t id, const ulog_trajectory_representation_waypoints_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(float)*5
                    + sizeof(float)*5
                    + sizeof(float)*5
                    + sizeof(float)*5
                    + sizeof(float)*5
                    + sizeof(float)*5
                    + sizeof(float)*5
                    + sizeof(float)*5
                    + sizeof(float)*5
                    + sizeof(float)*5
                    + sizeof(float)*5
                    + sizeof(uint16_t)*5
                    ,
        .msg_type = ULOG_DEF_MSG_TYPE_LOGGED_DATA,
    };

    if(log->state != ULOG_STATE_WRITING_DATA || id >= log->msg_cnt) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, &id, sizeof(id)) < 0) {
        return 1;
    }

    /* Timestamp [us] */
    if (lfs_file_write(log->lfs, log->file, &src->timestamp, sizeof(src->timestamp)) < 0) {
        return 1;
    }

    /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->time_usec, sizeof(src->time_usec)) < 0) {
        return 1;
    }

    /* Number of valid points (up-to 5 waypoints are possible) */
    if (lfs_file_write(log->lfs, log->file, &src->valid_points, sizeof(src->valid_points)) < 0) {
        return 1;
    }

    /* X-coordinate of waypoint, set to NaN if not being used [m] */
    if (lfs_file_write(log->lfs, log->file, src->pos_x, sizeof(src->pos_x)) < 0) {
        return 1;
    }

    /* Y-coordinate of waypoint, set to NaN if not being used [m] */
    if (lfs_file_write(log->lfs, log->file, src->pos_y, sizeof(src->pos_y)) < 0) {
        return 1;
    }

    /* Z-coordinate of waypoint, set to NaN if not being used [m] */
    if (lfs_file_write(log->lfs, log->file, src->pos_z, sizeof(src->pos_z)) < 0) {
        return 1;
    }

    /* X-velocity of waypoint, set to NaN if not being used [m/s] */
    if (lfs_file_write(log->lfs, log->file, src->vel_x, sizeof(src->vel_x)) < 0) {
        return 1;
    }

    /* Y-velocity of waypoint, set to NaN if not being used [m/s] */
    if (lfs_file_write(log->lfs, log->file, src->vel_y, sizeof(src->vel_y)) < 0) {
        return 1;
    }

    /* Z-velocity of waypoint, set to NaN if not being used [m/s] */
    if (lfs_file_write(log->lfs, log->file, src->vel_z, sizeof(src->vel_z)) < 0) {
        return 1;
    }

    /* X-acceleration of waypoint, set to NaN if not being used [m/s/s] */
    if (lfs_file_write(log->lfs, log->file, src->acc_x, sizeof(src->acc_x)) < 0) {
        return 1;
    }

    /* Y-acceleration of waypoint, set to NaN if not being used [m/s/s] */
    if (lfs_file_write(log->lfs, log->file, src->acc_y, sizeof(src->acc_y)) < 0) {
        return 1;
    }

    /* Z-acceleration of waypoint, set to NaN if not being used [m/s/s] */
    if (lfs_file_write(log->lfs, log->file, src->acc_z, sizeof(src->acc_z)) < 0) {
        return 1;
    }

    /* Yaw angle, set to NaN if not being used [rad] */
    if (lfs_file_write(log->lfs, log->file, src->pos_yaw, sizeof(src->pos_yaw)) < 0) {
        return 1;
    }

    /* Yaw rate, set to NaN if not being used [rad/s] */
    if (lfs_file_write(log->lfs, log->file, src->vel_yaw, sizeof(src->vel_yaw)) < 0) {
        return 1;
    }

    /* MAV_CMD command id of waypoint, set to UINT16_MAX if not being used. */
    if (lfs_file_write(log->lfs, log->file, src->command, sizeof(src->command)) < 0) {
        return 1;
    }

    
    return 0;
}
