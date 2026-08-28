/**
 * @file    ulog_heartbeat.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_heartbeat.h"
#include "ulog_def.h"

const char ulog_heartbeat_format[] = "heartbeat:uint64_t timestamp;uint8_t type;uint8_t autopilot;uint8_t base_mode;uint32_t custom_mode;uint8_t system_status;";
const char ulog_heartbeat_name[] = "heartbeat";

int32_t ulog_format_heartbeat(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_heartbeat_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_heartbeat_format, sizeof(ulog_heartbeat_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_heartbeat(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_heartbeat_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_heartbeat_name, sizeof(ulog_heartbeat_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_heartbeat(ulog_t *log, ulog_msg_id_t id, const ulog_heartbeat_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint32_t)
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

    /* Vehicle or component type. For a flight controller component the vehicle type (quadrotor, helicopter, etc.). For other components the component type (e.g. camera, gimbal, etc.). This should be used in preference to component id for identifying the component type. */
    if (lfs_file_write(log->lfs, log->file, &src->type, sizeof(src->type)) < 0) {
        return 1;
    }

    /* Autopilot type / class. Use MAV_AUTOPILOT_INVALID for components that are not flight controllers. */
    if (lfs_file_write(log->lfs, log->file, &src->autopilot, sizeof(src->autopilot)) < 0) {
        return 1;
    }

    /* System mode bitmap. */
    if (lfs_file_write(log->lfs, log->file, &src->base_mode, sizeof(src->base_mode)) < 0) {
        return 1;
    }

    /* A bitfield for use for autopilot-specific flags */
    if (lfs_file_write(log->lfs, log->file, &src->custom_mode, sizeof(src->custom_mode)) < 0) {
        return 1;
    }

    /* System status flag. */
    if (lfs_file_write(log->lfs, log->file, &src->system_status, sizeof(src->system_status)) < 0) {
        return 1;
    }

    
    return 0;
}
