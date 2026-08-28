/**
 * @file    ulog_protocol_version.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_protocol_version.h"
#include "ulog_def.h"

const char ulog_protocol_version_format[] = "protocol_version:uint64_t timestamp;uint16_t version;uint16_t min_version;uint16_t max_version;uint8_t[8] spec_version_hash;uint8_t[8] library_version_hash;";
const char ulog_protocol_version_name[] = "protocol_version";

int32_t ulog_format_protocol_version(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_protocol_version_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_protocol_version_format, sizeof(ulog_protocol_version_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_protocol_version(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_protocol_version_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_protocol_version_name, sizeof(ulog_protocol_version_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_protocol_version(ulog_t *log, ulog_msg_id_t id, const ulog_protocol_version_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint8_t)*8
                    + sizeof(uint8_t)*8
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

    /* Currently active MAVLink version number * 100: v1.0 is 100, v2.0 is 200, etc. */
    if (lfs_file_write(log->lfs, log->file, &src->version, sizeof(src->version)) < 0) {
        return 1;
    }

    /* Minimum MAVLink version supported */
    if (lfs_file_write(log->lfs, log->file, &src->min_version, sizeof(src->min_version)) < 0) {
        return 1;
    }

    /* Maximum MAVLink version supported (set to the same value as version by default) */
    if (lfs_file_write(log->lfs, log->file, &src->max_version, sizeof(src->max_version)) < 0) {
        return 1;
    }

    /* The first 8 bytes (not characters printed in hex!) of the git hash. */
    if (lfs_file_write(log->lfs, log->file, src->spec_version_hash, sizeof(src->spec_version_hash)) < 0) {
        return 1;
    }

    /* The first 8 bytes (not characters printed in hex!) of the git hash. */
    if (lfs_file_write(log->lfs, log->file, src->library_version_hash, sizeof(src->library_version_hash)) < 0) {
        return 1;
    }

    
    return 0;
}
