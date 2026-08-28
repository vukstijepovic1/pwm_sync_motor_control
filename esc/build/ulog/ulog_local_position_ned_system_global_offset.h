/**
 * @file    ulog_local_position_ned_system_global_offset.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_LOCAL_POSITION_NED_SYSTEM_GLOBAL_OFFSET_H
#define ULOG_LOCAL_POSITION_NED_SYSTEM_GLOBAL_OFFSET_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_local_position_ned_system_global_offset_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint32_t time_boot_ms; /* Timestamp (time since system boot). [ms] */
    float x; /* X Position [m] */
    float y; /* Y Position [m] */
    float z; /* Z Position [m] */
    float roll; /* Roll [rad] */
    float pitch; /* Pitch [rad] */
    float yaw; /* Yaw [rad] */
    
} ulog_local_position_ned_system_global_offset_t;

/**
 * Defines Local Position Ned System Global Offset message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_local_position_ned_system_global_offset(ulog_t *log);

/**
 * Subscribe Local Position Ned System Global Offset message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_local_position_ned_system_global_offset(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Local Position Ned System Global Offset message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_local_position_ned_system_global_offset(ulog_t *log, ulog_msg_id_t id, const ulog_local_position_ned_system_global_offset_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_LOCAL_POSITION_NED_SYSTEM_GLOBAL_OFFSET_H */