/**
 * @file    ulog_rc_channels_override.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_RC_CHANNELS_OVERRIDE_H
#define ULOG_RC_CHANNELS_OVERRIDE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_rc_channels_override_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t target_system; /* System ID */
    uint8_t target_component; /* Component ID */
    uint16_t chan1_raw; /* RC channel 1 value. A value of UINT16_MAX means to ignore this field. A value of 0 means to release this channel back to the RC radio. [us] */
    uint16_t chan2_raw; /* RC channel 2 value. A value of UINT16_MAX means to ignore this field. A value of 0 means to release this channel back to the RC radio. [us] */
    uint16_t chan3_raw; /* RC channel 3 value. A value of UINT16_MAX means to ignore this field. A value of 0 means to release this channel back to the RC radio. [us] */
    uint16_t chan4_raw; /* RC channel 4 value. A value of UINT16_MAX means to ignore this field. A value of 0 means to release this channel back to the RC radio. [us] */
    uint16_t chan5_raw; /* RC channel 5 value. A value of UINT16_MAX means to ignore this field. A value of 0 means to release this channel back to the RC radio. [us] */
    uint16_t chan6_raw; /* RC channel 6 value. A value of UINT16_MAX means to ignore this field. A value of 0 means to release this channel back to the RC radio. [us] */
    uint16_t chan7_raw; /* RC channel 7 value. A value of UINT16_MAX means to ignore this field. A value of 0 means to release this channel back to the RC radio. [us] */
    uint16_t chan8_raw; /* RC channel 8 value. A value of UINT16_MAX means to ignore this field. A value of 0 means to release this channel back to the RC radio. [us] */
    uint16_t chan9_raw; /* RC channel 9 value. A value of 0 or UINT16_MAX means to ignore this field. A value of UINT16_MAX-1 means to release this channel back to the RC radio. [us] */
    uint16_t chan10_raw; /* RC channel 10 value. A value of 0 or UINT16_MAX means to ignore this field. A value of UINT16_MAX-1 means to release this channel back to the RC radio. [us] */
    uint16_t chan11_raw; /* RC channel 11 value. A value of 0 or UINT16_MAX means to ignore this field. A value of UINT16_MAX-1 means to release this channel back to the RC radio. [us] */
    uint16_t chan12_raw; /* RC channel 12 value. A value of 0 or UINT16_MAX means to ignore this field. A value of UINT16_MAX-1 means to release this channel back to the RC radio. [us] */
    uint16_t chan13_raw; /* RC channel 13 value. A value of 0 or UINT16_MAX means to ignore this field. A value of UINT16_MAX-1 means to release this channel back to the RC radio. [us] */
    uint16_t chan14_raw; /* RC channel 14 value. A value of 0 or UINT16_MAX means to ignore this field. A value of UINT16_MAX-1 means to release this channel back to the RC radio. [us] */
    uint16_t chan15_raw; /* RC channel 15 value. A value of 0 or UINT16_MAX means to ignore this field. A value of UINT16_MAX-1 means to release this channel back to the RC radio. [us] */
    uint16_t chan16_raw; /* RC channel 16 value. A value of 0 or UINT16_MAX means to ignore this field. A value of UINT16_MAX-1 means to release this channel back to the RC radio. [us] */
    uint16_t chan17_raw; /* RC channel 17 value. A value of 0 or UINT16_MAX means to ignore this field. A value of UINT16_MAX-1 means to release this channel back to the RC radio. [us] */
    uint16_t chan18_raw; /* RC channel 18 value. A value of 0 or UINT16_MAX means to ignore this field. A value of UINT16_MAX-1 means to release this channel back to the RC radio. [us] */
    
} ulog_rc_channels_override_t;

/**
 * Defines Rc Channels Override message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_rc_channels_override(ulog_t *log);

/**
 * Subscribe Rc Channels Override message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_rc_channels_override(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Rc Channels Override message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_rc_channels_override(ulog_t *log, ulog_msg_id_t id, const ulog_rc_channels_override_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_RC_CHANNELS_OVERRIDE_H */