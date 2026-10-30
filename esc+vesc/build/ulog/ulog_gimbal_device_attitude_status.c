/**
 * @file    ulog_gimbal_device_attitude_status.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_gimbal_device_attitude_status.h"
#include "ulog_def.h"

const char ulog_gimbal_device_attitude_status_format[] = "gimbal_device_attitude_status:uint64_t timestamp;uint8_t target_system;uint8_t target_component;uint32_t time_boot_ms;uint16_t flags;float[4] q;float angular_velocity_x;float angular_velocity_y;float angular_velocity_z;uint32_t failure_flags;float delta_yaw;float delta_yaw_velocity;uint8_t gimbal_device_id;";
const char ulog_gimbal_device_attitude_status_name[] = "gimbal_device_attitude_status";

int32_t ulog_format_gimbal_device_attitude_status(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_gimbal_device_attitude_status_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_gimbal_device_attitude_status_format, sizeof(ulog_gimbal_device_attitude_status_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_gimbal_device_attitude_status(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_gimbal_device_attitude_status_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_gimbal_device_attitude_status_name, sizeof(ulog_gimbal_device_attitude_status_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_gimbal_device_attitude_status(ulog_t *log, ulog_msg_id_t id, const ulog_gimbal_device_attitude_status_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint32_t)
                    + sizeof(uint16_t)
                    + sizeof(float)*4
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(uint32_t)
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

    /* System ID */
    if (lfs_file_write(log->lfs, log->file, &src->target_system, sizeof(src->target_system)) < 0) {
        return 1;
    }

    /* Component ID */
    if (lfs_file_write(log->lfs, log->file, &src->target_component, sizeof(src->target_component)) < 0) {
        return 1;
    }

    /* Timestamp (time since system boot). [ms] */
    if (lfs_file_write(log->lfs, log->file, &src->time_boot_ms, sizeof(src->time_boot_ms)) < 0) {
        return 1;
    }

    /* Current gimbal flags set. */
    if (lfs_file_write(log->lfs, log->file, &src->flags, sizeof(src->flags)) < 0) {
        return 1;
    }

    /* Quaternion components, w, x, y, z (1 0 0 0 is the null-rotation). The frame is described in the message description. */
    if (lfs_file_write(log->lfs, log->file, src->q, sizeof(src->q)) < 0) {
        return 1;
    }

    /* X component of angular velocity (positive: rolling to the right). The frame is described in the message description. NaN if unknown. [rad/s] */
    if (lfs_file_write(log->lfs, log->file, &src->angular_velocity_x, sizeof(src->angular_velocity_x)) < 0) {
        return 1;
    }

    /* Y component of angular velocity (positive: pitching up). The frame is described in the message description. NaN if unknown. [rad/s] */
    if (lfs_file_write(log->lfs, log->file, &src->angular_velocity_y, sizeof(src->angular_velocity_y)) < 0) {
        return 1;
    }

    /* Z component of angular velocity (positive: yawing to the right). The frame is described in the message description. NaN if unknown. [rad/s] */
    if (lfs_file_write(log->lfs, log->file, &src->angular_velocity_z, sizeof(src->angular_velocity_z)) < 0) {
        return 1;
    }

    /* Failure flags (0 for no failure) */
    if (lfs_file_write(log->lfs, log->file, &src->failure_flags, sizeof(src->failure_flags)) < 0) {
        return 1;
    }

    /* Yaw angle relating the quaternions in earth and body frames (see message description). NaN if unknown. [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->delta_yaw, sizeof(src->delta_yaw)) < 0) {
        return 1;
    }

    /* Yaw angular velocity relating the angular velocities in earth and body frames (see message description). NaN if unknown. [rad/s] */
    if (lfs_file_write(log->lfs, log->file, &src->delta_yaw_velocity, sizeof(src->delta_yaw_velocity)) < 0) {
        return 1;
    }

    /* This field is to be used if the gimbal manager and the gimbal device are the same component and hence have the same component ID. This field is then set a number between 1-6. If the component ID is separate, this field is not required and must be set to 0. */
    if (lfs_file_write(log->lfs, log->file, &src->gimbal_device_id, sizeof(src->gimbal_device_id)) < 0) {
        return 1;
    }

    
    return 0;
}
