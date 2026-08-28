/**
 * @file    ulog_nav_controller_output.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_NAV_CONTROLLER_OUTPUT_H
#define ULOG_NAV_CONTROLLER_OUTPUT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_nav_controller_output_t {
    uint64_t timestamp; /* Timestamp [us] */
    float nav_roll; /* Current desired roll [deg] */
    float nav_pitch; /* Current desired pitch [deg] */
    int16_t nav_bearing; /* Current desired heading [deg] */
    int16_t target_bearing; /* Bearing to current waypoint/target [deg] */
    uint16_t wp_dist; /* Distance to active waypoint [m] */
    float alt_error; /* Current altitude error [m] */
    float aspd_error; /* Current airspeed error [m/s] */
    float xtrack_error; /* Current crosstrack error on x-y plane [m] */
    
} ulog_nav_controller_output_t;

/**
 * Defines Nav Controller Output message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_nav_controller_output(ulog_t *log);

/**
 * Subscribe Nav Controller Output message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_nav_controller_output(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Nav Controller Output message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_nav_controller_output(ulog_t *log, ulog_msg_id_t id, const ulog_nav_controller_output_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_NAV_CONTROLLER_OUTPUT_H */