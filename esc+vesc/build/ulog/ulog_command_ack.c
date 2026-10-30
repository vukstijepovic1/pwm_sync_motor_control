/**
 * @file    ulog_command_ack.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_command_ack.h"
#include "ulog_def.h"

const char ulog_command_ack_format[] = "command_ack:uint64_t timestamp;uint16_t command;uint8_t result;uint8_t progress;int32_t result_param2;uint8_t target_system;uint8_t target_component;";
const char ulog_command_ack_name[] = "command_ack";

int32_t ulog_format_command_ack(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_command_ack_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_command_ack_format, sizeof(ulog_command_ack_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_command_ack(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_command_ack_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_command_ack_name, sizeof(ulog_command_ack_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_command_ack(ulog_t *log, ulog_msg_id_t id, const ulog_command_ack_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint16_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(int32_t)
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

    /* Command ID (of acknowledged command). */
    if (lfs_file_write(log->lfs, log->file, &src->command, sizeof(src->command)) < 0) {
        return 1;
    }

    /* Result of command. */
    if (lfs_file_write(log->lfs, log->file, &src->result, sizeof(src->result)) < 0) {
        return 1;
    }

    /* The progress percentage when result is MAV_RESULT_IN_PROGRESS. Values: [0-100], or UINT8_MAX if the progress is unknown. [%] */
    if (lfs_file_write(log->lfs, log->file, &src->progress, sizeof(src->progress)) < 0) {
        return 1;
    }

    /* Additional result information. Can be set with a command-specific enum containing command-specific error reasons for why the command might be denied. If used, the associated enum must be documented in the corresponding MAV_CMD (this enum should have a 0 value to indicate "unused" or "unknown"). */
    if (lfs_file_write(log->lfs, log->file, &src->result_param2, sizeof(src->result_param2)) < 0) {
        return 1;
    }

    /* System ID of the target recipient. This is the ID of the system that sent the command for which this COMMAND_ACK is an acknowledgement. */
    if (lfs_file_write(log->lfs, log->file, &src->target_system, sizeof(src->target_system)) < 0) {
        return 1;
    }

    /* Component ID of the target recipient. This is the ID of the system that sent the command for which this COMMAND_ACK is an acknowledgement. */
    if (lfs_file_write(log->lfs, log->file, &src->target_component, sizeof(src->target_component)) < 0) {
        return 1;
    }

    
    return 0;
}
