/**
 * @file    ulog_command_int.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_command_int.h"
#include "ulog_def.h"

const char ulog_command_int_format[] = "command_int:uint64_t timestamp;uint8_t target_system;uint8_t target_component;uint8_t frame;uint16_t command;uint8_t current;uint8_t autocontinue;float param1;float param2;float param3;float param4;int32_t x;int32_t y;float z;";
const char ulog_command_int_name[] = "command_int";

int32_t ulog_format_command_int(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_command_int_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_command_int_format, sizeof(ulog_command_int_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_command_int(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_command_int_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_command_int_name, sizeof(ulog_command_int_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_command_int(ulog_t *log, ulog_msg_id_t id, const ulog_command_int_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint16_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
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

    /* System ID */
    if (lfs_file_write(log->lfs, log->file, &src->target_system, sizeof(src->target_system)) < 0) {
        return 1;
    }

    /* Component ID */
    if (lfs_file_write(log->lfs, log->file, &src->target_component, sizeof(src->target_component)) < 0) {
        return 1;
    }

    /* The coordinate system of the COMMAND. */
    if (lfs_file_write(log->lfs, log->file, &src->frame, sizeof(src->frame)) < 0) {
        return 1;
    }

    /* The scheduled action for the mission item. */
    if (lfs_file_write(log->lfs, log->file, &src->command, sizeof(src->command)) < 0) {
        return 1;
    }

    /* Not used. */
    if (lfs_file_write(log->lfs, log->file, &src->current, sizeof(src->current)) < 0) {
        return 1;
    }

    /* Not used (set 0). */
    if (lfs_file_write(log->lfs, log->file, &src->autocontinue, sizeof(src->autocontinue)) < 0) {
        return 1;
    }

    /* PARAM1, see MAV_CMD enum */
    if (lfs_file_write(log->lfs, log->file, &src->param1, sizeof(src->param1)) < 0) {
        return 1;
    }

    /* PARAM2, see MAV_CMD enum */
    if (lfs_file_write(log->lfs, log->file, &src->param2, sizeof(src->param2)) < 0) {
        return 1;
    }

    /* PARAM3, see MAV_CMD enum */
    if (lfs_file_write(log->lfs, log->file, &src->param3, sizeof(src->param3)) < 0) {
        return 1;
    }

    /* PARAM4, see MAV_CMD enum */
    if (lfs_file_write(log->lfs, log->file, &src->param4, sizeof(src->param4)) < 0) {
        return 1;
    }

    /* PARAM5 / local: x position in meters * 1e4, global: latitude in degrees * 10^7 */
    if (lfs_file_write(log->lfs, log->file, &src->x, sizeof(src->x)) < 0) {
        return 1;
    }

    /* PARAM6 / local: y position in meters * 1e4, global: longitude in degrees * 10^7 */
    if (lfs_file_write(log->lfs, log->file, &src->y, sizeof(src->y)) < 0) {
        return 1;
    }

    /* PARAM7 / z position: global: altitude in meters (relative or absolute, depending on frame). */
    if (lfs_file_write(log->lfs, log->file, &src->z, sizeof(src->z)) < 0) {
        return 1;
    }

    
    return 0;
}
