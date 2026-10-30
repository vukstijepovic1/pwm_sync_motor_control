/**
 * @file    ulog_gimbal_manager_information.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_gimbal_manager_information.h"
#include "ulog_def.h"

const char ulog_gimbal_manager_information_format[] = "gimbal_manager_information:uint64_t timestamp;uint32_t time_boot_ms;uint32_t cap_flags;uint8_t gimbal_device_id;float roll_min;float roll_max;float pitch_min;float pitch_max;float yaw_min;float yaw_max;";
const char ulog_gimbal_manager_information_name[] = "gimbal_manager_information";

int32_t ulog_format_gimbal_manager_information(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_gimbal_manager_information_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_gimbal_manager_information_format, sizeof(ulog_gimbal_manager_information_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_gimbal_manager_information(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_gimbal_manager_information_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_gimbal_manager_information_name, sizeof(ulog_gimbal_manager_information_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_gimbal_manager_information(ulog_t *log, ulog_msg_id_t id, const ulog_gimbal_manager_information_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
                    + sizeof(uint32_t)
                    + sizeof(uint8_t)
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

    /* Bitmap of gimbal capability flags. */
    if (lfs_file_write(log->lfs, log->file, &src->cap_flags, sizeof(src->cap_flags)) < 0) {
        return 1;
    }

    /* Gimbal device ID that this gimbal manager is responsible for. Component ID of gimbal device (or 1-6 for non-MAVLink gimbal). */
    if (lfs_file_write(log->lfs, log->file, &src->gimbal_device_id, sizeof(src->gimbal_device_id)) < 0) {
        return 1;
    }

    /* Minimum hardware roll angle (positive: rolling to the right, negative: rolling to the left) [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->roll_min, sizeof(src->roll_min)) < 0) {
        return 1;
    }

    /* Maximum hardware roll angle (positive: rolling to the right, negative: rolling to the left) [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->roll_max, sizeof(src->roll_max)) < 0) {
        return 1;
    }

    /* Minimum pitch angle (positive: up, negative: down) [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->pitch_min, sizeof(src->pitch_min)) < 0) {
        return 1;
    }

    /* Maximum pitch angle (positive: up, negative: down) [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->pitch_max, sizeof(src->pitch_max)) < 0) {
        return 1;
    }

    /* Minimum yaw angle (positive: to the right, negative: to the left) [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->yaw_min, sizeof(src->yaw_min)) < 0) {
        return 1;
    }

    /* Maximum yaw angle (positive: to the right, negative: to the left) [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->yaw_max, sizeof(src->yaw_max)) < 0) {
        return 1;
    }

    
    return 0;
}
