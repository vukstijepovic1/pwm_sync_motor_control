/**
 * @file    ulog_mag_cal_report.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_MAG_CAL_REPORT_H
#define ULOG_MAG_CAL_REPORT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_mag_cal_report_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t compass_id; /* Compass being calibrated. */
    uint8_t cal_mask; /* Bitmask of compasses being calibrated. */
    uint8_t cal_status; /* Calibration Status. */
    uint8_t autosaved; /* 0=requires a MAV_CMD_DO_ACCEPT_MAG_CAL, 1=saved to parameters. */
    float fitness; /* RMS milligauss residuals. [mgauss] */
    float ofs_x; /* X offset. */
    float ofs_y; /* Y offset. */
    float ofs_z; /* Z offset. */
    float diag_x; /* X diagonal (matrix 11). */
    float diag_y; /* Y diagonal (matrix 22). */
    float diag_z; /* Z diagonal (matrix 33). */
    float offdiag_x; /* X off-diagonal (matrix 12 and 21). */
    float offdiag_y; /* Y off-diagonal (matrix 13 and 31). */
    float offdiag_z; /* Z off-diagonal (matrix 32 and 23). */
    float orientation_confidence; /* Confidence in orientation (higher is better). */
    uint8_t old_orientation; /* orientation before calibration. */
    uint8_t new_orientation; /* orientation after calibration. */
    float scale_factor; /* field radius correction factor */
    
} ulog_mag_cal_report_t;

/**
 * Defines Mag Cal Report message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_mag_cal_report(ulog_t *log);

/**
 * Subscribe Mag Cal Report message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_mag_cal_report(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Mag Cal Report message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_mag_cal_report(ulog_t *log, ulog_msg_id_t id, const ulog_mag_cal_report_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_MAG_CAL_REPORT_H */