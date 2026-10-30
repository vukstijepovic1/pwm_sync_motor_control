/**
 * @file    ulog_debug_float_array.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_DEBUG_FLOAT_ARRAY_H
#define ULOG_DEBUG_FLOAT_ARRAY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_debug_float_array_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t time_usec; /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    char name[10]; /* Name, for human-friendly display in a Ground Control Station */
    uint16_t array_id; /* Unique ID used to discriminate between arrays */
    float data[58]; /* data */
    
} ulog_debug_float_array_t;

/**
 * Defines Debug Float Array message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_debug_float_array(ulog_t *log);

/**
 * Subscribe Debug Float Array message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_debug_float_array(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Debug Float Array message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_debug_float_array(ulog_t *log, ulog_msg_id_t id, const ulog_debug_float_array_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_DEBUG_FLOAT_ARRAY_H */