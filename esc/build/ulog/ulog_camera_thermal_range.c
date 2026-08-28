/**
 * @file    ulog_camera_thermal_range.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_camera_thermal_range.h"
#include "ulog_def.h"

const char ulog_camera_thermal_range_format[] = "camera_thermal_range:uint64_t timestamp;uint32_t time_boot_ms;uint8_t stream_id;uint8_t camera_device_id;float max;float max_point_x;float max_point_y;float min;float min_point_x;float min_point_y;";
const char ulog_camera_thermal_range_name[] = "camera_thermal_range";

int32_t ulog_format_camera_thermal_range(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_camera_thermal_range_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_camera_thermal_range_format, sizeof(ulog_camera_thermal_range_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_camera_thermal_range(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_camera_thermal_range_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_camera_thermal_range_name, sizeof(ulog_camera_thermal_range_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_camera_thermal_range(ulog_t *log, ulog_msg_id_t id, const ulog_camera_thermal_range_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
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

    /* Timestamp (time since system boot). [ms] */
    if (lfs_file_write(log->lfs, log->file, &src->time_boot_ms, sizeof(src->time_boot_ms)) < 0) {
        return 1;
    }

    /* Video Stream ID (1 for first, 2 for second, etc.) */
    if (lfs_file_write(log->lfs, log->file, &src->stream_id, sizeof(src->stream_id)) < 0) {
        return 1;
    }

    /* Camera id of a non-MAVLink camera attached to an autopilot (1-6).  0 if the component is a MAVLink camera (with its own component id). */
    if (lfs_file_write(log->lfs, log->file, &src->camera_device_id, sizeof(src->camera_device_id)) < 0) {
        return 1;
    }

    /* Temperature max. [degC] */
    if (lfs_file_write(log->lfs, log->file, &src->max, sizeof(src->max)) < 0) {
        return 1;
    }

    /* Temperature max point x value (normalized 0..1, 0 is left, 1 is right), NAN if unknown. */
    if (lfs_file_write(log->lfs, log->file, &src->max_point_x, sizeof(src->max_point_x)) < 0) {
        return 1;
    }

    /* Temperature max point y value (normalized 0..1, 0 is top, 1 is bottom), NAN if unknown. */
    if (lfs_file_write(log->lfs, log->file, &src->max_point_y, sizeof(src->max_point_y)) < 0) {
        return 1;
    }

    /* Temperature min. [degC] */
    if (lfs_file_write(log->lfs, log->file, &src->min, sizeof(src->min)) < 0) {
        return 1;
    }

    /* Temperature min point x value (normalized 0..1, 0 is left, 1 is right), NAN if unknown. */
    if (lfs_file_write(log->lfs, log->file, &src->min_point_x, sizeof(src->min_point_x)) < 0) {
        return 1;
    }

    /* Temperature min point y value (normalized 0..1, 0 is top, 1 is bottom), NAN if unknown. */
    if (lfs_file_write(log->lfs, log->file, &src->min_point_y, sizeof(src->min_point_y)) < 0) {
        return 1;
    }

    
    return 0;
}
