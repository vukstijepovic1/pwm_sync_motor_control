/**
 * @file    ulog_actuator_output_status.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_ACTUATOR_OUTPUT_STATUS_H
#define ULOG_ACTUATOR_OUTPUT_STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_actuator_output_status_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t time_usec; /* Timestamp (since system boot). [us] */
    uint32_t active; /* Active outputs */
    float actuator[32]; /* Servo / motor output array values. Zero values indicate unused channels. */
    
} ulog_actuator_output_status_t;

/**
 * Defines Actuator Output Status message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_actuator_output_status(ulog_t *log);

/**
 * Subscribe Actuator Output Status message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_actuator_output_status(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Actuator Output Status message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_actuator_output_status(ulog_t *log, ulog_msg_id_t id, const ulog_actuator_output_status_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_ACTUATOR_OUTPUT_STATUS_H */