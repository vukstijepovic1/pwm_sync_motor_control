/**
 * @file    ulog_hil_state.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_HIL_STATE_H
#define ULOG_HIL_STATE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_hil_state_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t time_usec; /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    float roll; /* Roll angle [rad] */
    float pitch; /* Pitch angle [rad] */
    float yaw; /* Yaw angle [rad] */
    float rollspeed; /* Body frame roll / phi angular speed [rad/s] */
    float pitchspeed; /* Body frame pitch / theta angular speed [rad/s] */
    float yawspeed; /* Body frame yaw / psi angular speed [rad/s] */
    int32_t lat; /* Latitude [degE7] */
    int32_t lon; /* Longitude [degE7] */
    int32_t alt; /* Altitude [mm] */
    int16_t vx; /* Ground X Speed (Latitude) [cm/s] */
    int16_t vy; /* Ground Y Speed (Longitude) [cm/s] */
    int16_t vz; /* Ground Z Speed (Altitude) [cm/s] */
    int16_t xacc; /* X acceleration [mG] */
    int16_t yacc; /* Y acceleration [mG] */
    int16_t zacc; /* Z acceleration [mG] */
    
} ulog_hil_state_t;

/**
 * Defines Hil State message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_hil_state(ulog_t *log);

/**
 * Subscribe Hil State message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_hil_state(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Hil State message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_hil_state(ulog_t *log, ulog_msg_id_t id, const ulog_hil_state_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_HIL_STATE_H */