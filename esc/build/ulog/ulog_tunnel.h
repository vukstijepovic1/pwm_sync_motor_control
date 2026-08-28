/**
 * @file    ulog_tunnel.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_TUNNEL_H
#define ULOG_TUNNEL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_tunnel_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t target_system; /* System ID (can be 0 for broadcast, but this is discouraged) */
    uint8_t target_component; /* Component ID (can be 0 for broadcast, but this is discouraged) */
    uint16_t payload_type; /* A code that identifies the content of the payload (0 for unknown, which is the default). If this code is less than 32768, it is a 'registered' payload type and the corresponding code should be added to the MAV_TUNNEL_PAYLOAD_TYPE enum. Software creators can register blocks of types as needed. Codes greater than 32767 are considered local experiments and should not be checked in to any widely distributed codebase. */
    uint8_t payload_length; /* Length of the data transported in payload */
    uint8_t payload[128]; /* Variable length payload. The payload length is defined by payload_length. The entire content of this block is opaque unless you understand the encoding specified by payload_type. */
    
} ulog_tunnel_t;

/**
 * Defines Tunnel message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_tunnel(ulog_t *log);

/**
 * Subscribe Tunnel message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_tunnel(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Tunnel message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_tunnel(ulog_t *log, ulog_msg_id_t id, const ulog_tunnel_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_TUNNEL_H */