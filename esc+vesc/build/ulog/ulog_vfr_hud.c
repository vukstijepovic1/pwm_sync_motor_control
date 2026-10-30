/**
 * @file    ulog_vfr_hud.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_vfr_hud.h"
#include "ulog_def.h"

const char ulog_vfr_hud_format[] = "vfr_hud:uint64_t timestamp;float airspeed;float groundspeed;int16_t heading;uint16_t throttle;float alt;float climb;";
const char ulog_vfr_hud_name[] = "vfr_hud";

int32_t ulog_format_vfr_hud(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_vfr_hud_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_vfr_hud_format, sizeof(ulog_vfr_hud_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_vfr_hud(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_vfr_hud_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_vfr_hud_name, sizeof(ulog_vfr_hud_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_vfr_hud(ulog_t *log, ulog_msg_id_t id, const ulog_vfr_hud_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(int16_t)
                    + sizeof(uint16_t)
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

    /* Vehicle speed in form appropriate for vehicle type. For standard aircraft this is typically calibrated airspeed (CAS) or indicated airspeed (IAS) - either of which can be used by a pilot to estimate stall speed. [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->airspeed, sizeof(src->airspeed)) < 0) {
        return 1;
    }

    /* Current ground speed. [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->groundspeed, sizeof(src->groundspeed)) < 0) {
        return 1;
    }

    /* Current heading in compass units (0-360, 0=north). [deg] */
    if (lfs_file_write(log->lfs, log->file, &src->heading, sizeof(src->heading)) < 0) {
        return 1;
    }

    /* Current throttle setting (0 to 100). [%] */
    if (lfs_file_write(log->lfs, log->file, &src->throttle, sizeof(src->throttle)) < 0) {
        return 1;
    }

    /* Current altitude (MSL). [m] */
    if (lfs_file_write(log->lfs, log->file, &src->alt, sizeof(src->alt)) < 0) {
        return 1;
    }

    /* Current climb rate. [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->climb, sizeof(src->climb)) < 0) {
        return 1;
    }

    
    return 0;
}
