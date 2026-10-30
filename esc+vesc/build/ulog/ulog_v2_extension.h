/**
 * @file    ulog_v2_extension.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_V2_EXTENSION_H
#define ULOG_V2_EXTENSION_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_v2_extension_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t target_network; /* Network ID (0 for broadcast) */
    uint8_t target_system; /* System ID (0 for broadcast) */
    uint8_t target_component; /* Component ID (0 for broadcast) */
    uint16_t message_type; /* A code that identifies the software component that understands this message (analogous to USB device classes or mime type strings). If this code is less than 32768, it is considered a 'registered' protocol extension and the corresponding entry should be added to https://github.com/mavlink/mavlink/definition_files/extension_message_ids.xml. Software creators can register blocks of message IDs as needed (useful for GCS specific metadata, etc...). Message_types greater than 32767 are considered local experiments and should not be checked in to any widely distributed codebase. */
    uint8_t payload[249]; /* Variable length payload. The length must be encoded in the payload as part of the message_type protocol, e.g. by including the length as payload data, or by terminating the payload data with a non-zero marker. This is required in order to reconstruct zero-terminated payloads that are (or otherwise would be) trimmed by MAVLink 2 empty-byte truncation. The entire content of the payload block is opaque unless you understand the encoding message_type. The particular encoding used can be extension specific and might not always be documented as part of the MAVLink specification. */
    
} ulog_v2_extension_t;

/**
 * Defines V2 Extension message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_v2_extension(ulog_t *log);

/**
 * Subscribe V2 Extension message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_v2_extension(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write V2 Extension message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_v2_extension(ulog_t *log, ulog_msg_id_t id, const ulog_v2_extension_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_V2_EXTENSION_H */