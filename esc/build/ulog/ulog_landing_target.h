/**
 * @file    ulog_landing_target.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_LANDING_TARGET_H
#define ULOG_LANDING_TARGET_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_landing_target_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t time_usec; /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    uint8_t target_num; /* The ID of the target if multiple targets are present */
    uint8_t frame; /* Coordinate frame used for following fields. */
    float angle_x; /* X-axis angular offset of the target from the center of the image [rad] */
    float angle_y; /* Y-axis angular offset of the target from the center of the image [rad] */
    float distance; /* Distance to the target from the vehicle [m] */
    float size_x; /* Size of target along x-axis [rad] */
    float size_y; /* Size of target along y-axis [rad] */
    float x; /* X Position of the landing target in MAV_FRAME [m] */
    float y; /* Y Position of the landing target in MAV_FRAME [m] */
    float z; /* Z Position of the landing target in MAV_FRAME [m] */
    float q[4]; /* Quaternion of landing target orientation (w, x, y, z order, zero-rotation is 1, 0, 0, 0) */
    uint8_t type; /* Type of landing target */
    uint8_t position_valid; /* Boolean indicating whether the position fields (x, y, z, q, type) contain valid target position information (valid: 1, invalid: 0). Default is 0 (invalid). */
    
} ulog_landing_target_t;

/**
 * Defines Landing Target message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_landing_target(ulog_t *log);

/**
 * Subscribe Landing Target message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_landing_target(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Landing Target message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_landing_target(ulog_t *log, ulog_msg_id_t id, const ulog_landing_target_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_LANDING_TARGET_H */