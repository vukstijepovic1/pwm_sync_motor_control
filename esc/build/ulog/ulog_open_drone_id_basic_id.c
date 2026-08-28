/**
 * @file    ulog_open_drone_id_basic_id.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_open_drone_id_basic_id.h"
#include "ulog_def.h"

const char ulog_open_drone_id_basic_id_format[] = "open_drone_id_basic_id:uint64_t timestamp;uint8_t target_system;uint8_t target_component;uint8_t[20] id_or_mac;uint8_t id_type;uint8_t ua_type;uint8_t[20] uas_id;";
const char ulog_open_drone_id_basic_id_name[] = "open_drone_id_basic_id";

int32_t ulog_format_open_drone_id_basic_id(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_open_drone_id_basic_id_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_open_drone_id_basic_id_format, sizeof(ulog_open_drone_id_basic_id_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_open_drone_id_basic_id(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_open_drone_id_basic_id_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_open_drone_id_basic_id_name, sizeof(ulog_open_drone_id_basic_id_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_open_drone_id_basic_id(ulog_t *log, ulog_msg_id_t id, const ulog_open_drone_id_basic_id_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)*20
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)*20
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

    /* System ID (0 for broadcast). */
    if (lfs_file_write(log->lfs, log->file, &src->target_system, sizeof(src->target_system)) < 0) {
        return 1;
    }

    /* Component ID (0 for broadcast). */
    if (lfs_file_write(log->lfs, log->file, &src->target_component, sizeof(src->target_component)) < 0) {
        return 1;
    }

    /* Only used for drone ID data received from other UAs. See detailed description at https://mavlink.io/en/services/opendroneid.html.  */
    if (lfs_file_write(log->lfs, log->file, src->id_or_mac, sizeof(src->id_or_mac)) < 0) {
        return 1;
    }

    /* Indicates the format for the uas_id field of this message. */
    if (lfs_file_write(log->lfs, log->file, &src->id_type, sizeof(src->id_type)) < 0) {
        return 1;
    }

    /* Indicates the type of UA (Unmanned Aircraft). */
    if (lfs_file_write(log->lfs, log->file, &src->ua_type, sizeof(src->ua_type)) < 0) {
        return 1;
    }

    /* UAS (Unmanned Aircraft System) ID following the format specified by id_type. Shall be filled with nulls in the unused portion of the field. */
    if (lfs_file_write(log->lfs, log->file, src->uas_id, sizeof(src->uas_id)) < 0) {
        return 1;
    }

    
    return 0;
}
