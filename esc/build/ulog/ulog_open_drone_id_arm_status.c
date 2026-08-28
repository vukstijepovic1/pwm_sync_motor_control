/**
 * @file    ulog_open_drone_id_arm_status.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_open_drone_id_arm_status.h"
#include "ulog_def.h"

const char ulog_open_drone_id_arm_status_format[] = "open_drone_id_arm_status:uint64_t timestamp;uint8_t status;char[50] error;";
const char ulog_open_drone_id_arm_status_name[] = "open_drone_id_arm_status";

int32_t ulog_format_open_drone_id_arm_status(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_open_drone_id_arm_status_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_open_drone_id_arm_status_format, sizeof(ulog_open_drone_id_arm_status_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_open_drone_id_arm_status(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_open_drone_id_arm_status_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_open_drone_id_arm_status_name, sizeof(ulog_open_drone_id_arm_status_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_open_drone_id_arm_status(ulog_t *log, ulog_msg_id_t id, const ulog_open_drone_id_arm_status_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(char)*50
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

    /* Status level indicating if arming is allowed. */
    if (lfs_file_write(log->lfs, log->file, &src->status, sizeof(src->status)) < 0) {
        return 1;
    }

    /* Text error message, should be empty if status is good to arm. Fill with nulls in unused portion. */
    if (lfs_file_write(log->lfs, log->file, src->error, sizeof(src->error)) < 0) {
        return 1;
    }

    
    return 0;
}
