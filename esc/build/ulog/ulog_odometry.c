/**
 * @file    ulog_odometry.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_odometry.h"
#include "ulog_def.h"

const char ulog_odometry_format[] = "odometry:uint64_t timestamp;uint64_t time_usec;uint8_t frame_id;uint8_t child_frame_id;float x;float y;float z;float[4] q;float vx;float vy;float vz;float rollspeed;float pitchspeed;float yawspeed;float[21] pose_covariance;float[21] velocity_covariance;uint8_t reset_counter;uint8_t estimator_type;int8_t quality;";
const char ulog_odometry_name[] = "odometry";

int32_t ulog_format_odometry(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_odometry_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_odometry_format, sizeof(ulog_odometry_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_odometry(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_odometry_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_odometry_name, sizeof(ulog_odometry_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_odometry(ulog_t *log, ulog_msg_id_t id, const ulog_odometry_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)*4
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)*21
                    + sizeof(float)*21
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(int8_t)
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

    /* Coordinate frame of reference for the pose data. */
    if (lfs_file_write(log->lfs, log->file, &src->frame_id, sizeof(src->frame_id)) < 0) {
        return 1;
    }

    /* Coordinate frame of reference for the velocity in free space (twist) data. */
    if (lfs_file_write(log->lfs, log->file, &src->child_frame_id, sizeof(src->child_frame_id)) < 0) {
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

    /* Quaternion components, w, x, y, z (1 0 0 0 is the null-rotation) */
    if (lfs_file_write(log->lfs, log->file, src->q, sizeof(src->q)) < 0) {
        return 1;
    }

    /* X linear speed [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vx, sizeof(src->vx)) < 0) {
        return 1;
    }

    /* Y linear speed [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vy, sizeof(src->vy)) < 0) {
        return 1;
    }

    /* Z linear speed [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vz, sizeof(src->vz)) < 0) {
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

    /* Row-major representation of a 6x6 pose cross-covariance matrix upper right triangle (states: x, y, z, roll, pitch, yaw; first six entries are the first ROW, next five entries are the second ROW, etc.). If unknown, assign NaN value to first element in the array. */
    if (lfs_file_write(log->lfs, log->file, src->pose_covariance, sizeof(src->pose_covariance)) < 0) {
        return 1;
    }

    /* Row-major representation of a 6x6 velocity cross-covariance matrix upper right triangle (states: vx, vy, vz, rollspeed, pitchspeed, yawspeed; first six entries are the first ROW, next five entries are the second ROW, etc.). If unknown, assign NaN value to first element in the array. */
    if (lfs_file_write(log->lfs, log->file, src->velocity_covariance, sizeof(src->velocity_covariance)) < 0) {
        return 1;
    }

    /* Estimate reset counter. This should be incremented when the estimate resets in any of the dimensions (position, velocity, attitude, angular speed). This is designed to be used when e.g an external SLAM system detects a loop-closure and the estimate jumps. */
    if (lfs_file_write(log->lfs, log->file, &src->reset_counter, sizeof(src->reset_counter)) < 0) {
        return 1;
    }

    /* Type of estimator that is providing the odometry. */
    if (lfs_file_write(log->lfs, log->file, &src->estimator_type, sizeof(src->estimator_type)) < 0) {
        return 1;
    }

    /* Optional odometry quality metric as a percentage. -1 = odometry has failed, 0 = unknown/unset quality, 1 = worst quality, 100 = best quality [%] */
    if (lfs_file_write(log->lfs, log->file, &src->quality, sizeof(src->quality)) < 0) {
        return 1;
    }

    
    return 0;
}
