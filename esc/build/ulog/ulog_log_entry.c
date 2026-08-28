/**
 * @file    ulog_log_entry.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_log_entry.h"
#include "ulog_def.h"

const char ulog_log_entry_format[] = "log_entry:uint64_t timestamp;uint16_t id;uint16_t num_logs;uint16_t last_log_num;uint32_t time_utc;uint32_t size;";
const char ulog_log_entry_name[] = "log_entry";

int32_t ulog_format_log_entry(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_log_entry_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_log_entry_format, sizeof(ulog_log_entry_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_log_entry(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_log_entry_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_log_entry_name, sizeof(ulog_log_entry_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_log_entry(ulog_t *log, ulog_msg_id_t id, const ulog_log_entry_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint32_t)
                    + sizeof(uint32_t)
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

    /* Log id */
    if (lfs_file_write(log->lfs, log->file, &src->id, sizeof(src->id)) < 0) {
        return 1;
    }

    /* Total number of logs */
    if (lfs_file_write(log->lfs, log->file, &src->num_logs, sizeof(src->num_logs)) < 0) {
        return 1;
    }

    /* High log number */
    if (lfs_file_write(log->lfs, log->file, &src->last_log_num, sizeof(src->last_log_num)) < 0) {
        return 1;
    }

    /* UTC timestamp of log since 1970, or 0 if not available [s] */
    if (lfs_file_write(log->lfs, log->file, &src->time_utc, sizeof(src->time_utc)) < 0) {
        return 1;
    }

    /* Size of the log (may be approximate) [bytes] */
    if (lfs_file_write(log->lfs, log->file, &src->size, sizeof(src->size)) < 0) {
        return 1;
    }

    
    return 0;
}
