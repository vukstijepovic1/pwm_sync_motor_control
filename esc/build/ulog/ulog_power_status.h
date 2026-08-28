/**
 * @file    ulog_power_status.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_POWER_STATUS_H
#define ULOG_POWER_STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_power_status_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint16_t Vcc; /* 5V rail voltage. [mV] */
    uint16_t Vservo; /* Servo rail voltage. [mV] */
    uint16_t flags; /* Bitmap of power supply status flags. */
    
} ulog_power_status_t;

/**
 * Defines Power Status message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_power_status(ulog_t *log);

/**
 * Subscribe Power Status message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_power_status(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Power Status message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_power_status(ulog_t *log, ulog_msg_id_t id, const ulog_power_status_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_POWER_STATUS_H */