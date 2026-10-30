/**
 * @file    ulog_control_system_state.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_control_system_state.h"
#include "ulog_def.h"

const char ulog_control_system_state_format[] = "control_system_state:uint64_t timestamp;uint64_t time_usec;float x_acc;float y_acc;float z_acc;float x_vel;float y_vel;float z_vel;float x_pos;float y_pos;float z_pos;float airspeed;float[3] vel_variance;float[3] pos_variance;float[4] q;float roll_rate;float pitch_rate;float yaw_rate;";
const char ulog_control_system_state_name[] = "control_system_state";

int32_t ulog_format_control_system_state(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_control_system_state_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_control_system_state_format, sizeof(ulog_control_system_state_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_control_system_state(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_control_system_state_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_control_system_state_name, sizeof(ulog_control_system_state_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_control_system_state(ulog_t *log, ulog_msg_id_t id, const ulog_control_system_state_t *src)
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
                    + sizeof(float)*3
                    + sizeof(float)*3
                    + sizeof(float)*4
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

    /* X acceleration in body frame [m/s/s] */
    if (lfs_file_write(log->lfs, log->file, &src->x_acc, sizeof(src->x_acc)) < 0) {
        return 1;
    }

    /* Y acceleration in body frame [m/s/s] */
    if (lfs_file_write(log->lfs, log->file, &src->y_acc, sizeof(src->y_acc)) < 0) {
        return 1;
    }

    /* Z acceleration in body frame [m/s/s] */
    if (lfs_file_write(log->lfs, log->file, &src->z_acc, sizeof(src->z_acc)) < 0) {
        return 1;
    }

    /* X velocity in body frame [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->x_vel, sizeof(src->x_vel)) < 0) {
        return 1;
    }

    /* Y velocity in body frame [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->y_vel, sizeof(src->y_vel)) < 0) {
        return 1;
    }

    /* Z velocity in body frame [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->z_vel, sizeof(src->z_vel)) < 0) {
        return 1;
    }

    /* X position in local frame [m] */
    if (lfs_file_write(log->lfs, log->file, &src->x_pos, sizeof(src->x_pos)) < 0) {
        return 1;
    }

    /* Y position in local frame [m] */
    if (lfs_file_write(log->lfs, log->file, &src->y_pos, sizeof(src->y_pos)) < 0) {
        return 1;
    }

    /* Z position in local frame [m] */
    if (lfs_file_write(log->lfs, log->file, &src->z_pos, sizeof(src->z_pos)) < 0) {
        return 1;
    }

    /* Airspeed, set to -1 if unknown [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->airspeed, sizeof(src->airspeed)) < 0) {
        return 1;
    }

    /* Variance of body velocity estimate */
    if (lfs_file_write(log->lfs, log->file, src->vel_variance, sizeof(src->vel_variance)) < 0) {
        return 1;
    }

    /* Variance in local position */
    if (lfs_file_write(log->lfs, log->file, src->pos_variance, sizeof(src->pos_variance)) < 0) {
        return 1;
    }

    /* The attitude, represented as Quaternion */
    if (lfs_file_write(log->lfs, log->file, src->q, sizeof(src->q)) < 0) {
        return 1;
    }

    /* Angular rate in roll axis [rad/s] */
    if (lfs_file_write(log->lfs, log->file, &src->roll_rate, sizeof(src->roll_rate)) < 0) {
        return 1;
    }

    /* Angular rate in pitch axis [rad/s] */
    if (lfs_file_write(log->lfs, log->file, &src->pitch_rate, sizeof(src->pitch_rate)) < 0) {
        return 1;
    }

    /* Angular rate in yaw axis [rad/s] */
    if (lfs_file_write(log->lfs, log->file, &src->yaw_rate, sizeof(src->yaw_rate)) < 0) {
        return 1;
    }

    
    return 0;
}
