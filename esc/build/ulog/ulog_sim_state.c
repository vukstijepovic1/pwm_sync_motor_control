/**
 * @file    ulog_sim_state.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_sim_state.h"
#include "ulog_def.h"

const char ulog_sim_state_format[] = "sim_state:uint64_t timestamp;float q1;float q2;float q3;float q4;float roll;float pitch;float yaw;float xacc;float yacc;float zacc;float xgyro;float ygyro;float zgyro;float lat;float lon;float alt;float std_dev_horz;float std_dev_vert;float vn;float ve;float vd;int32_t lat_int;int32_t lon_int;";
const char ulog_sim_state_name[] = "sim_state";

int32_t ulog_format_sim_state(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_sim_state_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_sim_state_format, sizeof(ulog_sim_state_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_sim_state(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_sim_state_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_sim_state_name, sizeof(ulog_sim_state_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_sim_state(ulog_t *log, ulog_msg_id_t id, const ulog_sim_state_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
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
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
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

    /* True attitude quaternion component 1, w (1 in null-rotation) */
    if (lfs_file_write(log->lfs, log->file, &src->q1, sizeof(src->q1)) < 0) {
        return 1;
    }

    /* True attitude quaternion component 2, x (0 in null-rotation) */
    if (lfs_file_write(log->lfs, log->file, &src->q2, sizeof(src->q2)) < 0) {
        return 1;
    }

    /* True attitude quaternion component 3, y (0 in null-rotation) */
    if (lfs_file_write(log->lfs, log->file, &src->q3, sizeof(src->q3)) < 0) {
        return 1;
    }

    /* True attitude quaternion component 4, z (0 in null-rotation) */
    if (lfs_file_write(log->lfs, log->file, &src->q4, sizeof(src->q4)) < 0) {
        return 1;
    }

    /* Attitude roll expressed as Euler angles, not recommended except for human-readable outputs [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->roll, sizeof(src->roll)) < 0) {
        return 1;
    }

    /* Attitude pitch expressed as Euler angles, not recommended except for human-readable outputs [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->pitch, sizeof(src->pitch)) < 0) {
        return 1;
    }

    /* Attitude yaw expressed as Euler angles, not recommended except for human-readable outputs [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->yaw, sizeof(src->yaw)) < 0) {
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

    /* Latitude (lower precision). Both this and the lat_int field should be set. [deg] */
    if (lfs_file_write(log->lfs, log->file, &src->lat, sizeof(src->lat)) < 0) {
        return 1;
    }

    /* Longitude (lower precision). Both this and the lon_int field should be set. [deg] */
    if (lfs_file_write(log->lfs, log->file, &src->lon, sizeof(src->lon)) < 0) {
        return 1;
    }

    /* Altitude [m] */
    if (lfs_file_write(log->lfs, log->file, &src->alt, sizeof(src->alt)) < 0) {
        return 1;
    }

    /* Horizontal position standard deviation */
    if (lfs_file_write(log->lfs, log->file, &src->std_dev_horz, sizeof(src->std_dev_horz)) < 0) {
        return 1;
    }

    /* Vertical position standard deviation */
    if (lfs_file_write(log->lfs, log->file, &src->std_dev_vert, sizeof(src->std_dev_vert)) < 0) {
        return 1;
    }

    /* True velocity in north direction in earth-fixed NED frame [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vn, sizeof(src->vn)) < 0) {
        return 1;
    }

    /* True velocity in east direction in earth-fixed NED frame [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->ve, sizeof(src->ve)) < 0) {
        return 1;
    }

    /* True velocity in down direction in earth-fixed NED frame [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vd, sizeof(src->vd)) < 0) {
        return 1;
    }

    /* Latitude (higher precision). If 0, recipients should use the lat field value (otherwise this field is preferred). [degE7] */
    if (lfs_file_write(log->lfs, log->file, &src->lat_int, sizeof(src->lat_int)) < 0) {
        return 1;
    }

    /* Longitude (higher precision). If 0, recipients should use the lon field value (otherwise this field is preferred). [degE7] */
    if (lfs_file_write(log->lfs, log->file, &src->lon_int, sizeof(src->lon_int)) < 0) {
        return 1;
    }

    
    return 0;
}
