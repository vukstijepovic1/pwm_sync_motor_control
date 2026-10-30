/**
 * @file    ulog_storage_information.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_storage_information.h"
#include "ulog_def.h"

const char ulog_storage_information_format[] = "storage_information:uint64_t timestamp;uint32_t time_boot_ms;uint8_t storage_id;uint8_t storage_count;uint8_t status;float total_capacity;float used_capacity;float available_capacity;float read_speed;float write_speed;uint8_t type;char[32] name;uint8_t storage_usage;";
const char ulog_storage_information_name[] = "storage_information";

int32_t ulog_format_storage_information(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_storage_information_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_storage_information_format, sizeof(ulog_storage_information_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_storage_information(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_storage_information_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_storage_information_name, sizeof(ulog_storage_information_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_storage_information(ulog_t *log, ulog_msg_id_t id, const ulog_storage_information_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(uint8_t)
                    + sizeof(char)*32
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

    /* Storage ID (1 for first, 2 for second, etc.) */
    if (lfs_file_write(log->lfs, log->file, &src->storage_id, sizeof(src->storage_id)) < 0) {
        return 1;
    }

    /* Number of storage devices */
    if (lfs_file_write(log->lfs, log->file, &src->storage_count, sizeof(src->storage_count)) < 0) {
        return 1;
    }

    /* Status of storage */
    if (lfs_file_write(log->lfs, log->file, &src->status, sizeof(src->status)) < 0) {
        return 1;
    }

    /* Total capacity. If storage is not ready (STORAGE_STATUS_READY) value will be ignored. [MiB] */
    if (lfs_file_write(log->lfs, log->file, &src->total_capacity, sizeof(src->total_capacity)) < 0) {
        return 1;
    }

    /* Used capacity. If storage is not ready (STORAGE_STATUS_READY) value will be ignored. [MiB] */
    if (lfs_file_write(log->lfs, log->file, &src->used_capacity, sizeof(src->used_capacity)) < 0) {
        return 1;
    }

    /* Available storage capacity. If storage is not ready (STORAGE_STATUS_READY) value will be ignored. [MiB] */
    if (lfs_file_write(log->lfs, log->file, &src->available_capacity, sizeof(src->available_capacity)) < 0) {
        return 1;
    }

    /* Read speed. [MiB/s] */
    if (lfs_file_write(log->lfs, log->file, &src->read_speed, sizeof(src->read_speed)) < 0) {
        return 1;
    }

    /* Write speed. [MiB/s] */
    if (lfs_file_write(log->lfs, log->file, &src->write_speed, sizeof(src->write_speed)) < 0) {
        return 1;
    }

    /* Type of storage */
    if (lfs_file_write(log->lfs, log->file, &src->type, sizeof(src->type)) < 0) {
        return 1;
    }

    /* Textual storage name to be used in UI (microSD 1, Internal Memory, etc.) This is a NULL terminated string. If it is exactly 32 characters long, add a terminating NULL. If this string is empty, the generic type is shown to the user. */
    if (lfs_file_write(log->lfs, log->file, src->name, sizeof(src->name)) < 0) {
        return 1;
    }

    /* Flags indicating whether this instance is preferred storage for photos, videos, etc.
        Note: Implementations should initially set the flags on the system-default storage id used for saving media (if possible/supported).
        This setting can then be overridden using MAV_CMD_SET_STORAGE_USAGE.
        If the media usage flags are not set, a GCS may assume storage ID 1 is the default storage for all media types. */
    if (lfs_file_write(log->lfs, log->file, &src->storage_usage, sizeof(src->storage_usage)) < 0) {
        return 1;
    }

    
    return 0;
}
