/**
 * @file    ulog_servo_output_raw.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_SERVO_OUTPUT_RAW_H
#define ULOG_SERVO_OUTPUT_RAW_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_servo_output_raw_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint32_t time_usec; /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    uint8_t port; /* Servo output port (set of 8 outputs = 1 port). Flight stacks running on Pixhawk should use: 0 = MAIN, 1 = AUX. */
    uint16_t servo1_raw; /* Servo output 1 value [us] */
    uint16_t servo2_raw; /* Servo output 2 value [us] */
    uint16_t servo3_raw; /* Servo output 3 value [us] */
    uint16_t servo4_raw; /* Servo output 4 value [us] */
    uint16_t servo5_raw; /* Servo output 5 value [us] */
    uint16_t servo6_raw; /* Servo output 6 value [us] */
    uint16_t servo7_raw; /* Servo output 7 value [us] */
    uint16_t servo8_raw; /* Servo output 8 value [us] */
    uint16_t servo9_raw; /* Servo output 9 value [us] */
    uint16_t servo10_raw; /* Servo output 10 value [us] */
    uint16_t servo11_raw; /* Servo output 11 value [us] */
    uint16_t servo12_raw; /* Servo output 12 value [us] */
    uint16_t servo13_raw; /* Servo output 13 value [us] */
    uint16_t servo14_raw; /* Servo output 14 value [us] */
    uint16_t servo15_raw; /* Servo output 15 value [us] */
    uint16_t servo16_raw; /* Servo output 16 value [us] */
    
} ulog_servo_output_raw_t;

/**
 * Defines Servo Output Raw message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_servo_output_raw(ulog_t *log);

/**
 * Subscribe Servo Output Raw message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_servo_output_raw(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Servo Output Raw message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_servo_output_raw(ulog_t *log, ulog_msg_id_t id, const ulog_servo_output_raw_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_SERVO_OUTPUT_RAW_H */