/**
 * @file    ulog_hil_controls.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_hil_controls.h"
#include "ulog_def.h"

const char ulog_hil_controls_format[] = "hil_controls:uint64_t timestamp;uint64_t time_usec;float roll_ailerons;float pitch_elevator;float yaw_rudder;float throttle;float aux1;float aux2;float aux3;float aux4;uint8_t mode;uint8_t nav_mode;";
const char ulog_hil_controls_name[] = "hil_controls";

int32_t ulog_format_hil_controls(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_hil_controls_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_hil_controls_format, sizeof(ulog_hil_controls_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_hil_controls(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_hil_controls_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_hil_controls_name, sizeof(ulog_hil_controls_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_hil_controls(ulog_t *log, ulog_msg_id_t id, const ulog_hil_controls_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint64_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(uint8_t)
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

    /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->time_usec, sizeof(src->time_usec)) < 0) {
        return 1;
    }

    /* Control output -1 .. 1 */
    if (lfs_file_write(log->lfs, log->file, &src->roll_ailerons, sizeof(src->roll_ailerons)) < 0) {
        return 1;
    }

    /* Control output -1 .. 1 */
    if (lfs_file_write(log->lfs, log->file, &src->pitch_elevator, sizeof(src->pitch_elevator)) < 0) {
        return 1;
    }

    /* Control output -1 .. 1 */
    if (lfs_file_write(log->lfs, log->file, &src->yaw_rudder, sizeof(src->yaw_rudder)) < 0) {
        return 1;
    }

    /* Throttle 0 .. 1 */
    if (lfs_file_write(log->lfs, log->file, &src->throttle, sizeof(src->throttle)) < 0) {
        return 1;
    }

    /* Aux 1, -1 .. 1 */
    if (lfs_file_write(log->lfs, log->file, &src->aux1, sizeof(src->aux1)) < 0) {
        return 1;
    }

    /* Aux 2, -1 .. 1 */
    if (lfs_file_write(log->lfs, log->file, &src->aux2, sizeof(src->aux2)) < 0) {
        return 1;
    }

    /* Aux 3, -1 .. 1 */
    if (lfs_file_write(log->lfs, log->file, &src->aux3, sizeof(src->aux3)) < 0) {
        return 1;
    }

    /* Aux 4, -1 .. 1 */
    if (lfs_file_write(log->lfs, log->file, &src->aux4, sizeof(src->aux4)) < 0) {
        return 1;
    }

    /* System mode. */
    if (lfs_file_write(log->lfs, log->file, &src->mode, sizeof(src->mode)) < 0) {
        return 1;
    }

    /* Navigation mode (MAV_NAV_MODE) */
    if (lfs_file_write(log->lfs, log->file, &src->nav_mode, sizeof(src->nav_mode)) < 0) {
        return 1;
    }

    
    return 0;
}
