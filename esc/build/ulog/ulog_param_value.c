/**
 * @file    ulog_param_value.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_param_value.h"
#include "ulog_def.h"

const char ulog_param_value_format[] = "param_value:uint64_t timestamp;char[16] param_id;float param_value;uint8_t param_type;uint16_t param_count;uint16_t param_index;";
const char ulog_param_value_name[] = "param_value";

int32_t ulog_format_param_value(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_param_value_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_param_value_format, sizeof(ulog_param_value_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_param_value(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_param_value_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_param_value_name, sizeof(ulog_param_value_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_param_value(ulog_t *log, ulog_msg_id_t id, const ulog_param_value_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(char)*16
                    + sizeof(float)
                    + sizeof(uint8_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
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

    /* Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string */
    if (lfs_file_write(log->lfs, log->file, src->param_id, sizeof(src->param_id)) < 0) {
        return 1;
    }

    /* Onboard parameter value */
    if (lfs_file_write(log->lfs, log->file, &src->param_value, sizeof(src->param_value)) < 0) {
        return 1;
    }

    /* Onboard parameter type. */
    if (lfs_file_write(log->lfs, log->file, &src->param_type, sizeof(src->param_type)) < 0) {
        return 1;
    }

    /* Total number of onboard parameters */
    if (lfs_file_write(log->lfs, log->file, &src->param_count, sizeof(src->param_count)) < 0) {
        return 1;
    }

    /* Index of this onboard parameter */
    if (lfs_file_write(log->lfs, log->file, &src->param_index, sizeof(src->param_index)) < 0) {
        return 1;
    }

    
    return 0;
}
