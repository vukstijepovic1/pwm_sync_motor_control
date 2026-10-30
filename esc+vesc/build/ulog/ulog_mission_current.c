/**
 * @file    ulog_mission_current.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_mission_current.h"
#include "ulog_def.h"

const char ulog_mission_current_format[] = "mission_current:uint64_t timestamp;uint16_t seq;uint16_t total;uint8_t mission_state;uint8_t mission_mode;uint32_t mission_id;uint32_t fence_id;uint32_t rally_points_id;";
const char ulog_mission_current_name[] = "mission_current";

int32_t ulog_format_mission_current(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_mission_current_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_mission_current_format, sizeof(ulog_mission_current_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_mission_current(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_mission_current_name) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_SUBSCRIPTION,
    };

    if(log->state == ULOG_STATE_DEFINITIONS_CREATED)
        log->state = ULOG_STATE_WRITING_DATA;

    if(log->state != ULOG_STATE_WRITING_DATA)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, &multi_id, sizeof(multi_id)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, &log->msg_cnt, sizeof(log->msg_cnt)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_mission_current_name, sizeof(ulog_mission_current_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_mission_current(ulog_t *log, ulog_msg_id_t id, const ulog_mission_current_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint32_t)
                    + sizeof(uint32_t)
                    + sizeof(uint32_t)
                    ,
        .msg_type = ULOG_DEF_MSG_TYPE_LOGGED_DATA,
    };

    if(log->state != ULOG_STATE_WRITING_DATA || id >= log->msg_cnt) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, &id, sizeof(id)) < 0) {
        return 1;
    }

    /* Timestamp [us] */
    if (lfs_file_write(log->lfs, log->file, &src->timestamp, sizeof(src->timestamp)) < 0) {
        return 1;
    }

    /* Sequence */
    if (lfs_file_write(log->lfs, log->file, &src->seq, sizeof(src->seq)) < 0) {
        return 1;
    }

    /* Total number of mission items on vehicle (on last item, sequence == total). If the autopilot stores its home location as part of the mission this will be excluded from the total. 0: Not supported, UINT16_MAX if no mission is present on the vehicle. */
    if (lfs_file_write(log->lfs, log->file, &src->total, sizeof(src->total)) < 0) {
        return 1;
    }

    /* Mission state machine state. MISSION_STATE_UNKNOWN if state reporting not supported. */
    if (lfs_file_write(log->lfs, log->file, &src->mission_state, sizeof(src->mission_state)) < 0) {
        return 1;
    }

    /* Vehicle is in a mode that can execute mission items or suspended. 0: Unknown, 1: In mission mode, 2: Suspended (not in mission mode). */
    if (lfs_file_write(log->lfs, log->file, &src->mission_mode, sizeof(src->mission_mode)) < 0) {
        return 1;
    }

    /* Id of current on-vehicle mission plan, or 0 if IDs are not supported or there is no mission loaded. GCS can use this to track changes to the mission plan type. The same value is returned on mission upload (in the MISSION_ACK). */
    if (lfs_file_write(log->lfs, log->file, &src->mission_id, sizeof(src->mission_id)) < 0) {
        return 1;
    }

    /* Id of current on-vehicle fence plan, or 0 if IDs are not supported or there is no fence loaded. GCS can use this to track changes to the fence plan type. The same value is returned on fence upload (in the MISSION_ACK). */
    if (lfs_file_write(log->lfs, log->file, &src->fence_id, sizeof(src->fence_id)) < 0) {
        return 1;
    }

    /* Id of current on-vehicle rally point plan, or 0 if IDs are not supported or there are no rally points loaded. GCS can use this to track changes to the rally point plan type. The same value is returned on rally point upload (in the MISSION_ACK). */
    if (lfs_file_write(log->lfs, log->file, &src->rally_points_id, sizeof(src->rally_points_id)) < 0) {
        return 1;
    }

    
    return 0;
}
