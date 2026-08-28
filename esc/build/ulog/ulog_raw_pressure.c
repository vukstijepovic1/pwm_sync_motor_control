/**
 * @file    ulog_raw_pressure.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_raw_pressure.h"
#include "ulog_def.h"

const char ulog_raw_pressure_format[] = "raw_pressure:uint64_t timestamp;uint64_t time_usec;int16_t press_abs;int16_t press_diff1;int16_t press_diff2;int16_t temperature;";
const char ulog_raw_pressure_name[] = "raw_pressure";

int32_t ulog_format_raw_pressure(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_raw_pressure_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_raw_pressure_format, sizeof(ulog_raw_pressure_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_raw_pressure(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_raw_pressure_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_raw_pressure_name, sizeof(ulog_raw_pressure_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_raw_pressure(ulog_t *log, ulog_msg_id_t id, const ulog_raw_pressure_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint64_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
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

    /* Absolute pressure (raw) */
    if (lfs_file_write(log->lfs, log->file, &src->press_abs, sizeof(src->press_abs)) < 0) {
        return 1;
    }

    /* Differential pressure 1 (raw, 0 if nonexistent) */
    if (lfs_file_write(log->lfs, log->file, &src->press_diff1, sizeof(src->press_diff1)) < 0) {
        return 1;
    }

    /* Differential pressure 2 (raw, 0 if nonexistent) */
    if (lfs_file_write(log->lfs, log->file, &src->press_diff2, sizeof(src->press_diff2)) < 0) {
        return 1;
    }

    /* Raw Temperature measurement (raw) */
    if (lfs_file_write(log->lfs, log->file, &src->temperature, sizeof(src->temperature)) < 0) {
        return 1;
    }

    
    return 0;
}
