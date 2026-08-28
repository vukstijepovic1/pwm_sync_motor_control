/**
 * @file    ulog_set_home_position.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_set_home_position.h"
#include "ulog_def.h"

const char ulog_set_home_position_format[] = "set_home_position:uint64_t timestamp;uint8_t target_system;int32_t latitude;int32_t longitude;int32_t altitude;float x;float y;float z;float[4] q;float approach_x;float approach_y;float approach_z;uint64_t time_usec;";
const char ulog_set_home_position_name[] = "set_home_position";

int32_t ulog_format_set_home_position(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_set_home_position_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_set_home_position_format, sizeof(ulog_set_home_position_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_set_home_position(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_set_home_position_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_set_home_position_name, sizeof(ulog_set_home_position_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_set_home_position(ulog_t *log, ulog_msg_id_t id, const ulog_set_home_position_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)*4
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
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

    /* System ID. */
    if (lfs_file_write(log->lfs, log->file, &src->target_system, sizeof(src->target_system)) < 0) {
        return 1;
    }

    /* Latitude (WGS84) [degE7] */
    if (lfs_file_write(log->lfs, log->file, &src->latitude, sizeof(src->latitude)) < 0) {
        return 1;
    }

    /* Longitude (WGS84) [degE7] */
    if (lfs_file_write(log->lfs, log->file, &src->longitude, sizeof(src->longitude)) < 0) {
        return 1;
    }

    /* Altitude (MSL). Positive for up. [mm] */
    if (lfs_file_write(log->lfs, log->file, &src->altitude, sizeof(src->altitude)) < 0) {
        return 1;
    }

    /* Local X position of this position in the local coordinate frame (NED) [m] */
    if (lfs_file_write(log->lfs, log->file, &src->x, sizeof(src->x)) < 0) {
        return 1;
    }

    /* Local Y position of this position in the local coordinate frame (NED) [m] */
    if (lfs_file_write(log->lfs, log->file, &src->y, sizeof(src->y)) < 0) {
        return 1;
    }

    /* Local Z position of this position in the local coordinate frame (NED: positive "down") [m] */
    if (lfs_file_write(log->lfs, log->file, &src->z, sizeof(src->z)) < 0) {
        return 1;
    }

    /* World to surface normal and heading transformation of the takeoff position. Used to indicate the heading and slope of the ground */
    if (lfs_file_write(log->lfs, log->file, src->q, sizeof(src->q)) < 0) {
        return 1;
    }

    /* Local X position of the end of the approach vector. Multicopters should set this position based on their takeoff path. Grass-landing fixed wing aircraft should set it the same way as multicopters. Runway-landing fixed wing aircraft should set it to the opposite direction of the takeoff, assuming the takeoff happened from the threshold / touchdown zone. [m] */
    if (lfs_file_write(log->lfs, log->file, &src->approach_x, sizeof(src->approach_x)) < 0) {
        return 1;
    }

    /* Local Y position of the end of the approach vector. Multicopters should set this position based on their takeoff path. Grass-landing fixed wing aircraft should set it the same way as multicopters. Runway-landing fixed wing aircraft should set it to the opposite direction of the takeoff, assuming the takeoff happened from the threshold / touchdown zone. [m] */
    if (lfs_file_write(log->lfs, log->file, &src->approach_y, sizeof(src->approach_y)) < 0) {
        return 1;
    }

    /* Local Z position of the end of the approach vector. Multicopters should set this position based on their takeoff path. Grass-landing fixed wing aircraft should set it the same way as multicopters. Runway-landing fixed wing aircraft should set it to the opposite direction of the takeoff, assuming the takeoff happened from the threshold / touchdown zone. [m] */
    if (lfs_file_write(log->lfs, log->file, &src->approach_z, sizeof(src->approach_z)) < 0) {
        return 1;
    }

    /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->time_usec, sizeof(src->time_usec)) < 0) {
        return 1;
    }

    
    return 0;
}
