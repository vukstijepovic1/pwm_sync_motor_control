/**
 * @file    ulog_optical_flow.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_optical_flow.h"
#include "ulog_def.h"

const char ulog_optical_flow_format[] = "optical_flow:uint64_t timestamp;uint64_t time_usec;uint8_t sensor_id;int16_t flow_x;int16_t flow_y;float flow_comp_m_x;float flow_comp_m_y;uint8_t quality;float ground_distance;float flow_rate_x;float flow_rate_y;";
const char ulog_optical_flow_name[] = "optical_flow";

int32_t ulog_format_optical_flow(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_optical_flow_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_optical_flow_format, sizeof(ulog_optical_flow_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_optical_flow(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_optical_flow_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_optical_flow_name, sizeof(ulog_optical_flow_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_optical_flow(ulog_t *log, ulog_msg_id_t id, const ulog_optical_flow_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(uint8_t)
                    + sizeof(float)
                    + sizeof(float)
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

    /* Flow in x-sensor direction [dpix] */
    if (lfs_file_write(log->lfs, log->file, &src->flow_x, sizeof(src->flow_x)) < 0) {
        return 1;
    }

    /* Flow in y-sensor direction [dpix] */
    if (lfs_file_write(log->lfs, log->file, &src->flow_y, sizeof(src->flow_y)) < 0) {
        return 1;
    }

    /* Flow in x-sensor direction, angular-speed compensated [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->flow_comp_m_x, sizeof(src->flow_comp_m_x)) < 0) {
        return 1;
    }

    /* Flow in y-sensor direction, angular-speed compensated [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->flow_comp_m_y, sizeof(src->flow_comp_m_y)) < 0) {
        return 1;
    }

    /* Optical flow quality / confidence. 0: bad, 255: maximum quality */
    if (lfs_file_write(log->lfs, log->file, &src->quality, sizeof(src->quality)) < 0) {
        return 1;
    }

    /* Ground distance. Positive value: distance known. Negative value: Unknown distance [m] */
    if (lfs_file_write(log->lfs, log->file, &src->ground_distance, sizeof(src->ground_distance)) < 0) {
        return 1;
    }

    /* Flow rate about X axis [rad/s] */
    if (lfs_file_write(log->lfs, log->file, &src->flow_rate_x, sizeof(src->flow_rate_x)) < 0) {
        return 1;
    }

    /* Flow rate about Y axis [rad/s] */
    if (lfs_file_write(log->lfs, log->file, &src->flow_rate_y, sizeof(src->flow_rate_y)) < 0) {
        return 1;
    }

    
    return 0;
}
