/**
 * @file    ulog_wifi_config_ap.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_wifi_config_ap.h"
#include "ulog_def.h"

const char ulog_wifi_config_ap_format[] = "wifi_config_ap:uint64_t timestamp;char[32] ssid;char[64] password;int8_t mode;int8_t response;";
const char ulog_wifi_config_ap_name[] = "wifi_config_ap";

int32_t ulog_format_wifi_config_ap(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_wifi_config_ap_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_wifi_config_ap_format, sizeof(ulog_wifi_config_ap_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_wifi_config_ap(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_wifi_config_ap_name) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_SUBSCRIPTION,
    };

    if(log->state == ULOG_STATE_DEFINITIONS_CREATED)
        log->state = ULOG_STATE_WRITING_DATA;

    if(log->state != ULOG_STATE_WRITING_DATA)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, &multi_id, sizeof(multi_id)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, &log->msg_cnt, sizeof(log->msg_cnt)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_wifi_config_ap_name, sizeof(ulog_wifi_config_ap_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_wifi_config_ap(ulog_t *log, ulog_msg_id_t id, const ulog_wifi_config_ap_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(char)*32
                    + sizeof(char)*64
                    + sizeof(int8_t)
                    + sizeof(int8_t)
                    ,
        .msg_type = ULOG_DEF_MSG_TYPE_LOGGED_DATA,
    };

    if(log->state != ULOG_STATE_WRITING_DATA || id >= log->msg_cnt) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, &id, sizeof(id)) < 0) {
        return 1;
    }

    /* Timestamp [us] */
    if (lfs_file_write(log->lfs, log->file, &src->timestamp, sizeof(src->timestamp)) < 0) {
        return 1;
    }

    /* Name of Wi-Fi network (SSID). Blank to leave it unchanged when setting. Current SSID when sent back as a response. */
    if (lfs_file_write(log->lfs, log->file, src->ssid, sizeof(src->ssid)) < 0) {
        return 1;
    }

    /* Password. Blank for an open AP. MD5 hash when message is sent back as a response. */
    if (lfs_file_write(log->lfs, log->file, src->password, sizeof(src->password)) < 0) {
        return 1;
    }

    /* WiFi Mode. */
    if (lfs_file_write(log->lfs, log->file, &src->mode, sizeof(src->mode)) < 0) {
        return 1;
    }

    /* Message acceptance response (sent back to GS). */
    if (lfs_file_write(log->lfs, log->file, &src->response, sizeof(src->response)) < 0) {
        return 1;
    }

    
    return 0;
}
