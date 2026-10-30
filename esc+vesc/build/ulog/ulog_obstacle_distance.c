/**
 * @file    ulog_obstacle_distance.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_obstacle_distance.h"
#include "ulog_def.h"

const char ulog_obstacle_distance_format[] = "obstacle_distance:uint64_t timestamp;uint64_t time_usec;uint8_t sensor_type;uint16_t[72] distances;uint8_t increment;uint16_t min_distance;uint16_t max_distance;float increment_f;float angle_offset;uint8_t frame;";
const char ulog_obstacle_distance_name[] = "obstacle_distance";

int32_t ulog_format_obstacle_distance(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_obstacle_distance_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_obstacle_distance_format, sizeof(ulog_obstacle_distance_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_obstacle_distance(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_obstacle_distance_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_obstacle_distance_name, sizeof(ulog_obstacle_distance_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_obstacle_distance(ulog_t *log, ulog_msg_id_t id, const ulog_obstacle_distance_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint16_t)*72
                    + sizeof(uint8_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(float)
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

    /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->time_usec, sizeof(src->time_usec)) < 0) {
        return 1;
    }

    /* Class id of the distance sensor type. */
    if (lfs_file_write(log->lfs, log->file, &src->sensor_type, sizeof(src->sensor_type)) < 0) {
        return 1;
    }

    /* Distance of obstacles around the vehicle with index 0 corresponding to north + angle_offset, unless otherwise specified in the frame. A value of 0 is valid and means that the obstacle is practically touching the sensor. A value of max_distance +1 means no obstacle is present. A value of UINT16_MAX for unknown/not used. In a array element, one unit corresponds to 1cm. [cm] */
    if (lfs_file_write(log->lfs, log->file, src->distances, sizeof(src->distances)) < 0) {
        return 1;
    }

    /* Angular width in degrees of each array element. Increment direction is clockwise. This field is ignored if increment_f is non-zero. [deg] */
    if (lfs_file_write(log->lfs, log->file, &src->increment, sizeof(src->increment)) < 0) {
        return 1;
    }

    /* Minimum distance the sensor can measure. [cm] */
    if (lfs_file_write(log->lfs, log->file, &src->min_distance, sizeof(src->min_distance)) < 0) {
        return 1;
    }

    /* Maximum distance the sensor can measure. [cm] */
    if (lfs_file_write(log->lfs, log->file, &src->max_distance, sizeof(src->max_distance)) < 0) {
        return 1;
    }

    /* Angular width in degrees of each array element as a float. If non-zero then this value is used instead of the uint8_t increment field. Positive is clockwise direction, negative is counter-clockwise. [deg] */
    if (lfs_file_write(log->lfs, log->file, &src->increment_f, sizeof(src->increment_f)) < 0) {
        return 1;
    }

    /* Relative angle offset of the 0-index element in the distances array. Value of 0 corresponds to forward. Positive is clockwise direction, negative is counter-clockwise. [deg] */
    if (lfs_file_write(log->lfs, log->file, &src->angle_offset, sizeof(src->angle_offset)) < 0) {
        return 1;
    }

    /* Coordinate frame of reference for the yaw rotation and offset of the sensor data. Defaults to MAV_FRAME_GLOBAL, which is north aligned. For body-mounted sensors use MAV_FRAME_BODY_FRD, which is vehicle front aligned. */
    if (lfs_file_write(log->lfs, log->file, &src->frame, sizeof(src->frame)) < 0) {
        return 1;
    }

    
    return 0;
}
