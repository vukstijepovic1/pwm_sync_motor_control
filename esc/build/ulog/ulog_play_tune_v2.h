/**
 * @file    ulog_play_tune_v2.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_PLAY_TUNE_V2_H
#define ULOG_PLAY_TUNE_V2_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_play_tune_v2_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t target_system; /* System ID */
    uint8_t target_component; /* Component ID */
    uint32_t format; /* Tune format */
    char tune[248]; /* Tune definition as a NULL-terminated string. */
    
} ulog_play_tune_v2_t;

/**
 * Defines Play Tune V2 message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_play_tune_v2(ulog_t *log);

/**
 * Subscribe Play Tune V2 message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_play_tune_v2(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Play Tune V2 message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_play_tune_v2(ulog_t *log, ulog_msg_id_t id, const ulog_play_tune_v2_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_PLAY_TUNE_V2_H */