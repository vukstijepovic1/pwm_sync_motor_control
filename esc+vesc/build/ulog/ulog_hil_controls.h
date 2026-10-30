/**
 * @file    ulog_hil_controls.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_HIL_CONTROLS_H
#define ULOG_HIL_CONTROLS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_hil_controls_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t time_usec; /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    float roll_ailerons; /* Control output -1 .. 1 */
    float pitch_elevator; /* Control output -1 .. 1 */
    float yaw_rudder; /* Control output -1 .. 1 */
    float throttle; /* Throttle 0 .. 1 */
    float aux1; /* Aux 1, -1 .. 1 */
    float aux2; /* Aux 2, -1 .. 1 */
    float aux3; /* Aux 3, -1 .. 1 */
    float aux4; /* Aux 4, -1 .. 1 */
    uint8_t mode; /* System mode. */
    uint8_t nav_mode; /* Navigation mode (MAV_NAV_MODE) */
    
} ulog_hil_controls_t;

/**
 * Defines Hil Controls message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_hil_controls(ulog_t *log);

/**
 * Subscribe Hil Controls message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_hil_controls(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Hil Controls message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_hil_controls(ulog_t *log, ulog_msg_id_t id, const ulog_hil_controls_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_HIL_CONTROLS_H */