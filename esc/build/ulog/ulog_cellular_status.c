/**
 * @file    ulog_cellular_status.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_cellular_status.h"
#include "ulog_def.h"

const char ulog_cellular_status_format[] = "cellular_status:uint64_t timestamp;uint8_t status;uint8_t failure_reason;uint8_t type;uint8_t quality;uint16_t mcc;uint16_t mnc;uint16_t lac;";
const char ulog_cellular_status_name[] = "cellular_status";

int32_t ulog_format_cellular_status(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_cellular_status_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_cellular_status_format, sizeof(ulog_cellular_status_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_cellular_status(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_cellular_status_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_cellular_status_name, sizeof(ulog_cellular_status_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_cellular_status(ulog_t *log, ulog_msg_id_t id, const ulog_cellular_status_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
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

    /* Cellular modem status */
    if (lfs_file_write(log->lfs, log->file, &src->status, sizeof(src->status)) < 0) {
        return 1;
    }

    /* Failure reason when status in in CELLULAR_STATUS_FLAG_FAILED */
    if (lfs_file_write(log->lfs, log->file, &src->failure_reason, sizeof(src->failure_reason)) < 0) {
        return 1;
    }

    /* Cellular network radio type: gsm, cdma, lte... */
    if (lfs_file_write(log->lfs, log->file, &src->type, sizeof(src->type)) < 0) {
        return 1;
    }

    /* Signal quality in percent. If unknown, set to UINT8_MAX */
    if (lfs_file_write(log->lfs, log->file, &src->quality, sizeof(src->quality)) < 0) {
        return 1;
    }

    /* Mobile country code. If unknown, set to UINT16_MAX */
    if (lfs_file_write(log->lfs, log->file, &src->mcc, sizeof(src->mcc)) < 0) {
        return 1;
    }

    /* Mobile network code. If unknown, set to UINT16_MAX */
    if (lfs_file_write(log->lfs, log->file, &src->mnc, sizeof(src->mnc)) < 0) {
        return 1;
    }

    /* Location area code. If unknown, set to 0 */
    if (lfs_file_write(log->lfs, log->file, &src->lac, sizeof(src->lac)) < 0) {
        return 1;
    }

    
    return 0;
}
