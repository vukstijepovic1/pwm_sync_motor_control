/**
 * @file    ulog_altitude.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_altitude.h"
#include "ulog_def.h"

const char ulog_altitude_format[] = "altitude:uint64_t timestamp;uint64_t time_usec;float altitude_monotonic;float altitude_amsl;float altitude_local;float altitude_relative;float altitude_terrain;float bottom_clearance;";
const char ulog_altitude_name[] = "altitude";

int32_t ulog_format_altitude(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_altitude_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_altitude_format, sizeof(ulog_altitude_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_altitude(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_altitude_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_altitude_name, sizeof(ulog_altitude_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_altitude(ulog_t *log, ulog_msg_id_t id, const ulog_altitude_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint64_t)
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

    /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->time_usec, sizeof(src->time_usec)) < 0) {
        return 1;
    }

    /* This altitude measure is initialized on system boot and monotonic (it is never reset, but represents the local altitude change). The only guarantee on this field is that it will never be reset and is consistent within a flight. The recommended value for this field is the uncorrected barometric altitude at boot time. This altitude will also drift and vary between flights. [m] */
    if (lfs_file_write(log->lfs, log->file, &src->altitude_monotonic, sizeof(src->altitude_monotonic)) < 0) {
        return 1;
    }

    /* This altitude measure is strictly above mean sea level and might be non-monotonic (it might reset on events like GPS lock or when a new QNH value is set). It should be the altitude to which global altitude waypoints are compared to. Note that it is *not* the GPS altitude, however, most GPS modules already output MSL by default and not the WGS84 altitude. [m] */
    if (lfs_file_write(log->lfs, log->file, &src->altitude_amsl, sizeof(src->altitude_amsl)) < 0) {
        return 1;
    }

    /* This is the local altitude in the local coordinate frame. It is not the altitude above home, but in reference to the coordinate origin (0, 0, 0). It is up-positive. [m] */
    if (lfs_file_write(log->lfs, log->file, &src->altitude_local, sizeof(src->altitude_local)) < 0) {
        return 1;
    }

    /* This is the altitude above the home position. It resets on each change of the current home position. [m] */
    if (lfs_file_write(log->lfs, log->file, &src->altitude_relative, sizeof(src->altitude_relative)) < 0) {
        return 1;
    }

    /* This is the altitude above terrain. It might be fed by a terrain database or an altimeter. Values smaller than -1000 should be interpreted as unknown. [m] */
    if (lfs_file_write(log->lfs, log->file, &src->altitude_terrain, sizeof(src->altitude_terrain)) < 0) {
        return 1;
    }

    /* This is not the altitude, but the clear space below the system according to the fused clearance estimate. It generally should max out at the maximum range of e.g. the laser altimeter. It is generally a moving target. A negative value indicates no measurement available. [m] */
    if (lfs_file_write(log->lfs, log->file, &src->bottom_clearance, sizeof(src->bottom_clearance)) < 0) {
        return 1;
    }

    
    return 0;
}
