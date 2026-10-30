/**
 * @file    ulog_log_entry.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_LOG_ENTRY_H
#define ULOG_LOG_ENTRY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_log_entry_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint16_t id; /* Log id */
    uint16_t num_logs; /* Total number of logs */
    uint16_t last_log_num; /* High log number */
    uint32_t time_utc; /* UTC timestamp of log since 1970, or 0 if not available [s] */
    uint32_t size; /* Size of the log (may be approximate) [bytes] */
    
} ulog_log_entry_t;

/**
 * Defines Log Entry message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_log_entry(ulog_t *log);

/**
 * Subscribe Log Entry message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_log_entry(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Log Entry message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_log_entry(ulog_t *log, ulog_msg_id_t id, const ulog_log_entry_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_LOG_ENTRY_H */