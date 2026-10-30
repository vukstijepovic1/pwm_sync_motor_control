/**
 * @file    ulog_set_home_position.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_SET_HOME_POSITION_H
#define ULOG_SET_HOME_POSITION_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_set_home_position_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t target_system; /* System ID. */
    int32_t latitude; /* Latitude (WGS84) [degE7] */
    int32_t longitude; /* Longitude (WGS84) [degE7] */
    int32_t altitude; /* Altitude (MSL). Positive for up. [mm] */
    float x; /* Local X position of this position in the local coordinate frame (NED) [m] */
    float y; /* Local Y position of this position in the local coordinate frame (NED) [m] */
    float z; /* Local Z position of this position in the local coordinate frame (NED: positive "down") [m] */
    float q[4]; /* World to surface normal and heading transformation of the takeoff position. Used to indicate the heading and slope of the ground */
    float approach_x; /* Local X position of the end of the approach vector. Multicopters should set this position based on their takeoff path. Grass-landing fixed wing aircraft should set it the same way as multicopters. Runway-landing fixed wing aircraft should set it to the opposite direction of the takeoff, assuming the takeoff happened from the threshold / touchdown zone. [m] */
    float approach_y; /* Local Y position of the end of the approach vector. Multicopters should set this position based on their takeoff path. Grass-landing fixed wing aircraft should set it the same way as multicopters. Runway-landing fixed wing aircraft should set it to the opposite direction of the takeoff, assuming the takeoff happened from the threshold / touchdown zone. [m] */
    float approach_z; /* Local Z position of the end of the approach vector. Multicopters should set this position based on their takeoff path. Grass-landing fixed wing aircraft should set it the same way as multicopters. Runway-landing fixed wing aircraft should set it to the opposite direction of the takeoff, assuming the takeoff happened from the threshold / touchdown zone. [m] */
    uint64_t time_usec; /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    
} ulog_set_home_position_t;

/**
 * Defines Set Home Position message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_set_home_position(ulog_t *log);

/**
 * Subscribe Set Home Position message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_set_home_position(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Set Home Position message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_set_home_position(ulog_t *log, ulog_msg_id_t id, const ulog_set_home_position_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_SET_HOME_POSITION_H */