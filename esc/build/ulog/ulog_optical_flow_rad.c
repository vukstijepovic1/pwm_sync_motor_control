/**
 * @file    ulog_optical_flow_rad.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_optical_flow_rad.h"
#include "ulog_def.h"

const char ulog_optical_flow_rad_format[] = "optical_flow_rad:uint64_t timestamp;uint64_t time_usec;uint8_t sensor_id;uint32_t integration_time_us;float integrated_x;float integrated_y;float integrated_xgyro;float integrated_ygyro;float integrated_zgyro;int16_t temperature;uint8_t quality;uint32_t time_delta_distance_us;float distance;";
const char ulog_optical_flow_rad_name[] = "optical_flow_rad";

int32_t ulog_format_optical_flow_rad(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_optical_flow_rad_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_optical_flow_rad_format, sizeof(ulog_optical_flow_rad_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_optical_flow_rad(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_optical_flow_rad_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_optical_flow_rad_name, sizeof(ulog_optical_flow_rad_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_optical_flow_rad(ulog_t *log, ulog_msg_id_t id, const ulog_optical_flow_rad_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint32_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(int16_t)
                    + sizeof(uint8_t)
                    + sizeof(uint32_t)
                    + sizeof(float)
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

    /* Sensor ID */
    if (lfs_file_write(log->lfs, log->file, &src->sensor_id, sizeof(src->sensor_id)) < 0) {
        return 1;
    }

    /* Integration time. Divide integrated_x and integrated_y by the integration time to obtain average flow. The integration time also indicates the. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->integration_time_us, sizeof(src->integration_time_us)) < 0) {
        return 1;
    }

    /* Flow around X axis (Sensor RH rotation about the X axis induces a positive flow. Sensor linear motion along the positive Y axis induces a negative flow.) [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->integrated_x, sizeof(src->integrated_x)) < 0) {
        return 1;
    }

    /* Flow around Y axis (Sensor RH rotation about the Y axis induces a positive flow. Sensor linear motion along the positive X axis induces a positive flow.) [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->integrated_y, sizeof(src->integrated_y)) < 0) {
        return 1;
    }

    /* RH rotation around X axis [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->integrated_xgyro, sizeof(src->integrated_xgyro)) < 0) {
        return 1;
    }

    /* RH rotation around Y axis [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->integrated_ygyro, sizeof(src->integrated_ygyro)) < 0) {
        return 1;
    }

    /* RH rotation around Z axis [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->integrated_zgyro, sizeof(src->integrated_zgyro)) < 0) {
        return 1;
    }

    /* Temperature [cdegC] */
    if (lfs_file_write(log->lfs, log->file, &src->temperature, sizeof(src->temperature)) < 0) {
        return 1;
    }

    /* Optical flow quality / confidence. 0: no valid flow, 255: maximum quality */
    if (lfs_file_write(log->lfs, log->file, &src->quality, sizeof(src->quality)) < 0) {
        return 1;
    }

    /* Time since the distance was sampled. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->time_delta_distance_us, sizeof(src->time_delta_distance_us)) < 0) {
        return 1;
    }

    /* Distance to the center of the flow field. Positive value (including zero): distance known. Negative value: Unknown distance. [m] */
    if (lfs_file_write(log->lfs, log->file, &src->distance, sizeof(src->distance)) < 0) {
        return 1;
    }

    
    return 0;
}
