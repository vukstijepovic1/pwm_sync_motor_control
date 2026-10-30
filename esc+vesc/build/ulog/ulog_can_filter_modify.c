/**
 * @file    ulog_can_filter_modify.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_can_filter_modify.h"
#include "ulog_def.h"

const char ulog_can_filter_modify_format[] = "can_filter_modify:uint64_t timestamp;uint8_t target_system;uint8_t target_component;uint8_t bus;uint8_t operation;uint8_t num_ids;uint16_t[16] ids;";
const char ulog_can_filter_modify_name[] = "can_filter_modify";

int32_t ulog_format_can_filter_modify(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_can_filter_modify_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_can_filter_modify_format, sizeof(ulog_can_filter_modify_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_can_filter_modify(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_can_filter_modify_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_can_filter_modify_name, sizeof(ulog_can_filter_modify_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_can_filter_modify(ulog_t *log, ulog_msg_id_t id, const ulog_can_filter_modify_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint16_t)*16
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

    /* System ID. */
    if (lfs_file_write(log->lfs, log->file, &src->target_system, sizeof(src->target_system)) < 0) {
        return 1;
    }

    /* Component ID. */
    if (lfs_file_write(log->lfs, log->file, &src->target_component, sizeof(src->target_component)) < 0) {
        return 1;
    }

    /* bus number */
    if (lfs_file_write(log->lfs, log->file, &src->bus, sizeof(src->bus)) < 0) {
        return 1;
    }

    /* what operation to perform on the filter list. See CAN_FILTER_OP enum. */
    if (lfs_file_write(log->lfs, log->file, &src->operation, sizeof(src->operation)) < 0) {
        return 1;
    }

    /* number of IDs in filter list */
    if (lfs_file_write(log->lfs, log->file, &src->num_ids, sizeof(src->num_ids)) < 0) {
        return 1;
    }

    /* filter IDs, length num_ids */
    if (lfs_file_write(log->lfs, log->file, src->ids, sizeof(src->ids)) < 0) {
        return 1;
    }

    
    return 0;
}
