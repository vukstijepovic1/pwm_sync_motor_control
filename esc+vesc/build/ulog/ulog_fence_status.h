/**
 * @file    ulog_fence_status.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_FENCE_STATUS_H
#define ULOG_FENCE_STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_fence_status_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t breach_status; /* Breach status (0 if currently inside fence, 1 if outside). */
    uint16_t breach_count; /* Number of fence breaches. */
    uint8_t breach_type; /* Last breach type. */
    uint32_t breach_time; /* Time (since boot) of last breach. [ms] */
    uint8_t breach_mitigation; /* Active action to prevent fence breach */
    
} ulog_fence_status_t;

/**
 * Defines Fence Status message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_fence_status(ulog_t *log);

/**
 * Subscribe Fence Status message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_fence_status(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Fence Status message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_fence_status(ulog_t *log, ulog_msg_id_t id, const ulog_fence_status_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_FENCE_STATUS_H */