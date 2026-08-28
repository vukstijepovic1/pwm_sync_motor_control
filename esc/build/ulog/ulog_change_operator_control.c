/**
 * @file    ulog_change_operator_control.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_change_operator_control.h"
#include "ulog_def.h"

const char ulog_change_operator_control_format[] = "change_operator_control:uint64_t timestamp;uint8_t target_system;uint8_t control_request;uint8_t version;char[25] passkey;";
const char ulog_change_operator_control_name[] = "change_operator_control";

int32_t ulog_format_change_operator_control(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_change_operator_control_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_change_operator_control_format, sizeof(ulog_change_operator_control_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_change_operator_control(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_change_operator_control_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_change_operator_control_name, sizeof(ulog_change_operator_control_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_change_operator_control(ulog_t *log, ulog_msg_id_t id, const ulog_change_operator_control_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(char)*25
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

    /* System the GCS requests control for */
    if (lfs_file_write(log->lfs, log->file, &src->target_system, sizeof(src->target_system)) < 0) {
        return 1;
    }

    /* 0: request control of this MAV, 1: Release control of this MAV */
    if (lfs_file_write(log->lfs, log->file, &src->control_request, sizeof(src->control_request)) < 0) {
        return 1;
    }

    /* 0: key as plaintext, 1-255: future, different hashing/encryption variants. The GCS should in general use the safest mode possible initially and then gradually move down the encryption level if it gets a NACK message indicating an encryption mismatch. [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->version, sizeof(src->version)) < 0) {
        return 1;
    }

    /* Password / Key, depending on version plaintext or encrypted. 25 or less characters, NULL terminated. The characters may involve A-Z, a-z, 0-9, and "!?,.-" */
    if (lfs_file_write(log->lfs, log->file, src->passkey, sizeof(src->passkey)) < 0) {
        return 1;
    }

    
    return 0;
}
