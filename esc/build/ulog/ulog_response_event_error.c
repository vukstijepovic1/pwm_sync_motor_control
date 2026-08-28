/**
 * @file    ulog_response_event_error.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_response_event_error.h"
#include "ulog_def.h"

const char ulog_response_event_error_format[] = "response_event_error:uint64_t timestamp;uint8_t target_system;uint8_t target_component;uint16_t sequence;uint16_t sequence_oldest_available;uint8_t reason;";
const char ulog_response_event_error_name[] = "response_event_error";

int32_t ulog_format_response_event_error(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_response_event_error_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_response_event_error_format, sizeof(ulog_response_event_error_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_response_event_error(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_response_event_error_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_response_event_error_name, sizeof(ulog_response_event_error_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_response_event_error(ulog_t *log, ulog_msg_id_t id, const ulog_response_event_error_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint16_t)
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

    /* System ID */
    if (lfs_file_write(log->lfs, log->file, &src->target_system, sizeof(src->target_system)) < 0) {
        return 1;
    }

    /* Component ID */
    if (lfs_file_write(log->lfs, log->file, &src->target_component, sizeof(src->target_component)) < 0) {
        return 1;
    }

    /* Sequence number. */
    if (lfs_file_write(log->lfs, log->file, &src->sequence, sizeof(src->sequence)) < 0) {
        return 1;
    }

    /* Oldest Sequence number that is still available after the sequence set in REQUEST_EVENT. */
    if (lfs_file_write(log->lfs, log->file, &src->sequence_oldest_available, sizeof(src->sequence_oldest_available)) < 0) {
        return 1;
    }

    /* Error reason. */
    if (lfs_file_write(log->lfs, log->file, &src->reason, sizeof(src->reason)) < 0) {
        return 1;
    }

    
    return 0;
}
