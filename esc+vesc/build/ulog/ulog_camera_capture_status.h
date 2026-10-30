/**
 * @file    ulog_camera_capture_status.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_CAMERA_CAPTURE_STATUS_H
#define ULOG_CAMERA_CAPTURE_STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_camera_capture_status_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint32_t time_boot_ms; /* Timestamp (time since system boot). [ms] */
    uint8_t image_status; /* Current status of image capturing (0: idle, 1: capture in progress, 2: interval set but idle, 3: interval set and capture in progress) */
    uint8_t video_status; /* Current status of video capturing (0: idle, 1: capture in progress) */
    float image_interval; /* Image capture interval [s] */
    uint32_t recording_time_ms; /* Elapsed time since recording started (0: Not supported/available). A GCS should compute recording time and use non-zero values of this field to correct any discrepancy. [ms] */
    float available_capacity; /* Available storage capacity. [MiB] */
    int32_t image_count; /* Total number of images captured ('forever', or until reset using MAV_CMD_STORAGE_FORMAT). */
    uint8_t camera_device_id; /* Camera id of a non-MAVLink camera attached to an autopilot (1-6).  0 if the component is a MAVLink camera (with its own component id). */
    
} ulog_camera_capture_status_t;

/**
 * Defines Camera Capture Status message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_camera_capture_status(ulog_t *log);

/**
 * Subscribe Camera Capture Status message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_camera_capture_status(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Camera Capture Status message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_camera_capture_status(ulog_t *log, ulog_msg_id_t id, const ulog_camera_capture_status_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_CAMERA_CAPTURE_STATUS_H */