/**
 * @file    ulog_set_position_target_global_int.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_set_position_target_global_int.h"
#include "ulog_def.h"

const char ulog_set_position_target_global_int_format[] = "set_position_target_global_int:uint64_t timestamp;uint32_t time_boot_ms;uint8_t target_system;uint8_t target_component;uint8_t coordinate_frame;uint16_t type_mask;int32_t lat_int;int32_t lon_int;float alt;float vx;float vy;float vz;float afx;float afy;float afz;float yaw;float yaw_rate;";
const char ulog_set_position_target_global_int_name[] = "set_position_target_global_int";

int32_t ulog_format_set_position_target_global_int(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_set_position_target_global_int_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_set_position_target_global_int_format, sizeof(ulog_set_position_target_global_int_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_set_position_target_global_int(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_set_position_target_global_int_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_set_position_target_global_int_name, sizeof(ulog_set_position_target_global_int_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_set_position_target_global_int(ulog_t *log, ulog_msg_id_t id, const ulog_set_position_target_global_int_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint16_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
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

    /* Timestamp (time since system boot). The rationale for the timestamp in the setpoint is to allow the system to compensate for the transport delay of the setpoint. This allows the system to compensate processing latency. [ms] */
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

    /* Valid options are: MAV_FRAME_GLOBAL = 0, MAV_FRAME_GLOBAL_RELATIVE_ALT = 3, MAV_FRAME_GLOBAL_TERRAIN_ALT = 10 (MAV_FRAME_GLOBAL_INT, MAV_FRAME_GLOBAL_RELATIVE_ALT_INT, MAV_FRAME_GLOBAL_TERRAIN_ALT_INT are allowed synonyms, but have been deprecated) */
    if (lfs_file_write(log->lfs, log->file, &src->coordinate_frame, sizeof(src->coordinate_frame)) < 0) {
        return 1;
    }

    /* Bitmap to indicate which dimensions should be ignored by the vehicle. */
    if (lfs_file_write(log->lfs, log->file, &src->type_mask, sizeof(src->type_mask)) < 0) {
        return 1;
    }

    /* Latitude in WGS84 frame [degE7] */
    if (lfs_file_write(log->lfs, log->file, &src->lat_int, sizeof(src->lat_int)) < 0) {
        return 1;
    }

    /* Longitude in WGS84 frame [degE7] */
    if (lfs_file_write(log->lfs, log->file, &src->lon_int, sizeof(src->lon_int)) < 0) {
        return 1;
    }

    /* Altitude (MSL, Relative to home, or AGL - depending on frame) [m] */
    if (lfs_file_write(log->lfs, log->file, &src->alt, sizeof(src->alt)) < 0) {
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
