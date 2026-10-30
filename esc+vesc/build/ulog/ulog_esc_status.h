/**
 * @file    ulog_esc_status.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_ESC_STATUS_H
#define ULOG_ESC_STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_esc_status_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t index; /* Index of the first ESC in this message. minValue = 0, maxValue = 60, increment = 4. */
    uint64_t time_usec; /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us] */
    int32_t rpm[4]; /* Reported motor RPM from each ESC (negative for reverse rotation). [rpm] */
    float voltage[4]; /* Voltage measured from each ESC. [V] */
    float current[4]; /* Current measured from each ESC. [A] */
    
} ulog_esc_status_t;

/**
 * Defines Esc Status message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_esc_status(ulog_t *log);

/**
 * Subscribe Esc Status message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_esc_status(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Esc Status message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_esc_status(ulog_t *log, ulog_msg_id_t id, const ulog_esc_status_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_ESC_STATUS_H */