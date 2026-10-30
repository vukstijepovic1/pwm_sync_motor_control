/**
 * @file    ulog_vibration.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_VIBRATION_H
#define ULOG_VIBRATION_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_vibration_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t time_usec; /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    float vibration_x; /* Vibration levels on X-axis */
    float vibration_y; /* Vibration levels on Y-axis */
    float vibration_z; /* Vibration levels on Z-axis */
    uint32_t clipping_0; /* first accelerometer clipping count */
    uint32_t clipping_1; /* second accelerometer clipping count */
    uint32_t clipping_2; /* third accelerometer clipping count */
    
} ulog_vibration_t;

/**
 * Defines Vibration message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_vibration(ulog_t *log);

/**
 * Subscribe Vibration message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_vibration(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Vibration message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_vibration(ulog_t *log, ulog_msg_id_t id, const ulog_vibration_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_VIBRATION_H */