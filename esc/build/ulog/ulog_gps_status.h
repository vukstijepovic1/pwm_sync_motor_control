/**
 * @file    ulog_gps_status.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_GPS_STATUS_H
#define ULOG_GPS_STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_gps_status_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t satellites_visible; /* Number of satellites visible */
    uint8_t satellite_prn[20]; /* Global satellite ID */
    uint8_t satellite_used[20]; /* 0: Satellite not used, 1: used for localization */
    uint8_t satellite_elevation[20]; /* Elevation (0: right on top of receiver, 90: on the horizon) of satellite [deg] */
    uint8_t satellite_azimuth[20]; /* Direction of satellite, 0: 0 deg, 255: 360 deg. [deg] */
    uint8_t satellite_snr[20]; /* Signal to noise ratio of satellite [dB] */
    
} ulog_gps_status_t;

/**
 * Defines Gps Status message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_gps_status(ulog_t *log);

/**
 * Subscribe Gps Status message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_gps_status(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Gps Status message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_gps_status(ulog_t *log, ulog_msg_id_t id, const ulog_gps_status_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_GPS_STATUS_H */