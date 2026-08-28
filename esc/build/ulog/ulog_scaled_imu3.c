/**
 * @file    ulog_scaled_imu3.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_scaled_imu3.h"
#include "ulog_def.h"

const char ulog_scaled_imu3_format[] = "scaled_imu3:uint64_t timestamp;uint32_t time_boot_ms;int16_t xacc;int16_t yacc;int16_t zacc;int16_t xgyro;int16_t ygyro;int16_t zgyro;int16_t xmag;int16_t ymag;int16_t zmag;int16_t temperature;";
const char ulog_scaled_imu3_name[] = "scaled_imu3";

int32_t ulog_format_scaled_imu3(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_scaled_imu3_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_scaled_imu3_format, sizeof(ulog_scaled_imu3_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_scaled_imu3(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_scaled_imu3_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_scaled_imu3_name, sizeof(ulog_scaled_imu3_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_scaled_imu3(ulog_t *log, ulog_msg_id_t id, const ulog_scaled_imu3_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
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

    /* Timestamp (time since system boot). [ms] */
    if (lfs_file_write(log->lfs, log->file, &src->time_boot_ms, sizeof(src->time_boot_ms)) < 0) {
        return 1;
    }

    /* X acceleration [mG] */
    if (lfs_file_write(log->lfs, log->file, &src->xacc, sizeof(src->xacc)) < 0) {
        return 1;
    }

    /* Y acceleration [mG] */
    if (lfs_file_write(log->lfs, log->file, &src->yacc, sizeof(src->yacc)) < 0) {
        return 1;
    }

    /* Z acceleration [mG] */
    if (lfs_file_write(log->lfs, log->file, &src->zacc, sizeof(src->zacc)) < 0) {
        return 1;
    }

    /* Angular speed around X axis [mrad/s] */
    if (lfs_file_write(log->lfs, log->file, &src->xgyro, sizeof(src->xgyro)) < 0) {
        return 1;
    }

    /* Angular speed around Y axis [mrad/s] */
    if (lfs_file_write(log->lfs, log->file, &src->ygyro, sizeof(src->ygyro)) < 0) {
        return 1;
    }

    /* Angular speed around Z axis [mrad/s] */
    if (lfs_file_write(log->lfs, log->file, &src->zgyro, sizeof(src->zgyro)) < 0) {
        return 1;
    }

    /* X Magnetic field [mgauss] */
    if (lfs_file_write(log->lfs, log->file, &src->xmag, sizeof(src->xmag)) < 0) {
        return 1;
    }

    /* Y Magnetic field [mgauss] */
    if (lfs_file_write(log->lfs, log->file, &src->ymag, sizeof(src->ymag)) < 0) {
        return 1;
    }

    /* Z Magnetic field [mgauss] */
    if (lfs_file_write(log->lfs, log->file, &src->zmag, sizeof(src->zmag)) < 0) {
        return 1;
    }

    /* Temperature, 0: IMU does not provide temperature values. If the IMU is at 0C it must send 1 (0.01C). [cdegC] */
    if (lfs_file_write(log->lfs, log->file, &src->temperature, sizeof(src->temperature)) < 0) {
        return 1;
    }

    
    return 0;
}
