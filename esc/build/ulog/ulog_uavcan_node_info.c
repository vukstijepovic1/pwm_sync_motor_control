/**
 * @file    ulog_uavcan_node_info.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_uavcan_node_info.h"
#include "ulog_def.h"

const char ulog_uavcan_node_info_format[] = "uavcan_node_info:uint64_t timestamp;uint64_t time_usec;uint32_t uptime_sec;char[80] name;uint8_t hw_version_major;uint8_t hw_version_minor;uint8_t[16] hw_unique_id;uint8_t sw_version_major;uint8_t sw_version_minor;uint32_t sw_vcs_commit;";
const char ulog_uavcan_node_info_name[] = "uavcan_node_info";

int32_t ulog_format_uavcan_node_info(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_uavcan_node_info_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_uavcan_node_info_format, sizeof(ulog_uavcan_node_info_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_uavcan_node_info(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_uavcan_node_info_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_uavcan_node_info_name, sizeof(ulog_uavcan_node_info_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_uavcan_node_info(ulog_t *log, ulog_msg_id_t id, const ulog_uavcan_node_info_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
                    + sizeof(char)*80
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)*16
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint32_t)
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

    /* Node name string. For example, "sapog.px4.io". */
    if (lfs_file_write(log->lfs, log->file, src->name, sizeof(src->name)) < 0) {
        return 1;
    }

    /* Hardware major version number. */
    if (lfs_file_write(log->lfs, log->file, &src->hw_version_major, sizeof(src->hw_version_major)) < 0) {
        return 1;
    }

    /* Hardware minor version number. */
    if (lfs_file_write(log->lfs, log->file, &src->hw_version_minor, sizeof(src->hw_version_minor)) < 0) {
        return 1;
    }

    /* Hardware unique 128-bit ID. */
    if (lfs_file_write(log->lfs, log->file, src->hw_unique_id, sizeof(src->hw_unique_id)) < 0) {
        return 1;
    }

    /* Software major version number. */
    if (lfs_file_write(log->lfs, log->file, &src->sw_version_major, sizeof(src->sw_version_major)) < 0) {
        return 1;
    }

    /* Software minor version number. */
    if (lfs_file_write(log->lfs, log->file, &src->sw_version_minor, sizeof(src->sw_version_minor)) < 0) {
        return 1;
    }

    /* Version control system (VCS) revision identifier (e.g. git short commit hash). 0 if unknown. */
    if (lfs_file_write(log->lfs, log->file, &src->sw_vcs_commit, sizeof(src->sw_vcs_commit)) < 0) {
        return 1;
    }

    
    return 0;
}
