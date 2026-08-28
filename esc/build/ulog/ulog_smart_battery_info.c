/**
 * @file    ulog_smart_battery_info.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_smart_battery_info.h"
#include "ulog_def.h"

const char ulog_smart_battery_info_format[] = "smart_battery_info:uint64_t timestamp;uint8_t id;uint8_t battery_function;uint8_t type;int32_t capacity_full_specification;int32_t capacity_full;uint16_t cycle_count;char[16] serial_number;char[50] device_name;uint16_t weight;uint16_t discharge_minimum_voltage;uint16_t charging_minimum_voltage;uint16_t resting_minimum_voltage;uint16_t charging_maximum_voltage;uint8_t cells_in_series;uint32_t discharge_maximum_current;uint32_t discharge_maximum_burst_current;char[11] manufacture_date;";
const char ulog_smart_battery_info_name[] = "smart_battery_info";

int32_t ulog_format_smart_battery_info(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_smart_battery_info_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_smart_battery_info_format, sizeof(ulog_smart_battery_info_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_smart_battery_info(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_smart_battery_info_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_smart_battery_info_name, sizeof(ulog_smart_battery_info_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_smart_battery_info(ulog_t *log, ulog_msg_id_t id, const ulog_smart_battery_info_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(uint16_t)
                    + sizeof(char)*16
                    + sizeof(char)*50
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint8_t)
                    + sizeof(uint32_t)
                    + sizeof(uint32_t)
                    + sizeof(char)*11
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

    /* Function of the battery */
    if (lfs_file_write(log->lfs, log->file, &src->battery_function, sizeof(src->battery_function)) < 0) {
        return 1;
    }

    /* Type (chemistry) of the battery */
    if (lfs_file_write(log->lfs, log->file, &src->type, sizeof(src->type)) < 0) {
        return 1;
    }

    /* Capacity when full according to manufacturer, -1: field not provided. [mAh] */
    if (lfs_file_write(log->lfs, log->file, &src->capacity_full_specification, sizeof(src->capacity_full_specification)) < 0) {
        return 1;
    }

    /* Capacity when full (accounting for battery degradation), -1: field not provided. [mAh] */
    if (lfs_file_write(log->lfs, log->file, &src->capacity_full, sizeof(src->capacity_full)) < 0) {
        return 1;
    }

    /* Charge/discharge cycle count. UINT16_MAX: field not provided. */
    if (lfs_file_write(log->lfs, log->file, &src->cycle_count, sizeof(src->cycle_count)) < 0) {
        return 1;
    }

    /* Serial number in ASCII characters, 0 terminated. All 0: field not provided. */
    if (lfs_file_write(log->lfs, log->file, src->serial_number, sizeof(src->serial_number)) < 0) {
        return 1;
    }

    /* Static device name in ASCII characters, 0 terminated. All 0: field not provided. Encode as manufacturer name then product name separated using an underscore. */
    if (lfs_file_write(log->lfs, log->file, src->device_name, sizeof(src->device_name)) < 0) {
        return 1;
    }

    /* Battery weight. 0: field not provided. [g] */
    if (lfs_file_write(log->lfs, log->file, &src->weight, sizeof(src->weight)) < 0) {
        return 1;
    }

    /* Minimum per-cell voltage when discharging. If not supplied set to UINT16_MAX value. [mV] */
    if (lfs_file_write(log->lfs, log->file, &src->discharge_minimum_voltage, sizeof(src->discharge_minimum_voltage)) < 0) {
        return 1;
    }

    /* Minimum per-cell voltage when charging. If not supplied set to UINT16_MAX value. [mV] */
    if (lfs_file_write(log->lfs, log->file, &src->charging_minimum_voltage, sizeof(src->charging_minimum_voltage)) < 0) {
        return 1;
    }

    /* Minimum per-cell voltage when resting. If not supplied set to UINT16_MAX value. [mV] */
    if (lfs_file_write(log->lfs, log->file, &src->resting_minimum_voltage, sizeof(src->resting_minimum_voltage)) < 0) {
        return 1;
    }

    /* Maximum per-cell voltage when charged. 0: field not provided. [mV] */
    if (lfs_file_write(log->lfs, log->file, &src->charging_maximum_voltage, sizeof(src->charging_maximum_voltage)) < 0) {
        return 1;
    }

    /* Number of battery cells in series. 0: field not provided. */
    if (lfs_file_write(log->lfs, log->file, &src->cells_in_series, sizeof(src->cells_in_series)) < 0) {
        return 1;
    }

    /* Maximum pack discharge current. 0: field not provided. [mA] */
    if (lfs_file_write(log->lfs, log->file, &src->discharge_maximum_current, sizeof(src->discharge_maximum_current)) < 0) {
        return 1;
    }

    /* Maximum pack discharge burst current. 0: field not provided. [mA] */
    if (lfs_file_write(log->lfs, log->file, &src->discharge_maximum_burst_current, sizeof(src->discharge_maximum_burst_current)) < 0) {
        return 1;
    }

    /* Manufacture date (DD/MM/YYYY) in ASCII characters, 0 terminated. All 0: field not provided. */
    if (lfs_file_write(log->lfs, log->file, src->manufacture_date, sizeof(src->manufacture_date)) < 0) {
        return 1;
    }

    
    return 0;
}
