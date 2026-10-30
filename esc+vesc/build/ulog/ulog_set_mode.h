/**
 * @file    ulog_set_mode.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_SET_MODE_H
#define ULOG_SET_MODE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_set_mode_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t target_system; /* The system setting the mode */
    uint8_t base_mode; /* The new base mode. */
    uint32_t custom_mode; /* The new autopilot-specific mode. This field can be ignored by an autopilot. */
    
} ulog_set_mode_t;

/**
 * Defines Set Mode message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_set_mode(ulog_t *log);

/**
 * Subscribe Set Mode message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_set_mode(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Set Mode message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_set_mode(ulog_t *log, ulog_msg_id_t id, const ulog_set_mode_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_SET_MODE_H */