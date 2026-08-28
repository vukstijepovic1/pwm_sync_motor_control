/**
 * @file    ulog_timesync.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_timesync.h"
#include "ulog_def.h"

const char ulog_timesync_format[] = "timesync:uint64_t timestamp;int64_t tc1;int64_t ts1;uint8_t target_system;uint8_t target_component;";
const char ulog_timesync_name[] = "timesync";

int32_t ulog_format_timesync(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_timesync_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_timesync_format, sizeof(ulog_timesync_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_timesync(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_timesync_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_timesync_name, sizeof(ulog_timesync_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_timesync(ulog_t *log, ulog_msg_id_t id, const ulog_timesync_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(int64_t)
                    + sizeof(int64_t)
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

    /* Time sync timestamp 1. Syncing: 0. Responding: Timestamp of responding component. [ns] */
    if (lfs_file_write(log->lfs, log->file, &src->tc1, sizeof(src->tc1)) < 0) {
        return 1;
    }

    /* Time sync timestamp 2. Timestamp of syncing component (mirrored in response). [ns] */
    if (lfs_file_write(log->lfs, log->file, &src->ts1, sizeof(src->ts1)) < 0) {
        return 1;
    }

    /* Target system id. Request: 0 (broadcast) or id of specific system. Response must contain system id of the requesting component. */
    if (lfs_file_write(log->lfs, log->file, &src->target_system, sizeof(src->target_system)) < 0) {
        return 1;
    }

    /* Target component id. Request: 0 (broadcast) or id of specific component. Response must contain component id of the requesting component. */
    if (lfs_file_write(log->lfs, log->file, &src->target_component, sizeof(src->target_component)) < 0) {
        return 1;
    }

    
    return 0;
}
