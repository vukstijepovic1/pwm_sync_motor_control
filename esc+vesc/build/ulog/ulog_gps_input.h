/**
 * @file    ulog_gps_input.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_GPS_INPUT_H
#define ULOG_GPS_INPUT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_gps_input_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t time_usec; /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    uint8_t gps_id; /* ID of the GPS for multiple GPS inputs */
    uint16_t ignore_flags; /* Bitmap indicating which GPS input flags fields to ignore.  All other fields must be provided. */
    uint32_t time_week_ms; /* GPS time (from start of GPS week) [ms] */
    uint16_t time_week; /* GPS week number */
    uint8_t fix_type; /* 0-1: no fix, 2: 2D fix, 3: 3D fix. 4: 3D with DGPS. 5: 3D with RTK */
    int32_t lat; /* Latitude (WGS84) [degE7] */
    int32_t lon; /* Longitude (WGS84) [degE7] */
    float alt; /* Altitude (MSL). Positive for up. [m] */
    float hdop; /* GPS HDOP horizontal dilution of position (unitless). If unknown, set to: UINT16_MAX */
    float vdop; /* GPS VDOP vertical dilution of position (unitless). If unknown, set to: UINT16_MAX */
    float vn; /* GPS velocity in north direction in earth-fixed NED frame [m/s] */
    float ve; /* GPS velocity in east direction in earth-fixed NED frame [m/s] */
    float vd; /* GPS velocity in down direction in earth-fixed NED frame [m/s] */
    float speed_accuracy; /* GPS speed accuracy [m/s] */
    float horiz_accuracy; /* GPS horizontal accuracy [m] */
    float vert_accuracy; /* GPS vertical accuracy [m] */
    uint8_t satellites_visible; /* Number of satellites visible. */
    uint16_t yaw; /* Yaw of vehicle relative to Earth's North, zero means not available, use 36000 for north [cdeg] */
    
} ulog_gps_input_t;

/**
 * Defines Gps Input message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_gps_input(ulog_t *log);

/**
 * Subscribe Gps Input message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_gps_input(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Gps Input message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_gps_input(ulog_t *log, ulog_msg_id_t id, const ulog_gps_input_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_GPS_INPUT_H */