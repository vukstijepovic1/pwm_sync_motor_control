/**
 * @file    ulog_isbd_link_status.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_ISBD_LINK_STATUS_H
#define ULOG_ISBD_LINK_STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_isbd_link_status_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t last_heartbeat; /* Timestamp of the last successful sbd session. The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    uint16_t failed_sessions; /* Number of failed SBD sessions. */
    uint16_t successful_sessions; /* Number of successful SBD sessions. */
    uint8_t signal_quality; /* Signal quality equal to the number of bars displayed on the ISU signal strength indicator. Range is 0 to 5, where 0 indicates no signal and 5 indicates maximum signal strength. */
    uint8_t ring_pending; /* 1: Ring call pending, 0: No call pending. */
    uint8_t tx_session_pending; /* 1: Transmission session pending, 0: No transmission session pending. */
    uint8_t rx_session_pending; /* 1: Receiving session pending, 0: No receiving session pending. */
    
} ulog_isbd_link_status_t;

/**
 * Defines Isbd Link Status message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_isbd_link_status(ulog_t *log);

/**
 * Subscribe Isbd Link Status message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_isbd_link_status(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Isbd Link Status message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_isbd_link_status(ulog_t *log, ulog_msg_id_t id, const ulog_isbd_link_status_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_ISBD_LINK_STATUS_H */