/**
 * @file    ulog_rc_channels.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_rc_channels.h"
#include "ulog_def.h"

const char ulog_rc_channels_format[] = "rc_channels:uint64_t timestamp;uint32_t time_boot_ms;uint8_t chancount;uint16_t chan1_raw;uint16_t chan2_raw;uint16_t chan3_raw;uint16_t chan4_raw;uint16_t chan5_raw;uint16_t chan6_raw;uint16_t chan7_raw;uint16_t chan8_raw;uint16_t chan9_raw;uint16_t chan10_raw;uint16_t chan11_raw;uint16_t chan12_raw;uint16_t chan13_raw;uint16_t chan14_raw;uint16_t chan15_raw;uint16_t chan16_raw;uint16_t chan17_raw;uint16_t chan18_raw;uint8_t rssi;";
const char ulog_rc_channels_name[] = "rc_channels";

int32_t ulog_format_rc_channels(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_rc_channels_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_rc_channels_format, sizeof(ulog_rc_channels_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_rc_channels(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_rc_channels_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_rc_channels_name, sizeof(ulog_rc_channels_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_rc_channels(ulog_t *log, ulog_msg_id_t id, const ulog_rc_channels_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
                    + sizeof(uint8_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
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

    /* Timestamp (time since system boot). [ms] */
    if (lfs_file_write(log->lfs, log->file, &src->time_boot_ms, sizeof(src->time_boot_ms)) < 0) {
        return 1;
    }

    /* Total number of RC channels being received. This can be larger than 18, indicating that more channels are available but not given in this message. This value should be 0 when no RC channels are available. */
    if (lfs_file_write(log->lfs, log->file, &src->chancount, sizeof(src->chancount)) < 0) {
        return 1;
    }

    /* RC channel 1 value. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->chan1_raw, sizeof(src->chan1_raw)) < 0) {
        return 1;
    }

    /* RC channel 2 value. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->chan2_raw, sizeof(src->chan2_raw)) < 0) {
        return 1;
    }

    /* RC channel 3 value. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->chan3_raw, sizeof(src->chan3_raw)) < 0) {
        return 1;
    }

    /* RC channel 4 value. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->chan4_raw, sizeof(src->chan4_raw)) < 0) {
        return 1;
    }

    /* RC channel 5 value. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->chan5_raw, sizeof(src->chan5_raw)) < 0) {
        return 1;
    }

    /* RC channel 6 value. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->chan6_raw, sizeof(src->chan6_raw)) < 0) {
        return 1;
    }

    /* RC channel 7 value. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->chan7_raw, sizeof(src->chan7_raw)) < 0) {
        return 1;
    }

    /* RC channel 8 value. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->chan8_raw, sizeof(src->chan8_raw)) < 0) {
        return 1;
    }

    /* RC channel 9 value. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->chan9_raw, sizeof(src->chan9_raw)) < 0) {
        return 1;
    }

    /* RC channel 10 value. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->chan10_raw, sizeof(src->chan10_raw)) < 0) {
        return 1;
    }

    /* RC channel 11 value. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->chan11_raw, sizeof(src->chan11_raw)) < 0) {
        return 1;
    }

    /* RC channel 12 value. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->chan12_raw, sizeof(src->chan12_raw)) < 0) {
        return 1;
    }

    /* RC channel 13 value. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->chan13_raw, sizeof(src->chan13_raw)) < 0) {
        return 1;
    }

    /* RC channel 14 value. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->chan14_raw, sizeof(src->chan14_raw)) < 0) {
        return 1;
    }

    /* RC channel 15 value. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->chan15_raw, sizeof(src->chan15_raw)) < 0) {
        return 1;
    }

    /* RC channel 16 value. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->chan16_raw, sizeof(src->chan16_raw)) < 0) {
        return 1;
    }

    /* RC channel 17 value. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->chan17_raw, sizeof(src->chan17_raw)) < 0) {
        return 1;
    }

    /* RC channel 18 value. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->chan18_raw, sizeof(src->chan18_raw)) < 0) {
        return 1;
    }

    /* Receive signal strength indicator in device-dependent units/scale. Values: [0-254], UINT8_MAX: invalid/unknown. */
    if (lfs_file_write(log->lfs, log->file, &src->rssi, sizeof(src->rssi)) < 0) {
        return 1;
    }

    
    return 0;
}
