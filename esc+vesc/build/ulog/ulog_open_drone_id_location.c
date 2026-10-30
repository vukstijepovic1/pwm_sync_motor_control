/**
 * @file    ulog_open_drone_id_location.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_open_drone_id_location.h"
#include "ulog_def.h"

const char ulog_open_drone_id_location_format[] = "open_drone_id_location:uint64_t timestamp;uint8_t target_system;uint8_t target_component;uint8_t[20] id_or_mac;uint8_t status;uint16_t direction;uint16_t speed_horizontal;int16_t speed_vertical;int32_t latitude;int32_t longitude;float altitude_barometric;float altitude_geodetic;uint8_t height_reference;float height;uint8_t horizontal_accuracy;uint8_t vertical_accuracy;uint8_t barometer_accuracy;uint8_t speed_accuracy;uint8_t timestamp_accuracy;";
const char ulog_open_drone_id_location_name[] = "open_drone_id_location";

int32_t ulog_format_open_drone_id_location(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_open_drone_id_location_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_open_drone_id_location_format, sizeof(ulog_open_drone_id_location_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_open_drone_id_location(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_open_drone_id_location_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_open_drone_id_location_name, sizeof(ulog_open_drone_id_location_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_open_drone_id_location(ulog_t *log, ulog_msg_id_t id, const ulog_open_drone_id_location_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)*20
                    + sizeof(uint8_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(int16_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(uint8_t)
                    + sizeof(float)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
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

    /* Indicates whether the unmanned aircraft is on the ground or in the air. */
    if (lfs_file_write(log->lfs, log->file, &src->status, sizeof(src->status)) < 0) {
        return 1;
    }

    /* Direction over ground (not heading, but direction of movement) measured clockwise from true North: 0 - 35999 centi-degrees. If unknown: 36100 centi-degrees. [cdeg] */
    if (lfs_file_write(log->lfs, log->file, &src->direction, sizeof(src->direction)) < 0) {
        return 1;
    }

    /* Ground speed. Positive only. If unknown: 25500 cm/s. If speed is larger than 25425 cm/s, use 25425 cm/s. [cm/s] */
    if (lfs_file_write(log->lfs, log->file, &src->speed_horizontal, sizeof(src->speed_horizontal)) < 0) {
        return 1;
    }

    /* The vertical speed. Up is positive. If unknown: 6300 cm/s. If speed is larger than 6200 cm/s, use 6200 cm/s. If lower than -6200 cm/s, use -6200 cm/s. [cm/s] */
    if (lfs_file_write(log->lfs, log->file, &src->speed_vertical, sizeof(src->speed_vertical)) < 0) {
        return 1;
    }

    /* Current latitude of the unmanned aircraft. If unknown: 0 (both Lat/Lon). [degE7] */
    if (lfs_file_write(log->lfs, log->file, &src->latitude, sizeof(src->latitude)) < 0) {
        return 1;
    }

    /* Current longitude of the unmanned aircraft. If unknown: 0 (both Lat/Lon). [degE7] */
    if (lfs_file_write(log->lfs, log->file, &src->longitude, sizeof(src->longitude)) < 0) {
        return 1;
    }

    /* The altitude calculated from the barometric pressue. Reference is against 29.92inHg or 1013.2mb. If unknown: -1000 m. [m] */
    if (lfs_file_write(log->lfs, log->file, &src->altitude_barometric, sizeof(src->altitude_barometric)) < 0) {
        return 1;
    }

    /* The geodetic altitude as defined by WGS84. If unknown: -1000 m. [m] */
    if (lfs_file_write(log->lfs, log->file, &src->altitude_geodetic, sizeof(src->altitude_geodetic)) < 0) {
        return 1;
    }

    /* Indicates the reference point for the height field. */
    if (lfs_file_write(log->lfs, log->file, &src->height_reference, sizeof(src->height_reference)) < 0) {
        return 1;
    }

    /* The current height of the unmanned aircraft above the take-off location or the ground as indicated by height_reference. If unknown: -1000 m. [m] */
    if (lfs_file_write(log->lfs, log->file, &src->height, sizeof(src->height)) < 0) {
        return 1;
    }

    /* The accuracy of the horizontal position. */
    if (lfs_file_write(log->lfs, log->file, &src->horizontal_accuracy, sizeof(src->horizontal_accuracy)) < 0) {
        return 1;
    }

    /* The accuracy of the vertical position. */
    if (lfs_file_write(log->lfs, log->file, &src->vertical_accuracy, sizeof(src->vertical_accuracy)) < 0) {
        return 1;
    }

    /* The accuracy of the barometric altitude. */
    if (lfs_file_write(log->lfs, log->file, &src->barometer_accuracy, sizeof(src->barometer_accuracy)) < 0) {
        return 1;
    }

    /* The accuracy of the horizontal and vertical speed. */
    if (lfs_file_write(log->lfs, log->file, &src->speed_accuracy, sizeof(src->speed_accuracy)) < 0) {
        return 1;
    }

    /* The accuracy of the timestamps. */
    if (lfs_file_write(log->lfs, log->file, &src->timestamp_accuracy, sizeof(src->timestamp_accuracy)) < 0) {
        return 1;
    }

    
    return 0;
}
