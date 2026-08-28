/**
 * @file    ulog_time_estimate_to_target.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_TIME_ESTIMATE_TO_TARGET_H
#define ULOG_TIME_ESTIMATE_TO_TARGET_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_time_estimate_to_target_t {
    uint64_t timestamp; /* Timestamp [us] */
    int32_t safe_return; /* Estimated time to complete the vehicle's configured "safe return" action from its current position (e.g. RTL, Smart RTL, etc.). -1 indicates that the vehicle is landed, or that no time estimate available. [s] */
    int32_t land; /* Estimated time for vehicle to complete the LAND action from its current position. -1 indicates that the vehicle is landed, or that no time estimate available. [s] */
    int32_t mission_next_item; /* Estimated time for reaching/completing the currently active mission item. -1 means no time estimate available. [s] */
    int32_t mission_end; /* Estimated time for completing the current mission. -1 means no mission active and/or no estimate available. [s] */
    int32_t commanded_action; /* Estimated time for completing the current commanded action (i.e. Go To, Takeoff, Land, etc.). -1 means no action active and/or no estimate available. [s] */
    
} ulog_time_estimate_to_target_t;

/**
 * Defines Time Estimate To Target message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_time_estimate_to_target(ulog_t *log);

/**
 * Subscribe Time Estimate To Target message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_time_estimate_to_target(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Time Estimate To Target message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_time_estimate_to_target(ulog_t *log, ulog_msg_id_t id, const ulog_time_estimate_to_target_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_TIME_ESTIMATE_TO_TARGET_H */