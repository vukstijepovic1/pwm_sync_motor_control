/**
 * @file    ulog_event.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_event.h"
#include "ulog_def.h"

const char ulog_event_format[] = "event:uint64_t timestamp;uint8_t destination_component;uint8_t destination_system;uint32_t id;uint32_t event_time_boot_ms;uint16_t sequence;uint8_t log_levels;uint8_t[40] arguments;";
const char ulog_event_name[] = "event";

int32_t ulog_format_event(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_event_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_event_format, sizeof(ulog_event_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_event(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_event_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_event_name, sizeof(ulog_event_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_event(ulog_t *log, ulog_msg_id_t id, const ulog_event_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint32_t)
                    + sizeof(uint32_t)
                    + sizeof(uint16_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)*40
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

    /* Component ID */
    if (lfs_file_write(log->lfs, log->file, &src->destination_component, sizeof(src->destination_component)) < 0) {
        return 1;
    }

    /* System ID */
    if (lfs_file_write(log->lfs, log->file, &src->destination_system, sizeof(src->destination_system)) < 0) {
        return 1;
    }

    /* Event ID (as defined in the component metadata) */
    if (lfs_file_write(log->lfs, log->file, &src->id, sizeof(src->id)) < 0) {
        return 1;
    }

    /* Timestamp (time since system boot when the event happened). [ms] */
    if (lfs_file_write(log->lfs, log->file, &src->event_time_boot_ms, sizeof(src->event_time_boot_ms)) < 0) {
        return 1;
    }

    /* Sequence number. */
    if (lfs_file_write(log->lfs, log->file, &src->sequence, sizeof(src->sequence)) < 0) {
        return 1;
    }

    /* Log levels: 4 bits MSB: internal (for logging purposes), 4 bits LSB: external. Levels: Emergency = 0, Alert = 1, Critical = 2, Error = 3, Warning = 4, Notice = 5, Info = 6, Debug = 7, Protocol = 8, Disabled = 9 */
    if (lfs_file_write(log->lfs, log->file, &src->log_levels, sizeof(src->log_levels)) < 0) {
        return 1;
    }

    /* Arguments (depend on event ID). */
    if (lfs_file_write(log->lfs, log->file, src->arguments, sizeof(src->arguments)) < 0) {
        return 1;
    }

    
    return 0;
}
