/**
 * @file    ulog_winch_status.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_WINCH_STATUS_H
#define ULOG_WINCH_STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_winch_status_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t time_usec; /* Timestamp (synced to UNIX time or since system boot). [us] */
    float line_length; /* Length of line released. NaN if unknown [m] */
    float speed; /* Speed line is being released or retracted. Positive values if being released, negative values if being retracted, NaN if unknown [m/s] */
    float tension; /* Tension on the line. NaN if unknown [kg] */
    float voltage; /* Voltage of the battery supplying the winch. NaN if unknown [V] */
    float current; /* Current draw from the winch. NaN if unknown [A] */
    int16_t temperature; /* Temperature of the motor. INT16_MAX if unknown [degC] */
    uint32_t status; /* Status flags */
    
} ulog_winch_status_t;

/**
 * Defines Winch Status message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_winch_status(ulog_t *log);

/**
 * Subscribe Winch Status message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_winch_status(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Winch Status message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_winch_status(ulog_t *log, ulog_msg_id_t id, const ulog_winch_status_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_WINCH_STATUS_H */