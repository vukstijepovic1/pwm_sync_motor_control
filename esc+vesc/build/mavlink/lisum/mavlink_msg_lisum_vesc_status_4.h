#pragma once
// MESSAGE LISUM_VESC_STATUS_4 PACKING

#define MAVLINK_MSG_ID_LISUM_VESC_STATUS_4 59531


typedef struct __mavlink_lisum_vesc_status_4_t {
 float pos; /*<  Rotor position [deg]*50.*/
 float current_in; /*<  Current In[A]*10.*/
 float motor_temp; /*<  Motor temperature [°C]*10.*/
 float fet_temp; /*<  FET temperature [°C]*10.*/
 uint8_t vesc_id; /*<  Target VESC ID.*/
} mavlink_lisum_vesc_status_4_t;

#define MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_LEN 17
#define MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_MIN_LEN 17
#define MAVLINK_MSG_ID_59531_LEN 17
#define MAVLINK_MSG_ID_59531_MIN_LEN 17

#define MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_CRC 243
#define MAVLINK_MSG_ID_59531_CRC 243



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_LISUM_VESC_STATUS_4 { \
    59531, \
    "LISUM_VESC_STATUS_4", \
    5, \
    {  { "vesc_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_lisum_vesc_status_4_t, vesc_id) }, \
         { "pos", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_lisum_vesc_status_4_t, pos) }, \
         { "current_in", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_lisum_vesc_status_4_t, current_in) }, \
         { "motor_temp", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_lisum_vesc_status_4_t, motor_temp) }, \
         { "fet_temp", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_lisum_vesc_status_4_t, fet_temp) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_LISUM_VESC_STATUS_4 { \
    "LISUM_VESC_STATUS_4", \
    5, \
    {  { "vesc_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_lisum_vesc_status_4_t, vesc_id) }, \
         { "pos", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_lisum_vesc_status_4_t, pos) }, \
         { "current_in", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_lisum_vesc_status_4_t, current_in) }, \
         { "motor_temp", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_lisum_vesc_status_4_t, motor_temp) }, \
         { "fet_temp", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_lisum_vesc_status_4_t, fet_temp) }, \
         } \
}
#endif

/**
 * @brief Pack a lisum_vesc_status_4 message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param vesc_id  Target VESC ID.
 * @param pos  Rotor position [deg]*50.
 * @param current_in  Current In[A]*10.
 * @param motor_temp  Motor temperature [°C]*10.
 * @param fet_temp  FET temperature [°C]*10.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_4_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t vesc_id, float pos, float current_in, float motor_temp, float fet_temp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_LEN];
    _mav_put_float(buf, 0, pos);
    _mav_put_float(buf, 4, current_in);
    _mav_put_float(buf, 8, motor_temp);
    _mav_put_float(buf, 12, fet_temp);
    _mav_put_uint8_t(buf, 16, vesc_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_LEN);
#else
    mavlink_lisum_vesc_status_4_t packet;
    packet.pos = pos;
    packet.current_in = current_in;
    packet.motor_temp = motor_temp;
    packet.fet_temp = fet_temp;
    packet.vesc_id = vesc_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_VESC_STATUS_4;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_CRC);
}

/**
 * @brief Pack a lisum_vesc_status_4 message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param vesc_id  Target VESC ID.
 * @param pos  Rotor position [deg]*50.
 * @param current_in  Current In[A]*10.
 * @param motor_temp  Motor temperature [°C]*10.
 * @param fet_temp  FET temperature [°C]*10.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_4_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t vesc_id, float pos, float current_in, float motor_temp, float fet_temp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_LEN];
    _mav_put_float(buf, 0, pos);
    _mav_put_float(buf, 4, current_in);
    _mav_put_float(buf, 8, motor_temp);
    _mav_put_float(buf, 12, fet_temp);
    _mav_put_uint8_t(buf, 16, vesc_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_LEN);
#else
    mavlink_lisum_vesc_status_4_t packet;
    packet.pos = pos;
    packet.current_in = current_in;
    packet.motor_temp = motor_temp;
    packet.fet_temp = fet_temp;
    packet.vesc_id = vesc_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_VESC_STATUS_4;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_LEN);
#endif
}

/**
 * @brief Pack a lisum_vesc_status_4 message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param vesc_id  Target VESC ID.
 * @param pos  Rotor position [deg]*50.
 * @param current_in  Current In[A]*10.
 * @param motor_temp  Motor temperature [°C]*10.
 * @param fet_temp  FET temperature [°C]*10.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_4_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t vesc_id,float pos,float current_in,float motor_temp,float fet_temp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_LEN];
    _mav_put_float(buf, 0, pos);
    _mav_put_float(buf, 4, current_in);
    _mav_put_float(buf, 8, motor_temp);
    _mav_put_float(buf, 12, fet_temp);
    _mav_put_uint8_t(buf, 16, vesc_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_LEN);
#else
    mavlink_lisum_vesc_status_4_t packet;
    packet.pos = pos;
    packet.current_in = current_in;
    packet.motor_temp = motor_temp;
    packet.fet_temp = fet_temp;
    packet.vesc_id = vesc_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_VESC_STATUS_4;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_CRC);
}

/**
 * @brief Encode a lisum_vesc_status_4 struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param lisum_vesc_status_4 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_4_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_lisum_vesc_status_4_t* lisum_vesc_status_4)
{
    return mavlink_msg_lisum_vesc_status_4_pack(system_id, component_id, msg, lisum_vesc_status_4->vesc_id, lisum_vesc_status_4->pos, lisum_vesc_status_4->current_in, lisum_vesc_status_4->motor_temp, lisum_vesc_status_4->fet_temp);
}

/**
 * @brief Encode a lisum_vesc_status_4 struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param lisum_vesc_status_4 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_4_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_lisum_vesc_status_4_t* lisum_vesc_status_4)
{
    return mavlink_msg_lisum_vesc_status_4_pack_chan(system_id, component_id, chan, msg, lisum_vesc_status_4->vesc_id, lisum_vesc_status_4->pos, lisum_vesc_status_4->current_in, lisum_vesc_status_4->motor_temp, lisum_vesc_status_4->fet_temp);
}

/**
 * @brief Encode a lisum_vesc_status_4 struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param lisum_vesc_status_4 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_4_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_lisum_vesc_status_4_t* lisum_vesc_status_4)
{
    return mavlink_msg_lisum_vesc_status_4_pack_status(system_id, component_id, _status, msg,  lisum_vesc_status_4->vesc_id, lisum_vesc_status_4->pos, lisum_vesc_status_4->current_in, lisum_vesc_status_4->motor_temp, lisum_vesc_status_4->fet_temp);
}

/**
 * @brief Send a lisum_vesc_status_4 message
 * @param chan MAVLink channel to send the message
 *
 * @param vesc_id  Target VESC ID.
 * @param pos  Rotor position [deg]*50.
 * @param current_in  Current In[A]*10.
 * @param motor_temp  Motor temperature [°C]*10.
 * @param fet_temp  FET temperature [°C]*10.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_lisum_vesc_status_4_send(mavlink_channel_t chan, uint8_t vesc_id, float pos, float current_in, float motor_temp, float fet_temp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_LEN];
    _mav_put_float(buf, 0, pos);
    _mav_put_float(buf, 4, current_in);
    _mav_put_float(buf, 8, motor_temp);
    _mav_put_float(buf, 12, fet_temp);
    _mav_put_uint8_t(buf, 16, vesc_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4, buf, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_CRC);
#else
    mavlink_lisum_vesc_status_4_t packet;
    packet.pos = pos;
    packet.current_in = current_in;
    packet.motor_temp = motor_temp;
    packet.fet_temp = fet_temp;
    packet.vesc_id = vesc_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4, (const char *)&packet, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_CRC);
#endif
}

/**
 * @brief Send a lisum_vesc_status_4 message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_lisum_vesc_status_4_send_struct(mavlink_channel_t chan, const mavlink_lisum_vesc_status_4_t* lisum_vesc_status_4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_lisum_vesc_status_4_send(chan, lisum_vesc_status_4->vesc_id, lisum_vesc_status_4->pos, lisum_vesc_status_4->current_in, lisum_vesc_status_4->motor_temp, lisum_vesc_status_4->fet_temp);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4, (const char *)lisum_vesc_status_4, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_CRC);
#endif
}

#if MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_lisum_vesc_status_4_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t vesc_id, float pos, float current_in, float motor_temp, float fet_temp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, pos);
    _mav_put_float(buf, 4, current_in);
    _mav_put_float(buf, 8, motor_temp);
    _mav_put_float(buf, 12, fet_temp);
    _mav_put_uint8_t(buf, 16, vesc_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4, buf, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_CRC);
#else
    mavlink_lisum_vesc_status_4_t *packet = (mavlink_lisum_vesc_status_4_t *)msgbuf;
    packet->pos = pos;
    packet->current_in = current_in;
    packet->motor_temp = motor_temp;
    packet->fet_temp = fet_temp;
    packet->vesc_id = vesc_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4, (const char *)packet, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_CRC);
#endif
}
#endif

#endif

// MESSAGE LISUM_VESC_STATUS_4 UNPACKING


/**
 * @brief Get field vesc_id from lisum_vesc_status_4 message
 *
 * @return  Target VESC ID.
 */
static inline uint8_t mavlink_msg_lisum_vesc_status_4_get_vesc_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  16);
}

/**
 * @brief Get field pos from lisum_vesc_status_4 message
 *
 * @return  Rotor position [deg]*50.
 */
static inline float mavlink_msg_lisum_vesc_status_4_get_pos(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field current_in from lisum_vesc_status_4 message
 *
 * @return  Current In[A]*10.
 */
static inline float mavlink_msg_lisum_vesc_status_4_get_current_in(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field motor_temp from lisum_vesc_status_4 message
 *
 * @return  Motor temperature [°C]*10.
 */
static inline float mavlink_msg_lisum_vesc_status_4_get_motor_temp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field fet_temp from lisum_vesc_status_4 message
 *
 * @return  FET temperature [°C]*10.
 */
static inline float mavlink_msg_lisum_vesc_status_4_get_fet_temp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Decode a lisum_vesc_status_4 message into a struct
 *
 * @param msg The message to decode
 * @param lisum_vesc_status_4 C-struct to decode the message contents into
 */
static inline void mavlink_msg_lisum_vesc_status_4_decode(const mavlink_message_t* msg, mavlink_lisum_vesc_status_4_t* lisum_vesc_status_4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    lisum_vesc_status_4->pos = mavlink_msg_lisum_vesc_status_4_get_pos(msg);
    lisum_vesc_status_4->current_in = mavlink_msg_lisum_vesc_status_4_get_current_in(msg);
    lisum_vesc_status_4->motor_temp = mavlink_msg_lisum_vesc_status_4_get_motor_temp(msg);
    lisum_vesc_status_4->fet_temp = mavlink_msg_lisum_vesc_status_4_get_fet_temp(msg);
    lisum_vesc_status_4->vesc_id = mavlink_msg_lisum_vesc_status_4_get_vesc_id(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_LEN? msg->len : MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_LEN;
        memset(lisum_vesc_status_4, 0, MAVLINK_MSG_ID_LISUM_VESC_STATUS_4_LEN);
    memcpy(lisum_vesc_status_4, _MAV_PAYLOAD(msg), len);
#endif
}
