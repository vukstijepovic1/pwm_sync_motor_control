/**
 * @file    ulog_request_data_stream.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_request_data_stream.h"
#include "ulog_def.h"

const char ulog_request_data_stream_format[] = "request_data_stream:uint64_t timestamp;uint8_t target_system;uint8_t target_component;uint8_t req_stream_id;uint16_t req_message_rate;uint8_t start_stop;";
const char ulog_request_data_stream_name[] = "request_data_stream";

int32_t ulog_format_request_data_stream(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_request_data_stream_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_request_data_stream_format, sizeof(ulog_request_data_stream_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_request_data_stream(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_request_data_stream_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_request_data_stream_name, sizeof(ulog_request_data_stream_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_request_data_stream(ulog_t *log, ulog_msg_id_t id, const ulog_request_data_stream_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint16_t)
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

    /* The target requested to send the message stream. */
    if (lfs_file_write(log->lfs, log->file, &src->target_system, sizeof(src->target_system)) < 0) {
        return 1;
    }

    /* The target requested to send the message stream. */
    if (lfs_file_write(log->lfs, log->file, &src->target_component, sizeof(src->target_component)) < 0) {
        return 1;
    }

    /* The ID of the requested data stream */
    if (lfs_file_write(log->lfs, log->file, &src->req_stream_id, sizeof(src->req_stream_id)) < 0) {
        return 1;
    }

    /* The requested message rate [Hz] */
    if (lfs_file_write(log->lfs, log->file, &src->req_message_rate, sizeof(src->req_message_rate)) < 0) {
        return 1;
    }

    /* 1 to start sending, 0 to stop sending. */
    if (lfs_file_write(log->lfs, log->file, &src->start_stop, sizeof(src->start_stop)) < 0) {
        return 1;
    }

    
    return 0;
}
