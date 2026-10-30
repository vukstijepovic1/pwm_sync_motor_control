/**
 * @file    ulog_gimbal_manager_status.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_gimbal_manager_status.h"
#include "ulog_def.h"

const char ulog_gimbal_manager_status_format[] = "gimbal_manager_status:uint64_t timestamp;uint32_t time_boot_ms;uint32_t flags;uint8_t gimbal_device_id;uint8_t primary_control_sysid;uint8_t primary_control_compid;uint8_t secondary_control_sysid;uint8_t secondary_control_compid;";
const char ulog_gimbal_manager_status_name[] = "gimbal_manager_status";

int32_t ulog_format_gimbal_manager_status(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_gimbal_manager_status_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_gimbal_manager_status_format, sizeof(ulog_gimbal_manager_status_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_gimbal_manager_status(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_gimbal_manager_status_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_gimbal_manager_status_name, sizeof(ulog_gimbal_manager_status_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_gimbal_manager_status(ulog_t *log, ulog_msg_id_t id, const ulog_gimbal_manager_status_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
                    + sizeof(uint32_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
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

    /* Timestamp (time since system boot). [ms] */
    if (lfs_file_write(log->lfs, log->file, &src->time_boot_ms, sizeof(src->time_boot_ms)) < 0) {
        return 1;
    }

    /* High level gimbal manager flags currently applied. */
    if (lfs_file_write(log->lfs, log->file, &src->flags, sizeof(src->flags)) < 0) {
        return 1;
    }

    /* Gimbal device ID that this gimbal manager is responsible for. Component ID of gimbal device (or 1-6 for non-MAVLink gimbal). */
    if (lfs_file_write(log->lfs, log->file, &src->gimbal_device_id, sizeof(src->gimbal_device_id)) < 0) {
        return 1;
    }

    /* System ID of MAVLink component with primary control, 0 for none. */
    if (lfs_file_write(log->lfs, log->file, &src->primary_control_sysid, sizeof(src->primary_control_sysid)) < 0) {
        return 1;
    }

    /* Component ID of MAVLink component with primary control, 0 for none. */
    if (lfs_file_write(log->lfs, log->file, &src->primary_control_compid, sizeof(src->primary_control_compid)) < 0) {
        return 1;
    }

    /* System ID of MAVLink component with secondary control, 0 for none. */
    if (lfs_file_write(log->lfs, log->file, &src->secondary_control_sysid, sizeof(src->secondary_control_sysid)) < 0) {
        return 1;
    }

    /* Component ID of MAVLink component with secondary control, 0 for none. */
    if (lfs_file_write(log->lfs, log->file, &src->secondary_control_compid, sizeof(src->secondary_control_compid)) < 0) {
        return 1;
    }

    
    return 0;
}
