/**
 * @file    ulog_scaled_pressure3.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_scaled_pressure3.h"
#include "ulog_def.h"

const char ulog_scaled_pressure3_format[] = "scaled_pressure3:uint64_t timestamp;uint32_t time_boot_ms;float press_abs;float press_diff;int16_t temperature;int16_t temperature_press_diff;";
const char ulog_scaled_pressure3_name[] = "scaled_pressure3";

int32_t ulog_format_scaled_pressure3(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_scaled_pressure3_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_scaled_pressure3_format, sizeof(ulog_scaled_pressure3_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_scaled_pressure3(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_scaled_pressure3_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_scaled_pressure3_name, sizeof(ulog_scaled_pressure3_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_scaled_pressure3(ulog_t *log, ulog_msg_id_t id, const ulog_scaled_pressure3_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
                    + sizeof(float)
                    + sizeof(float)
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

    /* Timestamp (time since system boot). [ms] */
    if (lfs_file_write(log->lfs, log->file, &src->time_boot_ms, sizeof(src->time_boot_ms)) < 0) {
        return 1;
    }

    /* Absolute pressure [hPa] */
    if (lfs_file_write(log->lfs, log->file, &src->press_abs, sizeof(src->press_abs)) < 0) {
        return 1;
    }

    /* Differential pressure [hPa] */
    if (lfs_file_write(log->lfs, log->file, &src->press_diff, sizeof(src->press_diff)) < 0) {
        return 1;
    }

    /* Absolute pressure temperature [cdegC] */
    if (lfs_file_write(log->lfs, log->file, &src->temperature, sizeof(src->temperature)) < 0) {
        return 1;
    }

    /* Differential pressure temperature (0, if not available). Report values of 0 (or 1) as 1 cdegC. [cdegC] */
    if (lfs_file_write(log->lfs, log->file, &src->temperature_press_diff, sizeof(src->temperature_press_diff)) < 0) {
        return 1;
    }

    
    return 0;
}
