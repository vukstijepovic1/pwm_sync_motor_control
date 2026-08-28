/**
 * @file    ulog_fence_status.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_fence_status.h"
#include "ulog_def.h"

const char ulog_fence_status_format[] = "fence_status:uint64_t timestamp;uint8_t breach_status;uint16_t breach_count;uint8_t breach_type;uint32_t breach_time;uint8_t breach_mitigation;";
const char ulog_fence_status_name[] = "fence_status";

int32_t ulog_format_fence_status(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_fence_status_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_fence_status_format, sizeof(ulog_fence_status_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_fence_status(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_fence_status_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_fence_status_name, sizeof(ulog_fence_status_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_fence_status(ulog_t *log, ulog_msg_id_t id, const ulog_fence_status_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint16_t)
                    + sizeof(uint8_t)
                    + sizeof(uint32_t)
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

    /* Breach status (0 if currently inside fence, 1 if outside). */
    if (lfs_file_write(log->lfs, log->file, &src->breach_status, sizeof(src->breach_status)) < 0) {
        return 1;
    }

    /* Number of fence breaches. */
    if (lfs_file_write(log->lfs, log->file, &src->breach_count, sizeof(src->breach_count)) < 0) {
        return 1;
    }

    /* Last breach type. */
    if (lfs_file_write(log->lfs, log->file, &src->breach_type, sizeof(src->breach_type)) < 0) {
        return 1;
    }

    /* Time (since boot) of last breach. [ms] */
    if (lfs_file_write(log->lfs, log->file, &src->breach_time, sizeof(src->breach_time)) < 0) {
        return 1;
    }

    /* Active action to prevent fence breach */
    if (lfs_file_write(log->lfs, log->file, &src->breach_mitigation, sizeof(src->breach_mitigation)) < 0) {
        return 1;
    }

    
    return 0;
}
