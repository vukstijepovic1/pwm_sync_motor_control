#pragma once
// MESSAGE LISUM_ESC_STATUS PACKING

#define MAVLINK_MSG_ID_LISUM_ESC_STATUS 59520


typedef struct __mavlink_lisum_esc_status_t {
 float voltage[2]; /*< [V] Input voltage supplied to the ESC.*/
 float curr_motor[2]; /*< [A] Current drawn by the motor.*/
 float current[2]; /*< [A] Total current drawn from the battery.*/
 float temp_fet[2]; /*< [C] Temperature of the ESC FETs.*/
 float temp_motor[2]; /*< [C] Temperature of the motor.*/
 float rpm[2]; /*< [eRPM] Motor rotational speed in electrical RPM.*/
 float duty[2]; /*< [%] Duty cycle of the ESC output.*/
 float energy_consumed[2]; /*< [Wh] Energy consumed by the motor.*/
 float curr_consumed[2]; /*< [Ah] Total charge consumed by the motor.*/
 uint8_t index; /*<  Index of the first ESC in this message. minValue = 0, maxValue = 60, increment = 2.*/
} mavlink_lisum_esc_status_t;

#define MAVLINK_MSG_ID_LISUM_ESC_STATUS_LEN 73
#define MAVLINK_MSG_ID_LISUM_ESC_STATUS_MIN_LEN 73
#define MAVLINK_MSG_ID_59520_LEN 73
#define MAVLINK_MSG_ID_59520_MIN_LEN 73

#define MAVLINK_MSG_ID_LISUM_ESC_STATUS_CRC 44
#define MAVLINK_MSG_ID_59520_CRC 44

#define MAVLINK_MSG_LISUM_ESC_STATUS_FIELD_VOLTAGE_LEN 2
#define MAVLINK_MSG_LISUM_ESC_STATUS_FIELD_CURR_MOTOR_LEN 2
#define MAVLINK_MSG_LISUM_ESC_STATUS_FIELD_CURRENT_LEN 2
#define MAVLINK_MSG_LISUM_ESC_STATUS_FIELD_TEMP_FET_LEN 2
#define MAVLINK_MSG_LISUM_ESC_STATUS_FIELD_TEMP_MOTOR_LEN 2
#define MAVLINK_MSG_LISUM_ESC_STATUS_FIELD_RPM_LEN 2
#define MAVLINK_MSG_LISUM_ESC_STATUS_FIELD_DUTY_LEN 2
#define MAVLINK_MSG_LISUM_ESC_STATUS_FIELD_ENERGY_CONSUMED_LEN 2
#define MAVLINK_MSG_LISUM_ESC_STATUS_FIELD_CURR_CONSUMED_LEN 2

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_LISUM_ESC_STATUS { \
    59520, \
    "LISUM_ESC_STATUS", \
    10, \
    {  { "index", NULL, MAVLINK_TYPE_UINT8_T, 0, 72, offsetof(mavlink_lisum_esc_status_t, index) }, \
         { "voltage", NULL, MAVLINK_TYPE_FLOAT, 2, 0, offsetof(mavlink_lisum_esc_status_t, voltage) }, \
         { "curr_motor", NULL, MAVLINK_TYPE_FLOAT, 2, 8, offsetof(mavlink_lisum_esc_status_t, curr_motor) }, \
         { "current", NULL, MAVLINK_TYPE_FLOAT, 2, 16, offsetof(mavlink_lisum_esc_status_t, current) }, \
         { "temp_fet", NULL, MAVLINK_TYPE_FLOAT, 2, 24, offsetof(mavlink_lisum_esc_status_t, temp_fet) }, \
         { "temp_motor", NULL, MAVLINK_TYPE_FLOAT, 2, 32, offsetof(mavlink_lisum_esc_status_t, temp_motor) }, \
         { "rpm", NULL, MAVLINK_TYPE_FLOAT, 2, 40, offsetof(mavlink_lisum_esc_status_t, rpm) }, \
         { "duty", NULL, MAVLINK_TYPE_FLOAT, 2, 48, offsetof(mavlink_lisum_esc_status_t, duty) }, \
         { "energy_consumed", NULL, MAVLINK_TYPE_FLOAT, 2, 56, offsetof(mavlink_lisum_esc_status_t, energy_consumed) }, \
         { "curr_consumed", NULL, MAVLINK_TYPE_FLOAT, 2, 64, offsetof(mavlink_lisum_esc_status_t, curr_consumed) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_LISUM_ESC_STATUS { \
    "LISUM_ESC_STATUS", \
    10, \
    {  { "index", NULL, MAVLINK_TYPE_UINT8_T, 0, 72, offsetof(mavlink_lisum_esc_status_t, index) }, \
         { "voltage", NULL, MAVLINK_TYPE_FLOAT, 2, 0, offsetof(mavlink_lisum_esc_status_t, voltage) }, \
         { "curr_motor", NULL, MAVLINK_TYPE_FLOAT, 2, 8, offsetof(mavlink_lisum_esc_status_t, curr_motor) }, \
         { "current", NULL, MAVLINK_TYPE_FLOAT, 2, 16, offsetof(mavlink_lisum_esc_status_t, current) }, \
         { "temp_fet", NULL, MAVLINK_TYPE_FLOAT, 2, 24, offsetof(mavlink_lisum_esc_status_t, temp_fet) }, \
         { "temp_motor", NULL, MAVLINK_TYPE_FLOAT, 2, 32, offsetof(mavlink_lisum_esc_status_t, temp_motor) }, \
         { "rpm", NULL, MAVLINK_TYPE_FLOAT, 2, 40, offsetof(mavlink_lisum_esc_status_t, rpm) }, \
         { "duty", NULL, MAVLINK_TYPE_FLOAT, 2, 48, offsetof(mavlink_lisum_esc_status_t, duty) }, \
         { "energy_consumed", NULL, MAVLINK_TYPE_FLOAT, 2, 56, offsetof(mavlink_lisum_esc_status_t, energy_consumed) }, \
         { "curr_consumed", NULL, MAVLINK_TYPE_FLOAT, 2, 64, offsetof(mavlink_lisum_esc_status_t, curr_consumed) }, \
         } \
}
#endif

/**
 * @brief Pack a lisum_esc_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param index  Index of the first ESC in this message. minValue = 0, maxValue = 60, increment = 2.
 * @param voltage [V] Input voltage supplied to the ESC.
 * @param curr_motor [A] Current drawn by the motor.
 * @param current [A] Total current drawn from the battery.
 * @param temp_fet [C] Temperature of the ESC FETs.
 * @param temp_motor [C] Temperature of the motor.
 * @param rpm [eRPM] Motor rotational speed in electrical RPM.
 * @param duty [%] Duty cycle of the ESC output.
 * @param energy_consumed [Wh] Energy consumed by the motor.
 * @param curr_consumed [Ah] Total charge consumed by the motor.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_esc_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t index, const float *voltage, const float *curr_motor, const float *current, const float *temp_fet, const float *temp_motor, const float *rpm, const float *duty, const float *energy_consumed, const float *curr_consumed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_ESC_STATUS_LEN];
    _mav_put_uint8_t(buf, 72, index);
    _mav_put_float_array(buf, 0, voltage, 2);
    _mav_put_float_array(buf, 8, curr_motor, 2);
    _mav_put_float_array(buf, 16, current, 2);
    _mav_put_float_array(buf, 24, temp_fet, 2);
    _mav_put_float_array(buf, 32, temp_motor, 2);
    _mav_put_float_array(buf, 40, rpm, 2);
    _mav_put_float_array(buf, 48, duty, 2);
    _mav_put_float_array(buf, 56, energy_consumed, 2);
    _mav_put_float_array(buf, 64, curr_consumed, 2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_ESC_STATUS_LEN);
#else
    mavlink_lisum_esc_status_t packet;
    packet.index = index;
    mav_array_memcpy(packet.voltage, voltage, sizeof(float)*2);
    mav_array_memcpy(packet.curr_motor, curr_motor, sizeof(float)*2);
    mav_array_memcpy(packet.current, current, sizeof(float)*2);
    mav_array_memcpy(packet.temp_fet, temp_fet, sizeof(float)*2);
    mav_array_memcpy(packet.temp_motor, temp_motor, sizeof(float)*2);
    mav_array_memcpy(packet.rpm, rpm, sizeof(float)*2);
    mav_array_memcpy(packet.duty, duty, sizeof(float)*2);
    mav_array_memcpy(packet.energy_consumed, energy_consumed, sizeof(float)*2);
    mav_array_memcpy(packet.curr_consumed, curr_consumed, sizeof(float)*2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_ESC_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_ESC_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_LISUM_ESC_STATUS_MIN_LEN, MAVLINK_MSG_ID_LISUM_ESC_STATUS_LEN, MAVLINK_MSG_ID_LISUM_ESC_STATUS_CRC);
}

/**
 * @brief Pack a lisum_esc_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param index  Index of the first ESC in this message. minValue = 0, maxValue = 60, increment = 2.
 * @param voltage [V] Input voltage supplied to the ESC.
 * @param curr_motor [A] Current drawn by the motor.
 * @param current [A] Total current drawn from the battery.
 * @param temp_fet [C] Temperature of the ESC FETs.
 * @param temp_motor [C] Temperature of the motor.
 * @param rpm [eRPM] Motor rotational speed in electrical RPM.
 * @param duty [%] Duty cycle of the ESC output.
 * @param energy_consumed [Wh] Energy consumed by the motor.
 * @param curr_consumed [Ah] Total charge consumed by the motor.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_esc_status_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t index, const float *voltage, const float *curr_motor, const float *current, const float *temp_fet, const float *temp_motor, const float *rpm, const float *duty, const float *energy_consumed, const float *curr_consumed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_ESC_STATUS_LEN];
    _mav_put_uint8_t(buf, 72, index);
    _mav_put_float_array(buf, 0, voltage, 2);
    _mav_put_float_array(buf, 8, curr_motor, 2);
    _mav_put_float_array(buf, 16, current, 2);
    _mav_put_float_array(buf, 24, temp_fet, 2);
    _mav_put_float_array(buf, 32, temp_motor, 2);
    _mav_put_float_array(buf, 40, rpm, 2);
    _mav_put_float_array(buf, 48, duty, 2);
    _mav_put_float_array(buf, 56, energy_consumed, 2);
    _mav_put_float_array(buf, 64, curr_consumed, 2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_ESC_STATUS_LEN);
#else
    mavlink_lisum_esc_status_t packet;
    packet.index = index;
    mav_array_memcpy(packet.voltage, voltage, sizeof(float)*2);
    mav_array_memcpy(packet.curr_motor, curr_motor, sizeof(float)*2);
    mav_array_memcpy(packet.current, current, sizeof(float)*2);
    mav_array_memcpy(packet.temp_fet, temp_fet, sizeof(float)*2);
    mav_array_memcpy(packet.temp_motor, temp_motor, sizeof(float)*2);
    mav_array_memcpy(packet.rpm, rpm, sizeof(float)*2);
    mav_array_memcpy(packet.duty, duty, sizeof(float)*2);
    mav_array_memcpy(packet.energy_consumed, energy_consumed, sizeof(float)*2);
    mav_array_memcpy(packet.curr_consumed, curr_consumed, sizeof(float)*2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_ESC_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_ESC_STATUS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_LISUM_ESC_STATUS_MIN_LEN, MAVLINK_MSG_ID_LISUM_ESC_STATUS_LEN, MAVLINK_MSG_ID_LISUM_ESC_STATUS_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_LISUM_ESC_STATUS_MIN_LEN, MAVLINK_MSG_ID_LISUM_ESC_STATUS_LEN);
#endif
}

/**
 * @brief Pack a lisum_esc_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param index  Index of the first ESC in this message. minValue = 0, maxValue = 60, increment = 2.
 * @param voltage [V] Input voltage supplied to the ESC.
 * @param curr_motor [A] Current drawn by the motor.
 * @param current [A] Total current drawn from the battery.
 * @param temp_fet [C] Temperature of the ESC FETs.
 * @param temp_motor [C] Temperature of the motor.
 * @param rpm [eRPM] Motor rotational speed in electrical RPM.
 * @param duty [%] Duty cycle of the ESC output.
 * @param energy_consumed [Wh] Energy consumed by the motor.
 * @param curr_consumed [Ah] Total charge consumed by the motor.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_lisum_esc_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t index,const float *voltage,const float *curr_motor,const float *current,const float *temp_fet,const float *temp_motor,const float *rpm,const float *duty,const float *energy_consumed,const float *curr_consumed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_ESC_STATUS_LEN];
    _mav_put_uint8_t(buf, 72, index);
    _mav_put_float_array(buf, 0, voltage, 2);
    _mav_put_float_array(buf, 8, curr_motor, 2);
    _mav_put_float_array(buf, 16, current, 2);
    _mav_put_float_array(buf, 24, temp_fet, 2);
    _mav_put_float_array(buf, 32, temp_motor, 2);
    _mav_put_float_array(buf, 40, rpm, 2);
    _mav_put_float_array(buf, 48, duty, 2);
    _mav_put_float_array(buf, 56, energy_consumed, 2);
    _mav_put_float_array(buf, 64, curr_consumed, 2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LISUM_ESC_STATUS_LEN);
#else
    mavlink_lisum_esc_status_t packet;
    packet.index = index;
    mav_array_memcpy(packet.voltage, voltage, sizeof(float)*2);
    mav_array_memcpy(packet.curr_motor, curr_motor, sizeof(float)*2);
    mav_array_memcpy(packet.current, current, sizeof(float)*2);
    mav_array_memcpy(packet.temp_fet, temp_fet, sizeof(float)*2);
    mav_array_memcpy(packet.temp_motor, temp_motor, sizeof(float)*2);
    mav_array_memcpy(packet.rpm, rpm, sizeof(float)*2);
    mav_array_memcpy(packet.duty, duty, sizeof(float)*2);
    mav_array_memcpy(packet.energy_consumed, energy_consumed, sizeof(float)*2);
    mav_array_memcpy(packet.curr_consumed, curr_consumed, sizeof(float)*2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LISUM_ESC_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LISUM_ESC_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_LISUM_ESC_STATUS_MIN_LEN, MAVLINK_MSG_ID_LISUM_ESC_STATUS_LEN, MAVLINK_MSG_ID_LISUM_ESC_STATUS_CRC);
}

/**
 * @brief Encode a lisum_esc_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param lisum_esc_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_esc_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_lisum_esc_status_t* lisum_esc_status)
{
    return mavlink_msg_lisum_esc_status_pack(system_id, component_id, msg, lisum_esc_status->index, lisum_esc_status->voltage, lisum_esc_status->curr_motor, lisum_esc_status->current, lisum_esc_status->temp_fet, lisum_esc_status->temp_motor, lisum_esc_status->rpm, lisum_esc_status->duty, lisum_esc_status->energy_consumed, lisum_esc_status->curr_consumed);
}

/**
 * @brief Encode a lisum_esc_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param lisum_esc_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_esc_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_lisum_esc_status_t* lisum_esc_status)
{
    return mavlink_msg_lisum_esc_status_pack_chan(system_id, component_id, chan, msg, lisum_esc_status->index, lisum_esc_status->voltage, lisum_esc_status->curr_motor, lisum_esc_status->current, lisum_esc_status->temp_fet, lisum_esc_status->temp_motor, lisum_esc_status->rpm, lisum_esc_status->duty, lisum_esc_status->energy_consumed, lisum_esc_status->curr_consumed);
}

/**
 * @brief Encode a lisum_esc_status struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param lisum_esc_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_lisum_esc_status_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_lisum_esc_status_t* lisum_esc_status)
{
    return mavlink_msg_lisum_esc_status_pack_status(system_id, component_id, _status, msg,  lisum_esc_status->index, lisum_esc_status->voltage, lisum_esc_status->curr_motor, lisum_esc_status->current, lisum_esc_status->temp_fet, lisum_esc_status->temp_motor, lisum_esc_status->rpm, lisum_esc_status->duty, lisum_esc_status->energy_consumed, lisum_esc_status->curr_consumed);
}

/**
 * @brief Send a lisum_esc_status message
 * @param chan MAVLink channel to send the message
 *
 * @param index  Index of the first ESC in this message. minValue = 0, maxValue = 60, increment = 2.
 * @param voltage [V] Input voltage supplied to the ESC.
 * @param curr_motor [A] Current drawn by the motor.
 * @param current [A] Total current drawn from the battery.
 * @param temp_fet [C] Temperature of the ESC FETs.
 * @param temp_motor [C] Temperature of the motor.
 * @param rpm [eRPM] Motor rotational speed in electrical RPM.
 * @param duty [%] Duty cycle of the ESC output.
 * @param energy_consumed [Wh] Energy consumed by the motor.
 * @param curr_consumed [Ah] Total charge consumed by the motor.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_lisum_esc_status_send(mavlink_channel_t chan, uint8_t index, const float *voltage, const float *curr_motor, const float *current, const float *temp_fet, const float *temp_motor, const float *rpm, const float *duty, const float *energy_consumed, const float *curr_consumed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LISUM_ESC_STATUS_LEN];
    _mav_put_uint8_t(buf, 72, index);
    _mav_put_float_array(buf, 0, voltage, 2);
    _mav_put_float_array(buf, 8, curr_motor, 2);
    _mav_put_float_array(buf, 16, current, 2);
    _mav_put_float_array(buf, 24, temp_fet, 2);
    _mav_put_float_array(buf, 32, temp_motor, 2);
    _mav_put_float_array(buf, 40, rpm, 2);
    _mav_put_float_array(buf, 48, duty, 2);
    _mav_put_float_array(buf, 56, energy_consumed, 2);
    _mav_put_float_array(buf, 64, curr_consumed, 2);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_ESC_STATUS, buf, MAVLINK_MSG_ID_LISUM_ESC_STATUS_MIN_LEN, MAVLINK_MSG_ID_LISUM_ESC_STATUS_LEN, MAVLINK_MSG_ID_LISUM_ESC_STATUS_CRC);
#else
    mavlink_lisum_esc_status_t packet;
    packet.index = index;
    mav_array_memcpy(packet.voltage, voltage, sizeof(float)*2);
    mav_array_memcpy(packet.curr_motor, curr_motor, sizeof(float)*2);
    mav_array_memcpy(packet.current, current, sizeof(float)*2);
    mav_array_memcpy(packet.temp_fet, temp_fet, sizeof(float)*2);
    mav_array_memcpy(packet.temp_motor, temp_motor, sizeof(float)*2);
    mav_array_memcpy(packet.rpm, rpm, sizeof(float)*2);
    mav_array_memcpy(packet.duty, duty, sizeof(float)*2);
    mav_array_memcpy(packet.energy_consumed, energy_consumed, sizeof(float)*2);
    mav_array_memcpy(packet.curr_consumed, curr_consumed, sizeof(float)*2);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_ESC_STATUS, (const char *)&packet, MAVLINK_MSG_ID_LISUM_ESC_STATUS_MIN_LEN, MAVLINK_MSG_ID_LISUM_ESC_STATUS_LEN, MAVLINK_MSG_ID_LISUM_ESC_STATUS_CRC);
#endif
}

/**
 * @brief Send a lisum_esc_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_lisum_esc_status_send_struct(mavlink_channel_t chan, const mavlink_lisum_esc_status_t* lisum_esc_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_lisum_esc_status_send(chan, lisum_esc_status->index, lisum_esc_status->voltage, lisum_esc_status->curr_motor, lisum_esc_status->current, lisum_esc_status->temp_fet, lisum_esc_status->temp_motor, lisum_esc_status->rpm, lisum_esc_status->duty, lisum_esc_status->energy_consumed, lisum_esc_status->curr_consumed);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_ESC_STATUS, (const char *)lisum_esc_status, MAVLINK_MSG_ID_LISUM_ESC_STATUS_MIN_LEN, MAVLINK_MSG_ID_LISUM_ESC_STATUS_LEN, MAVLINK_MSG_ID_LISUM_ESC_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_LISUM_ESC_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_lisum_esc_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t index, const float *voltage, const float *curr_motor, const float *current, const float *temp_fet, const float *temp_motor, const float *rpm, const float *duty, const float *energy_consumed, const float *curr_consumed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 72, index);
    _mav_put_float_array(buf, 0, voltage, 2);
    _mav_put_float_array(buf, 8, curr_motor, 2);
    _mav_put_float_array(buf, 16, current, 2);
    _mav_put_float_array(buf, 24, temp_fet, 2);
    _mav_put_float_array(buf, 32, temp_motor, 2);
    _mav_put_float_array(buf, 40, rpm, 2);
    _mav_put_float_array(buf, 48, duty, 2);
    _mav_put_float_array(buf, 56, energy_consumed, 2);
    _mav_put_float_array(buf, 64, curr_consumed, 2);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_ESC_STATUS, buf, MAVLINK_MSG_ID_LISUM_ESC_STATUS_MIN_LEN, MAVLINK_MSG_ID_LISUM_ESC_STATUS_LEN, MAVLINK_MSG_ID_LISUM_ESC_STATUS_CRC);
#else
    mavlink_lisum_esc_status_t *packet = (mavlink_lisum_esc_status_t *)msgbuf;
    packet->index = index;
    mav_array_memcpy(packet->voltage, voltage, sizeof(float)*2);
    mav_array_memcpy(packet->curr_motor, curr_motor, sizeof(float)*2);
    mav_array_memcpy(packet->current, current, sizeof(float)*2);
    mav_array_memcpy(packet->temp_fet, temp_fet, sizeof(float)*2);
    mav_array_memcpy(packet->temp_motor, temp_motor, sizeof(float)*2);
    mav_array_memcpy(packet->rpm, rpm, sizeof(float)*2);
    mav_array_memcpy(packet->duty, duty, sizeof(float)*2);
    mav_array_memcpy(packet->energy_consumed, energy_consumed, sizeof(float)*2);
    mav_array_memcpy(packet->curr_consumed, curr_consumed, sizeof(float)*2);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LISUM_ESC_STATUS, (const char *)packet, MAVLINK_MSG_ID_LISUM_ESC_STATUS_MIN_LEN, MAVLINK_MSG_ID_LISUM_ESC_STATUS_LEN, MAVLINK_MSG_ID_LISUM_ESC_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE LISUM_ESC_STATUS UNPACKING


/**
 * @brief Get field index from lisum_esc_status message
 *
 * @return  Index of the first ESC in this message. minValue = 0, maxValue = 60, increment = 2.
 */
static inline uint8_t mavlink_msg_lisum_esc_status_get_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  72);
}

/**
 * @brief Get field voltage from lisum_esc_status message
 *
 * @return [V] Input voltage supplied to the ESC.
 */
static inline uint16_t mavlink_msg_lisum_esc_status_get_voltage(const mavlink_message_t* msg, float *voltage)
{
    return _MAV_RETURN_float_array(msg, voltage, 2,  0);
}

/**
 * @brief Get field curr_motor from lisum_esc_status message
 *
 * @return [A] Current drawn by the motor.
 */
static inline uint16_t mavlink_msg_lisum_esc_status_get_curr_motor(const mavlink_message_t* msg, float *curr_motor)
{
    return _MAV_RETURN_float_array(msg, curr_motor, 2,  8);
}

/**
 * @brief Get field current from lisum_esc_status message
 *
 * @return [A] Total current drawn from the battery.
 */
static inline uint16_t mavlink_msg_lisum_esc_status_get_current(const mavlink_message_t* msg, float *current)
{
    return _MAV_RETURN_float_array(msg, current, 2,  16);
}

/**
 * @brief Get field temp_fet from lisum_esc_status message
 *
 * @return [C] Temperature of the ESC FETs.
 */
static inline uint16_t mavlink_msg_lisum_esc_status_get_temp_fet(const mavlink_message_t* msg, float *temp_fet)
{
    return _MAV_RETURN_float_array(msg, temp_fet, 2,  24);
}

/**
 * @brief Get field temp_motor from lisum_esc_status message
 *
 * @return [C] Temperature of the motor.
 */
static inline uint16_t mavlink_msg_lisum_esc_status_get_temp_motor(const mavlink_message_t* msg, float *temp_motor)
{
    return _MAV_RETURN_float_array(msg, temp_motor, 2,  32);
}

/**
 * @brief Get field rpm from lisum_esc_status message
 *
 * @return [eRPM] Motor rotational speed in electrical RPM.
 */
static inline uint16_t mavlink_msg_lisum_esc_status_get_rpm(const mavlink_message_t* msg, float *rpm)
{
    return _MAV_RETURN_float_array(msg, rpm, 2,  40);
}

/**
 * @brief Get field duty from lisum_esc_status message
 *
 * @return [%] Duty cycle of the ESC output.
 */
static inline uint16_t mavlink_msg_lisum_esc_status_get_duty(const mavlink_message_t* msg, float *duty)
{
    return _MAV_RETURN_float_array(msg, duty, 2,  48);
}

/**
 * @brief Get field energy_consumed from lisum_esc_status message
 *
 * @return [Wh] Energy consumed by the motor.
 */
static inline uint16_t mavlink_msg_lisum_esc_status_get_energy_consumed(const mavlink_message_t* msg, float *energy_consumed)
{
    return _MAV_RETURN_float_array(msg, energy_consumed, 2,  56);
}

/**
 * @brief Get field curr_consumed from lisum_esc_status message
 *
 * @return [Ah] Total charge consumed by the motor.
 */
static inline uint16_t mavlink_msg_lisum_esc_status_get_curr_consumed(const mavlink_message_t* msg, float *curr_consumed)
{
    return _MAV_RETURN_float_array(msg, curr_consumed, 2,  64);
}

/**
 * @brief Decode a lisum_esc_status message into a struct
 *
 * @param msg The message to decode
 * @param lisum_esc_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_lisum_esc_status_decode(const mavlink_message_t* msg, mavlink_lisum_esc_status_t* lisum_esc_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_lisum_esc_status_get_voltage(msg, lisum_esc_status->voltage);
    mavlink_msg_lisum_esc_status_get_curr_motor(msg, lisum_esc_status->curr_motor);
    mavlink_msg_lisum_esc_status_get_current(msg, lisum_esc_status->current);
    mavlink_msg_lisum_esc_status_get_temp_fet(msg, lisum_esc_status->temp_fet);
    mavlink_msg_lisum_esc_status_get_temp_motor(msg, lisum_esc_status->temp_motor);
    mavlink_msg_lisum_esc_status_get_rpm(msg, lisum_esc_status->rpm);
    mavlink_msg_lisum_esc_status_get_duty(msg, lisum_esc_status->duty);
    mavlink_msg_lisum_esc_status_get_energy_consumed(msg, lisum_esc_status->energy_consumed);
    mavlink_msg_lisum_esc_status_get_curr_consumed(msg, lisum_esc_status->curr_consumed);
    lisum_esc_status->index = mavlink_msg_lisum_esc_status_get_index(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_LISUM_ESC_STATUS_LEN? msg->len : MAVLINK_MSG_ID_LISUM_ESC_STATUS_LEN;
        memset(lisum_esc_status, 0, MAVLINK_MSG_ID_LISUM_ESC_STATUS_LEN);
    memcpy(lisum_esc_status, _MAV_PAYLOAD(msg), len);
#endif
}
