/**
 * @file    ulog_param_set.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_PARAM_SET_H
#define ULOG_PARAM_SET_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_param_set_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t target_system; /* System ID */
    uint8_t target_component; /* Component ID */
    char param_id[16]; /* Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string */
    float param_value; /* Onboard parameter value */
    uint8_t param_type; /* Onboard parameter type. */
    
} ulog_param_set_t;

/**
 * Defines Param Set message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_param_set(ulog_t *log);

/**
 * Subscribe Param Set message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_param_set(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Param Set message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_param_set(ulog_t *log, ulog_msg_id_t id, const ulog_param_set_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_PARAM_SET_H */