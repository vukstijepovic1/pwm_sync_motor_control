/**
 * @file    ulog_command_ack.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_COMMAND_ACK_H
#define ULOG_COMMAND_ACK_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_command_ack_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint16_t command; /* Command ID (of acknowledged command). */
    uint8_t result; /* Result of command. */
    uint8_t progress; /* The progress percentage when result is MAV_RESULT_IN_PROGRESS. Values: [0-100], or UINT8_MAX if the progress is unknown. [%] */
    int32_t result_param2; /* Additional result information. Can be set with a command-specific enum containing command-specific error reasons for why the command might be denied. If used, the associated enum must be documented in the corresponding MAV_CMD (this enum should have a 0 value to indicate "unused" or "unknown"). */
    uint8_t target_system; /* System ID of the target recipient. This is the ID of the system that sent the command for which this COMMAND_ACK is an acknowledgement. */
    uint8_t target_component; /* Component ID of the target recipient. This is the ID of the system that sent the command for which this COMMAND_ACK is an acknowledgement. */
    
} ulog_command_ack_t;

/**
 * Defines Command Ack message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_command_ack(ulog_t *log);

/**
 * Subscribe Command Ack message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_command_ack(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Command Ack message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_command_ack(ulog_t *log, ulog_msg_id_t id, const ulog_command_ack_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_COMMAND_ACK_H */