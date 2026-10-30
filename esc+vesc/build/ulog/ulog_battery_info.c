/**
 * @file    ulog_battery_info.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_battery_info.h"
#include "ulog_def.h"

const char ulog_battery_info_format[] = "battery_info:uint64_t timestamp;uint8_t id;uint8_t battery_function;uint8_t type;uint8_t state_of_health;uint8_t cells_in_series;uint16_t cycle_count;uint16_t weight;float discharge_minimum_voltage;float charging_minimum_voltage;float resting_minimum_voltage;float charging_maximum_voltage;float charging_maximum_current;float nominal_voltage;float discharge_maximum_current;float discharge_maximum_burst_current;float design_capacity;float full_charge_capacity;char[9] manufacture_date;char[32] serial_number;char[50] name;";
const char ulog_battery_info_name[] = "battery_info";

int32_t ulog_format_battery_info(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_battery_info_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_battery_info_format, sizeof(ulog_battery_info_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_battery_info(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_battery_info_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_battery_info_name, sizeof(ulog_battery_info_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_battery_info(ulog_t *log, ulog_msg_id_t id, const ulog_battery_info_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(char)*9
                    + sizeof(char)*32
                    + sizeof(char)*50
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

    /* Battery ID */
    if (lfs_file_write(log->lfs, log->file, &src->id, sizeof(src->id)) < 0) {
        return 1;
    }

    /* Function of the battery. */
    if (lfs_file_write(log->lfs, log->file, &src->battery_function, sizeof(src->battery_function)) < 0) {
        return 1;
    }

    /* Type (chemistry) of the battery. */
    if (lfs_file_write(log->lfs, log->file, &src->type, sizeof(src->type)) < 0) {
        return 1;
    }

    /* State of Health (SOH) estimate. Typically 100% at the time of manufacture and will decrease over time and use. -1: field not provided. [%] */
    if (lfs_file_write(log->lfs, log->file, &src->state_of_health, sizeof(src->state_of_health)) < 0) {
        return 1;
    }

    /* Number of battery cells in series. 0: field not provided. */
    if (lfs_file_write(log->lfs, log->file, &src->cells_in_series, sizeof(src->cells_in_series)) < 0) {
        return 1;
    }

    /* Lifetime count of the number of charge/discharge cycles (https://en.wikipedia.org/wiki/Charge_cycle). UINT16_MAX: field not provided. */
    if (lfs_file_write(log->lfs, log->file, &src->cycle_count, sizeof(src->cycle_count)) < 0) {
        return 1;
    }

    /* Battery weight. 0: field not provided. [g] */
    if (lfs_file_write(log->lfs, log->file, &src->weight, sizeof(src->weight)) < 0) {
        return 1;
    }

    /* Minimum per-cell voltage when discharging. 0: field not provided. [V] */
    if (lfs_file_write(log->lfs, log->file, &src->discharge_minimum_voltage, sizeof(src->discharge_minimum_voltage)) < 0) {
        return 1;
    }

    /* Minimum per-cell voltage when charging. 0: field not provided. [V] */
    if (lfs_file_write(log->lfs, log->file, &src->charging_minimum_voltage, sizeof(src->charging_minimum_voltage)) < 0) {
        return 1;
    }

    /* Minimum per-cell voltage when resting. 0: field not provided. [V] */
    if (lfs_file_write(log->lfs, log->file, &src->resting_minimum_voltage, sizeof(src->resting_minimum_voltage)) < 0) {
        return 1;
    }

    /* Maximum per-cell voltage when charged. 0: field not provided. [V] */
    if (lfs_file_write(log->lfs, log->file, &src->charging_maximum_voltage, sizeof(src->charging_maximum_voltage)) < 0) {
        return 1;
    }

    /* Maximum pack continuous charge current. 0: field not provided. [A] */
    if (lfs_file_write(log->lfs, log->file, &src->charging_maximum_current, sizeof(src->charging_maximum_current)) < 0) {
        return 1;
    }

    /* Battery nominal voltage. Used for conversion between Wh and Ah. 0: field not provided. [V] */
    if (lfs_file_write(log->lfs, log->file, &src->nominal_voltage, sizeof(src->nominal_voltage)) < 0) {
        return 1;
    }

    /* Maximum pack discharge current. 0: field not provided. [A] */
    if (lfs_file_write(log->lfs, log->file, &src->discharge_maximum_current, sizeof(src->discharge_maximum_current)) < 0) {
        return 1;
    }

    /* Maximum pack discharge burst current. 0: field not provided. [A] */
    if (lfs_file_write(log->lfs, log->file, &src->discharge_maximum_burst_current, sizeof(src->discharge_maximum_burst_current)) < 0) {
        return 1;
    }

    /* Fully charged design capacity. 0: field not provided. [Ah] */
    if (lfs_file_write(log->lfs, log->file, &src->design_capacity, sizeof(src->design_capacity)) < 0) {
        return 1;
    }

    /* Predicted battery capacity when fully charged (accounting for battery degradation). NAN: field not provided. [Ah] */
    if (lfs_file_write(log->lfs, log->file, &src->full_charge_capacity, sizeof(src->full_charge_capacity)) < 0) {
        return 1;
    }

    /* Manufacture date (DDMMYYYY) in ASCII characters, 0 terminated. All 0: field not provided. */
    if (lfs_file_write(log->lfs, log->file, src->manufacture_date, sizeof(src->manufacture_date)) < 0) {
        return 1;
    }

    /* Serial number in ASCII characters, 0 terminated. All 0: field not provided. */
    if (lfs_file_write(log->lfs, log->file, src->serial_number, sizeof(src->serial_number)) < 0) {
        return 1;
    }

    /* Battery device name. Formatted as manufacturer name then product name, separated with an underscore (in ASCII characters), 0 terminated. All 0: field not provided. */
    if (lfs_file_write(log->lfs, log->file, src->name, sizeof(src->name)) < 0) {
        return 1;
    }

    
    return 0;
}
