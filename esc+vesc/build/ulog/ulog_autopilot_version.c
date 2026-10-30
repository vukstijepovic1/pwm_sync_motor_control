/**
 * @file    ulog_autopilot_version.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_autopilot_version.h"
#include "ulog_def.h"

const char ulog_autopilot_version_format[] = "autopilot_version:uint64_t timestamp;uint64_t capabilities;uint32_t flight_sw_version;uint32_t middleware_sw_version;uint32_t os_sw_version;uint32_t board_version;uint8_t[8] flight_custom_version;uint8_t[8] middleware_custom_version;uint8_t[8] os_custom_version;uint16_t vendor_id;uint16_t product_id;uint64_t uid;uint8_t[18] uid2;";
const char ulog_autopilot_version_name[] = "autopilot_version";

int32_t ulog_format_autopilot_version(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_autopilot_version_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_autopilot_version_format, sizeof(ulog_autopilot_version_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_autopilot_version(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_autopilot_version_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_autopilot_version_name, sizeof(ulog_autopilot_version_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_autopilot_version(ulog_t *log, ulog_msg_id_t id, const ulog_autopilot_version_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
                    + sizeof(uint32_t)
                    + sizeof(uint32_t)
                    + sizeof(uint32_t)
                    + sizeof(uint8_t)*8
                    + sizeof(uint8_t)*8
                    + sizeof(uint8_t)*8
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)*18
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

    /* Bitmap of capabilities */
    if (lfs_file_write(log->lfs, log->file, &src->capabilities, sizeof(src->capabilities)) < 0) {
        return 1;
    }

    /* Firmware version number */
    if (lfs_file_write(log->lfs, log->file, &src->flight_sw_version, sizeof(src->flight_sw_version)) < 0) {
        return 1;
    }

    /* Middleware version number */
    if (lfs_file_write(log->lfs, log->file, &src->middleware_sw_version, sizeof(src->middleware_sw_version)) < 0) {
        return 1;
    }

    /* Operating system version number */
    if (lfs_file_write(log->lfs, log->file, &src->os_sw_version, sizeof(src->os_sw_version)) < 0) {
        return 1;
    }

    /* HW / board version (last 8 bits should be silicon ID, if any). The first 16 bits of this field specify https://github.com/PX4/PX4-Bootloader/blob/master/board_types.txt */
    if (lfs_file_write(log->lfs, log->file, &src->board_version, sizeof(src->board_version)) < 0) {
        return 1;
    }

    /* Custom version field, commonly the first 8 bytes of the git hash. This is not an unique identifier, but should allow to identify the commit using the main version number even for very large code bases. */
    if (lfs_file_write(log->lfs, log->file, src->flight_custom_version, sizeof(src->flight_custom_version)) < 0) {
        return 1;
    }

    /* Custom version field, commonly the first 8 bytes of the git hash. This is not an unique identifier, but should allow to identify the commit using the main version number even for very large code bases. */
    if (lfs_file_write(log->lfs, log->file, src->middleware_custom_version, sizeof(src->middleware_custom_version)) < 0) {
        return 1;
    }

    /* Custom version field, commonly the first 8 bytes of the git hash. This is not an unique identifier, but should allow to identify the commit using the main version number even for very large code bases. */
    if (lfs_file_write(log->lfs, log->file, src->os_custom_version, sizeof(src->os_custom_version)) < 0) {
        return 1;
    }

    /* ID of the board vendor */
    if (lfs_file_write(log->lfs, log->file, &src->vendor_id, sizeof(src->vendor_id)) < 0) {
        return 1;
    }

    /* ID of the product */
    if (lfs_file_write(log->lfs, log->file, &src->product_id, sizeof(src->product_id)) < 0) {
        return 1;
    }

    /* UID if provided by hardware (see uid2) */
    if (lfs_file_write(log->lfs, log->file, &src->uid, sizeof(src->uid)) < 0) {
        return 1;
    }

    /* UID if provided by hardware (supersedes the uid field. If this is non-zero, use this field, otherwise use uid) */
    if (lfs_file_write(log->lfs, log->file, src->uid2, sizeof(src->uid2)) < 0) {
        return 1;
    }

    
    return 0;
}
