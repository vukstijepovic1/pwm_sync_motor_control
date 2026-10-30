#pragma once
// MESSAGE LISUM_VESC_STATUS_2 PACKING

#define MAVLINK_MSG_ID_LISUM_VESC_STATUS_2 59529


typedef struct __mavlink_lisum_vesc_status_2_t {
 float amp_hours_charged; /*<  Amp-hours charged [Ah]*10000.*/
 float amp_hours; /*<  Amp-hours [Ah]*10000.*/
 uint8_t vesc_id; /*<  Target VESC ID.*/
} mavlink_lisum_vesc_status_2_t;

#define MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_LEN 9
#define MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_MIN_LEN 9
#define MAVLINK_MSG_ID_59529_LEN 9
#define MAVLINK_MSG_ID_59529_MIN_LEN 9

#define MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_CRC 172
#define MAVLINK_MSG_ID_59529_CRC 172



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_LISUM_VESC_STATUS_2 { \
    59529, \
    "LISUM_VESC_STATUS_2", \
    3, \
    {  { "vesc_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_lisum_vesc_status_2_t, vesc_id) }, \
         { "amp_hours_charged", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_lisum_vesc_status_2_t, amp_hours_charged) }, \
         { "amp_hours", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_lisum_vesc_status_2_t, amp_hours) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_LISUM_VESC_STATUS_2 { \
    "LISUM_VESC_STATUS_2", \
    3, \
    {  { "vesc_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_lisum_vesc_status_2_t, vesc_id) }, \
         { "amp_hours_charged", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_lisum_vesc_status_2_t, amp_hours_charged) }, \
         { "amp_hours", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_lisum_vesc_status_2_t, amp_hours) }, \
         } \
}
#endif

/**
 * @brief Pack a lisum_vesc_status_2 message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param vesc_id  Target VESC ID.
 * @param amp_hours_charged  Amp-hours charged [Ah]*10000.
 * @param amp_hours  Amp-hours [Ah]*10000.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_2_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t vesc_id, float amp_hours_charged, float amp_hours)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_LEN];
    _mav_put_float(buf, 0, amp_hours_charged);
    _mav_put_float(buf, 4, amp_hours);
    _mav_put_uint8_t(buf, 8, vesc_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_LEN);
#else
    mavlink_lisum_vesc_status_2_t packet;
    packet.amp_hours_charged = amp_hours_charged;
    packet.amp_hours = amp_hours;
    packet.vesc_id = vesc_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_VESC_STATUS_2;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_CRC);
}

/**
 * @brief Pack a lisum_vesc_status_2 message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param vesc_id  Target VESC ID.
 * @param amp_hours_charged  Amp-hours charged [Ah]*10000.
 * @param amp_hours  Amp-hours [Ah]*10000.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_2_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t vesc_id, float amp_hours_charged, float amp_hours)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_LEN];
    _mav_put_float(buf, 0, amp_hours_charged);
    _mav_put_float(buf, 4, amp_hours);
    _mav_put_uint8_t(buf, 8, vesc_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_LEN);
#else
    mavlink_lisum_vesc_status_2_t packet;
    packet.amp_hours_charged = amp_hours_charged;
    packet.amp_hours = amp_hours;
    packet.vesc_id = vesc_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_VESC_STATUS_2;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_LEN);
#endif
}

/**
 * @brief Pack a lisum_vesc_status_2 message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param vesc_id  Target VESC ID.
 * @param amp_hours_charged  Amp-hours charged [Ah]*10000.
 * @param amp_hours  Amp-hours [Ah]*10000.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_2_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t vesc_id,float amp_hours_charged,float amp_hours)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_LEN];
    _mav_put_float(buf, 0, amp_hours_charged);
    _mav_put_float(buf, 4, amp_hours);
    _mav_put_uint8_t(buf, 8, vesc_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_LEN);
#else
    mavlink_lisum_vesc_status_2_t packet;
    packet.amp_hours_charged = amp_hours_charged;
    packet.amp_hours = amp_hours;
    packet.vesc_id = vesc_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_VESC_STATUS_2;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_CRC);
}

/**
 * @brief Encode a lisum_vesc_status_2 struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param lisum_vesc_status_2 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_2_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_lisum_vesc_status_2_t* lisum_vesc_status_2)
{
    return mavlink_msg_lisum_vesc_status_2_pack(system_id, component_id, msg, lisum_vesc_status_2->vesc_id, lisum_vesc_status_2->amp_hours_charged, lisum_vesc_status_2->amp_hours);
}

/**
 * @brief Encode a lisum_vesc_status_2 struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param lisum_vesc_status_2 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_2_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_lisum_vesc_status_2_t* lisum_vesc_status_2)
{
    return mavlink_msg_lisum_vesc_status_2_pack_chan(system_id, component_id, chan, msg, lisum_vesc_status_2->vesc_id, lisum_vesc_status_2->amp_hours_charged, lisum_vesc_status_2->amp_hours);
}

/**
 * @brief Encode a lisum_vesc_status_2 struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param lisum_vesc_status_2 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_2_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_lisum_vesc_status_2_t* lisum_vesc_status_2)
{
    return mavlink_msg_lisum_vesc_status_2_pack_status(system_id, component_id, _status, msg,  lisum_vesc_status_2->vesc_id, lisum_vesc_status_2->amp_hours_charged, lisum_vesc_status_2->amp_hours);
}

/**
 * @brief Send a lisum_vesc_status_2 message
 * @param chan MAVLink channel to send the message
 *
 * @param vesc_id  Target VESC ID.
 * @param amp_hours_charged  Amp-hours charged [Ah]*10000.
 * @param amp_hours  Amp-hours [Ah]*10000.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_lisum_vesc_status_2_send(mavlink_channel_t chan, uint8_t vesc_id, float amp_hours_charged, float amp_hours)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_LEN];
    _mav_put_float(buf, 0, amp_hours_charged);
    _mav_put_float(buf, 4, amp_hours);
    _mav_put_uint8_t(buf, 8, vesc_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2, buf, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_CRC);
#else
    mavlink_lisum_vesc_status_2_t packet;
    packet.amp_hours_charged = amp_hours_charged;
    packet.amp_hours = amp_hours;
    packet.vesc_id = vesc_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2, (const char *)&packet, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_CRC);
#endif
}

/**
 * @brief Send a lisum_vesc_status_2 message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_lisum_vesc_status_2_send_struct(mavlink_channel_t chan, const mavlink_lisum_vesc_status_2_t* lisum_vesc_status_2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_lisum_vesc_status_2_send(chan, lisum_vesc_status_2->vesc_id, lisum_vesc_status_2->amp_hours_charged, lisum_vesc_status_2->amp_hours);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2, (const char *)lisum_vesc_status_2, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_CRC);
#endif
}

#if MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_lisum_vesc_status_2_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t vesc_id, float amp_hours_charged, float amp_hours)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, amp_hours_charged);
    _mav_put_float(buf, 4, amp_hours);
    _mav_put_uint8_t(buf, 8, vesc_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2, buf, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_CRC);
#else
    mavlink_lisum_vesc_status_2_t *packet = (mavlink_lisum_vesc_status_2_t *)msgbuf;
    packet->amp_hours_charged = amp_hours_charged;
    packet->amp_hours = amp_hours;
    packet->vesc_id = vesc_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2, (const char *)packet, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_CRC);
#endif
}
#endif

#endif

// MESSAGE LISUM_VESC_STATUS_2 UNPACKING


/**
 * @brief Get field vesc_id from lisum_vesc_status_2 message
 *
 * @return  Target VESC ID.
 */
static inline uint8_t mavlink_msg_lisum_vesc_status_2_get_vesc_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field amp_hours_charged from lisum_vesc_status_2 message
 *
 * @return  Amp-hours charged [Ah]*10000.
 */
static inline float mavlink_msg_lisum_vesc_status_2_get_amp_hours_charged(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field amp_hours from lisum_vesc_status_2 message
 *
 * @return  Amp-hours [Ah]*10000.
 */
static inline float mavlink_msg_lisum_vesc_status_2_get_amp_hours(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Decode a lisum_vesc_status_2 message into a struct
 *
 * @param msg The message to decode
 * @param lisum_vesc_status_2 C-struct to decode the message contents into
 */
static inline void mavlink_msg_lisum_vesc_status_2_decode(const mavlink_message_t* msg, mavlink_lisum_vesc_status_2_t* lisum_vesc_status_2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    lisum_vesc_status_2->amp_hours_charged = mavlink_msg_lisum_vesc_status_2_get_amp_hours_charged(msg);
    lisum_vesc_status_2->amp_hours = mavlink_msg_lisum_vesc_status_2_get_amp_hours(msg);
    lisum_vesc_status_2->vesc_id = mavlink_msg_lisum_vesc_status_2_get_vesc_id(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_LEN? msg->len : MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_LEN;
        memset(lisum_vesc_status_2, 0, MAVLINK_MSG_ID_LISUM_VESC_STATUS_2_LEN);
    memcpy(lisum_vesc_status_2, _MAV_PAYLOAD(msg), len);
#endif
}
