/**
 * @file    ulog_video_stream_status.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_VIDEO_STREAM_STATUS_H
#define ULOG_VIDEO_STREAM_STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_video_stream_status_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t stream_id; /* Video Stream ID (1 for first, 2 for second, etc.) */
    uint16_t flags; /* Bitmap of stream status flags */
    float framerate; /* Frame rate [Hz] */
    uint16_t resolution_h; /* Horizontal resolution [pix] */
    uint16_t resolution_v; /* Vertical resolution [pix] */
    uint32_t bitrate; /* Bit rate [bits/s] */
    uint16_t rotation; /* Video image rotation clockwise [deg] */
    uint16_t hfov; /* Horizontal Field of view [deg] */
    uint8_t camera_device_id; /* Camera id of a non-MAVLink camera attached to an autopilot (1-6).  0 if the component is a MAVLink camera (with its own component id). */
    
} ulog_video_stream_status_t;

/**
 * Defines Video Stream Status message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_video_stream_status(ulog_t *log);

/**
 * Subscribe Video Stream Status message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_video_stream_status(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Video Stream Status message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_video_stream_status(ulog_t *log, ulog_msg_id_t id, const ulog_video_stream_status_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_VIDEO_STREAM_STATUS_H */