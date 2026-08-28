/**
 * @file    ulog_file_transfer_protocol.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_file_transfer_protocol.h"
#include "ulog_def.h"

const char ulog_file_transfer_protocol_format[] = "file_transfer_protocol:uint64_t timestamp;uint8_t target_network;uint8_t target_system;uint8_t target_component;uint8_t[251] payload;";
const char ulog_file_transfer_protocol_name[] = "file_transfer_protocol";

int32_t ulog_format_file_transfer_protocol(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_file_transfer_protocol_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_file_transfer_protocol_format, sizeof(ulog_file_transfer_protocol_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_file_transfer_protocol(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_file_transfer_protocol_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_file_transfer_protocol_name, sizeof(ulog_file_transfer_protocol_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_file_transfer_protocol(ulog_t *log, ulog_msg_id_t id, const ulog_file_transfer_protocol_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)*251
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

    /* Network ID (0 for broadcast) */
    if (lfs_file_write(log->lfs, log->file, &src->target_network, sizeof(src->target_network)) < 0) {
        return 1;
    }

    /* System ID (0 for broadcast) */
    if (lfs_file_write(log->lfs, log->file, &src->target_system, sizeof(src->target_system)) < 0) {
        return 1;
    }

    /* Component ID (0 for broadcast) */
    if (lfs_file_write(log->lfs, log->file, &src->target_component, sizeof(src->target_component)) < 0) {
        return 1;
    }

    /* Variable length payload. The length is defined by the remaining message length when subtracting the header and other fields. The content/format of this block is defined in https://mavlink.io/en/services/ftp.html. */
    if (lfs_file_write(log->lfs, log->file, src->payload, sizeof(src->payload)) < 0) {
        return 1;
    }

    
    return 0;
}
