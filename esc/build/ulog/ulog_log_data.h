/**
 * @file    ulog_log_data.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_LOG_DATA_H
#define ULOG_LOG_DATA_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_log_data_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint16_t id; /* Log id (from LOG_ENTRY reply) */
    uint32_t ofs; /* Offset into the log */
    uint8_t count; /* Number of bytes (zero for end of log) [bytes] */
    uint8_t data[90]; /* log data */
    
} ulog_log_data_t;

/**
 * Defines Log Data message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_log_data(ulog_t *log);

/**
 * Subscribe Log Data message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_log_data(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Log Data message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_log_data(ulog_t *log, ulog_msg_id_t id, const ulog_log_data_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_LOG_DATA_H */