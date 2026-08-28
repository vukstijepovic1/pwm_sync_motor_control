/**
 * @file    ulog_rc_channels.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_RC_CHANNELS_H
#define ULOG_RC_CHANNELS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_rc_channels_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint32_t time_boot_ms; /* Timestamp (time since system boot). [ms] */
    uint8_t chancount; /* Total number of RC channels being received. This can be larger than 18, indicating that more channels are available but not given in this message. This value should be 0 when no RC channels are available. */
    uint16_t chan1_raw; /* RC channel 1 value. [us] */
    uint16_t chan2_raw; /* RC channel 2 value. [us] */
    uint16_t chan3_raw; /* RC channel 3 value. [us] */
    uint16_t chan4_raw; /* RC channel 4 value. [us] */
    uint16_t chan5_raw; /* RC channel 5 value. [us] */
    uint16_t chan6_raw; /* RC channel 6 value. [us] */
    uint16_t chan7_raw; /* RC channel 7 value. [us] */
    uint16_t chan8_raw; /* RC channel 8 value. [us] */
    uint16_t chan9_raw; /* RC channel 9 value. [us] */
    uint16_t chan10_raw; /* RC channel 10 value. [us] */
    uint16_t chan11_raw; /* RC channel 11 value. [us] */
    uint16_t chan12_raw; /* RC channel 12 value. [us] */
    uint16_t chan13_raw; /* RC channel 13 value. [us] */
    uint16_t chan14_raw; /* RC channel 14 value. [us] */
    uint16_t chan15_raw; /* RC channel 15 value. [us] */
    uint16_t chan16_raw; /* RC channel 16 value. [us] */
    uint16_t chan17_raw; /* RC channel 17 value. [us] */
    uint16_t chan18_raw; /* RC channel 18 value. [us] */
    uint8_t rssi; /* Receive signal strength indicator in device-dependent units/scale. Values: [0-254], UINT8_MAX: invalid/unknown. */
    
} ulog_rc_channels_t;

/**
 * Defines Rc Channels message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_rc_channels(ulog_t *log);

/**
 * Subscribe Rc Channels message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_rc_channels(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Rc Channels message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_rc_channels(ulog_t *log, ulog_msg_id_t id, const ulog_rc_channels_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_RC_CHANNELS_H */