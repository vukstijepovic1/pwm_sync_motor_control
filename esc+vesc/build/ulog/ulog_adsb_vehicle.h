/**
 * @file    ulog_adsb_vehicle.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_ADSB_VEHICLE_H
#define ULOG_ADSB_VEHICLE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_adsb_vehicle_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint32_t ICAO_address; /* ICAO address */
    int32_t lat; /* Latitude [degE7] */
    int32_t lon; /* Longitude [degE7] */
    uint8_t altitude_type; /* ADSB altitude type. */
    int32_t altitude; /* Altitude(ASL) [mm] */
    uint16_t heading; /* Course over ground [cdeg] */
    uint16_t hor_velocity; /* The horizontal velocity [cm/s] */
    int16_t ver_velocity; /* The vertical velocity. Positive is up [cm/s] */
    char callsign[9]; /* The callsign, 8+null */
    uint8_t emitter_type; /* ADSB emitter type. */
    uint8_t tslc; /* Time since last communication in seconds [s] */
    uint16_t flags; /* Bitmap to indicate various statuses including valid data fields */
    uint16_t squawk; /* Squawk code. Note that the code is in decimal: e.g. 7700 (general emergency) is encoded as binary 0b0001_1110_0001_0100, not(!) as 0b0000_111_111_000_000 */
    
} ulog_adsb_vehicle_t;

/**
 * Defines Adsb Vehicle message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_adsb_vehicle(ulog_t *log);

/**
 * Subscribe Adsb Vehicle message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_adsb_vehicle(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Adsb Vehicle message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_adsb_vehicle(ulog_t *log, ulog_msg_id_t id, const ulog_adsb_vehicle_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_ADSB_VEHICLE_H */