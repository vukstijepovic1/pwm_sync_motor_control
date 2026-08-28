/**
 * @file    ulog_debug_float_array.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_debug_float_array.h"
#include "ulog_def.h"

const char ulog_debug_float_array_format[] = "debug_float_array:uint64_t timestamp;uint64_t time_usec;char[10] name;uint16_t array_id;float[58] data;";
const char ulog_debug_float_array_name[] = "debug_float_array";

int32_t ulog_format_debug_float_array(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_debug_float_array_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_debug_float_array_format, sizeof(ulog_debug_float_array_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_debug_float_array(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_debug_float_array_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_debug_float_array_name, sizeof(ulog_debug_float_array_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_debug_float_array(ulog_t *log, ulog_msg_id_t id, const ulog_debug_float_array_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint64_t)
                    + sizeof(char)*10
                    + sizeof(uint16_t)
                    + sizeof(float)*58
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

    /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->time_usec, sizeof(src->time_usec)) < 0) {
        return 1;
    }

    /* Name, for human-friendly display in a Ground Control Station */
    if (lfs_file_write(log->lfs, log->file, src->name, sizeof(src->name)) < 0) {
        return 1;
    }

    /* Unique ID used to discriminate between arrays */
    if (lfs_file_write(log->lfs, log->file, &src->array_id, sizeof(src->array_id)) < 0) {
        return 1;
    }

    /* data */
    if (lfs_file_write(log->lfs, log->file, src->data, sizeof(src->data)) < 0) {
        return 1;
    }

    
    return 0;
}
