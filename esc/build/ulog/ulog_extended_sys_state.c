/**
 * @file    ulog_extended_sys_state.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_extended_sys_state.h"
#include "ulog_def.h"

const char ulog_extended_sys_state_format[] = "extended_sys_state:uint64_t timestamp;uint8_t vtol_state;uint8_t landed_state;";
const char ulog_extended_sys_state_name[] = "extended_sys_state";

int32_t ulog_format_extended_sys_state(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_extended_sys_state_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_extended_sys_state_format, sizeof(ulog_extended_sys_state_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_extended_sys_state(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_extended_sys_state_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_extended_sys_state_name, sizeof(ulog_extended_sys_state_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_extended_sys_state(ulog_t *log, ulog_msg_id_t id, const ulog_extended_sys_state_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
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

    /* The VTOL state if applicable. Is set to MAV_VTOL_STATE_UNDEFINED if UAV is not in VTOL configuration. */
    if (lfs_file_write(log->lfs, log->file, &src->vtol_state, sizeof(src->vtol_state)) < 0) {
        return 1;
    }

    /* The landed state. Is set to MAV_LANDED_STATE_UNDEFINED if landed state is unknown. */
    if (lfs_file_write(log->lfs, log->file, &src->landed_state, sizeof(src->landed_state)) < 0) {
        return 1;
    }

    
    return 0;
}
