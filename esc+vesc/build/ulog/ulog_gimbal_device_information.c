/**
 * @file    ulog_gimbal_device_information.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_gimbal_device_information.h"
#include "ulog_def.h"

const char ulog_gimbal_device_information_format[] = "gimbal_device_information:uint64_t timestamp;uint32_t time_boot_ms;char[32] vendor_name;char[32] model_name;char[32] custom_name;uint32_t firmware_version;uint32_t hardware_version;uint64_t uid;uint16_t cap_flags;uint16_t custom_cap_flags;float roll_min;float roll_max;float pitch_min;float pitch_max;float yaw_min;float yaw_max;uint8_t gimbal_device_id;";
const char ulog_gimbal_device_information_name[] = "gimbal_device_information";

int32_t ulog_format_gimbal_device_information(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_gimbal_device_information_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_gimbal_device_information_format, sizeof(ulog_gimbal_device_information_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_gimbal_device_information(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_gimbal_device_information_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_gimbal_device_information_name, sizeof(ulog_gimbal_device_information_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_gimbal_device_information(ulog_t *log, ulog_msg_id_t id, const ulog_gimbal_device_information_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
                    + sizeof(char)*32
                    + sizeof(char)*32
                    + sizeof(char)*32
                    + sizeof(uint32_t)
                    + sizeof(uint32_t)
                    + sizeof(uint64_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
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

    /* Name of the gimbal vendor. */
    if (lfs_file_write(log->lfs, log->file, src->vendor_name, sizeof(src->vendor_name)) < 0) {
        return 1;
    }

    /* Name of the gimbal model. */
    if (lfs_file_write(log->lfs, log->file, src->model_name, sizeof(src->model_name)) < 0) {
        return 1;
    }

    /* Custom name of the gimbal given to it by the user. */
    if (lfs_file_write(log->lfs, log->file, src->custom_name, sizeof(src->custom_name)) < 0) {
        return 1;
    }

    /* Version of the gimbal firmware, encoded as: (Dev & 0xff) << 24 | (Patch & 0xff) << 16 | (Minor & 0xff) << 8 | (Major & 0xff). */
    if (lfs_file_write(log->lfs, log->file, &src->firmware_version, sizeof(src->firmware_version)) < 0) {
        return 1;
    }

    /* Version of the gimbal hardware, encoded as: (Dev & 0xff) << 24 | (Patch & 0xff) << 16 | (Minor & 0xff) << 8 | (Major & 0xff). */
    if (lfs_file_write(log->lfs, log->file, &src->hardware_version, sizeof(src->hardware_version)) < 0) {
        return 1;
    }

    /* UID of gimbal hardware (0 if unknown). */
    if (lfs_file_write(log->lfs, log->file, &src->uid, sizeof(src->uid)) < 0) {
        return 1;
    }

    /* Bitmap of gimbal capability flags. */
    if (lfs_file_write(log->lfs, log->file, &src->cap_flags, sizeof(src->cap_flags)) < 0) {
        return 1;
    }

    /* Bitmap for use for gimbal-specific capability flags. */
    if (lfs_file_write(log->lfs, log->file, &src->custom_cap_flags, sizeof(src->custom_cap_flags)) < 0) {
        return 1;
    }

    /* Minimum hardware roll angle (positive: rolling to the right, negative: rolling to the left). NAN if unknown. [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->roll_min, sizeof(src->roll_min)) < 0) {
        return 1;
    }

    /* Maximum hardware roll angle (positive: rolling to the right, negative: rolling to the left). NAN if unknown. [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->roll_max, sizeof(src->roll_max)) < 0) {
        return 1;
    }

    /* Minimum hardware pitch angle (positive: up, negative: down). NAN if unknown. [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->pitch_min, sizeof(src->pitch_min)) < 0) {
        return 1;
    }

    /* Maximum hardware pitch angle (positive: up, negative: down). NAN if unknown. [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->pitch_max, sizeof(src->pitch_max)) < 0) {
        return 1;
    }

    /* Minimum hardware yaw angle (positive: to the right, negative: to the left). NAN if unknown. [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->yaw_min, sizeof(src->yaw_min)) < 0) {
        return 1;
    }

    /* Maximum hardware yaw angle (positive: to the right, negative: to the left). NAN if unknown. [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->yaw_max, sizeof(src->yaw_max)) < 0) {
        return 1;
    }

    /* This field is to be used if the gimbal manager and the gimbal device are the same component and hence have the same component ID. This field is then set to a number between 1-6. If the component ID is separate, this field is not required and must be set to 0. */
    if (lfs_file_write(log->lfs, log->file, &src->gimbal_device_id, sizeof(src->gimbal_device_id)) < 0) {
        return 1;
    }

    
    return 0;
}
