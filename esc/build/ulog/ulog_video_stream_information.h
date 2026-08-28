/**
 * @file    ulog_video_stream_information.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_VIDEO_STREAM_INFORMATION_H
#define ULOG_VIDEO_STREAM_INFORMATION_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_video_stream_information_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t stream_id; /* Video Stream ID (1 for first, 2 for second, etc.) */
    uint8_t count; /* Number of streams available. */
    uint8_t type; /* Type of stream. */
    uint16_t flags; /* Bitmap of stream status flags. */
    float framerate; /* Frame rate. [Hz] */
    uint16_t resolution_h; /* Horizontal resolution. [pix] */
    uint16_t resolution_v; /* Vertical resolution. [pix] */
    uint32_t bitrate; /* Bit rate. [bits/s] */
    uint16_t rotation; /* Video image rotation clockwise. [deg] */
    uint16_t hfov; /* Horizontal Field of view. [deg] */
    char name[32]; /* Stream name. */
    char uri[160]; /* Video stream URI (TCP or RTSP URI ground station should connect to) or port number (UDP port ground station should listen to). */
    uint8_t encoding; /* Encoding of stream. */
    uint8_t camera_device_id; /* Camera id of a non-MAVLink camera attached to an autopilot (1-6).  0 if the component is a MAVLink camera (with its own component id). */
    
} ulog_video_stream_information_t;

/**
 * Defines Video Stream Information message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_video_stream_information(ulog_t *log);

/**
 * Subscribe Video Stream Information message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_video_stream_information(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Video Stream Information message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_video_stream_information(ulog_t *log, ulog_msg_id_t id, const ulog_video_stream_information_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_VIDEO_STREAM_INFORMATION_H */