/**
 * @file    ulog_orbit_execution_status.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_ORBIT_EXECUTION_STATUS_H
#define ULOG_ORBIT_EXECUTION_STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_orbit_execution_status_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t time_usec; /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    float radius; /* Radius of the orbit circle. Positive values orbit clockwise, negative values orbit counter-clockwise. [m] */
    uint8_t frame; /* The coordinate system of the fields: x, y, z. */
    int32_t x; /* X coordinate of center point. Coordinate system depends on frame field: local = x position in meters * 1e4, global = latitude in degrees * 1e7. */
    int32_t y; /* Y coordinate of center point.  Coordinate system depends on frame field: local = x position in meters * 1e4, global = latitude in degrees * 1e7. */
    float z; /* Altitude of center point. Coordinate system depends on frame field. [m] */
    
} ulog_orbit_execution_status_t;

/**
 * Defines Orbit Execution Status message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_orbit_execution_status(ulog_t *log);

/**
 * Subscribe Orbit Execution Status message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_orbit_execution_status(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Orbit Execution Status message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_orbit_execution_status(ulog_t *log, ulog_msg_id_t id, const ulog_orbit_execution_status_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_ORBIT_EXECUTION_STATUS_H */