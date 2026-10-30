/**
 * @file    ulog_local_position_ned_system_global_offset.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_local_position_ned_system_global_offset.h"
#include "ulog_def.h"

const char ulog_local_position_ned_system_global_offset_format[] = "local_position_ned_system_global_offset:uint64_t timestamp;uint32_t time_boot_ms;float x;float y;float z;float roll;float pitch;float yaw;";
const char ulog_local_position_ned_system_global_offset_name[] = "local_position_ned_system_global_offset";

int32_t ulog_format_local_position_ned_system_global_offset(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_local_position_ned_system_global_offset_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_local_position_ned_system_global_offset_format, sizeof(ulog_local_position_ned_system_global_offset_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_local_position_ned_system_global_offset(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_local_position_ned_system_global_offset_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_local_position_ned_system_global_offset_name, sizeof(ulog_local_position_ned_system_global_offset_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_local_position_ned_system_global_offset(ulog_t *log, ulog_msg_id_t id, const ulog_local_position_ned_system_global_offset_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
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

    /* Timestamp (time since system boot). [ms] */
    if (lfs_file_write(log->lfs, log->file, &src->time_boot_ms, sizeof(src->time_boot_ms)) < 0) {
        return 1;
    }

    /* X Position [m] */
    if (lfs_file_write(log->lfs, log->file, &src->x, sizeof(src->x)) < 0) {
        return 1;
    }

    /* Y Position [m] */
    if (lfs_file_write(log->lfs, log->file, &src->y, sizeof(src->y)) < 0) {
        return 1;
    }

    /* Z Position [m] */
    if (lfs_file_write(log->lfs, log->file, &src->z, sizeof(src->z)) < 0) {
        return 1;
    }

    /* Roll [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->roll, sizeof(src->roll)) < 0) {
        return 1;
    }

    /* Pitch [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->pitch, sizeof(src->pitch)) < 0) {
        return 1;
    }

    /* Yaw [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->yaw, sizeof(src->yaw)) < 0) {
        return 1;
    }

    
    return 0;
}
