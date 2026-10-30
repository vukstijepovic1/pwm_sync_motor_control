/**
 * @file    ulog_hil_gps.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_hil_gps.h"
#include "ulog_def.h"

const char ulog_hil_gps_format[] = "hil_gps:uint64_t timestamp;uint64_t time_usec;uint8_t fix_type;int32_t lat;int32_t lon;int32_t alt;uint16_t eph;uint16_t epv;uint16_t vel;int16_t vn;int16_t ve;int16_t vd;uint16_t cog;uint8_t satellites_visible;uint8_t id;uint16_t yaw;";
const char ulog_hil_gps_name[] = "hil_gps";

int32_t ulog_format_hil_gps(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_hil_gps_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_hil_gps_format, sizeof(ulog_hil_gps_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_hil_gps(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_hil_gps_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_hil_gps_name, sizeof(ulog_hil_gps_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_hil_gps(ulog_t *log, ulog_msg_id_t id, const ulog_hil_gps_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint8_t)
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

    /* 0-1: no fix, 2: 2D fix, 3: 3D fix. Some applications will not use the value of this field unless it is at least two, so always correctly fill in the fix. */
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

    /* Altitude (MSL). Positive for up. [mm] */
    if (lfs_file_write(log->lfs, log->file, &src->alt, sizeof(src->alt)) < 0) {
        return 1;
    }

    /* GPS HDOP horizontal dilution of position (unitless * 100). If unknown, set to: UINT16_MAX */
    if (lfs_file_write(log->lfs, log->file, &src->eph, sizeof(src->eph)) < 0) {
        return 1;
    }

    /* GPS VDOP vertical dilution of position (unitless * 100). If unknown, set to: UINT16_MAX */
    if (lfs_file_write(log->lfs, log->file, &src->epv, sizeof(src->epv)) < 0) {
        return 1;
    }

    /* GPS ground speed. If unknown, set to: UINT16_MAX [cm/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vel, sizeof(src->vel)) < 0) {
        return 1;
    }

    /* GPS velocity in north direction in earth-fixed NED frame [cm/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vn, sizeof(src->vn)) < 0) {
        return 1;
    }

    /* GPS velocity in east direction in earth-fixed NED frame [cm/s] */
    if (lfs_file_write(log->lfs, log->file, &src->ve, sizeof(src->ve)) < 0) {
        return 1;
    }

    /* GPS velocity in down direction in earth-fixed NED frame [cm/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vd, sizeof(src->vd)) < 0) {
        return 1;
    }

    /* Course over ground (NOT heading, but direction of movement), 0.0..359.99 degrees. If unknown, set to: UINT16_MAX [cdeg] */
    if (lfs_file_write(log->lfs, log->file, &src->cog, sizeof(src->cog)) < 0) {
        return 1;
    }

    /* Number of satellites visible. If unknown, set to UINT8_MAX */
    if (lfs_file_write(log->lfs, log->file, &src->satellites_visible, sizeof(src->satellites_visible)) < 0) {
        return 1;
    }

    /* GPS ID (zero indexed). Used for multiple GPS inputs */
    if (lfs_file_write(log->lfs, log->file, &src->id, sizeof(src->id)) < 0) {
        return 1;
    }

    /* Yaw of vehicle relative to Earth's North, zero means not available, use 36000 for north [cdeg] */
    if (lfs_file_write(log->lfs, log->file, &src->yaw, sizeof(src->yaw)) < 0) {
        return 1;
    }

    
    return 0;
}
