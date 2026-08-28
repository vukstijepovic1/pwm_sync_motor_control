/**
 * @file    ulog_attitude_quaternion.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_attitude_quaternion.h"
#include "ulog_def.h"

const char ulog_attitude_quaternion_format[] = "attitude_quaternion:uint64_t timestamp;uint32_t time_boot_ms;float q1;float q2;float q3;float q4;float rollspeed;float pitchspeed;float yawspeed;float[4] repr_offset_q;";
const char ulog_attitude_quaternion_name[] = "attitude_quaternion";

int32_t ulog_format_attitude_quaternion(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_attitude_quaternion_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_attitude_quaternion_format, sizeof(ulog_attitude_quaternion_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_attitude_quaternion(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_attitude_quaternion_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_attitude_quaternion_name, sizeof(ulog_attitude_quaternion_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_attitude_quaternion(ulog_t *log, ulog_msg_id_t id, const ulog_attitude_quaternion_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)*4
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

    /* Quaternion component 1, w (1 in null-rotation) */
    if (lfs_file_write(log->lfs, log->file, &src->q1, sizeof(src->q1)) < 0) {
        return 1;
    }

    /* Quaternion component 2, x (0 in null-rotation) */
    if (lfs_file_write(log->lfs, log->file, &src->q2, sizeof(src->q2)) < 0) {
        return 1;
    }

    /* Quaternion component 3, y (0 in null-rotation) */
    if (lfs_file_write(log->lfs, log->file, &src->q3, sizeof(src->q3)) < 0) {
        return 1;
    }

    /* Quaternion component 4, z (0 in null-rotation) */
    if (lfs_file_write(log->lfs, log->file, &src->q4, sizeof(src->q4)) < 0) {
        return 1;
    }

    /* Roll angular speed [rad/s] */
    if (lfs_file_write(log->lfs, log->file, &src->rollspeed, sizeof(src->rollspeed)) < 0) {
        return 1;
    }

    /* Pitch angular speed [rad/s] */
    if (lfs_file_write(log->lfs, log->file, &src->pitchspeed, sizeof(src->pitchspeed)) < 0) {
        return 1;
    }

    /* Yaw angular speed [rad/s] */
    if (lfs_file_write(log->lfs, log->file, &src->yawspeed, sizeof(src->yawspeed)) < 0) {
        return 1;
    }

    /* Rotation offset by which the attitude quaternion and angular speed vector should be rotated for user display (quaternion with [w, x, y, z] order, zero-rotation is [1, 0, 0, 0], send [0, 0, 0, 0] if field not supported). This field is intended for systems in which the reference attitude may change during flight. For example, tailsitters VTOLs rotate their reference attitude by 90 degrees between hover mode and fixed wing mode, thus repr_offset_q is equal to [1, 0, 0, 0] in hover mode and equal to [0.7071, 0, 0.7071, 0] in fixed wing mode. */
    if (lfs_file_write(log->lfs, log->file, src->repr_offset_q, sizeof(src->repr_offset_q)) < 0) {
        return 1;
    }

    
    return 0;
}
