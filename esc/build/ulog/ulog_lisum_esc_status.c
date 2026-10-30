/**
 * @file    ulog_lisum_esc_status.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_lisum_esc_status.h"
#include "ulog_def.h"

const char ulog_lisum_esc_status_format[] = "lisum_esc_status:uint64_t timestamp;uint8_t index;float[2] voltage;float[2] curr_motor;float[2] current;float[2] temp_fet;float[2] temp_motor;float[2] rpm;float[2] duty;float[2] energy_consumed;float[2] curr_consumed;";
const char ulog_lisum_esc_status_name[] = "lisum_esc_status";

int32_t ulog_format_lisum_esc_status(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_lisum_esc_status_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_lisum_esc_status_format, sizeof(ulog_lisum_esc_status_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_lisum_esc_status(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_lisum_esc_status_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_lisum_esc_status_name, sizeof(ulog_lisum_esc_status_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_lisum_esc_status(ulog_t *log, ulog_msg_id_t id, const ulog_lisum_esc_status_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(float)*2
                    + sizeof(float)*2
                    + sizeof(float)*2
                    + sizeof(float)*2
                    + sizeof(float)*2
                    + sizeof(float)*2
                    + sizeof(float)*2
                    + sizeof(float)*2
                    + sizeof(float)*2
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

    /* Index of the first ESC in this message. minValue = 0, maxValue = 60, increment = 2. */
    if (lfs_file_write(log->lfs, log->file, &src->index, sizeof(src->index)) < 0) {
        return 1;
    }

    /* Input voltage supplied to the ESC. [V] */
    if (lfs_file_write(log->lfs, log->file, src->voltage, sizeof(src->voltage)) < 0) {
        return 1;
    }

    /* Current drawn by the motor. [A] */
    if (lfs_file_write(log->lfs, log->file, src->curr_motor, sizeof(src->curr_motor)) < 0) {
        return 1;
    }

    /* Total current drawn from the battery. [A] */
    if (lfs_file_write(log->lfs, log->file, src->current, sizeof(src->current)) < 0) {
        return 1;
    }

    /* Temperature of the ESC FETs. [C] */
    if (lfs_file_write(log->lfs, log->file, src->temp_fet, sizeof(src->temp_fet)) < 0) {
        return 1;
    }

    /* Temperature of the motor. [C] */
    if (lfs_file_write(log->lfs, log->file, src->temp_motor, sizeof(src->temp_motor)) < 0) {
        return 1;
    }

    /* Motor rotational speed in electrical RPM. [eRPM] */
    if (lfs_file_write(log->lfs, log->file, src->rpm, sizeof(src->rpm)) < 0) {
        return 1;
    }

    /* Duty cycle of the ESC output. [%] */
    if (lfs_file_write(log->lfs, log->file, src->duty, sizeof(src->duty)) < 0) {
        return 1;
    }

    /* Energy consumed by the motor. [Wh] */
    if (lfs_file_write(log->lfs, log->file, src->energy_consumed, sizeof(src->energy_consumed)) < 0) {
        return 1;
    }

    /* Total charge consumed by the motor. [Ah] */
    if (lfs_file_write(log->lfs, log->file, src->curr_consumed, sizeof(src->curr_consumed)) < 0) {
        return 1;
    }

    
    return 0;
}
