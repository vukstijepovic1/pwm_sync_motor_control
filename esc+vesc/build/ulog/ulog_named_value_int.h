/**
 * @file    ulog_named_value_int.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_NAMED_VALUE_INT_H
#define ULOG_NAMED_VALUE_INT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_named_value_int_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint32_t time_boot_ms; /* Timestamp (time since system boot). [ms] */
    char name[10]; /* Name of the debug variable */
    int32_t value; /* Signed integer value */
    
} ulog_named_value_int_t;

/**
 * Defines Named Value Int message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_named_value_int(ulog_t *log);

/**
 * Subscribe Named Value Int message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_named_value_int(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Named Value Int message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_named_value_int(ulog_t *log, ulog_msg_id_t id, const ulog_named_value_int_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_NAMED_VALUE_INT_H */