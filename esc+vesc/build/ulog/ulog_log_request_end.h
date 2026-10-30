/**
 * @file    ulog_log_request_end.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_LOG_REQUEST_END_H
#define ULOG_LOG_REQUEST_END_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_log_request_end_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t target_system; /* System ID */
    uint8_t target_component; /* Component ID */
    
} ulog_log_request_end_t;

/**
 * Defines Log Request End message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_log_request_end(ulog_t *log);

/**
 * Subscribe Log Request End message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_log_request_end(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Log Request End message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_log_request_end(ulog_t *log, ulog_msg_id_t id, const ulog_log_request_end_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_LOG_REQUEST_END_H */