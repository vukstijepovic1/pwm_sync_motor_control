/**
 * @file    ulog_illuminator_status.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_ILLUMINATOR_STATUS_H
#define ULOG_ILLUMINATOR_STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_illuminator_status_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint32_t uptime_ms; /* Time since the start-up of the illuminator in ms [ms] */
    uint8_t enable; /* 0: Illuminators OFF, 1: Illuminators ON */
    uint8_t mode_bitmask; /* Supported illuminator modes */
    uint32_t error_status; /* Errors */
    uint8_t mode; /* Illuminator mode */
    float brightness; /* Illuminator brightness [%] */
    float strobe_period; /* Illuminator strobing period in seconds [s] */
    float strobe_duty_cycle; /* Illuminator strobing duty cycle [%] */
    float temp_c; /* Temperature in Celsius */
    float min_strobe_period; /* Minimum strobing period in seconds [s] */
    float max_strobe_period; /* Maximum strobing period in seconds [s] */
    
} ulog_illuminator_status_t;

/**
 * Defines Illuminator Status message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_illuminator_status(ulog_t *log);

/**
 * Subscribe Illuminator Status message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_illuminator_status(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Illuminator Status message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_illuminator_status(ulog_t *log, ulog_msg_id_t id, const ulog_illuminator_status_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_ILLUMINATOR_STATUS_H */