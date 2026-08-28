/**
 * @file    ulog_rc_channels_scaled.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_rc_channels_scaled.h"
#include "ulog_def.h"

const char ulog_rc_channels_scaled_format[] = "rc_channels_scaled:uint64_t timestamp;uint32_t time_boot_ms;uint8_t port;int16_t chan1_scaled;int16_t chan2_scaled;int16_t chan3_scaled;int16_t chan4_scaled;int16_t chan5_scaled;int16_t chan6_scaled;int16_t chan7_scaled;int16_t chan8_scaled;uint8_t rssi;";
const char ulog_rc_channels_scaled_name[] = "rc_channels_scaled";

int32_t ulog_format_rc_channels_scaled(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_rc_channels_scaled_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_rc_channels_scaled_format, sizeof(ulog_rc_channels_scaled_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_rc_channels_scaled(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_rc_channels_scaled_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_rc_channels_scaled_name, sizeof(ulog_rc_channels_scaled_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_rc_channels_scaled(ulog_t *log, ulog_msg_id_t id, const ulog_rc_channels_scaled_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
                    + sizeof(uint8_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
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

    /* Servo output port (set of 8 outputs = 1 port). Flight stacks running on Pixhawk should use: 0 = MAIN, 1 = AUX. */
    if (lfs_file_write(log->lfs, log->file, &src->port, sizeof(src->port)) < 0) {
        return 1;
    }

    /* RC channel 1 value scaled. */
    if (lfs_file_write(log->lfs, log->file, &src->chan1_scaled, sizeof(src->chan1_scaled)) < 0) {
        return 1;
    }

    /* RC channel 2 value scaled. */
    if (lfs_file_write(log->lfs, log->file, &src->chan2_scaled, sizeof(src->chan2_scaled)) < 0) {
        return 1;
    }

    /* RC channel 3 value scaled. */
    if (lfs_file_write(log->lfs, log->file, &src->chan3_scaled, sizeof(src->chan3_scaled)) < 0) {
        return 1;
    }

    /* RC channel 4 value scaled. */
    if (lfs_file_write(log->lfs, log->file, &src->chan4_scaled, sizeof(src->chan4_scaled)) < 0) {
        return 1;
    }

    /* RC channel 5 value scaled. */
    if (lfs_file_write(log->lfs, log->file, &src->chan5_scaled, sizeof(src->chan5_scaled)) < 0) {
        return 1;
    }

    /* RC channel 6 value scaled. */
    if (lfs_file_write(log->lfs, log->file, &src->chan6_scaled, sizeof(src->chan6_scaled)) < 0) {
        return 1;
    }

    /* RC channel 7 value scaled. */
    if (lfs_file_write(log->lfs, log->file, &src->chan7_scaled, sizeof(src->chan7_scaled)) < 0) {
        return 1;
    }

    /* RC channel 8 value scaled. */
    if (lfs_file_write(log->lfs, log->file, &src->chan8_scaled, sizeof(src->chan8_scaled)) < 0) {
        return 1;
    }

    /* Receive signal strength indicator in device-dependent units/scale. Values: [0-254], UINT8_MAX: invalid/unknown. */
    if (lfs_file_write(log->lfs, log->file, &src->rssi, sizeof(src->rssi)) < 0) {
        return 1;
    }

    
    return 0;
}
