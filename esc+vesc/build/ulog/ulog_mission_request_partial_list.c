/**
 * @file    ulog_mission_request_partial_list.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_mission_request_partial_list.h"
#include "ulog_def.h"

const char ulog_mission_request_partial_list_format[] = "mission_request_partial_list:uint64_t timestamp;uint8_t target_system;uint8_t target_component;int16_t start_index;int16_t end_index;uint8_t mission_type;";
const char ulog_mission_request_partial_list_name[] = "mission_request_partial_list";

int32_t ulog_format_mission_request_partial_list(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_mission_request_partial_list_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_mission_request_partial_list_format, sizeof(ulog_mission_request_partial_list_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_mission_request_partial_list(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_mission_request_partial_list_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_mission_request_partial_list_name, sizeof(ulog_mission_request_partial_list_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_mission_request_partial_list(ulog_t *log, ulog_msg_id_t id, const ulog_mission_request_partial_list_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
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

    /* System ID */
    if (lfs_file_write(log->lfs, log->file, &src->target_system, sizeof(src->target_system)) < 0) {
        return 1;
    }

    /* Component ID */
    if (lfs_file_write(log->lfs, log->file, &src->target_component, sizeof(src->target_component)) < 0) {
        return 1;
    }

    /* Start index */
    if (lfs_file_write(log->lfs, log->file, &src->start_index, sizeof(src->start_index)) < 0) {
        return 1;
    }

    /* End index, -1 by default (-1: send list to end). Else a valid index of the list */
    if (lfs_file_write(log->lfs, log->file, &src->end_index, sizeof(src->end_index)) < 0) {
        return 1;
    }

    /* Mission type. */
    if (lfs_file_write(log->lfs, log->file, &src->mission_type, sizeof(src->mission_type)) < 0) {
        return 1;
    }

    
    return 0;
}
