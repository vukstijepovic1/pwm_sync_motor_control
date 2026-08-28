/**
 * @file    ulog_set_position_target_global_int.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_SET_POSITION_TARGET_GLOBAL_INT_H
#define ULOG_SET_POSITION_TARGET_GLOBAL_INT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_set_position_target_global_int_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint32_t time_boot_ms; /* Timestamp (time since system boot). The rationale for the timestamp in the setpoint is to allow the system to compensate for the transport delay of the setpoint. This allows the system to compensate processing latency. [ms] */
    uint8_t target_system; /* System ID */
    uint8_t target_component; /* Component ID */
    uint8_t coordinate_frame; /* Valid options are: MAV_FRAME_GLOBAL = 0, MAV_FRAME_GLOBAL_RELATIVE_ALT = 3, MAV_FRAME_GLOBAL_TERRAIN_ALT = 10 (MAV_FRAME_GLOBAL_INT, MAV_FRAME_GLOBAL_RELATIVE_ALT_INT, MAV_FRAME_GLOBAL_TERRAIN_ALT_INT are allowed synonyms, but have been deprecated) */
    uint16_t type_mask; /* Bitmap to indicate which dimensions should be ignored by the vehicle. */
    int32_t lat_int; /* Latitude in WGS84 frame [degE7] */
    int32_t lon_int; /* Longitude in WGS84 frame [degE7] */
    float alt; /* Altitude (MSL, Relative to home, or AGL - depending on frame) [m] */
    float vx; /* X velocity in NED frame [m/s] */
    float vy; /* Y velocity in NED frame [m/s] */
    float vz; /* Z velocity in NED frame [m/s] */
    float afx; /* X acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N [m/s/s] */
    float afy; /* Y acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N [m/s/s] */
    float afz; /* Z acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N [m/s/s] */
    float yaw; /* yaw setpoint [rad] */
    float yaw_rate; /* yaw rate setpoint [rad/s] */
    
} ulog_set_position_target_global_int_t;

/**
 * Defines Set Position Target Global Int message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_set_position_target_global_int(ulog_t *log);

/**
 * Subscribe Set Position Target Global Int message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_set_position_target_global_int(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Set Position Target Global Int message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_set_position_target_global_int(ulog_t *log, ulog_msg_id_t id, const ulog_set_position_target_global_int_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_SET_POSITION_TARGET_GLOBAL_INT_H */