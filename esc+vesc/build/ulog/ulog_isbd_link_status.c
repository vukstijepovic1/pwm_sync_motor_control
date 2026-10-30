/**
 * @file    ulog_isbd_link_status.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_isbd_link_status.h"
#include "ulog_def.h"

const char ulog_isbd_link_status_format[] = "isbd_link_status:uint64_t timestamp;uint64_t last_heartbeat;uint16_t failed_sessions;uint16_t successful_sessions;uint8_t signal_quality;uint8_t ring_pending;uint8_t tx_session_pending;uint8_t rx_session_pending;";
const char ulog_isbd_link_status_name[] = "isbd_link_status";

int32_t ulog_format_isbd_link_status(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_isbd_link_status_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_isbd_link_status_format, sizeof(ulog_isbd_link_status_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_isbd_link_status(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_isbd_link_status_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_isbd_link_status_name, sizeof(ulog_isbd_link_status_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_isbd_link_status(ulog_t *log, ulog_msg_id_t id, const ulog_isbd_link_status_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint64_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
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

    /* Timestamp of the last successful sbd session. The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->last_heartbeat, sizeof(src->last_heartbeat)) < 0) {
        return 1;
    }

    /* Number of failed SBD sessions. */
    if (lfs_file_write(log->lfs, log->file, &src->failed_sessions, sizeof(src->failed_sessions)) < 0) {
        return 1;
    }

    /* Number of successful SBD sessions. */
    if (lfs_file_write(log->lfs, log->file, &src->successful_sessions, sizeof(src->successful_sessions)) < 0) {
        return 1;
    }

    /* Signal quality equal to the number of bars displayed on the ISU signal strength indicator. Range is 0 to 5, where 0 indicates no signal and 5 indicates maximum signal strength. */
    if (lfs_file_write(log->lfs, log->file, &src->signal_quality, sizeof(src->signal_quality)) < 0) {
        return 1;
    }

    /* 1: Ring call pending, 0: No call pending. */
    if (lfs_file_write(log->lfs, log->file, &src->ring_pending, sizeof(src->ring_pending)) < 0) {
        return 1;
    }

    /* 1: Transmission session pending, 0: No transmission session pending. */
    if (lfs_file_write(log->lfs, log->file, &src->tx_session_pending, sizeof(src->tx_session_pending)) < 0) {
        return 1;
    }

    /* 1: Receiving session pending, 0: No receiving session pending. */
    if (lfs_file_write(log->lfs, log->file, &src->rx_session_pending, sizeof(src->rx_session_pending)) < 0) {
        return 1;
    }

    
    return 0;
}
