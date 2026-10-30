/**
 * @file    ulog_ais_vessel.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_ais_vessel.h"
#include "ulog_def.h"

const char ulog_ais_vessel_format[] = "ais_vessel:uint64_t timestamp;uint32_t MMSI;int32_t lat;int32_t lon;uint16_t COG;uint16_t heading;uint16_t velocity;int8_t turn_rate;uint8_t navigational_status;uint8_t type;uint16_t dimension_bow;uint16_t dimension_stern;uint8_t dimension_port;uint8_t dimension_starboard;char[7] callsign;char[20] name;uint16_t tslc;uint16_t flags;";
const char ulog_ais_vessel_name[] = "ais_vessel";

int32_t ulog_format_ais_vessel(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_ais_vessel_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_ais_vessel_format, sizeof(ulog_ais_vessel_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_ais_vessel(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_ais_vessel_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_ais_vessel_name, sizeof(ulog_ais_vessel_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_ais_vessel(ulog_t *log, ulog_msg_id_t id, const ulog_ais_vessel_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(int8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(char)*7
                    + sizeof(char)*20
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

    /* Mobile Marine Service Identifier, 9 decimal digits */
    if (lfs_file_write(log->lfs, log->file, &src->MMSI, sizeof(src->MMSI)) < 0) {
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

    /* Course over ground [cdeg] */
    if (lfs_file_write(log->lfs, log->file, &src->COG, sizeof(src->COG)) < 0) {
        return 1;
    }

    /* True heading [cdeg] */
    if (lfs_file_write(log->lfs, log->file, &src->heading, sizeof(src->heading)) < 0) {
        return 1;
    }

    /* Speed over ground [cm/s] */
    if (lfs_file_write(log->lfs, log->file, &src->velocity, sizeof(src->velocity)) < 0) {
        return 1;
    }

    /* Turn rate [cdeg/s] */
    if (lfs_file_write(log->lfs, log->file, &src->turn_rate, sizeof(src->turn_rate)) < 0) {
        return 1;
    }

    /* Navigational status */
    if (lfs_file_write(log->lfs, log->file, &src->navigational_status, sizeof(src->navigational_status)) < 0) {
        return 1;
    }

    /* Type of vessels */
    if (lfs_file_write(log->lfs, log->file, &src->type, sizeof(src->type)) < 0) {
        return 1;
    }

    /* Distance from lat/lon location to bow [m] */
    if (lfs_file_write(log->lfs, log->file, &src->dimension_bow, sizeof(src->dimension_bow)) < 0) {
        return 1;
    }

    /* Distance from lat/lon location to stern [m] */
    if (lfs_file_write(log->lfs, log->file, &src->dimension_stern, sizeof(src->dimension_stern)) < 0) {
        return 1;
    }

    /* Distance from lat/lon location to port side [m] */
    if (lfs_file_write(log->lfs, log->file, &src->dimension_port, sizeof(src->dimension_port)) < 0) {
        return 1;
    }

    /* Distance from lat/lon location to starboard side [m] */
    if (lfs_file_write(log->lfs, log->file, &src->dimension_starboard, sizeof(src->dimension_starboard)) < 0) {
        return 1;
    }

    /* The vessel callsign */
    if (lfs_file_write(log->lfs, log->file, src->callsign, sizeof(src->callsign)) < 0) {
        return 1;
    }

    /* The vessel name */
    if (lfs_file_write(log->lfs, log->file, src->name, sizeof(src->name)) < 0) {
        return 1;
    }

    /* Time since last communication in seconds [s] */
    if (lfs_file_write(log->lfs, log->file, &src->tslc, sizeof(src->tslc)) < 0) {
        return 1;
    }

    /* Bitmask to indicate various statuses including valid data fields */
    if (lfs_file_write(log->lfs, log->file, &src->flags, sizeof(src->flags)) < 0) {
        return 1;
    }

    
    return 0;
}
