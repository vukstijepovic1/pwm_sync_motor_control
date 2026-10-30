/**
 * @file    ulog_battery_status.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_battery_status.h"
#include "ulog_def.h"

const char ulog_battery_status_format[] = "battery_status:uint64_t timestamp;uint8_t id;uint8_t battery_function;uint8_t type;int16_t temperature;uint16_t[10] voltages;int16_t current_battery;int32_t current_consumed;int32_t energy_consumed;int8_t battery_remaining;int32_t time_remaining;uint8_t charge_state;uint16_t[4] voltages_ext;uint8_t mode;uint32_t fault_bitmask;";
const char ulog_battery_status_name[] = "battery_status";

int32_t ulog_format_battery_status(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_battery_status_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_battery_status_format, sizeof(ulog_battery_status_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_battery_status(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_battery_status_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_battery_status_name, sizeof(ulog_battery_status_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_battery_status(ulog_t *log, ulog_msg_id_t id, const ulog_battery_status_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(int16_t)
                    + sizeof(uint16_t)*10
                    + sizeof(int16_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(int8_t)
                    + sizeof(int32_t)
                    + sizeof(uint8_t)
                    + sizeof(uint16_t)*4
                    + sizeof(uint8_t)
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

    /* Temperature of the battery. INT16_MAX for unknown temperature. [cdegC] */
    if (lfs_file_write(log->lfs, log->file, &src->temperature, sizeof(src->temperature)) < 0) {
        return 1;
    }

    /* Battery voltage of cells 1 to 10 (see voltages_ext for cells 11-14). Cells in this field above the valid cell count for this battery should have the UINT16_MAX value. If individual cell voltages are unknown or not measured for this battery, then the overall battery voltage should be filled in cell 0, with all others set to UINT16_MAX. If the voltage of the battery is greater than (UINT16_MAX - 1), then cell 0 should be set to (UINT16_MAX - 1), and cell 1 to the remaining voltage. This can be extended to multiple cells if the total voltage is greater than 2 * (UINT16_MAX - 1). [mV] */
    if (lfs_file_write(log->lfs, log->file, src->voltages, sizeof(src->voltages)) < 0) {
        return 1;
    }

    /* Battery current, -1: autopilot does not measure the current [cA] */
    if (lfs_file_write(log->lfs, log->file, &src->current_battery, sizeof(src->current_battery)) < 0) {
        return 1;
    }

    /* Consumed charge, -1: autopilot does not provide consumption estimate [mAh] */
    if (lfs_file_write(log->lfs, log->file, &src->current_consumed, sizeof(src->current_consumed)) < 0) {
        return 1;
    }

    /* Consumed energy, -1: autopilot does not provide energy consumption estimate [hJ] */
    if (lfs_file_write(log->lfs, log->file, &src->energy_consumed, sizeof(src->energy_consumed)) < 0) {
        return 1;
    }

    /* Remaining battery energy. Values: [0-100], -1: autopilot does not estimate the remaining battery. [%] */
    if (lfs_file_write(log->lfs, log->file, &src->battery_remaining, sizeof(src->battery_remaining)) < 0) {
        return 1;
    }

    /* Remaining battery time, 0: autopilot does not provide remaining battery time estimate [s] */
    if (lfs_file_write(log->lfs, log->file, &src->time_remaining, sizeof(src->time_remaining)) < 0) {
        return 1;
    }

    /* State for extent of discharge, provided by autopilot for warning or external reactions */
    if (lfs_file_write(log->lfs, log->file, &src->charge_state, sizeof(src->charge_state)) < 0) {
        return 1;
    }

    /* Battery voltages for cells 11 to 14. Cells above the valid cell count for this battery should have a value of 0, where zero indicates not supported (note, this is different than for the voltages field and allows empty byte truncation). If the measured value is 0 then 1 should be sent instead. [mV] */
    if (lfs_file_write(log->lfs, log->file, src->voltages_ext, sizeof(src->voltages_ext)) < 0) {
        return 1;
    }

    /* Battery mode. Default (0) is that battery mode reporting is not supported or battery is in normal-use mode. */
    if (lfs_file_write(log->lfs, log->file, &src->mode, sizeof(src->mode)) < 0) {
        return 1;
    }

    /* Fault/health indications. These should be set when charge_state is MAV_BATTERY_CHARGE_STATE_FAILED or MAV_BATTERY_CHARGE_STATE_UNHEALTHY (if not, fault reporting is not supported). */
    if (lfs_file_write(log->lfs, log->file, &src->fault_bitmask, sizeof(src->fault_bitmask)) < 0) {
        return 1;
    }

    
    return 0;
}
