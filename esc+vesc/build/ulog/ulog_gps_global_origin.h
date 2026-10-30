/**
 * @file    ulog_gps_global_origin.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_GPS_GLOBAL_ORIGIN_H
#define ULOG_GPS_GLOBAL_ORIGIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_gps_global_origin_t {
    uint64_t timestamp; /* Timestamp [us] */
    int32_t latitude; /* Latitude (WGS84) [degE7] */
    int32_t longitude; /* Longitude (WGS84) [degE7] */
    int32_t altitude; /* Altitude (MSL). Positive for up. [mm] */
    uint64_t time_usec; /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    
} ulog_gps_global_origin_t;

/**
 * Defines Gps Global Origin message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_gps_global_origin(ulog_t *log);

/**
 * Subscribe Gps Global Origin message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_gps_global_origin(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Gps Global Origin message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_gps_global_origin(ulog_t *log, ulog_msg_id_t id, const ulog_gps_global_origin_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_GPS_GLOBAL_ORIGIN_H */