/**
 * @file    ulog_smart_battery_info.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_SMART_BATTERY_INFO_H
#define ULOG_SMART_BATTERY_INFO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_smart_battery_info_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t id; /* Battery ID */
    uint8_t battery_function; /* Function of the battery */
    uint8_t type; /* Type (chemistry) of the battery */
    int32_t capacity_full_specification; /* Capacity when full according to manufacturer, -1: field not provided. [mAh] */
    int32_t capacity_full; /* Capacity when full (accounting for battery degradation), -1: field not provided. [mAh] */
    uint16_t cycle_count; /* Charge/discharge cycle count. UINT16_MAX: field not provided. */
    char serial_number[16]; /* Serial number in ASCII characters, 0 terminated. All 0: field not provided. */
    char device_name[50]; /* Static device name in ASCII characters, 0 terminated. All 0: field not provided. Encode as manufacturer name then product name separated using an underscore. */
    uint16_t weight; /* Battery weight. 0: field not provided. [g] */
    uint16_t discharge_minimum_voltage; /* Minimum per-cell voltage when discharging. If not supplied set to UINT16_MAX value. [mV] */
    uint16_t charging_minimum_voltage; /* Minimum per-cell voltage when charging. If not supplied set to UINT16_MAX value. [mV] */
    uint16_t resting_minimum_voltage; /* Minimum per-cell voltage when resting. If not supplied set to UINT16_MAX value. [mV] */
    uint16_t charging_maximum_voltage; /* Maximum per-cell voltage when charged. 0: field not provided. [mV] */
    uint8_t cells_in_series; /* Number of battery cells in series. 0: field not provided. */
    uint32_t discharge_maximum_current; /* Maximum pack discharge current. 0: field not provided. [mA] */
    uint32_t discharge_maximum_burst_current; /* Maximum pack discharge burst current. 0: field not provided. [mA] */
    char manufacture_date[11]; /* Manufacture date (DD/MM/YYYY) in ASCII characters, 0 terminated. All 0: field not provided. */
    
} ulog_smart_battery_info_t;

/**
 * Defines Smart Battery Info message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_smart_battery_info(ulog_t *log);

/**
 * Subscribe Smart Battery Info message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_smart_battery_info(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Smart Battery Info message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_smart_battery_info(ulog_t *log, ulog_msg_id_t id, const ulog_smart_battery_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_SMART_BATTERY_INFO_H */