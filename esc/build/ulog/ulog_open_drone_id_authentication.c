/**
 * @file    ulog_open_drone_id_authentication.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_open_drone_id_authentication.h"
#include "ulog_def.h"

const char ulog_open_drone_id_authentication_format[] = "open_drone_id_authentication:uint64_t timestamp;uint8_t target_system;uint8_t target_component;uint8_t[20] id_or_mac;uint8_t authentication_type;uint8_t data_page;uint8_t last_page_index;uint8_t length;uint8_t[23] authentication_data;";
const char ulog_open_drone_id_authentication_name[] = "open_drone_id_authentication";

int32_t ulog_format_open_drone_id_authentication(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_open_drone_id_authentication_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_open_drone_id_authentication_format, sizeof(ulog_open_drone_id_authentication_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_open_drone_id_authentication(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_open_drone_id_authentication_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_open_drone_id_authentication_name, sizeof(ulog_open_drone_id_authentication_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_open_drone_id_authentication(ulog_t *log, ulog_msg_id_t id, const ulog_open_drone_id_authentication_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)*20
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)*23
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

    /* Indicates the type of authentication. */
    if (lfs_file_write(log->lfs, log->file, &src->authentication_type, sizeof(src->authentication_type)) < 0) {
        return 1;
    }

    /* Allowed range is 0 - 15. */
    if (lfs_file_write(log->lfs, log->file, &src->data_page, sizeof(src->data_page)) < 0) {
        return 1;
    }

    /* This field is only present for page 0. Allowed range is 0 - 15. See the description of struct ODID_Auth_data at https://github.com/opendroneid/opendroneid-core-c/blob/master/libopendroneid/opendroneid.h. */
    if (lfs_file_write(log->lfs, log->file, &src->last_page_index, sizeof(src->last_page_index)) < 0) {
        return 1;
    }

    /* This field is only present for page 0. Total bytes of authentication_data from all data pages. See the description of struct ODID_Auth_data at https://github.com/opendroneid/opendroneid-core-c/blob/master/libopendroneid/opendroneid.h. [bytes] */
    if (lfs_file_write(log->lfs, log->file, &src->length, sizeof(src->length)) < 0) {
        return 1;
    }

    /* Opaque authentication data. For page 0, the size is only 17 bytes. For other pages, the size is 23 bytes. Shall be filled with nulls in the unused portion of the field. */
    if (lfs_file_write(log->lfs, log->file, src->authentication_data, sizeof(src->authentication_data)) < 0) {
        return 1;
    }

    
    return 0;
}
