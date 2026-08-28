/**
 * @file    ulog_attitude.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_ATTITUDE_H
#define ULOG_ATTITUDE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_attitude_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint32_t time_boot_ms; /* Timestamp (time since system boot). [ms] */
    float roll; /* Roll angle (-pi..+pi) [rad] */
    float pitch; /* Pitch angle (-pi..+pi) [rad] */
    float yaw; /* Yaw angle (-pi..+pi) [rad] */
    float rollspeed; /* Roll angular speed [rad/s] */
    float pitchspeed; /* Pitch angular speed [rad/s] */
    float yawspeed; /* Yaw angular speed [rad/s] */
    
} ulog_attitude_t;

/**
 * Defines Attitude message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_attitude(ulog_t *log);

/**
 * Subscribe Attitude message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_attitude(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Attitude message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_attitude(ulog_t *log, ulog_msg_id_t id, const ulog_attitude_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_ATTITUDE_H */