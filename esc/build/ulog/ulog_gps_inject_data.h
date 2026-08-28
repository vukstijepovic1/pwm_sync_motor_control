/**
 * @file    ulog_gps_inject_data.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_GPS_INJECT_DATA_H
#define ULOG_GPS_INJECT_DATA_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_gps_inject_data_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t target_system; /* System ID */
    uint8_t target_component; /* Component ID */
    uint8_t len; /* Data length [bytes] */
    uint8_t data[110]; /* Raw data (110 is enough for 12 satellites of RTCMv2) */
    
} ulog_gps_inject_data_t;

/**
 * Defines Gps Inject Data message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_gps_inject_data(ulog_t *log);

/**
 * Subscribe Gps Inject Data message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_gps_inject_data(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Gps Inject Data message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_gps_inject_data(ulog_t *log, ulog_msg_id_t id, const ulog_gps_inject_data_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_GPS_INJECT_DATA_H */