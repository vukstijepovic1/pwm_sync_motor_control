#pragma once
// MESSAGE LISUM_GNSS_RECV_DATA PACKING

#define MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA 59264


typedef struct __mavlink_lisum_gnss_recv_data_t {
 double lon; /*< [deg] Longitude*/
 double lat; /*< [deg] Latitude*/
 float alt; /*< [m] Altitude*/
 float head; /*< [deg] Heading*/
 float head_rtk; /*< [deg] RTK Heading*/
 float vel_ne; /*< [m/s] Planar velocity*/
 float vel_d; /*< [m/s] Vertical velocity*/
 uint8_t dev_id; /*<  Index of receiver*/
 uint8_t fix_type; /*<  Fix Type Flag*/
 uint8_t carr_sol; /*<  Carrier phase solution type*/
 uint8_t rtk_head_valid; /*<  RTK heading validity flag*/
 uint8_t sv_num; /*<  Number of satellites*/
} mavlink_lisum_gnss_recv_data_t;

#define MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_LEN 41
#define MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_MIN_LEN 41
#define MAVLINK_MSG_ID_59264_LEN 41
#define MAVLINK_MSG_ID_59264_MIN_LEN 41

#define MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_CRC 142
#define MAVLINK_MSG_ID_59264_CRC 142



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_LISUM_GNSS_RECV_DATA { \
    59264, \
    "LISUM_GNSS_RECV_DATA", \
    12, \
    {  { "dev_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_lisum_gnss_recv_data_t, dev_id) }, \
         { "lon", NULL, MAVLINK_TYPE_DOUBLE, 0, 0, offsetof(mavlink_lisum_gnss_recv_data_t, lon) }, \
         { "lat", NULL, MAVLINK_TYPE_DOUBLE, 0, 8, offsetof(mavlink_lisum_gnss_recv_data_t, lat) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_lisum_gnss_recv_data_t, alt) }, \
         { "head", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_lisum_gnss_recv_data_t, head) }, \
         { "head_rtk", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_lisum_gnss_recv_data_t, head_rtk) }, \
         { "vel_ne", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_lisum_gnss_recv_data_t, vel_ne) }, \
         { "vel_d", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_lisum_gnss_recv_data_t, vel_d) }, \
         { "fix_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 37, offsetof(mavlink_lisum_gnss_recv_data_t, fix_type) }, \
         { "carr_sol", NULL, MAVLINK_TYPE_UINT8_T, 0, 38, offsetof(mavlink_lisum_gnss_recv_data_t, carr_sol) }, \
         { "rtk_head_valid", NULL, MAVLINK_TYPE_UINT8_T, 0, 39, offsetof(mavlink_lisum_gnss_recv_data_t, rtk_head_valid) }, \
         { "sv_num", NULL, MAVLINK_TYPE_UINT8_T, 0, 40, offsetof(mavlink_lisum_gnss_recv_data_t, sv_num) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_LISUM_GNSS_RECV_DATA { \
    "LISUM_GNSS_RECV_DATA", \
    12, \
    {  { "dev_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_lisum_gnss_recv_data_t, dev_id) }, \
         { "lon", NULL, MAVLINK_TYPE_DOUBLE, 0, 0, offsetof(mavlink_lisum_gnss_recv_data_t, lon) }, \
         { "lat", NULL, MAVLINK_TYPE_DOUBLE, 0, 8, offsetof(mavlink_lisum_gnss_recv_data_t, lat) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_lisum_gnss_recv_data_t, alt) }, \
         { "head", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_lisum_gnss_recv_data_t, head) }, \
         { "head_rtk", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_lisum_gnss_recv_data_t, head_rtk) }, \
         { "vel_ne", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_lisum_gnss_recv_data_t, vel_ne) }, \
         { "vel_d", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_lisum_gnss_recv_data_t, vel_d) }, \
         { "fix_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 37, offsetof(mavlink_lisum_gnss_recv_data_t, fix_type) }, \
         { "carr_sol", NULL, MAVLINK_TYPE_UINT8_T, 0, 38, offsetof(mavlink_lisum_gnss_recv_data_t, carr_sol) }, \
         { "rtk_head_valid", NULL, MAVLINK_TYPE_UINT8_T, 0, 39, offsetof(mavlink_lisum_gnss_recv_data_t, rtk_head_valid) }, \
         { "sv_num", NULL, MAVLINK_TYPE_UINT8_T, 0, 40, offsetof(mavlink_lisum_gnss_recv_data_t, sv_num) }, \
         } \
}
#endif

/**
 * @brief Pack a lisum_gnss_recv_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param dev_id  Index of receiver
 * @param lon [deg] Longitude
 * @param lat [deg] Latitude
 * @param alt [m] Altitude
 * @param head [deg] Heading
 * @param head_rtk [deg] RTK Heading
 * @param vel_ne [m/s] Planar velocity
 * @param vel_d [m/s] Vertical velocity
 * @param fix_type  Fix Type Flag
 * @param carr_sol  Carrier phase solution type
 * @param rtk_head_valid  RTK heading validity flag
 * @param sv_num  Number of satellites
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_gnss_recv_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t dev_id, double lon, double lat, float alt, float head, float head_rtk, float vel_ne, float vel_d, uint8_t fix_type, uint8_t carr_sol, uint8_t rtk_head_valid, uint8_t sv_num)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_LEN];
    _mav_put_double(buf, 0, lon);
    _mav_put_double(buf, 8, lat);
    _mav_put_float(buf, 16, alt);
    _mav_put_float(buf, 20, head);
    _mav_put_float(buf, 24, head_rtk);
    _mav_put_float(buf, 28, vel_ne);
    _mav_put_float(buf, 32, vel_d);
    _mav_put_uint8_t(buf, 36, dev_id);
    _mav_put_uint8_t(buf, 37, fix_type);
    _mav_put_uint8_t(buf, 38, carr_sol);
    _mav_put_uint8_t(buf, 39, rtk_head_valid);
    _mav_put_uint8_t(buf, 40, sv_num);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_LEN);
#else
    mavlink_lisum_gnss_recv_data_t packet;
    packet.lon = lon;
    packet.lat = lat;
    packet.alt = alt;
    packet.head = head;
    packet.head_rtk = head_rtk;
    packet.vel_ne = vel_ne;
    packet.vel_d = vel_d;
    packet.dev_id = dev_id;
    packet.fix_type = fix_type;
    packet.carr_sol = carr_sol;
    packet.rtk_head_valid = rtk_head_valid;
    packet.sv_num = sv_num;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_MIN_LEN, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_LEN, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_CRC);
}

/**
 * @brief Pack a lisum_gnss_recv_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param dev_id  Index of receiver
 * @param lon [deg] Longitude
 * @param lat [deg] Latitude
 * @param alt [m] Altitude
 * @param head [deg] Heading
 * @param head_rtk [deg] RTK Heading
 * @param vel_ne [m/s] Planar velocity
 * @param vel_d [m/s] Vertical velocity
 * @param fix_type  Fix Type Flag
 * @param carr_sol  Carrier phase solution type
 * @param rtk_head_valid  RTK heading validity flag
 * @param sv_num  Number of satellites
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_gnss_recv_data_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t dev_id, double lon, double lat, float alt, float head, float head_rtk, float vel_ne, float vel_d, uint8_t fix_type, uint8_t carr_sol, uint8_t rtk_head_valid, uint8_t sv_num)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_LEN];
    _mav_put_double(buf, 0, lon);
    _mav_put_double(buf, 8, lat);
    _mav_put_float(buf, 16, alt);
    _mav_put_float(buf, 20, head);
    _mav_put_float(buf, 24, head_rtk);
    _mav_put_float(buf, 28, vel_ne);
    _mav_put_float(buf, 32, vel_d);
    _mav_put_uint8_t(buf, 36, dev_id);
    _mav_put_uint8_t(buf, 37, fix_type);
    _mav_put_uint8_t(buf, 38, carr_sol);
    _mav_put_uint8_t(buf, 39, rtk_head_valid);
    _mav_put_uint8_t(buf, 40, sv_num);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_LEN);
#else
    mavlink_lisum_gnss_recv_data_t packet;
    packet.lon = lon;
    packet.lat = lat;
    packet.alt = alt;
    packet.head = head;
    packet.head_rtk = head_rtk;
    packet.vel_ne = vel_ne;
    packet.vel_d = vel_d;
    packet.dev_id = dev_id;
    packet.fix_type = fix_type;
    packet.carr_sol = carr_sol;
    packet.rtk_head_valid = rtk_head_valid;
    packet.sv_num = sv_num;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_MIN_LEN, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_LEN, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_MIN_LEN, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_LEN);
#endif
}

/**
 * @brief Pack a lisum_gnss_recv_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param dev_id  Index of receiver
 * @param lon [deg] Longitude
 * @param lat [deg] Latitude
 * @param alt [m] Altitude
 * @param head [deg] Heading
 * @param head_rtk [deg] RTK Heading
 * @param vel_ne [m/s] Planar velocity
 * @param vel_d [m/s] Vertical velocity
 * @param fix_type  Fix Type Flag
 * @param carr_sol  Carrier phase solution type
 * @param rtk_head_valid  RTK heading validity flag
 * @param sv_num  Number of satellites
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_gnss_recv_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t dev_id,double lon,double lat,float alt,float head,float head_rtk,float vel_ne,float vel_d,uint8_t fix_type,uint8_t carr_sol,uint8_t rtk_head_valid,uint8_t sv_num)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_LEN];
    _mav_put_double(buf, 0, lon);
    _mav_put_double(buf, 8, lat);
    _mav_put_float(buf, 16, alt);
    _mav_put_float(buf, 20, head);
    _mav_put_float(buf, 24, head_rtk);
    _mav_put_float(buf, 28, vel_ne);
    _mav_put_float(buf, 32, vel_d);
    _mav_put_uint8_t(buf, 36, dev_id);
    _mav_put_uint8_t(buf, 37, fix_type);
    _mav_put_uint8_t(buf, 38, carr_sol);
    _mav_put_uint8_t(buf, 39, rtk_head_valid);
    _mav_put_uint8_t(buf, 40, sv_num);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_LEN);
#else
    mavlink_lisum_gnss_recv_data_t packet;
    packet.lon = lon;
    packet.lat = lat;
    packet.alt = alt;
    packet.head = head;
    packet.head_rtk = head_rtk;
    packet.vel_ne = vel_ne;
    packet.vel_d = vel_d;
    packet.dev_id = dev_id;
    packet.fix_type = fix_type;
    packet.carr_sol = carr_sol;
    packet.rtk_head_valid = rtk_head_valid;
    packet.sv_num = sv_num;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_MIN_LEN, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_LEN, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_CRC);
}

/**
 * @brief Encode a lisum_gnss_recv_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param lisum_gnss_recv_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_gnss_recv_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_lisum_gnss_recv_data_t* lisum_gnss_recv_data)
{
    return mavlink_msg_lisum_gnss_recv_data_pack(system_id, component_id, msg, lisum_gnss_recv_data->dev_id, lisum_gnss_recv_data->lon, lisum_gnss_recv_data->lat, lisum_gnss_recv_data->alt, lisum_gnss_recv_data->head, lisum_gnss_recv_data->head_rtk, lisum_gnss_recv_data->vel_ne, lisum_gnss_recv_data->vel_d, lisum_gnss_recv_data->fix_type, lisum_gnss_recv_data->carr_sol, lisum_gnss_recv_data->rtk_head_valid, lisum_gnss_recv_data->sv_num);
}

/**
 * @brief Encode a lisum_gnss_recv_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param lisum_gnss_recv_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_gnss_recv_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_lisum_gnss_recv_data_t* lisum_gnss_recv_data)
{
    return mavlink_msg_lisum_gnss_recv_data_pack_chan(system_id, component_id, chan, msg, lisum_gnss_recv_data->dev_id, lisum_gnss_recv_data->lon, lisum_gnss_recv_data->lat, lisum_gnss_recv_data->alt, lisum_gnss_recv_data->head, lisum_gnss_recv_data->head_rtk, lisum_gnss_recv_data->vel_ne, lisum_gnss_recv_data->vel_d, lisum_gnss_recv_data->fix_type, lisum_gnss_recv_data->carr_sol, lisum_gnss_recv_data->rtk_head_valid, lisum_gnss_recv_data->sv_num);
}

/**
 * @brief Encode a lisum_gnss_recv_data struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param lisum_gnss_recv_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_gnss_recv_data_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_lisum_gnss_recv_data_t* lisum_gnss_recv_data)
{
    return mavlink_msg_lisum_gnss_recv_data_pack_status(system_id, component_id, _status, msg,  lisum_gnss_recv_data->dev_id, lisum_gnss_recv_data->lon, lisum_gnss_recv_data->lat, lisum_gnss_recv_data->alt, lisum_gnss_recv_data->head, lisum_gnss_recv_data->head_rtk, lisum_gnss_recv_data->vel_ne, lisum_gnss_recv_data->vel_d, lisum_gnss_recv_data->fix_type, lisum_gnss_recv_data->carr_sol, lisum_gnss_recv_data->rtk_head_valid, lisum_gnss_recv_data->sv_num);
}

/**
 * @brief Send a lisum_gnss_recv_data message
 * @param chan MAVLink channel to send the message
 *
 * @param dev_id  Index of receiver
 * @param lon [deg] Longitude
 * @param lat [deg] Latitude
 * @param alt [m] Altitude
 * @param head [deg] Heading
 * @param head_rtk [deg] RTK Heading
 * @param vel_ne [m/s] Planar velocity
 * @param vel_d [m/s] Vertical velocity
 * @param fix_type  Fix Type Flag
 * @param carr_sol  Carrier phase solution type
 * @param rtk_head_valid  RTK heading validity flag
 * @param sv_num  Number of satellites
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_lisum_gnss_recv_data_send(mavlink_channel_t chan, uint8_t dev_id, double lon, double lat, float alt, float head, float head_rtk, float vel_ne, float vel_d, uint8_t fix_type, uint8_t carr_sol, uint8_t rtk_head_valid, uint8_t sv_num)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_LEN];
    _mav_put_double(buf, 0, lon);
    _mav_put_double(buf, 8, lat);
    _mav_put_float(buf, 16, alt);
    _mav_put_float(buf, 20, head);
    _mav_put_float(buf, 24, head_rtk);
    _mav_put_float(buf, 28, vel_ne);
    _mav_put_float(buf, 32, vel_d);
    _mav_put_uint8_t(buf, 36, dev_id);
    _mav_put_uint8_t(buf, 37, fix_type);
    _mav_put_uint8_t(buf, 38, carr_sol);
    _mav_put_uint8_t(buf, 39, rtk_head_valid);
    _mav_put_uint8_t(buf, 40, sv_num);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA, buf, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_MIN_LEN, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_LEN, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_CRC);
#else
    mavlink_lisum_gnss_recv_data_t packet;
    packet.lon = lon;
    packet.lat = lat;
    packet.alt = alt;
    packet.head = head;
    packet.head_rtk = head_rtk;
    packet.vel_ne = vel_ne;
    packet.vel_d = vel_d;
    packet.dev_id = dev_id;
    packet.fix_type = fix_type;
    packet.carr_sol = carr_sol;
    packet.rtk_head_valid = rtk_head_valid;
    packet.sv_num = sv_num;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA, (const char *)&packet, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_MIN_LEN, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_LEN, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_CRC);
#endif
}

/**
 * @brief Send a lisum_gnss_recv_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_lisum_gnss_recv_data_send_struct(mavlink_channel_t chan, const mavlink_lisum_gnss_recv_data_t* lisum_gnss_recv_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_lisum_gnss_recv_data_send(chan, lisum_gnss_recv_data->dev_id, lisum_gnss_recv_data->lon, lisum_gnss_recv_data->lat, lisum_gnss_recv_data->alt, lisum_gnss_recv_data->head, lisum_gnss_recv_data->head_rtk, lisum_gnss_recv_data->vel_ne, lisum_gnss_recv_data->vel_d, lisum_gnss_recv_data->fix_type, lisum_gnss_recv_data->carr_sol, lisum_gnss_recv_data->rtk_head_valid, lisum_gnss_recv_data->sv_num);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA, (const char *)lisum_gnss_recv_data, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_MIN_LEN, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_LEN, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_CRC);
#endif
}

#if MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_lisum_gnss_recv_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t dev_id, double lon, double lat, float alt, float head, float head_rtk, float vel_ne, float vel_d, uint8_t fix_type, uint8_t carr_sol, uint8_t rtk_head_valid, uint8_t sv_num)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_double(buf, 0, lon);
    _mav_put_double(buf, 8, lat);
    _mav_put_float(buf, 16, alt);
    _mav_put_float(buf, 20, head);
    _mav_put_float(buf, 24, head_rtk);
    _mav_put_float(buf, 28, vel_ne);
    _mav_put_float(buf, 32, vel_d);
    _mav_put_uint8_t(buf, 36, dev_id);
    _mav_put_uint8_t(buf, 37, fix_type);
    _mav_put_uint8_t(buf, 38, carr_sol);
    _mav_put_uint8_t(buf, 39, rtk_head_valid);
    _mav_put_uint8_t(buf, 40, sv_num);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA, buf, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_MIN_LEN, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_LEN, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_CRC);
#else
    mavlink_lisum_gnss_recv_data_t *packet = (mavlink_lisum_gnss_recv_data_t *)msgbuf;
    packet->lon = lon;
    packet->lat = lat;
    packet->alt = alt;
    packet->head = head;
    packet->head_rtk = head_rtk;
    packet->vel_ne = vel_ne;
    packet->vel_d = vel_d;
    packet->dev_id = dev_id;
    packet->fix_type = fix_type;
    packet->carr_sol = carr_sol;
    packet->rtk_head_valid = rtk_head_valid;
    packet->sv_num = sv_num;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA, (const char *)packet, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_MIN_LEN, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_LEN, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_CRC);
#endif
}
#endif

#endif

// MESSAGE LISUM_GNSS_RECV_DATA UNPACKING


/**
 * @brief Get field dev_id from lisum_gnss_recv_data message
 *
 * @return  Index of receiver
 */
static inline uint8_t mavlink_msg_lisum_gnss_recv_data_get_dev_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  36);
}

/**
 * @brief Get field lon from lisum_gnss_recv_data message
 *
 * @return [deg] Longitude
 */
static inline double mavlink_msg_lisum_gnss_recv_data_get_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_double(msg,  0);
}

/**
 * @brief Get field lat from lisum_gnss_recv_data message
 *
 * @return [deg] Latitude
 */
static inline double mavlink_msg_lisum_gnss_recv_data_get_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_double(msg,  8);
}

/**
 * @brief Get field alt from lisum_gnss_recv_data message
 *
 * @return [m] Altitude
 */
static inline float mavlink_msg_lisum_gnss_recv_data_get_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field head from lisum_gnss_recv_data message
 *
 * @return [deg] Heading
 */
static inline float mavlink_msg_lisum_gnss_recv_data_get_head(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field head_rtk from lisum_gnss_recv_data message
 *
 * @return [deg] RTK Heading
 */
static inline float mavlink_msg_lisum_gnss_recv_data_get_head_rtk(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field vel_ne from lisum_gnss_recv_data message
 *
 * @return [m/s] Planar velocity
 */
static inline float mavlink_msg_lisum_gnss_recv_data_get_vel_ne(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field vel_d from lisum_gnss_recv_data message
 *
 * @return [m/s] Vertical velocity
 */
static inline float mavlink_msg_lisum_gnss_recv_data_get_vel_d(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field fix_type from lisum_gnss_recv_data message
 *
 * @return  Fix Type Flag
 */
static inline uint8_t mavlink_msg_lisum_gnss_recv_data_get_fix_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  37);
}

/**
 * @brief Get field carr_sol from lisum_gnss_recv_data message
 *
 * @return  Carrier phase solution type
 */
static inline uint8_t mavlink_msg_lisum_gnss_recv_data_get_carr_sol(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  38);
}

/**
 * @brief Get field rtk_head_valid from lisum_gnss_recv_data message
 *
 * @return  RTK heading validity flag
 */
static inline uint8_t mavlink_msg_lisum_gnss_recv_data_get_rtk_head_valid(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  39);
}

/**
 * @brief Get field sv_num from lisum_gnss_recv_data message
 *
 * @return  Number of satellites
 */
static inline uint8_t mavlink_msg_lisum_gnss_recv_data_get_sv_num(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  40);
}

/**
 * @brief Decode a lisum_gnss_recv_data message into a struct
 *
 * @param msg The message to decode
 * @param lisum_gnss_recv_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_lisum_gnss_recv_data_decode(const mavlink_message_t* msg, mavlink_lisum_gnss_recv_data_t* lisum_gnss_recv_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    lisum_gnss_recv_data->lon = mavlink_msg_lisum_gnss_recv_data_get_lon(msg);
    lisum_gnss_recv_data->lat = mavlink_msg_lisum_gnss_recv_data_get_lat(msg);
    lisum_gnss_recv_data->alt = mavlink_msg_lisum_gnss_recv_data_get_alt(msg);
    lisum_gnss_recv_data->head = mavlink_msg_lisum_gnss_recv_data_get_head(msg);
    lisum_gnss_recv_data->head_rtk = mavlink_msg_lisum_gnss_recv_data_get_head_rtk(msg);
    lisum_gnss_recv_data->vel_ne = mavlink_msg_lisum_gnss_recv_data_get_vel_ne(msg);
    lisum_gnss_recv_data->vel_d = mavlink_msg_lisum_gnss_recv_data_get_vel_d(msg);
    lisum_gnss_recv_data->dev_id = mavlink_msg_lisum_gnss_recv_data_get_dev_id(msg);
    lisum_gnss_recv_data->fix_type = mavlink_msg_lisum_gnss_recv_data_get_fix_type(msg);
    lisum_gnss_recv_data->carr_sol = mavlink_msg_lisum_gnss_recv_data_get_carr_sol(msg);
    lisum_gnss_recv_data->rtk_head_valid = mavlink_msg_lisum_gnss_recv_data_get_rtk_head_valid(msg);
    lisum_gnss_recv_data->sv_num = mavlink_msg_lisum_gnss_recv_data_get_sv_num(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_LEN? msg->len : MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_LEN;
        memset(lisum_gnss_recv_data, 0, MAVLINK_MSG_ID_LISUM_GNSS_RECV_DATA_LEN);
    memcpy(lisum_gnss_recv_data, _MAV_PAYLOAD(msg), len);
#endif
}
