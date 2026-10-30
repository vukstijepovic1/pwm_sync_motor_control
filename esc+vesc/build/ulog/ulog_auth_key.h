/**
 * @file    ulog_auth_key.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_AUTH_KEY_H
#define ULOG_AUTH_KEY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_auth_key_t {
    uint64_t timestamp; /* Timestamp [us] */
    char key[32]; /* key */
    
} ulog_auth_key_t;

/**
 * Defines Auth Key message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_auth_key(ulog_t *log);

/**
 * Subscribe Auth Key message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_auth_key(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Auth Key message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_auth_key(ulog_t *log, ulog_msg_id_t id, const ulog_auth_key_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_AUTH_KEY_H */