/**
 * @file    ulog_encapsulated_data.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_ENCAPSULATED_DATA_H
#define ULOG_ENCAPSULATED_DATA_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_encapsulated_data_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint16_t seqnr; /* sequence number (starting with 0 on every transmission) */
    uint8_t data[253]; /* image data bytes */
    
} ulog_encapsulated_data_t;

/**
 * Defines Encapsulated Data message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_encapsulated_data(ulog_t *log);

/**
 * Subscribe Encapsulated Data message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_encapsulated_data(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Encapsulated Data message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_encapsulated_data(ulog_t *log, ulog_msg_id_t id, const ulog_encapsulated_data_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_ENCAPSULATED_DATA_H */