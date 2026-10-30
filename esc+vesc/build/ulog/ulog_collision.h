/**
 * @file    ulog_collision.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_COLLISION_H
#define ULOG_COLLISION_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_collision_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t src; /* Collision data source */
    uint32_t id; /* Unique identifier, domain based on src field */
    uint8_t action; /* Action that is being taken to avoid this collision */
    uint8_t threat_level; /* How concerned the aircraft is about this collision */
    float time_to_minimum_delta; /* Estimated time until collision occurs [s] */
    float altitude_minimum_delta; /* Closest vertical distance between vehicle and object [m] */
    float horizontal_minimum_delta; /* Closest horizontal distance between vehicle and object [m] */
    
} ulog_collision_t;

/**
 * Defines Collision message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_collision(ulog_t *log);

/**
 * Subscribe Collision message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_collision(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Collision message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_collision(ulog_t *log, ulog_msg_id_t id, const ulog_collision_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_COLLISION_H */