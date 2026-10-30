#pragma once
// MESSAGE LISUM_VESC_SET_CURRENT PACKING

#define MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT 59523


typedef struct __mavlink_lisum_vesc_set_current_t {
 float current; /*<  Motor current [mA].*/
 uint8_t vesc_id; /*<  Target VESC ID.*/
} mavlink_lisum_vesc_set_current_t;

#define MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_LEN 5
#define MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_MIN_LEN 5
#define MAVLINK_MSG_ID_59523_LEN 5
#define MAVLINK_MSG_ID_59523_MIN_LEN 5

#define MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_CRC 203
#define MAVLINK_MSG_ID_59523_CRC 203



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_LISUM_VESC_SET_CURRENT { \
    59523, \
    "LISUM_VESC_SET_CURRENT", \
    2, \
    {  { "vesc_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_lisum_vesc_set_current_t, vesc_id) }, \
         { "current", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_lisum_vesc_set_current_t, current) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_LISUM_VESC_SET_CURRENT { \
    "LISUM_VESC_SET_CURRENT", \
    2, \
    {  { "vesc_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_lisum_vesc_set_current_t, vesc_id) }, \
         { "current", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_lisum_vesc_set_current_t, current) }, \
         } \
}
#endif

/**
 * @brief Pack a lisum_vesc_set_current message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param vesc_id  Target VESC ID.
 * @param current  Motor current [mA].
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_vesc_set_current_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t vesc_id, float current)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_LEN];
    _mav_put_float(buf, 0, current);
    _mav_put_uint8_t(buf, 4, vesc_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_LEN);
#else
    mavlink_lisum_vesc_set_current_t packet;
    packet.current = current;
    packet.vesc_id = vesc_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_LEN, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_CRC);
}

/**
 * @brief Pack a lisum_vesc_set_current message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param vesc_id  Target VESC ID.
 * @param current  Motor current [mA].
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_vesc_set_current_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t vesc_id, float current)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_LEN];
    _mav_put_float(buf, 0, current);
    _mav_put_uint8_t(buf, 4, vesc_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_LEN);
#else
    mavlink_lisum_vesc_set_current_t packet;
    packet.current = current;
    packet.vesc_id = vesc_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_LEN, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_LEN);
#endif
}

/**
 * @brief Pack a lisum_vesc_set_current message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param vesc_id  Target VESC ID.
 * @param current  Motor current [mA].
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_vesc_set_current_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t vesc_id,float current)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_LEN];
    _mav_put_float(buf, 0, current);
    _mav_put_uint8_t(buf, 4, vesc_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_LEN);
#else
    mavlink_lisum_vesc_set_current_t packet;
    packet.current = current;
    packet.vesc_id = vesc_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_LEN, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_CRC);
}

/**
 * @brief Encode a lisum_vesc_set_current struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param lisum_vesc_set_current C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_vesc_set_current_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_lisum_vesc_set_current_t* lisum_vesc_set_current)
{
    return mavlink_msg_lisum_vesc_set_current_pack(system_id, component_id, msg, lisum_vesc_set_current->vesc_id, lisum_vesc_set_current->current);
}

/**
 * @brief Encode a lisum_vesc_set_current struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param lisum_vesc_set_current C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_vesc_set_current_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_lisum_vesc_set_current_t* lisum_vesc_set_current)
{
    return mavlink_msg_lisum_vesc_set_current_pack_chan(system_id, component_id, chan, msg, lisum_vesc_set_current->vesc_id, lisum_vesc_set_current->current);
}

/**
 * @brief Encode a lisum_vesc_set_current struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param lisum_vesc_set_current C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_vesc_set_current_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_lisum_vesc_set_current_t* lisum_vesc_set_current)
{
    return mavlink_msg_lisum_vesc_set_current_pack_status(system_id, component_id, _status, msg,  lisum_vesc_set_current->vesc_id, lisum_vesc_set_current->current);
}

/**
 * @brief Send a lisum_vesc_set_current message
 * @param chan MAVLink channel to send the message
 *
 * @param vesc_id  Target VESC ID.
 * @param current  Motor current [mA].
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_lisum_vesc_set_current_send(mavlink_channel_t chan, uint8_t vesc_id, float current)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_LEN];
    _mav_put_float(buf, 0, current);
    _mav_put_uint8_t(buf, 4, vesc_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT, buf, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_LEN, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_CRC);
#else
    mavlink_lisum_vesc_set_current_t packet;
    packet.current = current;
    packet.vesc_id = vesc_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT, (const char *)&packet, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_LEN, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_CRC);
#endif
}

/**
 * @brief Send a lisum_vesc_set_current message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_lisum_vesc_set_current_send_struct(mavlink_channel_t chan, const mavlink_lisum_vesc_set_current_t* lisum_vesc_set_current)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_lisum_vesc_set_current_send(chan, lisum_vesc_set_current->vesc_id, lisum_vesc_set_current->current);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT, (const char *)lisum_vesc_set_current, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_LEN, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_CRC);
#endif
}

#if MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_lisum_vesc_set_current_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t vesc_id, float current)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, current);
    _mav_put_uint8_t(buf, 4, vesc_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT, buf, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_LEN, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_CRC);
#else
    mavlink_lisum_vesc_set_current_t *packet = (mavlink_lisum_vesc_set_current_t *)msgbuf;
    packet->current = current;
    packet->vesc_id = vesc_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT, (const char *)packet, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_LEN, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_CRC);
#endif
}
#endif

#endif

// MESSAGE LISUM_VESC_SET_CURRENT UNPACKING


/**
 * @brief Get field vesc_id from lisum_vesc_set_current message
 *
 * @return  Target VESC ID.
 */
static inline uint8_t mavlink_msg_lisum_vesc_set_current_get_vesc_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field current from lisum_vesc_set_current message
 *
 * @return  Motor current [mA].
 */
static inline float mavlink_msg_lisum_vesc_set_current_get_current(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Decode a lisum_vesc_set_current message into a struct
 *
 * @param msg The message to decode
 * @param lisum_vesc_set_current C-struct to decode the message contents into
 */
static inline void mavlink_msg_lisum_vesc_set_current_decode(const mavlink_message_t* msg, mavlink_lisum_vesc_set_current_t* lisum_vesc_set_current)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    lisum_vesc_set_current->current = mavlink_msg_lisum_vesc_set_current_get_current(msg);
    lisum_vesc_set_current->vesc_id = mavlink_msg_lisum_vesc_set_current_get_vesc_id(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_LEN? msg->len : MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_LEN;
        memset(lisum_vesc_set_current, 0, MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_LEN);
    memcpy(lisum_vesc_set_current, _MAV_PAYLOAD(msg), len);
#endif
}
