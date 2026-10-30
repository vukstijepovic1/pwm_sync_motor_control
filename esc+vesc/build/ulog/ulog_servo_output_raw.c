/**
 * @file    ulog_servo_output_raw.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_servo_output_raw.h"
#include "ulog_def.h"

const char ulog_servo_output_raw_format[] = "servo_output_raw:uint64_t timestamp;uint32_t time_usec;uint8_t port;uint16_t servo1_raw;uint16_t servo2_raw;uint16_t servo3_raw;uint16_t servo4_raw;uint16_t servo5_raw;uint16_t servo6_raw;uint16_t servo7_raw;uint16_t servo8_raw;uint16_t servo9_raw;uint16_t servo10_raw;uint16_t servo11_raw;uint16_t servo12_raw;uint16_t servo13_raw;uint16_t servo14_raw;uint16_t servo15_raw;uint16_t servo16_raw;";
const char ulog_servo_output_raw_name[] = "servo_output_raw";

int32_t ulog_format_servo_output_raw(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_servo_output_raw_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_servo_output_raw_format, sizeof(ulog_servo_output_raw_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_servo_output_raw(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_servo_output_raw_name) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_SUBSCRIPTION,
    };

    if(log->state == ULOG_STATE_DEFINITIONS_CREATED)
        log->state = ULOG_STATE_WRITING_DATA;

    if(log->state != ULOG_STATE_WRITING_DATA)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, &multi_id, sizeof(multi_id)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, &log->msg_cnt, sizeof(log->msg_cnt)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_servo_output_raw_name, sizeof(ulog_servo_output_raw_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_servo_output_raw(ulog_t *log, ulog_msg_id_t id, const ulog_servo_output_raw_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
                    + sizeof(uint8_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    ,
        .msg_type = ULOG_DEF_MSG_TYPE_LOGGED_DATA,
    };

    if(log->state != ULOG_STATE_WRITING_DATA || id >= log->msg_cnt) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, &id, sizeof(id)) < 0) {
        return 1;
    }

    /* Timestamp [us] */
    if (lfs_file_write(log->lfs, log->file, &src->timestamp, sizeof(src->timestamp)) < 0) {
        return 1;
    }

    /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->time_usec, sizeof(src->time_usec)) < 0) {
        return 1;
    }

    /* Servo output port (set of 8 outputs = 1 port). Flight stacks running on Pixhawk should use: 0 = MAIN, 1 = AUX. */
    if (lfs_file_write(log->lfs, log->file, &src->port, sizeof(src->port)) < 0) {
        return 1;
    }

    /* Servo output 1 value [us] */
    if (lfs_file_write(log->lfs, log->file, &src->servo1_raw, sizeof(src->servo1_raw)) < 0) {
        return 1;
    }

    /* Servo output 2 value [us] */
    if (lfs_file_write(log->lfs, log->file, &src->servo2_raw, sizeof(src->servo2_raw)) < 0) {
        return 1;
    }

    /* Servo output 3 value [us] */
    if (lfs_file_write(log->lfs, log->file, &src->servo3_raw, sizeof(src->servo3_raw)) < 0) {
        return 1;
    }

    /* Servo output 4 value [us] */
    if (lfs_file_write(log->lfs, log->file, &src->servo4_raw, sizeof(src->servo4_raw)) < 0) {
        return 1;
    }

    /* Servo output 5 value [us] */
    if (lfs_file_write(log->lfs, log->file, &src->servo5_raw, sizeof(src->servo5_raw)) < 0) {
        return 1;
    }

    /* Servo output 6 value [us] */
    if (lfs_file_write(log->lfs, log->file, &src->servo6_raw, sizeof(src->servo6_raw)) < 0) {
        return 1;
    }

    /* Servo output 7 value [us] */
    if (lfs_file_write(log->lfs, log->file, &src->servo7_raw, sizeof(src->servo7_raw)) < 0) {
        return 1;
    }

    /* Servo output 8 value [us] */
    if (lfs_file_write(log->lfs, log->file, &src->servo8_raw, sizeof(src->servo8_raw)) < 0) {
        return 1;
    }

    /* Servo output 9 value [us] */
    if (lfs_file_write(log->lfs, log->file, &src->servo9_raw, sizeof(src->servo9_raw)) < 0) {
        return 1;
    }

    /* Servo output 10 value [us] */
    if (lfs_file_write(log->lfs, log->file, &src->servo10_raw, sizeof(src->servo10_raw)) < 0) {
        return 1;
    }

    /* Servo output 11 value [us] */
    if (lfs_file_write(log->lfs, log->file, &src->servo11_raw, sizeof(src->servo11_raw)) < 0) {
        return 1;
    }

    /* Servo output 12 value [us] */
    if (lfs_file_write(log->lfs, log->file, &src->servo12_raw, sizeof(src->servo12_raw)) < 0) {
        return 1;
    }

    /* Servo output 13 value [us] */
    if (lfs_file_write(log->lfs, log->file, &src->servo13_raw, sizeof(src->servo13_raw)) < 0) {
        return 1;
    }

    /* Servo output 14 value [us] */
    if (lfs_file_write(log->lfs, log->file, &src->servo14_raw, sizeof(src->servo14_raw)) < 0) {
        return 1;
    }

    /* Servo output 15 value [us] */
    if (lfs_file_write(log->lfs, log->file, &src->servo15_raw, sizeof(src->servo15_raw)) < 0) {
        return 1;
    }

    /* Servo output 16 value [us] */
    if (lfs_file_write(log->lfs, log->file, &src->servo16_raw, sizeof(src->servo16_raw)) < 0) {
        return 1;
    }

    
    return 0;
}
