/**
 * @file    ulog_link_node_status.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_link_node_status.h"
#include "ulog_def.h"

const char ulog_link_node_status_format[] = "link_node_status:uint64_t timestamp;uint8_t tx_buf;uint8_t rx_buf;uint32_t tx_rate;uint32_t rx_rate;uint16_t rx_parse_err;uint16_t tx_overflows;uint16_t rx_overflows;uint32_t messages_sent;uint32_t messages_received;uint32_t messages_lost;";
const char ulog_link_node_status_name[] = "link_node_status";

int32_t ulog_format_link_node_status(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_link_node_status_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_link_node_status_format, sizeof(ulog_link_node_status_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_link_node_status(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_link_node_status_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_link_node_status_name, sizeof(ulog_link_node_status_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_link_node_status(ulog_t *log, ulog_msg_id_t id, const ulog_link_node_status_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint32_t)
                    + sizeof(uint32_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint32_t)
                    + sizeof(uint32_t)
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

    /* Remaining free transmit buffer space [%] */
    if (lfs_file_write(log->lfs, log->file, &src->tx_buf, sizeof(src->tx_buf)) < 0) {
        return 1;
    }

    /* Remaining free receive buffer space [%] */
    if (lfs_file_write(log->lfs, log->file, &src->rx_buf, sizeof(src->rx_buf)) < 0) {
        return 1;
    }

    /* Transmit rate [bytes/s] */
    if (lfs_file_write(log->lfs, log->file, &src->tx_rate, sizeof(src->tx_rate)) < 0) {
        return 1;
    }

    /* Receive rate [bytes/s] */
    if (lfs_file_write(log->lfs, log->file, &src->rx_rate, sizeof(src->rx_rate)) < 0) {
        return 1;
    }

    /* Number of bytes that could not be parsed correctly. [bytes] */
    if (lfs_file_write(log->lfs, log->file, &src->rx_parse_err, sizeof(src->rx_parse_err)) < 0) {
        return 1;
    }

    /* Transmit buffer overflows. This number wraps around as it reaches UINT16_MAX [bytes] */
    if (lfs_file_write(log->lfs, log->file, &src->tx_overflows, sizeof(src->tx_overflows)) < 0) {
        return 1;
    }

    /* Receive buffer overflows. This number wraps around as it reaches UINT16_MAX [bytes] */
    if (lfs_file_write(log->lfs, log->file, &src->rx_overflows, sizeof(src->rx_overflows)) < 0) {
        return 1;
    }

    /* Messages sent */
    if (lfs_file_write(log->lfs, log->file, &src->messages_sent, sizeof(src->messages_sent)) < 0) {
        return 1;
    }

    /* Messages received (estimated from counting seq) */
    if (lfs_file_write(log->lfs, log->file, &src->messages_received, sizeof(src->messages_received)) < 0) {
        return 1;
    }

    /* Messages lost (estimated from counting seq) */
    if (lfs_file_write(log->lfs, log->file, &src->messages_lost, sizeof(src->messages_lost)) < 0) {
        return 1;
    }

    
    return 0;
}
