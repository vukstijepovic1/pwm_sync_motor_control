/**
 * @file    ulog_cellular_config.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_CELLULAR_CONFIG_H
#define ULOG_CELLULAR_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_cellular_config_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t enable_lte; /* Enable/disable LTE. 0: setting unchanged, 1: disabled, 2: enabled. Current setting when sent back as a response. */
    uint8_t enable_pin; /* Enable/disable PIN on the SIM card. 0: setting unchanged, 1: disabled, 2: enabled. Current setting when sent back as a response. */
    char pin[16]; /* PIN sent to the SIM card. Blank when PIN is disabled. Empty when message is sent back as a response. */
    char new_pin[16]; /* New PIN when changing the PIN. Blank to leave it unchanged. Empty when message is sent back as a response. */
    char apn[32]; /* Name of the cellular APN. Blank to leave it unchanged. Current APN when sent back as a response. */
    char puk[16]; /* Required PUK code in case the user failed to authenticate 3 times with the PIN. Empty when message is sent back as a response. */
    uint8_t roaming; /* Enable/disable roaming. 0: setting unchanged, 1: disabled, 2: enabled. Current setting when sent back as a response. */
    uint8_t response; /* Message acceptance response (sent back to GS). */
    
} ulog_cellular_config_t;

/**
 * Defines Cellular Config message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_cellular_config(ulog_t *log);

/**
 * Subscribe Cellular Config message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_cellular_config(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Cellular Config message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_cellular_config(ulog_t *log, ulog_msg_id_t id, const ulog_cellular_config_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_CELLULAR_CONFIG_H */