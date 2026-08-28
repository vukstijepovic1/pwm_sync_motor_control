/**
 * @file    ulog_manual_setpoint.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_MANUAL_SETPOINT_H
#define ULOG_MANUAL_SETPOINT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_manual_setpoint_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint32_t time_boot_ms; /* Timestamp (time since system boot). [ms] */
    float roll; /* Desired roll rate [rad/s] */
    float pitch; /* Desired pitch rate [rad/s] */
    float yaw; /* Desired yaw rate [rad/s] */
    float thrust; /* Collective thrust, normalized to 0 .. 1 */
    uint8_t mode_switch; /* Flight mode switch position, 0.. 255 */
    uint8_t manual_override_switch; /* Override mode switch position, 0.. 255 */
    
} ulog_manual_setpoint_t;

/**
 * Defines Manual Setpoint message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_manual_setpoint(ulog_t *log);

/**
 * Subscribe Manual Setpoint message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_manual_setpoint(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Manual Setpoint message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_manual_setpoint(ulog_t *log, ulog_msg_id_t id, const ulog_manual_setpoint_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_MANUAL_SETPOINT_H */