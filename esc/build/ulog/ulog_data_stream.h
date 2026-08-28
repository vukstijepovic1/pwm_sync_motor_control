/**
 * @file    ulog_data_stream.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_DATA_STREAM_H
#define ULOG_DATA_STREAM_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_data_stream_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t stream_id; /* The ID of the requested data stream */
    uint16_t message_rate; /* The message rate [Hz] */
    uint8_t on_off; /* 1 stream is enabled, 0 stream is stopped. */
    
} ulog_data_stream_t;

/**
 * Defines Data Stream message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_data_stream(ulog_t *log);

/**
 * Subscribe Data Stream message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_data_stream(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Data Stream message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_data_stream(ulog_t *log, ulog_msg_id_t id, const ulog_data_stream_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_DATA_STREAM_H */