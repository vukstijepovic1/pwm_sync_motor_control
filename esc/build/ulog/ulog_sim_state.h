/**
 * @file    ulog_sim_state.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_SIM_STATE_H
#define ULOG_SIM_STATE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_sim_state_t {
    uint64_t timestamp; /* Timestamp [us] */
    float q1; /* True attitude quaternion component 1, w (1 in null-rotation) */
    float q2; /* True attitude quaternion component 2, x (0 in null-rotation) */
    float q3; /* True attitude quaternion component 3, y (0 in null-rotation) */
    float q4; /* True attitude quaternion component 4, z (0 in null-rotation) */
    float roll; /* Attitude roll expressed as Euler angles, not recommended except for human-readable outputs [rad] */
    float pitch; /* Attitude pitch expressed as Euler angles, not recommended except for human-readable outputs [rad] */
    float yaw; /* Attitude yaw expressed as Euler angles, not recommended except for human-readable outputs [rad] */
    float xacc; /* X acceleration [m/s/s] */
    float yacc; /* Y acceleration [m/s/s] */
    float zacc; /* Z acceleration [m/s/s] */
    float xgyro; /* Angular speed around X axis [rad/s] */
    float ygyro; /* Angular speed around Y axis [rad/s] */
    float zgyro; /* Angular speed around Z axis [rad/s] */
    float lat; /* Latitude (lower precision). Both this and the lat_int field should be set. [deg] */
    float lon; /* Longitude (lower precision). Both this and the lon_int field should be set. [deg] */
    float alt; /* Altitude [m] */
    float std_dev_horz; /* Horizontal position standard deviation */
    float std_dev_vert; /* Vertical position standard deviation */
    float vn; /* True velocity in north direction in earth-fixed NED frame [m/s] */
    float ve; /* True velocity in east direction in earth-fixed NED frame [m/s] */
    float vd; /* True velocity in down direction in earth-fixed NED frame [m/s] */
    int32_t lat_int; /* Latitude (higher precision). If 0, recipients should use the lat field value (otherwise this field is preferred). [degE7] */
    int32_t lon_int; /* Longitude (higher precision). If 0, recipients should use the lon field value (otherwise this field is preferred). [degE7] */
    
} ulog_sim_state_t;

/**
 * Defines Sim State message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_sim_state(ulog_t *log);

/**
 * Subscribe Sim State message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_sim_state(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Sim State message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_sim_state(ulog_t *log, ulog_msg_id_t id, const ulog_sim_state_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_SIM_STATE_H */