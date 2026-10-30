/**
 * @file    ulog_camera_capture_status.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_camera_capture_status.h"
#include "ulog_def.h"

const char ulog_camera_capture_status_format[] = "camera_capture_status:uint64_t timestamp;uint32_t time_boot_ms;uint8_t image_status;uint8_t video_status;float image_interval;uint32_t recording_time_ms;float available_capacity;int32_t image_count;uint8_t camera_device_id;";
const char ulog_camera_capture_status_name[] = "camera_capture_status";

int32_t ulog_format_camera_capture_status(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_camera_capture_status_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_camera_capture_status_format, sizeof(ulog_camera_capture_status_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_camera_capture_status(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_camera_capture_status_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_camera_capture_status_name, sizeof(ulog_camera_capture_status_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_camera_capture_status(ulog_t *log, ulog_msg_id_t id, const ulog_camera_capture_status_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(float)
                    + sizeof(uint32_t)
                    + sizeof(float)
                    + sizeof(int32_t)
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

    /* Current status of image capturing (0: idle, 1: capture in progress, 2: interval set but idle, 3: interval set and capture in progress) */
    if (lfs_file_write(log->lfs, log->file, &src->image_status, sizeof(src->image_status)) < 0) {
        return 1;
    }

    /* Current status of video capturing (0: idle, 1: capture in progress) */
    if (lfs_file_write(log->lfs, log->file, &src->video_status, sizeof(src->video_status)) < 0) {
        return 1;
    }

    /* Image capture interval [s] */
    if (lfs_file_write(log->lfs, log->file, &src->image_interval, sizeof(src->image_interval)) < 0) {
        return 1;
    }

    /* Elapsed time since recording started (0: Not supported/available). A GCS should compute recording time and use non-zero values of this field to correct any discrepancy. [ms] */
    if (lfs_file_write(log->lfs, log->file, &src->recording_time_ms, sizeof(src->recording_time_ms)) < 0) {
        return 1;
    }

    /* Available storage capacity. [MiB] */
    if (lfs_file_write(log->lfs, log->file, &src->available_capacity, sizeof(src->available_capacity)) < 0) {
        return 1;
    }

    /* Total number of images captured ('forever', or until reset using MAV_CMD_STORAGE_FORMAT). */
    if (lfs_file_write(log->lfs, log->file, &src->image_count, sizeof(src->image_count)) < 0) {
        return 1;
    }

    /* Camera id of a non-MAVLink camera attached to an autopilot (1-6).  0 if the component is a MAVLink camera (with its own component id). */
    if (lfs_file_write(log->lfs, log->file, &src->camera_device_id, sizeof(src->camera_device_id)) < 0) {
        return 1;
    }

    
    return 0;
}
