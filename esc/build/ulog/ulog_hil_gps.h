/**
 * @file    ulog_hil_gps.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_HIL_GPS_H
#define ULOG_HIL_GPS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_hil_gps_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t time_usec; /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    uint8_t fix_type; /* 0-1: no fix, 2: 2D fix, 3: 3D fix. Some applications will not use the value of this field unless it is at least two, so always correctly fill in the fix. */
    int32_t lat; /* Latitude (WGS84) [degE7] */
    int32_t lon; /* Longitude (WGS84) [degE7] */
    int32_t alt; /* Altitude (MSL). Positive for up. [mm] */
    uint16_t eph; /* GPS HDOP horizontal dilution of position (unitless * 100). If unknown, set to: UINT16_MAX */
    uint16_t epv; /* GPS VDOP vertical dilution of position (unitless * 100). If unknown, set to: UINT16_MAX */
    uint16_t vel; /* GPS ground speed. If unknown, set to: UINT16_MAX [cm/s] */
    int16_t vn; /* GPS velocity in north direction in earth-fixed NED frame [cm/s] */
    int16_t ve; /* GPS velocity in east direction in earth-fixed NED frame [cm/s] */
    int16_t vd; /* GPS velocity in down direction in earth-fixed NED frame [cm/s] */
    uint16_t cog; /* Course over ground (NOT heading, but direction of movement), 0.0..359.99 degrees. If unknown, set to: UINT16_MAX [cdeg] */
    uint8_t satellites_visible; /* Number of satellites visible. If unknown, set to UINT8_MAX */
    uint8_t id; /* GPS ID (zero indexed). Used for multiple GPS inputs */
    uint16_t yaw; /* Yaw of vehicle relative to Earth's North, zero means not available, use 36000 for north [cdeg] */
    
} ulog_hil_gps_t;

/**
 * Defines Hil Gps message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_hil_gps(ulog_t *log);

/**
 * Subscribe Hil Gps message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_hil_gps(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Hil Gps message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_hil_gps(ulog_t *log, ulog_msg_id_t id, const ulog_hil_gps_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_HIL_GPS_H */