/**
 * @file    ulog_fuel_status.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_FUEL_STATUS_H
#define ULOG_FUEL_STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_fuel_status_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t id; /* Fuel ID. Must match ID of other messages for same fuel system, such as BATTERY_STATUS_V2. */
    float maximum_fuel; /* Capacity when full. Must be provided. */
    float consumed_fuel; /* Consumed fuel (measured). This value should not be inferred: if not measured set to NaN. NaN: field not provided. */
    float remaining_fuel; /* Remaining fuel until empty (measured). The value should not be inferred: if not measured set to NaN. NaN: field not provided. */
    uint8_t percent_remaining; /* Percentage of remaining fuel, relative to full. Values: [0-100], UINT8_MAX: field not provided. [%] */
    float flow_rate; /* Positive value when emptying/using, and negative if filling/replacing. NaN: field not provided. */
    float temperature; /* Fuel temperature. NaN: field not provided. [K] */
    uint32_t fuel_type; /* Fuel type. Defines units for fuel capacity and consumption fields above. */
    
} ulog_fuel_status_t;

/**
 * Defines Fuel Status message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_fuel_status(ulog_t *log);

/**
 * Subscribe Fuel Status message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_fuel_status(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Fuel Status message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_fuel_status(ulog_t *log, ulog_msg_id_t id, const ulog_fuel_status_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_FUEL_STATUS_H */