/**
 * @file    ulog_vibration.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_vibration.h"
#include "ulog_def.h"

const char ulog_vibration_format[] = "vibration:uint64_t timestamp;uint64_t time_usec;float vibration_x;float vibration_y;float vibration_z;uint32_t clipping_0;uint32_t clipping_1;uint32_t clipping_2;";
const char ulog_vibration_name[] = "vibration";

int32_t ulog_format_vibration(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_vibration_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_vibration_format, sizeof(ulog_vibration_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_vibration(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_vibration_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_vibration_name, sizeof(ulog_vibration_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_vibration(ulog_t *log, ulog_msg_id_t id, const ulog_vibration_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint64_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(uint32_t)
                    + sizeof(uint32_t)
                    + sizeof(uint32_t)
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

    /* Vibration levels on X-axis */
    if (lfs_file_write(log->lfs, log->file, &src->vibration_x, sizeof(src->vibration_x)) < 0) {
        return 1;
    }

    /* Vibration levels on Y-axis */
    if (lfs_file_write(log->lfs, log->file, &src->vibration_y, sizeof(src->vibration_y)) < 0) {
        return 1;
    }

    /* Vibration levels on Z-axis */
    if (lfs_file_write(log->lfs, log->file, &src->vibration_z, sizeof(src->vibration_z)) < 0) {
        return 1;
    }

    /* first accelerometer clipping count */
    if (lfs_file_write(log->lfs, log->file, &src->clipping_0, sizeof(src->clipping_0)) < 0) {
        return 1;
    }

    /* second accelerometer clipping count */
    if (lfs_file_write(log->lfs, log->file, &src->clipping_1, sizeof(src->clipping_1)) < 0) {
        return 1;
    }

    /* third accelerometer clipping count */
    if (lfs_file_write(log->lfs, log->file, &src->clipping_2, sizeof(src->clipping_2)) < 0) {
        return 1;
    }

    
    return 0;
}
