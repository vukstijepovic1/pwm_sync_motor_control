/**
 * @file    ulog_mission_ack.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_mission_ack.h"
#include "ulog_def.h"

const char ulog_mission_ack_format[] = "mission_ack:uint64_t timestamp;uint8_t target_system;uint8_t target_component;uint8_t type;uint8_t mission_type;uint32_t opaque_id;";
const char ulog_mission_ack_name[] = "mission_ack";

int32_t ulog_format_mission_ack(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_mission_ack_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_mission_ack_format, sizeof(ulog_mission_ack_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_mission_ack(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_mission_ack_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_mission_ack_name, sizeof(ulog_mission_ack_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_mission_ack(ulog_t *log, ulog_msg_id_t id, const ulog_mission_ack_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
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

    /* System ID */
    if (lfs_file_write(log->lfs, log->file, &src->target_system, sizeof(src->target_system)) < 0) {
        return 1;
    }

    /* Component ID */
    if (lfs_file_write(log->lfs, log->file, &src->target_component, sizeof(src->target_component)) < 0) {
        return 1;
    }

    /* Mission result. */
    if (lfs_file_write(log->lfs, log->file, &src->type, sizeof(src->type)) < 0) {
        return 1;
    }

    /* Mission type. */
    if (lfs_file_write(log->lfs, log->file, &src->mission_type, sizeof(src->mission_type)) < 0) {
        return 1;
    }

    /* Id of new on-vehicle mission, fence, or rally point plan (on upload to vehicle).
        The id is calculated and returned by a vehicle when a new plan is uploaded by a GCS.
        The only requirement on the id is that it must change when there is any change to the on-vehicle plan type (there is no requirement that the id be globally unique).
        0 on download from the vehicle to the GCS (on download the ID is set in MISSION_COUNT).
        0 if plan ids are not supported.
        The current on-vehicle plan ids are streamed in `MISSION_CURRENT`, allowing a GCS to determine if any part of the plan has changed and needs to be re-uploaded.
       */
    if (lfs_file_write(log->lfs, log->file, &src->opaque_id, sizeof(src->opaque_id)) < 0) {
        return 1;
    }

    
    return 0;
}
