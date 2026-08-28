/**
 * @file    ulog_raw_imu.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_raw_imu.h"
#include "ulog_def.h"

const char ulog_raw_imu_format[] = "raw_imu:uint64_t timestamp;uint64_t time_usec;int16_t xacc;int16_t yacc;int16_t zacc;int16_t xgyro;int16_t ygyro;int16_t zgyro;int16_t xmag;int16_t ymag;int16_t zmag;uint8_t id;int16_t temperature;";
const char ulog_raw_imu_name[] = "raw_imu";

int32_t ulog_format_raw_imu(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_raw_imu_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_raw_imu_format, sizeof(ulog_raw_imu_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_raw_imu(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_raw_imu_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_raw_imu_name, sizeof(ulog_raw_imu_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_raw_imu(ulog_t *log, ulog_msg_id_t id, const ulog_raw_imu_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint64_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(uint8_t)
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

    /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->time_usec, sizeof(src->time_usec)) < 0) {
        return 1;
    }

    /* X acceleration (raw) */
    if (lfs_file_write(log->lfs, log->file, &src->xacc, sizeof(src->xacc)) < 0) {
        return 1;
    }

    /* Y acceleration (raw) */
    if (lfs_file_write(log->lfs, log->file, &src->yacc, sizeof(src->yacc)) < 0) {
        return 1;
    }

    /* Z acceleration (raw) */
    if (lfs_file_write(log->lfs, log->file, &src->zacc, sizeof(src->zacc)) < 0) {
        return 1;
    }

    /* Angular speed around X axis (raw) */
    if (lfs_file_write(log->lfs, log->file, &src->xgyro, sizeof(src->xgyro)) < 0) {
        return 1;
    }

    /* Angular speed around Y axis (raw) */
    if (lfs_file_write(log->lfs, log->file, &src->ygyro, sizeof(src->ygyro)) < 0) {
        return 1;
    }

    /* Angular speed around Z axis (raw) */
    if (lfs_file_write(log->lfs, log->file, &src->zgyro, sizeof(src->zgyro)) < 0) {
        return 1;
    }

    /* X Magnetic field (raw) */
    if (lfs_file_write(log->lfs, log->file, &src->xmag, sizeof(src->xmag)) < 0) {
        return 1;
    }

    /* Y Magnetic field (raw) */
    if (lfs_file_write(log->lfs, log->file, &src->ymag, sizeof(src->ymag)) < 0) {
        return 1;
    }

    /* Z Magnetic field (raw) */
    if (lfs_file_write(log->lfs, log->file, &src->zmag, sizeof(src->zmag)) < 0) {
        return 1;
    }

    /* Id. Ids are numbered from 0 and map to IMUs numbered from 1 (e.g. IMU1 will have a message with id=0) */
    if (lfs_file_write(log->lfs, log->file, &src->id, sizeof(src->id)) < 0) {
        return 1;
    }

    /* Temperature, 0: IMU does not provide temperature values. If the IMU is at 0C it must send 1 (0.01C). [cdegC] */
    if (lfs_file_write(log->lfs, log->file, &src->temperature, sizeof(src->temperature)) < 0) {
        return 1;
    }

    
    return 0;
}
