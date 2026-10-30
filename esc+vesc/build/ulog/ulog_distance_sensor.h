/**
 * @file    ulog_distance_sensor.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_DISTANCE_SENSOR_H
#define ULOG_DISTANCE_SENSOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_distance_sensor_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint32_t time_boot_ms; /* Timestamp (time since system boot). [ms] */
    uint16_t min_distance; /* Minimum distance the sensor can measure [cm] */
    uint16_t max_distance; /* Maximum distance the sensor can measure [cm] */
    uint16_t current_distance; /* Current distance reading [cm] */
    uint8_t type; /* Type of distance sensor. */
    uint8_t id; /* Onboard ID of the sensor */
    uint8_t orientation; /* Direction the sensor faces. downward-facing: ROTATION_PITCH_270, upward-facing: ROTATION_PITCH_90, backward-facing: ROTATION_PITCH_180, forward-facing: ROTATION_NONE, left-facing: ROTATION_YAW_90, right-facing: ROTATION_YAW_270 */
    uint8_t covariance; /* Measurement variance. Max standard deviation is 6cm. UINT8_MAX if unknown. [cm^2] */
    float horizontal_fov; /* Horizontal Field of View (angle) where the distance measurement is valid and the field of view is known. Otherwise this is set to 0. [rad] */
    float vertical_fov; /* Vertical Field of View (angle) where the distance measurement is valid and the field of view is known. Otherwise this is set to 0. [rad] */
    float quaternion[4]; /* Quaternion of the sensor orientation in vehicle body frame (w, x, y, z order, zero-rotation is 1, 0, 0, 0). Zero-rotation is along the vehicle body x-axis. This field is required if the orientation is set to MAV_SENSOR_ROTATION_CUSTOM. Set it to 0 if invalid." */
    uint8_t signal_quality; /* Signal quality of the sensor. Specific to each sensor type, representing the relation of the signal strength with the target reflectivity, distance, size or aspect, but normalised as a percentage. 0 = unknown/unset signal quality, 1 = invalid signal, 100 = perfect signal. [%] */
    
} ulog_distance_sensor_t;

/**
 * Defines Distance Sensor message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_distance_sensor(ulog_t *log);

/**
 * Subscribe Distance Sensor message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_distance_sensor(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Distance Sensor message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_distance_sensor(ulog_t *log, ulog_msg_id_t id, const ulog_distance_sensor_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_DISTANCE_SENSOR_H */