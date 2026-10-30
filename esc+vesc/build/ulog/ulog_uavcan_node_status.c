/**
 * @file    ulog_uavcan_node_status.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_uavcan_node_status.h"
#include "ulog_def.h"

const char ulog_uavcan_node_status_format[] = "uavcan_node_status:uint64_t timestamp;uint64_t time_usec;uint32_t uptime_sec;uint8_t health;uint8_t mode;uint8_t sub_mode;uint16_t vendor_specific_status_code;";
const char ulog_uavcan_node_status_name[] = "uavcan_node_status";

int32_t ulog_format_uavcan_node_status(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_uavcan_node_status_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_uavcan_node_status_format, sizeof(ulog_uavcan_node_status_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_uavcan_node_status(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_uavcan_node_status_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_uavcan_node_status_name, sizeof(ulog_uavcan_node_status_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_uavcan_node_status(ulog_t *log, ulog_msg_id_t id, const ulog_uavcan_node_status_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
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

    /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->time_usec, sizeof(src->time_usec)) < 0) {
        return 1;
    }

    /* Time since the start-up of the node. [s] */
    if (lfs_file_write(log->lfs, log->file, &src->uptime_sec, sizeof(src->uptime_sec)) < 0) {
        return 1;
    }

    /* Generalized node health status. */
    if (lfs_file_write(log->lfs, log->file, &src->health, sizeof(src->health)) < 0) {
        return 1;
    }

    /* Generalized operating mode. */
    if (lfs_file_write(log->lfs, log->file, &src->mode, sizeof(src->mode)) < 0) {
        return 1;
    }

    /* Not used currently. */
    if (lfs_file_write(log->lfs, log->file, &src->sub_mode, sizeof(src->sub_mode)) < 0) {
        return 1;
    }

    /* Vendor-specific status information. */
    if (lfs_file_write(log->lfs, log->file, &src->vendor_specific_status_code, sizeof(src->vendor_specific_status_code)) < 0) {
        return 1;
    }

    
    return 0;
}
