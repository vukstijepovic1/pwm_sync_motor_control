/**
 * @file    ulog_wind_cov.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_wind_cov.h"
#include "ulog_def.h"

const char ulog_wind_cov_format[] = "wind_cov:uint64_t timestamp;uint64_t time_usec;float wind_x;float wind_y;float wind_z;float var_horiz;float var_vert;float wind_alt;float horiz_accuracy;float vert_accuracy;";
const char ulog_wind_cov_name[] = "wind_cov";

int32_t ulog_format_wind_cov(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_wind_cov_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_wind_cov_format, sizeof(ulog_wind_cov_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_wind_cov(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_wind_cov_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_wind_cov_name, sizeof(ulog_wind_cov_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_wind_cov(ulog_t *log, ulog_msg_id_t id, const ulog_wind_cov_t *src)
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

    /* Wind in North (NED) direction (NAN if unknown) [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->wind_x, sizeof(src->wind_x)) < 0) {
        return 1;
    }

    /* Wind in East (NED) direction (NAN if unknown) [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->wind_y, sizeof(src->wind_y)) < 0) {
        return 1;
    }

    /* Wind in down (NED) direction (NAN if unknown) [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->wind_z, sizeof(src->wind_z)) < 0) {
        return 1;
    }

    /* Variability of wind in XY, 1-STD estimated from a 1 Hz lowpassed wind estimate (NAN if unknown) [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->var_horiz, sizeof(src->var_horiz)) < 0) {
        return 1;
    }

    /* Variability of wind in Z, 1-STD estimated from a 1 Hz lowpassed wind estimate (NAN if unknown) [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->var_vert, sizeof(src->var_vert)) < 0) {
        return 1;
    }

    /* Altitude (MSL) that this measurement was taken at (NAN if unknown) [m] */
    if (lfs_file_write(log->lfs, log->file, &src->wind_alt, sizeof(src->wind_alt)) < 0) {
        return 1;
    }

    /* Horizontal speed 1-STD accuracy (0 if unknown) [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->horiz_accuracy, sizeof(src->horiz_accuracy)) < 0) {
        return 1;
    }

    /* Vertical speed 1-STD accuracy (0 if unknown) [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vert_accuracy, sizeof(src->vert_accuracy)) < 0) {
        return 1;
    }

    
    return 0;
}
