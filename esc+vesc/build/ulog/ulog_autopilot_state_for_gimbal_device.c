/**
 * @file    ulog_autopilot_state_for_gimbal_device.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_autopilot_state_for_gimbal_device.h"
#include "ulog_def.h"

const char ulog_autopilot_state_for_gimbal_device_format[] = "autopilot_state_for_gimbal_device:uint64_t timestamp;uint8_t target_system;uint8_t target_component;uint64_t time_boot_us;float[4] q;uint32_t q_estimated_delay_us;float vx;float vy;float vz;uint32_t v_estimated_delay_us;float feed_forward_angular_velocity_z;uint16_t estimator_status;uint8_t landed_state;float angular_velocity_z;";
const char ulog_autopilot_state_for_gimbal_device_name[] = "autopilot_state_for_gimbal_device";

int32_t ulog_format_autopilot_state_for_gimbal_device(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_autopilot_state_for_gimbal_device_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_autopilot_state_for_gimbal_device_format, sizeof(ulog_autopilot_state_for_gimbal_device_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_autopilot_state_for_gimbal_device(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_autopilot_state_for_gimbal_device_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_autopilot_state_for_gimbal_device_name, sizeof(ulog_autopilot_state_for_gimbal_device_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_autopilot_state_for_gimbal_device(ulog_t *log, ulog_msg_id_t id, const ulog_autopilot_state_for_gimbal_device_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint64_t)
                    + sizeof(float)*4
                    + sizeof(uint32_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(uint32_t)
                    + sizeof(float)
                    + sizeof(uint16_t)
                    + sizeof(uint8_t)
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

    /* System ID */
    if (lfs_file_write(log->lfs, log->file, &src->target_system, sizeof(src->target_system)) < 0) {
        return 1;
    }

    /* Component ID */
    if (lfs_file_write(log->lfs, log->file, &src->target_component, sizeof(src->target_component)) < 0) {
        return 1;
    }

    /* Timestamp (time since system boot). [us] */
    if (lfs_file_write(log->lfs, log->file, &src->time_boot_us, sizeof(src->time_boot_us)) < 0) {
        return 1;
    }

    /* Quaternion components of autopilot attitude: w, x, y, z (1 0 0 0 is the null-rotation, Hamilton convention). */
    if (lfs_file_write(log->lfs, log->file, src->q, sizeof(src->q)) < 0) {
        return 1;
    }

    /* Estimated delay of the attitude data. 0 if unknown. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->q_estimated_delay_us, sizeof(src->q_estimated_delay_us)) < 0) {
        return 1;
    }

    /* X Speed in NED (North, East, Down). NAN if unknown. [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vx, sizeof(src->vx)) < 0) {
        return 1;
    }

    /* Y Speed in NED (North, East, Down). NAN if unknown. [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vy, sizeof(src->vy)) < 0) {
        return 1;
    }

    /* Z Speed in NED (North, East, Down). NAN if unknown. [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vz, sizeof(src->vz)) < 0) {
        return 1;
    }

    /* Estimated delay of the speed data. 0 if unknown. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->v_estimated_delay_us, sizeof(src->v_estimated_delay_us)) < 0) {
        return 1;
    }

    /* Feed forward Z component of angular velocity (positive: yawing to the right). NaN to be ignored. This is to indicate if the autopilot is actively yawing. [rad/s] */
    if (lfs_file_write(log->lfs, log->file, &src->feed_forward_angular_velocity_z, sizeof(src->feed_forward_angular_velocity_z)) < 0) {
        return 1;
    }

    /* Bitmap indicating which estimator outputs are valid. */
    if (lfs_file_write(log->lfs, log->file, &src->estimator_status, sizeof(src->estimator_status)) < 0) {
        return 1;
    }

    /* The landed state. Is set to MAV_LANDED_STATE_UNDEFINED if landed state is unknown. */
    if (lfs_file_write(log->lfs, log->file, &src->landed_state, sizeof(src->landed_state)) < 0) {
        return 1;
    }

    /* Z component of angular velocity in NED (North, East, Down). NaN if unknown. [rad/s] */
    if (lfs_file_write(log->lfs, log->file, &src->angular_velocity_z, sizeof(src->angular_velocity_z)) < 0) {
        return 1;
    }

    
    return 0;
}
