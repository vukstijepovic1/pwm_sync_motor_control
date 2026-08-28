/**
 * @file    ulog_camera_tracking_geo_status.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_camera_tracking_geo_status.h"
#include "ulog_def.h"

const char ulog_camera_tracking_geo_status_format[] = "camera_tracking_geo_status:uint64_t timestamp;uint8_t tracking_status;int32_t lat;int32_t lon;float alt;float h_acc;float v_acc;float vel_n;float vel_e;float vel_d;float vel_acc;float dist;float hdg;float hdg_acc;uint8_t camera_device_id;";
const char ulog_camera_tracking_geo_status_name[] = "camera_tracking_geo_status";

int32_t ulog_format_camera_tracking_geo_status(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_camera_tracking_geo_status_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_camera_tracking_geo_status_format, sizeof(ulog_camera_tracking_geo_status_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_camera_tracking_geo_status(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_camera_tracking_geo_status_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_camera_tracking_geo_status_name, sizeof(ulog_camera_tracking_geo_status_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_camera_tracking_geo_status(ulog_t *log, ulog_msg_id_t id, const ulog_camera_tracking_geo_status_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
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

    /* Current tracking status */
    if (lfs_file_write(log->lfs, log->file, &src->tracking_status, sizeof(src->tracking_status)) < 0) {
        return 1;
    }

    /* Latitude of tracked object [degE7] */
    if (lfs_file_write(log->lfs, log->file, &src->lat, sizeof(src->lat)) < 0) {
        return 1;
    }

    /* Longitude of tracked object [degE7] */
    if (lfs_file_write(log->lfs, log->file, &src->lon, sizeof(src->lon)) < 0) {
        return 1;
    }

    /* Altitude of tracked object(AMSL, WGS84) [m] */
    if (lfs_file_write(log->lfs, log->file, &src->alt, sizeof(src->alt)) < 0) {
        return 1;
    }

    /* Horizontal accuracy. NAN if unknown [m] */
    if (lfs_file_write(log->lfs, log->file, &src->h_acc, sizeof(src->h_acc)) < 0) {
        return 1;
    }

    /* Vertical accuracy. NAN if unknown [m] */
    if (lfs_file_write(log->lfs, log->file, &src->v_acc, sizeof(src->v_acc)) < 0) {
        return 1;
    }

    /* North velocity of tracked object. NAN if unknown [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vel_n, sizeof(src->vel_n)) < 0) {
        return 1;
    }

    /* East velocity of tracked object. NAN if unknown [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vel_e, sizeof(src->vel_e)) < 0) {
        return 1;
    }

    /* Down velocity of tracked object. NAN if unknown [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vel_d, sizeof(src->vel_d)) < 0) {
        return 1;
    }

    /* Velocity accuracy. NAN if unknown [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vel_acc, sizeof(src->vel_acc)) < 0) {
        return 1;
    }

    /* Distance between camera and tracked object. NAN if unknown [m] */
    if (lfs_file_write(log->lfs, log->file, &src->dist, sizeof(src->dist)) < 0) {
        return 1;
    }

    /* Heading in radians, in NED. NAN if unknown [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->hdg, sizeof(src->hdg)) < 0) {
        return 1;
    }

    /* Accuracy of heading, in NED. NAN if unknown [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->hdg_acc, sizeof(src->hdg_acc)) < 0) {
        return 1;
    }

    /* Camera id of a non-MAVLink camera attached to an autopilot (1-6).  0 if the component is a MAVLink camera (with its own component id). */
    if (lfs_file_write(log->lfs, log->file, &src->camera_device_id, sizeof(src->camera_device_id)) < 0) {
        return 1;
    }

    
    return 0;
}
