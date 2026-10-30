/**
 * @file    ulog_distance_sensor.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_distance_sensor.h"
#include "ulog_def.h"

const char ulog_distance_sensor_format[] = "distance_sensor:uint64_t timestamp;uint32_t time_boot_ms;uint16_t min_distance;uint16_t max_distance;uint16_t current_distance;uint8_t type;uint8_t id;uint8_t orientation;uint8_t covariance;float horizontal_fov;float vertical_fov;float[4] quaternion;uint8_t signal_quality;";
const char ulog_distance_sensor_name[] = "distance_sensor";

int32_t ulog_format_distance_sensor(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_distance_sensor_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_distance_sensor_format, sizeof(ulog_distance_sensor_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_distance_sensor(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_distance_sensor_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_distance_sensor_name, sizeof(ulog_distance_sensor_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_distance_sensor(ulog_t *log, ulog_msg_id_t id, const ulog_distance_sensor_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)*4
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

    /* Timestamp (time since system boot). [ms] */
    if (lfs_file_write(log->lfs, log->file, &src->time_boot_ms, sizeof(src->time_boot_ms)) < 0) {
        return 1;
    }

    /* Minimum distance the sensor can measure [cm] */
    if (lfs_file_write(log->lfs, log->file, &src->min_distance, sizeof(src->min_distance)) < 0) {
        return 1;
    }

    /* Maximum distance the sensor can measure [cm] */
    if (lfs_file_write(log->lfs, log->file, &src->max_distance, sizeof(src->max_distance)) < 0) {
        return 1;
    }

    /* Current distance reading [cm] */
    if (lfs_file_write(log->lfs, log->file, &src->current_distance, sizeof(src->current_distance)) < 0) {
        return 1;
    }

    /* Type of distance sensor. */
    if (lfs_file_write(log->lfs, log->file, &src->type, sizeof(src->type)) < 0) {
        return 1;
    }

    /* Onboard ID of the sensor */
    if (lfs_file_write(log->lfs, log->file, &src->id, sizeof(src->id)) < 0) {
        return 1;
    }

    /* Direction the sensor faces. downward-facing: ROTATION_PITCH_270, upward-facing: ROTATION_PITCH_90, backward-facing: ROTATION_PITCH_180, forward-facing: ROTATION_NONE, left-facing: ROTATION_YAW_90, right-facing: ROTATION_YAW_270 */
    if (lfs_file_write(log->lfs, log->file, &src->orientation, sizeof(src->orientation)) < 0) {
        return 1;
    }

    /* Measurement variance. Max standard deviation is 6cm. UINT8_MAX if unknown. [cm^2] */
    if (lfs_file_write(log->lfs, log->file, &src->covariance, sizeof(src->covariance)) < 0) {
        return 1;
    }

    /* Horizontal Field of View (angle) where the distance measurement is valid and the field of view is known. Otherwise this is set to 0. [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->horizontal_fov, sizeof(src->horizontal_fov)) < 0) {
        return 1;
    }

    /* Vertical Field of View (angle) where the distance measurement is valid and the field of view is known. Otherwise this is set to 0. [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->vertical_fov, sizeof(src->vertical_fov)) < 0) {
        return 1;
    }

    /* Quaternion of the sensor orientation in vehicle body frame (w, x, y, z order, zero-rotation is 1, 0, 0, 0). Zero-rotation is along the vehicle body x-axis. This field is required if the orientation is set to MAV_SENSOR_ROTATION_CUSTOM. Set it to 0 if invalid." */
    if (lfs_file_write(log->lfs, log->file, src->quaternion, sizeof(src->quaternion)) < 0) {
        return 1;
    }

    /* Signal quality of the sensor. Specific to each sensor type, representing the relation of the signal strength with the target reflectivity, distance, size or aspect, but normalised as a percentage. 0 = unknown/unset signal quality, 1 = invalid signal, 100 = perfect signal. [%] */
    if (lfs_file_write(log->lfs, log->file, &src->signal_quality, sizeof(src->signal_quality)) < 0) {
        return 1;
    }

    
    return 0;
}
