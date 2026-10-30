/**
 * @file    ulog_mission_item.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_MISSION_ITEM_H
#define ULOG_MISSION_ITEM_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_mission_item_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t target_system; /* System ID */
    uint8_t target_component; /* Component ID */
    uint16_t seq; /* Sequence */
    uint8_t frame; /* The coordinate system of the waypoint. */
    uint16_t command; /* The scheduled action for the waypoint. */
    uint8_t current; /* false:0, true:1 */
    uint8_t autocontinue; /* Autocontinue to next waypoint. 0: false, 1: true. Set false to pause mission after the item completes. */
    float param1; /* PARAM1, see MAV_CMD enum */
    float param2; /* PARAM2, see MAV_CMD enum */
    float param3; /* PARAM3, see MAV_CMD enum */
    float param4; /* PARAM4, see MAV_CMD enum */
    float x; /* PARAM5 / local: X coordinate, global: latitude */
    float y; /* PARAM6 / local: Y coordinate, global: longitude */
    float z; /* PARAM7 / local: Z coordinate, global: altitude (relative or absolute, depending on frame). */
    uint8_t mission_type; /* Mission type. */
    
} ulog_mission_item_t;

/**
 * Defines Mission Item message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_mission_item(ulog_t *log);

/**
 * Subscribe Mission Item message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_mission_item(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Mission Item message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_mission_item(ulog_t *log, ulog_msg_id_t id, const ulog_mission_item_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_MISSION_ITEM_H */