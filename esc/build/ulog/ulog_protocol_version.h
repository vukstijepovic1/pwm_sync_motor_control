/**
 * @file    ulog_protocol_version.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_PROTOCOL_VERSION_H
#define ULOG_PROTOCOL_VERSION_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_protocol_version_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint16_t version; /* Currently active MAVLink version number * 100: v1.0 is 100, v2.0 is 200, etc. */
    uint16_t min_version; /* Minimum MAVLink version supported */
    uint16_t max_version; /* Maximum MAVLink version supported (set to the same value as version by default) */
    uint8_t spec_version_hash[8]; /* The first 8 bytes (not characters printed in hex!) of the git hash. */
    uint8_t library_version_hash[8]; /* The first 8 bytes (not characters printed in hex!) of the git hash. */
    
} ulog_protocol_version_t;

/**
 * Defines Protocol Version message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_protocol_version(ulog_t *log);

/**
 * Subscribe Protocol Version message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_protocol_version(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Protocol Version message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_protocol_version(ulog_t *log, ulog_msg_id_t id, const ulog_protocol_version_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_PROTOCOL_VERSION_H */