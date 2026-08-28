/**
 * @file    ulog_time_estimate_to_target.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_time_estimate_to_target.h"
#include "ulog_def.h"

const char ulog_time_estimate_to_target_format[] = "time_estimate_to_target:uint64_t timestamp;int32_t safe_return;int32_t land;int32_t mission_next_item;int32_t mission_end;int32_t commanded_action;";
const char ulog_time_estimate_to_target_name[] = "time_estimate_to_target";

int32_t ulog_format_time_estimate_to_target(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_time_estimate_to_target_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_time_estimate_to_target_format, sizeof(ulog_time_estimate_to_target_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_time_estimate_to_target(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_time_estimate_to_target_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_time_estimate_to_target_name, sizeof(ulog_time_estimate_to_target_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_time_estimate_to_target(ulog_t *log, ulog_msg_id_t id, const ulog_time_estimate_to_target_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
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

    /* Estimated time to complete the vehicle's configured "safe return" action from its current position (e.g. RTL, Smart RTL, etc.). -1 indicates that the vehicle is landed, or that no time estimate available. [s] */
    if (lfs_file_write(log->lfs, log->file, &src->safe_return, sizeof(src->safe_return)) < 0) {
        return 1;
    }

    /* Estimated time for vehicle to complete the LAND action from its current position. -1 indicates that the vehicle is landed, or that no time estimate available. [s] */
    if (lfs_file_write(log->lfs, log->file, &src->land, sizeof(src->land)) < 0) {
        return 1;
    }

    /* Estimated time for reaching/completing the currently active mission item. -1 means no time estimate available. [s] */
    if (lfs_file_write(log->lfs, log->file, &src->mission_next_item, sizeof(src->mission_next_item)) < 0) {
        return 1;
    }

    /* Estimated time for completing the current mission. -1 means no mission active and/or no estimate available. [s] */
    if (lfs_file_write(log->lfs, log->file, &src->mission_end, sizeof(src->mission_end)) < 0) {
        return 1;
    }

    /* Estimated time for completing the current commanded action (i.e. Go To, Takeoff, Land, etc.). -1 means no action active and/or no estimate available. [s] */
    if (lfs_file_write(log->lfs, log->file, &src->commanded_action, sizeof(src->commanded_action)) < 0) {
        return 1;
    }

    
    return 0;
}
