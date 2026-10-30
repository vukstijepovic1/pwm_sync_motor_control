/**
 * @file    ulog_manual_setpoint.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_manual_setpoint.h"
#include "ulog_def.h"

const char ulog_manual_setpoint_format[] = "manual_setpoint:uint64_t timestamp;uint32_t time_boot_ms;float roll;float pitch;float yaw;float thrust;uint8_t mode_switch;uint8_t manual_override_switch;";
const char ulog_manual_setpoint_name[] = "manual_setpoint";

int32_t ulog_format_manual_setpoint(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_manual_setpoint_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_manual_setpoint_format, sizeof(ulog_manual_setpoint_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_manual_setpoint(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_manual_setpoint_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_manual_setpoint_name, sizeof(ulog_manual_setpoint_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_manual_setpoint(ulog_t *log, ulog_msg_id_t id, const ulog_manual_setpoint_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
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

    /* Timestamp (time since system boot). [ms] */
    if (lfs_file_write(log->lfs, log->file, &src->time_boot_ms, sizeof(src->time_boot_ms)) < 0) {
        return 1;
    }

    /* Desired roll rate [rad/s] */
    if (lfs_file_write(log->lfs, log->file, &src->roll, sizeof(src->roll)) < 0) {
        return 1;
    }

    /* Desired pitch rate [rad/s] */
    if (lfs_file_write(log->lfs, log->file, &src->pitch, sizeof(src->pitch)) < 0) {
        return 1;
    }

    /* Desired yaw rate [rad/s] */
    if (lfs_file_write(log->lfs, log->file, &src->yaw, sizeof(src->yaw)) < 0) {
        return 1;
    }

    /* Collective thrust, normalized to 0 .. 1 */
    if (lfs_file_write(log->lfs, log->file, &src->thrust, sizeof(src->thrust)) < 0) {
        return 1;
    }

    /* Flight mode switch position, 0.. 255 */
    if (lfs_file_write(log->lfs, log->file, &src->mode_switch, sizeof(src->mode_switch)) < 0) {
        return 1;
    }

    /* Override mode switch position, 0.. 255 */
    if (lfs_file_write(log->lfs, log->file, &src->manual_override_switch, sizeof(src->manual_override_switch)) < 0) {
        return 1;
    }

    
    return 0;
}
