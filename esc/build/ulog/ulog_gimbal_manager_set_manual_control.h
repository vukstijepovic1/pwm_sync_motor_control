/**
 * @file    ulog_gimbal_manager_set_manual_control.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_GIMBAL_MANAGER_SET_MANUAL_CONTROL_H
#define ULOG_GIMBAL_MANAGER_SET_MANUAL_CONTROL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_gimbal_manager_set_manual_control_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t target_system; /* System ID */
    uint8_t target_component; /* Component ID */
    uint32_t flags; /* High level gimbal manager flags. */
    uint8_t gimbal_device_id; /* Component ID of gimbal device to address (or 1-6 for non-MAVLink gimbal), 0 for all gimbal device components. Send command multiple times for more than one gimbal (but not all gimbals). */
    float pitch; /* Pitch angle unitless (-1..1, positive: up, negative: down, NaN to be ignored). */
    float yaw; /* Yaw angle unitless (-1..1, positive: to the right, negative: to the left, NaN to be ignored). */
    float pitch_rate; /* Pitch angular rate unitless (-1..1, positive: up, negative: down, NaN to be ignored). */
    float yaw_rate; /* Yaw angular rate unitless (-1..1, positive: to the right, negative: to the left, NaN to be ignored). */
    
} ulog_gimbal_manager_set_manual_control_t;

/**
 * Defines Gimbal Manager Set Manual Control message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_gimbal_manager_set_manual_control(ulog_t *log);

/**
 * Subscribe Gimbal Manager Set Manual Control message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_gimbal_manager_set_manual_control(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Gimbal Manager Set Manual Control message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_gimbal_manager_set_manual_control(ulog_t *log, ulog_msg_id_t id, const ulog_gimbal_manager_set_manual_control_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_GIMBAL_MANAGER_SET_MANUAL_CONTROL_H */