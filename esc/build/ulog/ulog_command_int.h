/**
 * @file    ulog_command_int.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_COMMAND_INT_H
#define ULOG_COMMAND_INT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_command_int_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t target_system; /* System ID */
    uint8_t target_component; /* Component ID */
    uint8_t frame; /* The coordinate system of the COMMAND. */
    uint16_t command; /* The scheduled action for the mission item. */
    uint8_t current; /* Not used. */
    uint8_t autocontinue; /* Not used (set 0). */
    float param1; /* PARAM1, see MAV_CMD enum */
    float param2; /* PARAM2, see MAV_CMD enum */
    float param3; /* PARAM3, see MAV_CMD enum */
    float param4; /* PARAM4, see MAV_CMD enum */
    int32_t x; /* PARAM5 / local: x position in meters * 1e4, global: latitude in degrees * 10^7 */
    int32_t y; /* PARAM6 / local: y position in meters * 1e4, global: longitude in degrees * 10^7 */
    float z; /* PARAM7 / z position: global: altitude in meters (relative or absolute, depending on frame). */
    
} ulog_command_int_t;

/**
 * Defines Command Int message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_command_int(ulog_t *log);

/**
 * Subscribe Command Int message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_command_int(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Command Int message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_command_int(ulog_t *log, ulog_msg_id_t id, const ulog_command_int_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_COMMAND_INT_H */