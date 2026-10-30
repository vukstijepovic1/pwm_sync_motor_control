/**
 * @file    ulog_mount_orientation.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_mount_orientation.h"
#include "ulog_def.h"

const char ulog_mount_orientation_format[] = "mount_orientation:uint64_t timestamp;uint32_t time_boot_ms;float roll;float pitch;float yaw;float yaw_absolute;";
const char ulog_mount_orientation_name[] = "mount_orientation";

int32_t ulog_format_mount_orientation(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_mount_orientation_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_mount_orientation_format, sizeof(ulog_mount_orientation_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_mount_orientation(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_mount_orientation_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_mount_orientation_name, sizeof(ulog_mount_orientation_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_mount_orientation(ulog_t *log, ulog_msg_id_t id, const ulog_mount_orientation_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
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

    /* Roll in global frame (set to NaN for invalid). [deg] */
    if (lfs_file_write(log->lfs, log->file, &src->roll, sizeof(src->roll)) < 0) {
        return 1;
    }

    /* Pitch in global frame (set to NaN for invalid). [deg] */
    if (lfs_file_write(log->lfs, log->file, &src->pitch, sizeof(src->pitch)) < 0) {
        return 1;
    }

    /* Yaw relative to vehicle (set to NaN for invalid). [deg] */
    if (lfs_file_write(log->lfs, log->file, &src->yaw, sizeof(src->yaw)) < 0) {
        return 1;
    }

    /* Yaw in absolute frame relative to Earth's North, north is 0 (set to NaN for invalid). [deg] */
    if (lfs_file_write(log->lfs, log->file, &src->yaw_absolute, sizeof(src->yaw_absolute)) < 0) {
        return 1;
    }

    
    return 0;
}
