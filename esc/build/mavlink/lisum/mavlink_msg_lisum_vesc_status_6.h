#pragma once
// MESSAGE LISUM_VESC_STATUS_6 PACKING

#define MAVLINK_MSG_ID_LISUM_VESC_STATUS_6 59533


typedef struct __mavlink_lisum_vesc_status_6_t {
 uint16_t ppm; /*<  PPM value.*/
 uint16_t adc1; /*<  ADC1 value.*/
 uint16_t adc2; /*<  ADC2 value.*/
 uint16_t adc3; /*<  ADC3 value.*/
 uint8_t vesc_id; /*<  Target VESC ID.*/
} mavlink_lisum_vesc_status_6_t;

#define MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_LEN 9
#define MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_MIN_LEN 9
#define MAVLINK_MSG_ID_59533_LEN 9
#define MAVLINK_MSG_ID_59533_MIN_LEN 9

#define MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_CRC 160
#define MAVLINK_MSG_ID_59533_CRC 160



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_LISUM_VESC_STATUS_6 { \
    59533, \
    "LISUM_VESC_STATUS_6", \
    5, \
    {  { "vesc_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_lisum_vesc_status_6_t, vesc_id) }, \
         { "ppm", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_lisum_vesc_status_6_t, ppm) }, \
         { "adc1", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_lisum_vesc_status_6_t, adc1) }, \
         { "adc2", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_lisum_vesc_status_6_t, adc2) }, \
         { "adc3", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_lisum_vesc_status_6_t, adc3) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_LISUM_VESC_STATUS_6 { \
    "LISUM_VESC_STATUS_6", \
    5, \
    {  { "vesc_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_lisum_vesc_status_6_t, vesc_id) }, \
         { "ppm", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_lisum_vesc_status_6_t, ppm) }, \
         { "adc1", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_lisum_vesc_status_6_t, adc1) }, \
         { "adc2", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_lisum_vesc_status_6_t, adc2) }, \
         { "adc3", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_lisum_vesc_status_6_t, adc3) }, \
         } \
}
#endif

/**
 * @brief Pack a lisum_vesc_status_6 message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param vesc_id  Target VESC ID.
 * @param ppm  PPM value.
 * @param adc1  ADC1 value.
 * @param adc2  ADC2 value.
 * @param adc3  ADC3 value.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_6_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t vesc_id, uint16_t ppm, uint16_t adc1, uint16_t adc2, uint16_t adc3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_LEN];
    _mav_put_uint16_t(buf, 0, ppm);
    _mav_put_uint16_t(buf, 2, adc1);
    _mav_put_uint16_t(buf, 4, adc2);
    _mav_put_uint16_t(buf, 6, adc3);
    _mav_put_uint8_t(buf, 8, vesc_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_LEN);
#else
    mavlink_lisum_vesc_status_6_t packet;
    packet.ppm = ppm;
    packet.adc1 = adc1;
    packet.adc2 = adc2;
    packet.adc3 = adc3;
    packet.vesc_id = vesc_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_VESC_STATUS_6;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_CRC);
}

/**
 * @brief Pack a lisum_vesc_status_6 message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param vesc_id  Target VESC ID.
 * @param ppm  PPM value.
 * @param adc1  ADC1 value.
 * @param adc2  ADC2 value.
 * @param adc3  ADC3 value.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_6_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t vesc_id, uint16_t ppm, uint16_t adc1, uint16_t adc2, uint16_t adc3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_LEN];
    _mav_put_uint16_t(buf, 0, ppm);
    _mav_put_uint16_t(buf, 2, adc1);
    _mav_put_uint16_t(buf, 4, adc2);
    _mav_put_uint16_t(buf, 6, adc3);
    _mav_put_uint8_t(buf, 8, vesc_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_LEN);
#else
    mavlink_lisum_vesc_status_6_t packet;
    packet.ppm = ppm;
    packet.adc1 = adc1;
    packet.adc2 = adc2;
    packet.adc3 = adc3;
    packet.vesc_id = vesc_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_VESC_STATUS_6;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_LEN);
#endif
}

/**
 * @brief Pack a lisum_vesc_status_6 message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param vesc_id  Target VESC ID.
 * @param ppm  PPM value.
 * @param adc1  ADC1 value.
 * @param adc2  ADC2 value.
 * @param adc3  ADC3 value.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_6_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t vesc_id,uint16_t ppm,uint16_t adc1,uint16_t adc2,uint16_t adc3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_LEN];
    _mav_put_uint16_t(buf, 0, ppm);
    _mav_put_uint16_t(buf, 2, adc1);
    _mav_put_uint16_t(buf, 4, adc2);
    _mav_put_uint16_t(buf, 6, adc3);
    _mav_put_uint8_t(buf, 8, vesc_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_LEN);
#else
    mavlink_lisum_vesc_status_6_t packet;
    packet.ppm = ppm;
    packet.adc1 = adc1;
    packet.adc2 = adc2;
    packet.adc3 = adc3;
    packet.vesc_id = vesc_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_VESC_STATUS_6;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_CRC);
}

/**
 * @brief Encode a lisum_vesc_status_6 struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param lisum_vesc_status_6 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_6_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_lisum_vesc_status_6_t* lisum_vesc_status_6)
{
    return mavlink_msg_lisum_vesc_status_6_pack(system_id, component_id, msg, lisum_vesc_status_6->vesc_id, lisum_vesc_status_6->ppm, lisum_vesc_status_6->adc1, lisum_vesc_status_6->adc2, lisum_vesc_status_6->adc3);
}

/**
 * @brief Encode a lisum_vesc_status_6 struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param lisum_vesc_status_6 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_6_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_lisum_vesc_status_6_t* lisum_vesc_status_6)
{
    return mavlink_msg_lisum_vesc_status_6_pack_chan(system_id, component_id, chan, msg, lisum_vesc_status_6->vesc_id, lisum_vesc_status_6->ppm, lisum_vesc_status_6->adc1, lisum_vesc_status_6->adc2, lisum_vesc_status_6->adc3);
}

/**
 * @brief Encode a lisum_vesc_status_6 struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param lisum_vesc_status_6 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_6_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_lisum_vesc_status_6_t* lisum_vesc_status_6)
{
    return mavlink_msg_lisum_vesc_status_6_pack_status(system_id, component_id, _status, msg,  lisum_vesc_status_6->vesc_id, lisum_vesc_status_6->ppm, lisum_vesc_status_6->adc1, lisum_vesc_status_6->adc2, lisum_vesc_status_6->adc3);
}

/**
 * @brief Send a lisum_vesc_status_6 message
 * @param chan MAVLink channel to send the message
 *
 * @param vesc_id  Target VESC ID.
 * @param ppm  PPM value.
 * @param adc1  ADC1 value.
 * @param adc2  ADC2 value.
 * @param adc3  ADC3 value.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_lisum_vesc_status_6_send(mavlink_channel_t chan, uint8_t vesc_id, uint16_t ppm, uint16_t adc1, uint16_t adc2, uint16_t adc3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_LEN];
    _mav_put_uint16_t(buf, 0, ppm);
    _mav_put_uint16_t(buf, 2, adc1);
    _mav_put_uint16_t(buf, 4, adc2);
    _mav_put_uint16_t(buf, 6, adc3);
    _mav_put_uint8_t(buf, 8, vesc_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6, buf, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_CRC);
#else
    mavlink_lisum_vesc_status_6_t packet;
    packet.ppm = ppm;
    packet.adc1 = adc1;
    packet.adc2 = adc2;
    packet.adc3 = adc3;
    packet.vesc_id = vesc_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6, (const char *)&packet, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_CRC);
#endif
}

/**
 * @brief Send a lisum_vesc_status_6 message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_lisum_vesc_status_6_send_struct(mavlink_channel_t chan, const mavlink_lisum_vesc_status_6_t* lisum_vesc_status_6)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_lisum_vesc_status_6_send(chan, lisum_vesc_status_6->vesc_id, lisum_vesc_status_6->ppm, lisum_vesc_status_6->adc1, lisum_vesc_status_6->adc2, lisum_vesc_status_6->adc3);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6, (const char *)lisum_vesc_status_6, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_CRC);
#endif
}

#if MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_lisum_vesc_status_6_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t vesc_id, uint16_t ppm, uint16_t adc1, uint16_t adc2, uint16_t adc3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, ppm);
    _mav_put_uint16_t(buf, 2, adc1);
    _mav_put_uint16_t(buf, 4, adc2);
    _mav_put_uint16_t(buf, 6, adc3);
    _mav_put_uint8_t(buf, 8, vesc_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6, buf, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_CRC);
#else
    mavlink_lisum_vesc_status_6_t *packet = (mavlink_lisum_vesc_status_6_t *)msgbuf;
    packet->ppm = ppm;
    packet->adc1 = adc1;
    packet->adc2 = adc2;
    packet->adc3 = adc3;
    packet->vesc_id = vesc_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6, (const char *)packet, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_MIN_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_LEN, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_CRC);
#endif
}
#endif

#endif

// MESSAGE LISUM_VESC_STATUS_6 UNPACKING


/**
 * @brief Get field vesc_id from lisum_vesc_status_6 message
 *
 * @return  Target VESC ID.
 */
static inline uint8_t mavlink_msg_lisum_vesc_status_6_get_vesc_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field ppm from lisum_vesc_status_6 message
 *
 * @return  PPM value.
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_6_get_ppm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field adc1 from lisum_vesc_status_6 message
 *
 * @return  ADC1 value.
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_6_get_adc1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  2);
}

/**
 * @brief Get field adc2 from lisum_vesc_status_6 message
 *
 * @return  ADC2 value.
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_6_get_adc2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field adc3 from lisum_vesc_status_6 message
 *
 * @return  ADC3 value.
 */
static inline uint16_t mavlink_msg_lisum_vesc_status_6_get_adc3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  6);
}

/**
 * @brief Decode a lisum_vesc_status_6 message into a struct
 *
 * @param msg The message to decode
 * @param lisum_vesc_status_6 C-struct to decode the message contents into
 */
static inline void mavlink_msg_lisum_vesc_status_6_decode(const mavlink_message_t* msg, mavlink_lisum_vesc_status_6_t* lisum_vesc_status_6)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    lisum_vesc_status_6->ppm = mavlink_msg_lisum_vesc_status_6_get_ppm(msg);
    lisum_vesc_status_6->adc1 = mavlink_msg_lisum_vesc_status_6_get_adc1(msg);
    lisum_vesc_status_6->adc2 = mavlink_msg_lisum_vesc_status_6_get_adc2(msg);
    lisum_vesc_status_6->adc3 = mavlink_msg_lisum_vesc_status_6_get_adc3(msg);
    lisum_vesc_status_6->vesc_id = mavlink_msg_lisum_vesc_status_6_get_vesc_id(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_LEN? msg->len : MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_LEN;
        memset(lisum_vesc_status_6, 0, MAVLINK_MSG_ID_LISUM_VESC_STATUS_6_LEN);
    memcpy(lisum_vesc_status_6, _MAV_PAYLOAD(msg), len);
#endif
}
