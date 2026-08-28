/**
 * @file    ulog_command_cancel.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_COMMAND_CANCEL_H
#define ULOG_COMMAND_CANCEL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_command_cancel_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t target_system; /* System executing long running command. Should not be broadcast (0). */
    uint8_t target_component; /* Component executing long running command. */
    uint16_t command; /* Command ID (of command to cancel). */
    
} ulog_command_cancel_t;

/**
 * Defines Command Cancel message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_command_cancel(ulog_t *log);

/**
 * Subscribe Command Cancel message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_command_cancel(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Command Cancel message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_command_cancel(ulog_t *log, ulog_msg_id_t id, const ulog_command_cancel_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_COMMAND_CANCEL_H */