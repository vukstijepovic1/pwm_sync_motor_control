/**
 * @file    ulog_cellular_status.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_CELLULAR_STATUS_H
#define ULOG_CELLULAR_STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_cellular_status_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t status; /* Cellular modem status */
    uint8_t failure_reason; /* Failure reason when status in in CELLULAR_STATUS_FLAG_FAILED */
    uint8_t type; /* Cellular network radio type: gsm, cdma, lte... */
    uint8_t quality; /* Signal quality in percent. If unknown, set to UINT8_MAX */
    uint16_t mcc; /* Mobile country code. If unknown, set to UINT16_MAX */
    uint16_t mnc; /* Mobile network code. If unknown, set to UINT16_MAX */
    uint16_t lac; /* Location area code. If unknown, set to 0 */
    
} ulog_cellular_status_t;

/**
 * Defines Cellular Status message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_cellular_status(ulog_t *log);

/**
 * Subscribe Cellular Status message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_cellular_status(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Cellular Status message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_cellular_status(ulog_t *log, ulog_msg_id_t id, const ulog_cellular_status_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_CELLULAR_STATUS_H */