/**
 * @file    ulog_att_pos_mocap.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_ATT_POS_MOCAP_H
#define ULOG_ATT_POS_MOCAP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_att_pos_mocap_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t time_usec; /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    float q[4]; /* Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0) */
    float x; /* X position (NED) [m] */
    float y; /* Y position (NED) [m] */
    float z; /* Z position (NED) [m] */
    float covariance[21]; /* Row-major representation of a pose 6x6 cross-covariance matrix upper right triangle (states: x, y, z, roll, pitch, yaw; first six entries are the first ROW, next five entries are the second ROW, etc.). If unknown, assign NaN value to first element in the array. */
    
} ulog_att_pos_mocap_t;

/**
 * Defines Att Pos Mocap message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_att_pos_mocap(ulog_t *log);

/**
 * Subscribe Att Pos Mocap message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_att_pos_mocap(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Att Pos Mocap message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_att_pos_mocap(ulog_t *log, ulog_msg_id_t id, const ulog_att_pos_mocap_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_ATT_POS_MOCAP_H */