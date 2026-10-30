/**
 * @file    ulog_camera_image_captured.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_CAMERA_IMAGE_CAPTURED_H
#define ULOG_CAMERA_IMAGE_CAPTURED_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_camera_image_captured_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint32_t time_boot_ms; /* Timestamp (time since system boot). [ms] */
    uint64_t time_utc; /* Timestamp (time since UNIX epoch) in UTC. 0 for unknown. [us] */
    uint8_t camera_id; /* Camera id of a non-MAVLink camera attached to an autopilot (1-6).  0 if the component is a MAVLink camera (with its own component id). Field name is usually camera_device_id. */
    int32_t lat; /* Latitude where image was taken [degE7] */
    int32_t lon; /* Longitude where capture was taken [degE7] */
    int32_t alt; /* Altitude (MSL) where image was taken [mm] */
    int32_t relative_alt; /* Altitude above ground [mm] */
    float q[4]; /* Quaternion of camera orientation (w, x, y, z order, zero-rotation is 1, 0, 0, 0) */
    int32_t image_index; /* Zero based index of this image (i.e. a new image will have index CAMERA_CAPTURE_STATUS.image count -1) */
    int8_t capture_result; /* Boolean indicating success (1) or failure (0) while capturing this image. */
    char file_url[205]; /* URL of image taken. Either local storage or http://foo.jpg if camera provides an HTTP interface. */
    
} ulog_camera_image_captured_t;

/**
 * Defines Camera Image Captured message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_camera_image_captured(ulog_t *log);

/**
 * Subscribe Camera Image Captured message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_camera_image_captured(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Camera Image Captured message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_camera_image_captured(ulog_t *log, ulog_msg_id_t id, const ulog_camera_image_captured_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_CAMERA_IMAGE_CAPTURED_H */