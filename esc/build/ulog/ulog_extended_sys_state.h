/**
 * @file    ulog_extended_sys_state.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_EXTENDED_SYS_STATE_H
#define ULOG_EXTENDED_SYS_STATE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_extended_sys_state_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t vtol_state; /* The VTOL state if applicable. Is set to MAV_VTOL_STATE_UNDEFINED if UAV is not in VTOL configuration. */
    uint8_t landed_state; /* The landed state. Is set to MAV_LANDED_STATE_UNDEFINED if landed state is unknown. */
    
} ulog_extended_sys_state_t;

/**
 * Defines Extended Sys State message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_extended_sys_state(ulog_t *log);

/**
 * Subscribe Extended Sys State message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_extended_sys_state(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Extended Sys State message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_extended_sys_state(ulog_t *log, ulog_msg_id_t id, const ulog_extended_sys_state_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_EXTENDED_SYS_STATE_H */