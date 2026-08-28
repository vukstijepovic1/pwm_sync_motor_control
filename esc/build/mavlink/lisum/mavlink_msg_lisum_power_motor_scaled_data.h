#pragma once
// MESSAGE LISUM_POWER_MOTOR_SCALED_DATA PACKING

#define MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA 59073


typedef struct __mavlink_lisum_power_motor_scaled_data_t {
 float time; /*< [s] Engine time since turning on*/
 float w_gg; /*< [Hz] Angular Rate of Gas Generator*/
 float w_gg_N; /*< [Hz] Nominal Rate Velocity of Gas generator*/
 float w_ft; /*< [Hz] Angular Rate of Free Turbine*/
 float w_ft_N; /*< [Hz] Nominal Rate Velocity of Free Turbine*/
 uint32_t warning; /*<  Warning Struct*/
 uint32_t error; /*<  Error Struct*/
 uint16_t fuel_flow; /*<  Fuel Flow [cg/s]*/
 uint16_t oil_flow_arm; /*<  Oil Flow - arm [cg/s]*/
 uint16_t oil_flow_reducer; /*<  Oil Flow - reducer [cg/s]*/
 uint16_t battery_volt; /*< [mV] Battery voltage*/
 int16_t temp_front_bearing; /*<  Temperature of front bearing [ddegC]*/
 int16_t temp_rear_bearing; /*<  Temperature of rear bearing [ddegC]*/
 int16_t temp_elastic_bearing; /*<  Temperature of elastic bearing [ddegC]*/
 int16_t temp_rigid_bearing; /*<  Temperature of rigid bearing [ddegC]*/
 int16_t temp_input_oil; /*<  Temperature of input oil [ddegC]*/
 int16_t temp_arm_oil; /*<  Temperature of oil - arm [ddegC]*/
 int16_t temp_reducer_oil; /*<  Temperature of oil - reducer [ddegC]*/
 int16_t temp_exhaust_fume; /*<  Temperature of exhaust fumes [ddegC]*/
 int16_t press_arm_oil; /*< [mbar] Oil pressure - arm*/
 int16_t fuel_level; /*<  Fuel level [cl]*/
 uint16_t oil_level_bearing; /*< [c%] Oil level - bearing*/
 uint16_t oil_level_reducer; /*< [c%] Oil level - reducer*/
 uint16_t PWM_fuel_pump; /*< [c%] Fuel pump PWM*/
 uint16_t current_fuel_pump; /*< [cA] Fuel pump current*/
 uint16_t PWM_oil_pump; /*< [c%] Oil pump PWM*/
 uint16_t current_oil_pump; /*< [cA] Oil pump current*/
 uint16_t PWM_oil_suction_pump_reducer; /*< [c%] Suction pump (reducer) PWM*/
 uint16_t PWM_oil_suction_pump_arm; /*< [c%] Suction pump (arm) PWM*/
 uint16_t PWM_oil_pressure_pump; /*< [c%] Oil pressure pump PWM*/
 uint16_t turn_on; /*<  Turn ON Struct*/
 uint8_t activate; /*<  Activate Struct*/
 uint8_t valve_state; /*<  Valve State*/
 uint8_t pressure_state; /*<  Pressure State*/
 uint8_t EvnC[8]; /*<  EvnC Struct*/
 uint8_t res[8]; /*<  Reserved for future*/
} mavlink_lisum_power_motor_scaled_data_t;

#define MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_LEN 95
#define MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_MIN_LEN 95
#define MAVLINK_MSG_ID_59073_LEN 95
#define MAVLINK_MSG_ID_59073_MIN_LEN 95

#define MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_CRC 39
#define MAVLINK_MSG_ID_59073_CRC 39

#define MAVLINK_MSG_LISUM_POWER_MOTOR_SCALED_DATA_FIELD_EVNC_LEN 8
#define MAVLINK_MSG_LISUM_POWER_MOTOR_SCALED_DATA_FIELD_RES_LEN 8

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_LISUM_POWER_MOTOR_SCALED_DATA { \
    59073, \
    "LISUM_POWER_MOTOR_SCALED_DATA", \
    36, \
    {  { "time", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_lisum_power_motor_scaled_data_t, time) }, \
         { "w_gg", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_lisum_power_motor_scaled_data_t, w_gg) }, \
         { "w_gg_N", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_lisum_power_motor_scaled_data_t, w_gg_N) }, \
         { "w_ft", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_lisum_power_motor_scaled_data_t, w_ft) }, \
         { "w_ft_N", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_lisum_power_motor_scaled_data_t, w_ft_N) }, \
         { "fuel_flow", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_lisum_power_motor_scaled_data_t, fuel_flow) }, \
         { "oil_flow_arm", NULL, MAVLINK_TYPE_UINT16_T, 0, 30, offsetof(mavlink_lisum_power_motor_scaled_data_t, oil_flow_arm) }, \
         { "oil_flow_reducer", NULL, MAVLINK_TYPE_UINT16_T, 0, 32, offsetof(mavlink_lisum_power_motor_scaled_data_t, oil_flow_reducer) }, \
         { "battery_volt", NULL, MAVLINK_TYPE_UINT16_T, 0, 34, offsetof(mavlink_lisum_power_motor_scaled_data_t, battery_volt) }, \
         { "temp_front_bearing", NULL, MAVLINK_TYPE_INT16_T, 0, 36, offsetof(mavlink_lisum_power_motor_scaled_data_t, temp_front_bearing) }, \
         { "temp_rear_bearing", NULL, MAVLINK_TYPE_INT16_T, 0, 38, offsetof(mavlink_lisum_power_motor_scaled_data_t, temp_rear_bearing) }, \
         { "temp_elastic_bearing", NULL, MAVLINK_TYPE_INT16_T, 0, 40, offsetof(mavlink_lisum_power_motor_scaled_data_t, temp_elastic_bearing) }, \
         { "temp_rigid_bearing", NULL, MAVLINK_TYPE_INT16_T, 0, 42, offsetof(mavlink_lisum_power_motor_scaled_data_t, temp_rigid_bearing) }, \
         { "temp_input_oil", NULL, MAVLINK_TYPE_INT16_T, 0, 44, offsetof(mavlink_lisum_power_motor_scaled_data_t, temp_input_oil) }, \
         { "temp_arm_oil", NULL, MAVLINK_TYPE_INT16_T, 0, 46, offsetof(mavlink_lisum_power_motor_scaled_data_t, temp_arm_oil) }, \
         { "temp_reducer_oil", NULL, MAVLINK_TYPE_INT16_T, 0, 48, offsetof(mavlink_lisum_power_motor_scaled_data_t, temp_reducer_oil) }, \
         { "temp_exhaust_fume", NULL, MAVLINK_TYPE_INT16_T, 0, 50, offsetof(mavlink_lisum_power_motor_scaled_data_t, temp_exhaust_fume) }, \
         { "press_arm_oil", NULL, MAVLINK_TYPE_INT16_T, 0, 52, offsetof(mavlink_lisum_power_motor_scaled_data_t, press_arm_oil) }, \
         { "fuel_level", NULL, MAVLINK_TYPE_INT16_T, 0, 54, offsetof(mavlink_lisum_power_motor_scaled_data_t, fuel_level) }, \
         { "oil_level_bearing", NULL, MAVLINK_TYPE_UINT16_T, 0, 56, offsetof(mavlink_lisum_power_motor_scaled_data_t, oil_level_bearing) }, \
         { "oil_level_reducer", NULL, MAVLINK_TYPE_UINT16_T, 0, 58, offsetof(mavlink_lisum_power_motor_scaled_data_t, oil_level_reducer) }, \
         { "PWM_fuel_pump", NULL, MAVLINK_TYPE_UINT16_T, 0, 60, offsetof(mavlink_lisum_power_motor_scaled_data_t, PWM_fuel_pump) }, \
         { "current_fuel_pump", NULL, MAVLINK_TYPE_UINT16_T, 0, 62, offsetof(mavlink_lisum_power_motor_scaled_data_t, current_fuel_pump) }, \
         { "PWM_oil_pump", NULL, MAVLINK_TYPE_UINT16_T, 0, 64, offsetof(mavlink_lisum_power_motor_scaled_data_t, PWM_oil_pump) }, \
         { "current_oil_pump", NULL, MAVLINK_TYPE_UINT16_T, 0, 66, offsetof(mavlink_lisum_power_motor_scaled_data_t, current_oil_pump) }, \
         { "PWM_oil_suction_pump_reducer", NULL, MAVLINK_TYPE_UINT16_T, 0, 68, offsetof(mavlink_lisum_power_motor_scaled_data_t, PWM_oil_suction_pump_reducer) }, \
         { "PWM_oil_suction_pump_arm", NULL, MAVLINK_TYPE_UINT16_T, 0, 70, offsetof(mavlink_lisum_power_motor_scaled_data_t, PWM_oil_suction_pump_arm) }, \
         { "PWM_oil_pressure_pump", NULL, MAVLINK_TYPE_UINT16_T, 0, 72, offsetof(mavlink_lisum_power_motor_scaled_data_t, PWM_oil_pressure_pump) }, \
         { "activate", NULL, MAVLINK_TYPE_UINT8_T, 0, 76, offsetof(mavlink_lisum_power_motor_scaled_data_t, activate) }, \
         { "turn_on", NULL, MAVLINK_TYPE_UINT16_T, 0, 74, offsetof(mavlink_lisum_power_motor_scaled_data_t, turn_on) }, \
         { "valve_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 77, offsetof(mavlink_lisum_power_motor_scaled_data_t, valve_state) }, \
         { "pressure_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 78, offsetof(mavlink_lisum_power_motor_scaled_data_t, pressure_state) }, \
         { "warning", NULL, MAVLINK_TYPE_UINT32_T, 0, 20, offsetof(mavlink_lisum_power_motor_scaled_data_t, warning) }, \
         { "error", NULL, MAVLINK_TYPE_UINT32_T, 0, 24, offsetof(mavlink_lisum_power_motor_scaled_data_t, error) }, \
         { "EvnC", NULL, MAVLINK_TYPE_UINT8_T, 8, 79, offsetof(mavlink_lisum_power_motor_scaled_data_t, EvnC) }, \
         { "res", NULL, MAVLINK_TYPE_UINT8_T, 8, 87, offsetof(mavlink_lisum_power_motor_scaled_data_t, res) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_LISUM_POWER_MOTOR_SCALED_DATA { \
    "LISUM_POWER_MOTOR_SCALED_DATA", \
    36, \
    {  { "time", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_lisum_power_motor_scaled_data_t, time) }, \
         { "w_gg", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_lisum_power_motor_scaled_data_t, w_gg) }, \
         { "w_gg_N", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_lisum_power_motor_scaled_data_t, w_gg_N) }, \
         { "w_ft", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_lisum_power_motor_scaled_data_t, w_ft) }, \
         { "w_ft_N", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_lisum_power_motor_scaled_data_t, w_ft_N) }, \
         { "fuel_flow", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_lisum_power_motor_scaled_data_t, fuel_flow) }, \
         { "oil_flow_arm", NULL, MAVLINK_TYPE_UINT16_T, 0, 30, offsetof(mavlink_lisum_power_motor_scaled_data_t, oil_flow_arm) }, \
         { "oil_flow_reducer", NULL, MAVLINK_TYPE_UINT16_T, 0, 32, offsetof(mavlink_lisum_power_motor_scaled_data_t, oil_flow_reducer) }, \
         { "battery_volt", NULL, MAVLINK_TYPE_UINT16_T, 0, 34, offsetof(mavlink_lisum_power_motor_scaled_data_t, battery_volt) }, \
         { "temp_front_bearing", NULL, MAVLINK_TYPE_INT16_T, 0, 36, offsetof(mavlink_lisum_power_motor_scaled_data_t, temp_front_bearing) }, \
         { "temp_rear_bearing", NULL, MAVLINK_TYPE_INT16_T, 0, 38, offsetof(mavlink_lisum_power_motor_scaled_data_t, temp_rear_bearing) }, \
         { "temp_elastic_bearing", NULL, MAVLINK_TYPE_INT16_T, 0, 40, offsetof(mavlink_lisum_power_motor_scaled_data_t, temp_elastic_bearing) }, \
         { "temp_rigid_bearing", NULL, MAVLINK_TYPE_INT16_T, 0, 42, offsetof(mavlink_lisum_power_motor_scaled_data_t, temp_rigid_bearing) }, \
         { "temp_input_oil", NULL, MAVLINK_TYPE_INT16_T, 0, 44, offsetof(mavlink_lisum_power_motor_scaled_data_t, temp_input_oil) }, \
         { "temp_arm_oil", NULL, MAVLINK_TYPE_INT16_T, 0, 46, offsetof(mavlink_lisum_power_motor_scaled_data_t, temp_arm_oil) }, \
         { "temp_reducer_oil", NULL, MAVLINK_TYPE_INT16_T, 0, 48, offsetof(mavlink_lisum_power_motor_scaled_data_t, temp_reducer_oil) }, \
         { "temp_exhaust_fume", NULL, MAVLINK_TYPE_INT16_T, 0, 50, offsetof(mavlink_lisum_power_motor_scaled_data_t, temp_exhaust_fume) }, \
         { "press_arm_oil", NULL, MAVLINK_TYPE_INT16_T, 0, 52, offsetof(mavlink_lisum_power_motor_scaled_data_t, press_arm_oil) }, \
         { "fuel_level", NULL, MAVLINK_TYPE_INT16_T, 0, 54, offsetof(mavlink_lisum_power_motor_scaled_data_t, fuel_level) }, \
         { "oil_level_bearing", NULL, MAVLINK_TYPE_UINT16_T, 0, 56, offsetof(mavlink_lisum_power_motor_scaled_data_t, oil_level_bearing) }, \
         { "oil_level_reducer", NULL, MAVLINK_TYPE_UINT16_T, 0, 58, offsetof(mavlink_lisum_power_motor_scaled_data_t, oil_level_reducer) }, \
         { "PWM_fuel_pump", NULL, MAVLINK_TYPE_UINT16_T, 0, 60, offsetof(mavlink_lisum_power_motor_scaled_data_t, PWM_fuel_pump) }, \
         { "current_fuel_pump", NULL, MAVLINK_TYPE_UINT16_T, 0, 62, offsetof(mavlink_lisum_power_motor_scaled_data_t, current_fuel_pump) }, \
         { "PWM_oil_pump", NULL, MAVLINK_TYPE_UINT16_T, 0, 64, offsetof(mavlink_lisum_power_motor_scaled_data_t, PWM_oil_pump) }, \
         { "current_oil_pump", NULL, MAVLINK_TYPE_UINT16_T, 0, 66, offsetof(mavlink_lisum_power_motor_scaled_data_t, current_oil_pump) }, \
         { "PWM_oil_suction_pump_reducer", NULL, MAVLINK_TYPE_UINT16_T, 0, 68, offsetof(mavlink_lisum_power_motor_scaled_data_t, PWM_oil_suction_pump_reducer) }, \
         { "PWM_oil_suction_pump_arm", NULL, MAVLINK_TYPE_UINT16_T, 0, 70, offsetof(mavlink_lisum_power_motor_scaled_data_t, PWM_oil_suction_pump_arm) }, \
         { "PWM_oil_pressure_pump", NULL, MAVLINK_TYPE_UINT16_T, 0, 72, offsetof(mavlink_lisum_power_motor_scaled_data_t, PWM_oil_pressure_pump) }, \
         { "activate", NULL, MAVLINK_TYPE_UINT8_T, 0, 76, offsetof(mavlink_lisum_power_motor_scaled_data_t, activate) }, \
         { "turn_on", NULL, MAVLINK_TYPE_UINT16_T, 0, 74, offsetof(mavlink_lisum_power_motor_scaled_data_t, turn_on) }, \
         { "valve_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 77, offsetof(mavlink_lisum_power_motor_scaled_data_t, valve_state) }, \
         { "pressure_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 78, offsetof(mavlink_lisum_power_motor_scaled_data_t, pressure_state) }, \
         { "warning", NULL, MAVLINK_TYPE_UINT32_T, 0, 20, offsetof(mavlink_lisum_power_motor_scaled_data_t, warning) }, \
         { "error", NULL, MAVLINK_TYPE_UINT32_T, 0, 24, offsetof(mavlink_lisum_power_motor_scaled_data_t, error) }, \
         { "EvnC", NULL, MAVLINK_TYPE_UINT8_T, 8, 79, offsetof(mavlink_lisum_power_motor_scaled_data_t, EvnC) }, \
         { "res", NULL, MAVLINK_TYPE_UINT8_T, 8, 87, offsetof(mavlink_lisum_power_motor_scaled_data_t, res) }, \
         } \
}
#endif

/**
 * @brief Pack a lisum_power_motor_scaled_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time [s] Engine time since turning on
 * @param w_gg [Hz] Angular Rate of Gas Generator
 * @param w_gg_N [Hz] Nominal Rate Velocity of Gas generator
 * @param w_ft [Hz] Angular Rate of Free Turbine
 * @param w_ft_N [Hz] Nominal Rate Velocity of Free Turbine
 * @param fuel_flow  Fuel Flow [cg/s]
 * @param oil_flow_arm  Oil Flow - arm [cg/s]
 * @param oil_flow_reducer  Oil Flow - reducer [cg/s]
 * @param battery_volt [mV] Battery voltage
 * @param temp_front_bearing  Temperature of front bearing [ddegC]
 * @param temp_rear_bearing  Temperature of rear bearing [ddegC]
 * @param temp_elastic_bearing  Temperature of elastic bearing [ddegC]
 * @param temp_rigid_bearing  Temperature of rigid bearing [ddegC]
 * @param temp_input_oil  Temperature of input oil [ddegC]
 * @param temp_arm_oil  Temperature of oil - arm [ddegC]
 * @param temp_reducer_oil  Temperature of oil - reducer [ddegC]
 * @param temp_exhaust_fume  Temperature of exhaust fumes [ddegC]
 * @param press_arm_oil [mbar] Oil pressure - arm
 * @param fuel_level  Fuel level [cl]
 * @param oil_level_bearing [c%] Oil level - bearing
 * @param oil_level_reducer [c%] Oil level - reducer
 * @param PWM_fuel_pump [c%] Fuel pump PWM
 * @param current_fuel_pump [cA] Fuel pump current
 * @param PWM_oil_pump [c%] Oil pump PWM
 * @param current_oil_pump [cA] Oil pump current
 * @param PWM_oil_suction_pump_reducer [c%] Suction pump (reducer) PWM
 * @param PWM_oil_suction_pump_arm [c%] Suction pump (arm) PWM
 * @param PWM_oil_pressure_pump [c%] Oil pressure pump PWM
 * @param activate  Activate Struct
 * @param turn_on  Turn ON Struct
 * @param valve_state  Valve State
 * @param pressure_state  Pressure State
 * @param warning  Warning Struct
 * @param error  Error Struct
 * @param EvnC  EvnC Struct
 * @param res  Reserved for future
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_power_motor_scaled_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float time, float w_gg, float w_gg_N, float w_ft, float w_ft_N, uint16_t fuel_flow, uint16_t oil_flow_arm, uint16_t oil_flow_reducer, uint16_t battery_volt, int16_t temp_front_bearing, int16_t temp_rear_bearing, int16_t temp_elastic_bearing, int16_t temp_rigid_bearing, int16_t temp_input_oil, int16_t temp_arm_oil, int16_t temp_reducer_oil, int16_t temp_exhaust_fume, int16_t press_arm_oil, int16_t fuel_level, uint16_t oil_level_bearing, uint16_t oil_level_reducer, uint16_t PWM_fuel_pump, uint16_t current_fuel_pump, uint16_t PWM_oil_pump, uint16_t current_oil_pump, uint16_t PWM_oil_suction_pump_reducer, uint16_t PWM_oil_suction_pump_arm, uint16_t PWM_oil_pressure_pump, uint8_t activate, uint16_t turn_on, uint8_t valve_state, uint8_t pressure_state, uint32_t warning, uint32_t error, const uint8_t *EvnC, const uint8_t *res)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_LEN];
    _mav_put_float(buf, 0, time);
    _mav_put_float(buf, 4, w_gg);
    _mav_put_float(buf, 8, w_gg_N);
    _mav_put_float(buf, 12, w_ft);
    _mav_put_float(buf, 16, w_ft_N);
    _mav_put_uint32_t(buf, 20, warning);
    _mav_put_uint32_t(buf, 24, error);
    _mav_put_uint16_t(buf, 28, fuel_flow);
    _mav_put_uint16_t(buf, 30, oil_flow_arm);
    _mav_put_uint16_t(buf, 32, oil_flow_reducer);
    _mav_put_uint16_t(buf, 34, battery_volt);
    _mav_put_int16_t(buf, 36, temp_front_bearing);
    _mav_put_int16_t(buf, 38, temp_rear_bearing);
    _mav_put_int16_t(buf, 40, temp_elastic_bearing);
    _mav_put_int16_t(buf, 42, temp_rigid_bearing);
    _mav_put_int16_t(buf, 44, temp_input_oil);
    _mav_put_int16_t(buf, 46, temp_arm_oil);
    _mav_put_int16_t(buf, 48, temp_reducer_oil);
    _mav_put_int16_t(buf, 50, temp_exhaust_fume);
    _mav_put_int16_t(buf, 52, press_arm_oil);
    _mav_put_int16_t(buf, 54, fuel_level);
    _mav_put_uint16_t(buf, 56, oil_level_bearing);
    _mav_put_uint16_t(buf, 58, oil_level_reducer);
    _mav_put_uint16_t(buf, 60, PWM_fuel_pump);
    _mav_put_uint16_t(buf, 62, current_fuel_pump);
    _mav_put_uint16_t(buf, 64, PWM_oil_pump);
    _mav_put_uint16_t(buf, 66, current_oil_pump);
    _mav_put_uint16_t(buf, 68, PWM_oil_suction_pump_reducer);
    _mav_put_uint16_t(buf, 70, PWM_oil_suction_pump_arm);
    _mav_put_uint16_t(buf, 72, PWM_oil_pressure_pump);
    _mav_put_uint16_t(buf, 74, turn_on);
    _mav_put_uint8_t(buf, 76, activate);
    _mav_put_uint8_t(buf, 77, valve_state);
    _mav_put_uint8_t(buf, 78, pressure_state);
    _mav_put_uint8_t_array(buf, 79, EvnC, 8);
    _mav_put_uint8_t_array(buf, 87, res, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_LEN);
#else
    mavlink_lisum_power_motor_scaled_data_t packet;
    packet.time = time;
    packet.w_gg = w_gg;
    packet.w_gg_N = w_gg_N;
    packet.w_ft = w_ft;
    packet.w_ft_N = w_ft_N;
    packet.warning = warning;
    packet.error = error;
    packet.fuel_flow = fuel_flow;
    packet.oil_flow_arm = oil_flow_arm;
    packet.oil_flow_reducer = oil_flow_reducer;
    packet.battery_volt = battery_volt;
    packet.temp_front_bearing = temp_front_bearing;
    packet.temp_rear_bearing = temp_rear_bearing;
    packet.temp_elastic_bearing = temp_elastic_bearing;
    packet.temp_rigid_bearing = temp_rigid_bearing;
    packet.temp_input_oil = temp_input_oil;
    packet.temp_arm_oil = temp_arm_oil;
    packet.temp_reducer_oil = temp_reducer_oil;
    packet.temp_exhaust_fume = temp_exhaust_fume;
    packet.press_arm_oil = press_arm_oil;
    packet.fuel_level = fuel_level;
    packet.oil_level_bearing = oil_level_bearing;
    packet.oil_level_reducer = oil_level_reducer;
    packet.PWM_fuel_pump = PWM_fuel_pump;
    packet.current_fuel_pump = current_fuel_pump;
    packet.PWM_oil_pump = PWM_oil_pump;
    packet.current_oil_pump = current_oil_pump;
    packet.PWM_oil_suction_pump_reducer = PWM_oil_suction_pump_reducer;
    packet.PWM_oil_suction_pump_arm = PWM_oil_suction_pump_arm;
    packet.PWM_oil_pressure_pump = PWM_oil_pressure_pump;
    packet.turn_on = turn_on;
    packet.activate = activate;
    packet.valve_state = valve_state;
    packet.pressure_state = pressure_state;
    mav_array_memcpy(packet.EvnC, EvnC, sizeof(uint8_t)*8);
    mav_array_memcpy(packet.res, res, sizeof(uint8_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_MIN_LEN, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_LEN, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_CRC);
}

/**
 * @brief Pack a lisum_power_motor_scaled_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param time [s] Engine time since turning on
 * @param w_gg [Hz] Angular Rate of Gas Generator
 * @param w_gg_N [Hz] Nominal Rate Velocity of Gas generator
 * @param w_ft [Hz] Angular Rate of Free Turbine
 * @param w_ft_N [Hz] Nominal Rate Velocity of Free Turbine
 * @param fuel_flow  Fuel Flow [cg/s]
 * @param oil_flow_arm  Oil Flow - arm [cg/s]
 * @param oil_flow_reducer  Oil Flow - reducer [cg/s]
 * @param battery_volt [mV] Battery voltage
 * @param temp_front_bearing  Temperature of front bearing [ddegC]
 * @param temp_rear_bearing  Temperature of rear bearing [ddegC]
 * @param temp_elastic_bearing  Temperature of elastic bearing [ddegC]
 * @param temp_rigid_bearing  Temperature of rigid bearing [ddegC]
 * @param temp_input_oil  Temperature of input oil [ddegC]
 * @param temp_arm_oil  Temperature of oil - arm [ddegC]
 * @param temp_reducer_oil  Temperature of oil - reducer [ddegC]
 * @param temp_exhaust_fume  Temperature of exhaust fumes [ddegC]
 * @param press_arm_oil [mbar] Oil pressure - arm
 * @param fuel_level  Fuel level [cl]
 * @param oil_level_bearing [c%] Oil level - bearing
 * @param oil_level_reducer [c%] Oil level - reducer
 * @param PWM_fuel_pump [c%] Fuel pump PWM
 * @param current_fuel_pump [cA] Fuel pump current
 * @param PWM_oil_pump [c%] Oil pump PWM
 * @param current_oil_pump [cA] Oil pump current
 * @param PWM_oil_suction_pump_reducer [c%] Suction pump (reducer) PWM
 * @param PWM_oil_suction_pump_arm [c%] Suction pump (arm) PWM
 * @param PWM_oil_pressure_pump [c%] Oil pressure pump PWM
 * @param activate  Activate Struct
 * @param turn_on  Turn ON Struct
 * @param valve_state  Valve State
 * @param pressure_state  Pressure State
 * @param warning  Warning Struct
 * @param error  Error Struct
 * @param EvnC  EvnC Struct
 * @param res  Reserved for future
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_power_motor_scaled_data_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               float time, float w_gg, float w_gg_N, float w_ft, float w_ft_N, uint16_t fuel_flow, uint16_t oil_flow_arm, uint16_t oil_flow_reducer, uint16_t battery_volt, int16_t temp_front_bearing, int16_t temp_rear_bearing, int16_t temp_elastic_bearing, int16_t temp_rigid_bearing, int16_t temp_input_oil, int16_t temp_arm_oil, int16_t temp_reducer_oil, int16_t temp_exhaust_fume, int16_t press_arm_oil, int16_t fuel_level, uint16_t oil_level_bearing, uint16_t oil_level_reducer, uint16_t PWM_fuel_pump, uint16_t current_fuel_pump, uint16_t PWM_oil_pump, uint16_t current_oil_pump, uint16_t PWM_oil_suction_pump_reducer, uint16_t PWM_oil_suction_pump_arm, uint16_t PWM_oil_pressure_pump, uint8_t activate, uint16_t turn_on, uint8_t valve_state, uint8_t pressure_state, uint32_t warning, uint32_t error, const uint8_t *EvnC, const uint8_t *res)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_LEN];
    _mav_put_float(buf, 0, time);
    _mav_put_float(buf, 4, w_gg);
    _mav_put_float(buf, 8, w_gg_N);
    _mav_put_float(buf, 12, w_ft);
    _mav_put_float(buf, 16, w_ft_N);
    _mav_put_uint32_t(buf, 20, warning);
    _mav_put_uint32_t(buf, 24, error);
    _mav_put_uint16_t(buf, 28, fuel_flow);
    _mav_put_uint16_t(buf, 30, oil_flow_arm);
    _mav_put_uint16_t(buf, 32, oil_flow_reducer);
    _mav_put_uint16_t(buf, 34, battery_volt);
    _mav_put_int16_t(buf, 36, temp_front_bearing);
    _mav_put_int16_t(buf, 38, temp_rear_bearing);
    _mav_put_int16_t(buf, 40, temp_elastic_bearing);
    _mav_put_int16_t(buf, 42, temp_rigid_bearing);
    _mav_put_int16_t(buf, 44, temp_input_oil);
    _mav_put_int16_t(buf, 46, temp_arm_oil);
    _mav_put_int16_t(buf, 48, temp_reducer_oil);
    _mav_put_int16_t(buf, 50, temp_exhaust_fume);
    _mav_put_int16_t(buf, 52, press_arm_oil);
    _mav_put_int16_t(buf, 54, fuel_level);
    _mav_put_uint16_t(buf, 56, oil_level_bearing);
    _mav_put_uint16_t(buf, 58, oil_level_reducer);
    _mav_put_uint16_t(buf, 60, PWM_fuel_pump);
    _mav_put_uint16_t(buf, 62, current_fuel_pump);
    _mav_put_uint16_t(buf, 64, PWM_oil_pump);
    _mav_put_uint16_t(buf, 66, current_oil_pump);
    _mav_put_uint16_t(buf, 68, PWM_oil_suction_pump_reducer);
    _mav_put_uint16_t(buf, 70, PWM_oil_suction_pump_arm);
    _mav_put_uint16_t(buf, 72, PWM_oil_pressure_pump);
    _mav_put_uint16_t(buf, 74, turn_on);
    _mav_put_uint8_t(buf, 76, activate);
    _mav_put_uint8_t(buf, 77, valve_state);
    _mav_put_uint8_t(buf, 78, pressure_state);
    _mav_put_uint8_t_array(buf, 79, EvnC, 8);
    _mav_put_uint8_t_array(buf, 87, res, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_LEN);
#else
    mavlink_lisum_power_motor_scaled_data_t packet;
    packet.time = time;
    packet.w_gg = w_gg;
    packet.w_gg_N = w_gg_N;
    packet.w_ft = w_ft;
    packet.w_ft_N = w_ft_N;
    packet.warning = warning;
    packet.error = error;
    packet.fuel_flow = fuel_flow;
    packet.oil_flow_arm = oil_flow_arm;
    packet.oil_flow_reducer = oil_flow_reducer;
    packet.battery_volt = battery_volt;
    packet.temp_front_bearing = temp_front_bearing;
    packet.temp_rear_bearing = temp_rear_bearing;
    packet.temp_elastic_bearing = temp_elastic_bearing;
    packet.temp_rigid_bearing = temp_rigid_bearing;
    packet.temp_input_oil = temp_input_oil;
    packet.temp_arm_oil = temp_arm_oil;
    packet.temp_reducer_oil = temp_reducer_oil;
    packet.temp_exhaust_fume = temp_exhaust_fume;
    packet.press_arm_oil = press_arm_oil;
    packet.fuel_level = fuel_level;
    packet.oil_level_bearing = oil_level_bearing;
    packet.oil_level_reducer = oil_level_reducer;
    packet.PWM_fuel_pump = PWM_fuel_pump;
    packet.current_fuel_pump = current_fuel_pump;
    packet.PWM_oil_pump = PWM_oil_pump;
    packet.current_oil_pump = current_oil_pump;
    packet.PWM_oil_suction_pump_reducer = PWM_oil_suction_pump_reducer;
    packet.PWM_oil_suction_pump_arm = PWM_oil_suction_pump_arm;
    packet.PWM_oil_pressure_pump = PWM_oil_pressure_pump;
    packet.turn_on = turn_on;
    packet.activate = activate;
    packet.valve_state = valve_state;
    packet.pressure_state = pressure_state;
    mav_array_memcpy(packet.EvnC, EvnC, sizeof(uint8_t)*8);
    mav_array_memcpy(packet.res, res, sizeof(uint8_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_MIN_LEN, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_LEN, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_MIN_LEN, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_LEN);
#endif
}

/**
 * @brief Pack a lisum_power_motor_scaled_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time [s] Engine time since turning on
 * @param w_gg [Hz] Angular Rate of Gas Generator
 * @param w_gg_N [Hz] Nominal Rate Velocity of Gas generator
 * @param w_ft [Hz] Angular Rate of Free Turbine
 * @param w_ft_N [Hz] Nominal Rate Velocity of Free Turbine
 * @param fuel_flow  Fuel Flow [cg/s]
 * @param oil_flow_arm  Oil Flow - arm [cg/s]
 * @param oil_flow_reducer  Oil Flow - reducer [cg/s]
 * @param battery_volt [mV] Battery voltage
 * @param temp_front_bearing  Temperature of front bearing [ddegC]
 * @param temp_rear_bearing  Temperature of rear bearing [ddegC]
 * @param temp_elastic_bearing  Temperature of elastic bearing [ddegC]
 * @param temp_rigid_bearing  Temperature of rigid bearing [ddegC]
 * @param temp_input_oil  Temperature of input oil [ddegC]
 * @param temp_arm_oil  Temperature of oil - arm [ddegC]
 * @param temp_reducer_oil  Temperature of oil - reducer [ddegC]
 * @param temp_exhaust_fume  Temperature of exhaust fumes [ddegC]
 * @param press_arm_oil [mbar] Oil pressure - arm
 * @param fuel_level  Fuel level [cl]
 * @param oil_level_bearing [c%] Oil level - bearing
 * @param oil_level_reducer [c%] Oil level - reducer
 * @param PWM_fuel_pump [c%] Fuel pump PWM
 * @param current_fuel_pump [cA] Fuel pump current
 * @param PWM_oil_pump [c%] Oil pump PWM
 * @param current_oil_pump [cA] Oil pump current
 * @param PWM_oil_suction_pump_reducer [c%] Suction pump (reducer) PWM
 * @param PWM_oil_suction_pump_arm [c%] Suction pump (arm) PWM
 * @param PWM_oil_pressure_pump [c%] Oil pressure pump PWM
 * @param activate  Activate Struct
 * @param turn_on  Turn ON Struct
 * @param valve_state  Valve State
 * @param pressure_state  Pressure State
 * @param warning  Warning Struct
 * @param error  Error Struct
 * @param EvnC  EvnC Struct
 * @param res  Reserved for future
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_power_motor_scaled_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float time,float w_gg,float w_gg_N,float w_ft,float w_ft_N,uint16_t fuel_flow,uint16_t oil_flow_arm,uint16_t oil_flow_reducer,uint16_t battery_volt,int16_t temp_front_bearing,int16_t temp_rear_bearing,int16_t temp_elastic_bearing,int16_t temp_rigid_bearing,int16_t temp_input_oil,int16_t temp_arm_oil,int16_t temp_reducer_oil,int16_t temp_exhaust_fume,int16_t press_arm_oil,int16_t fuel_level,uint16_t oil_level_bearing,uint16_t oil_level_reducer,uint16_t PWM_fuel_pump,uint16_t current_fuel_pump,uint16_t PWM_oil_pump,uint16_t current_oil_pump,uint16_t PWM_oil_suction_pump_reducer,uint16_t PWM_oil_suction_pump_arm,uint16_t PWM_oil_pressure_pump,uint8_t activate,uint16_t turn_on,uint8_t valve_state,uint8_t pressure_state,uint32_t warning,uint32_t error,const uint8_t *EvnC,const uint8_t *res)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_LEN];
    _mav_put_float(buf, 0, time);
    _mav_put_float(buf, 4, w_gg);
    _mav_put_float(buf, 8, w_gg_N);
    _mav_put_float(buf, 12, w_ft);
    _mav_put_float(buf, 16, w_ft_N);
    _mav_put_uint32_t(buf, 20, warning);
    _mav_put_uint32_t(buf, 24, error);
    _mav_put_uint16_t(buf, 28, fuel_flow);
    _mav_put_uint16_t(buf, 30, oil_flow_arm);
    _mav_put_uint16_t(buf, 32, oil_flow_reducer);
    _mav_put_uint16_t(buf, 34, battery_volt);
    _mav_put_int16_t(buf, 36, temp_front_bearing);
    _mav_put_int16_t(buf, 38, temp_rear_bearing);
    _mav_put_int16_t(buf, 40, temp_elastic_bearing);
    _mav_put_int16_t(buf, 42, temp_rigid_bearing);
    _mav_put_int16_t(buf, 44, temp_input_oil);
    _mav_put_int16_t(buf, 46, temp_arm_oil);
    _mav_put_int16_t(buf, 48, temp_reducer_oil);
    _mav_put_int16_t(buf, 50, temp_exhaust_fume);
    _mav_put_int16_t(buf, 52, press_arm_oil);
    _mav_put_int16_t(buf, 54, fuel_level);
    _mav_put_uint16_t(buf, 56, oil_level_bearing);
    _mav_put_uint16_t(buf, 58, oil_level_reducer);
    _mav_put_uint16_t(buf, 60, PWM_fuel_pump);
    _mav_put_uint16_t(buf, 62, current_fuel_pump);
    _mav_put_uint16_t(buf, 64, PWM_oil_pump);
    _mav_put_uint16_t(buf, 66, current_oil_pump);
    _mav_put_uint16_t(buf, 68, PWM_oil_suction_pump_reducer);
    _mav_put_uint16_t(buf, 70, PWM_oil_suction_pump_arm);
    _mav_put_uint16_t(buf, 72, PWM_oil_pressure_pump);
    _mav_put_uint16_t(buf, 74, turn_on);
    _mav_put_uint8_t(buf, 76, activate);
    _mav_put_uint8_t(buf, 77, valve_state);
    _mav_put_uint8_t(buf, 78, pressure_state);
    _mav_put_uint8_t_array(buf, 79, EvnC, 8);
    _mav_put_uint8_t_array(buf, 87, res, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_LEN);
#else
    mavlink_lisum_power_motor_scaled_data_t packet;
    packet.time = time;
    packet.w_gg = w_gg;
    packet.w_gg_N = w_gg_N;
    packet.w_ft = w_ft;
    packet.w_ft_N = w_ft_N;
    packet.warning = warning;
    packet.error = error;
    packet.fuel_flow = fuel_flow;
    packet.oil_flow_arm = oil_flow_arm;
    packet.oil_flow_reducer = oil_flow_reducer;
    packet.battery_volt = battery_volt;
    packet.temp_front_bearing = temp_front_bearing;
    packet.temp_rear_bearing = temp_rear_bearing;
    packet.temp_elastic_bearing = temp_elastic_bearing;
    packet.temp_rigid_bearing = temp_rigid_bearing;
    packet.temp_input_oil = temp_input_oil;
    packet.temp_arm_oil = temp_arm_oil;
    packet.temp_reducer_oil = temp_reducer_oil;
    packet.temp_exhaust_fume = temp_exhaust_fume;
    packet.press_arm_oil = press_arm_oil;
    packet.fuel_level = fuel_level;
    packet.oil_level_bearing = oil_level_bearing;
    packet.oil_level_reducer = oil_level_reducer;
    packet.PWM_fuel_pump = PWM_fuel_pump;
    packet.current_fuel_pump = current_fuel_pump;
    packet.PWM_oil_pump = PWM_oil_pump;
    packet.current_oil_pump = current_oil_pump;
    packet.PWM_oil_suction_pump_reducer = PWM_oil_suction_pump_reducer;
    packet.PWM_oil_suction_pump_arm = PWM_oil_suction_pump_arm;
    packet.PWM_oil_pressure_pump = PWM_oil_pressure_pump;
    packet.turn_on = turn_on;
    packet.activate = activate;
    packet.valve_state = valve_state;
    packet.pressure_state = pressure_state;
    mav_array_memcpy(packet.EvnC, EvnC, sizeof(uint8_t)*8);
    mav_array_memcpy(packet.res, res, sizeof(uint8_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_MIN_LEN, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_LEN, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_CRC);
}

/**
 * @brief Encode a lisum_power_motor_scaled_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param lisum_power_motor_scaled_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_power_motor_scaled_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_lisum_power_motor_scaled_data_t* lisum_power_motor_scaled_data)
{
    return mavlink_msg_lisum_power_motor_scaled_data_pack(system_id, component_id, msg, lisum_power_motor_scaled_data->time, lisum_power_motor_scaled_data->w_gg, lisum_power_motor_scaled_data->w_gg_N, lisum_power_motor_scaled_data->w_ft, lisum_power_motor_scaled_data->w_ft_N, lisum_power_motor_scaled_data->fuel_flow, lisum_power_motor_scaled_data->oil_flow_arm, lisum_power_motor_scaled_data->oil_flow_reducer, lisum_power_motor_scaled_data->battery_volt, lisum_power_motor_scaled_data->temp_front_bearing, lisum_power_motor_scaled_data->temp_rear_bearing, lisum_power_motor_scaled_data->temp_elastic_bearing, lisum_power_motor_scaled_data->temp_rigid_bearing, lisum_power_motor_scaled_data->temp_input_oil, lisum_power_motor_scaled_data->temp_arm_oil, lisum_power_motor_scaled_data->temp_reducer_oil, lisum_power_motor_scaled_data->temp_exhaust_fume, lisum_power_motor_scaled_data->press_arm_oil, lisum_power_motor_scaled_data->fuel_level, lisum_power_motor_scaled_data->oil_level_bearing, lisum_power_motor_scaled_data->oil_level_reducer, lisum_power_motor_scaled_data->PWM_fuel_pump, lisum_power_motor_scaled_data->current_fuel_pump, lisum_power_motor_scaled_data->PWM_oil_pump, lisum_power_motor_scaled_data->current_oil_pump, lisum_power_motor_scaled_data->PWM_oil_suction_pump_reducer, lisum_power_motor_scaled_data->PWM_oil_suction_pump_arm, lisum_power_motor_scaled_data->PWM_oil_pressure_pump, lisum_power_motor_scaled_data->activate, lisum_power_motor_scaled_data->turn_on, lisum_power_motor_scaled_data->valve_state, lisum_power_motor_scaled_data->pressure_state, lisum_power_motor_scaled_data->warning, lisum_power_motor_scaled_data->error, lisum_power_motor_scaled_data->EvnC, lisum_power_motor_scaled_data->res);
}

/**
 * @brief Encode a lisum_power_motor_scaled_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param lisum_power_motor_scaled_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_power_motor_scaled_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_lisum_power_motor_scaled_data_t* lisum_power_motor_scaled_data)
{
    return mavlink_msg_lisum_power_motor_scaled_data_pack_chan(system_id, component_id, chan, msg, lisum_power_motor_scaled_data->time, lisum_power_motor_scaled_data->w_gg, lisum_power_motor_scaled_data->w_gg_N, lisum_power_motor_scaled_data->w_ft, lisum_power_motor_scaled_data->w_ft_N, lisum_power_motor_scaled_data->fuel_flow, lisum_power_motor_scaled_data->oil_flow_arm, lisum_power_motor_scaled_data->oil_flow_reducer, lisum_power_motor_scaled_data->battery_volt, lisum_power_motor_scaled_data->temp_front_bearing, lisum_power_motor_scaled_data->temp_rear_bearing, lisum_power_motor_scaled_data->temp_elastic_bearing, lisum_power_motor_scaled_data->temp_rigid_bearing, lisum_power_motor_scaled_data->temp_input_oil, lisum_power_motor_scaled_data->temp_arm_oil, lisum_power_motor_scaled_data->temp_reducer_oil, lisum_power_motor_scaled_data->temp_exhaust_fume, lisum_power_motor_scaled_data->press_arm_oil, lisum_power_motor_scaled_data->fuel_level, lisum_power_motor_scaled_data->oil_level_bearing, lisum_power_motor_scaled_data->oil_level_reducer, lisum_power_motor_scaled_data->PWM_fuel_pump, lisum_power_motor_scaled_data->current_fuel_pump, lisum_power_motor_scaled_data->PWM_oil_pump, lisum_power_motor_scaled_data->current_oil_pump, lisum_power_motor_scaled_data->PWM_oil_suction_pump_reducer, lisum_power_motor_scaled_data->PWM_oil_suction_pump_arm, lisum_power_motor_scaled_data->PWM_oil_pressure_pump, lisum_power_motor_scaled_data->activate, lisum_power_motor_scaled_data->turn_on, lisum_power_motor_scaled_data->valve_state, lisum_power_motor_scaled_data->pressure_state, lisum_power_motor_scaled_data->warning, lisum_power_motor_scaled_data->error, lisum_power_motor_scaled_data->EvnC, lisum_power_motor_scaled_data->res);
}

/**
 * @brief Encode a lisum_power_motor_scaled_data struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param lisum_power_motor_scaled_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_power_motor_scaled_data_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_lisum_power_motor_scaled_data_t* lisum_power_motor_scaled_data)
{
    return mavlink_msg_lisum_power_motor_scaled_data_pack_status(system_id, component_id, _status, msg,  lisum_power_motor_scaled_data->time, lisum_power_motor_scaled_data->w_gg, lisum_power_motor_scaled_data->w_gg_N, lisum_power_motor_scaled_data->w_ft, lisum_power_motor_scaled_data->w_ft_N, lisum_power_motor_scaled_data->fuel_flow, lisum_power_motor_scaled_data->oil_flow_arm, lisum_power_motor_scaled_data->oil_flow_reducer, lisum_power_motor_scaled_data->battery_volt, lisum_power_motor_scaled_data->temp_front_bearing, lisum_power_motor_scaled_data->temp_rear_bearing, lisum_power_motor_scaled_data->temp_elastic_bearing, lisum_power_motor_scaled_data->temp_rigid_bearing, lisum_power_motor_scaled_data->temp_input_oil, lisum_power_motor_scaled_data->temp_arm_oil, lisum_power_motor_scaled_data->temp_reducer_oil, lisum_power_motor_scaled_data->temp_exhaust_fume, lisum_power_motor_scaled_data->press_arm_oil, lisum_power_motor_scaled_data->fuel_level, lisum_power_motor_scaled_data->oil_level_bearing, lisum_power_motor_scaled_data->oil_level_reducer, lisum_power_motor_scaled_data->PWM_fuel_pump, lisum_power_motor_scaled_data->current_fuel_pump, lisum_power_motor_scaled_data->PWM_oil_pump, lisum_power_motor_scaled_data->current_oil_pump, lisum_power_motor_scaled_data->PWM_oil_suction_pump_reducer, lisum_power_motor_scaled_data->PWM_oil_suction_pump_arm, lisum_power_motor_scaled_data->PWM_oil_pressure_pump, lisum_power_motor_scaled_data->activate, lisum_power_motor_scaled_data->turn_on, lisum_power_motor_scaled_data->valve_state, lisum_power_motor_scaled_data->pressure_state, lisum_power_motor_scaled_data->warning, lisum_power_motor_scaled_data->error, lisum_power_motor_scaled_data->EvnC, lisum_power_motor_scaled_data->res);
}

/**
 * @brief Send a lisum_power_motor_scaled_data message
 * @param chan MAVLink channel to send the message
 *
 * @param time [s] Engine time since turning on
 * @param w_gg [Hz] Angular Rate of Gas Generator
 * @param w_gg_N [Hz] Nominal Rate Velocity of Gas generator
 * @param w_ft [Hz] Angular Rate of Free Turbine
 * @param w_ft_N [Hz] Nominal Rate Velocity of Free Turbine
 * @param fuel_flow  Fuel Flow [cg/s]
 * @param oil_flow_arm  Oil Flow - arm [cg/s]
 * @param oil_flow_reducer  Oil Flow - reducer [cg/s]
 * @param battery_volt [mV] Battery voltage
 * @param temp_front_bearing  Temperature of front bearing [ddegC]
 * @param temp_rear_bearing  Temperature of rear bearing [ddegC]
 * @param temp_elastic_bearing  Temperature of elastic bearing [ddegC]
 * @param temp_rigid_bearing  Temperature of rigid bearing [ddegC]
 * @param temp_input_oil  Temperature of input oil [ddegC]
 * @param temp_arm_oil  Temperature of oil - arm [ddegC]
 * @param temp_reducer_oil  Temperature of oil - reducer [ddegC]
 * @param temp_exhaust_fume  Temperature of exhaust fumes [ddegC]
 * @param press_arm_oil [mbar] Oil pressure - arm
 * @param fuel_level  Fuel level [cl]
 * @param oil_level_bearing [c%] Oil level - bearing
 * @param oil_level_reducer [c%] Oil level - reducer
 * @param PWM_fuel_pump [c%] Fuel pump PWM
 * @param current_fuel_pump [cA] Fuel pump current
 * @param PWM_oil_pump [c%] Oil pump PWM
 * @param current_oil_pump [cA] Oil pump current
 * @param PWM_oil_suction_pump_reducer [c%] Suction pump (reducer) PWM
 * @param PWM_oil_suction_pump_arm [c%] Suction pump (arm) PWM
 * @param PWM_oil_pressure_pump [c%] Oil pressure pump PWM
 * @param activate  Activate Struct
 * @param turn_on  Turn ON Struct
 * @param valve_state  Valve State
 * @param pressure_state  Pressure State
 * @param warning  Warning Struct
 * @param error  Error Struct
 * @param EvnC  EvnC Struct
 * @param res  Reserved for future
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_lisum_power_motor_scaled_data_send(mavlink_channel_t chan, float time, float w_gg, float w_gg_N, float w_ft, float w_ft_N, uint16_t fuel_flow, uint16_t oil_flow_arm, uint16_t oil_flow_reducer, uint16_t battery_volt, int16_t temp_front_bearing, int16_t temp_rear_bearing, int16_t temp_elastic_bearing, int16_t temp_rigid_bearing, int16_t temp_input_oil, int16_t temp_arm_oil, int16_t temp_reducer_oil, int16_t temp_exhaust_fume, int16_t press_arm_oil, int16_t fuel_level, uint16_t oil_level_bearing, uint16_t oil_level_reducer, uint16_t PWM_fuel_pump, uint16_t current_fuel_pump, uint16_t PWM_oil_pump, uint16_t current_oil_pump, uint16_t PWM_oil_suction_pump_reducer, uint16_t PWM_oil_suction_pump_arm, uint16_t PWM_oil_pressure_pump, uint8_t activate, uint16_t turn_on, uint8_t valve_state, uint8_t pressure_state, uint32_t warning, uint32_t error, const uint8_t *EvnC, const uint8_t *res)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_LEN];
    _mav_put_float(buf, 0, time);
    _mav_put_float(buf, 4, w_gg);
    _mav_put_float(buf, 8, w_gg_N);
    _mav_put_float(buf, 12, w_ft);
    _mav_put_float(buf, 16, w_ft_N);
    _mav_put_uint32_t(buf, 20, warning);
    _mav_put_uint32_t(buf, 24, error);
    _mav_put_uint16_t(buf, 28, fuel_flow);
    _mav_put_uint16_t(buf, 30, oil_flow_arm);
    _mav_put_uint16_t(buf, 32, oil_flow_reducer);
    _mav_put_uint16_t(buf, 34, battery_volt);
    _mav_put_int16_t(buf, 36, temp_front_bearing);
    _mav_put_int16_t(buf, 38, temp_rear_bearing);
    _mav_put_int16_t(buf, 40, temp_elastic_bearing);
    _mav_put_int16_t(buf, 42, temp_rigid_bearing);
    _mav_put_int16_t(buf, 44, temp_input_oil);
    _mav_put_int16_t(buf, 46, temp_arm_oil);
    _mav_put_int16_t(buf, 48, temp_reducer_oil);
    _mav_put_int16_t(buf, 50, temp_exhaust_fume);
    _mav_put_int16_t(buf, 52, press_arm_oil);
    _mav_put_int16_t(buf, 54, fuel_level);
    _mav_put_uint16_t(buf, 56, oil_level_bearing);
    _mav_put_uint16_t(buf, 58, oil_level_reducer);
    _mav_put_uint16_t(buf, 60, PWM_fuel_pump);
    _mav_put_uint16_t(buf, 62, current_fuel_pump);
    _mav_put_uint16_t(buf, 64, PWM_oil_pump);
    _mav_put_uint16_t(buf, 66, current_oil_pump);
    _mav_put_uint16_t(buf, 68, PWM_oil_suction_pump_reducer);
    _mav_put_uint16_t(buf, 70, PWM_oil_suction_pump_arm);
    _mav_put_uint16_t(buf, 72, PWM_oil_pressure_pump);
    _mav_put_uint16_t(buf, 74, turn_on);
    _mav_put_uint8_t(buf, 76, activate);
    _mav_put_uint8_t(buf, 77, valve_state);
    _mav_put_uint8_t(buf, 78, pressure_state);
    _mav_put_uint8_t_array(buf, 79, EvnC, 8);
    _mav_put_uint8_t_array(buf, 87, res, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA, buf, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_MIN_LEN, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_LEN, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_CRC);
#else
    mavlink_lisum_power_motor_scaled_data_t packet;
    packet.time = time;
    packet.w_gg = w_gg;
    packet.w_gg_N = w_gg_N;
    packet.w_ft = w_ft;
    packet.w_ft_N = w_ft_N;
    packet.warning = warning;
    packet.error = error;
    packet.fuel_flow = fuel_flow;
    packet.oil_flow_arm = oil_flow_arm;
    packet.oil_flow_reducer = oil_flow_reducer;
    packet.battery_volt = battery_volt;
    packet.temp_front_bearing = temp_front_bearing;
    packet.temp_rear_bearing = temp_rear_bearing;
    packet.temp_elastic_bearing = temp_elastic_bearing;
    packet.temp_rigid_bearing = temp_rigid_bearing;
    packet.temp_input_oil = temp_input_oil;
    packet.temp_arm_oil = temp_arm_oil;
    packet.temp_reducer_oil = temp_reducer_oil;
    packet.temp_exhaust_fume = temp_exhaust_fume;
    packet.press_arm_oil = press_arm_oil;
    packet.fuel_level = fuel_level;
    packet.oil_level_bearing = oil_level_bearing;
    packet.oil_level_reducer = oil_level_reducer;
    packet.PWM_fuel_pump = PWM_fuel_pump;
    packet.current_fuel_pump = current_fuel_pump;
    packet.PWM_oil_pump = PWM_oil_pump;
    packet.current_oil_pump = current_oil_pump;
    packet.PWM_oil_suction_pump_reducer = PWM_oil_suction_pump_reducer;
    packet.PWM_oil_suction_pump_arm = PWM_oil_suction_pump_arm;
    packet.PWM_oil_pressure_pump = PWM_oil_pressure_pump;
    packet.turn_on = turn_on;
    packet.activate = activate;
    packet.valve_state = valve_state;
    packet.pressure_state = pressure_state;
    mav_array_memcpy(packet.EvnC, EvnC, sizeof(uint8_t)*8);
    mav_array_memcpy(packet.res, res, sizeof(uint8_t)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA, (const char *)&packet, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_MIN_LEN, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_LEN, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_CRC);
#endif
}

/**
 * @brief Send a lisum_power_motor_scaled_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_lisum_power_motor_scaled_data_send_struct(mavlink_channel_t chan, const mavlink_lisum_power_motor_scaled_data_t* lisum_power_motor_scaled_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_lisum_power_motor_scaled_data_send(chan, lisum_power_motor_scaled_data->time, lisum_power_motor_scaled_data->w_gg, lisum_power_motor_scaled_data->w_gg_N, lisum_power_motor_scaled_data->w_ft, lisum_power_motor_scaled_data->w_ft_N, lisum_power_motor_scaled_data->fuel_flow, lisum_power_motor_scaled_data->oil_flow_arm, lisum_power_motor_scaled_data->oil_flow_reducer, lisum_power_motor_scaled_data->battery_volt, lisum_power_motor_scaled_data->temp_front_bearing, lisum_power_motor_scaled_data->temp_rear_bearing, lisum_power_motor_scaled_data->temp_elastic_bearing, lisum_power_motor_scaled_data->temp_rigid_bearing, lisum_power_motor_scaled_data->temp_input_oil, lisum_power_motor_scaled_data->temp_arm_oil, lisum_power_motor_scaled_data->temp_reducer_oil, lisum_power_motor_scaled_data->temp_exhaust_fume, lisum_power_motor_scaled_data->press_arm_oil, lisum_power_motor_scaled_data->fuel_level, lisum_power_motor_scaled_data->oil_level_bearing, lisum_power_motor_scaled_data->oil_level_reducer, lisum_power_motor_scaled_data->PWM_fuel_pump, lisum_power_motor_scaled_data->current_fuel_pump, lisum_power_motor_scaled_data->PWM_oil_pump, lisum_power_motor_scaled_data->current_oil_pump, lisum_power_motor_scaled_data->PWM_oil_suction_pump_reducer, lisum_power_motor_scaled_data->PWM_oil_suction_pump_arm, lisum_power_motor_scaled_data->PWM_oil_pressure_pump, lisum_power_motor_scaled_data->activate, lisum_power_motor_scaled_data->turn_on, lisum_power_motor_scaled_data->valve_state, lisum_power_motor_scaled_data->pressure_state, lisum_power_motor_scaled_data->warning, lisum_power_motor_scaled_data->error, lisum_power_motor_scaled_data->EvnC, lisum_power_motor_scaled_data->res);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA, (const char *)lisum_power_motor_scaled_data, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_MIN_LEN, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_LEN, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_CRC);
#endif
}

#if MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_lisum_power_motor_scaled_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float time, float w_gg, float w_gg_N, float w_ft, float w_ft_N, uint16_t fuel_flow, uint16_t oil_flow_arm, uint16_t oil_flow_reducer, uint16_t battery_volt, int16_t temp_front_bearing, int16_t temp_rear_bearing, int16_t temp_elastic_bearing, int16_t temp_rigid_bearing, int16_t temp_input_oil, int16_t temp_arm_oil, int16_t temp_reducer_oil, int16_t temp_exhaust_fume, int16_t press_arm_oil, int16_t fuel_level, uint16_t oil_level_bearing, uint16_t oil_level_reducer, uint16_t PWM_fuel_pump, uint16_t current_fuel_pump, uint16_t PWM_oil_pump, uint16_t current_oil_pump, uint16_t PWM_oil_suction_pump_reducer, uint16_t PWM_oil_suction_pump_arm, uint16_t PWM_oil_pressure_pump, uint8_t activate, uint16_t turn_on, uint8_t valve_state, uint8_t pressure_state, uint32_t warning, uint32_t error, const uint8_t *EvnC, const uint8_t *res)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, time);
    _mav_put_float(buf, 4, w_gg);
    _mav_put_float(buf, 8, w_gg_N);
    _mav_put_float(buf, 12, w_ft);
    _mav_put_float(buf, 16, w_ft_N);
    _mav_put_uint32_t(buf, 20, warning);
    _mav_put_uint32_t(buf, 24, error);
    _mav_put_uint16_t(buf, 28, fuel_flow);
    _mav_put_uint16_t(buf, 30, oil_flow_arm);
    _mav_put_uint16_t(buf, 32, oil_flow_reducer);
    _mav_put_uint16_t(buf, 34, battery_volt);
    _mav_put_int16_t(buf, 36, temp_front_bearing);
    _mav_put_int16_t(buf, 38, temp_rear_bearing);
    _mav_put_int16_t(buf, 40, temp_elastic_bearing);
    _mav_put_int16_t(buf, 42, temp_rigid_bearing);
    _mav_put_int16_t(buf, 44, temp_input_oil);
    _mav_put_int16_t(buf, 46, temp_arm_oil);
    _mav_put_int16_t(buf, 48, temp_reducer_oil);
    _mav_put_int16_t(buf, 50, temp_exhaust_fume);
    _mav_put_int16_t(buf, 52, press_arm_oil);
    _mav_put_int16_t(buf, 54, fuel_level);
    _mav_put_uint16_t(buf, 56, oil_level_bearing);
    _mav_put_uint16_t(buf, 58, oil_level_reducer);
    _mav_put_uint16_t(buf, 60, PWM_fuel_pump);
    _mav_put_uint16_t(buf, 62, current_fuel_pump);
    _mav_put_uint16_t(buf, 64, PWM_oil_pump);
    _mav_put_uint16_t(buf, 66, current_oil_pump);
    _mav_put_uint16_t(buf, 68, PWM_oil_suction_pump_reducer);
    _mav_put_uint16_t(buf, 70, PWM_oil_suction_pump_arm);
    _mav_put_uint16_t(buf, 72, PWM_oil_pressure_pump);
    _mav_put_uint16_t(buf, 74, turn_on);
    _mav_put_uint8_t(buf, 76, activate);
    _mav_put_uint8_t(buf, 77, valve_state);
    _mav_put_uint8_t(buf, 78, pressure_state);
    _mav_put_uint8_t_array(buf, 79, EvnC, 8);
    _mav_put_uint8_t_array(buf, 87, res, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA, buf, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_MIN_LEN, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_LEN, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_CRC);
#else
    mavlink_lisum_power_motor_scaled_data_t *packet = (mavlink_lisum_power_motor_scaled_data_t *)msgbuf;
    packet->time = time;
    packet->w_gg = w_gg;
    packet->w_gg_N = w_gg_N;
    packet->w_ft = w_ft;
    packet->w_ft_N = w_ft_N;
    packet->warning = warning;
    packet->error = error;
    packet->fuel_flow = fuel_flow;
    packet->oil_flow_arm = oil_flow_arm;
    packet->oil_flow_reducer = oil_flow_reducer;
    packet->battery_volt = battery_volt;
    packet->temp_front_bearing = temp_front_bearing;
    packet->temp_rear_bearing = temp_rear_bearing;
    packet->temp_elastic_bearing = temp_elastic_bearing;
    packet->temp_rigid_bearing = temp_rigid_bearing;
    packet->temp_input_oil = temp_input_oil;
    packet->temp_arm_oil = temp_arm_oil;
    packet->temp_reducer_oil = temp_reducer_oil;
    packet->temp_exhaust_fume = temp_exhaust_fume;
    packet->press_arm_oil = press_arm_oil;
    packet->fuel_level = fuel_level;
    packet->oil_level_bearing = oil_level_bearing;
    packet->oil_level_reducer = oil_level_reducer;
    packet->PWM_fuel_pump = PWM_fuel_pump;
    packet->current_fuel_pump = current_fuel_pump;
    packet->PWM_oil_pump = PWM_oil_pump;
    packet->current_oil_pump = current_oil_pump;
    packet->PWM_oil_suction_pump_reducer = PWM_oil_suction_pump_reducer;
    packet->PWM_oil_suction_pump_arm = PWM_oil_suction_pump_arm;
    packet->PWM_oil_pressure_pump = PWM_oil_pressure_pump;
    packet->turn_on = turn_on;
    packet->activate = activate;
    packet->valve_state = valve_state;
    packet->pressure_state = pressure_state;
    mav_array_memcpy(packet->EvnC, EvnC, sizeof(uint8_t)*8);
    mav_array_memcpy(packet->res, res, sizeof(uint8_t)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA, (const char *)packet, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_MIN_LEN, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_LEN, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_CRC);
#endif
}
#endif

#endif

// MESSAGE LISUM_POWER_MOTOR_SCALED_DATA UNPACKING


/**
 * @brief Get field time from lisum_power_motor_scaled_data message
 *
 * @return [s] Engine time since turning on
 */
static inline float mavlink_msg_lisum_power_motor_scaled_data_get_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field w_gg from lisum_power_motor_scaled_data message
 *
 * @return [Hz] Angular Rate of Gas Generator
 */
static inline float mavlink_msg_lisum_power_motor_scaled_data_get_w_gg(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field w_gg_N from lisum_power_motor_scaled_data message
 *
 * @return [Hz] Nominal Rate Velocity of Gas generator
 */
static inline float mavlink_msg_lisum_power_motor_scaled_data_get_w_gg_N(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field w_ft from lisum_power_motor_scaled_data message
 *
 * @return [Hz] Angular Rate of Free Turbine
 */
static inline float mavlink_msg_lisum_power_motor_scaled_data_get_w_ft(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field w_ft_N from lisum_power_motor_scaled_data message
 *
 * @return [Hz] Nominal Rate Velocity of Free Turbine
 */
static inline float mavlink_msg_lisum_power_motor_scaled_data_get_w_ft_N(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field fuel_flow from lisum_power_motor_scaled_data message
 *
 * @return  Fuel Flow [cg/s]
 */
static inline uint16_t mavlink_msg_lisum_power_motor_scaled_data_get_fuel_flow(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  28);
}

/**
 * @brief Get field oil_flow_arm from lisum_power_motor_scaled_data message
 *
 * @return  Oil Flow - arm [cg/s]
 */
static inline uint16_t mavlink_msg_lisum_power_motor_scaled_data_get_oil_flow_arm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  30);
}

/**
 * @brief Get field oil_flow_reducer from lisum_power_motor_scaled_data message
 *
 * @return  Oil Flow - reducer [cg/s]
 */
static inline uint16_t mavlink_msg_lisum_power_motor_scaled_data_get_oil_flow_reducer(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  32);
}

/**
 * @brief Get field battery_volt from lisum_power_motor_scaled_data message
 *
 * @return [mV] Battery voltage
 */
static inline uint16_t mavlink_msg_lisum_power_motor_scaled_data_get_battery_volt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  34);
}

/**
 * @brief Get field temp_front_bearing from lisum_power_motor_scaled_data message
 *
 * @return  Temperature of front bearing [ddegC]
 */
static inline int16_t mavlink_msg_lisum_power_motor_scaled_data_get_temp_front_bearing(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  36);
}

/**
 * @brief Get field temp_rear_bearing from lisum_power_motor_scaled_data message
 *
 * @return  Temperature of rear bearing [ddegC]
 */
static inline int16_t mavlink_msg_lisum_power_motor_scaled_data_get_temp_rear_bearing(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  38);
}

/**
 * @brief Get field temp_elastic_bearing from lisum_power_motor_scaled_data message
 *
 * @return  Temperature of elastic bearing [ddegC]
 */
static inline int16_t mavlink_msg_lisum_power_motor_scaled_data_get_temp_elastic_bearing(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  40);
}

/**
 * @brief Get field temp_rigid_bearing from lisum_power_motor_scaled_data message
 *
 * @return  Temperature of rigid bearing [ddegC]
 */
static inline int16_t mavlink_msg_lisum_power_motor_scaled_data_get_temp_rigid_bearing(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  42);
}

/**
 * @brief Get field temp_input_oil from lisum_power_motor_scaled_data message
 *
 * @return  Temperature of input oil [ddegC]
 */
static inline int16_t mavlink_msg_lisum_power_motor_scaled_data_get_temp_input_oil(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  44);
}

/**
 * @brief Get field temp_arm_oil from lisum_power_motor_scaled_data message
 *
 * @return  Temperature of oil - arm [ddegC]
 */
static inline int16_t mavlink_msg_lisum_power_motor_scaled_data_get_temp_arm_oil(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  46);
}

/**
 * @brief Get field temp_reducer_oil from lisum_power_motor_scaled_data message
 *
 * @return  Temperature of oil - reducer [ddegC]
 */
static inline int16_t mavlink_msg_lisum_power_motor_scaled_data_get_temp_reducer_oil(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  48);
}

/**
 * @brief Get field temp_exhaust_fume from lisum_power_motor_scaled_data message
 *
 * @return  Temperature of exhaust fumes [ddegC]
 */
static inline int16_t mavlink_msg_lisum_power_motor_scaled_data_get_temp_exhaust_fume(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  50);
}

/**
 * @brief Get field press_arm_oil from lisum_power_motor_scaled_data message
 *
 * @return [mbar] Oil pressure - arm
 */
static inline int16_t mavlink_msg_lisum_power_motor_scaled_data_get_press_arm_oil(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  52);
}

/**
 * @brief Get field fuel_level from lisum_power_motor_scaled_data message
 *
 * @return  Fuel level [cl]
 */
static inline int16_t mavlink_msg_lisum_power_motor_scaled_data_get_fuel_level(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  54);
}

/**
 * @brief Get field oil_level_bearing from lisum_power_motor_scaled_data message
 *
 * @return [c%] Oil level - bearing
 */
static inline uint16_t mavlink_msg_lisum_power_motor_scaled_data_get_oil_level_bearing(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  56);
}

/**
 * @brief Get field oil_level_reducer from lisum_power_motor_scaled_data message
 *
 * @return [c%] Oil level - reducer
 */
static inline uint16_t mavlink_msg_lisum_power_motor_scaled_data_get_oil_level_reducer(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  58);
}

/**
 * @brief Get field PWM_fuel_pump from lisum_power_motor_scaled_data message
 *
 * @return [c%] Fuel pump PWM
 */
static inline uint16_t mavlink_msg_lisum_power_motor_scaled_data_get_PWM_fuel_pump(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  60);
}

/**
 * @brief Get field current_fuel_pump from lisum_power_motor_scaled_data message
 *
 * @return [cA] Fuel pump current
 */
static inline uint16_t mavlink_msg_lisum_power_motor_scaled_data_get_current_fuel_pump(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  62);
}

/**
 * @brief Get field PWM_oil_pump from lisum_power_motor_scaled_data message
 *
 * @return [c%] Oil pump PWM
 */
static inline uint16_t mavlink_msg_lisum_power_motor_scaled_data_get_PWM_oil_pump(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  64);
}

/**
 * @brief Get field current_oil_pump from lisum_power_motor_scaled_data message
 *
 * @return [cA] Oil pump current
 */
static inline uint16_t mavlink_msg_lisum_power_motor_scaled_data_get_current_oil_pump(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  66);
}

/**
 * @brief Get field PWM_oil_suction_pump_reducer from lisum_power_motor_scaled_data message
 *
 * @return [c%] Suction pump (reducer) PWM
 */
static inline uint16_t mavlink_msg_lisum_power_motor_scaled_data_get_PWM_oil_suction_pump_reducer(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  68);
}

/**
 * @brief Get field PWM_oil_suction_pump_arm from lisum_power_motor_scaled_data message
 *
 * @return [c%] Suction pump (arm) PWM
 */
static inline uint16_t mavlink_msg_lisum_power_motor_scaled_data_get_PWM_oil_suction_pump_arm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  70);
}

/**
 * @brief Get field PWM_oil_pressure_pump from lisum_power_motor_scaled_data message
 *
 * @return [c%] Oil pressure pump PWM
 */
static inline uint16_t mavlink_msg_lisum_power_motor_scaled_data_get_PWM_oil_pressure_pump(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  72);
}

/**
 * @brief Get field activate from lisum_power_motor_scaled_data message
 *
 * @return  Activate Struct
 */
static inline uint8_t mavlink_msg_lisum_power_motor_scaled_data_get_activate(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  76);
}

/**
 * @brief Get field turn_on from lisum_power_motor_scaled_data message
 *
 * @return  Turn ON Struct
 */
static inline uint16_t mavlink_msg_lisum_power_motor_scaled_data_get_turn_on(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  74);
}

/**
 * @brief Get field valve_state from lisum_power_motor_scaled_data message
 *
 * @return  Valve State
 */
static inline uint8_t mavlink_msg_lisum_power_motor_scaled_data_get_valve_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  77);
}

/**
 * @brief Get field pressure_state from lisum_power_motor_scaled_data message
 *
 * @return  Pressure State
 */
static inline uint8_t mavlink_msg_lisum_power_motor_scaled_data_get_pressure_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  78);
}

/**
 * @brief Get field warning from lisum_power_motor_scaled_data message
 *
 * @return  Warning Struct
 */
static inline uint32_t mavlink_msg_lisum_power_motor_scaled_data_get_warning(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  20);
}

/**
 * @brief Get field error from lisum_power_motor_scaled_data message
 *
 * @return  Error Struct
 */
static inline uint32_t mavlink_msg_lisum_power_motor_scaled_data_get_error(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  24);
}

/**
 * @brief Get field EvnC from lisum_power_motor_scaled_data message
 *
 * @return  EvnC Struct
 */
static inline uint16_t mavlink_msg_lisum_power_motor_scaled_data_get_EvnC(const mavlink_message_t* msg, uint8_t *EvnC)
{
    return _MAV_RETURN_uint8_t_array(msg, EvnC, 8,  79);
}

/**
 * @brief Get field res from lisum_power_motor_scaled_data message
 *
 * @return  Reserved for future
 */
static inline uint16_t mavlink_msg_lisum_power_motor_scaled_data_get_res(const mavlink_message_t* msg, uint8_t *res)
{
    return _MAV_RETURN_uint8_t_array(msg, res, 8,  87);
}

/**
 * @brief Decode a lisum_power_motor_scaled_data message into a struct
 *
 * @param msg The message to decode
 * @param lisum_power_motor_scaled_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_lisum_power_motor_scaled_data_decode(const mavlink_message_t* msg, mavlink_lisum_power_motor_scaled_data_t* lisum_power_motor_scaled_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    lisum_power_motor_scaled_data->time = mavlink_msg_lisum_power_motor_scaled_data_get_time(msg);
    lisum_power_motor_scaled_data->w_gg = mavlink_msg_lisum_power_motor_scaled_data_get_w_gg(msg);
    lisum_power_motor_scaled_data->w_gg_N = mavlink_msg_lisum_power_motor_scaled_data_get_w_gg_N(msg);
    lisum_power_motor_scaled_data->w_ft = mavlink_msg_lisum_power_motor_scaled_data_get_w_ft(msg);
    lisum_power_motor_scaled_data->w_ft_N = mavlink_msg_lisum_power_motor_scaled_data_get_w_ft_N(msg);
    lisum_power_motor_scaled_data->warning = mavlink_msg_lisum_power_motor_scaled_data_get_warning(msg);
    lisum_power_motor_scaled_data->error = mavlink_msg_lisum_power_motor_scaled_data_get_error(msg);
    lisum_power_motor_scaled_data->fuel_flow = mavlink_msg_lisum_power_motor_scaled_data_get_fuel_flow(msg);
    lisum_power_motor_scaled_data->oil_flow_arm = mavlink_msg_lisum_power_motor_scaled_data_get_oil_flow_arm(msg);
    lisum_power_motor_scaled_data->oil_flow_reducer = mavlink_msg_lisum_power_motor_scaled_data_get_oil_flow_reducer(msg);
    lisum_power_motor_scaled_data->battery_volt = mavlink_msg_lisum_power_motor_scaled_data_get_battery_volt(msg);
    lisum_power_motor_scaled_data->temp_front_bearing = mavlink_msg_lisum_power_motor_scaled_data_get_temp_front_bearing(msg);
    lisum_power_motor_scaled_data->temp_rear_bearing = mavlink_msg_lisum_power_motor_scaled_data_get_temp_rear_bearing(msg);
    lisum_power_motor_scaled_data->temp_elastic_bearing = mavlink_msg_lisum_power_motor_scaled_data_get_temp_elastic_bearing(msg);
    lisum_power_motor_scaled_data->temp_rigid_bearing = mavlink_msg_lisum_power_motor_scaled_data_get_temp_rigid_bearing(msg);
    lisum_power_motor_scaled_data->temp_input_oil = mavlink_msg_lisum_power_motor_scaled_data_get_temp_input_oil(msg);
    lisum_power_motor_scaled_data->temp_arm_oil = mavlink_msg_lisum_power_motor_scaled_data_get_temp_arm_oil(msg);
    lisum_power_motor_scaled_data->temp_reducer_oil = mavlink_msg_lisum_power_motor_scaled_data_get_temp_reducer_oil(msg);
    lisum_power_motor_scaled_data->temp_exhaust_fume = mavlink_msg_lisum_power_motor_scaled_data_get_temp_exhaust_fume(msg);
    lisum_power_motor_scaled_data->press_arm_oil = mavlink_msg_lisum_power_motor_scaled_data_get_press_arm_oil(msg);
    lisum_power_motor_scaled_data->fuel_level = mavlink_msg_lisum_power_motor_scaled_data_get_fuel_level(msg);
    lisum_power_motor_scaled_data->oil_level_bearing = mavlink_msg_lisum_power_motor_scaled_data_get_oil_level_bearing(msg);
    lisum_power_motor_scaled_data->oil_level_reducer = mavlink_msg_lisum_power_motor_scaled_data_get_oil_level_reducer(msg);
    lisum_power_motor_scaled_data->PWM_fuel_pump = mavlink_msg_lisum_power_motor_scaled_data_get_PWM_fuel_pump(msg);
    lisum_power_motor_scaled_data->current_fuel_pump = mavlink_msg_lisum_power_motor_scaled_data_get_current_fuel_pump(msg);
    lisum_power_motor_scaled_data->PWM_oil_pump = mavlink_msg_lisum_power_motor_scaled_data_get_PWM_oil_pump(msg);
    lisum_power_motor_scaled_data->current_oil_pump = mavlink_msg_lisum_power_motor_scaled_data_get_current_oil_pump(msg);
    lisum_power_motor_scaled_data->PWM_oil_suction_pump_reducer = mavlink_msg_lisum_power_motor_scaled_data_get_PWM_oil_suction_pump_reducer(msg);
    lisum_power_motor_scaled_data->PWM_oil_suction_pump_arm = mavlink_msg_lisum_power_motor_scaled_data_get_PWM_oil_suction_pump_arm(msg);
    lisum_power_motor_scaled_data->PWM_oil_pressure_pump = mavlink_msg_lisum_power_motor_scaled_data_get_PWM_oil_pressure_pump(msg);
    lisum_power_motor_scaled_data->turn_on = mavlink_msg_lisum_power_motor_scaled_data_get_turn_on(msg);
    lisum_power_motor_scaled_data->activate = mavlink_msg_lisum_power_motor_scaled_data_get_activate(msg);
    lisum_power_motor_scaled_data->valve_state = mavlink_msg_lisum_power_motor_scaled_data_get_valve_state(msg);
    lisum_power_motor_scaled_data->pressure_state = mavlink_msg_lisum_power_motor_scaled_data_get_pressure_state(msg);
    mavlink_msg_lisum_power_motor_scaled_data_get_EvnC(msg, lisum_power_motor_scaled_data->EvnC);
    mavlink_msg_lisum_power_motor_scaled_data_get_res(msg, lisum_power_motor_scaled_data->res);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_LEN? msg->len : MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_LEN;
        memset(lisum_power_motor_scaled_data, 0, MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_LEN);
    memcpy(lisum_power_motor_scaled_data, _MAV_PAYLOAD(msg), len);
#endif
}
