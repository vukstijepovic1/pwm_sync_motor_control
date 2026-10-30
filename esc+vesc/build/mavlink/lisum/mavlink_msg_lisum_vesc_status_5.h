#pragma once
// MESSAGE LISUM_VESC_STATUS_5 PACKING

#define MAVLINK_MSG_ID_LISUM_VESC_STATUS_5 59532


typedef struct __mavlink_lisum_vesc_status_5_t {
 float voltage; /*<  Bus voltage [V]*10.*/
 float tachometar; /*<  Tachometer reading *6.*/
 uint8_t vesc_id; /*<  Target VESC ID.*/
} mavlink_lisum_vesc_status_5_t;

#define MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_LEN 9
#define MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_MIN_LEN 9
#define MAVLINK_MSG_ID_59532_LEN 9
#define MAVLINK_MSG_ID_59532_MIN_LEN 9

#define MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_CRC 111
#define MAVLINK_MSG_ID_59532_CRC 111



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_LISUM_VESC_STATUS_5 { \
    59532, \
    "LISUM_VESC_STATUS_5", \
    3, \
    {  { "vesc_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_lisum_vesc_status_5_t, vesc_id) }, \
         { "voltage", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_lisum_vesc_status_5_t, voltage) }, \
         { "tachometar", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_lisum_vesc_status_5_t, tachometar) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_LISUM_VESC_STATUS_5 { \
    "LISUM_VESC_STATUS_5", \
    3, \
    {  { "vesc_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_lisum_vesc_status_5_t, vesc_id) }, \
         { "voltage", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_lisum_vesc_status_5_t, voltage) }, \
         { "tachometar", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_lisum_vesc_status_5_t, tachometar) }, \
         } \
}
#endif

/**
 * @brief Pack a lisum_vesc_status_5 message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param vesc_id  Target VESC ID.
 * @param voltage  Bus voltage [V]*10.
 * @param tachometar  Tachometer reading *6.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_5_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t vesc_id, float voltage, float tachometar)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_LEN];
    _mav_put_float(buf, 0, voltage);
    _mav_put_float(buf, 4, tachometar);
    _mav_put_uint8_t(buf, 8, vesc_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_LEN);
#else
    mavlink_lisum_vesc_status_5_t packet;
    packet.voltage = voltage;
    packet.tachometar = tachometar;
    packet.vesc_id = vesc_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_VESC_STATUS_5;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_CRC);
}

/**
 * @brief Pack a lisum_vesc_status_5 message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param vesc_id  Target VESC ID.
 * @param voltage  Bus voltage [V]*10.
 * @param tachometar  Tachometer reading *6.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_5_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t vesc_id, float voltage, float tachometar)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_LEN];
    _mav_put_float(buf, 0, voltage);
    _mav_put_float(buf, 4, tachometar);
    _mav_put_uint8_t(buf, 8, vesc_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_LEN);
#else
    mavlink_lisum_vesc_status_5_t packet;
    packet.voltage = voltage;
    packet.tachometar = tachometar;
    packet.vesc_id = vesc_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_VESC_STATUS_5;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_LEN);
#endif
}

/**
 * @brief Pack a lisum_vesc_status_5 message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param vesc_id  Target VESC ID.
 * @param voltage  Bus voltage [V]*10.
 * @param tachometar  Tachometer reading *6.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_5_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t vesc_id,float voltage,float tachometar)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_LEN];
    _mav_put_float(buf, 0, voltage);
    _mav_put_float(buf, 4, tachometar);
    _mav_put_uint8_t(buf, 8, vesc_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_LEN);
#else
    mavlink_lisum_vesc_status_5_t packet;
    packet.voltage = voltage;
    packet.tachometar = tachometar;
    packet.vesc_id = vesc_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_VESC_STATUS_5;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_CRC);
}

/**
 * @brief Encode a lisum_vesc_status_5 struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param lisum_vesc_status_5 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_5_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_lisum_vesc_status_5_t* lisum_vesc_status_5)
{
    return mavlink_msg_lisum_vesc_status_5_pack(system_id, component_id, msg, lisum_vesc_status_5->vesc_id, lisum_vesc_status_5->voltage, lisum_vesc_status_5->tachometar);
}

/**
 * @brief Encode a lisum_vesc_status_5 struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param lisum_vesc_status_5 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_5_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_lisum_vesc_status_5_t* lisum_vesc_status_5)
{
    return mavlink_msg_lisum_vesc_status_5_pack_chan(system_id, component_id, chan, msg, lisum_vesc_status_5->vesc_id, lisum_vesc_status_5->voltage, lisum_vesc_status_5->tachometar);
}

/**
 * @brief Encode a lisum_vesc_status_5 struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param lisum_vesc_status_5 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_5_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_lisum_vesc_status_5_t* lisum_vesc_status_5)
{
    return mavlink_msg_lisum_vesc_status_5_pack_status(system_id, component_id, _status, msg,  lisum_vesc_status_5->vesc_id, lisum_vesc_status_5->voltage, lisum_vesc_status_5->tachometar);
}

/**
 * @brief Send a lisum_vesc_status_5 message
 * @param chan MAVLink channel to send the message
 *
 * @param vesc_id  Target VESC ID.
 * @param voltage  Bus voltage [V]*10.
 * @param tachometar  Tachometer reading *6.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_lisum_vesc_status_5_send(mavlink_channel_t chan, uint8_t vesc_id, float voltage, float tachometar)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_LEN];
    _mav_put_float(buf, 0, voltage);
    _mav_put_float(buf, 4, tachometar);
    _mav_put_uint8_t(buf, 8, vesc_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5, buf, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_CRC);
#else
    mavlink_lisum_vesc_status_5_t packet;
    packet.voltage = voltage;
    packet.tachometar = tachometar;
    packet.vesc_id = vesc_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5, (const char *)&packet, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_CRC);
#endif
}

/**
 * @brief Send a lisum_vesc_status_5 message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_lisum_vesc_status_5_send_struct(mavlink_channel_t chan, const mavlink_lisum_vesc_status_5_t* lisum_vesc_status_5)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_lisum_vesc_status_5_send(chan, lisum_vesc_status_5->vesc_id, lisum_vesc_status_5->voltage, lisum_vesc_status_5->tachometar);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5, (const char *)lisum_vesc_status_5, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_CRC);
#endif
}

#if MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_lisum_vesc_status_5_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t vesc_id, float voltage, float tachometar)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, voltage);
    _mav_put_float(buf, 4, tachometar);
    _mav_put_uint8_t(buf, 8, vesc_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5, buf, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_CRC);
#else
    mavlink_lisum_vesc_status_5_t *packet = (mavlink_lisum_vesc_status_5_t *)msgbuf;
    packet->voltage = voltage;
    packet->tachometar = tachometar;
    packet->vesc_id = vesc_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5, (const char *)packet, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_CRC);
#endif
}
#endif

#endif

// MESSAGE LISUM_VESC_STATUS_5 UNPACKING


/**
 * @brief Get field vesc_id from lisum_vesc_status_5 message
 *
 * @return  Target VESC ID.
 */
static inline uint8_t mavlink_msg_lisum_vesc_status_5_get_vesc_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field voltage from lisum_vesc_status_5 message
 *
 * @return  Bus voltage [V]*10.
 */
static inline float mavlink_msg_lisum_vesc_status_5_get_voltage(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field tachometar from lisum_vesc_status_5 message
 *
 * @return  Tachometer reading *6.
 */
static inline float mavlink_msg_lisum_vesc_status_5_get_tachometar(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Decode a lisum_vesc_status_5 message into a struct
 *
 * @param msg The message to decode
 * @param lisum_vesc_status_5 C-struct to decode the message contents into
 */
static inline void mavlink_msg_lisum_vesc_status_5_decode(const mavlink_message_t* msg, mavlink_lisum_vesc_status_5_t* lisum_vesc_status_5)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    lisum_vesc_status_5->voltage = mavlink_msg_lisum_vesc_status_5_get_voltage(msg);
    lisum_vesc_status_5->tachometar = mavlink_msg_lisum_vesc_status_5_get_tachometar(msg);
    lisum_vesc_status_5->vesc_id = mavlink_msg_lisum_vesc_status_5_get_vesc_id(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_LEN? msg->len : MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_LEN;
        memset(lisum_vesc_status_5, 0, MAVLINK_MSG_ID_LISUM_VESC_STATUS_5_LEN);
    memcpy(lisum_vesc_status_5, _MAV_PAYLOAD(msg), len);
#endif
}
