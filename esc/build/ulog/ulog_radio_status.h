/**
 * @file    ulog_radio_status.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_RADIO_STATUS_H
#define ULOG_RADIO_STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_radio_status_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t rssi; /* Local (message sender) received signal strength indication in device-dependent units/scale. Values: [0-254], UINT8_MAX: invalid/unknown. */
    uint8_t remrssi; /* Remote (message receiver) signal strength indication in device-dependent units/scale. Values: [0-254], UINT8_MAX: invalid/unknown. */
    uint8_t txbuf; /* Remaining free transmitter buffer space. [%] */
    uint8_t noise; /* Local background noise level. These are device dependent RSSI values (scale as approx 2x dB on SiK radios). Values: [0-254], UINT8_MAX: invalid/unknown. */
    uint8_t remnoise; /* Remote background noise level. These are device dependent RSSI values (scale as approx 2x dB on SiK radios). Values: [0-254], UINT8_MAX: invalid/unknown. */
    uint16_t rxerrors; /* Count of radio packet receive errors (since boot). */
    uint16_t fixed; /* Count of error corrected radio packets (since boot). */
    
} ulog_radio_status_t;

/**
 * Defines Radio Status message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_radio_status(ulog_t *log);

/**
 * Subscribe Radio Status message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_radio_status(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Radio Status message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_radio_status(ulog_t *log, ulog_msg_id_t id, const ulog_radio_status_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_RADIO_STATUS_H */