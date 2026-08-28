/**
 * @file    ulog_component_information_basic.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_component_information_basic.h"
#include "ulog_def.h"

const char ulog_component_information_basic_format[] = "component_information_basic:uint64_t timestamp;uint32_t time_boot_ms;uint64_t capabilities;uint32_t time_manufacture_s;char[32] vendor_name;char[32] model_name;char[24] software_version;char[24] hardware_version;char[32] serial_number;";
const char ulog_component_information_basic_name[] = "component_information_basic";

int32_t ulog_format_component_information_basic(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_component_information_basic_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_component_information_basic_format, sizeof(ulog_component_information_basic_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_component_information_basic(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_component_information_basic_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_component_information_basic_name, sizeof(ulog_component_information_basic_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_component_information_basic(ulog_t *log, ulog_msg_id_t id, const ulog_component_information_basic_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
                    + sizeof(char)*32
                    + sizeof(char)*32
                    + sizeof(char)*24
                    + sizeof(char)*24
                    + sizeof(char)*32
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

    /* Component capability flags */
    if (lfs_file_write(log->lfs, log->file, &src->capabilities, sizeof(src->capabilities)) < 0) {
        return 1;
    }

    /* Date of manufacture as a UNIX Epoch time (since 1.1.1970) in seconds. [s] */
    if (lfs_file_write(log->lfs, log->file, &src->time_manufacture_s, sizeof(src->time_manufacture_s)) < 0) {
        return 1;
    }

    /* Name of the component vendor. Needs to be zero terminated. The field is optional and can be empty/all zeros. */
    if (lfs_file_write(log->lfs, log->file, src->vendor_name, sizeof(src->vendor_name)) < 0) {
        return 1;
    }

    /* Name of the component model. Needs to be zero terminated. The field is optional and can be empty/all zeros. */
    if (lfs_file_write(log->lfs, log->file, src->model_name, sizeof(src->model_name)) < 0) {
        return 1;
    }

    /* Software version. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros. */
    if (lfs_file_write(log->lfs, log->file, src->software_version, sizeof(src->software_version)) < 0) {
        return 1;
    }

    /* Hardware version. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros. */
    if (lfs_file_write(log->lfs, log->file, src->hardware_version, sizeof(src->hardware_version)) < 0) {
        return 1;
    }

    /* Hardware serial number. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros. */
    if (lfs_file_write(log->lfs, log->file, src->serial_number, sizeof(src->serial_number)) < 0) {
        return 1;
    }

    
    return 0;
}
