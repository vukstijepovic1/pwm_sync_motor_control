/**
 * @file    ulog_autopilot_state_for_gimbal_device.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_AUTOPILOT_STATE_FOR_GIMBAL_DEVICE_H
#define ULOG_AUTOPILOT_STATE_FOR_GIMBAL_DEVICE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_autopilot_state_for_gimbal_device_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t target_system; /* System ID */
    uint8_t target_component; /* Component ID */
    uint64_t time_boot_us; /* Timestamp (time since system boot). [us] */
    float q[4]; /* Quaternion components of autopilot attitude: w, x, y, z (1 0 0 0 is the null-rotation, Hamilton convention). */
    uint32_t q_estimated_delay_us; /* Estimated delay of the attitude data. 0 if unknown. [us] */
    float vx; /* X Speed in NED (North, East, Down). NAN if unknown. [m/s] */
    float vy; /* Y Speed in NED (North, East, Down). NAN if unknown. [m/s] */
    float vz; /* Z Speed in NED (North, East, Down). NAN if unknown. [m/s] */
    uint32_t v_estimated_delay_us; /* Estimated delay of the speed data. 0 if unknown. [us] */
    float feed_forward_angular_velocity_z; /* Feed forward Z component of angular velocity (positive: yawing to the right). NaN to be ignored. This is to indicate if the autopilot is actively yawing. [rad/s] */
    uint16_t estimator_status; /* Bitmap indicating which estimator outputs are valid. */
    uint8_t landed_state; /* The landed state. Is set to MAV_LANDED_STATE_UNDEFINED if landed state is unknown. */
    float angular_velocity_z; /* Z component of angular velocity in NED (North, East, Down). NaN if unknown. [rad/s] */
    
} ulog_autopilot_state_for_gimbal_device_t;

/**
 * Defines Autopilot State For Gimbal Device message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_autopilot_state_for_gimbal_device(ulog_t *log);

/**
 * Subscribe Autopilot State For Gimbal Device message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_autopilot_state_for_gimbal_device(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Autopilot State For Gimbal Device message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_autopilot_state_for_gimbal_device(ulog_t *log, ulog_msg_id_t id, const ulog_autopilot_state_for_gimbal_device_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_AUTOPILOT_STATE_FOR_GIMBAL_DEVICE_H */