/**
 * @file    ulog_hil_rc_inputs_raw.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_hil_rc_inputs_raw.h"
#include "ulog_def.h"

const char ulog_hil_rc_inputs_raw_format[] = "hil_rc_inputs_raw:uint64_t timestamp;uint64_t time_usec;uint16_t chan1_raw;uint16_t chan2_raw;uint16_t chan3_raw;uint16_t chan4_raw;uint16_t chan5_raw;uint16_t chan6_raw;uint16_t chan7_raw;uint16_t chan8_raw;uint16_t chan9_raw;uint16_t chan10_raw;uint16_t chan11_raw;uint16_t chan12_raw;uint8_t rssi;";
const char ulog_hil_rc_inputs_raw_name[] = "hil_rc_inputs_raw";

int32_t ulog_format_hil_rc_inputs_raw(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_hil_rc_inputs_raw_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_hil_rc_inputs_raw_format, sizeof(ulog_hil_rc_inputs_raw_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_hil_rc_inputs_raw(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_hil_rc_inputs_raw_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_hil_rc_inputs_raw_name, sizeof(ulog_hil_rc_inputs_raw_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_hil_rc_inputs_raw(ulog_t *log, ulog_msg_id_t id, const ulog_hil_rc_inputs_raw_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint64_t)
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

    /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->time_usec, sizeof(src->time_usec)) < 0) {
        return 1;
    }

    /* RC channel 1 value [us] */
    if (lfs_file_write(log->lfs, log->file, &src->chan1_raw, sizeof(src->chan1_raw)) < 0) {
        return 1;
    }

    /* RC channel 2 value [us] */
    if (lfs_file_write(log->lfs, log->file, &src->chan2_raw, sizeof(src->chan2_raw)) < 0) {
        return 1;
    }

    /* RC channel 3 value [us] */
    if (lfs_file_write(log->lfs, log->file, &src->chan3_raw, sizeof(src->chan3_raw)) < 0) {
        return 1;
    }

    /* RC channel 4 value [us] */
    if (lfs_file_write(log->lfs, log->file, &src->chan4_raw, sizeof(src->chan4_raw)) < 0) {
        return 1;
    }

    /* RC channel 5 value [us] */
    if (lfs_file_write(log->lfs, log->file, &src->chan5_raw, sizeof(src->chan5_raw)) < 0) {
        return 1;
    }

    /* RC channel 6 value [us] */
    if (lfs_file_write(log->lfs, log->file, &src->chan6_raw, sizeof(src->chan6_raw)) < 0) {
        return 1;
    }

    /* RC channel 7 value [us] */
    if (lfs_file_write(log->lfs, log->file, &src->chan7_raw, sizeof(src->chan7_raw)) < 0) {
        return 1;
    }

    /* RC channel 8 value [us] */
    if (lfs_file_write(log->lfs, log->file, &src->chan8_raw, sizeof(src->chan8_raw)) < 0) {
        return 1;
    }

    /* RC channel 9 value [us] */
    if (lfs_file_write(log->lfs, log->file, &src->chan9_raw, sizeof(src->chan9_raw)) < 0) {
        return 1;
    }

    /* RC channel 10 value [us] */
    if (lfs_file_write(log->lfs, log->file, &src->chan10_raw, sizeof(src->chan10_raw)) < 0) {
        return 1;
    }

    /* RC channel 11 value [us] */
    if (lfs_file_write(log->lfs, log->file, &src->chan11_raw, sizeof(src->chan11_raw)) < 0) {
        return 1;
    }

    /* RC channel 12 value [us] */
    if (lfs_file_write(log->lfs, log->file, &src->chan12_raw, sizeof(src->chan12_raw)) < 0) {
        return 1;
    }

    /* Receive signal strength indicator in device-dependent units/scale. Values: [0-254], UINT8_MAX: invalid/unknown. */
    if (lfs_file_write(log->lfs, log->file, &src->rssi, sizeof(src->rssi)) < 0) {
        return 1;
    }

    
    return 0;
}
