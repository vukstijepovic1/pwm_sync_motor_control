/**
 * @file    ulog_gps_raw_int.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_GPS_RAW_INT_H
#define ULOG_GPS_RAW_INT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_gps_raw_int_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t time_usec; /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    uint8_t fix_type; /* GPS fix type. */
    int32_t lat; /* Latitude (WGS84, EGM96 ellipsoid) [degE7] */
    int32_t lon; /* Longitude (WGS84, EGM96 ellipsoid) [degE7] */
    int32_t alt; /* Altitude (MSL). Positive for up. Note that virtually all GPS modules provide the MSL altitude in addition to the WGS84 altitude. [mm] */
    uint16_t eph; /* GPS HDOP horizontal dilution of position (unitless * 100). If unknown, set to: UINT16_MAX */
    uint16_t epv; /* GPS VDOP vertical dilution of position (unitless * 100). If unknown, set to: UINT16_MAX */
    uint16_t vel; /* GPS ground speed. If unknown, set to: UINT16_MAX [cm/s] */
    uint16_t cog; /* Course over ground (NOT heading, but direction of movement) in degrees * 100, 0.0..359.99 degrees. If unknown, set to: UINT16_MAX [cdeg] */
    uint8_t satellites_visible; /* Number of satellites visible. If unknown, set to UINT8_MAX */
    int32_t alt_ellipsoid; /* Altitude (above WGS84, EGM96 ellipsoid). Positive for up. [mm] */
    uint32_t h_acc; /* Position uncertainty. [mm] */
    uint32_t v_acc; /* Altitude uncertainty. [mm] */
    uint32_t vel_acc; /* Speed uncertainty. [mm/s] */
    uint32_t hdg_acc; /* Heading / track uncertainty [degE5] */
    uint16_t yaw; /* Yaw in earth frame from north. Use 0 if this GPS does not provide yaw. Use UINT16_MAX if this GPS is configured to provide yaw and is currently unable to provide it. Use 36000 for north. [cdeg] */
    
} ulog_gps_raw_int_t;

/**
 * Defines Gps Raw Int message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_gps_raw_int(ulog_t *log);

/**
 * Subscribe Gps Raw Int message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_gps_raw_int(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Gps Raw Int message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_gps_raw_int(ulog_t *log, ulog_msg_id_t id, const ulog_gps_raw_int_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_GPS_RAW_INT_H */