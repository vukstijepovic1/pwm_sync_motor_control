/**
 * @file    ulog_gps_input.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_gps_input.h"
#include "ulog_def.h"

const char ulog_gps_input_format[] = "gps_input:uint64_t timestamp;uint64_t time_usec;uint8_t gps_id;uint16_t ignore_flags;uint32_t time_week_ms;uint16_t time_week;uint8_t fix_type;int32_t lat;int32_t lon;float alt;float hdop;float vdop;float vn;float ve;float vd;float speed_accuracy;float horiz_accuracy;float vert_accuracy;uint8_t satellites_visible;uint16_t yaw;";
const char ulog_gps_input_name[] = "gps_input";

int32_t ulog_format_gps_input(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_gps_input_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_gps_input_format, sizeof(ulog_gps_input_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_gps_input(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_gps_input_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_gps_input_name, sizeof(ulog_gps_input_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_gps_input(ulog_t *log, ulog_msg_id_t id, const ulog_gps_input_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint16_t)
                    + sizeof(uint32_t)
                    + sizeof(uint16_t)
                    + sizeof(uint8_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(uint8_t)
                    + sizeof(uint16_t)
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

    /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->time_usec, sizeof(src->time_usec)) < 0) {
        return 1;
    }

    /* ID of the GPS for multiple GPS inputs */
    if (lfs_file_write(log->lfs, log->file, &src->gps_id, sizeof(src->gps_id)) < 0) {
        return 1;
    }

    /* Bitmap indicating which GPS input flags fields to ignore.  All other fields must be provided. */
    if (lfs_file_write(log->lfs, log->file, &src->ignore_flags, sizeof(src->ignore_flags)) < 0) {
        return 1;
    }

    /* GPS time (from start of GPS week) [ms] */
    if (lfs_file_write(log->lfs, log->file, &src->time_week_ms, sizeof(src->time_week_ms)) < 0) {
        return 1;
    }

    /* GPS week number */
    if (lfs_file_write(log->lfs, log->file, &src->time_week, sizeof(src->time_week)) < 0) {
        return 1;
    }

    /* 0-1: no fix, 2: 2D fix, 3: 3D fix. 4: 3D with DGPS. 5: 3D with RTK */
    if (lfs_file_write(log->lfs, log->file, &src->fix_type, sizeof(src->fix_type)) < 0) {
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

    /* Altitude (MSL). Positive for up. [m] */
    if (lfs_file_write(log->lfs, log->file, &src->alt, sizeof(src->alt)) < 0) {
        return 1;
    }

    /* GPS HDOP horizontal dilution of position (unitless). If unknown, set to: UINT16_MAX */
    if (lfs_file_write(log->lfs, log->file, &src->hdop, sizeof(src->hdop)) < 0) {
        return 1;
    }

    /* GPS VDOP vertical dilution of position (unitless). If unknown, set to: UINT16_MAX */
    if (lfs_file_write(log->lfs, log->file, &src->vdop, sizeof(src->vdop)) < 0) {
        return 1;
    }

    /* GPS velocity in north direction in earth-fixed NED frame [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vn, sizeof(src->vn)) < 0) {
        return 1;
    }

    /* GPS velocity in east direction in earth-fixed NED frame [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->ve, sizeof(src->ve)) < 0) {
        return 1;
    }

    /* GPS velocity in down direction in earth-fixed NED frame [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vd, sizeof(src->vd)) < 0) {
        return 1;
    }

    /* GPS speed accuracy [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->speed_accuracy, sizeof(src->speed_accuracy)) < 0) {
        return 1;
    }

    /* GPS horizontal accuracy [m] */
    if (lfs_file_write(log->lfs, log->file, &src->horiz_accuracy, sizeof(src->horiz_accuracy)) < 0) {
        return 1;
    }

    /* GPS vertical accuracy [m] */
    if (lfs_file_write(log->lfs, log->file, &src->vert_accuracy, sizeof(src->vert_accuracy)) < 0) {
        return 1;
    }

    /* Number of satellites visible. */
    if (lfs_file_write(log->lfs, log->file, &src->satellites_visible, sizeof(src->satellites_visible)) < 0) {
        return 1;
    }

    /* Yaw of vehicle relative to Earth's North, zero means not available, use 36000 for north [cdeg] */
    if (lfs_file_write(log->lfs, log->file, &src->yaw, sizeof(src->yaw)) < 0) {
        return 1;
    }

    
    return 0;
}
