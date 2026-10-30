/**
 * @file    ulog_control_system_state.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_CONTROL_SYSTEM_STATE_H
#define ULOG_CONTROL_SYSTEM_STATE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_control_system_state_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t time_usec; /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    float x_acc; /* X acceleration in body frame [m/s/s] */
    float y_acc; /* Y acceleration in body frame [m/s/s] */
    float z_acc; /* Z acceleration in body frame [m/s/s] */
    float x_vel; /* X velocity in body frame [m/s] */
    float y_vel; /* Y velocity in body frame [m/s] */
    float z_vel; /* Z velocity in body frame [m/s] */
    float x_pos; /* X position in local frame [m] */
    float y_pos; /* Y position in local frame [m] */
    float z_pos; /* Z position in local frame [m] */
    float airspeed; /* Airspeed, set to -1 if unknown [m/s] */
    float vel_variance[3]; /* Variance of body velocity estimate */
    float pos_variance[3]; /* Variance in local position */
    float q[4]; /* The attitude, represented as Quaternion */
    float roll_rate; /* Angular rate in roll axis [rad/s] */
    float pitch_rate; /* Angular rate in pitch axis [rad/s] */
    float yaw_rate; /* Angular rate in yaw axis [rad/s] */
    
} ulog_control_system_state_t;

/**
 * Defines Control System State message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_control_system_state(ulog_t *log);

/**
 * Subscribe Control System State message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_control_system_state(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Control System State message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_control_system_state(ulog_t *log, ulog_msg_id_t id, const ulog_control_system_state_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_CONTROL_SYSTEM_STATE_H */