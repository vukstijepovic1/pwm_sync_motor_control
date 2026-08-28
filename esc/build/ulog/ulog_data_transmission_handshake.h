/**
 * @file    ulog_data_transmission_handshake.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_DATA_TRANSMISSION_HANDSHAKE_H
#define ULOG_DATA_TRANSMISSION_HANDSHAKE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_data_transmission_handshake_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t type; /* Type of requested/acknowledged data. */
    uint32_t size; /* total data size (set on ACK only). [bytes] */
    uint16_t width; /* Width of a matrix or image. */
    uint16_t height; /* Height of a matrix or image. */
    uint16_t packets; /* Number of packets being sent (set on ACK only). */
    uint8_t payload; /* Payload size per packet (normally 253 byte, see DATA field size in message ENCAPSULATED_DATA) (set on ACK only). [bytes] */
    uint8_t jpg_quality; /* JPEG quality. Values: [1-100]. [%] */
    
} ulog_data_transmission_handshake_t;

/**
 * Defines Data Transmission Handshake message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_data_transmission_handshake(ulog_t *log);

/**
 * Subscribe Data Transmission Handshake message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_data_transmission_handshake(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Data Transmission Handshake message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_data_transmission_handshake(ulog_t *log, ulog_msg_id_t id, const ulog_data_transmission_handshake_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_DATA_TRANSMISSION_HANDSHAKE_H */