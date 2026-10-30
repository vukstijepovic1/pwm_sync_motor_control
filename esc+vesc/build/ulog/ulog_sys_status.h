/**
 * @file    ulog_sys_status.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_SYS_STATUS_H
#define ULOG_SYS_STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_sys_status_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint32_t onboard_control_sensors_present; /* Bitmap showing which onboard controllers and sensors are present. Value of 0: not present. Value of 1: present. */
    uint32_t onboard_control_sensors_enabled; /* Bitmap showing which onboard controllers and sensors are enabled:  Value of 0: not enabled. Value of 1: enabled. */
    uint32_t onboard_control_sensors_health; /* Bitmap showing which onboard controllers and sensors have an error (or are operational). Value of 0: error. Value of 1: healthy. */
    uint16_t load; /* Maximum usage in percent of the mainloop time. Values: [0-1000] - should always be below 1000 [d%] */
    uint16_t voltage_battery; /* Battery voltage, UINT16_MAX: Voltage not sent by autopilot [mV] */
    int16_t current_battery; /* Battery current, -1: Current not sent by autopilot [cA] */
    int8_t battery_remaining; /* Battery energy remaining, -1: Battery remaining energy not sent by autopilot [%] */
    uint16_t drop_rate_comm; /* Communication drop rate, (UART, I2C, SPI, CAN), dropped packets on all links (packets that were corrupted on reception on the MAV) [c%] */
    uint16_t errors_comm; /* Communication errors (UART, I2C, SPI, CAN), dropped packets on all links (packets that were corrupted on reception on the MAV) */
    uint16_t errors_count1; /* Autopilot-specific errors */
    uint16_t errors_count2; /* Autopilot-specific errors */
    uint16_t errors_count3; /* Autopilot-specific errors */
    uint16_t errors_count4; /* Autopilot-specific errors */
    uint32_t onboard_control_sensors_present_extended; /* Bitmap showing which onboard controllers and sensors are present. Value of 0: not present. Value of 1: present. */
    uint32_t onboard_control_sensors_enabled_extended; /* Bitmap showing which onboard controllers and sensors are enabled:  Value of 0: not enabled. Value of 1: enabled. */
    uint32_t onboard_control_sensors_health_extended; /* Bitmap showing which onboard controllers and sensors have an error (or are operational). Value of 0: error. Value of 1: healthy. */
    
} ulog_sys_status_t;

/**
 * Defines Sys Status message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_sys_status(ulog_t *log);

/**
 * Subscribe Sys Status message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_sys_status(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Sys Status message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_sys_status(ulog_t *log, ulog_msg_id_t id, const ulog_sys_status_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_SYS_STATUS_H */