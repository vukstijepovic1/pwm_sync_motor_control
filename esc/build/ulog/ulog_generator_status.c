/**
 * @file    ulog_generator_status.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_generator_status.h"
#include "ulog_def.h"

const char ulog_generator_status_format[] = "generator_status:uint64_t timestamp;uint64_t status;uint16_t generator_speed;float battery_current;float load_current;float power_generated;float bus_voltage;int16_t rectifier_temperature;float bat_current_setpoint;int16_t generator_temperature;uint32_t runtime;int32_t time_until_maintenance;";
const char ulog_generator_status_name[] = "generator_status";

int32_t ulog_format_generator_status(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_generator_status_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_generator_status_format, sizeof(ulog_generator_status_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_generator_status(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_generator_status_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_generator_status_name, sizeof(ulog_generator_status_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_generator_status(ulog_t *log, ulog_msg_id_t id, const ulog_generator_status_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint64_t)
                    + sizeof(uint16_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(int16_t)
                    + sizeof(float)
                    + sizeof(int16_t)
                    + sizeof(uint32_t)
                    + sizeof(int32_t)
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

    /* Status flags. */
    if (lfs_file_write(log->lfs, log->file, &src->status, sizeof(src->status)) < 0) {
        return 1;
    }

    /* Speed of electrical generator or alternator. UINT16_MAX: field not provided. [rpm] */
    if (lfs_file_write(log->lfs, log->file, &src->generator_speed, sizeof(src->generator_speed)) < 0) {
        return 1;
    }

    /* Current into/out of battery. Positive for out. Negative for in. NaN: field not provided. [A] */
    if (lfs_file_write(log->lfs, log->file, &src->battery_current, sizeof(src->battery_current)) < 0) {
        return 1;
    }

    /* Current going to the UAV. If battery current not available this is the DC current from the generator. Positive for out. Negative for in. NaN: field not provided [A] */
    if (lfs_file_write(log->lfs, log->file, &src->load_current, sizeof(src->load_current)) < 0) {
        return 1;
    }

    /* The power being generated. NaN: field not provided [W] */
    if (lfs_file_write(log->lfs, log->file, &src->power_generated, sizeof(src->power_generated)) < 0) {
        return 1;
    }

    /* Voltage of the bus seen at the generator, or battery bus if battery bus is controlled by generator and at a different voltage to main bus. [V] */
    if (lfs_file_write(log->lfs, log->file, &src->bus_voltage, sizeof(src->bus_voltage)) < 0) {
        return 1;
    }

    /* The temperature of the rectifier or power converter. INT16_MAX: field not provided. [degC] */
    if (lfs_file_write(log->lfs, log->file, &src->rectifier_temperature, sizeof(src->rectifier_temperature)) < 0) {
        return 1;
    }

    /* The target battery current. Positive for out. Negative for in. NaN: field not provided [A] */
    if (lfs_file_write(log->lfs, log->file, &src->bat_current_setpoint, sizeof(src->bat_current_setpoint)) < 0) {
        return 1;
    }

    /* The temperature of the mechanical motor, fuel cell core or generator. INT16_MAX: field not provided. [degC] */
    if (lfs_file_write(log->lfs, log->file, &src->generator_temperature, sizeof(src->generator_temperature)) < 0) {
        return 1;
    }

    /* Seconds this generator has run since it was rebooted. UINT32_MAX: field not provided. [s] */
    if (lfs_file_write(log->lfs, log->file, &src->runtime, sizeof(src->runtime)) < 0) {
        return 1;
    }

    /* Seconds until this generator requires maintenance.  A negative value indicates maintenance is past-due. INT32_MAX: field not provided. [s] */
    if (lfs_file_write(log->lfs, log->file, &src->time_until_maintenance, sizeof(src->time_until_maintenance)) < 0) {
        return 1;
    }

    
    return 0;
}
