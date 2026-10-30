/**
 * @file    ulog_mag_cal_report.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_mag_cal_report.h"
#include "ulog_def.h"

const char ulog_mag_cal_report_format[] = "mag_cal_report:uint64_t timestamp;uint8_t compass_id;uint8_t cal_mask;uint8_t cal_status;uint8_t autosaved;float fitness;float ofs_x;float ofs_y;float ofs_z;float diag_x;float diag_y;float diag_z;float offdiag_x;float offdiag_y;float offdiag_z;float orientation_confidence;uint8_t old_orientation;uint8_t new_orientation;float scale_factor;";
const char ulog_mag_cal_report_name[] = "mag_cal_report";

int32_t ulog_format_mag_cal_report(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_mag_cal_report_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_mag_cal_report_format, sizeof(ulog_mag_cal_report_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_mag_cal_report(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_mag_cal_report_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_mag_cal_report_name, sizeof(ulog_mag_cal_report_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_mag_cal_report(ulog_t *log, ulog_msg_id_t id, const ulog_mag_cal_report_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
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
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
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

    /* Compass being calibrated. */
    if (lfs_file_write(log->lfs, log->file, &src->compass_id, sizeof(src->compass_id)) < 0) {
        return 1;
    }

    /* Bitmask of compasses being calibrated. */
    if (lfs_file_write(log->lfs, log->file, &src->cal_mask, sizeof(src->cal_mask)) < 0) {
        return 1;
    }

    /* Calibration Status. */
    if (lfs_file_write(log->lfs, log->file, &src->cal_status, sizeof(src->cal_status)) < 0) {
        return 1;
    }

    /* 0=requires a MAV_CMD_DO_ACCEPT_MAG_CAL, 1=saved to parameters. */
    if (lfs_file_write(log->lfs, log->file, &src->autosaved, sizeof(src->autosaved)) < 0) {
        return 1;
    }

    /* RMS milligauss residuals. [mgauss] */
    if (lfs_file_write(log->lfs, log->file, &src->fitness, sizeof(src->fitness)) < 0) {
        return 1;
    }

    /* X offset. */
    if (lfs_file_write(log->lfs, log->file, &src->ofs_x, sizeof(src->ofs_x)) < 0) {
        return 1;
    }

    /* Y offset. */
    if (lfs_file_write(log->lfs, log->file, &src->ofs_y, sizeof(src->ofs_y)) < 0) {
        return 1;
    }

    /* Z offset. */
    if (lfs_file_write(log->lfs, log->file, &src->ofs_z, sizeof(src->ofs_z)) < 0) {
        return 1;
    }

    /* X diagonal (matrix 11). */
    if (lfs_file_write(log->lfs, log->file, &src->diag_x, sizeof(src->diag_x)) < 0) {
        return 1;
    }

    /* Y diagonal (matrix 22). */
    if (lfs_file_write(log->lfs, log->file, &src->diag_y, sizeof(src->diag_y)) < 0) {
        return 1;
    }

    /* Z diagonal (matrix 33). */
    if (lfs_file_write(log->lfs, log->file, &src->diag_z, sizeof(src->diag_z)) < 0) {
        return 1;
    }

    /* X off-diagonal (matrix 12 and 21). */
    if (lfs_file_write(log->lfs, log->file, &src->offdiag_x, sizeof(src->offdiag_x)) < 0) {
        return 1;
    }

    /* Y off-diagonal (matrix 13 and 31). */
    if (lfs_file_write(log->lfs, log->file, &src->offdiag_y, sizeof(src->offdiag_y)) < 0) {
        return 1;
    }

    /* Z off-diagonal (matrix 32 and 23). */
    if (lfs_file_write(log->lfs, log->file, &src->offdiag_z, sizeof(src->offdiag_z)) < 0) {
        return 1;
    }

    /* Confidence in orientation (higher is better). */
    if (lfs_file_write(log->lfs, log->file, &src->orientation_confidence, sizeof(src->orientation_confidence)) < 0) {
        return 1;
    }

    /* orientation before calibration. */
    if (lfs_file_write(log->lfs, log->file, &src->old_orientation, sizeof(src->old_orientation)) < 0) {
        return 1;
    }

    /* orientation after calibration. */
    if (lfs_file_write(log->lfs, log->file, &src->new_orientation, sizeof(src->new_orientation)) < 0) {
        return 1;
    }

    /* field radius correction factor */
    if (lfs_file_write(log->lfs, log->file, &src->scale_factor, sizeof(src->scale_factor)) < 0) {
        return 1;
    }

    
    return 0;
}
