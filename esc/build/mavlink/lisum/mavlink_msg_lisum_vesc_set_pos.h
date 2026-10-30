#pragma once
// MESSAGE LISUM_VESC_SET_POS PACKING

#define MAVLINK_MSG_ID_LISUM_VESC_SET_POS 59526


typedef struct __mavlink_lisum_vesc_set_pos_t {
 float pos; /*<  Motor position [deg].*/
 uint8_t vesc_id; /*<  Target VESC ID.*/
} mavlink_lisum_vesc_set_pos_t;

#define MAVLINK_MSG_ID_LISUM_VESC_SET_POS_LEN 5
#define MAVLINK_MSG_ID_LISUM_VESC_SET_POS_MIN_LEN 5
#define MAVLINK_MSG_ID_59526_LEN 5
#define MAVLINK_MSG_ID_59526_MIN_LEN 5

#define MAVLINK_MSG_ID_LISUM_VESC_SET_POS_CRC 220
#define MAVLINK_MSG_ID_59526_CRC 220



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_LISUM_VESC_SET_POS { \
    59526, \
    "LISUM_VESC_SET_POS", \
    2, \
    {  { "vesc_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_lisum_vesc_set_pos_t, vesc_id) }, \
         { "pos", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_lisum_vesc_set_pos_t, pos) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_LISUM_VESC_SET_POS { \
    "LISUM_VESC_SET_POS", \
    2, \
    {  { "vesc_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_lisum_vesc_set_pos_t, vesc_id) }, \
         { "pos", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_lisum_vesc_set_pos_t, pos) }, \
         } \
}
#endif

/**
 * @brief Pack a lisum_vesc_set_pos message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param vesc_id  Target VESC ID.
 * @param pos  Motor position [deg].
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_vesc_set_pos_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t vesc_id, float pos)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_VESC_SET_POS_LEN];
    _mav_put_float(buf, 0, pos);
    _mav_put_uint8_t(buf, 4, vesc_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_VESC_SET_POS_LEN);
#else
    mavlink_lisum_vesc_set_pos_t packet;
    packet.pos = pos;
    packet.vesc_id = vesc_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_VESC_SET_POS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_VESC_SET_POS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_LISUM_VESC_SET_POS_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_SET_POS_LEN, MAVLINK_MSG_ID_LISUM_VESC_SET_POS_CRC);
}

/**
 * @brief Pack a lisum_vesc_set_pos message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param vesc_id  Target VESC ID.
 * @param pos  Motor position [deg].
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_vesc_set_pos_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t vesc_id, float pos)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_VESC_SET_POS_LEN];
    _mav_put_float(buf, 0, pos);
    _mav_put_uint8_t(buf, 4, vesc_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_VESC_SET_POS_LEN);
#else
    mavlink_lisum_vesc_set_pos_t packet;
    packet.pos = pos;
    packet.vesc_id = vesc_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_VESC_SET_POS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_VESC_SET_POS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_LISUM_VESC_SET_POS_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_SET_POS_LEN, MAVLINK_MSG_ID_LISUM_VESC_SET_POS_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_LISUM_VESC_SET_POS_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_SET_POS_LEN);
#endif
}

/**
 * @brief Pack a lisum_vesc_set_pos message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param vesc_id  Target VESC ID.
 * @param pos  Motor position [deg].
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_vesc_set_pos_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t vesc_id,float pos)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_VESC_SET_POS_LEN];
    _mav_put_float(buf, 0, pos);
    _mav_put_uint8_t(buf, 4, vesc_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_VESC_SET_POS_LEN);
#else
    mavlink_lisum_vesc_set_pos_t packet;
    packet.pos = pos;
    packet.vesc_id = vesc_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_VESC_SET_POS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_VESC_SET_POS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_LISUM_VESC_SET_POS_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_SET_POS_LEN, MAVLINK_MSG_ID_LISUM_VESC_SET_POS_CRC);
}

/**
 * @brief Encode a lisum_vesc_set_pos struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param lisum_vesc_set_pos C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_vesc_set_pos_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_lisum_vesc_set_pos_t* lisum_vesc_set_pos)
{
    return mavlink_msg_lisum_vesc_set_pos_pack(system_id, component_id, msg, lisum_vesc_set_pos->vesc_id, lisum_vesc_set_pos->pos);
}

/**
 * @brief Encode a lisum_vesc_set_pos struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param lisum_vesc_set_pos C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_vesc_set_pos_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_lisum_vesc_set_pos_t* lisum_vesc_set_pos)
{
    return mavlink_msg_lisum_vesc_set_pos_pack_chan(system_id, component_id, chan, msg, lisum_vesc_set_pos->vesc_id, lisum_vesc_set_pos->pos);
}

/**
 * @brief Encode a lisum_vesc_set_pos struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param lisum_vesc_set_pos C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_vesc_set_pos_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_lisum_vesc_set_pos_t* lisum_vesc_set_pos)
{
    return mavlink_msg_lisum_vesc_set_pos_pack_status(system_id, component_id, _status, msg,  lisum_vesc_set_pos->vesc_id, lisum_vesc_set_pos->pos);
}

/**
 * @brief Send a lisum_vesc_set_pos message
 * @param chan MAVLink channel to send the message
 *
 * @param vesc_id  Target VESC ID.
 * @param pos  Motor position [deg].
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_lisum_vesc_set_pos_send(mavlink_channel_t chan, uint8_t vesc_id, float pos)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_VESC_SET_POS_LEN];
    _mav_put_float(buf, 0, pos);
    _mav_put_uint8_t(buf, 4, vesc_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_SET_POS, buf, MAVLINK_MSG_ID_LISUM_VESC_SET_POS_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_SET_POS_LEN, MAVLINK_MSG_ID_LISUM_VESC_SET_POS_CRC);
#else
    mavlink_lisum_vesc_set_pos_t packet;
    packet.pos = pos;
    packet.vesc_id = vesc_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_SET_POS, (const char *)&packet, MAVLINK_MSG_ID_LISUM_VESC_SET_POS_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_SET_POS_LEN, MAVLINK_MSG_ID_LISUM_VESC_SET_POS_CRC);
#endif
}

/**
 * @brief Send a lisum_vesc_set_pos message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_lisum_vesc_set_pos_send_struct(mavlink_channel_t chan, const mavlink_lisum_vesc_set_pos_t* lisum_vesc_set_pos)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_lisum_vesc_set_pos_send(chan, lisum_vesc_set_pos->vesc_id, lisum_vesc_set_pos->pos);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_SET_POS, (const char *)lisum_vesc_set_pos, MAVLINK_MSG_ID_LISUM_VESC_SET_POS_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_SET_POS_LEN, MAVLINK_MSG_ID_LISUM_VESC_SET_POS_CRC);
#endif
}

#if MAVLINK_MSG_ID_LISUM_VESC_SET_POS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_lisum_vesc_set_pos_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t vesc_id, float pos)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, pos);
    _mav_put_uint8_t(buf, 4, vesc_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_SET_POS, buf, MAVLINK_MSG_ID_LISUM_VESC_SET_POS_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_SET_POS_LEN, MAVLINK_MSG_ID_LISUM_VESC_SET_POS_CRC);
#else
    mavlink_lisum_vesc_set_pos_t *packet = (mavlink_lisum_vesc_set_pos_t *)msgbuf;
    packet->pos = pos;
    packet->vesc_id = vesc_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_SET_POS, (const char *)packet, MAVLINK_MSG_ID_LISUM_VESC_SET_POS_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_SET_POS_LEN, MAVLINK_MSG_ID_LISUM_VESC_SET_POS_CRC);
#endif
}
#endif

#endif

// MESSAGE LISUM_VESC_SET_POS UNPACKING


/**
 * @brief Get field vesc_id from lisum_vesc_set_pos message
 *
 * @return  Target VESC ID.
 */
static inline uint8_t mavlink_msg_lisum_vesc_set_pos_get_vesc_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field pos from lisum_vesc_set_pos message
 *
 * @return  Motor position [deg].
 */
static inline float mavlink_msg_lisum_vesc_set_pos_get_pos(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Decode a lisum_vesc_set_pos message into a struct
 *
 * @param msg The message to decode
 * @param lisum_vesc_set_pos C-struct to decode the message contents into
 */
static inline void mavlink_msg_lisum_vesc_set_pos_decode(const mavlink_message_t* msg, mavlink_lisum_vesc_set_pos_t* lisum_vesc_set_pos)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    lisum_vesc_set_pos->pos = mavlink_msg_lisum_vesc_set_pos_get_pos(msg);
    lisum_vesc_set_pos->vesc_id = mavlink_msg_lisum_vesc_set_pos_get_vesc_id(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_LISUM_VESC_SET_POS_LEN? msg->len : MAVLINK_MSG_ID_LISUM_VESC_SET_POS_LEN;
        memset(lisum_vesc_set_pos, 0, MAVLINK_MSG_ID_LISUM_VESC_SET_POS_LEN);
    memcpy(lisum_vesc_set_pos, _MAV_PAYLOAD(msg), len);
#endif
}
