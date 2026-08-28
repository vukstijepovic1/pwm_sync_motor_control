/**
 * @file    ulog_camera_thermal_range.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_CAMERA_THERMAL_RANGE_H
#define ULOG_CAMERA_THERMAL_RANGE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_camera_thermal_range_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint32_t time_boot_ms; /* Timestamp (time since system boot). [ms] */
    uint8_t stream_id; /* Video Stream ID (1 for first, 2 for second, etc.) */
    uint8_t camera_device_id; /* Camera id of a non-MAVLink camera attached to an autopilot (1-6).  0 if the component is a MAVLink camera (with its own component id). */
    float max; /* Temperature max. [degC] */
    float max_point_x; /* Temperature max point x value (normalized 0..1, 0 is left, 1 is right), NAN if unknown. */
    float max_point_y; /* Temperature max point y value (normalized 0..1, 0 is top, 1 is bottom), NAN if unknown. */
    float min; /* Temperature min. [degC] */
    float min_point_x; /* Temperature min point x value (normalized 0..1, 0 is left, 1 is right), NAN if unknown. */
    float min_point_y; /* Temperature min point y value (normalized 0..1, 0 is top, 1 is bottom), NAN if unknown. */
    
} ulog_camera_thermal_range_t;

/**
 * Defines Camera Thermal Range message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_camera_thermal_range(ulog_t *log);

/**
 * Subscribe Camera Thermal Range message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_camera_thermal_range(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Camera Thermal Range message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_camera_thermal_range(ulog_t *log, ulog_msg_id_t id, const ulog_camera_thermal_range_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_CAMERA_THERMAL_RANGE_H */