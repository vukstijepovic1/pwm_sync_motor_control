/**
 * @file    ulog_mission_count.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_MISSION_COUNT_H
#define ULOG_MISSION_COUNT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_mission_count_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t target_system; /* System ID */
    uint8_t target_component; /* Component ID */
    uint16_t count; /* Number of mission items in the sequence */
    uint8_t mission_type; /* Mission type. */
    uint32_t opaque_id; /* Id of current on-vehicle mission, fence, or rally point plan (on download from vehicle).
        This field is used when downloading a plan from a vehicle to a GCS.
        0 on upload to the vehicle from GCS.
        0 if plan ids are not supported.
        The current on-vehicle plan ids are streamed in `MISSION_CURRENT`, allowing a GCS to determine if any part of the plan has changed and needs to be re-uploaded.
        The ids are recalculated by the vehicle when any part of the on-vehicle plan changes (when a new plan is uploaded, the vehicle returns the new id to the GCS in MISSION_ACK).
       */
    
} ulog_mission_count_t;

/**
 * Defines Mission Count message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_mission_count(ulog_t *log);

/**
 * Subscribe Mission Count message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_mission_count(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Mission Count message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_mission_count(ulog_t *log, ulog_msg_id_t id, const ulog_mission_count_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_MISSION_COUNT_H */