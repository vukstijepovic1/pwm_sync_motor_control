/**
 * @file    ulog_scaled_pressure.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_SCALED_PRESSURE_H
#define ULOG_SCALED_PRESSURE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_scaled_pressure_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint32_t time_boot_ms; /* Timestamp (time since system boot). [ms] */
    float press_abs; /* Absolute pressure [hPa] */
    float press_diff; /* Differential pressure 1 [hPa] */
    int16_t temperature; /* Absolute pressure temperature [cdegC] */
    int16_t temperature_press_diff; /* Differential pressure temperature (0, if not available). Report values of 0 (or 1) as 1 cdegC. [cdegC] */
    
} ulog_scaled_pressure_t;

/**
 * Defines Scaled Pressure message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_scaled_pressure(ulog_t *log);

/**
 * Subscribe Scaled Pressure message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_scaled_pressure(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Scaled Pressure message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_scaled_pressure(ulog_t *log, ulog_msg_id_t id, const ulog_scaled_pressure_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_SCALED_PRESSURE_H */