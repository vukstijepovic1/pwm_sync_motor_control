/**
 * @file    ulog_safety_allowed_area.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_SAFETY_ALLOWED_AREA_H
#define ULOG_SAFETY_ALLOWED_AREA_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_safety_allowed_area_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t frame; /* Coordinate frame. Can be either global, GPS, right-handed with Z axis up or local, right handed, Z axis down. */
    float p1x; /* x position 1 / Latitude 1 [m] */
    float p1y; /* y position 1 / Longitude 1 [m] */
    float p1z; /* z position 1 / Altitude 1 [m] */
    float p2x; /* x position 2 / Latitude 2 [m] */
    float p2y; /* y position 2 / Longitude 2 [m] */
    float p2z; /* z position 2 / Altitude 2 [m] */
    
} ulog_safety_allowed_area_t;

/**
 * Defines Safety Allowed Area message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_safety_allowed_area(ulog_t *log);

/**
 * Subscribe Safety Allowed Area message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_safety_allowed_area(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Safety Allowed Area message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_safety_allowed_area(ulog_t *log, ulog_msg_id_t id, const ulog_safety_allowed_area_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_SAFETY_ALLOWED_AREA_H */