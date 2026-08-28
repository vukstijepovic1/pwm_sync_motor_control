/**
 * @file    ulog_fuel_status.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_fuel_status.h"
#include "ulog_def.h"

const char ulog_fuel_status_format[] = "fuel_status:uint64_t timestamp;uint8_t id;float maximum_fuel;float consumed_fuel;float remaining_fuel;uint8_t percent_remaining;float flow_rate;float temperature;uint32_t fuel_type;";
const char ulog_fuel_status_name[] = "fuel_status";

int32_t ulog_format_fuel_status(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_fuel_status_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_fuel_status_format, sizeof(ulog_fuel_status_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_fuel_status(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_fuel_status_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_fuel_status_name, sizeof(ulog_fuel_status_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_fuel_status(ulog_t *log, ulog_msg_id_t id, const ulog_fuel_status_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(uint8_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(uint32_t)
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

    /* Fuel ID. Must match ID of other messages for same fuel system, such as BATTERY_STATUS_V2. */
    if (lfs_file_write(log->lfs, log->file, &src->id, sizeof(src->id)) < 0) {
        return 1;
    }

    /* Capacity when full. Must be provided. */
    if (lfs_file_write(log->lfs, log->file, &src->maximum_fuel, sizeof(src->maximum_fuel)) < 0) {
        return 1;
    }

    /* Consumed fuel (measured). This value should not be inferred: if not measured set to NaN. NaN: field not provided. */
    if (lfs_file_write(log->lfs, log->file, &src->consumed_fuel, sizeof(src->consumed_fuel)) < 0) {
        return 1;
    }

    /* Remaining fuel until empty (measured). The value should not be inferred: if not measured set to NaN. NaN: field not provided. */
    if (lfs_file_write(log->lfs, log->file, &src->remaining_fuel, sizeof(src->remaining_fuel)) < 0) {
        return 1;
    }

    /* Percentage of remaining fuel, relative to full. Values: [0-100], UINT8_MAX: field not provided. [%] */
    if (lfs_file_write(log->lfs, log->file, &src->percent_remaining, sizeof(src->percent_remaining)) < 0) {
        return 1;
    }

    /* Positive value when emptying/using, and negative if filling/replacing. NaN: field not provided. */
    if (lfs_file_write(log->lfs, log->file, &src->flow_rate, sizeof(src->flow_rate)) < 0) {
        return 1;
    }

    /* Fuel temperature. NaN: field not provided. [K] */
    if (lfs_file_write(log->lfs, log->file, &src->temperature, sizeof(src->temperature)) < 0) {
        return 1;
    }

    /* Fuel type. Defines units for fuel capacity and consumption fields above. */
    if (lfs_file_write(log->lfs, log->file, &src->fuel_type, sizeof(src->fuel_type)) < 0) {
        return 1;
    }

    
    return 0;
}
