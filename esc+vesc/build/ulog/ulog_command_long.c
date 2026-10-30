/**
 * @file    ulog_command_long.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_command_long.h"
#include "ulog_def.h"

const char ulog_command_long_format[] = "command_long:uint64_t timestamp;uint8_t target_system;uint8_t target_component;uint16_t command;uint8_t confirmation;float param1;float param2;float param3;float param4;float param5;float param6;float param7;";
const char ulog_command_long_name[] = "command_long";

int32_t ulog_format_command_long(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_command_long_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_command_long_format, sizeof(ulog_command_long_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_command_long(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_command_long_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_command_long_name, sizeof(ulog_command_long_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_command_long(ulog_t *log, ulog_msg_id_t id, const ulog_command_long_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint16_t)
                    + sizeof(uint8_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
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

    /* System which should execute the command */
    if (lfs_file_write(log->lfs, log->file, &src->target_system, sizeof(src->target_system)) < 0) {
        return 1;
    }

    /* Component which should execute the command, 0 for all components */
    if (lfs_file_write(log->lfs, log->file, &src->target_component, sizeof(src->target_component)) < 0) {
        return 1;
    }

    /* Command ID (of command to send). */
    if (lfs_file_write(log->lfs, log->file, &src->command, sizeof(src->command)) < 0) {
        return 1;
    }

    /* 0: First transmission of this command. 1-255: Confirmation transmissions (e.g. for kill command) */
    if (lfs_file_write(log->lfs, log->file, &src->confirmation, sizeof(src->confirmation)) < 0) {
        return 1;
    }

    /* Parameter 1 (for the specific command). */
    if (lfs_file_write(log->lfs, log->file, &src->param1, sizeof(src->param1)) < 0) {
        return 1;
    }

    /* Parameter 2 (for the specific command). */
    if (lfs_file_write(log->lfs, log->file, &src->param2, sizeof(src->param2)) < 0) {
        return 1;
    }

    /* Parameter 3 (for the specific command). */
    if (lfs_file_write(log->lfs, log->file, &src->param3, sizeof(src->param3)) < 0) {
        return 1;
    }

    /* Parameter 4 (for the specific command). */
    if (lfs_file_write(log->lfs, log->file, &src->param4, sizeof(src->param4)) < 0) {
        return 1;
    }

    /* Parameter 5 (for the specific command). */
    if (lfs_file_write(log->lfs, log->file, &src->param5, sizeof(src->param5)) < 0) {
        return 1;
    }

    /* Parameter 6 (for the specific command). */
    if (lfs_file_write(log->lfs, log->file, &src->param6, sizeof(src->param6)) < 0) {
        return 1;
    }

    /* Parameter 7 (for the specific command). */
    if (lfs_file_write(log->lfs, log->file, &src->param7, sizeof(src->param7)) < 0) {
        return 1;
    }

    
    return 0;
}
