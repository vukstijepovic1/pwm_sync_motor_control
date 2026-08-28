/**
 * @file    ulog_hil_state_quaternion.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_hil_state_quaternion.h"
#include "ulog_def.h"

const char ulog_hil_state_quaternion_format[] = "hil_state_quaternion:uint64_t timestamp;uint64_t time_usec;float[4] attitude_quaternion;float rollspeed;float pitchspeed;float yawspeed;int32_t lat;int32_t lon;int32_t alt;int16_t vx;int16_t vy;int16_t vz;uint16_t ind_airspeed;uint16_t true_airspeed;int16_t xacc;int16_t yacc;int16_t zacc;";
const char ulog_hil_state_quaternion_name[] = "hil_state_quaternion";

int32_t ulog_format_hil_state_quaternion(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_hil_state_quaternion_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_hil_state_quaternion_format, sizeof(ulog_hil_state_quaternion_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_hil_state_quaternion(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_hil_state_quaternion_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_hil_state_quaternion_name, sizeof(ulog_hil_state_quaternion_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_hil_state_quaternion(ulog_t *log, ulog_msg_id_t id, const ulog_hil_state_quaternion_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint64_t)
                    + sizeof(float)*4
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
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

    /* Vehicle attitude expressed as normalized quaternion in w, x, y, z order (with 1 0 0 0 being the null-rotation) */
    if (lfs_file_write(log->lfs, log->file, src->attitude_quaternion, sizeof(src->attitude_quaternion)) < 0) {
        return 1;
    }

    /* Body frame roll / phi angular speed [rad/s] */
    if (lfs_file_write(log->lfs, log->file, &src->rollspeed, sizeof(src->rollspeed)) < 0) {
        return 1;
    }

    /* Body frame pitch / theta angular speed [rad/s] */
    if (lfs_file_write(log->lfs, log->file, &src->pitchspeed, sizeof(src->pitchspeed)) < 0) {
        return 1;
    }

    /* Body frame yaw / psi angular speed [rad/s] */
    if (lfs_file_write(log->lfs, log->file, &src->yawspeed, sizeof(src->yawspeed)) < 0) {
        return 1;
    }

    /* Latitude [degE7] */
    if (lfs_file_write(log->lfs, log->file, &src->lat, sizeof(src->lat)) < 0) {
        return 1;
    }

    /* Longitude [degE7] */
    if (lfs_file_write(log->lfs, log->file, &src->lon, sizeof(src->lon)) < 0) {
        return 1;
    }

    /* Altitude [mm] */
    if (lfs_file_write(log->lfs, log->file, &src->alt, sizeof(src->alt)) < 0) {
        return 1;
    }

    /* Ground X Speed (Latitude) [cm/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vx, sizeof(src->vx)) < 0) {
        return 1;
    }

    /* Ground Y Speed (Longitude) [cm/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vy, sizeof(src->vy)) < 0) {
        return 1;
    }

    /* Ground Z Speed (Altitude) [cm/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vz, sizeof(src->vz)) < 0) {
        return 1;
    }

    /* Indicated airspeed [cm/s] */
    if (lfs_file_write(log->lfs, log->file, &src->ind_airspeed, sizeof(src->ind_airspeed)) < 0) {
        return 1;
    }

    /* True airspeed [cm/s] */
    if (lfs_file_write(log->lfs, log->file, &src->true_airspeed, sizeof(src->true_airspeed)) < 0) {
        return 1;
    }

    /* X acceleration [mG] */
    if (lfs_file_write(log->lfs, log->file, &src->xacc, sizeof(src->xacc)) < 0) {
        return 1;
    }

    /* Y acceleration [mG] */
    if (lfs_file_write(log->lfs, log->file, &src->yacc, sizeof(src->yacc)) < 0) {
        return 1;
    }

    /* Z acceleration [mG] */
    if (lfs_file_write(log->lfs, log->file, &src->zacc, sizeof(src->zacc)) < 0) {
        return 1;
    }

    
    return 0;
}
