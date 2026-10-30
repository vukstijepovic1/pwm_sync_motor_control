/**
 * @file    ulog_radio_status.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_radio_status.h"
#include "ulog_def.h"

const char ulog_radio_status_format[] = "radio_status:uint64_t timestamp;uint8_t rssi;uint8_t remrssi;uint8_t txbuf;uint8_t noise;uint8_t remnoise;uint16_t rxerrors;uint16_t fixed;";
const char ulog_radio_status_name[] = "radio_status";

int32_t ulog_format_radio_status(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_radio_status_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_radio_status_format, sizeof(ulog_radio_status_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_radio_status(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_radio_status_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_radio_status_name, sizeof(ulog_radio_status_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_radio_status(ulog_t *log, ulog_msg_id_t id, const ulog_radio_status_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
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

    /* Local (message sender) received signal strength indication in device-dependent units/scale. Values: [0-254], UINT8_MAX: invalid/unknown. */
    if (lfs_file_write(log->lfs, log->file, &src->rssi, sizeof(src->rssi)) < 0) {
        return 1;
    }

    /* Remote (message receiver) signal strength indication in device-dependent units/scale. Values: [0-254], UINT8_MAX: invalid/unknown. */
    if (lfs_file_write(log->lfs, log->file, &src->remrssi, sizeof(src->remrssi)) < 0) {
        return 1;
    }

    /* Remaining free transmitter buffer space. [%] */
    if (lfs_file_write(log->lfs, log->file, &src->txbuf, sizeof(src->txbuf)) < 0) {
        return 1;
    }

    /* Local background noise level. These are device dependent RSSI values (scale as approx 2x dB on SiK radios). Values: [0-254], UINT8_MAX: invalid/unknown. */
    if (lfs_file_write(log->lfs, log->file, &src->noise, sizeof(src->noise)) < 0) {
        return 1;
    }

    /* Remote background noise level. These are device dependent RSSI values (scale as approx 2x dB on SiK radios). Values: [0-254], UINT8_MAX: invalid/unknown. */
    if (lfs_file_write(log->lfs, log->file, &src->remnoise, sizeof(src->remnoise)) < 0) {
        return 1;
    }

    /* Count of radio packet receive errors (since boot). */
    if (lfs_file_write(log->lfs, log->file, &src->rxerrors, sizeof(src->rxerrors)) < 0) {
        return 1;
    }

    /* Count of error corrected radio packets (since boot). */
    if (lfs_file_write(log->lfs, log->file, &src->fixed, sizeof(src->fixed)) < 0) {
        return 1;
    }

    
    return 0;
}
