/**
 * @file    ulog_serial_control.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_SERIAL_CONTROL_H
#define ULOG_SERIAL_CONTROL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_serial_control_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t device; /* Serial control device type. */
    uint8_t flags; /* Bitmap of serial control flags. */
    uint16_t timeout; /* Timeout for reply data [ms] */
    uint32_t baudrate; /* Baudrate of transfer. Zero means no change. [bits/s] */
    uint8_t count; /* how many bytes in this transfer [bytes] */
    uint8_t data[70]; /* serial data */
    uint8_t target_system; /* System ID */
    uint8_t target_component; /* Component ID */
    
} ulog_serial_control_t;

/**
 * Defines Serial Control message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_serial_control(ulog_t *log);

/**
 * Subscribe Serial Control message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_serial_control(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Serial Control message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_serial_control(ulog_t *log, ulog_msg_id_t id, const ulog_serial_control_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_SERIAL_CONTROL_H */