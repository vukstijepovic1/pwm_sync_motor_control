/**
 * @file    ulog_high_latency.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_HIGH_LATENCY_H
#define ULOG_HIGH_LATENCY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_high_latency_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t base_mode; /* Bitmap of enabled system modes. */
    uint32_t custom_mode; /* A bitfield for use for autopilot-specific flags. */
    uint8_t landed_state; /* The landed state. Is set to MAV_LANDED_STATE_UNDEFINED if landed state is unknown. */
    int16_t roll; /* roll [cdeg] */
    int16_t pitch; /* pitch [cdeg] */
    uint16_t heading; /* heading [cdeg] */
    int8_t throttle; /* throttle (percentage) [%] */
    int16_t heading_sp; /* heading setpoint [cdeg] */
    int32_t latitude; /* Latitude [degE7] */
    int32_t longitude; /* Longitude [degE7] */
    int16_t altitude_amsl; /* Altitude above mean sea level [m] */
    int16_t altitude_sp; /* Altitude setpoint relative to the home position [m] */
    uint8_t airspeed; /* airspeed [m/s] */
    uint8_t airspeed_sp; /* airspeed setpoint [m/s] */
    uint8_t groundspeed; /* groundspeed [m/s] */
    int8_t climb_rate; /* climb rate [m/s] */
    uint8_t gps_nsat; /* Number of satellites visible. If unknown, set to UINT8_MAX */
    uint8_t gps_fix_type; /* GPS Fix type. */
    uint8_t battery_remaining; /* Remaining battery (percentage) [%] */
    int8_t temperature; /* Autopilot temperature (degrees C) [degC] */
    int8_t temperature_air; /* Air temperature (degrees C) from airspeed sensor [degC] */
    uint8_t failsafe; /* failsafe (each bit represents a failsafe where 0=ok, 1=failsafe active (bit0:RC, bit1:batt, bit2:GPS, bit3:GCS, bit4:fence) */
    uint8_t wp_num; /* current waypoint number */
    uint16_t wp_distance; /* distance to target [m] */
    
} ulog_high_latency_t;

/**
 * Defines High Latency message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_high_latency(ulog_t *log);

/**
 * Subscribe High Latency message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_high_latency(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write High Latency message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_high_latency(ulog_t *log, ulog_msg_id_t id, const ulog_high_latency_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_HIGH_LATENCY_H */