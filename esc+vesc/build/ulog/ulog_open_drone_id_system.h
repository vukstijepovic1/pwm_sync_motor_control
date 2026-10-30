/**
 * @file    ulog_open_drone_id_system.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_OPEN_DRONE_ID_SYSTEM_H
#define ULOG_OPEN_DRONE_ID_SYSTEM_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_open_drone_id_system_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t target_system; /* System ID (0 for broadcast). */
    uint8_t target_component; /* Component ID (0 for broadcast). */
    uint8_t id_or_mac[20]; /* Only used for drone ID data received from other UAs. See detailed description at https://mavlink.io/en/services/opendroneid.html.  */
    uint8_t operator_location_type; /* Specifies the operator location type. */
    uint8_t classification_type; /* Specifies the classification type of the UA. */
    int32_t operator_latitude; /* Latitude of the operator. If unknown: 0 (both Lat/Lon). [degE7] */
    int32_t operator_longitude; /* Longitude of the operator. If unknown: 0 (both Lat/Lon). [degE7] */
    uint16_t area_count; /* Number of aircraft in the area, group or formation (default 1). Used only for swarms/multiple UA. */
    uint16_t area_radius; /* Radius of the cylindrical area of the group or formation (default 0). Used only for swarms/multiple UA. [m] */
    float area_ceiling; /* Area Operations Ceiling relative to WGS84. If unknown: -1000 m. Used only for swarms/multiple UA. [m] */
    float area_floor; /* Area Operations Floor relative to WGS84. If unknown: -1000 m. Used only for swarms/multiple UA. [m] */
    uint8_t category_eu; /* When classification_type is MAV_ODID_CLASSIFICATION_TYPE_EU, specifies the category of the UA. */
    uint8_t class_eu; /* When classification_type is MAV_ODID_CLASSIFICATION_TYPE_EU, specifies the class of the UA. */
    float operator_altitude_geo; /* Geodetic altitude of the operator relative to WGS84. If unknown: -1000 m. [m] */
    
} ulog_open_drone_id_system_t;

/**
 * Defines Open Drone Id System message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_open_drone_id_system(ulog_t *log);

/**
 * Subscribe Open Drone Id System message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_open_drone_id_system(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Open Drone Id System message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_open_drone_id_system(ulog_t *log, ulog_msg_id_t id, const ulog_open_drone_id_system_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_OPEN_DRONE_ID_SYSTEM_H */