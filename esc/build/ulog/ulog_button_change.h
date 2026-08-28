/**
 * @file    ulog_button_change.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_BUTTON_CHANGE_H
#define ULOG_BUTTON_CHANGE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_button_change_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint32_t time_boot_ms; /* Timestamp (time since system boot). [ms] */
    uint32_t last_change_ms; /* Time of last change of button state. [ms] */
    uint8_t state; /* Bitmap for state of buttons. */
    
} ulog_button_change_t;

/**
 * Defines Button Change message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_button_change(ulog_t *log);

/**
 * Subscribe Button Change message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_button_change(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Button Change message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_button_change(ulog_t *log, ulog_msg_id_t id, const ulog_button_change_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_BUTTON_CHANGE_H */