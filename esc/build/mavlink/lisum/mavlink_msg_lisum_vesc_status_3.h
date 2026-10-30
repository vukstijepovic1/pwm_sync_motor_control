#pragma once
// MESSAGE LISUM_VESC_STATUS_3 PACKING

#define MAVLINK_MSG_ID_LISUM_VESC_STATUS_3 59530


typedef struct __mavlink_lisum_vesc_status_3_t {
 float watt_hours_charged; /*<  Watt-hours charged [Wh]*10000.*/
 float watt_hours; /*<  Watt-hours [Wh]*10000.*/
 uint8_t vesc_id; /*<  Target VESC ID.*/
} mavlink_lisum_vesc_status_3_t;

#define MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_LEN 9
#define MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_MIN_LEN 9
#define MAVLINK_MSG_ID_59530_LEN 9
#define MAVLINK_MSG_ID_59530_MIN_LEN 9

#define MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_CRC 205
#define MAVLINK_MSG_ID_59530_CRC 205



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_LISUM_VESC_STATUS_3 { \
    59530, \
    "LISUM_VESC_STATUS_3", \
    3, \
    {  { "vesc_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_lisum_vesc_status_3_t, vesc_id) }, \
         { "watt_hours_charged", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_lisum_vesc_status_3_t, watt_hours_charged) }, \
         { "watt_hours", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_lisum_vesc_status_3_t, watt_hours) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_LISUM_VESC_STATUS_3 { \
    "LISUM_VESC_STATUS_3", \
    3, \
    {  { "vesc_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_lisum_vesc_status_3_t, vesc_id) }, \
         { "watt_hours_charged", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_lisum_vesc_status_3_t, watt_hours_charged) }, \
         { "watt_hours", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_lisum_vesc_status_3_t, watt_hours) }, \
         } \
}
#endif

/**
 * @brief Pack a lisum_vesc_status_3 message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param vesc_id  Target VESC ID.
 * @param watt_hours_charged  Watt-hours charged [Wh]*10000.
 * @param watt_hours  Watt-hours [Wh]*10000.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_3_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t vesc_id, float watt_hours_charged, float watt_hours)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_LEN];
    _mav_put_float(buf, 0, watt_hours_charged);
    _mav_put_float(buf, 4, watt_hours);
    _mav_put_uint8_t(buf, 8, vesc_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_LEN);
#else
    mavlink_lisum_vesc_status_3_t packet;
    packet.watt_hours_charged = watt_hours_charged;
    packet.watt_hours = watt_hours;
    packet.vesc_id = vesc_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_VESC_STATUS_3;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_CRC);
}

/**
 * @brief Pack a lisum_vesc_status_3 message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param vesc_id  Target VESC ID.
 * @param watt_hours_charged  Watt-hours charged [Wh]*10000.
 * @param watt_hours  Watt-hours [Wh]*10000.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_3_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t vesc_id, float watt_hours_charged, float watt_hours)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_LEN];
    _mav_put_float(buf, 0, watt_hours_charged);
    _mav_put_float(buf, 4, watt_hours);
    _mav_put_uint8_t(buf, 8, vesc_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_LEN);
#else
    mavlink_lisum_vesc_status_3_t packet;
    packet.watt_hours_charged = watt_hours_charged;
    packet.watt_hours = watt_hours;
    packet.vesc_id = vesc_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_VESC_STATUS_3;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_LEN);
#endif
}

/**
 * @brief Pack a lisum_vesc_status_3 message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param vesc_id  Target VESC ID.
 * @param watt_hours_charged  Watt-hours charged [Wh]*10000.
 * @param watt_hours  Watt-hours [Wh]*10000.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_3_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t vesc_id,float watt_hours_charged,float watt_hours)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_LEN];
    _mav_put_float(buf, 0, watt_hours_charged);
    _mav_put_float(buf, 4, watt_hours);
    _mav_put_uint8_t(buf, 8, vesc_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_LEN);
#else
    mavlink_lisum_vesc_status_3_t packet;
    packet.watt_hours_charged = watt_hours_charged;
    packet.watt_hours = watt_hours;
    packet.vesc_id = vesc_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_VESC_STATUS_3;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_CRC);
}

/**
 * @brief Encode a lisum_vesc_status_3 struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param lisum_vesc_status_3 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_3_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_lisum_vesc_status_3_t* lisum_vesc_status_3)
{
    return mavlink_msg_lisum_vesc_status_3_pack(system_id, component_id, msg, lisum_vesc_status_3->vesc_id, lisum_vesc_status_3->watt_hours_charged, lisum_vesc_status_3->watt_hours);
}

/**
 * @brief Encode a lisum_vesc_status_3 struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param lisum_vesc_status_3 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_3_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_lisum_vesc_status_3_t* lisum_vesc_status_3)
{
    return mavlink_msg_lisum_vesc_status_3_pack_chan(system_id, component_id, chan, msg, lisum_vesc_status_3->vesc_id, lisum_vesc_status_3->watt_hours_charged, lisum_vesc_status_3->watt_hours);
}

/**
 * @brief Encode a lisum_vesc_status_3 struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param lisum_vesc_status_3 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_3_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_lisum_vesc_status_3_t* lisum_vesc_status_3)
{
    return mavlink_msg_lisum_vesc_status_3_pack_status(system_id, component_id, _status, msg,  lisum_vesc_status_3->vesc_id, lisum_vesc_status_3->watt_hours_charged, lisum_vesc_status_3->watt_hours);
}

/**
 * @brief Send a lisum_vesc_status_3 message
 * @param chan MAVLink channel to send the message
 *
 * @param vesc_id  Target VESC ID.
 * @param watt_hours_charged  Watt-hours charged [Wh]*10000.
 * @param watt_hours  Watt-hours [Wh]*10000.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_lisum_vesc_status_3_send(mavlink_channel_t chan, uint8_t vesc_id, float watt_hours_charged, float watt_hours)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_LEN];
    _mav_put_float(buf, 0, watt_hours_charged);
    _mav_put_float(buf, 4, watt_hours);
    _mav_put_uint8_t(buf, 8, vesc_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3, buf, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_CRC);
#else
    mavlink_lisum_vesc_status_3_t packet;
    packet.watt_hours_charged = watt_hours_charged;
    packet.watt_hours = watt_hours;
    packet.vesc_id = vesc_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3, (const char *)&packet, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_CRC);
#endif
}

/**
 * @brief Send a lisum_vesc_status_3 message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_lisum_vesc_status_3_send_struct(mavlink_channel_t chan, const mavlink_lisum_vesc_status_3_t* lisum_vesc_status_3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_lisum_vesc_status_3_send(chan, lisum_vesc_status_3->vesc_id, lisum_vesc_status_3->watt_hours_charged, lisum_vesc_status_3->watt_hours);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3, (const char *)lisum_vesc_status_3, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_CRC);
#endif
}

#if MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_lisum_vesc_status_3_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t vesc_id, float watt_hours_charged, float watt_hours)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, watt_hours_charged);
    _mav_put_float(buf, 4, watt_hours);
    _mav_put_uint8_t(buf, 8, vesc_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3, buf, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_CRC);
#else
    mavlink_lisum_vesc_status_3_t *packet = (mavlink_lisum_vesc_status_3_t *)msgbuf;
    packet->watt_hours_charged = watt_hours_charged;
    packet->watt_hours = watt_hours;
    packet->vesc_id = vesc_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3, (const char *)packet, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_CRC);
#endif
}
#endif

#endif

// MESSAGE LISUM_VESC_STATUS_3 UNPACKING


/**
 * @brief Get field vesc_id from lisum_vesc_status_3 message
 *
 * @return  Target VESC ID.
 */
static inline uint8_t mavlink_msg_lisum_vesc_status_3_get_vesc_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field watt_hours_charged from lisum_vesc_status_3 message
 *
 * @return  Watt-hours charged [Wh]*10000.
 */
static inline float mavlink_msg_lisum_vesc_status_3_get_watt_hours_charged(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field watt_hours from lisum_vesc_status_3 message
 *
 * @return  Watt-hours [Wh]*10000.
 */
static inline float mavlink_msg_lisum_vesc_status_3_get_watt_hours(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Decode a lisum_vesc_status_3 message into a struct
 *
 * @param msg The message to decode
 * @param lisum_vesc_status_3 C-struct to decode the message contents into
 */
static inline void mavlink_msg_lisum_vesc_status_3_decode(const mavlink_message_t* msg, mavlink_lisum_vesc_status_3_t* lisum_vesc_status_3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    lisum_vesc_status_3->watt_hours_charged = mavlink_msg_lisum_vesc_status_3_get_watt_hours_charged(msg);
    lisum_vesc_status_3->watt_hours = mavlink_msg_lisum_vesc_status_3_get_watt_hours(msg);
    lisum_vesc_status_3->vesc_id = mavlink_msg_lisum_vesc_status_3_get_vesc_id(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_LEN? msg->len : MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_LEN;
        memset(lisum_vesc_status_3, 0, MAVLINK_MSG_ID_LISUM_VESC_STATUS_3_LEN);
    memcpy(lisum_vesc_status_3, _MAV_PAYLOAD(msg), len);
#endif
}
