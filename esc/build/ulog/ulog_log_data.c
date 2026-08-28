/**
 * @file    ulog_log_data.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_log_data.h"
#include "ulog_def.h"

const char ulog_log_data_format[] = "log_data:uint64_t timestamp;uint16_t id;uint32_t ofs;uint8_t count;uint8_t[90] data;";
const char ulog_log_data_name[] = "log_data";

int32_t ulog_format_log_data(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_log_data_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_log_data_format, sizeof(ulog_log_data_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_log_data(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_log_data_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_log_data_name, sizeof(ulog_log_data_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_log_data(ulog_t *log, ulog_msg_id_t id, const ulog_log_data_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint16_t)
                    + sizeof(uint32_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)*90
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

    /* Log id (from LOG_ENTRY reply) */
    if (lfs_file_write(log->lfs, log->file, &src->id, sizeof(src->id)) < 0) {
        return 1;
    }

    /* Offset into the log */
    if (lfs_file_write(log->lfs, log->file, &src->ofs, sizeof(src->ofs)) < 0) {
        return 1;
    }

    /* Number of bytes (zero for end of log) [bytes] */
    if (lfs_file_write(log->lfs, log->file, &src->count, sizeof(src->count)) < 0) {
        return 1;
    }

    /* log data */
    if (lfs_file_write(log->lfs, log->file, src->data, sizeof(src->data)) < 0) {
        return 1;
    }

    
    return 0;
}
