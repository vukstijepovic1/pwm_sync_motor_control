/**
 * @file    ulog_utm_global_position.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_utm_global_position.h"
#include "ulog_def.h"

const char ulog_utm_global_position_format[] = "utm_global_position:uint64_t timestamp;uint64_t time;uint8_t[18] uas_id;int32_t lat;int32_t lon;int32_t alt;int32_t relative_alt;int16_t vx;int16_t vy;int16_t vz;uint16_t h_acc;uint16_t v_acc;uint16_t vel_acc;int32_t next_lat;int32_t next_lon;int32_t next_alt;uint16_t update_rate;uint8_t flight_state;uint8_t flags;";
const char ulog_utm_global_position_name[] = "utm_global_position";

int32_t ulog_format_utm_global_position(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_utm_global_position_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_utm_global_position_format, sizeof(ulog_utm_global_position_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_utm_global_position(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_utm_global_position_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_utm_global_position_name, sizeof(ulog_utm_global_position_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_utm_global_position(ulog_t *log, ulog_msg_id_t id, const ulog_utm_global_position_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)*18
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(uint16_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
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

    /* Time of applicability of position (microseconds since UNIX epoch). [us] */
    if (lfs_file_write(log->lfs, log->file, &src->time, sizeof(src->time)) < 0) {
        return 1;
    }

    /* Unique UAS ID. */
    if (lfs_file_write(log->lfs, log->file, src->uas_id, sizeof(src->uas_id)) < 0) {
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

    /* Altitude (WGS84) [mm] */
    if (lfs_file_write(log->lfs, log->file, &src->alt, sizeof(src->alt)) < 0) {
        return 1;
    }

    /* Altitude above ground [mm] */
    if (lfs_file_write(log->lfs, log->file, &src->relative_alt, sizeof(src->relative_alt)) < 0) {
        return 1;
    }

    /* Ground X speed (latitude, positive north) [cm/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vx, sizeof(src->vx)) < 0) {
        return 1;
    }

    /* Ground Y speed (longitude, positive east) [cm/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vy, sizeof(src->vy)) < 0) {
        return 1;
    }

    /* Ground Z speed (altitude, positive down) [cm/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vz, sizeof(src->vz)) < 0) {
        return 1;
    }

    /* Horizontal position uncertainty (standard deviation) [mm] */
    if (lfs_file_write(log->lfs, log->file, &src->h_acc, sizeof(src->h_acc)) < 0) {
        return 1;
    }

    /* Altitude uncertainty (standard deviation) [mm] */
    if (lfs_file_write(log->lfs, log->file, &src->v_acc, sizeof(src->v_acc)) < 0) {
        return 1;
    }

    /* Speed uncertainty (standard deviation) [cm/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vel_acc, sizeof(src->vel_acc)) < 0) {
        return 1;
    }

    /* Next waypoint, latitude (WGS84) [degE7] */
    if (lfs_file_write(log->lfs, log->file, &src->next_lat, sizeof(src->next_lat)) < 0) {
        return 1;
    }

    /* Next waypoint, longitude (WGS84) [degE7] */
    if (lfs_file_write(log->lfs, log->file, &src->next_lon, sizeof(src->next_lon)) < 0) {
        return 1;
    }

    /* Next waypoint, altitude (WGS84) [mm] */
    if (lfs_file_write(log->lfs, log->file, &src->next_alt, sizeof(src->next_alt)) < 0) {
        return 1;
    }

    /* Time until next update. Set to 0 if unknown or in data driven mode. [cs] */
    if (lfs_file_write(log->lfs, log->file, &src->update_rate, sizeof(src->update_rate)) < 0) {
        return 1;
    }

    /* Flight state */
    if (lfs_file_write(log->lfs, log->file, &src->flight_state, sizeof(src->flight_state)) < 0) {
        return 1;
    }

    /* Bitwise OR combination of the data available flags. */
    if (lfs_file_write(log->lfs, log->file, &src->flags, sizeof(src->flags)) < 0) {
        return 1;
    }

    
    return 0;
}
