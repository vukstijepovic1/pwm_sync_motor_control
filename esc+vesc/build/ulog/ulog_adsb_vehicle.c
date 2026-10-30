/**
 * @file    ulog_adsb_vehicle.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_adsb_vehicle.h"
#include "ulog_def.h"

const char ulog_adsb_vehicle_format[] = "adsb_vehicle:uint64_t timestamp;uint32_t ICAO_address;int32_t lat;int32_t lon;uint8_t altitude_type;int32_t altitude;uint16_t heading;uint16_t hor_velocity;int16_t ver_velocity;char[9] callsign;uint8_t emitter_type;uint8_t tslc;uint16_t flags;uint16_t squawk;";
const char ulog_adsb_vehicle_name[] = "adsb_vehicle";

int32_t ulog_format_adsb_vehicle(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_adsb_vehicle_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_adsb_vehicle_format, sizeof(ulog_adsb_vehicle_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_adsb_vehicle(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_adsb_vehicle_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_adsb_vehicle_name, sizeof(ulog_adsb_vehicle_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_adsb_vehicle(ulog_t *log, ulog_msg_id_t id, const ulog_adsb_vehicle_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(uint8_t)
                    + sizeof(int32_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(int16_t)
                    + sizeof(char)*9
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint16_t)
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

    /* ICAO address */
    if (lfs_file_write(log->lfs, log->file, &src->ICAO_address, sizeof(src->ICAO_address)) < 0) {
        return 1;
    }

    /* Latitude [degE7] */
    if (lfs_file_write(log->lfs, log->file, &src->lat, sizeof(src->lat)) < 0) {
        return 1;
    }

    /* Longitude [degE7] */
    if (lfs_file_write(log->lfs, log->file, &src->lon, sizeof(src->lon)) < 0) {
        return 1;
    }

    /* ADSB altitude type. */
    if (lfs_file_write(log->lfs, log->file, &src->altitude_type, sizeof(src->altitude_type)) < 0) {
        return 1;
    }

    /* Altitude(ASL) [mm] */
    if (lfs_file_write(log->lfs, log->file, &src->altitude, sizeof(src->altitude)) < 0) {
        return 1;
    }

    /* Course over ground [cdeg] */
    if (lfs_file_write(log->lfs, log->file, &src->heading, sizeof(src->heading)) < 0) {
        return 1;
    }

    /* The horizontal velocity [cm/s] */
    if (lfs_file_write(log->lfs, log->file, &src->hor_velocity, sizeof(src->hor_velocity)) < 0) {
        return 1;
    }

    /* The vertical velocity. Positive is up [cm/s] */
    if (lfs_file_write(log->lfs, log->file, &src->ver_velocity, sizeof(src->ver_velocity)) < 0) {
        return 1;
    }

    /* The callsign, 8+null */
    if (lfs_file_write(log->lfs, log->file, src->callsign, sizeof(src->callsign)) < 0) {
        return 1;
    }

    /* ADSB emitter type. */
    if (lfs_file_write(log->lfs, log->file, &src->emitter_type, sizeof(src->emitter_type)) < 0) {
        return 1;
    }

    /* Time since last communication in seconds [s] */
    if (lfs_file_write(log->lfs, log->file, &src->tslc, sizeof(src->tslc)) < 0) {
        return 1;
    }

    /* Bitmap to indicate various statuses including valid data fields */
    if (lfs_file_write(log->lfs, log->file, &src->flags, sizeof(src->flags)) < 0) {
        return 1;
    }

    /* Squawk code. Note that the code is in decimal: e.g. 7700 (general emergency) is encoded as binary 0b0001_1110_0001_0100, not(!) as 0b0000_111_111_000_000 */
    if (lfs_file_write(log->lfs, log->file, &src->squawk, sizeof(src->squawk)) < 0) {
        return 1;
    }

    
    return 0;
}
