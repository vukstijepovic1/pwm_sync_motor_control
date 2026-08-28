/**
 * @file    ulog_efi_status.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_efi_status.h"
#include "ulog_def.h"

const char ulog_efi_status_format[] = "efi_status:uint64_t timestamp;uint8_t health;float ecu_index;float rpm;float fuel_consumed;float fuel_flow;float engine_load;float throttle_position;float spark_dwell_time;float barometric_pressure;float intake_manifold_pressure;float intake_manifold_temperature;float cylinder_head_temperature;float ignition_timing;float injection_time;float exhaust_gas_temperature;float throttle_out;float pt_compensation;float ignition_voltage;float fuel_pressure;";
const char ulog_efi_status_name[] = "efi_status";

int32_t ulog_format_efi_status(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_efi_status_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_efi_status_format, sizeof(ulog_efi_status_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_efi_status(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_efi_status_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_efi_status_name, sizeof(ulog_efi_status_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_efi_status(ulog_t *log, ulog_msg_id_t id, const ulog_efi_status_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
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
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
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

    /* EFI health status */
    if (lfs_file_write(log->lfs, log->file, &src->health, sizeof(src->health)) < 0) {
        return 1;
    }

    /* ECU index */
    if (lfs_file_write(log->lfs, log->file, &src->ecu_index, sizeof(src->ecu_index)) < 0) {
        return 1;
    }

    /* RPM */
    if (lfs_file_write(log->lfs, log->file, &src->rpm, sizeof(src->rpm)) < 0) {
        return 1;
    }

    /* Fuel consumed [cm^3] */
    if (lfs_file_write(log->lfs, log->file, &src->fuel_consumed, sizeof(src->fuel_consumed)) < 0) {
        return 1;
    }

    /* Fuel flow rate [cm^3/min] */
    if (lfs_file_write(log->lfs, log->file, &src->fuel_flow, sizeof(src->fuel_flow)) < 0) {
        return 1;
    }

    /* Engine load [%] */
    if (lfs_file_write(log->lfs, log->file, &src->engine_load, sizeof(src->engine_load)) < 0) {
        return 1;
    }

    /* Throttle position [%] */
    if (lfs_file_write(log->lfs, log->file, &src->throttle_position, sizeof(src->throttle_position)) < 0) {
        return 1;
    }

    /* Spark dwell time [ms] */
    if (lfs_file_write(log->lfs, log->file, &src->spark_dwell_time, sizeof(src->spark_dwell_time)) < 0) {
        return 1;
    }

    /* Barometric pressure [kPa] */
    if (lfs_file_write(log->lfs, log->file, &src->barometric_pressure, sizeof(src->barometric_pressure)) < 0) {
        return 1;
    }

    /* Intake manifold pressure( [kPa] */
    if (lfs_file_write(log->lfs, log->file, &src->intake_manifold_pressure, sizeof(src->intake_manifold_pressure)) < 0) {
        return 1;
    }

    /* Intake manifold temperature [degC] */
    if (lfs_file_write(log->lfs, log->file, &src->intake_manifold_temperature, sizeof(src->intake_manifold_temperature)) < 0) {
        return 1;
    }

    /* Cylinder head temperature [degC] */
    if (lfs_file_write(log->lfs, log->file, &src->cylinder_head_temperature, sizeof(src->cylinder_head_temperature)) < 0) {
        return 1;
    }

    /* Ignition timing (Crank angle degrees) [deg] */
    if (lfs_file_write(log->lfs, log->file, &src->ignition_timing, sizeof(src->ignition_timing)) < 0) {
        return 1;
    }

    /* Injection time [ms] */
    if (lfs_file_write(log->lfs, log->file, &src->injection_time, sizeof(src->injection_time)) < 0) {
        return 1;
    }

    /* Exhaust gas temperature [degC] */
    if (lfs_file_write(log->lfs, log->file, &src->exhaust_gas_temperature, sizeof(src->exhaust_gas_temperature)) < 0) {
        return 1;
    }

    /* Output throttle [%] */
    if (lfs_file_write(log->lfs, log->file, &src->throttle_out, sizeof(src->throttle_out)) < 0) {
        return 1;
    }

    /* Pressure/temperature compensation */
    if (lfs_file_write(log->lfs, log->file, &src->pt_compensation, sizeof(src->pt_compensation)) < 0) {
        return 1;
    }

    /* Supply voltage to EFI sparking system.  Zero in this value means "unknown", so if the supply voltage really is zero volts use 0.0001 instead. [V] */
    if (lfs_file_write(log->lfs, log->file, &src->ignition_voltage, sizeof(src->ignition_voltage)) < 0) {
        return 1;
    }

    /* Fuel pressure. Zero in this value means "unknown", so if the fuel pressure really is zero kPa use 0.0001 instead. [kPa] */
    if (lfs_file_write(log->lfs, log->file, &src->fuel_pressure, sizeof(src->fuel_pressure)) < 0) {
        return 1;
    }

    
    return 0;
}
