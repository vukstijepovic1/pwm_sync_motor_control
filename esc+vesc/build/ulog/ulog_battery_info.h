/**
 * @file    ulog_battery_info.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_BATTERY_INFO_H
#define ULOG_BATTERY_INFO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_battery_info_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t id; /* Battery ID */
    uint8_t battery_function; /* Function of the battery. */
    uint8_t type; /* Type (chemistry) of the battery. */
    uint8_t state_of_health; /* State of Health (SOH) estimate. Typically 100% at the time of manufacture and will decrease over time and use. -1: field not provided. [%] */
    uint8_t cells_in_series; /* Number of battery cells in series. 0: field not provided. */
    uint16_t cycle_count; /* Lifetime count of the number of charge/discharge cycles (https://en.wikipedia.org/wiki/Charge_cycle). UINT16_MAX: field not provided. */
    uint16_t weight; /* Battery weight. 0: field not provided. [g] */
    float discharge_minimum_voltage; /* Minimum per-cell voltage when discharging. 0: field not provided. [V] */
    float charging_minimum_voltage; /* Minimum per-cell voltage when charging. 0: field not provided. [V] */
    float resting_minimum_voltage; /* Minimum per-cell voltage when resting. 0: field not provided. [V] */
    float charging_maximum_voltage; /* Maximum per-cell voltage when charged. 0: field not provided. [V] */
    float charging_maximum_current; /* Maximum pack continuous charge current. 0: field not provided. [A] */
    float nominal_voltage; /* Battery nominal voltage. Used for conversion between Wh and Ah. 0: field not provided. [V] */
    float discharge_maximum_current; /* Maximum pack discharge current. 0: field not provided. [A] */
    float discharge_maximum_burst_current; /* Maximum pack discharge burst current. 0: field not provided. [A] */
    float design_capacity; /* Fully charged design capacity. 0: field not provided. [Ah] */
    float full_charge_capacity; /* Predicted battery capacity when fully charged (accounting for battery degradation). NAN: field not provided. [Ah] */
    char manufacture_date[9]; /* Manufacture date (DDMMYYYY) in ASCII characters, 0 terminated. All 0: field not provided. */
    char serial_number[32]; /* Serial number in ASCII characters, 0 terminated. All 0: field not provided. */
    char name[50]; /* Battery device name. Formatted as manufacturer name then product name, separated with an underscore (in ASCII characters), 0 terminated. All 0: field not provided. */
    
} ulog_battery_info_t;

/**
 * Defines Battery Info message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_battery_info(ulog_t *log);

/**
 * Subscribe Battery Info message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_battery_info(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Battery Info message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_battery_info(ulog_t *log, ulog_msg_id_t id, const ulog_battery_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_BATTERY_INFO_H */