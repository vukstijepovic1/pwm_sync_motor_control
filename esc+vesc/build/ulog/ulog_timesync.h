/**
 * @file    ulog_timesync.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_TIMESYNC_H
#define ULOG_TIMESYNC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_timesync_t {
    uint64_t timestamp; /* Timestamp [us] */
    int64_t tc1; /* Time sync timestamp 1. Syncing: 0. Responding: Timestamp of responding component. [ns] */
    int64_t ts1; /* Time sync timestamp 2. Timestamp of syncing component (mirrored in response). [ns] */
    uint8_t target_system; /* Target system id. Request: 0 (broadcast) or id of specific system. Response must contain system id of the requesting component. */
    uint8_t target_component; /* Target component id. Request: 0 (broadcast) or id of specific component. Response must contain component id of the requesting component. */
    
} ulog_timesync_t;

/**
 * Defines Timesync message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_timesync(ulog_t *log);

/**
 * Subscribe Timesync message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_timesync(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Timesync message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_timesync(ulog_t *log, ulog_msg_id_t id, const ulog_timesync_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_TIMESYNC_H */