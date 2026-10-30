/**
 * @file    ulog_obstacle_distance.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_OBSTACLE_DISTANCE_H
#define ULOG_OBSTACLE_DISTANCE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_obstacle_distance_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t time_usec; /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    uint8_t sensor_type; /* Class id of the distance sensor type. */
    uint16_t distances[72]; /* Distance of obstacles around the vehicle with index 0 corresponding to north + angle_offset, unless otherwise specified in the frame. A value of 0 is valid and means that the obstacle is practically touching the sensor. A value of max_distance +1 means no obstacle is present. A value of UINT16_MAX for unknown/not used. In a array element, one unit corresponds to 1cm. [cm] */
    uint8_t increment; /* Angular width in degrees of each array element. Increment direction is clockwise. This field is ignored if increment_f is non-zero. [deg] */
    uint16_t min_distance; /* Minimum distance the sensor can measure. [cm] */
    uint16_t max_distance; /* Maximum distance the sensor can measure. [cm] */
    float increment_f; /* Angular width in degrees of each array element as a float. If non-zero then this value is used instead of the uint8_t increment field. Positive is clockwise direction, negative is counter-clockwise. [deg] */
    float angle_offset; /* Relative angle offset of the 0-index element in the distances array. Value of 0 corresponds to forward. Positive is clockwise direction, negative is counter-clockwise. [deg] */
    uint8_t frame; /* Coordinate frame of reference for the yaw rotation and offset of the sensor data. Defaults to MAV_FRAME_GLOBAL, which is north aligned. For body-mounted sensors use MAV_FRAME_BODY_FRD, which is vehicle front aligned. */
    
} ulog_obstacle_distance_t;

/**
 * Defines Obstacle Distance message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_obstacle_distance(ulog_t *log);

/**
 * Subscribe Obstacle Distance message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_obstacle_distance(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Obstacle Distance message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_obstacle_distance(ulog_t *log, ulog_msg_id_t id, const ulog_obstacle_distance_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_OBSTACLE_DISTANCE_H */