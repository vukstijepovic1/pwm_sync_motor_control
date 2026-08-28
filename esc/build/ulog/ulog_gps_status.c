/**
 * @file    ulog_gps_status.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_gps_status.h"
#include "ulog_def.h"

const char ulog_gps_status_format[] = "gps_status:uint64_t timestamp;uint8_t satellites_visible;uint8_t[20] satellite_prn;uint8_t[20] satellite_used;uint8_t[20] satellite_elevation;uint8_t[20] satellite_azimuth;uint8_t[20] satellite_snr;";
const char ulog_gps_status_name[] = "gps_status";

int32_t ulog_format_gps_status(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_gps_status_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_gps_status_format, sizeof(ulog_gps_status_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_gps_status(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_gps_status_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_gps_status_name, sizeof(ulog_gps_status_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_gps_status(ulog_t *log, ulog_msg_id_t id, const ulog_gps_status_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)*20
                    + sizeof(uint8_t)*20
                    + sizeof(uint8_t)*20
                    + sizeof(uint8_t)*20
                    + sizeof(uint8_t)*20
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

    /* Number of satellites visible */
    if (lfs_file_write(log->lfs, log->file, &src->satellites_visible, sizeof(src->satellites_visible)) < 0) {
        return 1;
    }

    /* Global satellite ID */
    if (lfs_file_write(log->lfs, log->file, src->satellite_prn, sizeof(src->satellite_prn)) < 0) {
        return 1;
    }

    /* 0: Satellite not used, 1: used for localization */
    if (lfs_file_write(log->lfs, log->file, src->satellite_used, sizeof(src->satellite_used)) < 0) {
        return 1;
    }

    /* Elevation (0: right on top of receiver, 90: on the horizon) of satellite [deg] */
    if (lfs_file_write(log->lfs, log->file, src->satellite_elevation, sizeof(src->satellite_elevation)) < 0) {
        return 1;
    }

    /* Direction of satellite, 0: 0 deg, 255: 360 deg. [deg] */
    if (lfs_file_write(log->lfs, log->file, src->satellite_azimuth, sizeof(src->satellite_azimuth)) < 0) {
        return 1;
    }

    /* Signal to noise ratio of satellite [dB] */
    if (lfs_file_write(log->lfs, log->file, src->satellite_snr, sizeof(src->satellite_snr)) < 0) {
        return 1;
    }

    
    return 0;
}
