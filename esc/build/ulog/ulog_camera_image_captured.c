/**
 * @file    ulog_camera_image_captured.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_camera_image_captured.h"
#include "ulog_def.h"

const char ulog_camera_image_captured_format[] = "camera_image_captured:uint64_t timestamp;uint32_t time_boot_ms;uint64_t time_utc;uint8_t camera_id;int32_t lat;int32_t lon;int32_t alt;int32_t relative_alt;float[4] q;int32_t image_index;int8_t capture_result;char[205] file_url;";
const char ulog_camera_image_captured_name[] = "camera_image_captured";

int32_t ulog_format_camera_image_captured(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_camera_image_captured_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_camera_image_captured_format, sizeof(ulog_camera_image_captured_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_camera_image_captured(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_camera_image_captured_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_camera_image_captured_name, sizeof(ulog_camera_image_captured_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_camera_image_captured(ulog_t *log, ulog_msg_id_t id, const ulog_camera_image_captured_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(float)*4
                    + sizeof(int32_t)
                    + sizeof(int8_t)
                    + sizeof(char)*205
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

    /* Timestamp (time since UNIX epoch) in UTC. 0 for unknown. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->time_utc, sizeof(src->time_utc)) < 0) {
        return 1;
    }

    /* Camera id of a non-MAVLink camera attached to an autopilot (1-6).  0 if the component is a MAVLink camera (with its own component id). Field name is usually camera_device_id. */
    if (lfs_file_write(log->lfs, log->file, &src->camera_id, sizeof(src->camera_id)) < 0) {
        return 1;
    }

    /* Latitude where image was taken [degE7] */
    if (lfs_file_write(log->lfs, log->file, &src->lat, sizeof(src->lat)) < 0) {
        return 1;
    }

    /* Longitude where capture was taken [degE7] */
    if (lfs_file_write(log->lfs, log->file, &src->lon, sizeof(src->lon)) < 0) {
        return 1;
    }

    /* Altitude (MSL) where image was taken [mm] */
    if (lfs_file_write(log->lfs, log->file, &src->alt, sizeof(src->alt)) < 0) {
        return 1;
    }

    /* Altitude above ground [mm] */
    if (lfs_file_write(log->lfs, log->file, &src->relative_alt, sizeof(src->relative_alt)) < 0) {
        return 1;
    }

    /* Quaternion of camera orientation (w, x, y, z order, zero-rotation is 1, 0, 0, 0) */
    if (lfs_file_write(log->lfs, log->file, src->q, sizeof(src->q)) < 0) {
        return 1;
    }

    /* Zero based index of this image (i.e. a new image will have index CAMERA_CAPTURE_STATUS.image count -1) */
    if (lfs_file_write(log->lfs, log->file, &src->image_index, sizeof(src->image_index)) < 0) {
        return 1;
    }

    /* Boolean indicating success (1) or failure (0) while capturing this image. */
    if (lfs_file_write(log->lfs, log->file, &src->capture_result, sizeof(src->capture_result)) < 0) {
        return 1;
    }

    /* URL of image taken. Either local storage or http://foo.jpg if camera provides an HTTP interface. */
    if (lfs_file_write(log->lfs, log->file, src->file_url, sizeof(src->file_url)) < 0) {
        return 1;
    }

    
    return 0;
}
