/**
 * @file    ulog_safety_set_allowed_area.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_safety_set_allowed_area.h"
#include "ulog_def.h"

const char ulog_safety_set_allowed_area_format[] = "safety_set_allowed_area:uint64_t timestamp;uint8_t target_system;uint8_t target_component;uint8_t frame;float p1x;float p1y;float p1z;float p2x;float p2y;float p2z;";
const char ulog_safety_set_allowed_area_name[] = "safety_set_allowed_area";

int32_t ulog_format_safety_set_allowed_area(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_safety_set_allowed_area_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_safety_set_allowed_area_format, sizeof(ulog_safety_set_allowed_area_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_safety_set_allowed_area(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_safety_set_allowed_area_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_safety_set_allowed_area_name, sizeof(ulog_safety_set_allowed_area_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_safety_set_allowed_area(ulog_t *log, ulog_msg_id_t id, const ulog_safety_set_allowed_area_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
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

    /* Coordinate frame. Can be either global, GPS, right-handed with Z axis up or local, right handed, Z axis down. */
    if (lfs_file_write(log->lfs, log->file, &src->frame, sizeof(src->frame)) < 0) {
        return 1;
    }

    /* x position 1 / Latitude 1 [m] */
    if (lfs_file_write(log->lfs, log->file, &src->p1x, sizeof(src->p1x)) < 0) {
        return 1;
    }

    /* y position 1 / Longitude 1 [m] */
    if (lfs_file_write(log->lfs, log->file, &src->p1y, sizeof(src->p1y)) < 0) {
        return 1;
    }

    /* z position 1 / Altitude 1 [m] */
    if (lfs_file_write(log->lfs, log->file, &src->p1z, sizeof(src->p1z)) < 0) {
        return 1;
    }

    /* x position 2 / Latitude 2 [m] */
    if (lfs_file_write(log->lfs, log->file, &src->p2x, sizeof(src->p2x)) < 0) {
        return 1;
    }

    /* y position 2 / Longitude 2 [m] */
    if (lfs_file_write(log->lfs, log->file, &src->p2y, sizeof(src->p2y)) < 0) {
        return 1;
    }

    /* z position 2 / Altitude 2 [m] */
    if (lfs_file_write(log->lfs, log->file, &src->p2z, sizeof(src->p2z)) < 0) {
        return 1;
    }

    
    return 0;
}
