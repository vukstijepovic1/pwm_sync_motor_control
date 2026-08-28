/**
 * @file    ulog_resource_request.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_resource_request.h"
#include "ulog_def.h"

const char ulog_resource_request_format[] = "resource_request:uint64_t timestamp;uint8_t request_id;uint8_t uri_type;uint8_t[120] uri;uint8_t transfer_type;uint8_t[120] storage;";
const char ulog_resource_request_name[] = "resource_request";

int32_t ulog_format_resource_request(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_resource_request_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_resource_request_format, sizeof(ulog_resource_request_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_resource_request(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_resource_request_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_resource_request_name, sizeof(ulog_resource_request_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_resource_request(ulog_t *log, ulog_msg_id_t id, const ulog_resource_request_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)*120
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)*120
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

    /* Request ID. This ID should be re-used when sending back URI contents */
    if (lfs_file_write(log->lfs, log->file, &src->request_id, sizeof(src->request_id)) < 0) {
        return 1;
    }

    /* The type of requested URI. 0 = a file via URL. 1 = a UAVCAN binary */
    if (lfs_file_write(log->lfs, log->file, &src->uri_type, sizeof(src->uri_type)) < 0) {
        return 1;
    }

    /* The requested unique resource identifier (URI). It is not necessarily a straight domain name (depends on the URI type enum) */
    if (lfs_file_write(log->lfs, log->file, src->uri, sizeof(src->uri)) < 0) {
        return 1;
    }

    /* The way the autopilot wants to receive the URI. 0 = MAVLink FTP. 1 = binary stream. */
    if (lfs_file_write(log->lfs, log->file, &src->transfer_type, sizeof(src->transfer_type)) < 0) {
        return 1;
    }

    /* The storage path the autopilot wants the URI to be stored in. Will only be valid if the transfer_type has a storage associated (e.g. MAVLink FTP). */
    if (lfs_file_write(log->lfs, log->file, src->storage, sizeof(src->storage)) < 0) {
        return 1;
    }

    
    return 0;
}
