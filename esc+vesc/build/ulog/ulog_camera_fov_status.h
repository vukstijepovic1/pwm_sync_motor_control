/**
 * @file    ulog_camera_fov_status.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_CAMERA_FOV_STATUS_H
#define ULOG_CAMERA_FOV_STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_camera_fov_status_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint32_t time_boot_ms; /* Timestamp (time since system boot). [ms] */
    int32_t lat_camera; /* Latitude of camera (INT32_MAX if unknown). [degE7] */
    int32_t lon_camera; /* Longitude of camera (INT32_MAX if unknown). [degE7] */
    int32_t alt_camera; /* Altitude (MSL) of camera (INT32_MAX if unknown). [mm] */
    int32_t lat_image; /* Latitude of center of image (INT32_MAX if unknown, INT32_MIN if at infinity, not intersecting with horizon). [degE7] */
    int32_t lon_image; /* Longitude of center of image (INT32_MAX if unknown, INT32_MIN if at infinity, not intersecting with horizon). [degE7] */
    int32_t alt_image; /* Altitude (MSL) of center of image (INT32_MAX if unknown, INT32_MIN if at infinity, not intersecting with horizon). [mm] */
    float q[4]; /* Quaternion of camera orientation (w, x, y, z order, zero-rotation is 1, 0, 0, 0) */
    float hfov; /* Horizontal field of view (NaN if unknown). [deg] */
    float vfov; /* Vertical field of view (NaN if unknown). [deg] */
    uint8_t camera_device_id; /* Camera id of a non-MAVLink camera attached to an autopilot (1-6).  0 if the component is a MAVLink camera (with its own component id). */
    
} ulog_camera_fov_status_t;

/**
 * Defines Camera Fov Status message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_camera_fov_status(ulog_t *log);

/**
 * Subscribe Camera Fov Status message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_camera_fov_status(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Camera Fov Status message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_camera_fov_status(ulog_t *log, ulog_msg_id_t id, const ulog_camera_fov_status_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_CAMERA_FOV_STATUS_H */