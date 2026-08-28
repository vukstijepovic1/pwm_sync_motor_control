/**
 * @file    ulog_estimator_status.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_estimator_status.h"
#include "ulog_def.h"

const char ulog_estimator_status_format[] = "estimator_status:uint64_t timestamp;uint64_t time_usec;uint16_t flags;float vel_ratio;float pos_horiz_ratio;float pos_vert_ratio;float mag_ratio;float hagl_ratio;float tas_ratio;float pos_horiz_accuracy;float pos_vert_accuracy;";
const char ulog_estimator_status_name[] = "estimator_status";

int32_t ulog_format_estimator_status(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_estimator_status_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_estimator_status_format, sizeof(ulog_estimator_status_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_estimator_status(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_estimator_status_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_estimator_status_name, sizeof(ulog_estimator_status_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_estimator_status(ulog_t *log, ulog_msg_id_t id, const ulog_estimator_status_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint64_t)
                    + sizeof(uint16_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
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

    /* Bitmap indicating which EKF outputs are valid. */
    if (lfs_file_write(log->lfs, log->file, &src->flags, sizeof(src->flags)) < 0) {
        return 1;
    }

    /* Velocity innovation test ratio */
    if (lfs_file_write(log->lfs, log->file, &src->vel_ratio, sizeof(src->vel_ratio)) < 0) {
        return 1;
    }

    /* Horizontal position innovation test ratio */
    if (lfs_file_write(log->lfs, log->file, &src->pos_horiz_ratio, sizeof(src->pos_horiz_ratio)) < 0) {
        return 1;
    }

    /* Vertical position innovation test ratio */
    if (lfs_file_write(log->lfs, log->file, &src->pos_vert_ratio, sizeof(src->pos_vert_ratio)) < 0) {
        return 1;
    }

    /* Magnetometer innovation test ratio */
    if (lfs_file_write(log->lfs, log->file, &src->mag_ratio, sizeof(src->mag_ratio)) < 0) {
        return 1;
    }

    /* Height above terrain innovation test ratio */
    if (lfs_file_write(log->lfs, log->file, &src->hagl_ratio, sizeof(src->hagl_ratio)) < 0) {
        return 1;
    }

    /* True airspeed innovation test ratio */
    if (lfs_file_write(log->lfs, log->file, &src->tas_ratio, sizeof(src->tas_ratio)) < 0) {
        return 1;
    }

    /* Horizontal position 1-STD accuracy relative to the EKF local origin [m] */
    if (lfs_file_write(log->lfs, log->file, &src->pos_horiz_accuracy, sizeof(src->pos_horiz_accuracy)) < 0) {
        return 1;
    }

    /* Vertical position 1-STD accuracy relative to the EKF local origin [m] */
    if (lfs_file_write(log->lfs, log->file, &src->pos_vert_accuracy, sizeof(src->pos_vert_accuracy)) < 0) {
        return 1;
    }

    
    return 0;
}
