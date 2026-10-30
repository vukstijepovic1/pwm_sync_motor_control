#pragma once
// MESSAGE LISUM_MANUAL_CTRL_HORNET PACKING

#define MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET 59328


typedef struct __mavlink_lisum_manual_ctrl_hornet_t {
 float pos_sp_act1; /*< [mm] Position setpoint Actuator 1*/
 float pos_sp_act2; /*< [mm] Position setpoint Actuator 2*/
 float pos_sp_act3; /*< [mm] Position setpoint Actuator 3*/
 float pos_sp_act4; /*< [mm] Position setpoint Actuator 4*/
 uint8_t mode; /*<  Operational Mode*/
} mavlink_lisum_manual_ctrl_hornet_t;

#define MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_LEN 17
#define MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_MIN_LEN 17
#define MAVLINK_MSG_ID_59328_LEN 17
#define MAVLINK_MSG_ID_59328_MIN_LEN 17

#define MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_CRC 27
#define MAVLINK_MSG_ID_59328_CRC 27



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_LISUM_MANUAL_CTRL_HORNET { \
    59328, \
    "LISUM_MANUAL_CTRL_HORNET", \
    5, \
    {  { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_lisum_manual_ctrl_hornet_t, mode) }, \
         { "pos_sp_act1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_lisum_manual_ctrl_hornet_t, pos_sp_act1) }, \
         { "pos_sp_act2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_lisum_manual_ctrl_hornet_t, pos_sp_act2) }, \
         { "pos_sp_act3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_lisum_manual_ctrl_hornet_t, pos_sp_act3) }, \
         { "pos_sp_act4", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_lisum_manual_ctrl_hornet_t, pos_sp_act4) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_LISUM_MANUAL_CTRL_HORNET { \
    "LISUM_MANUAL_CTRL_HORNET", \
    5, \
    {  { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_lisum_manual_ctrl_hornet_t, mode) }, \
         { "pos_sp_act1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_lisum_manual_ctrl_hornet_t, pos_sp_act1) }, \
         { "pos_sp_act2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_lisum_manual_ctrl_hornet_t, pos_sp_act2) }, \
         { "pos_sp_act3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_lisum_manual_ctrl_hornet_t, pos_sp_act3) }, \
         { "pos_sp_act4", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_lisum_manual_ctrl_hornet_t, pos_sp_act4) }, \
         } \
}
#endif

/**
 * @brief Pack a lisum_manual_ctrl_hornet message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param mode  Operational Mode
 * @param pos_sp_act1 [mm] Position setpoint Actuator 1
 * @param pos_sp_act2 [mm] Position setpoint Actuator 2
 * @param pos_sp_act3 [mm] Position setpoint Actuator 3
 * @param pos_sp_act4 [mm] Position setpoint Actuator 4
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_manual_ctrl_hornet_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t mode, float pos_sp_act1, float pos_sp_act2, float pos_sp_act3, float pos_sp_act4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_LEN];
    _mav_put_float(buf, 0, pos_sp_act1);
    _mav_put_float(buf, 4, pos_sp_act2);
    _mav_put_float(buf, 8, pos_sp_act3);
    _mav_put_float(buf, 12, pos_sp_act4);
    _mav_put_uint8_t(buf, 16, mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_LEN);
#else
    mavlink_lisum_manual_ctrl_hornet_t packet;
    packet.pos_sp_act1 = pos_sp_act1;
    packet.pos_sp_act2 = pos_sp_act2;
    packet.pos_sp_act3 = pos_sp_act3;
    packet.pos_sp_act4 = pos_sp_act4;
    packet.mode = mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_MIN_LEN, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_LEN, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_CRC);
}

/**
 * @brief Pack a lisum_manual_ctrl_hornet message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param mode  Operational Mode
 * @param pos_sp_act1 [mm] Position setpoint Actuator 1
 * @param pos_sp_act2 [mm] Position setpoint Actuator 2
 * @param pos_sp_act3 [mm] Position setpoint Actuator 3
 * @param pos_sp_act4 [mm] Position setpoint Actuator 4
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_manual_ctrl_hornet_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t mode, float pos_sp_act1, float pos_sp_act2, float pos_sp_act3, float pos_sp_act4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_LEN];
    _mav_put_float(buf, 0, pos_sp_act1);
    _mav_put_float(buf, 4, pos_sp_act2);
    _mav_put_float(buf, 8, pos_sp_act3);
    _mav_put_float(buf, 12, pos_sp_act4);
    _mav_put_uint8_t(buf, 16, mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_LEN);
#else
    mavlink_lisum_manual_ctrl_hornet_t packet;
    packet.pos_sp_act1 = pos_sp_act1;
    packet.pos_sp_act2 = pos_sp_act2;
    packet.pos_sp_act3 = pos_sp_act3;
    packet.pos_sp_act4 = pos_sp_act4;
    packet.mode = mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_MIN_LEN, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_LEN, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_MIN_LEN, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_LEN);
#endif
}

/**
 * @brief Pack a lisum_manual_ctrl_hornet message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mode  Operational Mode
 * @param pos_sp_act1 [mm] Position setpoint Actuator 1
 * @param pos_sp_act2 [mm] Position setpoint Actuator 2
 * @param pos_sp_act3 [mm] Position setpoint Actuator 3
 * @param pos_sp_act4 [mm] Position setpoint Actuator 4
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_manual_ctrl_hornet_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t mode,float pos_sp_act1,float pos_sp_act2,float pos_sp_act3,float pos_sp_act4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_LEN];
    _mav_put_float(buf, 0, pos_sp_act1);
    _mav_put_float(buf, 4, pos_sp_act2);
    _mav_put_float(buf, 8, pos_sp_act3);
    _mav_put_float(buf, 12, pos_sp_act4);
    _mav_put_uint8_t(buf, 16, mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_LEN);
#else
    mavlink_lisum_manual_ctrl_hornet_t packet;
    packet.pos_sp_act1 = pos_sp_act1;
    packet.pos_sp_act2 = pos_sp_act2;
    packet.pos_sp_act3 = pos_sp_act3;
    packet.pos_sp_act4 = pos_sp_act4;
    packet.mode = mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_MIN_LEN, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_LEN, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_CRC);
}

/**
 * @brief Encode a lisum_manual_ctrl_hornet struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param lisum_manual_ctrl_hornet C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_manual_ctrl_hornet_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_lisum_manual_ctrl_hornet_t* lisum_manual_ctrl_hornet)
{
    return mavlink_msg_lisum_manual_ctrl_hornet_pack(system_id, component_id, msg, lisum_manual_ctrl_hornet->mode, lisum_manual_ctrl_hornet->pos_sp_act1, lisum_manual_ctrl_hornet->pos_sp_act2, lisum_manual_ctrl_hornet->pos_sp_act3, lisum_manual_ctrl_hornet->pos_sp_act4);
}

/**
 * @brief Encode a lisum_manual_ctrl_hornet struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param lisum_manual_ctrl_hornet C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_manual_ctrl_hornet_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_lisum_manual_ctrl_hornet_t* lisum_manual_ctrl_hornet)
{
    return mavlink_msg_lisum_manual_ctrl_hornet_pack_chan(system_id, component_id, chan, msg, lisum_manual_ctrl_hornet->mode, lisum_manual_ctrl_hornet->pos_sp_act1, lisum_manual_ctrl_hornet->pos_sp_act2, lisum_manual_ctrl_hornet->pos_sp_act3, lisum_manual_ctrl_hornet->pos_sp_act4);
}

/**
 * @brief Encode a lisum_manual_ctrl_hornet struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param lisum_manual_ctrl_hornet C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_manual_ctrl_hornet_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_lisum_manual_ctrl_hornet_t* lisum_manual_ctrl_hornet)
{
    return mavlink_msg_lisum_manual_ctrl_hornet_pack_status(system_id, component_id, _status, msg,  lisum_manual_ctrl_hornet->mode, lisum_manual_ctrl_hornet->pos_sp_act1, lisum_manual_ctrl_hornet->pos_sp_act2, lisum_manual_ctrl_hornet->pos_sp_act3, lisum_manual_ctrl_hornet->pos_sp_act4);
}

/**
 * @brief Send a lisum_manual_ctrl_hornet message
 * @param chan MAVLink channel to send the message
 *
 * @param mode  Operational Mode
 * @param pos_sp_act1 [mm] Position setpoint Actuator 1
 * @param pos_sp_act2 [mm] Position setpoint Actuator 2
 * @param pos_sp_act3 [mm] Position setpoint Actuator 3
 * @param pos_sp_act4 [mm] Position setpoint Actuator 4
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_lisum_manual_ctrl_hornet_send(mavlink_channel_t chan, uint8_t mode, float pos_sp_act1, float pos_sp_act2, float pos_sp_act3, float pos_sp_act4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_LEN];
    _mav_put_float(buf, 0, pos_sp_act1);
    _mav_put_float(buf, 4, pos_sp_act2);
    _mav_put_float(buf, 8, pos_sp_act3);
    _mav_put_float(buf, 12, pos_sp_act4);
    _mav_put_uint8_t(buf, 16, mode);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET, buf, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_MIN_LEN, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_LEN, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_CRC);
#else
    mavlink_lisum_manual_ctrl_hornet_t packet;
    packet.pos_sp_act1 = pos_sp_act1;
    packet.pos_sp_act2 = pos_sp_act2;
    packet.pos_sp_act3 = pos_sp_act3;
    packet.pos_sp_act4 = pos_sp_act4;
    packet.mode = mode;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET, (const char *)&packet, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_MIN_LEN, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_LEN, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_CRC);
#endif
}

/**
 * @brief Send a lisum_manual_ctrl_hornet message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_lisum_manual_ctrl_hornet_send_struct(mavlink_channel_t chan, const mavlink_lisum_manual_ctrl_hornet_t* lisum_manual_ctrl_hornet)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_lisum_manual_ctrl_hornet_send(chan, lisum_manual_ctrl_hornet->mode, lisum_manual_ctrl_hornet->pos_sp_act1, lisum_manual_ctrl_hornet->pos_sp_act2, lisum_manual_ctrl_hornet->pos_sp_act3, lisum_manual_ctrl_hornet->pos_sp_act4);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET, (const char *)lisum_manual_ctrl_hornet, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_MIN_LEN, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_LEN, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_CRC);
#endif
}

#if MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_lisum_manual_ctrl_hornet_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t mode, float pos_sp_act1, float pos_sp_act2, float pos_sp_act3, float pos_sp_act4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, pos_sp_act1);
    _mav_put_float(buf, 4, pos_sp_act2);
    _mav_put_float(buf, 8, pos_sp_act3);
    _mav_put_float(buf, 12, pos_sp_act4);
    _mav_put_uint8_t(buf, 16, mode);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET, buf, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_MIN_LEN, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_LEN, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_CRC);
#else
    mavlink_lisum_manual_ctrl_hornet_t *packet = (mavlink_lisum_manual_ctrl_hornet_t *)msgbuf;
    packet->pos_sp_act1 = pos_sp_act1;
    packet->pos_sp_act2 = pos_sp_act2;
    packet->pos_sp_act3 = pos_sp_act3;
    packet->pos_sp_act4 = pos_sp_act4;
    packet->mode = mode;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET, (const char *)packet, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_MIN_LEN, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_LEN, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_CRC);
#endif
}
#endif

#endif

// MESSAGE LISUM_MANUAL_CTRL_HORNET UNPACKING


/**
 * @brief Get field mode from lisum_manual_ctrl_hornet message
 *
 * @return  Operational Mode
 */
static inline uint8_t mavlink_msg_lisum_manual_ctrl_hornet_get_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  16);
}

/**
 * @brief Get field pos_sp_act1 from lisum_manual_ctrl_hornet message
 *
 * @return [mm] Position setpoint Actuator 1
 */
static inline float mavlink_msg_lisum_manual_ctrl_hornet_get_pos_sp_act1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field pos_sp_act2 from lisum_manual_ctrl_hornet message
 *
 * @return [mm] Position setpoint Actuator 2
 */
static inline float mavlink_msg_lisum_manual_ctrl_hornet_get_pos_sp_act2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field pos_sp_act3 from lisum_manual_ctrl_hornet message
 *
 * @return [mm] Position setpoint Actuator 3
 */
static inline float mavlink_msg_lisum_manual_ctrl_hornet_get_pos_sp_act3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field pos_sp_act4 from lisum_manual_ctrl_hornet message
 *
 * @return [mm] Position setpoint Actuator 4
 */
static inline float mavlink_msg_lisum_manual_ctrl_hornet_get_pos_sp_act4(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Decode a lisum_manual_ctrl_hornet message into a struct
 *
 * @param msg The message to decode
 * @param lisum_manual_ctrl_hornet C-struct to decode the message contents into
 */
static inline void mavlink_msg_lisum_manual_ctrl_hornet_decode(const mavlink_message_t* msg, mavlink_lisum_manual_ctrl_hornet_t* lisum_manual_ctrl_hornet)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    lisum_manual_ctrl_hornet->pos_sp_act1 = mavlink_msg_lisum_manual_ctrl_hornet_get_pos_sp_act1(msg);
    lisum_manual_ctrl_hornet->pos_sp_act2 = mavlink_msg_lisum_manual_ctrl_hornet_get_pos_sp_act2(msg);
    lisum_manual_ctrl_hornet->pos_sp_act3 = mavlink_msg_lisum_manual_ctrl_hornet_get_pos_sp_act3(msg);
    lisum_manual_ctrl_hornet->pos_sp_act4 = mavlink_msg_lisum_manual_ctrl_hornet_get_pos_sp_act4(msg);
    lisum_manual_ctrl_hornet->mode = mavlink_msg_lisum_manual_ctrl_hornet_get_mode(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_LEN? msg->len : MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_LEN;
        memset(lisum_manual_ctrl_hornet, 0, MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET_LEN);
    memcpy(lisum_manual_ctrl_hornet, _MAV_PAYLOAD(msg), len);
#endif
}
