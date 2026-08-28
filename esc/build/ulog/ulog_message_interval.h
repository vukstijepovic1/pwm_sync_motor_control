/**
 * @file    ulog_message_interval.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_MESSAGE_INTERVAL_H
#define ULOG_MESSAGE_INTERVAL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_message_interval_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint16_t message_id; /* The ID of the requested MAVLink message. v1.0 is limited to 254 messages. */
    int32_t interval_us; /* The interval between two messages. A value of -1 indicates this stream is disabled, 0 indicates it is not available, > 0 indicates the interval at which it is sent. [us] */
    
} ulog_message_interval_t;

/**
 * Defines Message Interval message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_message_interval(ulog_t *log);

/**
 * Subscribe Message Interval message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_message_interval(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Message Interval message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_message_interval(ulog_t *log, ulog_msg_id_t id, const ulog_message_interval_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_MESSAGE_INTERVAL_H */