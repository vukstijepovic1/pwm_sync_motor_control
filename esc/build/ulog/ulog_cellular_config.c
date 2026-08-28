/**
 * @file    ulog_cellular_config.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_cellular_config.h"
#include "ulog_def.h"

const char ulog_cellular_config_format[] = "cellular_config:uint64_t timestamp;uint8_t enable_lte;uint8_t enable_pin;char[16] pin;char[16] new_pin;char[32] apn;char[16] puk;uint8_t roaming;uint8_t response;";
const char ulog_cellular_config_name[] = "cellular_config";

int32_t ulog_format_cellular_config(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_cellular_config_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_cellular_config_format, sizeof(ulog_cellular_config_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_cellular_config(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_cellular_config_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_cellular_config_name, sizeof(ulog_cellular_config_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_cellular_config(ulog_t *log, ulog_msg_id_t id, const ulog_cellular_config_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(char)*16
                    + sizeof(char)*16
                    + sizeof(char)*32
                    + sizeof(char)*16
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
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

    /* Enable/disable LTE. 0: setting unchanged, 1: disabled, 2: enabled. Current setting when sent back as a response. */
    if (lfs_file_write(log->lfs, log->file, &src->enable_lte, sizeof(src->enable_lte)) < 0) {
        return 1;
    }

    /* Enable/disable PIN on the SIM card. 0: setting unchanged, 1: disabled, 2: enabled. Current setting when sent back as a response. */
    if (lfs_file_write(log->lfs, log->file, &src->enable_pin, sizeof(src->enable_pin)) < 0) {
        return 1;
    }

    /* PIN sent to the SIM card. Blank when PIN is disabled. Empty when message is sent back as a response. */
    if (lfs_file_write(log->lfs, log->file, src->pin, sizeof(src->pin)) < 0) {
        return 1;
    }

    /* New PIN when changing the PIN. Blank to leave it unchanged. Empty when message is sent back as a response. */
    if (lfs_file_write(log->lfs, log->file, src->new_pin, sizeof(src->new_pin)) < 0) {
        return 1;
    }

    /* Name of the cellular APN. Blank to leave it unchanged. Current APN when sent back as a response. */
    if (lfs_file_write(log->lfs, log->file, src->apn, sizeof(src->apn)) < 0) {
        return 1;
    }

    /* Required PUK code in case the user failed to authenticate 3 times with the PIN. Empty when message is sent back as a response. */
    if (lfs_file_write(log->lfs, log->file, src->puk, sizeof(src->puk)) < 0) {
        return 1;
    }

    /* Enable/disable roaming. 0: setting unchanged, 1: disabled, 2: enabled. Current setting when sent back as a response. */
    if (lfs_file_write(log->lfs, log->file, &src->roaming, sizeof(src->roaming)) < 0) {
        return 1;
    }

    /* Message acceptance response (sent back to GS). */
    if (lfs_file_write(log->lfs, log->file, &src->response, sizeof(src->response)) < 0) {
        return 1;
    }

    
    return 0;
}
