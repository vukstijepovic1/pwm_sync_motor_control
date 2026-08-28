/**
 * @file    ulog_wifi_config_ap.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_WIFI_CONFIG_AP_H
#define ULOG_WIFI_CONFIG_AP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_wifi_config_ap_t {
    uint64_t timestamp; /* Timestamp [us] */
    char ssid[32]; /* Name of Wi-Fi network (SSID). Blank to leave it unchanged when setting. Current SSID when sent back as a response. */
    char password[64]; /* Password. Blank for an open AP. MD5 hash when message is sent back as a response. */
    int8_t mode; /* WiFi Mode. */
    int8_t response; /* Message acceptance response (sent back to GS). */
    
} ulog_wifi_config_ap_t;

/**
 * Defines Wifi Config Ap message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_wifi_config_ap(ulog_t *log);

/**
 * Subscribe Wifi Config Ap message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_wifi_config_ap(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Wifi Config Ap message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_wifi_config_ap(ulog_t *log, ulog_msg_id_t id, const ulog_wifi_config_ap_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_WIFI_CONFIG_AP_H */