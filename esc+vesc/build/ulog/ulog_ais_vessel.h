/**
 * @file    ulog_ais_vessel.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_AIS_VESSEL_H
#define ULOG_AIS_VESSEL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_ais_vessel_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint32_t MMSI; /* Mobile Marine Service Identifier, 9 decimal digits */
    int32_t lat; /* Latitude [degE7] */
    int32_t lon; /* Longitude [degE7] */
    uint16_t COG; /* Course over ground [cdeg] */
    uint16_t heading; /* True heading [cdeg] */
    uint16_t velocity; /* Speed over ground [cm/s] */
    int8_t turn_rate; /* Turn rate [cdeg/s] */
    uint8_t navigational_status; /* Navigational status */
    uint8_t type; /* Type of vessels */
    uint16_t dimension_bow; /* Distance from lat/lon location to bow [m] */
    uint16_t dimension_stern; /* Distance from lat/lon location to stern [m] */
    uint8_t dimension_port; /* Distance from lat/lon location to port side [m] */
    uint8_t dimension_starboard; /* Distance from lat/lon location to starboard side [m] */
    char callsign[7]; /* The vessel callsign */
    char name[20]; /* The vessel name */
    uint16_t tslc; /* Time since last communication in seconds [s] */
    uint16_t flags; /* Bitmask to indicate various statuses including valid data fields */
    
} ulog_ais_vessel_t;

/**
 * Defines Ais Vessel message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_ais_vessel(ulog_t *log);

/**
 * Subscribe Ais Vessel message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_ais_vessel(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Ais Vessel message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_ais_vessel(ulog_t *log, ulog_msg_id_t id, const ulog_ais_vessel_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_AIS_VESSEL_H */