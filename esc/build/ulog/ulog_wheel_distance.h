/**
 * @file    ulog_wheel_distance.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_WHEEL_DISTANCE_H
#define ULOG_WHEEL_DISTANCE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_wheel_distance_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t time_usec; /* Timestamp (synced to UNIX time or since system boot). [us] */
    uint8_t count; /* Number of wheels reported. */
    double distance[16]; /* Distance reported by individual wheel encoders. Forward rotations increase values, reverse rotations decrease them. Not all wheels will necessarily have wheel encoders; the mapping of encoders to wheel positions must be agreed/understood by the endpoints. [m] */
    
} ulog_wheel_distance_t;

/**
 * Defines Wheel Distance message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_wheel_distance(ulog_t *log);

/**
 * Subscribe Wheel Distance message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_wheel_distance(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Wheel Distance message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_wheel_distance(ulog_t *log, ulog_msg_id_t id, const ulog_wheel_distance_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_WHEEL_DISTANCE_H */