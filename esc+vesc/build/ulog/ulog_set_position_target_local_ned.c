/**
 * @file    ulog_set_position_target_local_ned.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_set_position_target_local_ned.h"
#include "ulog_def.h"

const char ulog_set_position_target_local_ned_format[] = "set_position_target_local_ned:uint64_t timestamp;uint32_t time_boot_ms;uint8_t target_system;uint8_t target_component;uint8_t coordinate_frame;uint16_t type_mask;float x;float y;float z;float vx;float vy;float vz;float afx;float afy;float afz;float yaw;float yaw_rate;";
const char ulog_set_position_target_local_ned_name[] = "set_position_target_local_ned";

int32_t ulog_format_set_position_target_local_ned(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_set_position_target_local_ned_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_set_position_target_local_ned_format, sizeof(ulog_set_position_target_local_ned_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_set_position_target_local_ned(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_set_position_target_local_ned_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_set_position_target_local_ned_name, sizeof(ulog_set_position_target_local_ned_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_set_position_target_local_ned(ulog_t *log, ulog_msg_id_t id, const ulog_set_position_target_local_ned_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint16_t)
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

    /* System ID */
    if (lfs_file_write(log->lfs, log->file, &src->target_system, sizeof(src->target_system)) < 0) {
        return 1;
    }

    /* Component ID */
    if (lfs_file_write(log->lfs, log->file, &src->target_component, sizeof(src->target_component)) < 0) {
        return 1;
    }

    /* Valid options are: MAV_FRAME_LOCAL_NED = 1, MAV_FRAME_LOCAL_OFFSET_NED = 7, MAV_FRAME_BODY_NED = 8, MAV_FRAME_BODY_OFFSET_NED = 9 */
    if (lfs_file_write(log->lfs, log->file, &src->coordinate_frame, sizeof(src->coordinate_frame)) < 0) {
        return 1;
    }

    /* Bitmap to indicate which dimensions should be ignored by the vehicle. */
    if (lfs_file_write(log->lfs, log->file, &src->type_mask, sizeof(src->type_mask)) < 0) {
        return 1;
    }

    /* X Position in NED frame [m] */
    if (lfs_file_write(log->lfs, log->file, &src->x, sizeof(src->x)) < 0) {
        return 1;
    }

    /* Y Position in NED frame [m] */
    if (lfs_file_write(log->lfs, log->file, &src->y, sizeof(src->y)) < 0) {
        return 1;
    }

    /* Z Position in NED frame (note, altitude is negative in NED) [m] */
    if (lfs_file_write(log->lfs, log->file, &src->z, sizeof(src->z)) < 0) {
        return 1;
    }

    /* X velocity in NED frame [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vx, sizeof(src->vx)) < 0) {
        return 1;
    }

    /* Y velocity in NED frame [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vy, sizeof(src->vy)) < 0) {
        return 1;
    }

    /* Z velocity in NED frame [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vz, sizeof(src->vz)) < 0) {
        return 1;
    }

    /* X acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N [m/s/s] */
    if (lfs_file_write(log->lfs, log->file, &src->afx, sizeof(src->afx)) < 0) {
        return 1;
    }

    /* Y acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N [m/s/s] */
    if (lfs_file_write(log->lfs, log->file, &src->afy, sizeof(src->afy)) < 0) {
        return 1;
    }

    /* Z acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N [m/s/s] */
    if (lfs_file_write(log->lfs, log->file, &src->afz, sizeof(src->afz)) < 0) {
        return 1;
    }

    /* yaw setpoint [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->yaw, sizeof(src->yaw)) < 0) {
        return 1;
    }

    /* yaw rate setpoint [rad/s] */
    if (lfs_file_write(log->lfs, log->file, &src->yaw_rate, sizeof(src->yaw_rate)) < 0) {
        return 1;
    }

    
    return 0;
}
