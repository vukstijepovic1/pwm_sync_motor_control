#pragma once
// MESSAGE LISUM_VESC_STATUS_1 PACKING

#define MAVLINK_MSG_ID_LISUM_VESC_STATUS_1 59528


typedef struct __mavlink_lisum_vesc_status_1_t {
 float duty; /*<  Duty cycle [-1..1]*1000*/
 float total_current; /*<  Motor current [A]*10.*/
 float erpm; /*<  Motor speed [ERPM].*/
 uint8_t vesc_id; /*<  Target VESC ID.*/
} mavlink_lisum_vesc_status_1_t;

#define MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_LEN 13
#define MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_MIN_LEN 13
#define MAVLINK_MSG_ID_59528_LEN 13
#define MAVLINK_MSG_ID_59528_MIN_LEN 13

#define MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_CRC 208
#define MAVLINK_MSG_ID_59528_CRC 208



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_LISUM_VESC_STATUS_1 { \
    59528, \
    "LISUM_VESC_STATUS_1", \
    4, \
    {  { "vesc_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_lisum_vesc_status_1_t, vesc_id) }, \
         { "duty", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_lisum_vesc_status_1_t, duty) }, \
         { "total_current", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_lisum_vesc_status_1_t, total_current) }, \
         { "erpm", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_lisum_vesc_status_1_t, erpm) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_LISUM_VESC_STATUS_1 { \
    "LISUM_VESC_STATUS_1", \
    4, \
    {  { "vesc_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_lisum_vesc_status_1_t, vesc_id) }, \
         { "duty", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_lisum_vesc_status_1_t, duty) }, \
         { "total_current", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_lisum_vesc_status_1_t, total_current) }, \
         { "erpm", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_lisum_vesc_status_1_t, erpm) }, \
         } \
}
#endif

/**
 * @brief Pack a lisum_vesc_status_1 message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param vesc_id  Target VESC ID.
 * @param duty  Duty cycle [-1..1]*1000
 * @param total_current  Motor current [A]*10.
 * @param erpm  Motor speed [ERPM].
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_1_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t vesc_id, float duty, float total_current, float erpm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_LEN];
    _mav_put_float(buf, 0, duty);
    _mav_put_float(buf, 4, total_current);
    _mav_put_float(buf, 8, erpm);
    _mav_put_uint8_t(buf, 12, vesc_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_LEN);
#else
    mavlink_lisum_vesc_status_1_t packet;
    packet.duty = duty;
    packet.total_current = total_current;
    packet.erpm = erpm;
    packet.vesc_id = vesc_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_VESC_STATUS_1;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_CRC);
}

/**
 * @brief Pack a lisum_vesc_status_1 message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param vesc_id  Target VESC ID.
 * @param duty  Duty cycle [-1..1]*1000
 * @param total_current  Motor current [A]*10.
 * @param erpm  Motor speed [ERPM].
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_1_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t vesc_id, float duty, float total_current, float erpm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_LEN];
    _mav_put_float(buf, 0, duty);
    _mav_put_float(buf, 4, total_current);
    _mav_put_float(buf, 8, erpm);
    _mav_put_uint8_t(buf, 12, vesc_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_LEN);
#else
    mavlink_lisum_vesc_status_1_t packet;
    packet.duty = duty;
    packet.total_current = total_current;
    packet.erpm = erpm;
    packet.vesc_id = vesc_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_VESC_STATUS_1;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_LEN);
#endif
}

/**
 * @brief Pack a lisum_vesc_status_1 message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param vesc_id  Target VESC ID.
 * @param duty  Duty cycle [-1..1]*1000
 * @param total_current  Motor current [A]*10.
 * @param erpm  Motor speed [ERPM].
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_1_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t vesc_id,float duty,float total_current,float erpm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_LEN];
    _mav_put_float(buf, 0, duty);
    _mav_put_float(buf, 4, total_current);
    _mav_put_float(buf, 8, erpm);
    _mav_put_uint8_t(buf, 12, vesc_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_LEN);
#else
    mavlink_lisum_vesc_status_1_t packet;
    packet.duty = duty;
    packet.total_current = total_current;
    packet.erpm = erpm;
    packet.vesc_id = vesc_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_VESC_STATUS_1;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_CRC);
}

/**
 * @brief Encode a lisum_vesc_status_1 struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param lisum_vesc_status_1 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_1_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_lisum_vesc_status_1_t* lisum_vesc_status_1)
{
    return mavlink_msg_lisum_vesc_status_1_pack(system_id, component_id, msg, lisum_vesc_status_1->vesc_id, lisum_vesc_status_1->duty, lisum_vesc_status_1->total_current, lisum_vesc_status_1->erpm);
}

/**
 * @brief Encode a lisum_vesc_status_1 struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param lisum_vesc_status_1 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_1_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_lisum_vesc_status_1_t* lisum_vesc_status_1)
{
    return mavlink_msg_lisum_vesc_status_1_pack_chan(system_id, component_id, chan, msg, lisum_vesc_status_1->vesc_id, lisum_vesc_status_1->duty, lisum_vesc_status_1->total_current, lisum_vesc_status_1->erpm);
}

/**
 * @brief Encode a lisum_vesc_status_1 struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param lisum_vesc_status_1 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_1_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_lisum_vesc_status_1_t* lisum_vesc_status_1)
{
    return mavlink_msg_lisum_vesc_status_1_pack_status(system_id, component_id, _status, msg,  lisum_vesc_status_1->vesc_id, lisum_vesc_status_1->duty, lisum_vesc_status_1->total_current, lisum_vesc_status_1->erpm);
}

/**
 * @brief Send a lisum_vesc_status_1 message
 * @param chan MAVLink channel to send the message
 *
 * @param vesc_id  Target VESC ID.
 * @param duty  Duty cycle [-1..1]*1000
 * @param total_current  Motor current [A]*10.
 * @param erpm  Motor speed [ERPM].
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_lisum_vesc_status_1_send(mavlink_channel_t chan, uint8_t vesc_id, float duty, float total_current, float erpm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_LEN];
    _mav_put_float(buf, 0, duty);
    _mav_put_float(buf, 4, total_current);
    _mav_put_float(buf, 8, erpm);
    _mav_put_uint8_t(buf, 12, vesc_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1, buf, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_CRC);
#else
    mavlink_lisum_vesc_status_1_t packet;
    packet.duty = duty;
    packet.total_current = total_current;
    packet.erpm = erpm;
    packet.vesc_id = vesc_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1, (const char *)&packet, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_CRC);
#endif
}

/**
 * @brief Send a lisum_vesc_status_1 message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_lisum_vesc_status_1_send_struct(mavlink_channel_t chan, const mavlink_lisum_vesc_status_1_t* lisum_vesc_status_1)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_lisum_vesc_status_1_send(chan, lisum_vesc_status_1->vesc_id, lisum_vesc_status_1->duty, lisum_vesc_status_1->total_current, lisum_vesc_status_1->erpm);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1, (const char *)lisum_vesc_status_1, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_CRC);
#endif
}

#if MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_lisum_vesc_status_1_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t vesc_id, float duty, float total_current, float erpm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, duty);
    _mav_put_float(buf, 4, total_current);
    _mav_put_float(buf, 8, erpm);
    _mav_put_uint8_t(buf, 12, vesc_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1, buf, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_CRC);
#else
    mavlink_lisum_vesc_status_1_t *packet = (mavlink_lisum_vesc_status_1_t *)msgbuf;
    packet->duty = duty;
    packet->total_current = total_current;
    packet->erpm = erpm;
    packet->vesc_id = vesc_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1, (const char *)packet, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_CRC);
#endif
}
#endif

#endif

// MESSAGE LISUM_VESC_STATUS_1 UNPACKING


/**
 * @brief Get field vesc_id from lisum_vesc_status_1 message
 *
 * @return  Target VESC ID.
 */
static inline uint8_t mavlink_msg_lisum_vesc_status_1_get_vesc_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field duty from lisum_vesc_status_1 message
 *
 * @return  Duty cycle [-1..1]*1000
 */
static inline float mavlink_msg_lisum_vesc_status_1_get_duty(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field total_current from lisum_vesc_status_1 message
 *
 * @return  Motor current [A]*10.
 */
static inline float mavlink_msg_lisum_vesc_status_1_get_total_current(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field erpm from lisum_vesc_status_1 message
 *
 * @return  Motor speed [ERPM].
 */
static inline float mavlink_msg_lisum_vesc_status_1_get_erpm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Decode a lisum_vesc_status_1 message into a struct
 *
 * @param msg The message to decode
 * @param lisum_vesc_status_1 C-struct to decode the message contents into
 */
static inline void mavlink_msg_lisum_vesc_status_1_decode(const mavlink_message_t* msg, mavlink_lisum_vesc_status_1_t* lisum_vesc_status_1)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    lisum_vesc_status_1->duty = mavlink_msg_lisum_vesc_status_1_get_duty(msg);
    lisum_vesc_status_1->total_current = mavlink_msg_lisum_vesc_status_1_get_total_current(msg);
    lisum_vesc_status_1->erpm = mavlink_msg_lisum_vesc_status_1_get_erpm(msg);
    lisum_vesc_status_1->vesc_id = mavlink_msg_lisum_vesc_status_1_get_vesc_id(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_LEN? msg->len : MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_LEN;
        memset(lisum_vesc_status_1, 0, MAVLINK_MSG_ID_LISUM_VESC_STATUS_1_LEN);
    memcpy(lisum_vesc_status_1, _MAV_PAYLOAD(msg), len);
#endif
}
