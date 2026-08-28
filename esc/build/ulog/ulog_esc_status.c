/**
 * @file    ulog_esc_status.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_esc_status.h"
#include "ulog_def.h"

const char ulog_esc_status_format[] = "esc_status:uint64_t timestamp;uint8_t index;uint64_t time_usec;int32_t[4] rpm;float[4] voltage;float[4] current;";
const char ulog_esc_status_name[] = "esc_status";

int32_t ulog_format_esc_status(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_esc_status_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_esc_status_format, sizeof(ulog_esc_status_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_esc_status(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_esc_status_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_esc_status_name, sizeof(ulog_esc_status_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_esc_status(ulog_t *log, ulog_msg_id_t id, const ulog_esc_status_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint64_t)
                    + sizeof(int32_t)*4
                    + sizeof(float)*4
                    + sizeof(float)*4
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

    /* Index of the first ESC in this message. minValue = 0, maxValue = 60, increment = 4. */
    if (lfs_file_write(log->lfs, log->file, &src->index, sizeof(src->index)) < 0) {
        return 1;
    }

    /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->time_usec, sizeof(src->time_usec)) < 0) {
        return 1;
    }

    /* Reported motor RPM from each ESC (negative for reverse rotation). [rpm] */
    if (lfs_file_write(log->lfs, log->file, src->rpm, sizeof(src->rpm)) < 0) {
        return 1;
    }

    /* Voltage measured from each ESC. [V] */
    if (lfs_file_write(log->lfs, log->file, src->voltage, sizeof(src->voltage)) < 0) {
        return 1;
    }

    /* Current measured from each ESC. [A] */
    if (lfs_file_write(log->lfs, log->file, src->current, sizeof(src->current)) < 0) {
        return 1;
    }

    
    return 0;
}
