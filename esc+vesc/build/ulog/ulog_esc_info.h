/**
 * @file    ulog_esc_info.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_ESC_INFO_H
#define ULOG_ESC_INFO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_esc_info_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t index; /* Index of the first ESC in this message. minValue = 0, maxValue = 60, increment = 4. */
    uint64_t time_usec; /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude the number. [us] */
    uint16_t counter; /* Counter of data packets received. */
    uint8_t count; /* Total number of ESCs in all messages of this type. Message fields with an index higher than this should be ignored because they contain invalid data. */
    uint8_t connection_type; /* Connection type protocol for all ESC. */
    uint8_t info; /* Information regarding online/offline status of each ESC. */
    uint16_t failure_flags[4]; /* Bitmap of ESC failure flags. */
    uint32_t error_count[4]; /* Number of reported errors by each ESC since boot. */
    int16_t temperature[4]; /* Temperature of each ESC. INT16_MAX: if data not supplied by ESC. [cdegC] */
    
} ulog_esc_info_t;

/**
 * Defines Esc Info message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_esc_info(ulog_t *log);

/**
 * Subscribe Esc Info message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_esc_info(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Esc Info message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_esc_info(ulog_t *log, ulog_msg_id_t id, const ulog_esc_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_ESC_INFO_H */