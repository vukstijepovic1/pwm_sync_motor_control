/**
 * @file    ulog_change_operator_control_ack.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_CHANGE_OPERATOR_CONTROL_ACK_H
#define ULOG_CHANGE_OPERATOR_CONTROL_ACK_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_change_operator_control_ack_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t gcs_system_id; /* ID of the GCS this message  */
    uint8_t control_request; /* 0: request control of this MAV, 1: Release control of this MAV */
    uint8_t ack; /* 0: ACK, 1: NACK: Wrong passkey, 2: NACK: Unsupported passkey encryption method, 3: NACK: Already under control */
    
} ulog_change_operator_control_ack_t;

/**
 * Defines Change Operator Control Ack message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_change_operator_control_ack(ulog_t *log);

/**
 * Subscribe Change Operator Control Ack message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_change_operator_control_ack(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Change Operator Control Ack message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_change_operator_control_ack(ulog_t *log, ulog_msg_id_t id, const ulog_change_operator_control_ack_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_CHANGE_OPERATOR_CONTROL_ACK_H */