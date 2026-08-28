/**
 * @file    ulog_battery_status.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_BATTERY_STATUS_H
#define ULOG_BATTERY_STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_battery_status_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t id; /* Battery ID */
    uint8_t battery_function; /* Function of the battery */
    uint8_t type; /* Type (chemistry) of the battery */
    int16_t temperature; /* Temperature of the battery. INT16_MAX for unknown temperature. [cdegC] */
    uint16_t voltages[10]; /* Battery voltage of cells 1 to 10 (see voltages_ext for cells 11-14). Cells in this field above the valid cell count for this battery should have the UINT16_MAX value. If individual cell voltages are unknown or not measured for this battery, then the overall battery voltage should be filled in cell 0, with all others set to UINT16_MAX. If the voltage of the battery is greater than (UINT16_MAX - 1), then cell 0 should be set to (UINT16_MAX - 1), and cell 1 to the remaining voltage. This can be extended to multiple cells if the total voltage is greater than 2 * (UINT16_MAX - 1). [mV] */
    int16_t current_battery; /* Battery current, -1: autopilot does not measure the current [cA] */
    int32_t current_consumed; /* Consumed charge, -1: autopilot does not provide consumption estimate [mAh] */
    int32_t energy_consumed; /* Consumed energy, -1: autopilot does not provide energy consumption estimate [hJ] */
    int8_t battery_remaining; /* Remaining battery energy. Values: [0-100], -1: autopilot does not estimate the remaining battery. [%] */
    int32_t time_remaining; /* Remaining battery time, 0: autopilot does not provide remaining battery time estimate [s] */
    uint8_t charge_state; /* State for extent of discharge, provided by autopilot for warning or external reactions */
    uint16_t voltages_ext[4]; /* Battery voltages for cells 11 to 14. Cells above the valid cell count for this battery should have a value of 0, where zero indicates not supported (note, this is different than for the voltages field and allows empty byte truncation). If the measured value is 0 then 1 should be sent instead. [mV] */
    uint8_t mode; /* Battery mode. Default (0) is that battery mode reporting is not supported or battery is in normal-use mode. */
    uint32_t fault_bitmask; /* Fault/health indications. These should be set when charge_state is MAV_BATTERY_CHARGE_STATE_FAILED or MAV_BATTERY_CHARGE_STATE_UNHEALTHY (if not, fault reporting is not supported). */
    
} ulog_battery_status_t;

/**
 * Defines Battery Status message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_battery_status(ulog_t *log);

/**
 * Subscribe Battery Status message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_battery_status(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Battery Status message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_battery_status(ulog_t *log, ulog_msg_id_t id, const ulog_battery_status_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_BATTERY_STATUS_H */