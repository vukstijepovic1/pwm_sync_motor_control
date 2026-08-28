/**
 * @file    ulog_global_position_int_cov.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_global_position_int_cov.h"
#include "ulog_def.h"

const char ulog_global_position_int_cov_format[] = "global_position_int_cov:uint64_t timestamp;uint64_t time_usec;uint8_t estimator_type;int32_t lat;int32_t lon;int32_t alt;int32_t relative_alt;float vx;float vy;float vz;float[36] covariance;";
const char ulog_global_position_int_cov_name[] = "global_position_int_cov";

int32_t ulog_format_global_position_int_cov(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_global_position_int_cov_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_global_position_int_cov_format, sizeof(ulog_global_position_int_cov_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_global_position_int_cov(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_global_position_int_cov_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_global_position_int_cov_name, sizeof(ulog_global_position_int_cov_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_global_position_int_cov(ulog_t *log, ulog_msg_id_t id, const ulog_global_position_int_cov_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)*36
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

    /* Class id of the estimator this estimate originated from. */
    if (lfs_file_write(log->lfs, log->file, &src->estimator_type, sizeof(src->estimator_type)) < 0) {
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

    /* Altitude in meters above MSL [mm] */
    if (lfs_file_write(log->lfs, log->file, &src->alt, sizeof(src->alt)) < 0) {
        return 1;
    }

    /* Altitude above ground [mm] */
    if (lfs_file_write(log->lfs, log->file, &src->relative_alt, sizeof(src->relative_alt)) < 0) {
        return 1;
    }

    /* Ground X Speed (Latitude) [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vx, sizeof(src->vx)) < 0) {
        return 1;
    }

    /* Ground Y Speed (Longitude) [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vy, sizeof(src->vy)) < 0) {
        return 1;
    }

    /* Ground Z Speed (Altitude) [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vz, sizeof(src->vz)) < 0) {
        return 1;
    }

    /* Row-major representation of a 6x6 position and velocity 6x6 cross-covariance matrix (states: lat, lon, alt, vx, vy, vz; first six entries are the first ROW, next six entries are the second row, etc.). If unknown, assign NaN value to first element in the array. */
    if (lfs_file_write(log->lfs, log->file, src->covariance, sizeof(src->covariance)) < 0) {
        return 1;
    }

    
    return 0;
}
