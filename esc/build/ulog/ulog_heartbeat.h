/**
 * @file    ulog_heartbeat.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_HEARTBEAT_H
#define ULOG_HEARTBEAT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_heartbeat_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t type; /* Vehicle or component type. For a flight controller component the vehicle type (quadrotor, helicopter, etc.). For other components the component type (e.g. camera, gimbal, etc.). This should be used in preference to component id for identifying the component type. */
    uint8_t autopilot; /* Autopilot type / class. Use MAV_AUTOPILOT_INVALID for components that are not flight controllers. */
    uint8_t base_mode; /* System mode bitmap. */
    uint32_t custom_mode; /* A bitfield for use for autopilot-specific flags */
    uint8_t system_status; /* System status flag. */
    
} ulog_heartbeat_t;

/**
 * Defines Heartbeat message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_heartbeat(ulog_t *log);

/**
 * Subscribe Heartbeat message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_heartbeat(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Heartbeat message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_heartbeat(ulog_t *log, ulog_msg_id_t id, const ulog_heartbeat_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_HEARTBEAT_H */