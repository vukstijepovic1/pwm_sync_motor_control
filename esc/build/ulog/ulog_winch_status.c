/**
 * @file    ulog_winch_status.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_winch_status.h"
#include "ulog_def.h"

const char ulog_winch_status_format[] = "winch_status:uint64_t timestamp;uint64_t time_usec;float line_length;float speed;float tension;float voltage;float current;int16_t temperature;uint32_t status;";
const char ulog_winch_status_name[] = "winch_status";

int32_t ulog_format_winch_status(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_winch_status_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_winch_status_format, sizeof(ulog_winch_status_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_winch_status(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_winch_status_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_winch_status_name, sizeof(ulog_winch_status_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_winch_status(ulog_t *log, ulog_msg_id_t id, const ulog_winch_status_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint64_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(int16_t)
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

    /* Timestamp (synced to UNIX time or since system boot). [us] */
    if (lfs_file_write(log->lfs, log->file, &src->time_usec, sizeof(src->time_usec)) < 0) {
        return 1;
    }

    /* Length of line released. NaN if unknown [m] */
    if (lfs_file_write(log->lfs, log->file, &src->line_length, sizeof(src->line_length)) < 0) {
        return 1;
    }

    /* Speed line is being released or retracted. Positive values if being released, negative values if being retracted, NaN if unknown [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->speed, sizeof(src->speed)) < 0) {
        return 1;
    }

    /* Tension on the line. NaN if unknown [kg] */
    if (lfs_file_write(log->lfs, log->file, &src->tension, sizeof(src->tension)) < 0) {
        return 1;
    }

    /* Voltage of the battery supplying the winch. NaN if unknown [V] */
    if (lfs_file_write(log->lfs, log->file, &src->voltage, sizeof(src->voltage)) < 0) {
        return 1;
    }

    /* Current draw from the winch. NaN if unknown [A] */
    if (lfs_file_write(log->lfs, log->file, &src->current, sizeof(src->current)) < 0) {
        return 1;
    }

    /* Temperature of the motor. INT16_MAX if unknown [degC] */
    if (lfs_file_write(log->lfs, log->file, &src->temperature, sizeof(src->temperature)) < 0) {
        return 1;
    }

    /* Status flags */
    if (lfs_file_write(log->lfs, log->file, &src->status, sizeof(src->status)) < 0) {
        return 1;
    }

    
    return 0;
}
