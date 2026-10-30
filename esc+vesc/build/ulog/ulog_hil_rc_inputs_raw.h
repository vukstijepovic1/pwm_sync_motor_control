/**
 * @file    ulog_hil_rc_inputs_raw.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_HIL_RC_INPUTS_RAW_H
#define ULOG_HIL_RC_INPUTS_RAW_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_hil_rc_inputs_raw_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t time_usec; /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    uint16_t chan1_raw; /* RC channel 1 value [us] */
    uint16_t chan2_raw; /* RC channel 2 value [us] */
    uint16_t chan3_raw; /* RC channel 3 value [us] */
    uint16_t chan4_raw; /* RC channel 4 value [us] */
    uint16_t chan5_raw; /* RC channel 5 value [us] */
    uint16_t chan6_raw; /* RC channel 6 value [us] */
    uint16_t chan7_raw; /* RC channel 7 value [us] */
    uint16_t chan8_raw; /* RC channel 8 value [us] */
    uint16_t chan9_raw; /* RC channel 9 value [us] */
    uint16_t chan10_raw; /* RC channel 10 value [us] */
    uint16_t chan11_raw; /* RC channel 11 value [us] */
    uint16_t chan12_raw; /* RC channel 12 value [us] */
    uint8_t rssi; /* Receive signal strength indicator in device-dependent units/scale. Values: [0-254], UINT8_MAX: invalid/unknown. */
    
} ulog_hil_rc_inputs_raw_t;

/**
 * Defines Hil Rc Inputs Raw message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_hil_rc_inputs_raw(ulog_t *log);

/**
 * Subscribe Hil Rc Inputs Raw message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_hil_rc_inputs_raw(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Hil Rc Inputs Raw message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_hil_rc_inputs_raw(ulog_t *log, ulog_msg_id_t id, const ulog_hil_rc_inputs_raw_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_HIL_RC_INPUTS_RAW_H */