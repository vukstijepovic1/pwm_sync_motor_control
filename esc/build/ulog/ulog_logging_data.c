/**
 * @file    ulog_logging_data.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_logging_data.h"
#include "ulog_def.h"

const char ulog_logging_data_format[] = "logging_data:uint64_t timestamp;uint8_t target_system;uint8_t target_component;uint16_t sequence;uint8_t length;uint8_t first_message_offset;uint8_t[249] data;";
const char ulog_logging_data_name[] = "logging_data";

int32_t ulog_format_logging_data(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_logging_data_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_logging_data_format, sizeof(ulog_logging_data_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_logging_data(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_logging_data_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_logging_data_name, sizeof(ulog_logging_data_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_logging_data(ulog_t *log, ulog_msg_id_t id, const ulog_logging_data_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint16_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)*249
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

    /* system ID of the target */
    if (lfs_file_write(log->lfs, log->file, &src->target_system, sizeof(src->target_system)) < 0) {
        return 1;
    }

    /* component ID of the target */
    if (lfs_file_write(log->lfs, log->file, &src->target_component, sizeof(src->target_component)) < 0) {
        return 1;
    }

    /* sequence number (can wrap) */
    if (lfs_file_write(log->lfs, log->file, &src->sequence, sizeof(src->sequence)) < 0) {
        return 1;
    }

    /* data length [bytes] */
    if (lfs_file_write(log->lfs, log->file, &src->length, sizeof(src->length)) < 0) {
        return 1;
    }

    /* offset into data where first message starts. This can be used for recovery, when a previous message got lost (set to UINT8_MAX if no start exists). [bytes] */
    if (lfs_file_write(log->lfs, log->file, &src->first_message_offset, sizeof(src->first_message_offset)) < 0) {
        return 1;
    }

    /* logged data */
    if (lfs_file_write(log->lfs, log->file, src->data, sizeof(src->data)) < 0) {
        return 1;
    }

    
    return 0;
}
