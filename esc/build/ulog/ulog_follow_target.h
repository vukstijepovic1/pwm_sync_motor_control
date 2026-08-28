/**
 * @file    ulog_follow_target.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_FOLLOW_TARGET_H
#define ULOG_FOLLOW_TARGET_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_follow_target_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t est_capabilities; /* bit positions for tracker reporting capabilities (POS = 0, VEL = 1, ACCEL = 2, ATT + RATES = 3) */
    int32_t lat; /* Latitude (WGS84) [degE7] */
    int32_t lon; /* Longitude (WGS84) [degE7] */
    float alt; /* Altitude (MSL) [m] */
    float vel[3]; /* target velocity (0,0,0) for unknown [m/s] */
    float acc[3]; /* linear target acceleration (0,0,0) for unknown [m/s/s] */
    float attitude_q[4]; /* (0 0 0 0 for unknown) */
    float rates[3]; /* (0 0 0 for unknown) */
    float position_cov[3]; /* eph epv */
    uint64_t custom_state; /* button states or switches of a tracker device */
    
} ulog_follow_target_t;

/**
 * Defines Follow Target message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_follow_target(ulog_t *log);

/**
 * Subscribe Follow Target message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_follow_target(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Follow Target message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_follow_target(ulog_t *log, ulog_msg_id_t id, const ulog_follow_target_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_FOLLOW_TARGET_H */