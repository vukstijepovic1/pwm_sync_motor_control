/**
 * @file    ulog_rc_channels_scaled.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_RC_CHANNELS_SCALED_H
#define ULOG_RC_CHANNELS_SCALED_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_rc_channels_scaled_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint32_t time_boot_ms; /* Timestamp (time since system boot). [ms] */
    uint8_t port; /* Servo output port (set of 8 outputs = 1 port). Flight stacks running on Pixhawk should use: 0 = MAIN, 1 = AUX. */
    int16_t chan1_scaled; /* RC channel 1 value scaled. */
    int16_t chan2_scaled; /* RC channel 2 value scaled. */
    int16_t chan3_scaled; /* RC channel 3 value scaled. */
    int16_t chan4_scaled; /* RC channel 4 value scaled. */
    int16_t chan5_scaled; /* RC channel 5 value scaled. */
    int16_t chan6_scaled; /* RC channel 6 value scaled. */
    int16_t chan7_scaled; /* RC channel 7 value scaled. */
    int16_t chan8_scaled; /* RC channel 8 value scaled. */
    uint8_t rssi; /* Receive signal strength indicator in device-dependent units/scale. Values: [0-254], UINT8_MAX: invalid/unknown. */
    
} ulog_rc_channels_scaled_t;

/**
 * Defines Rc Channels Scaled message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_rc_channels_scaled(ulog_t *log);

/**
 * Subscribe Rc Channels Scaled message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_rc_channels_scaled(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Rc Channels Scaled message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_rc_channels_scaled(ulog_t *log, ulog_msg_id_t id, const ulog_rc_channels_scaled_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_RC_CHANNELS_SCALED_H */