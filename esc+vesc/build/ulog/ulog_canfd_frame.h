/**
 * @file    ulog_canfd_frame.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_CANFD_FRAME_H
#define ULOG_CANFD_FRAME_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_canfd_frame_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t target_system; /* System ID. */
    uint8_t target_component; /* Component ID. */
    uint8_t bus; /* bus number */
    uint8_t len; /* Frame length */
    uint32_t id; /* Frame ID */
    uint8_t data[64]; /* Frame data */
    
} ulog_canfd_frame_t;

/**
 * Defines Canfd Frame message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_canfd_frame(ulog_t *log);

/**
 * Subscribe Canfd Frame message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_canfd_frame(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Canfd Frame message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_canfd_frame(ulog_t *log, ulog_msg_id_t id, const ulog_canfd_frame_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_CANFD_FRAME_H */