/**
 * @file    ulog_lisum_power_motor_scaled_data.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_LISUM_POWER_MOTOR_SCALED_DATA_H
#define ULOG_LISUM_POWER_MOTOR_SCALED_DATA_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_lisum_power_motor_scaled_data_t {
    uint64_t timestamp; /* Timestamp [us] */
    float time; /* Engine time since turning on [s] */
    float w_gg; /* Angular Rate of Gas Generator [Hz] */
    float w_gg_N; /* Nominal Rate Velocity of Gas generator [Hz] */
    float w_ft; /* Angular Rate of Free Turbine [Hz] */
    float w_ft_N; /* Nominal Rate Velocity of Free Turbine [Hz] */
    uint16_t fuel_flow; /* Fuel Flow [cg/s] */
    uint16_t oil_flow_arm; /* Oil Flow - arm [cg/s] */
    uint16_t oil_flow_reducer; /* Oil Flow - reducer [cg/s] */
    uint16_t battery_volt; /* Battery voltage [mV] */
    int16_t temp_front_bearing; /* Temperature of front bearing [ddegC] */
    int16_t temp_rear_bearing; /* Temperature of rear bearing [ddegC] */
    int16_t temp_elastic_bearing; /* Temperature of elastic bearing [ddegC] */
    int16_t temp_rigid_bearing; /* Temperature of rigid bearing [ddegC] */
    int16_t temp_input_oil; /* Temperature of input oil [ddegC] */
    int16_t temp_arm_oil; /* Temperature of oil - arm [ddegC] */
    int16_t temp_reducer_oil; /* Temperature of oil - reducer [ddegC] */
    int16_t temp_exhaust_fume; /* Temperature of exhaust fumes [ddegC] */
    int16_t press_arm_oil; /* Oil pressure - arm [mbar] */
    int16_t fuel_level; /* Fuel level [cl] */
    uint16_t oil_level_bearing; /* Oil level - bearing [c%] */
    uint16_t oil_level_reducer; /* Oil level - reducer [c%] */
    uint16_t PWM_fuel_pump; /* Fuel pump PWM [c%] */
    uint16_t current_fuel_pump; /* Fuel pump current [cA] */
    uint16_t PWM_oil_pump; /* Oil pump PWM [c%] */
    uint16_t current_oil_pump; /* Oil pump current [cA] */
    uint16_t PWM_oil_suction_pump_reducer; /* Suction pump (reducer) PWM [c%] */
    uint16_t PWM_oil_suction_pump_arm; /* Suction pump (arm) PWM [c%] */
    uint16_t PWM_oil_pressure_pump; /* Oil pressure pump PWM [c%] */
    uint8_t activate; /* Activate Struct */
    uint16_t turn_on; /* Turn ON Struct */
    uint8_t valve_state; /* Valve State */
    uint8_t pressure_state; /* Pressure State */
    uint32_t warning; /* Warning Struct */
    uint32_t error; /* Error Struct */
    uint8_t EvnC[8]; /* EvnC Struct */
    uint8_t res[8]; /* Reserved for future */
    
} ulog_lisum_power_motor_scaled_data_t;

/**
 * Defines Lisum Power Motor Scaled Data message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_lisum_power_motor_scaled_data(ulog_t *log);

/**
 * Subscribe Lisum Power Motor Scaled Data message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_lisum_power_motor_scaled_data(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Lisum Power Motor Scaled Data message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_lisum_power_motor_scaled_data(ulog_t *log, ulog_msg_id_t id, const ulog_lisum_power_motor_scaled_data_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_LISUM_POWER_MOTOR_SCALED_DATA_H */