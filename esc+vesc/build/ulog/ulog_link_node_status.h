/**
 * @file    ulog_link_node_status.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_LINK_NODE_STATUS_H
#define ULOG_LINK_NODE_STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_link_node_status_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t tx_buf; /* Remaining free transmit buffer space [%] */
    uint8_t rx_buf; /* Remaining free receive buffer space [%] */
    uint32_t tx_rate; /* Transmit rate [bytes/s] */
    uint32_t rx_rate; /* Receive rate [bytes/s] */
    uint16_t rx_parse_err; /* Number of bytes that could not be parsed correctly. [bytes] */
    uint16_t tx_overflows; /* Transmit buffer overflows. This number wraps around as it reaches UINT16_MAX [bytes] */
    uint16_t rx_overflows; /* Receive buffer overflows. This number wraps around as it reaches UINT16_MAX [bytes] */
    uint32_t messages_sent; /* Messages sent */
    uint32_t messages_received; /* Messages received (estimated from counting seq) */
    uint32_t messages_lost; /* Messages lost (estimated from counting seq) */
    
} ulog_link_node_status_t;

/**
 * Defines Link Node Status message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_link_node_status(ulog_t *log);

/**
 * Subscribe Link Node Status message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_link_node_status(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Link Node Status message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_link_node_status(ulog_t *log, ulog_msg_id_t id, const ulog_link_node_status_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_LINK_NODE_STATUS_H */