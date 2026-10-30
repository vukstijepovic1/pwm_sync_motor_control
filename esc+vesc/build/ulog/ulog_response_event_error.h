/**
 * @file    ulog_response_event_error.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_RESPONSE_EVENT_ERROR_H
#define ULOG_RESPONSE_EVENT_ERROR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_response_event_error_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t target_system; /* System ID */
    uint8_t target_component; /* Component ID */
    uint16_t sequence; /* Sequence number. */
    uint16_t sequence_oldest_available; /* Oldest Sequence number that is still available after the sequence set in REQUEST_EVENT. */
    uint8_t reason; /* Error reason. */
    
} ulog_response_event_error_t;

/**
 * Defines Response Event Error message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_response_event_error(ulog_t *log);

/**
 * Subscribe Response Event Error message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_response_event_error(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Response Event Error message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_response_event_error(ulog_t *log, ulog_msg_id_t id, const ulog_response_event_error_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_RESPONSE_EVENT_ERROR_H */