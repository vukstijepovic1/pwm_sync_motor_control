/**
 * @file    ulog_param_ext_ack.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_PARAM_EXT_ACK_H
#define ULOG_PARAM_EXT_ACK_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_param_ext_ack_t {
    uint64_t timestamp; /* Timestamp [us] */
    char param_id[16]; /* Parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string */
    char param_value[128]; /* Parameter value (new value if PARAM_ACK_ACCEPTED, current value otherwise) */
    uint8_t param_type; /* Parameter type. */
    uint8_t param_result; /* Result code. */
    
} ulog_param_ext_ack_t;

/**
 * Defines Param Ext Ack message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_param_ext_ack(ulog_t *log);

/**
 * Subscribe Param Ext Ack message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_param_ext_ack(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Param Ext Ack message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_param_ext_ack(ulog_t *log, ulog_msg_id_t id, const ulog_param_ext_ack_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_PARAM_EXT_ACK_H */