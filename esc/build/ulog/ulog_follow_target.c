/**
 * @file    ulog_follow_target.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_follow_target.h"
#include "ulog_def.h"

const char ulog_follow_target_format[] = "follow_target:uint64_t timestamp;uint8_t est_capabilities;int32_t lat;int32_t lon;float alt;float[3] vel;float[3] acc;float[4] attitude_q;float[3] rates;float[3] position_cov;uint64_t custom_state;";
const char ulog_follow_target_name[] = "follow_target";

int32_t ulog_format_follow_target(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_follow_target_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_follow_target_format, sizeof(ulog_follow_target_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_follow_target(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_follow_target_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_follow_target_name, sizeof(ulog_follow_target_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_follow_target(ulog_t *log, ulog_msg_id_t id, const ulog_follow_target_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(float)
                    + sizeof(float)*3
                    + sizeof(float)*3
                    + sizeof(float)*4
                    + sizeof(float)*3
                    + sizeof(float)*3
                    + sizeof(uint64_t)
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

    /* bit positions for tracker reporting capabilities (POS = 0, VEL = 1, ACCEL = 2, ATT + RATES = 3) */
    if (lfs_file_write(log->lfs, log->file, &src->est_capabilities, sizeof(src->est_capabilities)) < 0) {
        return 1;
    }

    /* Latitude (WGS84) [degE7] */
    if (lfs_file_write(log->lfs, log->file, &src->lat, sizeof(src->lat)) < 0) {
        return 1;
    }

    /* Longitude (WGS84) [degE7] */
    if (lfs_file_write(log->lfs, log->file, &src->lon, sizeof(src->lon)) < 0) {
        return 1;
    }

    /* Altitude (MSL) [m] */
    if (lfs_file_write(log->lfs, log->file, &src->alt, sizeof(src->alt)) < 0) {
        return 1;
    }

    /* target velocity (0,0,0) for unknown [m/s] */
    if (lfs_file_write(log->lfs, log->file, src->vel, sizeof(src->vel)) < 0) {
        return 1;
    }

    /* linear target acceleration (0,0,0) for unknown [m/s/s] */
    if (lfs_file_write(log->lfs, log->file, src->acc, sizeof(src->acc)) < 0) {
        return 1;
    }

    /* (0 0 0 0 for unknown) */
    if (lfs_file_write(log->lfs, log->file, src->attitude_q, sizeof(src->attitude_q)) < 0) {
        return 1;
    }

    /* (0 0 0 for unknown) */
    if (lfs_file_write(log->lfs, log->file, src->rates, sizeof(src->rates)) < 0) {
        return 1;
    }

    /* eph epv */
    if (lfs_file_write(log->lfs, log->file, src->position_cov, sizeof(src->position_cov)) < 0) {
        return 1;
    }

    /* button states or switches of a tracker device */
    if (lfs_file_write(log->lfs, log->file, &src->custom_state, sizeof(src->custom_state)) < 0) {
        return 1;
    }

    
    return 0;
}
