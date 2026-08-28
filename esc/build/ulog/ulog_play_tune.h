/**
 * @file    ulog_play_tune.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_PLAY_TUNE_H
#define ULOG_PLAY_TUNE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_play_tune_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t target_system; /* System ID */
    uint8_t target_component; /* Component ID */
    char tune[30]; /* tune in board specific format */
    char tune2[200]; /* tune extension (appended to tune) */
    
} ulog_play_tune_t;

/**
 * Defines Play Tune message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_play_tune(ulog_t *log);

/**
 * Subscribe Play Tune message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_play_tune(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Play Tune message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_play_tune(ulog_t *log, ulog_msg_id_t id, const ulog_play_tune_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_PLAY_TUNE_H */