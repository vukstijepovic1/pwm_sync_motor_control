/**
 * @file    ulog_sys_status.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_sys_status.h"
#include "ulog_def.h"

const char ulog_sys_status_format[] = "sys_status:uint64_t timestamp;uint32_t onboard_control_sensors_present;uint32_t onboard_control_sensors_enabled;uint32_t onboard_control_sensors_health;uint16_t load;uint16_t voltage_battery;int16_t current_battery;int8_t battery_remaining;uint16_t drop_rate_comm;uint16_t errors_comm;uint16_t errors_count1;uint16_t errors_count2;uint16_t errors_count3;uint16_t errors_count4;uint32_t onboard_control_sensors_present_extended;uint32_t onboard_control_sensors_enabled_extended;uint32_t onboard_control_sensors_health_extended;";
const char ulog_sys_status_name[] = "sys_status";

int32_t ulog_format_sys_status(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_sys_status_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_sys_status_format, sizeof(ulog_sys_status_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_sys_status(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_sys_status_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_sys_status_name, sizeof(ulog_sys_status_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_sys_status(ulog_t *log, ulog_msg_id_t id, const ulog_sys_status_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
                    + sizeof(uint32_t)
                    + sizeof(uint32_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(int16_t)
                    + sizeof(int8_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint32_t)
                    + sizeof(uint32_t)
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

    /* Bitmap showing which onboard controllers and sensors are present. Value of 0: not present. Value of 1: present. */
    if (lfs_file_write(log->lfs, log->file, &src->onboard_control_sensors_present, sizeof(src->onboard_control_sensors_present)) < 0) {
        return 1;
    }

    /* Bitmap showing which onboard controllers and sensors are enabled:  Value of 0: not enabled. Value of 1: enabled. */
    if (lfs_file_write(log->lfs, log->file, &src->onboard_control_sensors_enabled, sizeof(src->onboard_control_sensors_enabled)) < 0) {
        return 1;
    }

    /* Bitmap showing which onboard controllers and sensors have an error (or are operational). Value of 0: error. Value of 1: healthy. */
    if (lfs_file_write(log->lfs, log->file, &src->onboard_control_sensors_health, sizeof(src->onboard_control_sensors_health)) < 0) {
        return 1;
    }

    /* Maximum usage in percent of the mainloop time. Values: [0-1000] - should always be below 1000 [d%] */
    if (lfs_file_write(log->lfs, log->file, &src->load, sizeof(src->load)) < 0) {
        return 1;
    }

    /* Battery voltage, UINT16_MAX: Voltage not sent by autopilot [mV] */
    if (lfs_file_write(log->lfs, log->file, &src->voltage_battery, sizeof(src->voltage_battery)) < 0) {
        return 1;
    }

    /* Battery current, -1: Current not sent by autopilot [cA] */
    if (lfs_file_write(log->lfs, log->file, &src->current_battery, sizeof(src->current_battery)) < 0) {
        return 1;
    }

    /* Battery energy remaining, -1: Battery remaining energy not sent by autopilot [%] */
    if (lfs_file_write(log->lfs, log->file, &src->battery_remaining, sizeof(src->battery_remaining)) < 0) {
        return 1;
    }

    /* Communication drop rate, (UART, I2C, SPI, CAN), dropped packets on all links (packets that were corrupted on reception on the MAV) [c%] */
    if (lfs_file_write(log->lfs, log->file, &src->drop_rate_comm, sizeof(src->drop_rate_comm)) < 0) {
        return 1;
    }

    /* Communication errors (UART, I2C, SPI, CAN), dropped packets on all links (packets that were corrupted on reception on the MAV) */
    if (lfs_file_write(log->lfs, log->file, &src->errors_comm, sizeof(src->errors_comm)) < 0) {
        return 1;
    }

    /* Autopilot-specific errors */
    if (lfs_file_write(log->lfs, log->file, &src->errors_count1, sizeof(src->errors_count1)) < 0) {
        return 1;
    }

    /* Autopilot-specific errors */
    if (lfs_file_write(log->lfs, log->file, &src->errors_count2, sizeof(src->errors_count2)) < 0) {
        return 1;
    }

    /* Autopilot-specific errors */
    if (lfs_file_write(log->lfs, log->file, &src->errors_count3, sizeof(src->errors_count3)) < 0) {
        return 1;
    }

    /* Autopilot-specific errors */
    if (lfs_file_write(log->lfs, log->file, &src->errors_count4, sizeof(src->errors_count4)) < 0) {
        return 1;
    }

    /* Bitmap showing which onboard controllers and sensors are present. Value of 0: not present. Value of 1: present. */
    if (lfs_file_write(log->lfs, log->file, &src->onboard_control_sensors_present_extended, sizeof(src->onboard_control_sensors_present_extended)) < 0) {
        return 1;
    }

    /* Bitmap showing which onboard controllers and sensors are enabled:  Value of 0: not enabled. Value of 1: enabled. */
    if (lfs_file_write(log->lfs, log->file, &src->onboard_control_sensors_enabled_extended, sizeof(src->onboard_control_sensors_enabled_extended)) < 0) {
        return 1;
    }

    /* Bitmap showing which onboard controllers and sensors have an error (or are operational). Value of 0: error. Value of 1: healthy. */
    if (lfs_file_write(log->lfs, log->file, &src->onboard_control_sensors_health_extended, sizeof(src->onboard_control_sensors_health_extended)) < 0) {
        return 1;
    }

    
    return 0;
}
