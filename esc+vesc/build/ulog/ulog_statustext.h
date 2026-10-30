/**
 * @file    ulog_statustext.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_STATUSTEXT_H
#define ULOG_STATUSTEXT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_statustext_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t severity; /* Severity of status. Relies on the definitions within RFC-5424. */
    char text[50]; /* Status text message, without null termination character */
    uint16_t id; /* Unique (opaque) identifier for this statustext message.  May be used to reassemble a logical long-statustext message from a sequence of chunks.  A value of zero indicates this is the only chunk in the sequence and the message can be emitted immediately. */
    uint8_t chunk_seq; /* This chunk's sequence number; indexing is from zero.  Any null character in the text field is taken to mean this was the last chunk. */
    
} ulog_statustext_t;

/**
 * Defines Statustext message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_statustext(ulog_t *log);

/**
 * Subscribe Statustext message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_statustext(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Statustext message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_statustext(ulog_t *log, ulog_msg_id_t id, const ulog_statustext_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_STATUSTEXT_H */