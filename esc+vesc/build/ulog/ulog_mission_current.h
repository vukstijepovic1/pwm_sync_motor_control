/**
 * @file    ulog_mission_current.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_MISSION_CURRENT_H
#define ULOG_MISSION_CURRENT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_mission_current_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint16_t seq; /* Sequence */
    uint16_t total; /* Total number of mission items on vehicle (on last item, sequence == total). If the autopilot stores its home location as part of the mission this will be excluded from the total. 0: Not supported, UINT16_MAX if no mission is present on the vehicle. */
    uint8_t mission_state; /* Mission state machine state. MISSION_STATE_UNKNOWN if state reporting not supported. */
    uint8_t mission_mode; /* Vehicle is in a mode that can execute mission items or suspended. 0: Unknown, 1: In mission mode, 2: Suspended (not in mission mode). */
    uint32_t mission_id; /* Id of current on-vehicle mission plan, or 0 if IDs are not supported or there is no mission loaded. GCS can use this to track changes to the mission plan type. The same value is returned on mission upload (in the MISSION_ACK). */
    uint32_t fence_id; /* Id of current on-vehicle fence plan, or 0 if IDs are not supported or there is no fence loaded. GCS can use this to track changes to the fence plan type. The same value is returned on fence upload (in the MISSION_ACK). */
    uint32_t rally_points_id; /* Id of current on-vehicle rally point plan, or 0 if IDs are not supported or there are no rally points loaded. GCS can use this to track changes to the rally point plan type. The same value is returned on rally point upload (in the MISSION_ACK). */
    
} ulog_mission_current_t;

/**
 * Defines Mission Current message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_mission_current(ulog_t *log);

/**
 * Subscribe Mission Current message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_mission_current(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Mission Current message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_mission_current(ulog_t *log, ulog_msg_id_t id, const ulog_mission_current_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_MISSION_CURRENT_H */