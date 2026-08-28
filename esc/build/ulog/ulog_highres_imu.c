/**
 * @file    ulog_highres_imu.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_highres_imu.h"
#include "ulog_def.h"

const char ulog_highres_imu_format[] = "highres_imu:uint64_t timestamp;uint64_t time_usec;float xacc;float yacc;float zacc;float xgyro;float ygyro;float zgyro;float xmag;float ymag;float zmag;float abs_pressure;float diff_pressure;float pressure_alt;float temperature;uint16_t fields_updated;uint8_t id;";
const char ulog_highres_imu_name[] = "highres_imu";

int32_t ulog_format_highres_imu(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_highres_imu_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_highres_imu_format, sizeof(ulog_highres_imu_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_highres_imu(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_highres_imu_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_highres_imu_name, sizeof(ulog_highres_imu_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_highres_imu(ulog_t *log, ulog_msg_id_t id, const ulog_highres_imu_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint64_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(uint16_t)
                    + sizeof(uint8_t)
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

    /* X acceleration [m/s/s] */
    if (lfs_file_write(log->lfs, log->file, &src->xacc, sizeof(src->xacc)) < 0) {
        return 1;
    }

    /* Y acceleration [m/s/s] */
    if (lfs_file_write(log->lfs, log->file, &src->yacc, sizeof(src->yacc)) < 0) {
        return 1;
    }

    /* Z acceleration [m/s/s] */
    if (lfs_file_write(log->lfs, log->file, &src->zacc, sizeof(src->zacc)) < 0) {
        return 1;
    }

    /* Angular speed around X axis [rad/s] */
    if (lfs_file_write(log->lfs, log->file, &src->xgyro, sizeof(src->xgyro)) < 0) {
        return 1;
    }

    /* Angular speed around Y axis [rad/s] */
    if (lfs_file_write(log->lfs, log->file, &src->ygyro, sizeof(src->ygyro)) < 0) {
        return 1;
    }

    /* Angular speed around Z axis [rad/s] */
    if (lfs_file_write(log->lfs, log->file, &src->zgyro, sizeof(src->zgyro)) < 0) {
        return 1;
    }

    /* X Magnetic field [gauss] */
    if (lfs_file_write(log->lfs, log->file, &src->xmag, sizeof(src->xmag)) < 0) {
        return 1;
    }

    /* Y Magnetic field [gauss] */
    if (lfs_file_write(log->lfs, log->file, &src->ymag, sizeof(src->ymag)) < 0) {
        return 1;
    }

    /* Z Magnetic field [gauss] */
    if (lfs_file_write(log->lfs, log->file, &src->zmag, sizeof(src->zmag)) < 0) {
        return 1;
    }

    /* Absolute pressure [hPa] */
    if (lfs_file_write(log->lfs, log->file, &src->abs_pressure, sizeof(src->abs_pressure)) < 0) {
        return 1;
    }

    /* Differential pressure [hPa] */
    if (lfs_file_write(log->lfs, log->file, &src->diff_pressure, sizeof(src->diff_pressure)) < 0) {
        return 1;
    }

    /* Altitude calculated from pressure */
    if (lfs_file_write(log->lfs, log->file, &src->pressure_alt, sizeof(src->pressure_alt)) < 0) {
        return 1;
    }

    /* Temperature [degC] */
    if (lfs_file_write(log->lfs, log->file, &src->temperature, sizeof(src->temperature)) < 0) {
        return 1;
    }

    /* Bitmap for fields that have updated since last message */
    if (lfs_file_write(log->lfs, log->file, &src->fields_updated, sizeof(src->fields_updated)) < 0) {
        return 1;
    }

    /* Id. Ids are numbered from 0 and map to IMUs numbered from 1 (e.g. IMU1 will have a message with id=0) */
    if (lfs_file_write(log->lfs, log->file, &src->id, sizeof(src->id)) < 0) {
        return 1;
    }

    
    return 0;
}
