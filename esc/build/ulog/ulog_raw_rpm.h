/**
 * @file    ulog_raw_rpm.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_RAW_RPM_H
#define ULOG_RAW_RPM_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_raw_rpm_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t index; /* Index of this RPM sensor (0-indexed) */
    float frequency; /* Indicated rate [rpm] */
    
} ulog_raw_rpm_t;

/**
 * Defines Raw Rpm message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_raw_rpm(ulog_t *log);

/**
 * Subscribe Raw Rpm message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_raw_rpm(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Raw Rpm message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_raw_rpm(ulog_t *log, ulog_msg_id_t id, const ulog_raw_rpm_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_RAW_RPM_H */