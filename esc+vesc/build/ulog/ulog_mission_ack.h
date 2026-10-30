/**
 * @file    ulog_mission_ack.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_MISSION_ACK_H
#define ULOG_MISSION_ACK_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_mission_ack_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t target_system; /* System ID */
    uint8_t target_component; /* Component ID */
    uint8_t type; /* Mission result. */
    uint8_t mission_type; /* Mission type. */
    uint32_t opaque_id; /* Id of new on-vehicle mission, fence, or rally point plan (on upload to vehicle).
        The id is calculated and returned by a vehicle when a new plan is uploaded by a GCS.
        The only requirement on the id is that it must change when there is any change to the on-vehicle plan type (there is no requirement that the id be globally unique).
        0 on download from the vehicle to the GCS (on download the ID is set in MISSION_COUNT).
        0 if plan ids are not supported.
        The current on-vehicle plan ids are streamed in `MISSION_CURRENT`, allowing a GCS to determine if any part of the plan has changed and needs to be re-uploaded.
       */
    
} ulog_mission_ack_t;

/**
 * Defines Mission Ack message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_mission_ack(ulog_t *log);

/**
 * Subscribe Mission Ack message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_mission_ack(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Mission Ack message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_mission_ack(ulog_t *log, ulog_msg_id_t id, const ulog_mission_ack_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_MISSION_ACK_H */