/**
 * @file    ulog_logging_ack.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_LOGGING_ACK_H
#define ULOG_LOGGING_ACK_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_logging_ack_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t target_system; /* system ID of the target */
    uint8_t target_component; /* component ID of the target */
    uint16_t sequence; /* sequence number (must match the one in LOGGING_DATA_ACKED) */
    
} ulog_logging_ack_t;

/**
 * Defines Logging Ack message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_logging_ack(ulog_t *log);

/**
 * Subscribe Logging Ack message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_logging_ack(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Logging Ack message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_logging_ack(ulog_t *log, ulog_msg_id_t id, const ulog_logging_ack_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_LOGGING_ACK_H */