/**
 * @file    ulog_high_latency2.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_HIGH_LATENCY2_H
#define ULOG_HIGH_LATENCY2_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_high_latency2_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t type; /* Type of the MAV (quadrotor, helicopter, etc.) */
    uint8_t autopilot; /* Autopilot type / class. Use MAV_AUTOPILOT_INVALID for components that are not flight controllers. */
    uint16_t custom_mode; /* A bitfield for use for autopilot-specific flags (2 byte version). */
    int32_t latitude; /* Latitude [degE7] */
    int32_t longitude; /* Longitude [degE7] */
    int16_t altitude; /* Altitude above mean sea level [m] */
    int16_t target_altitude; /* Altitude setpoint [m] */
    uint8_t heading; /* Heading [deg/2] */
    uint8_t target_heading; /* Heading setpoint [deg/2] */
    uint16_t target_distance; /* Distance to target waypoint or position [dam] */
    uint8_t throttle; /* Throttle [%] */
    uint8_t airspeed; /* Airspeed [m/s*5] */
    uint8_t airspeed_sp; /* Airspeed setpoint [m/s*5] */
    uint8_t groundspeed; /* Groundspeed [m/s*5] */
    uint8_t windspeed; /* Windspeed [m/s*5] */
    uint8_t wind_heading; /* Wind heading [deg/2] */
    uint8_t eph; /* Maximum error horizontal position since last message [dm] */
    uint8_t epv; /* Maximum error vertical position since last message [dm] */
    int8_t temperature_air; /* Air temperature from airspeed sensor [degC] */
    int8_t climb_rate; /* Maximum climb rate magnitude since last message [dm/s] */
    int8_t battery; /* Battery level (-1 if field not provided). [%] */
    uint16_t wp_num; /* Current waypoint number */
    uint16_t failure_flags; /* Bitmap of failure flags. */
    int8_t custom0; /* Field for custom payload. */
    int8_t custom1; /* Field for custom payload. */
    int8_t custom2; /* Field for custom payload. */
    
} ulog_high_latency2_t;

/**
 * Defines High Latency2 message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_high_latency2(ulog_t *log);

/**
 * Subscribe High Latency2 message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_high_latency2(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write High Latency2 message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_high_latency2(ulog_t *log, ulog_msg_id_t id, const ulog_high_latency2_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_HIGH_LATENCY2_H */