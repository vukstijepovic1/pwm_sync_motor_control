/**
 * @file    ulog_file_transfer_protocol.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_FILE_TRANSFER_PROTOCOL_H
#define ULOG_FILE_TRANSFER_PROTOCOL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_file_transfer_protocol_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t target_network; /* Network ID (0 for broadcast) */
    uint8_t target_system; /* System ID (0 for broadcast) */
    uint8_t target_component; /* Component ID (0 for broadcast) */
    uint8_t payload[251]; /* Variable length payload. The length is defined by the remaining message length when subtracting the header and other fields. The content/format of this block is defined in https://mavlink.io/en/services/ftp.html. */
    
} ulog_file_transfer_protocol_t;

/**
 * Defines File Transfer Protocol message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_file_transfer_protocol(ulog_t *log);

/**
 * Subscribe File Transfer Protocol message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_file_transfer_protocol(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write File Transfer Protocol message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_file_transfer_protocol(ulog_t *log, ulog_msg_id_t id, const ulog_file_transfer_protocol_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_FILE_TRANSFER_PROTOCOL_H */