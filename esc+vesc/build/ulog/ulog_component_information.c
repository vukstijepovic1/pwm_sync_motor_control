/**
 * @file    ulog_component_information.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_component_information.h"
#include "ulog_def.h"

const char ulog_component_information_format[] = "component_information:uint64_t timestamp;uint32_t time_boot_ms;uint32_t general_metadata_file_crc;char[100] general_metadata_uri;uint32_t peripherals_metadata_file_crc;char[100] peripherals_metadata_uri;";
const char ulog_component_information_name[] = "component_information";

int32_t ulog_format_component_information(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_component_information_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_component_information_format, sizeof(ulog_component_information_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_component_information(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_component_information_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_component_information_name, sizeof(ulog_component_information_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_component_information(ulog_t *log, ulog_msg_id_t id, const ulog_component_information_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
                    + sizeof(uint32_t)
                    + sizeof(char)*100
                    + sizeof(uint32_t)
                    + sizeof(char)*100
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

    /* CRC32 of the general metadata file (general_metadata_uri). */
    if (lfs_file_write(log->lfs, log->file, &src->general_metadata_file_crc, sizeof(src->general_metadata_file_crc)) < 0) {
        return 1;
    }

    /* MAVLink FTP URI for the general metadata file (COMP_METADATA_TYPE_GENERAL), which may be compressed with xz. The file contains general component metadata, and may contain URI links for additional metadata (see COMP_METADATA_TYPE). The information is static from boot, and may be generated at compile time. The string needs to be zero terminated. */
    if (lfs_file_write(log->lfs, log->file, src->general_metadata_uri, sizeof(src->general_metadata_uri)) < 0) {
        return 1;
    }

    /* CRC32 of peripherals metadata file (peripherals_metadata_uri). */
    if (lfs_file_write(log->lfs, log->file, &src->peripherals_metadata_file_crc, sizeof(src->peripherals_metadata_file_crc)) < 0) {
        return 1;
    }

    /* (Optional) MAVLink FTP URI for the peripherals metadata file (COMP_METADATA_TYPE_PERIPHERALS), which may be compressed with xz. This contains data about "attached components" such as UAVCAN nodes. The peripherals are in a separate file because the information must be generated dynamically at runtime. The string needs to be zero terminated. */
    if (lfs_file_write(log->lfs, log->file, src->peripherals_metadata_uri, sizeof(src->peripherals_metadata_uri)) < 0) {
        return 1;
    }

    
    return 0;
}
