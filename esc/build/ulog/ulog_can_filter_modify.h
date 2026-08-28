/**
 * @file    ulog_can_filter_modify.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_CAN_FILTER_MODIFY_H
#define ULOG_CAN_FILTER_MODIFY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_can_filter_modify_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t target_system; /* System ID. */
    uint8_t target_component; /* Component ID. */
    uint8_t bus; /* bus number */
    uint8_t operation; /* what operation to perform on the filter list. See CAN_FILTER_OP enum. */
    uint8_t num_ids; /* number of IDs in filter list */
    uint16_t ids[16]; /* filter IDs, length num_ids */
    
} ulog_can_filter_modify_t;

/**
 * Defines Can Filter Modify message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_can_filter_modify(ulog_t *log);

/**
 * Subscribe Can Filter Modify message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_can_filter_modify(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Can Filter Modify message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_can_filter_modify(ulog_t *log, ulog_msg_id_t id, const ulog_can_filter_modify_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_CAN_FILTER_MODIFY_H */