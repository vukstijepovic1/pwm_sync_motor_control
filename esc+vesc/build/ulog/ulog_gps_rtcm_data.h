/**
 * @file    ulog_gps_rtcm_data.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_GPS_RTCM_DATA_H
#define ULOG_GPS_RTCM_DATA_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_gps_rtcm_data_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t flags; /* LSB: 1 means message is fragmented, next 2 bits are the fragment ID, the remaining 5 bits are used for the sequence ID. Messages are only to be flushed to the GPS when the entire message has been reconstructed on the autopilot. The fragment ID specifies which order the fragments should be assembled into a buffer, while the sequence ID is used to detect a mismatch between different buffers. The buffer is considered fully reconstructed when either all 4 fragments are present, or all the fragments before the first fragment with a non full payload is received. This management is used to ensure that normal GPS operation doesn't corrupt RTCM data, and to recover from a unreliable transport delivery order. */
    uint8_t len; /* data length [bytes] */
    uint8_t data[180]; /* RTCM message (may be fragmented) */
    
} ulog_gps_rtcm_data_t;

/**
 * Defines Gps Rtcm Data message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_gps_rtcm_data(ulog_t *log);

/**
 * Subscribe Gps Rtcm Data message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_gps_rtcm_data(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Gps Rtcm Data message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_gps_rtcm_data(ulog_t *log, ulog_msg_id_t id, const ulog_gps_rtcm_data_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_GPS_RTCM_DATA_H */