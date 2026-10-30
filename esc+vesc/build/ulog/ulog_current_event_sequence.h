/**
 * @file    ulog_current_event_sequence.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_CURRENT_EVENT_SEQUENCE_H
#define ULOG_CURRENT_EVENT_SEQUENCE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_current_event_sequence_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint16_t sequence; /* Sequence number. */
    uint8_t flags; /* Flag bitset. */
    
} ulog_current_event_sequence_t;

/**
 * Defines Current Event Sequence message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_current_event_sequence(ulog_t *log);

/**
 * Subscribe Current Event Sequence message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_current_event_sequence(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Current Event Sequence message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_current_event_sequence(ulog_t *log, ulog_msg_id_t id, const ulog_current_event_sequence_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_CURRENT_EVENT_SEQUENCE_H */