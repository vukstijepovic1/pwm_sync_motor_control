/**
 * @file    ulog_camera_tracking_image_status.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_CAMERA_TRACKING_IMAGE_STATUS_H
#define ULOG_CAMERA_TRACKING_IMAGE_STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_camera_tracking_image_status_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t tracking_status; /* Current tracking status */
    uint8_t tracking_mode; /* Current tracking mode */
    uint8_t target_data; /* Defines location of target data */
    float point_x; /* Current tracked point x value if CAMERA_TRACKING_MODE_POINT (normalized 0..1, 0 is left, 1 is right), NAN if unknown */
    float point_y; /* Current tracked point y value if CAMERA_TRACKING_MODE_POINT (normalized 0..1, 0 is top, 1 is bottom), NAN if unknown */
    float radius; /* Current tracked radius if CAMERA_TRACKING_MODE_POINT (normalized 0..1, 0 is image left, 1 is image right), NAN if unknown */
    float rec_top_x; /* Current tracked rectangle top x value if CAMERA_TRACKING_MODE_RECTANGLE (normalized 0..1, 0 is left, 1 is right), NAN if unknown */
    float rec_top_y; /* Current tracked rectangle top y value if CAMERA_TRACKING_MODE_RECTANGLE (normalized 0..1, 0 is top, 1 is bottom), NAN if unknown */
    float rec_bottom_x; /* Current tracked rectangle bottom x value if CAMERA_TRACKING_MODE_RECTANGLE (normalized 0..1, 0 is left, 1 is right), NAN if unknown */
    float rec_bottom_y; /* Current tracked rectangle bottom y value if CAMERA_TRACKING_MODE_RECTANGLE (normalized 0..1, 0 is top, 1 is bottom), NAN if unknown */
    uint8_t camera_device_id; /* Camera id of a non-MAVLink camera attached to an autopilot (1-6).  0 if the component is a MAVLink camera (with its own component id). */
    
} ulog_camera_tracking_image_status_t;

/**
 * Defines Camera Tracking Image Status message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_camera_tracking_image_status(ulog_t *log);

/**
 * Subscribe Camera Tracking Image Status message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_camera_tracking_image_status(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Camera Tracking Image Status message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_camera_tracking_image_status(ulog_t *log, ulog_msg_id_t id, const ulog_camera_tracking_image_status_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_CAMERA_TRACKING_IMAGE_STATUS_H */