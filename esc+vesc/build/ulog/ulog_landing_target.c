/**
 * @file    ulog_landing_target.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_landing_target.h"
#include "ulog_def.h"

const char ulog_landing_target_format[] = "landing_target:uint64_t timestamp;uint64_t time_usec;uint8_t target_num;uint8_t frame;float angle_x;float angle_y;float distance;float size_x;float size_y;float x;float y;float z;float[4] q;uint8_t type;uint8_t position_valid;";
const char ulog_landing_target_name[] = "landing_target";

int32_t ulog_format_landing_target(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_landing_target_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_landing_target_format, sizeof(ulog_landing_target_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_landing_target(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_landing_target_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_landing_target_name, sizeof(ulog_landing_target_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_landing_target(ulog_t *log, ulog_msg_id_t id, const ulog_landing_target_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)*4
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
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

    /* The ID of the target if multiple targets are present */
    if (lfs_file_write(log->lfs, log->file, &src->target_num, sizeof(src->target_num)) < 0) {
        return 1;
    }

    /* Coordinate frame used for following fields. */
    if (lfs_file_write(log->lfs, log->file, &src->frame, sizeof(src->frame)) < 0) {
        return 1;
    }

    /* X-axis angular offset of the target from the center of the image [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->angle_x, sizeof(src->angle_x)) < 0) {
        return 1;
    }

    /* Y-axis angular offset of the target from the center of the image [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->angle_y, sizeof(src->angle_y)) < 0) {
        return 1;
    }

    /* Distance to the target from the vehicle [m] */
    if (lfs_file_write(log->lfs, log->file, &src->distance, sizeof(src->distance)) < 0) {
        return 1;
    }

    /* Size of target along x-axis [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->size_x, sizeof(src->size_x)) < 0) {
        return 1;
    }

    /* Size of target along y-axis [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->size_y, sizeof(src->size_y)) < 0) {
        return 1;
    }

    /* X Position of the landing target in MAV_FRAME [m] */
    if (lfs_file_write(log->lfs, log->file, &src->x, sizeof(src->x)) < 0) {
        return 1;
    }

    /* Y Position of the landing target in MAV_FRAME [m] */
    if (lfs_file_write(log->lfs, log->file, &src->y, sizeof(src->y)) < 0) {
        return 1;
    }

    /* Z Position of the landing target in MAV_FRAME [m] */
    if (lfs_file_write(log->lfs, log->file, &src->z, sizeof(src->z)) < 0) {
        return 1;
    }

    /* Quaternion of landing target orientation (w, x, y, z order, zero-rotation is 1, 0, 0, 0) */
    if (lfs_file_write(log->lfs, log->file, src->q, sizeof(src->q)) < 0) {
        return 1;
    }

    /* Type of landing target */
    if (lfs_file_write(log->lfs, log->file, &src->type, sizeof(src->type)) < 0) {
        return 1;
    }

    /* Boolean indicating whether the position fields (x, y, z, q, type) contain valid target position information (valid: 1, invalid: 0). Default is 0 (invalid). */
    if (lfs_file_write(log->lfs, log->file, &src->position_valid, sizeof(src->position_valid)) < 0) {
        return 1;
    }

    
    return 0;
}
