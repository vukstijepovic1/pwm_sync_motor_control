/**
 * @file    ulog_open_drone_id_system_update.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_OPEN_DRONE_ID_SYSTEM_UPDATE_H
#define ULOG_OPEN_DRONE_ID_SYSTEM_UPDATE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_open_drone_id_system_update_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t target_system; /* System ID (0 for broadcast). */
    uint8_t target_component; /* Component ID (0 for broadcast). */
    int32_t operator_latitude; /* Latitude of the operator. If unknown: 0 (both Lat/Lon). [degE7] */
    int32_t operator_longitude; /* Longitude of the operator. If unknown: 0 (both Lat/Lon). [degE7] */
    float operator_altitude_geo; /* Geodetic altitude of the operator relative to WGS84. If unknown: -1000 m. [m] */
    
} ulog_open_drone_id_system_update_t;

/**
 * Defines Open Drone Id System Update message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_open_drone_id_system_update(ulog_t *log);

/**
 * Subscribe Open Drone Id System Update message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_open_drone_id_system_update(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Open Drone Id System Update message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_open_drone_id_system_update(ulog_t *log, ulog_msg_id_t id, const ulog_open_drone_id_system_update_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_OPEN_DRONE_ID_SYSTEM_UPDATE_H */