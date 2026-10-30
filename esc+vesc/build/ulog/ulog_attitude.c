/**
 * @file    ulog_attitude.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_attitude.h"
#include "ulog_def.h"

const char ulog_attitude_format[] = "attitude:uint64_t timestamp;uint32_t time_boot_ms;float roll;float pitch;float yaw;float rollspeed;float pitchspeed;float yawspeed;";
const char ulog_attitude_name[] = "attitude";

int32_t ulog_format_attitude(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_attitude_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_attitude_format, sizeof(ulog_attitude_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_attitude(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_attitude_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_attitude_name, sizeof(ulog_attitude_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_attitude(ulog_t *log, ulog_msg_id_t id, const ulog_attitude_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
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

    /* Roll angle (-pi..+pi) [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->roll, sizeof(src->roll)) < 0) {
        return 1;
    }

    /* Pitch angle (-pi..+pi) [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->pitch, sizeof(src->pitch)) < 0) {
        return 1;
    }

    /* Yaw angle (-pi..+pi) [rad] */
    if (lfs_file_write(log->lfs, log->file, &src->yaw, sizeof(src->yaw)) < 0) {
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

    
    return 0;
}
