/**
 * @file    ulog_nav_controller_output.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_nav_controller_output.h"
#include "ulog_def.h"

const char ulog_nav_controller_output_format[] = "nav_controller_output:uint64_t timestamp;float nav_roll;float nav_pitch;int16_t nav_bearing;int16_t target_bearing;uint16_t wp_dist;float alt_error;float aspd_error;float xtrack_error;";
const char ulog_nav_controller_output_name[] = "nav_controller_output";

int32_t ulog_format_nav_controller_output(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_nav_controller_output_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_nav_controller_output_format, sizeof(ulog_nav_controller_output_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_nav_controller_output(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_nav_controller_output_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_nav_controller_output_name, sizeof(ulog_nav_controller_output_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_nav_controller_output(ulog_t *log, ulog_msg_id_t id, const ulog_nav_controller_output_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(uint16_t)
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

    /* Current desired roll [deg] */
    if (lfs_file_write(log->lfs, log->file, &src->nav_roll, sizeof(src->nav_roll)) < 0) {
        return 1;
    }

    /* Current desired pitch [deg] */
    if (lfs_file_write(log->lfs, log->file, &src->nav_pitch, sizeof(src->nav_pitch)) < 0) {
        return 1;
    }

    /* Current desired heading [deg] */
    if (lfs_file_write(log->lfs, log->file, &src->nav_bearing, sizeof(src->nav_bearing)) < 0) {
        return 1;
    }

    /* Bearing to current waypoint/target [deg] */
    if (lfs_file_write(log->lfs, log->file, &src->target_bearing, sizeof(src->target_bearing)) < 0) {
        return 1;
    }

    /* Distance to active waypoint [m] */
    if (lfs_file_write(log->lfs, log->file, &src->wp_dist, sizeof(src->wp_dist)) < 0) {
        return 1;
    }

    /* Current altitude error [m] */
    if (lfs_file_write(log->lfs, log->file, &src->alt_error, sizeof(src->alt_error)) < 0) {
        return 1;
    }

    /* Current airspeed error [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->aspd_error, sizeof(src->aspd_error)) < 0) {
        return 1;
    }

    /* Current crosstrack error on x-y plane [m] */
    if (lfs_file_write(log->lfs, log->file, &src->xtrack_error, sizeof(src->xtrack_error)) < 0) {
        return 1;
    }

    
    return 0;
}
