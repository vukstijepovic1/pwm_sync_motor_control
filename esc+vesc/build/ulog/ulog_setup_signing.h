/**
 * @file    ulog_setup_signing.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_SETUP_SIGNING_H
#define ULOG_SETUP_SIGNING_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_setup_signing_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t target_system; /* system id of the target */
    uint8_t target_component; /* component ID of the target */
    uint8_t secret_key[32]; /* signing key */
    uint64_t initial_timestamp; /* initial timestamp */
    
} ulog_setup_signing_t;

/**
 * Defines Setup Signing message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_setup_signing(ulog_t *log);

/**
 * Subscribe Setup Signing message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_setup_signing(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Setup Signing message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_setup_signing(ulog_t *log, ulog_msg_id_t id, const ulog_setup_signing_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_SETUP_SIGNING_H */