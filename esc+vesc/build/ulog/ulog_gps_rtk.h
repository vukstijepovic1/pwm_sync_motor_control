/**
 * @file    ulog_gps_rtk.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_GPS_RTK_H
#define ULOG_GPS_RTK_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_gps_rtk_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint32_t time_last_baseline_ms; /* Time since boot of last baseline message received. [ms] */
    uint8_t rtk_receiver_id; /* Identification of connected RTK receiver. */
    uint16_t wn; /* GPS Week Number of last baseline */
    uint32_t tow; /* GPS Time of Week of last baseline [ms] */
    uint8_t rtk_health; /* GPS-specific health report for RTK data. */
    uint8_t rtk_rate; /* Rate of baseline messages being received by GPS [Hz] */
    uint8_t nsats; /* Current number of sats used for RTK calculation. */
    uint8_t baseline_coords_type; /* Coordinate system of baseline */
    int32_t baseline_a_mm; /* Current baseline in ECEF x or NED north component. [mm] */
    int32_t baseline_b_mm; /* Current baseline in ECEF y or NED east component. [mm] */
    int32_t baseline_c_mm; /* Current baseline in ECEF z or NED down component. [mm] */
    uint32_t accuracy; /* Current estimate of baseline accuracy. */
    int32_t iar_num_hypotheses; /* Current number of integer ambiguity hypotheses. */
    
} ulog_gps_rtk_t;

/**
 * Defines Gps Rtk message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_gps_rtk(ulog_t *log);

/**
 * Subscribe Gps Rtk message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_gps_rtk(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Gps Rtk message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_gps_rtk(ulog_t *log, ulog_msg_id_t id, const ulog_gps_rtk_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_GPS_RTK_H */