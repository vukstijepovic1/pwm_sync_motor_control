/**
 * @file    ulog_data_transmission_handshake.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_data_transmission_handshake.h"
#include "ulog_def.h"

const char ulog_data_transmission_handshake_format[] = "data_transmission_handshake:uint64_t timestamp;uint8_t type;uint32_t size;uint16_t width;uint16_t height;uint16_t packets;uint8_t payload;uint8_t jpg_quality;";
const char ulog_data_transmission_handshake_name[] = "data_transmission_handshake";

int32_t ulog_format_data_transmission_handshake(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_data_transmission_handshake_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_data_transmission_handshake_format, sizeof(ulog_data_transmission_handshake_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_data_transmission_handshake(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_data_transmission_handshake_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_data_transmission_handshake_name, sizeof(ulog_data_transmission_handshake_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_data_transmission_handshake(ulog_t *log, ulog_msg_id_t id, const ulog_data_transmission_handshake_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint32_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
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

    /* Type of requested/acknowledged data. */
    if (lfs_file_write(log->lfs, log->file, &src->type, sizeof(src->type)) < 0) {
        return 1;
    }

    /* total data size (set on ACK only). [bytes] */
    if (lfs_file_write(log->lfs, log->file, &src->size, sizeof(src->size)) < 0) {
        return 1;
    }

    /* Width of a matrix or image. */
    if (lfs_file_write(log->lfs, log->file, &src->width, sizeof(src->width)) < 0) {
        return 1;
    }

    /* Height of a matrix or image. */
    if (lfs_file_write(log->lfs, log->file, &src->height, sizeof(src->height)) < 0) {
        return 1;
    }

    /* Number of packets being sent (set on ACK only). */
    if (lfs_file_write(log->lfs, log->file, &src->packets, sizeof(src->packets)) < 0) {
        return 1;
    }

    /* Payload size per packet (normally 253 byte, see DATA field size in message ENCAPSULATED_DATA) (set on ACK only). [bytes] */
    if (lfs_file_write(log->lfs, log->file, &src->payload, sizeof(src->payload)) < 0) {
        return 1;
    }

    /* JPEG quality. Values: [1-100]. [%] */
    if (lfs_file_write(log->lfs, log->file, &src->jpg_quality, sizeof(src->jpg_quality)) < 0) {
        return 1;
    }

    
    return 0;
}
