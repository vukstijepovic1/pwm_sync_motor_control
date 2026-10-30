/**
 * @file    ulog_camera_settings.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_CAMERA_SETTINGS_H
#define ULOG_CAMERA_SETTINGS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_camera_settings_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint32_t time_boot_ms; /* Timestamp (time since system boot). [ms] */
    uint8_t mode_id; /* Camera mode */
    float zoomLevel; /* Current zoom level as a percentage of the full range (0.0 to 100.0, NaN if not known) */
    float focusLevel; /* Current focus level as a percentage of the full range (0.0 to 100.0, NaN if not known) */
    uint8_t camera_device_id; /* Camera id of a non-MAVLink camera attached to an autopilot (1-6).  0 if the component is a MAVLink camera (with its own component id). */
    
} ulog_camera_settings_t;

/**
 * Defines Camera Settings message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_camera_settings(ulog_t *log);

/**
 * Subscribe Camera Settings message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_camera_settings(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Camera Settings message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_camera_settings(ulog_t *log, ulog_msg_id_t id, const ulog_camera_settings_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_CAMERA_SETTINGS_H */