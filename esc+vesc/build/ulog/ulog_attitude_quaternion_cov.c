/**
 * @file    ulog_attitude_quaternion_cov.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_attitude_quaternion_cov.h"
#include "ulog_def.h"

const char ulog_attitude_quaternion_cov_format[] = "attitude_quaternion_cov:uint64_t timestamp;uint64_t time_usec;float[4] q;float rollspeed;float pitchspeed;float yawspeed;float[9] covariance;";
const char ulog_attitude_quaternion_cov_name[] = "attitude_quaternion_cov";

int32_t ulog_format_attitude_quaternion_cov(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_attitude_quaternion_cov_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_attitude_quaternion_cov_format, sizeof(ulog_attitude_quaternion_cov_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_attitude_quaternion_cov(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_attitude_quaternion_cov_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_attitude_quaternion_cov_name, sizeof(ulog_attitude_quaternion_cov_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_attitude_quaternion_cov(ulog_t *log, ulog_msg_id_t id, const ulog_attitude_quaternion_cov_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint64_t)
                    + sizeof(float)*4
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)*9
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

    /* Quaternion components, w, x, y, z (1 0 0 0 is the null-rotation) */
    if (lfs_file_write(log->lfs, log->file, src->q, sizeof(src->q)) < 0) {
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

    /* Row-major representation of a 3x3 attitude covariance matrix (states: roll, pitch, yaw; first three entries are the first ROW, next three entries are the second row, etc.). If unknown, assign NaN value to first element in the array. */
    if (lfs_file_write(log->lfs, log->file, src->covariance, sizeof(src->covariance)) < 0) {
        return 1;
    }

    
    return 0;
}
