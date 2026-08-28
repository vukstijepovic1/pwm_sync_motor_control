/**
 * @file    ulog_system_time.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_SYSTEM_TIME_H
#define ULOG_SYSTEM_TIME_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_system_time_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t time_unix_usec; /* Timestamp (UNIX epoch time). [us] */
    uint32_t time_boot_ms; /* Timestamp (time since system boot). [ms] */
    
} ulog_system_time_t;

/**
 * Defines System Time message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_system_time(ulog_t *log);

/**
 * Subscribe System Time message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_system_time(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write System Time message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_system_time(ulog_t *log, ulog_msg_id_t id, const ulog_system_time_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_SYSTEM_TIME_H */