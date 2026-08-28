/**
 * @file    ulog_lisum_sensor_airspeed_data.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_lisum_sensor_airspeed_data.h"
#include "ulog_def.h"

const char ulog_lisum_sensor_airspeed_data_format[] = "lisum_sensor_airspeed_data:uint64_t timestamp;uint8_t id;float airspeed;int16_t temperature;float raw_press;uint8_t flags;";
const char ulog_lisum_sensor_airspeed_data_name[] = "lisum_sensor_airspeed_data";

int32_t ulog_format_lisum_sensor_airspeed_data(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_lisum_sensor_airspeed_data_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_lisum_sensor_airspeed_data_format, sizeof(ulog_lisum_sensor_airspeed_data_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_lisum_sensor_airspeed_data(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_lisum_sensor_airspeed_data_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_lisum_sensor_airspeed_data_name, sizeof(ulog_lisum_sensor_airspeed_data_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_lisum_sensor_airspeed_data(ulog_t *log, ulog_msg_id_t id, const ulog_lisum_sensor_airspeed_data_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(float)
                    + sizeof(int16_t)
                    + sizeof(float)
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

    /* Sensor ID. */
    if (lfs_file_write(log->lfs, log->file, &src->id, sizeof(src->id)) < 0) {
        return 1;
    }

    /* Calibrated airspeed (CAS). [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->airspeed, sizeof(src->airspeed)) < 0) {
        return 1;
    }

    /* Temperature. INT16_MAX for value unknown/not supplied. [cdegC] */
    if (lfs_file_write(log->lfs, log->file, &src->temperature, sizeof(src->temperature)) < 0) {
        return 1;
    }

    /* Raw differential pressure. NaN for value unknown/not supplied. [hPa] */
    if (lfs_file_write(log->lfs, log->file, &src->raw_press, sizeof(src->raw_press)) < 0) {
        return 1;
    }

    /* Airspeed sensor flags. */
    if (lfs_file_write(log->lfs, log->file, &src->flags, sizeof(src->flags)) < 0) {
        return 1;
    }

    
    return 0;
}
