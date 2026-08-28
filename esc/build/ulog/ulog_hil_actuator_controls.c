/**
 * @file    ulog_hil_actuator_controls.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_hil_actuator_controls.h"
#include "ulog_def.h"

const char ulog_hil_actuator_controls_format[] = "hil_actuator_controls:uint64_t timestamp;uint64_t time_usec;float[16] controls;uint8_t mode;uint64_t flags;";
const char ulog_hil_actuator_controls_name[] = "hil_actuator_controls";

int32_t ulog_format_hil_actuator_controls(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_hil_actuator_controls_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_hil_actuator_controls_format, sizeof(ulog_hil_actuator_controls_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_hil_actuator_controls(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_hil_actuator_controls_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_hil_actuator_controls_name, sizeof(ulog_hil_actuator_controls_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_hil_actuator_controls(ulog_t *log, ulog_msg_id_t id, const ulog_hil_actuator_controls_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint64_t)
                    + sizeof(float)*16
                    + sizeof(uint8_t)
                    + sizeof(uint64_t)
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

    /* Control outputs -1 .. 1. Channel assignment depends on the simulated hardware. */
    if (lfs_file_write(log->lfs, log->file, src->controls, sizeof(src->controls)) < 0) {
        return 1;
    }

    /* System mode. Includes arming state. */
    if (lfs_file_write(log->lfs, log->file, &src->mode, sizeof(src->mode)) < 0) {
        return 1;
    }

    /* Flags as bitfield, 1: indicate simulation using lockstep. */
    if (lfs_file_write(log->lfs, log->file, &src->flags, sizeof(src->flags)) < 0) {
        return 1;
    }

    
    return 0;
}
