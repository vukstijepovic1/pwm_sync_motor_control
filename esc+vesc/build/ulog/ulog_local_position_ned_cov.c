/**
 * @file    ulog_local_position_ned_cov.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_local_position_ned_cov.h"
#include "ulog_def.h"

const char ulog_local_position_ned_cov_format[] = "local_position_ned_cov:uint64_t timestamp;uint64_t time_usec;uint8_t estimator_type;float x;float y;float z;float vx;float vy;float vz;float ax;float ay;float az;float[45] covariance;";
const char ulog_local_position_ned_cov_name[] = "local_position_ned_cov";

int32_t ulog_format_local_position_ned_cov(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_local_position_ned_cov_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_local_position_ned_cov_format, sizeof(ulog_local_position_ned_cov_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_local_position_ned_cov(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_local_position_ned_cov_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_local_position_ned_cov_name, sizeof(ulog_local_position_ned_cov_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_local_position_ned_cov(ulog_t *log, ulog_msg_id_t id, const ulog_local_position_ned_cov_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)*45
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

    /* Class id of the estimator this estimate originated from. */
    if (lfs_file_write(log->lfs, log->file, &src->estimator_type, sizeof(src->estimator_type)) < 0) {
        return 1;
    }

    /* X Position [m] */
    if (lfs_file_write(log->lfs, log->file, &src->x, sizeof(src->x)) < 0) {
        return 1;
    }

    /* Y Position [m] */
    if (lfs_file_write(log->lfs, log->file, &src->y, sizeof(src->y)) < 0) {
        return 1;
    }

    /* Z Position [m] */
    if (lfs_file_write(log->lfs, log->file, &src->z, sizeof(src->z)) < 0) {
        return 1;
    }

    /* X Speed [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vx, sizeof(src->vx)) < 0) {
        return 1;
    }

    /* Y Speed [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vy, sizeof(src->vy)) < 0) {
        return 1;
    }

    /* Z Speed [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vz, sizeof(src->vz)) < 0) {
        return 1;
    }

    /* X Acceleration [m/s/s] */
    if (lfs_file_write(log->lfs, log->file, &src->ax, sizeof(src->ax)) < 0) {
        return 1;
    }

    /* Y Acceleration [m/s/s] */
    if (lfs_file_write(log->lfs, log->file, &src->ay, sizeof(src->ay)) < 0) {
        return 1;
    }

    /* Z Acceleration [m/s/s] */
    if (lfs_file_write(log->lfs, log->file, &src->az, sizeof(src->az)) < 0) {
        return 1;
    }

    /* Row-major representation of position, velocity and acceleration 9x9 cross-covariance matrix upper right triangle (states: x, y, z, vx, vy, vz, ax, ay, az; first nine entries are the first ROW, next eight entries are the second row, etc.). If unknown, assign NaN value to first element in the array. */
    if (lfs_file_write(log->lfs, log->file, src->covariance, sizeof(src->covariance)) < 0) {
        return 1;
    }

    
    return 0;
}
