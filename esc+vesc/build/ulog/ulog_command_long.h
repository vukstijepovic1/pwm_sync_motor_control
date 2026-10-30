/**
 * @file    ulog_command_long.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_COMMAND_LONG_H
#define ULOG_COMMAND_LONG_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_command_long_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t target_system; /* System which should execute the command */
    uint8_t target_component; /* Component which should execute the command, 0 for all components */
    uint16_t command; /* Command ID (of command to send). */
    uint8_t confirmation; /* 0: First transmission of this command. 1-255: Confirmation transmissions (e.g. for kill command) */
    float param1; /* Parameter 1 (for the specific command). */
    float param2; /* Parameter 2 (for the specific command). */
    float param3; /* Parameter 3 (for the specific command). */
    float param4; /* Parameter 4 (for the specific command). */
    float param5; /* Parameter 5 (for the specific command). */
    float param6; /* Parameter 6 (for the specific command). */
    float param7; /* Parameter 7 (for the specific command). */
    
} ulog_command_long_t;

/**
 * Defines Command Long message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_command_long(ulog_t *log);

/**
 * Subscribe Command Long message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_command_long(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Command Long message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_command_long(ulog_t *log, ulog_msg_id_t id, const ulog_command_long_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_COMMAND_LONG_H */