/**
 * @file    ulog_gps_rtk.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_gps_rtk.h"
#include "ulog_def.h"

const char ulog_gps_rtk_format[] = "gps_rtk:uint64_t timestamp;uint32_t time_last_baseline_ms;uint8_t rtk_receiver_id;uint16_t wn;uint32_t tow;uint8_t rtk_health;uint8_t rtk_rate;uint8_t nsats;uint8_t baseline_coords_type;int32_t baseline_a_mm;int32_t baseline_b_mm;int32_t baseline_c_mm;uint32_t accuracy;int32_t iar_num_hypotheses;";
const char ulog_gps_rtk_name[] = "gps_rtk";

int32_t ulog_format_gps_rtk(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_gps_rtk_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_gps_rtk_format, sizeof(ulog_gps_rtk_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_gps_rtk(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_gps_rtk_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_gps_rtk_name, sizeof(ulog_gps_rtk_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_gps_rtk(ulog_t *log, ulog_msg_id_t id, const ulog_gps_rtk_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
                    + sizeof(uint8_t)
                    + sizeof(uint16_t)
                    + sizeof(uint32_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(uint32_t)
                    + sizeof(int32_t)
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

    /* Time since boot of last baseline message received. [ms] */
    if (lfs_file_write(log->lfs, log->file, &src->time_last_baseline_ms, sizeof(src->time_last_baseline_ms)) < 0) {
        return 1;
    }

    /* Identification of connected RTK receiver. */
    if (lfs_file_write(log->lfs, log->file, &src->rtk_receiver_id, sizeof(src->rtk_receiver_id)) < 0) {
        return 1;
    }

    /* GPS Week Number of last baseline */
    if (lfs_file_write(log->lfs, log->file, &src->wn, sizeof(src->wn)) < 0) {
        return 1;
    }

    /* GPS Time of Week of last baseline [ms] */
    if (lfs_file_write(log->lfs, log->file, &src->tow, sizeof(src->tow)) < 0) {
        return 1;
    }

    /* GPS-specific health report for RTK data. */
    if (lfs_file_write(log->lfs, log->file, &src->rtk_health, sizeof(src->rtk_health)) < 0) {
        return 1;
    }

    /* Rate of baseline messages being received by GPS [Hz] */
    if (lfs_file_write(log->lfs, log->file, &src->rtk_rate, sizeof(src->rtk_rate)) < 0) {
        return 1;
    }

    /* Current number of sats used for RTK calculation. */
    if (lfs_file_write(log->lfs, log->file, &src->nsats, sizeof(src->nsats)) < 0) {
        return 1;
    }

    /* Coordinate system of baseline */
    if (lfs_file_write(log->lfs, log->file, &src->baseline_coords_type, sizeof(src->baseline_coords_type)) < 0) {
        return 1;
    }

    /* Current baseline in ECEF x or NED north component. [mm] */
    if (lfs_file_write(log->lfs, log->file, &src->baseline_a_mm, sizeof(src->baseline_a_mm)) < 0) {
        return 1;
    }

    /* Current baseline in ECEF y or NED east component. [mm] */
    if (lfs_file_write(log->lfs, log->file, &src->baseline_b_mm, sizeof(src->baseline_b_mm)) < 0) {
        return 1;
    }

    /* Current baseline in ECEF z or NED down component. [mm] */
    if (lfs_file_write(log->lfs, log->file, &src->baseline_c_mm, sizeof(src->baseline_c_mm)) < 0) {
        return 1;
    }

    /* Current estimate of baseline accuracy. */
    if (lfs_file_write(log->lfs, log->file, &src->accuracy, sizeof(src->accuracy)) < 0) {
        return 1;
    }

    /* Current number of integer ambiguity hypotheses. */
    if (lfs_file_write(log->lfs, log->file, &src->iar_num_hypotheses, sizeof(src->iar_num_hypotheses)) < 0) {
        return 1;
    }

    
    return 0;
}
