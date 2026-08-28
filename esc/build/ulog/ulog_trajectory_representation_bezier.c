/**
 * @file    ulog_trajectory_representation_bezier.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_trajectory_representation_bezier.h"
#include "ulog_def.h"

const char ulog_trajectory_representation_bezier_format[] = "trajectory_representation_bezier:uint64_t timestamp;uint64_t time_usec;uint8_t valid_points;float[5] pos_x;float[5] pos_y;float[5] pos_z;float[5] delta;float[5] pos_yaw;";
const char ulog_trajectory_representation_bezier_name[] = "trajectory_representation_bezier";

int32_t ulog_format_trajectory_representation_bezier(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_trajectory_representation_bezier_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_trajectory_representation_bezier_format, sizeof(ulog_trajectory_representation_bezier_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_trajectory_representation_bezier(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_trajectory_representation_bezier_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_trajectory_representation_bezier_name, sizeof(ulog_trajectory_representation_bezier_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_trajectory_representation_bezier(ulog_t *log, ulog_msg_id_t id, const ulog_trajectory_representation_bezier_t *src)
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

    /* Number of valid control points (up-to 5 points are possible) */
    if (lfs_file_write(log->lfs, log->file, &src->valid_points, sizeof(src->valid_points)) < 0) {
        return 1;
    }

    /* X-coordinate of bezier control points. Set to NaN if not being used [m] */
    if (lfs_file_write(log->lfs, log->file, src->pos_x, sizeof(src->pos_x)) < 0) {
        return 1;
    }

    /* Y-coordinate of bezier control points. Set to NaN if not being used [m] */
    if (lfs_file_write(log->lfs, log->file, src->pos_y, sizeof(src->pos_y)) < 0) {
        return 1;
    }

    /* Z-coordinate of bezier control points. Set to NaN if not being used [m] */
    if (lfs_file_write(log->lfs, log->file, src->pos_z, sizeof(src->pos_z)) < 0) {
        return 1;
    }

    /* Bezier time horizon. Set to NaN if velocity/acceleration should not be incorporated [s] */
    if (lfs_file_write(log->lfs, log->file, src->delta, sizeof(src->delta)) < 0) {
        return 1;
    }

    /* Yaw. Set to NaN for unchanged [rad] */
    if (lfs_file_write(log->lfs, log->file, src->pos_yaw, sizeof(src->pos_yaw)) < 0) {
        return 1;
    }

    
    return 0;
}
