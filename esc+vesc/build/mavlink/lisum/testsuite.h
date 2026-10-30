/** @file
 *    @brief MAVLink comm protocol testsuite generated from lisum.xml
 *    @see https://mavlink.io/en/
 */
#pragma once
#ifndef LISUM_TESTSUITE_H
#define LISUM_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_lisum(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_common(system_id, component_id, last_msg);
    mavlink_test_lisum(system_id, component_id, last_msg);
}
#endif

#include "../common/testsuite.h"


static void mavlink_test_lisum_power_motor_data(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_LISUM_POWER_MOTOR_DATA >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_lisum_power_motor_data_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,157.0,185.0,213.0,241.0,269.0,297.0,325.0,353.0,381.0,409.0,437.0,465.0,493.0,521.0,549.0,577.0,605.0,633.0,661.0,689.0,717.0,745.0,773.0,963503288,963503496,23475,243,54,121,{ 188, 189, 190, 191, 192, 193, 194, 195 },{ 212, 213, 214, 215, 216, 217, 218, 219 }
    };
    mavlink_lisum_power_motor_data_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time = packet_in.time;
        packet1.w_gg = packet_in.w_gg;
        packet1.w_gg_N = packet_in.w_gg_N;
        packet1.w_ft = packet_in.w_ft;
        packet1.w_ft_N = packet_in.w_ft_N;
        packet1.fuel_flow = packet_in.fuel_flow;
        packet1.oil_flow_arm = packet_in.oil_flow_arm;
        packet1.oil_flow_reducer = packet_in.oil_flow_reducer;
        packet1.battery_volt = packet_in.battery_volt;
        packet1.temp_front_bearing = packet_in.temp_front_bearing;
        packet1.temp_rear_bearing = packet_in.temp_rear_bearing;
        packet1.temp_elastic_bearing = packet_in.temp_elastic_bearing;
        packet1.temp_rigid_bearing = packet_in.temp_rigid_bearing;
        packet1.temp_input_oil = packet_in.temp_input_oil;
        packet1.temp_arm_oil = packet_in.temp_arm_oil;
        packet1.temp_reducer_oil = packet_in.temp_reducer_oil;
        packet1.temp_exhaust_fume = packet_in.temp_exhaust_fume;
        packet1.press_arm_oil = packet_in.press_arm_oil;
        packet1.fuel_level = packet_in.fuel_level;
        packet1.oil_level_bearing = packet_in.oil_level_bearing;
        packet1.oil_level_reducer = packet_in.oil_level_reducer;
        packet1.PWM_fuel_pump = packet_in.PWM_fuel_pump;
        packet1.current_fuel_pump = packet_in.current_fuel_pump;
        packet1.PWM_oil_pump = packet_in.PWM_oil_pump;
        packet1.current_oil_pump = packet_in.current_oil_pump;
        packet1.PWM_oil_suction_pump_reducer = packet_in.PWM_oil_suction_pump_reducer;
        packet1.PWM_oil_suction_pump_arm = packet_in.PWM_oil_suction_pump_arm;
        packet1.PWM_oil_pressure_pump = packet_in.PWM_oil_pressure_pump;
        packet1.warning = packet_in.warning;
        packet1.error = packet_in.error;
        packet1.turn_on = packet_in.turn_on;
        packet1.activate = packet_in.activate;
        packet1.valve_state = packet_in.valve_state;
        packet1.pressure_state = packet_in.pressure_state;
        
        mav_array_memcpy(packet1.EvnC, packet_in.EvnC, sizeof(uint8_t)*8);
        mav_array_memcpy(packet1.res, packet_in.res, sizeof(uint8_t)*8);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_LISUM_POWER_MOTOR_DATA_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_LISUM_POWER_MOTOR_DATA_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_power_motor_data_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_lisum_power_motor_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_power_motor_data_pack(system_id, component_id, &msg , packet1.time , packet1.w_gg , packet1.w_gg_N , packet1.w_ft , packet1.w_ft_N , packet1.fuel_flow , packet1.oil_flow_arm , packet1.oil_flow_reducer , packet1.battery_volt , packet1.temp_front_bearing , packet1.temp_rear_bearing , packet1.temp_elastic_bearing , packet1.temp_rigid_bearing , packet1.temp_input_oil , packet1.temp_arm_oil , packet1.temp_reducer_oil , packet1.temp_exhaust_fume , packet1.press_arm_oil , packet1.fuel_level , packet1.oil_level_bearing , packet1.oil_level_reducer , packet1.PWM_fuel_pump , packet1.current_fuel_pump , packet1.PWM_oil_pump , packet1.current_oil_pump , packet1.PWM_oil_suction_pump_reducer , packet1.PWM_oil_suction_pump_arm , packet1.PWM_oil_pressure_pump , packet1.activate , packet1.turn_on , packet1.valve_state , packet1.pressure_state , packet1.warning , packet1.error , packet1.EvnC , packet1.res );
    mavlink_msg_lisum_power_motor_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_power_motor_data_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time , packet1.w_gg , packet1.w_gg_N , packet1.w_ft , packet1.w_ft_N , packet1.fuel_flow , packet1.oil_flow_arm , packet1.oil_flow_reducer , packet1.battery_volt , packet1.temp_front_bearing , packet1.temp_rear_bearing , packet1.temp_elastic_bearing , packet1.temp_rigid_bearing , packet1.temp_input_oil , packet1.temp_arm_oil , packet1.temp_reducer_oil , packet1.temp_exhaust_fume , packet1.press_arm_oil , packet1.fuel_level , packet1.oil_level_bearing , packet1.oil_level_reducer , packet1.PWM_fuel_pump , packet1.current_fuel_pump , packet1.PWM_oil_pump , packet1.current_oil_pump , packet1.PWM_oil_suction_pump_reducer , packet1.PWM_oil_suction_pump_arm , packet1.PWM_oil_pressure_pump , packet1.activate , packet1.turn_on , packet1.valve_state , packet1.pressure_state , packet1.warning , packet1.error , packet1.EvnC , packet1.res );
    mavlink_msg_lisum_power_motor_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_lisum_power_motor_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_power_motor_data_send(MAVLINK_COMM_1 , packet1.time , packet1.w_gg , packet1.w_gg_N , packet1.w_ft , packet1.w_ft_N , packet1.fuel_flow , packet1.oil_flow_arm , packet1.oil_flow_reducer , packet1.battery_volt , packet1.temp_front_bearing , packet1.temp_rear_bearing , packet1.temp_elastic_bearing , packet1.temp_rigid_bearing , packet1.temp_input_oil , packet1.temp_arm_oil , packet1.temp_reducer_oil , packet1.temp_exhaust_fume , packet1.press_arm_oil , packet1.fuel_level , packet1.oil_level_bearing , packet1.oil_level_reducer , packet1.PWM_fuel_pump , packet1.current_fuel_pump , packet1.PWM_oil_pump , packet1.current_oil_pump , packet1.PWM_oil_suction_pump_reducer , packet1.PWM_oil_suction_pump_arm , packet1.PWM_oil_pressure_pump , packet1.activate , packet1.turn_on , packet1.valve_state , packet1.pressure_state , packet1.warning , packet1.error , packet1.EvnC , packet1.res );
    mavlink_msg_lisum_power_motor_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("LISUM_POWER_MOTOR_DATA") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_LISUM_POWER_MOTOR_DATA) != NULL);
#endif
}

static void mavlink_test_lisum_power_motor_scaled_data(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_lisum_power_motor_scaled_data_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,963498504,963498712,18691,18795,18899,19003,19107,19211,19315,19419,19523,19627,19731,19835,19939,20043,20147,20251,20355,20459,20563,20667,20771,20875,20979,21083,233,44,111,{ 178, 179, 180, 181, 182, 183, 184, 185 },{ 202, 203, 204, 205, 206, 207, 208, 209 }
    };
    mavlink_lisum_power_motor_scaled_data_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time = packet_in.time;
        packet1.w_gg = packet_in.w_gg;
        packet1.w_gg_N = packet_in.w_gg_N;
        packet1.w_ft = packet_in.w_ft;
        packet1.w_ft_N = packet_in.w_ft_N;
        packet1.warning = packet_in.warning;
        packet1.error = packet_in.error;
        packet1.fuel_flow = packet_in.fuel_flow;
        packet1.oil_flow_arm = packet_in.oil_flow_arm;
        packet1.oil_flow_reducer = packet_in.oil_flow_reducer;
        packet1.battery_volt = packet_in.battery_volt;
        packet1.temp_front_bearing = packet_in.temp_front_bearing;
        packet1.temp_rear_bearing = packet_in.temp_rear_bearing;
        packet1.temp_elastic_bearing = packet_in.temp_elastic_bearing;
        packet1.temp_rigid_bearing = packet_in.temp_rigid_bearing;
        packet1.temp_input_oil = packet_in.temp_input_oil;
        packet1.temp_arm_oil = packet_in.temp_arm_oil;
        packet1.temp_reducer_oil = packet_in.temp_reducer_oil;
        packet1.temp_exhaust_fume = packet_in.temp_exhaust_fume;
        packet1.press_arm_oil = packet_in.press_arm_oil;
        packet1.fuel_level = packet_in.fuel_level;
        packet1.oil_level_bearing = packet_in.oil_level_bearing;
        packet1.oil_level_reducer = packet_in.oil_level_reducer;
        packet1.PWM_fuel_pump = packet_in.PWM_fuel_pump;
        packet1.current_fuel_pump = packet_in.current_fuel_pump;
        packet1.PWM_oil_pump = packet_in.PWM_oil_pump;
        packet1.current_oil_pump = packet_in.current_oil_pump;
        packet1.PWM_oil_suction_pump_reducer = packet_in.PWM_oil_suction_pump_reducer;
        packet1.PWM_oil_suction_pump_arm = packet_in.PWM_oil_suction_pump_arm;
        packet1.PWM_oil_pressure_pump = packet_in.PWM_oil_pressure_pump;
        packet1.turn_on = packet_in.turn_on;
        packet1.activate = packet_in.activate;
        packet1.valve_state = packet_in.valve_state;
        packet1.pressure_state = packet_in.pressure_state;
        
        mav_array_memcpy(packet1.EvnC, packet_in.EvnC, sizeof(uint8_t)*8);
        mav_array_memcpy(packet1.res, packet_in.res, sizeof(uint8_t)*8);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_power_motor_scaled_data_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_lisum_power_motor_scaled_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_power_motor_scaled_data_pack(system_id, component_id, &msg , packet1.time , packet1.w_gg , packet1.w_gg_N , packet1.w_ft , packet1.w_ft_N , packet1.fuel_flow , packet1.oil_flow_arm , packet1.oil_flow_reducer , packet1.battery_volt , packet1.temp_front_bearing , packet1.temp_rear_bearing , packet1.temp_elastic_bearing , packet1.temp_rigid_bearing , packet1.temp_input_oil , packet1.temp_arm_oil , packet1.temp_reducer_oil , packet1.temp_exhaust_fume , packet1.press_arm_oil , packet1.fuel_level , packet1.oil_level_bearing , packet1.oil_level_reducer , packet1.PWM_fuel_pump , packet1.current_fuel_pump , packet1.PWM_oil_pump , packet1.current_oil_pump , packet1.PWM_oil_suction_pump_reducer , packet1.PWM_oil_suction_pump_arm , packet1.PWM_oil_pressure_pump , packet1.activate , packet1.turn_on , packet1.valve_state , packet1.pressure_state , packet1.warning , packet1.error , packet1.EvnC , packet1.res );
    mavlink_msg_lisum_power_motor_scaled_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_power_motor_scaled_data_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time , packet1.w_gg , packet1.w_gg_N , packet1.w_ft , packet1.w_ft_N , packet1.fuel_flow , packet1.oil_flow_arm , packet1.oil_flow_reducer , packet1.battery_volt , packet1.temp_front_bearing , packet1.temp_rear_bearing , packet1.temp_elastic_bearing , packet1.temp_rigid_bearing , packet1.temp_input_oil , packet1.temp_arm_oil , packet1.temp_reducer_oil , packet1.temp_exhaust_fume , packet1.press_arm_oil , packet1.fuel_level , packet1.oil_level_bearing , packet1.oil_level_reducer , packet1.PWM_fuel_pump , packet1.current_fuel_pump , packet1.PWM_oil_pump , packet1.current_oil_pump , packet1.PWM_oil_suction_pump_reducer , packet1.PWM_oil_suction_pump_arm , packet1.PWM_oil_pressure_pump , packet1.activate , packet1.turn_on , packet1.valve_state , packet1.pressure_state , packet1.warning , packet1.error , packet1.EvnC , packet1.res );
    mavlink_msg_lisum_power_motor_scaled_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_lisum_power_motor_scaled_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_power_motor_scaled_data_send(MAVLINK_COMM_1 , packet1.time , packet1.w_gg , packet1.w_gg_N , packet1.w_ft , packet1.w_ft_N , packet1.fuel_flow , packet1.oil_flow_arm , packet1.oil_flow_reducer , packet1.battery_volt , packet1.temp_front_bearing , packet1.temp_rear_bearing , packet1.temp_elastic_bearing , packet1.temp_rigid_bearing , packet1.temp_input_oil , packet1.temp_arm_oil , packet1.temp_reducer_oil , packet1.temp_exhaust_fume , packet1.press_arm_oil , packet1.fuel_level , packet1.oil_level_bearing , packet1.oil_level_reducer , packet1.PWM_fuel_pump , packet1.current_fuel_pump , packet1.PWM_oil_pump , packet1.current_oil_pump , packet1.PWM_oil_suction_pump_reducer , packet1.PWM_oil_suction_pump_arm , packet1.PWM_oil_pressure_pump , packet1.activate , packet1.turn_on , packet1.valve_state , packet1.pressure_state , packet1.warning , packet1.error , packet1.EvnC , packet1.res );
    mavlink_msg_lisum_power_motor_scaled_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("LISUM_POWER_MOTOR_SCALED_DATA") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_LISUM_POWER_MOTOR_SCALED_DATA) != NULL);
#endif
}

static void mavlink_test_lisum_power_hornet_act_data(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_lisum_power_hornet_act_data_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,157.0,185.0,213.0,241.0,269.0,297.0,325.0,353.0,381.0,409.0,437.0,20563,20667,20771,20875,20979,21083,21187,21291
    };
    mavlink_lisum_power_hornet_act_data_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.pos_act1 = packet_in.pos_act1;
        packet1.abs_pos_act1 = packet_in.abs_pos_act1;
        packet1.vel_act1 = packet_in.vel_act1;
        packet1.curr_act1 = packet_in.curr_act1;
        packet1.pos_act2 = packet_in.pos_act2;
        packet1.abs_pos_act2 = packet_in.abs_pos_act2;
        packet1.vel_act2 = packet_in.vel_act2;
        packet1.curr_act2 = packet_in.curr_act2;
        packet1.pos_act3 = packet_in.pos_act3;
        packet1.abs_pos_act3 = packet_in.abs_pos_act3;
        packet1.vel_act3 = packet_in.vel_act3;
        packet1.curr_act3 = packet_in.curr_act3;
        packet1.pos_act4 = packet_in.pos_act4;
        packet1.abs_pos_act4 = packet_in.abs_pos_act4;
        packet1.vel_act4 = packet_in.vel_act4;
        packet1.curr_act4 = packet_in.curr_act4;
        packet1.sw_act1 = packet_in.sw_act1;
        packet1.abs_enc_sw_act1 = packet_in.abs_enc_sw_act1;
        packet1.sw_act2 = packet_in.sw_act2;
        packet1.abs_enc_sw_act2 = packet_in.abs_enc_sw_act2;
        packet1.sw_act3 = packet_in.sw_act3;
        packet1.abs_enc_sw_act3 = packet_in.abs_enc_sw_act3;
        packet1.sw_act4 = packet_in.sw_act4;
        packet1.abs_enc_sw_act4 = packet_in.abs_enc_sw_act4;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_power_hornet_act_data_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_lisum_power_hornet_act_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_power_hornet_act_data_pack(system_id, component_id, &msg , packet1.pos_act1 , packet1.abs_pos_act1 , packet1.vel_act1 , packet1.curr_act1 , packet1.sw_act1 , packet1.abs_enc_sw_act1 , packet1.pos_act2 , packet1.abs_pos_act2 , packet1.vel_act2 , packet1.curr_act2 , packet1.sw_act2 , packet1.abs_enc_sw_act2 , packet1.pos_act3 , packet1.abs_pos_act3 , packet1.vel_act3 , packet1.curr_act3 , packet1.sw_act3 , packet1.abs_enc_sw_act3 , packet1.pos_act4 , packet1.abs_pos_act4 , packet1.vel_act4 , packet1.curr_act4 , packet1.sw_act4 , packet1.abs_enc_sw_act4 );
    mavlink_msg_lisum_power_hornet_act_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_power_hornet_act_data_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.pos_act1 , packet1.abs_pos_act1 , packet1.vel_act1 , packet1.curr_act1 , packet1.sw_act1 , packet1.abs_enc_sw_act1 , packet1.pos_act2 , packet1.abs_pos_act2 , packet1.vel_act2 , packet1.curr_act2 , packet1.sw_act2 , packet1.abs_enc_sw_act2 , packet1.pos_act3 , packet1.abs_pos_act3 , packet1.vel_act3 , packet1.curr_act3 , packet1.sw_act3 , packet1.abs_enc_sw_act3 , packet1.pos_act4 , packet1.abs_pos_act4 , packet1.vel_act4 , packet1.curr_act4 , packet1.sw_act4 , packet1.abs_enc_sw_act4 );
    mavlink_msg_lisum_power_hornet_act_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_lisum_power_hornet_act_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_power_hornet_act_data_send(MAVLINK_COMM_1 , packet1.pos_act1 , packet1.abs_pos_act1 , packet1.vel_act1 , packet1.curr_act1 , packet1.sw_act1 , packet1.abs_enc_sw_act1 , packet1.pos_act2 , packet1.abs_pos_act2 , packet1.vel_act2 , packet1.curr_act2 , packet1.sw_act2 , packet1.abs_enc_sw_act2 , packet1.pos_act3 , packet1.abs_pos_act3 , packet1.vel_act3 , packet1.curr_act3 , packet1.sw_act3 , packet1.abs_enc_sw_act3 , packet1.pos_act4 , packet1.abs_pos_act4 , packet1.vel_act4 , packet1.curr_act4 , packet1.sw_act4 , packet1.abs_enc_sw_act4 );
    mavlink_msg_lisum_power_hornet_act_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("LISUM_POWER_HORNET_ACT_DATA") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA) != NULL);
#endif
}

static void mavlink_test_lisum_sensor_airspeed_data(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_LISUM_SENSOR_AIRSPEED_DATA >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_lisum_sensor_airspeed_data_t packet_in = {
        17.0,45.0,17651,163,230
    };
    mavlink_lisum_sensor_airspeed_data_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.airspeed = packet_in.airspeed;
        packet1.raw_press = packet_in.raw_press;
        packet1.temperature = packet_in.temperature;
        packet1.id = packet_in.id;
        packet1.flags = packet_in.flags;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_LISUM_SENSOR_AIRSPEED_DATA_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_LISUM_SENSOR_AIRSPEED_DATA_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_sensor_airspeed_data_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_lisum_sensor_airspeed_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_sensor_airspeed_data_pack(system_id, component_id, &msg , packet1.id , packet1.airspeed , packet1.temperature , packet1.raw_press , packet1.flags );
    mavlink_msg_lisum_sensor_airspeed_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_sensor_airspeed_data_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.id , packet1.airspeed , packet1.temperature , packet1.raw_press , packet1.flags );
    mavlink_msg_lisum_sensor_airspeed_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_lisum_sensor_airspeed_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_sensor_airspeed_data_send(MAVLINK_COMM_1 , packet1.id , packet1.airspeed , packet1.temperature , packet1.raw_press , packet1.flags );
    mavlink_msg_lisum_sensor_airspeed_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("LISUM_SENSOR_AIRSPEED_DATA") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_LISUM_SENSOR_AIRSPEED_DATA) != NULL);
#endif
}

static void mavlink_test_lisum_gnss_recv_data(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_lisum_gnss_recv_data_t packet_in = {
        123.0,179.0,129.0,157.0,185.0,213.0,241.0,113,180,247,58,125
    };
    mavlink_lisum_gnss_recv_data_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.lon = packet_in.lon;
        packet1.lat = packet_in.lat;
        packet1.alt = packet_in.alt;
        packet1.head = packet_in.head;
        packet1.head_rtk = packet_in.head_rtk;
        packet1.vel_ne = packet_in.vel_ne;
        packet1.vel_d = packet_in.vel_d;
        packet1.dev_id = packet_in.dev_id;
        packet1.fix_type = packet_in.fix_type;
        packet1.carr_sol = packet_in.carr_sol;
        packet1.rtk_head_valid = packet_in.rtk_head_valid;
        packet1.sv_num = packet_in.sv_num;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_gnss_recv_data_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_lisum_gnss_recv_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_gnss_recv_data_pack(system_id, component_id, &msg , packet1.dev_id , packet1.lon , packet1.lat , packet1.alt , packet1.head , packet1.head_rtk , packet1.vel_ne , packet1.vel_d , packet1.fix_type , packet1.carr_sol , packet1.rtk_head_valid , packet1.sv_num );
    mavlink_msg_lisum_gnss_recv_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_gnss_recv_data_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.dev_id , packet1.lon , packet1.lat , packet1.alt , packet1.head , packet1.head_rtk , packet1.vel_ne , packet1.vel_d , packet1.fix_type , packet1.carr_sol , packet1.rtk_head_valid , packet1.sv_num );
    mavlink_msg_lisum_gnss_recv_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_lisum_gnss_recv_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_gnss_recv_data_send(MAVLINK_COMM_1 , packet1.dev_id , packet1.lon , packet1.lat , packet1.alt , packet1.head , packet1.head_rtk , packet1.vel_ne , packet1.vel_d , packet1.fix_type , packet1.carr_sol , packet1.rtk_head_valid , packet1.sv_num );
    mavlink_msg_lisum_gnss_recv_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("LISUM_GNSS_RECV_DATA") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA) != NULL);
#endif
}

static void mavlink_test_lisum_manual_ctrl_hornet(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_lisum_manual_ctrl_hornet_t packet_in = {
        17.0,45.0,73.0,101.0,53
    };
    mavlink_lisum_manual_ctrl_hornet_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.pos_sp_act1 = packet_in.pos_sp_act1;
        packet1.pos_sp_act2 = packet_in.pos_sp_act2;
        packet1.pos_sp_act3 = packet_in.pos_sp_act3;
        packet1.pos_sp_act4 = packet_in.pos_sp_act4;
        packet1.mode = packet_in.mode;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_manual_ctrl_hornet_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_lisum_manual_ctrl_hornet_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_manual_ctrl_hornet_pack(system_id, component_id, &msg , packet1.mode , packet1.pos_sp_act1 , packet1.pos_sp_act2 , packet1.pos_sp_act3 , packet1.pos_sp_act4 );
    mavlink_msg_lisum_manual_ctrl_hornet_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_manual_ctrl_hornet_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.mode , packet1.pos_sp_act1 , packet1.pos_sp_act2 , packet1.pos_sp_act3 , packet1.pos_sp_act4 );
    mavlink_msg_lisum_manual_ctrl_hornet_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_lisum_manual_ctrl_hornet_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_manual_ctrl_hornet_send(MAVLINK_COMM_1 , packet1.mode , packet1.pos_sp_act1 , packet1.pos_sp_act2 , packet1.pos_sp_act3 , packet1.pos_sp_act4 );
    mavlink_msg_lisum_manual_ctrl_hornet_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("LISUM_MANUAL_CTRL_HORNET") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET) != NULL);
#endif
}

static void mavlink_test_lisum_esc_status(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_LISUM_ESC_STATUS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_lisum_esc_status_t packet_in = {
        { 17.0, 18.0 },{ 73.0, 74.0 },{ 129.0, 130.0 },{ 185.0, 186.0 },{ 241.0, 242.0 },{ 297.0, 298.0 },{ 353.0, 354.0 },{ 409.0, 410.0 },{ 465.0, 466.0 },221
    };
    mavlink_lisum_esc_status_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.index = packet_in.index;
        
        mav_array_memcpy(packet1.voltage, packet_in.voltage, sizeof(float)*2);
        mav_array_memcpy(packet1.curr_motor, packet_in.curr_motor, sizeof(float)*2);
        mav_array_memcpy(packet1.current, packet_in.current, sizeof(float)*2);
        mav_array_memcpy(packet1.temp_fet, packet_in.temp_fet, sizeof(float)*2);
        mav_array_memcpy(packet1.temp_motor, packet_in.temp_motor, sizeof(float)*2);
        mav_array_memcpy(packet1.rpm, packet_in.rpm, sizeof(float)*2);
        mav_array_memcpy(packet1.duty, packet_in.duty, sizeof(float)*2);
        mav_array_memcpy(packet1.energy_consumed, packet_in.energy_consumed, sizeof(float)*2);
        mav_array_memcpy(packet1.curr_consumed, packet_in.curr_consumed, sizeof(float)*2);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_LISUM_ESC_STATUS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_LISUM_ESC_STATUS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_esc_status_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_lisum_esc_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_esc_status_pack(system_id, component_id, &msg , packet1.index , packet1.voltage , packet1.curr_motor , packet1.current , packet1.temp_fet , packet1.temp_motor , packet1.rpm , packet1.duty , packet1.energy_consumed , packet1.curr_consumed );
    mavlink_msg_lisum_esc_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_esc_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.index , packet1.voltage , packet1.curr_motor , packet1.current , packet1.temp_fet , packet1.temp_motor , packet1.rpm , packet1.duty , packet1.energy_consumed , packet1.curr_consumed );
    mavlink_msg_lisum_esc_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_lisum_esc_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_esc_status_send(MAVLINK_COMM_1 , packet1.index , packet1.voltage , packet1.curr_motor , packet1.current , packet1.temp_fet , packet1.temp_motor , packet1.rpm , packet1.duty , packet1.energy_consumed , packet1.curr_consumed );
    mavlink_msg_lisum_esc_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("LISUM_ESC_STATUS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_LISUM_ESC_STATUS) != NULL);
#endif
}

static void mavlink_test_lisum_propulsion_tb_status(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_LISUM_PROPULSION_TB_STATUS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_lisum_propulsion_tb_status_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,157.0,185.0,213.0,241.0
    };
    mavlink_lisum_propulsion_tb_status_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.voltage = packet_in.voltage;
        packet1.current = packet_in.current;
        packet1.rpm = packet_in.rpm;
        packet1.temp_motor = packet_in.temp_motor;
        packet1.temp_inverter = packet_in.temp_inverter;
        packet1.temp_ambient = packet_in.temp_ambient;
        packet1.torque = packet_in.torque;
        packet1.thrust = packet_in.thrust;
        packet1.throttle = packet_in.throttle;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_LISUM_PROPULSION_TB_STATUS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_LISUM_PROPULSION_TB_STATUS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_propulsion_tb_status_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_lisum_propulsion_tb_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_propulsion_tb_status_pack(system_id, component_id, &msg , packet1.voltage , packet1.current , packet1.rpm , packet1.temp_motor , packet1.temp_inverter , packet1.temp_ambient , packet1.torque , packet1.thrust , packet1.throttle );
    mavlink_msg_lisum_propulsion_tb_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_propulsion_tb_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.voltage , packet1.current , packet1.rpm , packet1.temp_motor , packet1.temp_inverter , packet1.temp_ambient , packet1.torque , packet1.thrust , packet1.throttle );
    mavlink_msg_lisum_propulsion_tb_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_lisum_propulsion_tb_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_propulsion_tb_status_send(MAVLINK_COMM_1 , packet1.voltage , packet1.current , packet1.rpm , packet1.temp_motor , packet1.temp_inverter , packet1.temp_ambient , packet1.torque , packet1.thrust , packet1.throttle );
    mavlink_msg_lisum_propulsion_tb_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("LISUM_PROPULSION_TB_STATUS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_LISUM_PROPULSION_TB_STATUS) != NULL);
#endif
}

static void mavlink_test_lisum_vesc_set_duty(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_LISUM_VESC_SET_DUTY >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_lisum_vesc_set_duty_t packet_in = {
        17.0,17
    };
    mavlink_lisum_vesc_set_duty_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.duty_cycle = packet_in.duty_cycle;
        packet1.vesc_id = packet_in.vesc_id;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_LISUM_VESC_SET_DUTY_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_LISUM_VESC_SET_DUTY_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_set_duty_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_lisum_vesc_set_duty_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_set_duty_pack(system_id, component_id, &msg , packet1.vesc_id , packet1.duty_cycle );
    mavlink_msg_lisum_vesc_set_duty_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_set_duty_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.vesc_id , packet1.duty_cycle );
    mavlink_msg_lisum_vesc_set_duty_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_lisum_vesc_set_duty_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_set_duty_send(MAVLINK_COMM_1 , packet1.vesc_id , packet1.duty_cycle );
    mavlink_msg_lisum_vesc_set_duty_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("LISUM_VESC_SET_DUTY") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_LISUM_VESC_SET_DUTY) != NULL);
#endif
}

static void mavlink_test_lisum_vesc_set_current(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_lisum_vesc_set_current_t packet_in = {
        17.0,17
    };
    mavlink_lisum_vesc_set_current_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.current = packet_in.current;
        packet1.vesc_id = packet_in.vesc_id;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_set_current_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_lisum_vesc_set_current_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_set_current_pack(system_id, component_id, &msg , packet1.vesc_id , packet1.current );
    mavlink_msg_lisum_vesc_set_current_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_set_current_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.vesc_id , packet1.current );
    mavlink_msg_lisum_vesc_set_current_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_lisum_vesc_set_current_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_set_current_send(MAVLINK_COMM_1 , packet1.vesc_id , packet1.current );
    mavlink_msg_lisum_vesc_set_current_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("LISUM_VESC_SET_CURRENT") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT) != NULL);
#endif
}

static void mavlink_test_lisum_vesc_set_current_brake(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_BRAKE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_lisum_vesc_set_current_brake_t packet_in = {
        17.0,17
    };
    mavlink_lisum_vesc_set_current_brake_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.current = packet_in.current;
        packet1.vesc_id = packet_in.vesc_id;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_BRAKE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_BRAKE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_set_current_brake_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_lisum_vesc_set_current_brake_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_set_current_brake_pack(system_id, component_id, &msg , packet1.vesc_id , packet1.current );
    mavlink_msg_lisum_vesc_set_current_brake_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_set_current_brake_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.vesc_id , packet1.current );
    mavlink_msg_lisum_vesc_set_current_brake_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_lisum_vesc_set_current_brake_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_set_current_brake_send(MAVLINK_COMM_1 , packet1.vesc_id , packet1.current );
    mavlink_msg_lisum_vesc_set_current_brake_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("LISUM_VESC_SET_CURRENT_BRAKE") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_BRAKE) != NULL);
#endif
}

static void mavlink_test_lisum_vesc_set_rpm(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_LISUM_VESC_SET_RPM >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_lisum_vesc_set_rpm_t packet_in = {
        17.0,17
    };
    mavlink_lisum_vesc_set_rpm_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.rpm = packet_in.rpm;
        packet1.vesc_id = packet_in.vesc_id;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_LISUM_VESC_SET_RPM_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_LISUM_VESC_SET_RPM_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_set_rpm_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_lisum_vesc_set_rpm_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_set_rpm_pack(system_id, component_id, &msg , packet1.vesc_id , packet1.rpm );
    mavlink_msg_lisum_vesc_set_rpm_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_set_rpm_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.vesc_id , packet1.rpm );
    mavlink_msg_lisum_vesc_set_rpm_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_lisum_vesc_set_rpm_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_set_rpm_send(MAVLINK_COMM_1 , packet1.vesc_id , packet1.rpm );
    mavlink_msg_lisum_vesc_set_rpm_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("LISUM_VESC_SET_RPM") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_LISUM_VESC_SET_RPM) != NULL);
#endif
}

static void mavlink_test_lisum_vesc_set_pos(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_LISUM_VESC_SET_POS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_lisum_vesc_set_pos_t packet_in = {
        17.0,17
    };
    mavlink_lisum_vesc_set_pos_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.pos = packet_in.pos;
        packet1.vesc_id = packet_in.vesc_id;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_LISUM_VESC_SET_POS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_LISUM_VESC_SET_POS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_set_pos_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_lisum_vesc_set_pos_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_set_pos_pack(system_id, component_id, &msg , packet1.vesc_id , packet1.pos );
    mavlink_msg_lisum_vesc_set_pos_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_set_pos_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.vesc_id , packet1.pos );
    mavlink_msg_lisum_vesc_set_pos_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_lisum_vesc_set_pos_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_set_pos_send(MAVLINK_COMM_1 , packet1.vesc_id , packet1.pos );
    mavlink_msg_lisum_vesc_set_pos_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("LISUM_VESC_SET_POS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_LISUM_VESC_SET_POS) != NULL);
#endif
}

static void mavlink_test_lisum_vesc_ping(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_LISUM_VESC_PING >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_lisum_vesc_ping_t packet_in = {
        5
    };
    mavlink_lisum_vesc_ping_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.vesc_id = packet_in.vesc_id;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_LISUM_VESC_PING_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_LISUM_VESC_PING_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_ping_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_lisum_vesc_ping_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_ping_pack(system_id, component_id, &msg , packet1.vesc_id );
    mavlink_msg_lisum_vesc_ping_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_ping_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.vesc_id );
    mavlink_msg_lisum_vesc_ping_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_lisum_vesc_ping_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_ping_send(MAVLINK_COMM_1 , packet1.vesc_id );
    mavlink_msg_lisum_vesc_ping_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("LISUM_VESC_PING") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_LISUM_VESC_PING) != NULL);
#endif
}

static void mavlink_test_lisum_vesc_status_1(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_LISUM_VESC_STATUS_1 >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_lisum_vesc_status_1_t packet_in = {
        17.0,45.0,73.0,41
    };
    mavlink_lisum_vesc_status_1_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.duty = packet_in.duty;
        packet1.total_current = packet_in.total_current;
        packet1.erpm = packet_in.erpm;
        packet1.vesc_id = packet_in.vesc_id;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_status_1_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_lisum_vesc_status_1_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_status_1_pack(system_id, component_id, &msg , packet1.vesc_id , packet1.duty , packet1.total_current , packet1.erpm );
    mavlink_msg_lisum_vesc_status_1_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_status_1_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.vesc_id , packet1.duty , packet1.total_current , packet1.erpm );
    mavlink_msg_lisum_vesc_status_1_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_lisum_vesc_status_1_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_status_1_send(MAVLINK_COMM_1 , packet1.vesc_id , packet1.duty , packet1.total_current , packet1.erpm );
    mavlink_msg_lisum_vesc_status_1_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("LISUM_VESC_STATUS_1") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_LISUM_VESC_STATUS_1) != NULL);
#endif
}

static void mavlink_test_lisum_vesc_status_2(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_LISUM_VESC_STATUS_2 >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_lisum_vesc_status_2_t packet_in = {
        17.0,45.0,29
    };
    mavlink_lisum_vesc_status_2_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.amp_hours_charged = packet_in.amp_hours_charged;
        packet1.amp_hours = packet_in.amp_hours;
        packet1.vesc_id = packet_in.vesc_id;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_status_2_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_lisum_vesc_status_2_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_status_2_pack(system_id, component_id, &msg , packet1.vesc_id , packet1.amp_hours_charged , packet1.amp_hours );
    mavlink_msg_lisum_vesc_status_2_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_status_2_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.vesc_id , packet1.amp_hours_charged , packet1.amp_hours );
    mavlink_msg_lisum_vesc_status_2_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_lisum_vesc_status_2_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_status_2_send(MAVLINK_COMM_1 , packet1.vesc_id , packet1.amp_hours_charged , packet1.amp_hours );
    mavlink_msg_lisum_vesc_status_2_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("LISUM_VESC_STATUS_2") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_LISUM_VESC_STATUS_2) != NULL);
#endif
}

static void mavlink_test_lisum_vesc_status_3(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_LISUM_VESC_STATUS_3 >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_lisum_vesc_status_3_t packet_in = {
        17.0,45.0,29
    };
    mavlink_lisum_vesc_status_3_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.watt_hours_charged = packet_in.watt_hours_charged;
        packet1.watt_hours = packet_in.watt_hours;
        packet1.vesc_id = packet_in.vesc_id;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_status_3_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_lisum_vesc_status_3_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_status_3_pack(system_id, component_id, &msg , packet1.vesc_id , packet1.watt_hours_charged , packet1.watt_hours );
    mavlink_msg_lisum_vesc_status_3_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_status_3_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.vesc_id , packet1.watt_hours_charged , packet1.watt_hours );
    mavlink_msg_lisum_vesc_status_3_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_lisum_vesc_status_3_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_status_3_send(MAVLINK_COMM_1 , packet1.vesc_id , packet1.watt_hours_charged , packet1.watt_hours );
    mavlink_msg_lisum_vesc_status_3_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("LISUM_VESC_STATUS_3") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_LISUM_VESC_STATUS_3) != NULL);
#endif
}

static void mavlink_test_lisum_vesc_status_4(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_LISUM_VESC_STATUS_4 >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_lisum_vesc_status_4_t packet_in = {
        17.0,45.0,73.0,101.0,53
    };
    mavlink_lisum_vesc_status_4_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.pos = packet_in.pos;
        packet1.current_in = packet_in.current_in;
        packet1.motor_temp = packet_in.motor_temp;
        packet1.fet_temp = packet_in.fet_temp;
        packet1.vesc_id = packet_in.vesc_id;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_status_4_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_lisum_vesc_status_4_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_status_4_pack(system_id, component_id, &msg , packet1.vesc_id , packet1.pos , packet1.current_in , packet1.motor_temp , packet1.fet_temp );
    mavlink_msg_lisum_vesc_status_4_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_status_4_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.vesc_id , packet1.pos , packet1.current_in , packet1.motor_temp , packet1.fet_temp );
    mavlink_msg_lisum_vesc_status_4_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_lisum_vesc_status_4_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_status_4_send(MAVLINK_COMM_1 , packet1.vesc_id , packet1.pos , packet1.current_in , packet1.motor_temp , packet1.fet_temp );
    mavlink_msg_lisum_vesc_status_4_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("LISUM_VESC_STATUS_4") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_LISUM_VESC_STATUS_4) != NULL);
#endif
}

static void mavlink_test_lisum_vesc_status_5(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_LISUM_VESC_STATUS_5 >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_lisum_vesc_status_5_t packet_in = {
        17.0,45.0,29
    };
    mavlink_lisum_vesc_status_5_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.voltage = packet_in.voltage;
        packet1.tachometar = packet_in.tachometar;
        packet1.vesc_id = packet_in.vesc_id;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_status_5_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_lisum_vesc_status_5_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_status_5_pack(system_id, component_id, &msg , packet1.vesc_id , packet1.voltage , packet1.tachometar );
    mavlink_msg_lisum_vesc_status_5_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_status_5_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.vesc_id , packet1.voltage , packet1.tachometar );
    mavlink_msg_lisum_vesc_status_5_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_lisum_vesc_status_5_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_status_5_send(MAVLINK_COMM_1 , packet1.vesc_id , packet1.voltage , packet1.tachometar );
    mavlink_msg_lisum_vesc_status_5_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("LISUM_VESC_STATUS_5") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_LISUM_VESC_STATUS_5) != NULL);
#endif
}

static void mavlink_test_lisum_vesc_status_6(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_LISUM_VESC_STATUS_6 >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_lisum_vesc_status_6_t packet_in = {
        17235,17339,17443,17547,29
    };
    mavlink_lisum_vesc_status_6_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.ppm = packet_in.ppm;
        packet1.adc1 = packet_in.adc1;
        packet1.adc2 = packet_in.adc2;
        packet1.adc3 = packet_in.adc3;
        packet1.vesc_id = packet_in.vesc_id;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_status_6_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_lisum_vesc_status_6_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_status_6_pack(system_id, component_id, &msg , packet1.vesc_id , packet1.ppm , packet1.adc1 , packet1.adc2 , packet1.adc3 );
    mavlink_msg_lisum_vesc_status_6_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_status_6_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.vesc_id , packet1.ppm , packet1.adc1 , packet1.adc2 , packet1.adc3 );
    mavlink_msg_lisum_vesc_status_6_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_lisum_vesc_status_6_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_lisum_vesc_status_6_send(MAVLINK_COMM_1 , packet1.vesc_id , packet1.ppm , packet1.adc1 , packet1.adc2 , packet1.adc3 );
    mavlink_msg_lisum_vesc_status_6_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("LISUM_VESC_STATUS_6") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_LISUM_VESC_STATUS_6) != NULL);
#endif
}

static void mavlink_test_lisum(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_lisum_power_motor_data(system_id, component_id, last_msg);
    mavlink_test_lisum_power_motor_scaled_data(system_id, component_id, last_msg);
    mavlink_test_lisum_power_hornet_act_data(system_id, component_id, last_msg);
    mavlink_test_lisum_sensor_airspeed_data(system_id, component_id, last_msg);
    mavlink_test_lisum_gnss_recv_data(system_id, component_id, last_msg);
    mavlink_test_lisum_manual_ctrl_hornet(system_id, component_id, last_msg);
    mavlink_test_lisum_esc_status(system_id, component_id, last_msg);
    mavlink_test_lisum_propulsion_tb_status(system_id, component_id, last_msg);
    mavlink_test_lisum_vesc_set_duty(system_id, component_id, last_msg);
    mavlink_test_lisum_vesc_set_current(system_id, component_id, last_msg);
    mavlink_test_lisum_vesc_set_current_brake(system_id, component_id, last_msg);
    mavlink_test_lisum_vesc_set_rpm(system_id, component_id, last_msg);
    mavlink_test_lisum_vesc_set_pos(system_id, component_id, last_msg);
    mavlink_test_lisum_vesc_ping(system_id, component_id, last_msg);
    mavlink_test_lisum_vesc_status_1(system_id, component_id, last_msg);
    mavlink_test_lisum_vesc_status_2(system_id, component_id, last_msg);
    mavlink_test_lisum_vesc_status_3(system_id, component_id, last_msg);
    mavlink_test_lisum_vesc_status_4(system_id, component_id, last_msg);
    mavlink_test_lisum_vesc_status_5(system_id, component_id, last_msg);
    mavlink_test_lisum_vesc_status_6(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // LISUM_TESTSUITE_H
