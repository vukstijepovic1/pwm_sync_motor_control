/**
 * @file    ulog_illuminator_status.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_illuminator_status.h"
#include "ulog_def.h"

const char ulog_illuminator_status_format[] = "illuminator_status:uint64_t timestamp;uint32_t uptime_ms;uint8_t enable;uint8_t mode_bitmask;uint32_t error_status;uint8_t mode;float brightness;float strobe_period;float strobe_duty_cycle;float temp_c;float min_strobe_period;float max_strobe_period;";
const char ulog_illuminator_status_name[] = "illuminator_status";

int32_t ulog_format_illuminator_status(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_illuminator_status_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_illuminator_status_format, sizeof(ulog_illuminator_status_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_illuminator_status(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_illuminator_status_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_illuminator_status_name, sizeof(ulog_illuminator_status_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_illuminator_status(ulog_t *log, ulog_msg_id_t id, const ulog_illuminator_status_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint32_t)
                    + sizeof(uint8_t)
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

    /* Time since the start-up of the illuminator in ms [ms] */
    if (lfs_file_write(log->lfs, log->file, &src->uptime_ms, sizeof(src->uptime_ms)) < 0) {
        return 1;
    }

    /* 0: Illuminators OFF, 1: Illuminators ON */
    if (lfs_file_write(log->lfs, log->file, &src->enable, sizeof(src->enable)) < 0) {
        return 1;
    }

    /* Supported illuminator modes */
    if (lfs_file_write(log->lfs, log->file, &src->mode_bitmask, sizeof(src->mode_bitmask)) < 0) {
        return 1;
    }

    /* Errors */
    if (lfs_file_write(log->lfs, log->file, &src->error_status, sizeof(src->error_status)) < 0) {
        return 1;
    }

    /* Illuminator mode */
    if (lfs_file_write(log->lfs, log->file, &src->mode, sizeof(src->mode)) < 0) {
        return 1;
    }

    /* Illuminator brightness [%] */
    if (lfs_file_write(log->lfs, log->file, &src->brightness, sizeof(src->brightness)) < 0) {
        return 1;
    }

    /* Illuminator strobing period in seconds [s] */
    if (lfs_file_write(log->lfs, log->file, &src->strobe_period, sizeof(src->strobe_period)) < 0) {
        return 1;
    }

    /* Illuminator strobing duty cycle [%] */
    if (lfs_file_write(log->lfs, log->file, &src->strobe_duty_cycle, sizeof(src->strobe_duty_cycle)) < 0) {
        return 1;
    }

    /* Temperature in Celsius */
    if (lfs_file_write(log->lfs, log->file, &src->temp_c, sizeof(src->temp_c)) < 0) {
        return 1;
    }

    /* Minimum strobing period in seconds [s] */
    if (lfs_file_write(log->lfs, log->file, &src->min_strobe_period, sizeof(src->min_strobe_period)) < 0) {
        return 1;
    }

    /* Maximum strobing period in seconds [s] */
    if (lfs_file_write(log->lfs, log->file, &src->max_strobe_period, sizeof(src->max_strobe_period)) < 0) {
        return 1;
    }

    
    return 0;
}
