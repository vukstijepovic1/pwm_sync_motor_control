/**
 * @file    ulog_open_drone_id_basic_id.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_OPEN_DRONE_ID_BASIC_ID_H
#define ULOG_OPEN_DRONE_ID_BASIC_ID_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_open_drone_id_basic_id_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t target_system; /* System ID (0 for broadcast). */
    uint8_t target_component; /* Component ID (0 for broadcast). */
    uint8_t id_or_mac[20]; /* Only used for drone ID data received from other UAs. See detailed description at https://mavlink.io/en/services/opendroneid.html.  */
    uint8_t id_type; /* Indicates the format for the uas_id field of this message. */
    uint8_t ua_type; /* Indicates the type of UA (Unmanned Aircraft). */
    uint8_t uas_id[20]; /* UAS (Unmanned Aircraft System) ID following the format specified by id_type. Shall be filled with nulls in the unused portion of the field. */
    
} ulog_open_drone_id_basic_id_t;

/**
 * Defines Open Drone Id Basic Id message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_open_drone_id_basic_id(ulog_t *log);

/**
 * Subscribe Open Drone Id Basic Id message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_open_drone_id_basic_id(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Open Drone Id Basic Id message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_open_drone_id_basic_id(ulog_t *log, ulog_msg_id_t id, const ulog_open_drone_id_basic_id_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_OPEN_DRONE_ID_BASIC_ID_H */