/**
 * @file    ulog_lisum_gnss_recv_data.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_lisum_gnss_recv_data.h"
#include "ulog_def.h"

const char ulog_lisum_gnss_recv_data_format[] = "lisum_gnss_recv_data:uint64_t timestamp;uint8_t dev_id;double lon;double lat;float alt;float head;float head_rtk;float vel_ne;float vel_d;uint8_t fix_type;uint8_t carr_sol;uint8_t rtk_head_valid;uint8_t sv_num;";
const char ulog_lisum_gnss_recv_data_name[] = "lisum_gnss_recv_data";

int32_t ulog_format_lisum_gnss_recv_data(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_lisum_gnss_recv_data_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_lisum_gnss_recv_data_format, sizeof(ulog_lisum_gnss_recv_data_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_lisum_gnss_recv_data(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_lisum_gnss_recv_data_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_lisum_gnss_recv_data_name, sizeof(ulog_lisum_gnss_recv_data_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_lisum_gnss_recv_data(ulog_t *log, ulog_msg_id_t id, const ulog_lisum_gnss_recv_data_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(double)
                    + sizeof(double)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
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

    /* Index of receiver */
    if (lfs_file_write(log->lfs, log->file, &src->dev_id, sizeof(src->dev_id)) < 0) {
        return 1;
    }

    /* Longitude [deg] */
    if (lfs_file_write(log->lfs, log->file, &src->lon, sizeof(src->lon)) < 0) {
        return 1;
    }

    /* Latitude [deg] */
    if (lfs_file_write(log->lfs, log->file, &src->lat, sizeof(src->lat)) < 0) {
        return 1;
    }

    /* Altitude [m] */
    if (lfs_file_write(log->lfs, log->file, &src->alt, sizeof(src->alt)) < 0) {
        return 1;
    }

    /* Heading [deg] */
    if (lfs_file_write(log->lfs, log->file, &src->head, sizeof(src->head)) < 0) {
        return 1;
    }

    /* RTK Heading [deg] */
    if (lfs_file_write(log->lfs, log->file, &src->head_rtk, sizeof(src->head_rtk)) < 0) {
        return 1;
    }

    /* Planar velocity [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vel_ne, sizeof(src->vel_ne)) < 0) {
        return 1;
    }

    /* Vertical velocity [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vel_d, sizeof(src->vel_d)) < 0) {
        return 1;
    }

    /* Fix Type Flag */
    if (lfs_file_write(log->lfs, log->file, &src->fix_type, sizeof(src->fix_type)) < 0) {
        return 1;
    }

    /* Carrier phase solution type */
    if (lfs_file_write(log->lfs, log->file, &src->carr_sol, sizeof(src->carr_sol)) < 0) {
        return 1;
    }

    /* RTK heading validity flag */
    if (lfs_file_write(log->lfs, log->file, &src->rtk_head_valid, sizeof(src->rtk_head_valid)) < 0) {
        return 1;
    }

    /* Number of satellites */
    if (lfs_file_write(log->lfs, log->file, &src->sv_num, sizeof(src->sv_num)) < 0) {
        return 1;
    }

    
    return 0;
}
