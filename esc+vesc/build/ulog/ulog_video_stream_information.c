/**
 * @file    ulog_video_stream_information.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_video_stream_information.h"
#include "ulog_def.h"

const char ulog_video_stream_information_format[] = "video_stream_information:uint64_t timestamp;uint8_t stream_id;uint8_t count;uint8_t type;uint16_t flags;float framerate;uint16_t resolution_h;uint16_t resolution_v;uint32_t bitrate;uint16_t rotation;uint16_t hfov;char[32] name;char[160] uri;uint8_t encoding;uint8_t camera_device_id;";
const char ulog_video_stream_information_name[] = "video_stream_information";

int32_t ulog_format_video_stream_information(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_video_stream_information_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_video_stream_information_format, sizeof(ulog_video_stream_information_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_video_stream_information(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_video_stream_information_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_video_stream_information_name, sizeof(ulog_video_stream_information_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_video_stream_information(ulog_t *log, ulog_msg_id_t id, const ulog_video_stream_information_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint16_t)
                    + sizeof(float)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint32_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(char)*32
                    + sizeof(char)*160
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

    /* Video Stream ID (1 for first, 2 for second, etc.) */
    if (lfs_file_write(log->lfs, log->file, &src->stream_id, sizeof(src->stream_id)) < 0) {
        return 1;
    }

    /* Number of streams available. */
    if (lfs_file_write(log->lfs, log->file, &src->count, sizeof(src->count)) < 0) {
        return 1;
    }

    /* Type of stream. */
    if (lfs_file_write(log->lfs, log->file, &src->type, sizeof(src->type)) < 0) {
        return 1;
    }

    /* Bitmap of stream status flags. */
    if (lfs_file_write(log->lfs, log->file, &src->flags, sizeof(src->flags)) < 0) {
        return 1;
    }

    /* Frame rate. [Hz] */
    if (lfs_file_write(log->lfs, log->file, &src->framerate, sizeof(src->framerate)) < 0) {
        return 1;
    }

    /* Horizontal resolution. [pix] */
    if (lfs_file_write(log->lfs, log->file, &src->resolution_h, sizeof(src->resolution_h)) < 0) {
        return 1;
    }

    /* Vertical resolution. [pix] */
    if (lfs_file_write(log->lfs, log->file, &src->resolution_v, sizeof(src->resolution_v)) < 0) {
        return 1;
    }

    /* Bit rate. [bits/s] */
    if (lfs_file_write(log->lfs, log->file, &src->bitrate, sizeof(src->bitrate)) < 0) {
        return 1;
    }

    /* Video image rotation clockwise. [deg] */
    if (lfs_file_write(log->lfs, log->file, &src->rotation, sizeof(src->rotation)) < 0) {
        return 1;
    }

    /* Horizontal Field of view. [deg] */
    if (lfs_file_write(log->lfs, log->file, &src->hfov, sizeof(src->hfov)) < 0) {
        return 1;
    }

    /* Stream name. */
    if (lfs_file_write(log->lfs, log->file, src->name, sizeof(src->name)) < 0) {
        return 1;
    }

    /* Video stream URI (TCP or RTSP URI ground station should connect to) or port number (UDP port ground station should listen to). */
    if (lfs_file_write(log->lfs, log->file, src->uri, sizeof(src->uri)) < 0) {
        return 1;
    }

    /* Encoding of stream. */
    if (lfs_file_write(log->lfs, log->file, &src->encoding, sizeof(src->encoding)) < 0) {
        return 1;
    }

    /* Camera id of a non-MAVLink camera attached to an autopilot (1-6).  0 if the component is a MAVLink camera (with its own component id). */
    if (lfs_file_write(log->lfs, log->file, &src->camera_device_id, sizeof(src->camera_device_id)) < 0) {
        return 1;
    }

    
    return 0;
}
