/**
 * @file    ulog_open_drone_id_system.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_open_drone_id_system.h"
#include "ulog_def.h"

const char ulog_open_drone_id_system_format[] = "open_drone_id_system:uint64_t timestamp;uint8_t target_system;uint8_t target_component;uint8_t[20] id_or_mac;uint8_t operator_location_type;uint8_t classification_type;int32_t operator_latitude;int32_t operator_longitude;uint16_t area_count;uint16_t area_radius;float area_ceiling;float area_floor;uint8_t category_eu;uint8_t class_eu;float operator_altitude_geo;";
const char ulog_open_drone_id_system_name[] = "open_drone_id_system";

int32_t ulog_format_open_drone_id_system(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_open_drone_id_system_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_open_drone_id_system_format, sizeof(ulog_open_drone_id_system_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_open_drone_id_system(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_open_drone_id_system_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_open_drone_id_system_name, sizeof(ulog_open_drone_id_system_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_open_drone_id_system(ulog_t *log, ulog_msg_id_t id, const ulog_open_drone_id_system_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)*20
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
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

    /* System ID (0 for broadcast). */
    if (lfs_file_write(log->lfs, log->file, &src->target_system, sizeof(src->target_system)) < 0) {
        return 1;
    }

    /* Component ID (0 for broadcast). */
    if (lfs_file_write(log->lfs, log->file, &src->target_component, sizeof(src->target_component)) < 0) {
        return 1;
    }

    /* Only used for drone ID data received from other UAs. See detailed description at https://mavlink.io/en/services/opendroneid.html.  */
    if (lfs_file_write(log->lfs, log->file, src->id_or_mac, sizeof(src->id_or_mac)) < 0) {
        return 1;
    }

    /* Specifies the operator location type. */
    if (lfs_file_write(log->lfs, log->file, &src->operator_location_type, sizeof(src->operator_location_type)) < 0) {
        return 1;
    }

    /* Specifies the classification type of the UA. */
    if (lfs_file_write(log->lfs, log->file, &src->classification_type, sizeof(src->classification_type)) < 0) {
        return 1;
    }

    /* Latitude of the operator. If unknown: 0 (both Lat/Lon). [degE7] */
    if (lfs_file_write(log->lfs, log->file, &src->operator_latitude, sizeof(src->operator_latitude)) < 0) {
        return 1;
    }

    /* Longitude of the operator. If unknown: 0 (both Lat/Lon). [degE7] */
    if (lfs_file_write(log->lfs, log->file, &src->operator_longitude, sizeof(src->operator_longitude)) < 0) {
        return 1;
    }

    /* Number of aircraft in the area, group or formation (default 1). Used only for swarms/multiple UA. */
    if (lfs_file_write(log->lfs, log->file, &src->area_count, sizeof(src->area_count)) < 0) {
        return 1;
    }

    /* Radius of the cylindrical area of the group or formation (default 0). Used only for swarms/multiple UA. [m] */
    if (lfs_file_write(log->lfs, log->file, &src->area_radius, sizeof(src->area_radius)) < 0) {
        return 1;
    }

    /* Area Operations Ceiling relative to WGS84. If unknown: -1000 m. Used only for swarms/multiple UA. [m] */
    if (lfs_file_write(log->lfs, log->file, &src->area_ceiling, sizeof(src->area_ceiling)) < 0) {
        return 1;
    }

    /* Area Operations Floor relative to WGS84. If unknown: -1000 m. Used only for swarms/multiple UA. [m] */
    if (lfs_file_write(log->lfs, log->file, &src->area_floor, sizeof(src->area_floor)) < 0) {
        return 1;
    }

    /* When classification_type is MAV_ODID_CLASSIFICATION_TYPE_EU, specifies the category of the UA. */
    if (lfs_file_write(log->lfs, log->file, &src->category_eu, sizeof(src->category_eu)) < 0) {
        return 1;
    }

    /* When classification_type is MAV_ODID_CLASSIFICATION_TYPE_EU, specifies the class of the UA. */
    if (lfs_file_write(log->lfs, log->file, &src->class_eu, sizeof(src->class_eu)) < 0) {
        return 1;
    }

    /* Geodetic altitude of the operator relative to WGS84. If unknown: -1000 m. [m] */
    if (lfs_file_write(log->lfs, log->file, &src->operator_altitude_geo, sizeof(src->operator_altitude_geo)) < 0) {
        return 1;
    }

    
    return 0;
}
