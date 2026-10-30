/**
 * @file    ulog_set_attitude_target.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_set_attitude_target.h"
#include "ulog_def.h"

const char ulog_set_attitude_target_format[] = "set_attitude_target:uint64_t timestamp;uint32_t time_boot_ms;uint8_t target_system;uint8_t target_component;uint8_t type_mask;float[4] q;float body_roll_rate;float body_pitch_rate;float body_yaw_rate;float thrust;float[3] thrust_body;";
const char ulog_set_attitude_target_name[] = "set_attitude_target";

int32_t ulog_format_set_attitude_target(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_set_attitude_target_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_set_attitude_target_format, sizeof(ulog_set_attitude_target_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_set_attitude_target(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_set_attitude_target_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_set_attitude_target_name, sizeof(ulog_set_attitude_target_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_set_attitude_target(ulog_t *log, ulog_msg_id_t id, const ulog_set_attitude_target_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(float)*4
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)*3
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

    /* Bitmap to indicate which dimensions should be ignored by the vehicle. */
    if (lfs_file_write(log->lfs, log->file, &src->type_mask, sizeof(src->type_mask)) < 0) {
        return 1;
    }

    /* Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0) from MAV_FRAME_LOCAL_NED to MAV_FRAME_BODY_FRD */
    if (lfs_file_write(log->lfs, log->file, src->q, sizeof(src->q)) < 0) {
        return 1;
    }

    /* Body roll rate [rad/s] */
    if (lfs_file_write(log->lfs, log->file, &src->body_roll_rate, sizeof(src->body_roll_rate)) < 0) {
        return 1;
    }

    /* Body pitch rate [rad/s] */
    if (lfs_file_write(log->lfs, log->file, &src->body_pitch_rate, sizeof(src->body_pitch_rate)) < 0) {
        return 1;
    }

    /* Body yaw rate [rad/s] */
    if (lfs_file_write(log->lfs, log->file, &src->body_yaw_rate, sizeof(src->body_yaw_rate)) < 0) {
        return 1;
    }

    /* Collective thrust, normalized to 0 .. 1 (-1 .. 1 for vehicles capable of reverse trust) */
    if (lfs_file_write(log->lfs, log->file, &src->thrust, sizeof(src->thrust)) < 0) {
        return 1;
    }

    /* 3D thrust setpoint in the body NED frame, normalized to -1 .. 1 */
    if (lfs_file_write(log->lfs, log->file, src->thrust_body, sizeof(src->thrust_body)) < 0) {
        return 1;
    }

    
    return 0;
}
