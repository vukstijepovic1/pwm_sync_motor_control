/**
 * @file    ulog_event.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_EVENT_H
#define ULOG_EVENT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_event_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t destination_component; /* Component ID */
    uint8_t destination_system; /* System ID */
    uint32_t id; /* Event ID (as defined in the component metadata) */
    uint32_t event_time_boot_ms; /* Timestamp (time since system boot when the event happened). [ms] */
    uint16_t sequence; /* Sequence number. */
    uint8_t log_levels; /* Log levels: 4 bits MSB: internal (for logging purposes), 4 bits LSB: external. Levels: Emergency = 0, Alert = 1, Critical = 2, Error = 3, Warning = 4, Notice = 5, Info = 6, Debug = 7, Protocol = 8, Disabled = 9 */
    uint8_t arguments[40]; /* Arguments (depend on event ID). */
    
} ulog_event_t;

/**
 * Defines Event message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_event(ulog_t *log);

/**
 * Subscribe Event message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_event(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Event message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_event(ulog_t *log, ulog_msg_id_t id, const ulog_event_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_EVENT_H */