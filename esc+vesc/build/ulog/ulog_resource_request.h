/**
 * @file    ulog_resource_request.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_RESOURCE_REQUEST_H
#define ULOG_RESOURCE_REQUEST_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_resource_request_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t request_id; /* Request ID. This ID should be re-used when sending back URI contents */
    uint8_t uri_type; /* The type of requested URI. 0 = a file via URL. 1 = a UAVCAN binary */
    uint8_t uri[120]; /* The requested unique resource identifier (URI). It is not necessarily a straight domain name (depends on the URI type enum) */
    uint8_t transfer_type; /* The way the autopilot wants to receive the URI. 0 = MAVLink FTP. 1 = binary stream. */
    uint8_t storage[120]; /* The storage path the autopilot wants the URI to be stored in. Will only be valid if the transfer_type has a storage associated (e.g. MAVLink FTP). */
    
} ulog_resource_request_t;

/**
 * Defines Resource Request message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_resource_request(ulog_t *log);

/**
 * Subscribe Resource Request message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_resource_request(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Resource Request message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_resource_request(ulog_t *log, ulog_msg_id_t id, const ulog_resource_request_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_RESOURCE_REQUEST_H */