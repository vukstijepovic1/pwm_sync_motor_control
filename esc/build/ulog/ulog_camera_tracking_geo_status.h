/**
 * @file    ulog_camera_tracking_geo_status.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_CAMERA_TRACKING_GEO_STATUS_H
#define ULOG_CAMERA_TRACKING_GEO_STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_camera_tracking_geo_status_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t tracking_status; /* Current tracking status */
    int32_t lat; /* Latitude of tracked object [degE7] */
    int32_t lon; /* Longitude of tracked object [degE7] */
    float alt; /* Altitude of tracked object(AMSL, WGS84) [m] */
    float h_acc; /* Horizontal accuracy. NAN if unknown [m] */
    float v_acc; /* Vertical accuracy. NAN if unknown [m] */
    float vel_n; /* North velocity of tracked object. NAN if unknown [m/s] */
    float vel_e; /* East velocity of tracked object. NAN if unknown [m/s] */
    float vel_d; /* Down velocity of tracked object. NAN if unknown [m/s] */
    float vel_acc; /* Velocity accuracy. NAN if unknown [m/s] */
    float dist; /* Distance between camera and tracked object. NAN if unknown [m] */
    float hdg; /* Heading in radians, in NED. NAN if unknown [rad] */
    float hdg_acc; /* Accuracy of heading, in NED. NAN if unknown [rad] */
    uint8_t camera_device_id; /* Camera id of a non-MAVLink camera attached to an autopilot (1-6).  0 if the component is a MAVLink camera (with its own component id). */
    
} ulog_camera_tracking_geo_status_t;

/**
 * Defines Camera Tracking Geo Status message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_camera_tracking_geo_status(ulog_t *log);

/**
 * Subscribe Camera Tracking Geo Status message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_camera_tracking_geo_status(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Camera Tracking Geo Status message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_camera_tracking_geo_status(ulog_t *log, ulog_msg_id_t id, const ulog_camera_tracking_geo_status_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_CAMERA_TRACKING_GEO_STATUS_H */