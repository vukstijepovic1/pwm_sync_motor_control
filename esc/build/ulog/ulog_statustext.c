/**
 * @file    ulog_statustext.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_statustext.h"
#include "ulog_def.h"

const char ulog_statustext_format[] = "statustext:uint64_t timestamp;uint8_t severity;char[50] text;uint16_t id;uint8_t chunk_seq;";
const char ulog_statustext_name[] = "statustext";

int32_t ulog_format_statustext(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_statustext_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_statustext_format, sizeof(ulog_statustext_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_statustext(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_statustext_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_statustext_name, sizeof(ulog_statustext_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_statustext(ulog_t *log, ulog_msg_id_t id, const ulog_statustext_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(char)*50
                    + sizeof(uint16_t)
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

    /* Severity of status. Relies on the definitions within RFC-5424. */
    if (lfs_file_write(log->lfs, log->file, &src->severity, sizeof(src->severity)) < 0) {
        return 1;
    }

    /* Status text message, without null termination character */
    if (lfs_file_write(log->lfs, log->file, src->text, sizeof(src->text)) < 0) {
        return 1;
    }

    /* Unique (opaque) identifier for this statustext message.  May be used to reassemble a logical long-statustext message from a sequence of chunks.  A value of zero indicates this is the only chunk in the sequence and the message can be emitted immediately. */
    if (lfs_file_write(log->lfs, log->file, &src->id, sizeof(src->id)) < 0) {
        return 1;
    }

    /* This chunk's sequence number; indexing is from zero.  Any null character in the text field is taken to mean this was the last chunk. */
    if (lfs_file_write(log->lfs, log->file, &src->chunk_seq, sizeof(src->chunk_seq)) < 0) {
        return 1;
    }

    
    return 0;
}
