/**
 * @file    ulog_collision.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_collision.h"
#include "ulog_def.h"

const char ulog_collision_format[] = "collision:uint64_t timestamp;uint8_t src;uint32_t id;uint8_t action;uint8_t threat_level;float time_to_minimum_delta;float altitude_minimum_delta;float horizontal_minimum_delta;";
const char ulog_collision_name[] = "collision";

int32_t ulog_format_collision(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_collision_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_collision_format, sizeof(ulog_collision_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_collision(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_collision_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_collision_name, sizeof(ulog_collision_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_collision(ulog_t *log, ulog_msg_id_t id, const ulog_collision_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint32_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
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

    /* Collision data source */
    if (lfs_file_write(log->lfs, log->file, &src->src, sizeof(src->src)) < 0) {
        return 1;
    }

    /* Unique identifier, domain based on src field */
    if (lfs_file_write(log->lfs, log->file, &src->id, sizeof(src->id)) < 0) {
        return 1;
    }

    /* Action that is being taken to avoid this collision */
    if (lfs_file_write(log->lfs, log->file, &src->action, sizeof(src->action)) < 0) {
        return 1;
    }

    /* How concerned the aircraft is about this collision */
    if (lfs_file_write(log->lfs, log->file, &src->threat_level, sizeof(src->threat_level)) < 0) {
        return 1;
    }

    /* Estimated time until collision occurs [s] */
    if (lfs_file_write(log->lfs, log->file, &src->time_to_minimum_delta, sizeof(src->time_to_minimum_delta)) < 0) {
        return 1;
    }

    /* Closest vertical distance between vehicle and object [m] */
    if (lfs_file_write(log->lfs, log->file, &src->altitude_minimum_delta, sizeof(src->altitude_minimum_delta)) < 0) {
        return 1;
    }

    /* Closest horizontal distance between vehicle and object [m] */
    if (lfs_file_write(log->lfs, log->file, &src->horizontal_minimum_delta, sizeof(src->horizontal_minimum_delta)) < 0) {
        return 1;
    }

    
    return 0;
}
