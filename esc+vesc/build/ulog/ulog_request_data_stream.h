/**
 * @file    ulog_request_data_stream.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_REQUEST_DATA_STREAM_H
#define ULOG_REQUEST_DATA_STREAM_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_request_data_stream_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t target_system; /* The target requested to send the message stream. */
    uint8_t target_component; /* The target requested to send the message stream. */
    uint8_t req_stream_id; /* The ID of the requested data stream */
    uint16_t req_message_rate; /* The requested message rate [Hz] */
    uint8_t start_stop; /* 1 to start sending, 0 to stop sending. */
    
} ulog_request_data_stream_t;

/**
 * Defines Request Data Stream message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_request_data_stream(ulog_t *log);

/**
 * Subscribe Request Data Stream message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_request_data_stream(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Request Data Stream message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_request_data_stream(ulog_t *log, ulog_msg_id_t id, const ulog_request_data_stream_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_REQUEST_DATA_STREAM_H */