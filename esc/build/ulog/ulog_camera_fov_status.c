/**
 * @file    ulog_camera_fov_status.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_camera_fov_status.h"
#include "ulog_def.h"

const char ulog_camera_fov_status_format[] = "camera_fov_status:uint64_t timestamp;uint32_t time_boot_ms;int32_t lat_camera;int32_t lon_camera;int32_t alt_camera;int32_t lat_image;int32_t lon_image;int32_t alt_image;float[4] q;float hfov;float vfov;uint8_t camera_device_id;";
const char ulog_camera_fov_status_name[] = "camera_fov_status";

int32_t ulog_format_camera_fov_status(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_camera_fov_status_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_camera_fov_status_format, sizeof(ulog_camera_fov_status_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_camera_fov_status(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_camera_fov_status_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_camera_fov_status_name, sizeof(ulog_camera_fov_status_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_camera_fov_status(ulog_t *log, ulog_msg_id_t id, const ulog_camera_fov_status_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(float)*4
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

    /* Latitude of camera (INT32_MAX if unknown). [degE7] */
    if (lfs_file_write(log->lfs, log->file, &src->lat_camera, sizeof(src->lat_camera)) < 0) {
        return 1;
    }

    /* Longitude of camera (INT32_MAX if unknown). [degE7] */
    if (lfs_file_write(log->lfs, log->file, &src->lon_camera, sizeof(src->lon_camera)) < 0) {
        return 1;
    }

    /* Altitude (MSL) of camera (INT32_MAX if unknown). [mm] */
    if (lfs_file_write(log->lfs, log->file, &src->alt_camera, sizeof(src->alt_camera)) < 0) {
        return 1;
    }

    /* Latitude of center of image (INT32_MAX if unknown, INT32_MIN if at infinity, not intersecting with horizon). [degE7] */
    if (lfs_file_write(log->lfs, log->file, &src->lat_image, sizeof(src->lat_image)) < 0) {
        return 1;
    }

    /* Longitude of center of image (INT32_MAX if unknown, INT32_MIN if at infinity, not intersecting with horizon). [degE7] */
    if (lfs_file_write(log->lfs, log->file, &src->lon_image, sizeof(src->lon_image)) < 0) {
        return 1;
    }

    /* Altitude (MSL) of center of image (INT32_MAX if unknown, INT32_MIN if at infinity, not intersecting with horizon). [mm] */
    if (lfs_file_write(log->lfs, log->file, &src->alt_image, sizeof(src->alt_image)) < 0) {
        return 1;
    }

    /* Quaternion of camera orientation (w, x, y, z order, zero-rotation is 1, 0, 0, 0) */
    if (lfs_file_write(log->lfs, log->file, src->q, sizeof(src->q)) < 0) {
        return 1;
    }

    /* Horizontal field of view (NaN if unknown). [deg] */
    if (lfs_file_write(log->lfs, log->file, &src->hfov, sizeof(src->hfov)) < 0) {
        return 1;
    }

    /* Vertical field of view (NaN if unknown). [deg] */
    if (lfs_file_write(log->lfs, log->file, &src->vfov, sizeof(src->vfov)) < 0) {
        return 1;
    }

    /* Camera id of a non-MAVLink camera attached to an autopilot (1-6).  0 if the component is a MAVLink camera (with its own component id). */
    if (lfs_file_write(log->lfs, log->file, &src->camera_device_id, sizeof(src->camera_device_id)) < 0) {
        return 1;
    }

    
    return 0;
}
