/**
 * @file    ulog_esc_info.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_esc_info.h"
#include "ulog_def.h"

const char ulog_esc_info_format[] = "esc_info:uint64_t timestamp;uint8_t index;uint64_t time_usec;uint16_t counter;uint8_t count;uint8_t connection_type;uint8_t info;uint16_t[4] failure_flags;uint32_t[4] error_count;int16_t[4] temperature;";
const char ulog_esc_info_name[] = "esc_info";

int32_t ulog_format_esc_info(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_esc_info_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_esc_info_format, sizeof(ulog_esc_info_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_esc_info(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_esc_info_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_esc_info_name, sizeof(ulog_esc_info_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_esc_info(ulog_t *log, ulog_msg_id_t id, const ulog_esc_info_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint64_t)
                    + sizeof(uint16_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint16_t)*4
                    + sizeof(uint32_t)*4
                    + sizeof(int16_t)*4
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

    /* Index of the first ESC in this message. minValue = 0, maxValue = 60, increment = 4. */
    if (lfs_file_write(log->lfs, log->file, &src->index, sizeof(src->index)) < 0) {
        return 1;
    }

    /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->time_usec, sizeof(src->time_usec)) < 0) {
        return 1;
    }

    /* Counter of data packets received. */
    if (lfs_file_write(log->lfs, log->file, &src->counter, sizeof(src->counter)) < 0) {
        return 1;
    }

    /* Total number of ESCs in all messages of this type. Message fields with an index higher than this should be ignored because they contain invalid data. */
    if (lfs_file_write(log->lfs, log->file, &src->count, sizeof(src->count)) < 0) {
        return 1;
    }

    /* Connection type protocol for all ESC. */
    if (lfs_file_write(log->lfs, log->file, &src->connection_type, sizeof(src->connection_type)) < 0) {
        return 1;
    }

    /* Information regarding online/offline status of each ESC. */
    if (lfs_file_write(log->lfs, log->file, &src->info, sizeof(src->info)) < 0) {
        return 1;
    }

    /* Bitmap of ESC failure flags. */
    if (lfs_file_write(log->lfs, log->file, src->failure_flags, sizeof(src->failure_flags)) < 0) {
        return 1;
    }

    /* Number of reported errors by each ESC since boot. */
    if (lfs_file_write(log->lfs, log->file, src->error_count, sizeof(src->error_count)) < 0) {
        return 1;
    }

    /* Temperature of each ESC. INT16_MAX: if data not supplied by ESC. [cdegC] */
    if (lfs_file_write(log->lfs, log->file, src->temperature, sizeof(src->temperature)) < 0) {
        return 1;
    }

    
    return 0;
}
