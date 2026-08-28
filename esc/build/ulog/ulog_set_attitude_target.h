/**
 * @file    ulog_set_attitude_target.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_SET_ATTITUDE_TARGET_H
#define ULOG_SET_ATTITUDE_TARGET_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_set_attitude_target_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint32_t time_boot_ms; /* Timestamp (time since system boot). [ms] */
    uint8_t target_system; /* System ID */
    uint8_t target_component; /* Component ID */
    uint8_t type_mask; /* Bitmap to indicate which dimensions should be ignored by the vehicle. */
    float q[4]; /* Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0) from MAV_FRAME_LOCAL_NED to MAV_FRAME_BODY_FRD */
    float body_roll_rate; /* Body roll rate [rad/s] */
    float body_pitch_rate; /* Body pitch rate [rad/s] */
    float body_yaw_rate; /* Body yaw rate [rad/s] */
    float thrust; /* Collective thrust, normalized to 0 .. 1 (-1 .. 1 for vehicles capable of reverse trust) */
    float thrust_body[3]; /* 3D thrust setpoint in the body NED frame, normalized to -1 .. 1 */
    
} ulog_set_attitude_target_t;

/**
 * Defines Set Attitude Target message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_set_attitude_target(ulog_t *log);

/**
 * Subscribe Set Attitude Target message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_set_attitude_target(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Set Attitude Target message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_set_attitude_target(ulog_t *log, ulog_msg_id_t id, const ulog_set_attitude_target_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_SET_ATTITUDE_TARGET_H */