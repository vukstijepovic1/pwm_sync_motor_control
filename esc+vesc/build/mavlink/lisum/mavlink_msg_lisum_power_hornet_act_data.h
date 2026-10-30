#pragma once
// MESSAGE LISUM_POWER_HORNET_ACT_DATA PACKING

#define MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA 59080


typedef struct __mavlink_lisum_power_hornet_act_data_t {
 float pos_act1; /*< [mm] Position of Actuator 1*/
 float abs_pos_act1; /*< [mm] Absolute Position of Actuator 1*/
 float vel_act1; /*< [mm/s] Velocity of Actuator 1*/
 float curr_act1; /*< [A] Current of Actuator 1*/
 float pos_act2; /*< [mm] Position of Actuator 2*/
 float abs_pos_act2; /*< [mm] Absolute Position of Actuator 2*/
 float vel_act2; /*< [mm/s] Velocity of Actuator 2*/
 float curr_act2; /*< [A] Current of Actuator 2*/
 float pos_act3; /*< [mm] Position of Actuator 3*/
 float abs_pos_act3; /*< [mm] Absolute Position of Actuator 3*/
 float vel_act3; /*< [mm/s] Velocity of Actuator 3*/
 float curr_act3; /*< [A] Current of Actuator 3*/
 float pos_act4; /*< [mm] Position of Actuator 4*/
 float abs_pos_act4; /*< [mm] Absolute Position of Actuator 4*/
 float vel_act4; /*< [mm/s] Velocity of Actuator 4*/
 float curr_act4; /*< [A] Current of Actuator 4*/
 uint16_t sw_act1; /*<  Statusword of Actuator 1*/
 uint16_t abs_enc_sw_act1; /*<  Absolute encoder statusword of Actuator 1*/
 uint16_t sw_act2; /*<  Statusword of Actuator 2*/
 uint16_t abs_enc_sw_act2; /*<  Absolute encoder statusword of Actuator 2*/
 uint16_t sw_act3; /*<  Statusword of Actuator 3*/
 uint16_t abs_enc_sw_act3; /*<  Absolute encoder statusword of Actuator 3*/
 uint16_t sw_act4; /*<  Statusword of Actuator 4*/
 uint16_t abs_enc_sw_act4; /*<  Absolute encoder statusword of Actuator 4*/
} mavlink_lisum_power_hornet_act_data_t;

#define MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_LEN 80
#define MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_MIN_LEN 80
#define MAVLINK_MSG_ID_59080_LEN 80
#define MAVLINK_MSG_ID_59080_MIN_LEN 80

#define MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_CRC 153
#define MAVLINK_MSG_ID_59080_CRC 153



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_LISUM_POWER_HORNET_ACT_DATA { \
    59080, \
    "LISUM_POWER_HORNET_ACT_DATA", \
    24, \
    {  { "pos_act1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_lisum_power_hornet_act_data_t, pos_act1) }, \
         { "abs_pos_act1", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_lisum_power_hornet_act_data_t, abs_pos_act1) }, \
         { "vel_act1", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_lisum_power_hornet_act_data_t, vel_act1) }, \
         { "curr_act1", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_lisum_power_hornet_act_data_t, curr_act1) }, \
         { "sw_act1", NULL, MAVLINK_TYPE_UINT16_T, 0, 64, offsetof(mavlink_lisum_power_hornet_act_data_t, sw_act1) }, \
         { "abs_enc_sw_act1", NULL, MAVLINK_TYPE_UINT16_T, 0, 66, offsetof(mavlink_lisum_power_hornet_act_data_t, abs_enc_sw_act1) }, \
         { "pos_act2", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_lisum_power_hornet_act_data_t, pos_act2) }, \
         { "abs_pos_act2", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_lisum_power_hornet_act_data_t, abs_pos_act2) }, \
         { "vel_act2", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_lisum_power_hornet_act_data_t, vel_act2) }, \
         { "curr_act2", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_lisum_power_hornet_act_data_t, curr_act2) }, \
         { "sw_act2", NULL, MAVLINK_TYPE_UINT16_T, 0, 68, offsetof(mavlink_lisum_power_hornet_act_data_t, sw_act2) }, \
         { "abs_enc_sw_act2", NULL, MAVLINK_TYPE_UINT16_T, 0, 70, offsetof(mavlink_lisum_power_hornet_act_data_t, abs_enc_sw_act2) }, \
         { "pos_act3", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_lisum_power_hornet_act_data_t, pos_act3) }, \
         { "abs_pos_act3", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_lisum_power_hornet_act_data_t, abs_pos_act3) }, \
         { "vel_act3", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_lisum_power_hornet_act_data_t, vel_act3) }, \
         { "curr_act3", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_lisum_power_hornet_act_data_t, curr_act3) }, \
         { "sw_act3", NULL, MAVLINK_TYPE_UINT16_T, 0, 72, offsetof(mavlink_lisum_power_hornet_act_data_t, sw_act3) }, \
         { "abs_enc_sw_act3", NULL, MAVLINK_TYPE_UINT16_T, 0, 74, offsetof(mavlink_lisum_power_hornet_act_data_t, abs_enc_sw_act3) }, \
         { "pos_act4", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_lisum_power_hornet_act_data_t, pos_act4) }, \
         { "abs_pos_act4", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_lisum_power_hornet_act_data_t, abs_pos_act4) }, \
         { "vel_act4", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_lisum_power_hornet_act_data_t, vel_act4) }, \
         { "curr_act4", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_lisum_power_hornet_act_data_t, curr_act4) }, \
         { "sw_act4", NULL, MAVLINK_TYPE_UINT16_T, 0, 76, offsetof(mavlink_lisum_power_hornet_act_data_t, sw_act4) }, \
         { "abs_enc_sw_act4", NULL, MAVLINK_TYPE_UINT16_T, 0, 78, offsetof(mavlink_lisum_power_hornet_act_data_t, abs_enc_sw_act4) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_LISUM_POWER_HORNET_ACT_DATA { \
    "LISUM_POWER_HORNET_ACT_DATA", \
    24, \
    {  { "pos_act1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_lisum_power_hornet_act_data_t, pos_act1) }, \
         { "abs_pos_act1", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_lisum_power_hornet_act_data_t, abs_pos_act1) }, \
         { "vel_act1", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_lisum_power_hornet_act_data_t, vel_act1) }, \
         { "curr_act1", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_lisum_power_hornet_act_data_t, curr_act1) }, \
         { "sw_act1", NULL, MAVLINK_TYPE_UINT16_T, 0, 64, offsetof(mavlink_lisum_power_hornet_act_data_t, sw_act1) }, \
         { "abs_enc_sw_act1", NULL, MAVLINK_TYPE_UINT16_T, 0, 66, offsetof(mavlink_lisum_power_hornet_act_data_t, abs_enc_sw_act1) }, \
         { "pos_act2", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_lisum_power_hornet_act_data_t, pos_act2) }, \
         { "abs_pos_act2", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_lisum_power_hornet_act_data_t, abs_pos_act2) }, \
         { "vel_act2", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_lisum_power_hornet_act_data_t, vel_act2) }, \
         { "curr_act2", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_lisum_power_hornet_act_data_t, curr_act2) }, \
         { "sw_act2", NULL, MAVLINK_TYPE_UINT16_T, 0, 68, offsetof(mavlink_lisum_power_hornet_act_data_t, sw_act2) }, \
         { "abs_enc_sw_act2", NULL, MAVLINK_TYPE_UINT16_T, 0, 70, offsetof(mavlink_lisum_power_hornet_act_data_t, abs_enc_sw_act2) }, \
         { "pos_act3", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_lisum_power_hornet_act_data_t, pos_act3) }, \
         { "abs_pos_act3", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_lisum_power_hornet_act_data_t, abs_pos_act3) }, \
         { "vel_act3", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_lisum_power_hornet_act_data_t, vel_act3) }, \
         { "curr_act3", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_lisum_power_hornet_act_data_t, curr_act3) }, \
         { "sw_act3", NULL, MAVLINK_TYPE_UINT16_T, 0, 72, offsetof(mavlink_lisum_power_hornet_act_data_t, sw_act3) }, \
         { "abs_enc_sw_act3", NULL, MAVLINK_TYPE_UINT16_T, 0, 74, offsetof(mavlink_lisum_power_hornet_act_data_t, abs_enc_sw_act3) }, \
         { "pos_act4", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_lisum_power_hornet_act_data_t, pos_act4) }, \
         { "abs_pos_act4", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_lisum_power_hornet_act_data_t, abs_pos_act4) }, \
         { "vel_act4", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_lisum_power_hornet_act_data_t, vel_act4) }, \
         { "curr_act4", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_lisum_power_hornet_act_data_t, curr_act4) }, \
         { "sw_act4", NULL, MAVLINK_TYPE_UINT16_T, 0, 76, offsetof(mavlink_lisum_power_hornet_act_data_t, sw_act4) }, \
         { "abs_enc_sw_act4", NULL, MAVLINK_TYPE_UINT16_T, 0, 78, offsetof(mavlink_lisum_power_hornet_act_data_t, abs_enc_sw_act4) }, \
         } \
}
#endif

/**
 * @brief Pack a lisum_power_hornet_act_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param pos_act1 [mm] Position of Actuator 1
 * @param abs_pos_act1 [mm] Absolute Position of Actuator 1
 * @param vel_act1 [mm/s] Velocity of Actuator 1
 * @param curr_act1 [A] Current of Actuator 1
 * @param sw_act1  Statusword of Actuator 1
 * @param abs_enc_sw_act1  Absolute encoder statusword of Actuator 1
 * @param pos_act2 [mm] Position of Actuator 2
 * @param abs_pos_act2 [mm] Absolute Position of Actuator 2
 * @param vel_act2 [mm/s] Velocity of Actuator 2
 * @param curr_act2 [A] Current of Actuator 2
 * @param sw_act2  Statusword of Actuator 2
 * @param abs_enc_sw_act2  Absolute encoder statusword of Actuator 2
 * @param pos_act3 [mm] Position of Actuator 3
 * @param abs_pos_act3 [mm] Absolute Position of Actuator 3
 * @param vel_act3 [mm/s] Velocity of Actuator 3
 * @param curr_act3 [A] Current of Actuator 3
 * @param sw_act3  Statusword of Actuator 3
 * @param abs_enc_sw_act3  Absolute encoder statusword of Actuator 3
 * @param pos_act4 [mm] Position of Actuator 4
 * @param abs_pos_act4 [mm] Absolute Position of Actuator 4
 * @param vel_act4 [mm/s] Velocity of Actuator 4
 * @param curr_act4 [A] Current of Actuator 4
 * @param sw_act4  Statusword of Actuator 4
 * @param abs_enc_sw_act4  Absolute encoder statusword of Actuator 4
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_power_hornet_act_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float pos_act1, float abs_pos_act1, float vel_act1, float curr_act1, uint16_t sw_act1, uint16_t abs_enc_sw_act1, float pos_act2, float abs_pos_act2, float vel_act2, float curr_act2, uint16_t sw_act2, uint16_t abs_enc_sw_act2, float pos_act3, float abs_pos_act3, float vel_act3, float curr_act3, uint16_t sw_act3, uint16_t abs_enc_sw_act3, float pos_act4, float abs_pos_act4, float vel_act4, float curr_act4, uint16_t sw_act4, uint16_t abs_enc_sw_act4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_LEN];
    _mav_put_float(buf, 0, pos_act1);
    _mav_put_float(buf, 4, abs_pos_act1);
    _mav_put_float(buf, 8, vel_act1);
    _mav_put_float(buf, 12, curr_act1);
    _mav_put_float(buf, 16, pos_act2);
    _mav_put_float(buf, 20, abs_pos_act2);
    _mav_put_float(buf, 24, vel_act2);
    _mav_put_float(buf, 28, curr_act2);
    _mav_put_float(buf, 32, pos_act3);
    _mav_put_float(buf, 36, abs_pos_act3);
    _mav_put_float(buf, 40, vel_act3);
    _mav_put_float(buf, 44, curr_act3);
    _mav_put_float(buf, 48, pos_act4);
    _mav_put_float(buf, 52, abs_pos_act4);
    _mav_put_float(buf, 56, vel_act4);
    _mav_put_float(buf, 60, curr_act4);
    _mav_put_uint16_t(buf, 64, sw_act1);
    _mav_put_uint16_t(buf, 66, abs_enc_sw_act1);
    _mav_put_uint16_t(buf, 68, sw_act2);
    _mav_put_uint16_t(buf, 70, abs_enc_sw_act2);
    _mav_put_uint16_t(buf, 72, sw_act3);
    _mav_put_uint16_t(buf, 74, abs_enc_sw_act3);
    _mav_put_uint16_t(buf, 76, sw_act4);
    _mav_put_uint16_t(buf, 78, abs_enc_sw_act4);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_LEN);
#else
    mavlink_lisum_power_hornet_act_data_t packet;
    packet.pos_act1 = pos_act1;
    packet.abs_pos_act1 = abs_pos_act1;
    packet.vel_act1 = vel_act1;
    packet.curr_act1 = curr_act1;
    packet.pos_act2 = pos_act2;
    packet.abs_pos_act2 = abs_pos_act2;
    packet.vel_act2 = vel_act2;
    packet.curr_act2 = curr_act2;
    packet.pos_act3 = pos_act3;
    packet.abs_pos_act3 = abs_pos_act3;
    packet.vel_act3 = vel_act3;
    packet.curr_act3 = curr_act3;
    packet.pos_act4 = pos_act4;
    packet.abs_pos_act4 = abs_pos_act4;
    packet.vel_act4 = vel_act4;
    packet.curr_act4 = curr_act4;
    packet.sw_act1 = sw_act1;
    packet.abs_enc_sw_act1 = abs_enc_sw_act1;
    packet.sw_act2 = sw_act2;
    packet.abs_enc_sw_act2 = abs_enc_sw_act2;
    packet.sw_act3 = sw_act3;
    packet.abs_enc_sw_act3 = abs_enc_sw_act3;
    packet.sw_act4 = sw_act4;
    packet.abs_enc_sw_act4 = abs_enc_sw_act4;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_MIN_LEN, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_LEN, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_CRC);
}

/**
 * @brief Pack a lisum_power_hornet_act_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param pos_act1 [mm] Position of Actuator 1
 * @param abs_pos_act1 [mm] Absolute Position of Actuator 1
 * @param vel_act1 [mm/s] Velocity of Actuator 1
 * @param curr_act1 [A] Current of Actuator 1
 * @param sw_act1  Statusword of Actuator 1
 * @param abs_enc_sw_act1  Absolute encoder statusword of Actuator 1
 * @param pos_act2 [mm] Position of Actuator 2
 * @param abs_pos_act2 [mm] Absolute Position of Actuator 2
 * @param vel_act2 [mm/s] Velocity of Actuator 2
 * @param curr_act2 [A] Current of Actuator 2
 * @param sw_act2  Statusword of Actuator 2
 * @param abs_enc_sw_act2  Absolute encoder statusword of Actuator 2
 * @param pos_act3 [mm] Position of Actuator 3
 * @param abs_pos_act3 [mm] Absolute Position of Actuator 3
 * @param vel_act3 [mm/s] Velocity of Actuator 3
 * @param curr_act3 [A] Current of Actuator 3
 * @param sw_act3  Statusword of Actuator 3
 * @param abs_enc_sw_act3  Absolute encoder statusword of Actuator 3
 * @param pos_act4 [mm] Position of Actuator 4
 * @param abs_pos_act4 [mm] Absolute Position of Actuator 4
 * @param vel_act4 [mm/s] Velocity of Actuator 4
 * @param curr_act4 [A] Current of Actuator 4
 * @param sw_act4  Statusword of Actuator 4
 * @param abs_enc_sw_act4  Absolute encoder statusword of Actuator 4
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_power_hornet_act_data_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               float pos_act1, float abs_pos_act1, float vel_act1, float curr_act1, uint16_t sw_act1, uint16_t abs_enc_sw_act1, float pos_act2, float abs_pos_act2, float vel_act2, float curr_act2, uint16_t sw_act2, uint16_t abs_enc_sw_act2, float pos_act3, float abs_pos_act3, float vel_act3, float curr_act3, uint16_t sw_act3, uint16_t abs_enc_sw_act3, float pos_act4, float abs_pos_act4, float vel_act4, float curr_act4, uint16_t sw_act4, uint16_t abs_enc_sw_act4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_LEN];
    _mav_put_float(buf, 0, pos_act1);
    _mav_put_float(buf, 4, abs_pos_act1);
    _mav_put_float(buf, 8, vel_act1);
    _mav_put_float(buf, 12, curr_act1);
    _mav_put_float(buf, 16, pos_act2);
    _mav_put_float(buf, 20, abs_pos_act2);
    _mav_put_float(buf, 24, vel_act2);
    _mav_put_float(buf, 28, curr_act2);
    _mav_put_float(buf, 32, pos_act3);
    _mav_put_float(buf, 36, abs_pos_act3);
    _mav_put_float(buf, 40, vel_act3);
    _mav_put_float(buf, 44, curr_act3);
    _mav_put_float(buf, 48, pos_act4);
    _mav_put_float(buf, 52, abs_pos_act4);
    _mav_put_float(buf, 56, vel_act4);
    _mav_put_float(buf, 60, curr_act4);
    _mav_put_uint16_t(buf, 64, sw_act1);
    _mav_put_uint16_t(buf, 66, abs_enc_sw_act1);
    _mav_put_uint16_t(buf, 68, sw_act2);
    _mav_put_uint16_t(buf, 70, abs_enc_sw_act2);
    _mav_put_uint16_t(buf, 72, sw_act3);
    _mav_put_uint16_t(buf, 74, abs_enc_sw_act3);
    _mav_put_uint16_t(buf, 76, sw_act4);
    _mav_put_uint16_t(buf, 78, abs_enc_sw_act4);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_LEN);
#else
    mavlink_lisum_power_hornet_act_data_t packet;
    packet.pos_act1 = pos_act1;
    packet.abs_pos_act1 = abs_pos_act1;
    packet.vel_act1 = vel_act1;
    packet.curr_act1 = curr_act1;
    packet.pos_act2 = pos_act2;
    packet.abs_pos_act2 = abs_pos_act2;
    packet.vel_act2 = vel_act2;
    packet.curr_act2 = curr_act2;
    packet.pos_act3 = pos_act3;
    packet.abs_pos_act3 = abs_pos_act3;
    packet.vel_act3 = vel_act3;
    packet.curr_act3 = curr_act3;
    packet.pos_act4 = pos_act4;
    packet.abs_pos_act4 = abs_pos_act4;
    packet.vel_act4 = vel_act4;
    packet.curr_act4 = curr_act4;
    packet.sw_act1 = sw_act1;
    packet.abs_enc_sw_act1 = abs_enc_sw_act1;
    packet.sw_act2 = sw_act2;
    packet.abs_enc_sw_act2 = abs_enc_sw_act2;
    packet.sw_act3 = sw_act3;
    packet.abs_enc_sw_act3 = abs_enc_sw_act3;
    packet.sw_act4 = sw_act4;
    packet.abs_enc_sw_act4 = abs_enc_sw_act4;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_MIN_LEN, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_LEN, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_MIN_LEN, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_LEN);
#endif
}

/**
 * @brief Pack a lisum_power_hornet_act_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pos_act1 [mm] Position of Actuator 1
 * @param abs_pos_act1 [mm] Absolute Position of Actuator 1
 * @param vel_act1 [mm/s] Velocity of Actuator 1
 * @param curr_act1 [A] Current of Actuator 1
 * @param sw_act1  Statusword of Actuator 1
 * @param abs_enc_sw_act1  Absolute encoder statusword of Actuator 1
 * @param pos_act2 [mm] Position of Actuator 2
 * @param abs_pos_act2 [mm] Absolute Position of Actuator 2
 * @param vel_act2 [mm/s] Velocity of Actuator 2
 * @param curr_act2 [A] Current of Actuator 2
 * @param sw_act2  Statusword of Actuator 2
 * @param abs_enc_sw_act2  Absolute encoder statusword of Actuator 2
 * @param pos_act3 [mm] Position of Actuator 3
 * @param abs_pos_act3 [mm] Absolute Position of Actuator 3
 * @param vel_act3 [mm/s] Velocity of Actuator 3
 * @param curr_act3 [A] Current of Actuator 3
 * @param sw_act3  Statusword of Actuator 3
 * @param abs_enc_sw_act3  Absolute encoder statusword of Actuator 3
 * @param pos_act4 [mm] Position of Actuator 4
 * @param abs_pos_act4 [mm] Absolute Position of Actuator 4
 * @param vel_act4 [mm/s] Velocity of Actuator 4
 * @param curr_act4 [A] Current of Actuator 4
 * @param sw_act4  Statusword of Actuator 4
 * @param abs_enc_sw_act4  Absolute encoder statusword of Actuator 4
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_power_hornet_act_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float pos_act1,float abs_pos_act1,float vel_act1,float curr_act1,uint16_t sw_act1,uint16_t abs_enc_sw_act1,float pos_act2,float abs_pos_act2,float vel_act2,float curr_act2,uint16_t sw_act2,uint16_t abs_enc_sw_act2,float pos_act3,float abs_pos_act3,float vel_act3,float curr_act3,uint16_t sw_act3,uint16_t abs_enc_sw_act3,float pos_act4,float abs_pos_act4,float vel_act4,float curr_act4,uint16_t sw_act4,uint16_t abs_enc_sw_act4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_LEN];
    _mav_put_float(buf, 0, pos_act1);
    _mav_put_float(buf, 4, abs_pos_act1);
    _mav_put_float(buf, 8, vel_act1);
    _mav_put_float(buf, 12, curr_act1);
    _mav_put_float(buf, 16, pos_act2);
    _mav_put_float(buf, 20, abs_pos_act2);
    _mav_put_float(buf, 24, vel_act2);
    _mav_put_float(buf, 28, curr_act2);
    _mav_put_float(buf, 32, pos_act3);
    _mav_put_float(buf, 36, abs_pos_act3);
    _mav_put_float(buf, 40, vel_act3);
    _mav_put_float(buf, 44, curr_act3);
    _mav_put_float(buf, 48, pos_act4);
    _mav_put_float(buf, 52, abs_pos_act4);
    _mav_put_float(buf, 56, vel_act4);
    _mav_put_float(buf, 60, curr_act4);
    _mav_put_uint16_t(buf, 64, sw_act1);
    _mav_put_uint16_t(buf, 66, abs_enc_sw_act1);
    _mav_put_uint16_t(buf, 68, sw_act2);
    _mav_put_uint16_t(buf, 70, abs_enc_sw_act2);
    _mav_put_uint16_t(buf, 72, sw_act3);
    _mav_put_uint16_t(buf, 74, abs_enc_sw_act3);
    _mav_put_uint16_t(buf, 76, sw_act4);
    _mav_put_uint16_t(buf, 78, abs_enc_sw_act4);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_LEN);
#else
    mavlink_lisum_power_hornet_act_data_t packet;
    packet.pos_act1 = pos_act1;
    packet.abs_pos_act1 = abs_pos_act1;
    packet.vel_act1 = vel_act1;
    packet.curr_act1 = curr_act1;
    packet.pos_act2 = pos_act2;
    packet.abs_pos_act2 = abs_pos_act2;
    packet.vel_act2 = vel_act2;
    packet.curr_act2 = curr_act2;
    packet.pos_act3 = pos_act3;
    packet.abs_pos_act3 = abs_pos_act3;
    packet.vel_act3 = vel_act3;
    packet.curr_act3 = curr_act3;
    packet.pos_act4 = pos_act4;
    packet.abs_pos_act4 = abs_pos_act4;
    packet.vel_act4 = vel_act4;
    packet.curr_act4 = curr_act4;
    packet.sw_act1 = sw_act1;
    packet.abs_enc_sw_act1 = abs_enc_sw_act1;
    packet.sw_act2 = sw_act2;
    packet.abs_enc_sw_act2 = abs_enc_sw_act2;
    packet.sw_act3 = sw_act3;
    packet.abs_enc_sw_act3 = abs_enc_sw_act3;
    packet.sw_act4 = sw_act4;
    packet.abs_enc_sw_act4 = abs_enc_sw_act4;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_MIN_LEN, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_LEN, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_CRC);
}

/**
 * @brief Encode a lisum_power_hornet_act_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param lisum_power_hornet_act_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_power_hornet_act_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_lisum_power_hornet_act_data_t* lisum_power_hornet_act_data)
{
    return mavlink_msg_lisum_power_hornet_act_data_pack(system_id, component_id, msg, lisum_power_hornet_act_data->pos_act1, lisum_power_hornet_act_data->abs_pos_act1, lisum_power_hornet_act_data->vel_act1, lisum_power_hornet_act_data->curr_act1, lisum_power_hornet_act_data->sw_act1, lisum_power_hornet_act_data->abs_enc_sw_act1, lisum_power_hornet_act_data->pos_act2, lisum_power_hornet_act_data->abs_pos_act2, lisum_power_hornet_act_data->vel_act2, lisum_power_hornet_act_data->curr_act2, lisum_power_hornet_act_data->sw_act2, lisum_power_hornet_act_data->abs_enc_sw_act2, lisum_power_hornet_act_data->pos_act3, lisum_power_hornet_act_data->abs_pos_act3, lisum_power_hornet_act_data->vel_act3, lisum_power_hornet_act_data->curr_act3, lisum_power_hornet_act_data->sw_act3, lisum_power_hornet_act_data->abs_enc_sw_act3, lisum_power_hornet_act_data->pos_act4, lisum_power_hornet_act_data->abs_pos_act4, lisum_power_hornet_act_data->vel_act4, lisum_power_hornet_act_data->curr_act4, lisum_power_hornet_act_data->sw_act4, lisum_power_hornet_act_data->abs_enc_sw_act4);
}

/**
 * @brief Encode a lisum_power_hornet_act_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param lisum_power_hornet_act_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_power_hornet_act_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_lisum_power_hornet_act_data_t* lisum_power_hornet_act_data)
{
    return mavlink_msg_lisum_power_hornet_act_data_pack_chan(system_id, component_id, chan, msg, lisum_power_hornet_act_data->pos_act1, lisum_power_hornet_act_data->abs_pos_act1, lisum_power_hornet_act_data->vel_act1, lisum_power_hornet_act_data->curr_act1, lisum_power_hornet_act_data->sw_act1, lisum_power_hornet_act_data->abs_enc_sw_act1, lisum_power_hornet_act_data->pos_act2, lisum_power_hornet_act_data->abs_pos_act2, lisum_power_hornet_act_data->vel_act2, lisum_power_hornet_act_data->curr_act2, lisum_power_hornet_act_data->sw_act2, lisum_power_hornet_act_data->abs_enc_sw_act2, lisum_power_hornet_act_data->pos_act3, lisum_power_hornet_act_data->abs_pos_act3, lisum_power_hornet_act_data->vel_act3, lisum_power_hornet_act_data->curr_act3, lisum_power_hornet_act_data->sw_act3, lisum_power_hornet_act_data->abs_enc_sw_act3, lisum_power_hornet_act_data->pos_act4, lisum_power_hornet_act_data->abs_pos_act4, lisum_power_hornet_act_data->vel_act4, lisum_power_hornet_act_data->curr_act4, lisum_power_hornet_act_data->sw_act4, lisum_power_hornet_act_data->abs_enc_sw_act4);
}

/**
 * @brief Encode a lisum_power_hornet_act_data struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param lisum_power_hornet_act_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_power_hornet_act_data_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_lisum_power_hornet_act_data_t* lisum_power_hornet_act_data)
{
    return mavlink_msg_lisum_power_hornet_act_data_pack_status(system_id, component_id, _status, msg,  lisum_power_hornet_act_data->pos_act1, lisum_power_hornet_act_data->abs_pos_act1, lisum_power_hornet_act_data->vel_act1, lisum_power_hornet_act_data->curr_act1, lisum_power_hornet_act_data->sw_act1, lisum_power_hornet_act_data->abs_enc_sw_act1, lisum_power_hornet_act_data->pos_act2, lisum_power_hornet_act_data->abs_pos_act2, lisum_power_hornet_act_data->vel_act2, lisum_power_hornet_act_data->curr_act2, lisum_power_hornet_act_data->sw_act2, lisum_power_hornet_act_data->abs_enc_sw_act2, lisum_power_hornet_act_data->pos_act3, lisum_power_hornet_act_data->abs_pos_act3, lisum_power_hornet_act_data->vel_act3, lisum_power_hornet_act_data->curr_act3, lisum_power_hornet_act_data->sw_act3, lisum_power_hornet_act_data->abs_enc_sw_act3, lisum_power_hornet_act_data->pos_act4, lisum_power_hornet_act_data->abs_pos_act4, lisum_power_hornet_act_data->vel_act4, lisum_power_hornet_act_data->curr_act4, lisum_power_hornet_act_data->sw_act4, lisum_power_hornet_act_data->abs_enc_sw_act4);
}

/**
 * @brief Send a lisum_power_hornet_act_data message
 * @param chan MAVLink channel to send the message
 *
 * @param pos_act1 [mm] Position of Actuator 1
 * @param abs_pos_act1 [mm] Absolute Position of Actuator 1
 * @param vel_act1 [mm/s] Velocity of Actuator 1
 * @param curr_act1 [A] Current of Actuator 1
 * @param sw_act1  Statusword of Actuator 1
 * @param abs_enc_sw_act1  Absolute encoder statusword of Actuator 1
 * @param pos_act2 [mm] Position of Actuator 2
 * @param abs_pos_act2 [mm] Absolute Position of Actuator 2
 * @param vel_act2 [mm/s] Velocity of Actuator 2
 * @param curr_act2 [A] Current of Actuator 2
 * @param sw_act2  Statusword of Actuator 2
 * @param abs_enc_sw_act2  Absolute encoder statusword of Actuator 2
 * @param pos_act3 [mm] Position of Actuator 3
 * @param abs_pos_act3 [mm] Absolute Position of Actuator 3
 * @param vel_act3 [mm/s] Velocity of Actuator 3
 * @param curr_act3 [A] Current of Actuator 3
 * @param sw_act3  Statusword of Actuator 3
 * @param abs_enc_sw_act3  Absolute encoder statusword of Actuator 3
 * @param pos_act4 [mm] Position of Actuator 4
 * @param abs_pos_act4 [mm] Absolute Position of Actuator 4
 * @param vel_act4 [mm/s] Velocity of Actuator 4
 * @param curr_act4 [A] Current of Actuator 4
 * @param sw_act4  Statusword of Actuator 4
 * @param abs_enc_sw_act4  Absolute encoder statusword of Actuator 4
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_lisum_power_hornet_act_data_send(mavlink_channel_t chan, float pos_act1, float abs_pos_act1, float vel_act1, float curr_act1, uint16_t sw_act1, uint16_t abs_enc_sw_act1, float pos_act2, float abs_pos_act2, float vel_act2, float curr_act2, uint16_t sw_act2, uint16_t abs_enc_sw_act2, float pos_act3, float abs_pos_act3, float vel_act3, float curr_act3, uint16_t sw_act3, uint16_t abs_enc_sw_act3, float pos_act4, float abs_pos_act4, float vel_act4, float curr_act4, uint16_t sw_act4, uint16_t abs_enc_sw_act4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_LEN];
    _mav_put_float(buf, 0, pos_act1);
    _mav_put_float(buf, 4, abs_pos_act1);
    _mav_put_float(buf, 8, vel_act1);
    _mav_put_float(buf, 12, curr_act1);
    _mav_put_float(buf, 16, pos_act2);
    _mav_put_float(buf, 20, abs_pos_act2);
    _mav_put_float(buf, 24, vel_act2);
    _mav_put_float(buf, 28, curr_act2);
    _mav_put_float(buf, 32, pos_act3);
    _mav_put_float(buf, 36, abs_pos_act3);
    _mav_put_float(buf, 40, vel_act3);
    _mav_put_float(buf, 44, curr_act3);
    _mav_put_float(buf, 48, pos_act4);
    _mav_put_float(buf, 52, abs_pos_act4);
    _mav_put_float(buf, 56, vel_act4);
    _mav_put_float(buf, 60, curr_act4);
    _mav_put_uint16_t(buf, 64, sw_act1);
    _mav_put_uint16_t(buf, 66, abs_enc_sw_act1);
    _mav_put_uint16_t(buf, 68, sw_act2);
    _mav_put_uint16_t(buf, 70, abs_enc_sw_act2);
    _mav_put_uint16_t(buf, 72, sw_act3);
    _mav_put_uint16_t(buf, 74, abs_enc_sw_act3);
    _mav_put_uint16_t(buf, 76, sw_act4);
    _mav_put_uint16_t(buf, 78, abs_enc_sw_act4);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA, buf, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_MIN_LEN, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_LEN, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_CRC);
#else
    mavlink_lisum_power_hornet_act_data_t packet;
    packet.pos_act1 = pos_act1;
    packet.abs_pos_act1 = abs_pos_act1;
    packet.vel_act1 = vel_act1;
    packet.curr_act1 = curr_act1;
    packet.pos_act2 = pos_act2;
    packet.abs_pos_act2 = abs_pos_act2;
    packet.vel_act2 = vel_act2;
    packet.curr_act2 = curr_act2;
    packet.pos_act3 = pos_act3;
    packet.abs_pos_act3 = abs_pos_act3;
    packet.vel_act3 = vel_act3;
    packet.curr_act3 = curr_act3;
    packet.pos_act4 = pos_act4;
    packet.abs_pos_act4 = abs_pos_act4;
    packet.vel_act4 = vel_act4;
    packet.curr_act4 = curr_act4;
    packet.sw_act1 = sw_act1;
    packet.abs_enc_sw_act1 = abs_enc_sw_act1;
    packet.sw_act2 = sw_act2;
    packet.abs_enc_sw_act2 = abs_enc_sw_act2;
    packet.sw_act3 = sw_act3;
    packet.abs_enc_sw_act3 = abs_enc_sw_act3;
    packet.sw_act4 = sw_act4;
    packet.abs_enc_sw_act4 = abs_enc_sw_act4;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA, (const char *)&packet, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_MIN_LEN, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_LEN, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_CRC);
#endif
}

/**
 * @brief Send a lisum_power_hornet_act_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_lisum_power_hornet_act_data_send_struct(mavlink_channel_t chan, const mavlink_lisum_power_hornet_act_data_t* lisum_power_hornet_act_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_lisum_power_hornet_act_data_send(chan, lisum_power_hornet_act_data->pos_act1, lisum_power_hornet_act_data->abs_pos_act1, lisum_power_hornet_act_data->vel_act1, lisum_power_hornet_act_data->curr_act1, lisum_power_hornet_act_data->sw_act1, lisum_power_hornet_act_data->abs_enc_sw_act1, lisum_power_hornet_act_data->pos_act2, lisum_power_hornet_act_data->abs_pos_act2, lisum_power_hornet_act_data->vel_act2, lisum_power_hornet_act_data->curr_act2, lisum_power_hornet_act_data->sw_act2, lisum_power_hornet_act_data->abs_enc_sw_act2, lisum_power_hornet_act_data->pos_act3, lisum_power_hornet_act_data->abs_pos_act3, lisum_power_hornet_act_data->vel_act3, lisum_power_hornet_act_data->curr_act3, lisum_power_hornet_act_data->sw_act3, lisum_power_hornet_act_data->abs_enc_sw_act3, lisum_power_hornet_act_data->pos_act4, lisum_power_hornet_act_data->abs_pos_act4, lisum_power_hornet_act_data->vel_act4, lisum_power_hornet_act_data->curr_act4, lisum_power_hornet_act_data->sw_act4, lisum_power_hornet_act_data->abs_enc_sw_act4);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA, (const char *)lisum_power_hornet_act_data, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_MIN_LEN, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_LEN, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_CRC);
#endif
}

#if MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_lisum_power_hornet_act_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float pos_act1, float abs_pos_act1, float vel_act1, float curr_act1, uint16_t sw_act1, uint16_t abs_enc_sw_act1, float pos_act2, float abs_pos_act2, float vel_act2, float curr_act2, uint16_t sw_act2, uint16_t abs_enc_sw_act2, float pos_act3, float abs_pos_act3, float vel_act3, float curr_act3, uint16_t sw_act3, uint16_t abs_enc_sw_act3, float pos_act4, float abs_pos_act4, float vel_act4, float curr_act4, uint16_t sw_act4, uint16_t abs_enc_sw_act4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, pos_act1);
    _mav_put_float(buf, 4, abs_pos_act1);
    _mav_put_float(buf, 8, vel_act1);
    _mav_put_float(buf, 12, curr_act1);
    _mav_put_float(buf, 16, pos_act2);
    _mav_put_float(buf, 20, abs_pos_act2);
    _mav_put_float(buf, 24, vel_act2);
    _mav_put_float(buf, 28, curr_act2);
    _mav_put_float(buf, 32, pos_act3);
    _mav_put_float(buf, 36, abs_pos_act3);
    _mav_put_float(buf, 40, vel_act3);
    _mav_put_float(buf, 44, curr_act3);
    _mav_put_float(buf, 48, pos_act4);
    _mav_put_float(buf, 52, abs_pos_act4);
    _mav_put_float(buf, 56, vel_act4);
    _mav_put_float(buf, 60, curr_act4);
    _mav_put_uint16_t(buf, 64, sw_act1);
    _mav_put_uint16_t(buf, 66, abs_enc_sw_act1);
    _mav_put_uint16_t(buf, 68, sw_act2);
    _mav_put_uint16_t(buf, 70, abs_enc_sw_act2);
    _mav_put_uint16_t(buf, 72, sw_act3);
    _mav_put_uint16_t(buf, 74, abs_enc_sw_act3);
    _mav_put_uint16_t(buf, 76, sw_act4);
    _mav_put_uint16_t(buf, 78, abs_enc_sw_act4);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA, buf, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_MIN_LEN, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_LEN, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_CRC);
#else
    mavlink_lisum_power_hornet_act_data_t *packet = (mavlink_lisum_power_hornet_act_data_t *)msgbuf;
    packet->pos_act1 = pos_act1;
    packet->abs_pos_act1 = abs_pos_act1;
    packet->vel_act1 = vel_act1;
    packet->curr_act1 = curr_act1;
    packet->pos_act2 = pos_act2;
    packet->abs_pos_act2 = abs_pos_act2;
    packet->vel_act2 = vel_act2;
    packet->curr_act2 = curr_act2;
    packet->pos_act3 = pos_act3;
    packet->abs_pos_act3 = abs_pos_act3;
    packet->vel_act3 = vel_act3;
    packet->curr_act3 = curr_act3;
    packet->pos_act4 = pos_act4;
    packet->abs_pos_act4 = abs_pos_act4;
    packet->vel_act4 = vel_act4;
    packet->curr_act4 = curr_act4;
    packet->sw_act1 = sw_act1;
    packet->abs_enc_sw_act1 = abs_enc_sw_act1;
    packet->sw_act2 = sw_act2;
    packet->abs_enc_sw_act2 = abs_enc_sw_act2;
    packet->sw_act3 = sw_act3;
    packet->abs_enc_sw_act3 = abs_enc_sw_act3;
    packet->sw_act4 = sw_act4;
    packet->abs_enc_sw_act4 = abs_enc_sw_act4;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA, (const char *)packet, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_MIN_LEN, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_LEN, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_CRC);
#endif
}
#endif

#endif

// MESSAGE LISUM_POWER_HORNET_ACT_DATA UNPACKING


/**
 * @brief Get field pos_act1 from lisum_power_hornet_act_data message
 *
 * @return [mm] Position of Actuator 1
 */
static inline float mavlink_msg_lisum_power_hornet_act_data_get_pos_act1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field abs_pos_act1 from lisum_power_hornet_act_data message
 *
 * @return [mm] Absolute Position of Actuator 1
 */
static inline float mavlink_msg_lisum_power_hornet_act_data_get_abs_pos_act1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field vel_act1 from lisum_power_hornet_act_data message
 *
 * @return [mm/s] Velocity of Actuator 1
 */
static inline float mavlink_msg_lisum_power_hornet_act_data_get_vel_act1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field curr_act1 from lisum_power_hornet_act_data message
 *
 * @return [A] Current of Actuator 1
 */
static inline float mavlink_msg_lisum_power_hornet_act_data_get_curr_act1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field sw_act1 from lisum_power_hornet_act_data message
 *
 * @return  Statusword of Actuator 1
 */
static inline uint16_t mavlink_msg_lisum_power_hornet_act_data_get_sw_act1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  64);
}

/**
 * @brief Get field abs_enc_sw_act1 from lisum_power_hornet_act_data message
 *
 * @return  Absolute encoder statusword of Actuator 1
 */
static inline uint16_t mavlink_msg_lisum_power_hornet_act_data_get_abs_enc_sw_act1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  66);
}

/**
 * @brief Get field pos_act2 from lisum_power_hornet_act_data message
 *
 * @return [mm] Position of Actuator 2
 */
static inline float mavlink_msg_lisum_power_hornet_act_data_get_pos_act2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field abs_pos_act2 from lisum_power_hornet_act_data message
 *
 * @return [mm] Absolute Position of Actuator 2
 */
static inline float mavlink_msg_lisum_power_hornet_act_data_get_abs_pos_act2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field vel_act2 from lisum_power_hornet_act_data message
 *
 * @return [mm/s] Velocity of Actuator 2
 */
static inline float mavlink_msg_lisum_power_hornet_act_data_get_vel_act2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field curr_act2 from lisum_power_hornet_act_data message
 *
 * @return [A] Current of Actuator 2
 */
static inline float mavlink_msg_lisum_power_hornet_act_data_get_curr_act2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field sw_act2 from lisum_power_hornet_act_data message
 *
 * @return  Statusword of Actuator 2
 */
static inline uint16_t mavlink_msg_lisum_power_hornet_act_data_get_sw_act2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  68);
}

/**
 * @brief Get field abs_enc_sw_act2 from lisum_power_hornet_act_data message
 *
 * @return  Absolute encoder statusword of Actuator 2
 */
static inline uint16_t mavlink_msg_lisum_power_hornet_act_data_get_abs_enc_sw_act2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  70);
}

/**
 * @brief Get field pos_act3 from lisum_power_hornet_act_data message
 *
 * @return [mm] Position of Actuator 3
 */
static inline float mavlink_msg_lisum_power_hornet_act_data_get_pos_act3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field abs_pos_act3 from lisum_power_hornet_act_data message
 *
 * @return [mm] Absolute Position of Actuator 3
 */
static inline float mavlink_msg_lisum_power_hornet_act_data_get_abs_pos_act3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field vel_act3 from lisum_power_hornet_act_data message
 *
 * @return [mm/s] Velocity of Actuator 3
 */
static inline float mavlink_msg_lisum_power_hornet_act_data_get_vel_act3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field curr_act3 from lisum_power_hornet_act_data message
 *
 * @return [A] Current of Actuator 3
 */
static inline float mavlink_msg_lisum_power_hornet_act_data_get_curr_act3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field sw_act3 from lisum_power_hornet_act_data message
 *
 * @return  Statusword of Actuator 3
 */
static inline uint16_t mavlink_msg_lisum_power_hornet_act_data_get_sw_act3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  72);
}

/**
 * @brief Get field abs_enc_sw_act3 from lisum_power_hornet_act_data message
 *
 * @return  Absolute encoder statusword of Actuator 3
 */
static inline uint16_t mavlink_msg_lisum_power_hornet_act_data_get_abs_enc_sw_act3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  74);
}

/**
 * @brief Get field pos_act4 from lisum_power_hornet_act_data message
 *
 * @return [mm] Position of Actuator 4
 */
static inline float mavlink_msg_lisum_power_hornet_act_data_get_pos_act4(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field abs_pos_act4 from lisum_power_hornet_act_data message
 *
 * @return [mm] Absolute Position of Actuator 4
 */
static inline float mavlink_msg_lisum_power_hornet_act_data_get_abs_pos_act4(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Get field vel_act4 from lisum_power_hornet_act_data message
 *
 * @return [mm/s] Velocity of Actuator 4
 */
static inline float mavlink_msg_lisum_power_hornet_act_data_get_vel_act4(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  56);
}

/**
 * @brief Get field curr_act4 from lisum_power_hornet_act_data message
 *
 * @return [A] Current of Actuator 4
 */
static inline float mavlink_msg_lisum_power_hornet_act_data_get_curr_act4(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  60);
}

/**
 * @brief Get field sw_act4 from lisum_power_hornet_act_data message
 *
 * @return  Statusword of Actuator 4
 */
static inline uint16_t mavlink_msg_lisum_power_hornet_act_data_get_sw_act4(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  76);
}

/**
 * @brief Get field abs_enc_sw_act4 from lisum_power_hornet_act_data message
 *
 * @return  Absolute encoder statusword of Actuator 4
 */
static inline uint16_t mavlink_msg_lisum_power_hornet_act_data_get_abs_enc_sw_act4(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  78);
}

/**
 * @brief Decode a lisum_power_hornet_act_data message into a struct
 *
 * @param msg The message to decode
 * @param lisum_power_hornet_act_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_lisum_power_hornet_act_data_decode(const mavlink_message_t* msg, mavlink_lisum_power_hornet_act_data_t* lisum_power_hornet_act_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    lisum_power_hornet_act_data->pos_act1 = mavlink_msg_lisum_power_hornet_act_data_get_pos_act1(msg);
    lisum_power_hornet_act_data->abs_pos_act1 = mavlink_msg_lisum_power_hornet_act_data_get_abs_pos_act1(msg);
    lisum_power_hornet_act_data->vel_act1 = mavlink_msg_lisum_power_hornet_act_data_get_vel_act1(msg);
    lisum_power_hornet_act_data->curr_act1 = mavlink_msg_lisum_power_hornet_act_data_get_curr_act1(msg);
    lisum_power_hornet_act_data->pos_act2 = mavlink_msg_lisum_power_hornet_act_data_get_pos_act2(msg);
    lisum_power_hornet_act_data->abs_pos_act2 = mavlink_msg_lisum_power_hornet_act_data_get_abs_pos_act2(msg);
    lisum_power_hornet_act_data->vel_act2 = mavlink_msg_lisum_power_hornet_act_data_get_vel_act2(msg);
    lisum_power_hornet_act_data->curr_act2 = mavlink_msg_lisum_power_hornet_act_data_get_curr_act2(msg);
    lisum_power_hornet_act_data->pos_act3 = mavlink_msg_lisum_power_hornet_act_data_get_pos_act3(msg);
    lisum_power_hornet_act_data->abs_pos_act3 = mavlink_msg_lisum_power_hornet_act_data_get_abs_pos_act3(msg);
    lisum_power_hornet_act_data->vel_act3 = mavlink_msg_lisum_power_hornet_act_data_get_vel_act3(msg);
    lisum_power_hornet_act_data->curr_act3 = mavlink_msg_lisum_power_hornet_act_data_get_curr_act3(msg);
    lisum_power_hornet_act_data->pos_act4 = mavlink_msg_lisum_power_hornet_act_data_get_pos_act4(msg);
    lisum_power_hornet_act_data->abs_pos_act4 = mavlink_msg_lisum_power_hornet_act_data_get_abs_pos_act4(msg);
    lisum_power_hornet_act_data->vel_act4 = mavlink_msg_lisum_power_hornet_act_data_get_vel_act4(msg);
    lisum_power_hornet_act_data->curr_act4 = mavlink_msg_lisum_power_hornet_act_data_get_curr_act4(msg);
    lisum_power_hornet_act_data->sw_act1 = mavlink_msg_lisum_power_hornet_act_data_get_sw_act1(msg);
    lisum_power_hornet_act_data->abs_enc_sw_act1 = mavlink_msg_lisum_power_hornet_act_data_get_abs_enc_sw_act1(msg);
    lisum_power_hornet_act_data->sw_act2 = mavlink_msg_lisum_power_hornet_act_data_get_sw_act2(msg);
    lisum_power_hornet_act_data->abs_enc_sw_act2 = mavlink_msg_lisum_power_hornet_act_data_get_abs_enc_sw_act2(msg);
    lisum_power_hornet_act_data->sw_act3 = mavlink_msg_lisum_power_hornet_act_data_get_sw_act3(msg);
    lisum_power_hornet_act_data->abs_enc_sw_act3 = mavlink_msg_lisum_power_hornet_act_data_get_abs_enc_sw_act3(msg);
    lisum_power_hornet_act_data->sw_act4 = mavlink_msg_lisum_power_hornet_act_data_get_sw_act4(msg);
    lisum_power_hornet_act_data->abs_enc_sw_act4 = mavlink_msg_lisum_power_hornet_act_data_get_abs_enc_sw_act4(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_LEN? msg->len : MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_LEN;
        memset(lisum_power_hornet_act_data, 0, MAVLINK_MSG_ID_LISUM_POWER_HORNET_ACT_DATA_LEN);
    memcpy(lisum_power_hornet_act_data, _MAV_PAYLOAD(msg), len);
#endif
}
