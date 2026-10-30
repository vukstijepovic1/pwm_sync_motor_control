/**
 * @file    ulog_ping.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_PING_H
#define ULOG_PING_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_ping_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t time_usec; /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    uint32_t seq; /* PING sequence */
    uint8_t target_system; /* 0: request ping from all receiving systems. If greater than 0: message is a ping response and number is the system id of the requesting system */
    uint8_t target_component; /* 0: request ping from all receiving components. If greater than 0: message is a ping response and number is the component id of the requesting component. */
    
} ulog_ping_t;

/**
 * Defines Ping message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_ping(ulog_t *log);

/**
 * Subscribe Ping message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_ping(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Ping message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_ping(ulog_t *log, ulog_msg_id_t id, const ulog_ping_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_PING_H */