/**
 * @file    ulog_camera_tracking_image_status.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_camera_tracking_image_status.h"
#include "ulog_def.h"

const char ulog_camera_tracking_image_status_format[] = "camera_tracking_image_status:uint64_t timestamp;uint8_t tracking_status;uint8_t tracking_mode;uint8_t target_data;float point_x;float point_y;float radius;float rec_top_x;float rec_top_y;float rec_bottom_x;float rec_bottom_y;uint8_t camera_device_id;";
const char ulog_camera_tracking_image_status_name[] = "camera_tracking_image_status";

int32_t ulog_format_camera_tracking_image_status(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_camera_tracking_image_status_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_camera_tracking_image_status_format, sizeof(ulog_camera_tracking_image_status_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_camera_tracking_image_status(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_camera_tracking_image_status_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_camera_tracking_image_status_name, sizeof(ulog_camera_tracking_image_status_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_camera_tracking_image_status(ulog_t *log, ulog_msg_id_t id, const ulog_camera_tracking_image_status_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(float)
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

    /* Current tracking status */
    if (lfs_file_write(log->lfs, log->file, &src->tracking_status, sizeof(src->tracking_status)) < 0) {
        return 1;
    }

    /* Current tracking mode */
    if (lfs_file_write(log->lfs, log->file, &src->tracking_mode, sizeof(src->tracking_mode)) < 0) {
        return 1;
    }

    /* Defines location of target data */
    if (lfs_file_write(log->lfs, log->file, &src->target_data, sizeof(src->target_data)) < 0) {
        return 1;
    }

    /* Current tracked point x value if CAMERA_TRACKING_MODE_POINT (normalized 0..1, 0 is left, 1 is right), NAN if unknown */
    if (lfs_file_write(log->lfs, log->file, &src->point_x, sizeof(src->point_x)) < 0) {
        return 1;
    }

    /* Current tracked point y value if CAMERA_TRACKING_MODE_POINT (normalized 0..1, 0 is top, 1 is bottom), NAN if unknown */
    if (lfs_file_write(log->lfs, log->file, &src->point_y, sizeof(src->point_y)) < 0) {
        return 1;
    }

    /* Current tracked radius if CAMERA_TRACKING_MODE_POINT (normalized 0..1, 0 is image left, 1 is image right), NAN if unknown */
    if (lfs_file_write(log->lfs, log->file, &src->radius, sizeof(src->radius)) < 0) {
        return 1;
    }

    /* Current tracked rectangle top x value if CAMERA_TRACKING_MODE_RECTANGLE (normalized 0..1, 0 is left, 1 is right), NAN if unknown */
    if (lfs_file_write(log->lfs, log->file, &src->rec_top_x, sizeof(src->rec_top_x)) < 0) {
        return 1;
    }

    /* Current tracked rectangle top y value if CAMERA_TRACKING_MODE_RECTANGLE (normalized 0..1, 0 is top, 1 is bottom), NAN if unknown */
    if (lfs_file_write(log->lfs, log->file, &src->rec_top_y, sizeof(src->rec_top_y)) < 0) {
        return 1;
    }

    /* Current tracked rectangle bottom x value if CAMERA_TRACKING_MODE_RECTANGLE (normalized 0..1, 0 is left, 1 is right), NAN if unknown */
    if (lfs_file_write(log->lfs, log->file, &src->rec_bottom_x, sizeof(src->rec_bottom_x)) < 0) {
        return 1;
    }

    /* Current tracked rectangle bottom y value if CAMERA_TRACKING_MODE_RECTANGLE (normalized 0..1, 0 is top, 1 is bottom), NAN if unknown */
    if (lfs_file_write(log->lfs, log->file, &src->rec_bottom_y, sizeof(src->rec_bottom_y)) < 0) {
        return 1;
    }

    /* Camera id of a non-MAVLink camera attached to an autopilot (1-6).  0 if the component is a MAVLink camera (with its own component id). */
    if (lfs_file_write(log->lfs, log->file, &src->camera_device_id, sizeof(src->camera_device_id)) < 0) {
        return 1;
    }

    
    return 0;
}
