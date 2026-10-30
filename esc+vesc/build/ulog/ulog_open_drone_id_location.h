/**
 * @file    ulog_open_drone_id_location.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_OPEN_DRONE_ID_LOCATION_H
#define ULOG_OPEN_DRONE_ID_LOCATION_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_open_drone_id_location_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t target_system; /* System ID (0 for broadcast). */
    uint8_t target_component; /* Component ID (0 for broadcast). */
    uint8_t id_or_mac[20]; /* Only used for drone ID data received from other UAs. See detailed description at https://mavlink.io/en/services/opendroneid.html.  */
    uint8_t status; /* Indicates whether the unmanned aircraft is on the ground or in the air. */
    uint16_t direction; /* Direction over ground (not heading, but direction of movement) measured clockwise from true North: 0 - 35999 centi-degrees. If unknown: 36100 centi-degrees. [cdeg] */
    uint16_t speed_horizontal; /* Ground speed. Positive only. If unknown: 25500 cm/s. If speed is larger than 25425 cm/s, use 25425 cm/s. [cm/s] */
    int16_t speed_vertical; /* The vertical speed. Up is positive. If unknown: 6300 cm/s. If speed is larger than 6200 cm/s, use 6200 cm/s. If lower than -6200 cm/s, use -6200 cm/s. [cm/s] */
    int32_t latitude; /* Current latitude of the unmanned aircraft. If unknown: 0 (both Lat/Lon). [degE7] */
    int32_t longitude; /* Current longitude of the unmanned aircraft. If unknown: 0 (both Lat/Lon). [degE7] */
    float altitude_barometric; /* The altitude calculated from the barometric pressue. Reference is against 29.92inHg or 1013.2mb. If unknown: -1000 m. [m] */
    float altitude_geodetic; /* The geodetic altitude as defined by WGS84. If unknown: -1000 m. [m] */
    uint8_t height_reference; /* Indicates the reference point for the height field. */
    float height; /* The current height of the unmanned aircraft above the take-off location or the ground as indicated by height_reference. If unknown: -1000 m. [m] */
    uint8_t horizontal_accuracy; /* The accuracy of the horizontal position. */
    uint8_t vertical_accuracy; /* The accuracy of the vertical position. */
    uint8_t barometer_accuracy; /* The accuracy of the barometric altitude. */
    uint8_t speed_accuracy; /* The accuracy of the horizontal and vertical speed. */
    uint8_t timestamp_accuracy; /* The accuracy of the timestamps. */
    
} ulog_open_drone_id_location_t;

/**
 * Defines Open Drone Id Location message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_open_drone_id_location(ulog_t *log);

/**
 * Subscribe Open Drone Id Location message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_open_drone_id_location(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Open Drone Id Location message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_open_drone_id_location(ulog_t *log, ulog_msg_id_t id, const ulog_open_drone_id_location_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_OPEN_DRONE_ID_LOCATION_H */