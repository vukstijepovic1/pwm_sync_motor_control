/**
 * @file    ulog_lisum_power_motor_scaled_data.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_lisum_power_motor_scaled_data.h"
#include "ulog_def.h"

const char ulog_lisum_power_motor_scaled_data_format[] = "lisum_power_motor_scaled_data:uint64_t timestamp;float time;float w_gg;float w_gg_N;float w_ft;float w_ft_N;uint16_t fuel_flow;uint16_t oil_flow_arm;uint16_t oil_flow_reducer;uint16_t battery_volt;int16_t temp_front_bearing;int16_t temp_rear_bearing;int16_t temp_elastic_bearing;int16_t temp_rigid_bearing;int16_t temp_input_oil;int16_t temp_arm_oil;int16_t temp_reducer_oil;int16_t temp_exhaust_fume;int16_t press_arm_oil;int16_t fuel_level;uint16_t oil_level_bearing;uint16_t oil_level_reducer;uint16_t PWM_fuel_pump;uint16_t current_fuel_pump;uint16_t PWM_oil_pump;uint16_t current_oil_pump;uint16_t PWM_oil_suction_pump_reducer;uint16_t PWM_oil_suction_pump_arm;uint16_t PWM_oil_pressure_pump;uint8_t activate;uint16_t turn_on;uint8_t valve_state;uint8_t pressure_state;uint32_t warning;uint32_t error;uint8_t[8] EvnC;uint8_t[8] res;";
const char ulog_lisum_power_motor_scaled_data_name[] = "lisum_power_motor_scaled_data";

int32_t ulog_format_lisum_power_motor_scaled_data(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_lisum_power_motor_scaled_data_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_lisum_power_motor_scaled_data_format, sizeof(ulog_lisum_power_motor_scaled_data_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_lisum_power_motor_scaled_data(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_lisum_power_motor_scaled_data_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_lisum_power_motor_scaled_data_name, sizeof(ulog_lisum_power_motor_scaled_data_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_lisum_power_motor_scaled_data(ulog_t *log, ulog_msg_id_t id, const ulog_lisum_power_motor_scaled_data_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint8_t)
                    + sizeof(uint16_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint32_t)
                    + sizeof(uint32_t)
                    + sizeof(uint8_t)*8
                    + sizeof(uint8_t)*8
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

    /* Engine time since turning on [s] */
    if (lfs_file_write(log->lfs, log->file, &src->time, sizeof(src->time)) < 0) {
        return 1;
    }

    /* Angular Rate of Gas Generator [Hz] */
    if (lfs_file_write(log->lfs, log->file, &src->w_gg, sizeof(src->w_gg)) < 0) {
        return 1;
    }

    /* Nominal Rate Velocity of Gas generator [Hz] */
    if (lfs_file_write(log->lfs, log->file, &src->w_gg_N, sizeof(src->w_gg_N)) < 0) {
        return 1;
    }

    /* Angular Rate of Free Turbine [Hz] */
    if (lfs_file_write(log->lfs, log->file, &src->w_ft, sizeof(src->w_ft)) < 0) {
        return 1;
    }

    /* Nominal Rate Velocity of Free Turbine [Hz] */
    if (lfs_file_write(log->lfs, log->file, &src->w_ft_N, sizeof(src->w_ft_N)) < 0) {
        return 1;
    }

    /* Fuel Flow [cg/s] */
    if (lfs_file_write(log->lfs, log->file, &src->fuel_flow, sizeof(src->fuel_flow)) < 0) {
        return 1;
    }

    /* Oil Flow - arm [cg/s] */
    if (lfs_file_write(log->lfs, log->file, &src->oil_flow_arm, sizeof(src->oil_flow_arm)) < 0) {
        return 1;
    }

    /* Oil Flow - reducer [cg/s] */
    if (lfs_file_write(log->lfs, log->file, &src->oil_flow_reducer, sizeof(src->oil_flow_reducer)) < 0) {
        return 1;
    }

    /* Battery voltage [mV] */
    if (lfs_file_write(log->lfs, log->file, &src->battery_volt, sizeof(src->battery_volt)) < 0) {
        return 1;
    }

    /* Temperature of front bearing [ddegC] */
    if (lfs_file_write(log->lfs, log->file, &src->temp_front_bearing, sizeof(src->temp_front_bearing)) < 0) {
        return 1;
    }

    /* Temperature of rear bearing [ddegC] */
    if (lfs_file_write(log->lfs, log->file, &src->temp_rear_bearing, sizeof(src->temp_rear_bearing)) < 0) {
        return 1;
    }

    /* Temperature of elastic bearing [ddegC] */
    if (lfs_file_write(log->lfs, log->file, &src->temp_elastic_bearing, sizeof(src->temp_elastic_bearing)) < 0) {
        return 1;
    }

    /* Temperature of rigid bearing [ddegC] */
    if (lfs_file_write(log->lfs, log->file, &src->temp_rigid_bearing, sizeof(src->temp_rigid_bearing)) < 0) {
        return 1;
    }

    /* Temperature of input oil [ddegC] */
    if (lfs_file_write(log->lfs, log->file, &src->temp_input_oil, sizeof(src->temp_input_oil)) < 0) {
        return 1;
    }

    /* Temperature of oil - arm [ddegC] */
    if (lfs_file_write(log->lfs, log->file, &src->temp_arm_oil, sizeof(src->temp_arm_oil)) < 0) {
        return 1;
    }

    /* Temperature of oil - reducer [ddegC] */
    if (lfs_file_write(log->lfs, log->file, &src->temp_reducer_oil, sizeof(src->temp_reducer_oil)) < 0) {
        return 1;
    }

    /* Temperature of exhaust fumes [ddegC] */
    if (lfs_file_write(log->lfs, log->file, &src->temp_exhaust_fume, sizeof(src->temp_exhaust_fume)) < 0) {
        return 1;
    }

    /* Oil pressure - arm [mbar] */
    if (lfs_file_write(log->lfs, log->file, &src->press_arm_oil, sizeof(src->press_arm_oil)) < 0) {
        return 1;
    }

    /* Fuel level [cl] */
    if (lfs_file_write(log->lfs, log->file, &src->fuel_level, sizeof(src->fuel_level)) < 0) {
        return 1;
    }

    /* Oil level - bearing [c%] */
    if (lfs_file_write(log->lfs, log->file, &src->oil_level_bearing, sizeof(src->oil_level_bearing)) < 0) {
        return 1;
    }

    /* Oil level - reducer [c%] */
    if (lfs_file_write(log->lfs, log->file, &src->oil_level_reducer, sizeof(src->oil_level_reducer)) < 0) {
        return 1;
    }

    /* Fuel pump PWM [c%] */
    if (lfs_file_write(log->lfs, log->file, &src->PWM_fuel_pump, sizeof(src->PWM_fuel_pump)) < 0) {
        return 1;
    }

    /* Fuel pump current [cA] */
    if (lfs_file_write(log->lfs, log->file, &src->current_fuel_pump, sizeof(src->current_fuel_pump)) < 0) {
        return 1;
    }

    /* Oil pump PWM [c%] */
    if (lfs_file_write(log->lfs, log->file, &src->PWM_oil_pump, sizeof(src->PWM_oil_pump)) < 0) {
        return 1;
    }

    /* Oil pump current [cA] */
    if (lfs_file_write(log->lfs, log->file, &src->current_oil_pump, sizeof(src->current_oil_pump)) < 0) {
        return 1;
    }

    /* Suction pump (reducer) PWM [c%] */
    if (lfs_file_write(log->lfs, log->file, &src->PWM_oil_suction_pump_reducer, sizeof(src->PWM_oil_suction_pump_reducer)) < 0) {
        return 1;
    }

    /* Suction pump (arm) PWM [c%] */
    if (lfs_file_write(log->lfs, log->file, &src->PWM_oil_suction_pump_arm, sizeof(src->PWM_oil_suction_pump_arm)) < 0) {
        return 1;
    }

    /* Oil pressure pump PWM [c%] */
    if (lfs_file_write(log->lfs, log->file, &src->PWM_oil_pressure_pump, sizeof(src->PWM_oil_pressure_pump)) < 0) {
        return 1;
    }

    /* Activate Struct */
    if (lfs_file_write(log->lfs, log->file, &src->activate, sizeof(src->activate)) < 0) {
        return 1;
    }

    /* Turn ON Struct */
    if (lfs_file_write(log->lfs, log->file, &src->turn_on, sizeof(src->turn_on)) < 0) {
        return 1;
    }

    /* Valve State */
    if (lfs_file_write(log->lfs, log->file, &src->valve_state, sizeof(src->valve_state)) < 0) {
        return 1;
    }

    /* Pressure State */
    if (lfs_file_write(log->lfs, log->file, &src->pressure_state, sizeof(src->pressure_state)) < 0) {
        return 1;
    }

    /* Warning Struct */
    if (lfs_file_write(log->lfs, log->file, &src->warning, sizeof(src->warning)) < 0) {
        return 1;
    }

    /* Error Struct */
    if (lfs_file_write(log->lfs, log->file, &src->error, sizeof(src->error)) < 0) {
        return 1;
    }

    /* EvnC Struct */
    if (lfs_file_write(log->lfs, log->file, src->EvnC, sizeof(src->EvnC)) < 0) {
        return 1;
    }

    /* Reserved for future */
    if (lfs_file_write(log->lfs, log->file, src->res, sizeof(src->res)) < 0) {
        return 1;
    }

    
    return 0;
}
