/**
 * @file    ulog_serial_control.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_serial_control.h"
#include "ulog_def.h"

const char ulog_serial_control_format[] = "serial_control:uint64_t timestamp;uint8_t device;uint8_t flags;uint16_t timeout;uint32_t baudrate;uint8_t count;uint8_t[70] data;uint8_t target_system;uint8_t target_component;";
const char ulog_serial_control_name[] = "serial_control";

int32_t ulog_format_serial_control(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_serial_control_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_serial_control_format, sizeof(ulog_serial_control_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_serial_control(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_serial_control_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_serial_control_name, sizeof(ulog_serial_control_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_serial_control(ulog_t *log, ulog_msg_id_t id, const ulog_serial_control_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint16_t)
                    + sizeof(uint32_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)*70
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

    /* Serial control device type. */
    if (lfs_file_write(log->lfs, log->file, &src->device, sizeof(src->device)) < 0) {
        return 1;
    }

    /* Bitmap of serial control flags. */
    if (lfs_file_write(log->lfs, log->file, &src->flags, sizeof(src->flags)) < 0) {
        return 1;
    }

    /* Timeout for reply data [ms] */
    if (lfs_file_write(log->lfs, log->file, &src->timeout, sizeof(src->timeout)) < 0) {
        return 1;
    }

    /* Baudrate of transfer. Zero means no change. [bits/s] */
    if (lfs_file_write(log->lfs, log->file, &src->baudrate, sizeof(src->baudrate)) < 0) {
        return 1;
    }

    /* how many bytes in this transfer [bytes] */
    if (lfs_file_write(log->lfs, log->file, &src->count, sizeof(src->count)) < 0) {
        return 1;
    }

    /* serial data */
    if (lfs_file_write(log->lfs, log->file, src->data, sizeof(src->data)) < 0) {
        return 1;
    }

    /* System ID */
    if (lfs_file_write(log->lfs, log->file, &src->target_system, sizeof(src->target_system)) < 0) {
        return 1;
    }

    /* Component ID */
    if (lfs_file_write(log->lfs, log->file, &src->target_component, sizeof(src->target_component)) < 0) {
        return 1;
    }

    
    return 0;
}
