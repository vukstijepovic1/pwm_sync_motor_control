/**
 * @file    ulog_uavcan_node_status.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_UAVCAN_NODE_STATUS_H
#define ULOG_UAVCAN_NODE_STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_uavcan_node_status_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t time_usec; /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    uint32_t uptime_sec; /* Time since the start-up of the node. [s] */
    uint8_t health; /* Generalized node health status. */
    uint8_t mode; /* Generalized operating mode. */
    uint8_t sub_mode; /* Not used currently. */
    uint16_t vendor_specific_status_code; /* Vendor-specific status information. */
    
} ulog_uavcan_node_status_t;

/**
 * Defines Uavcan Node Status message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_uavcan_node_status(ulog_t *log);

/**
 * Subscribe Uavcan Node Status message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_uavcan_node_status(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Uavcan Node Status message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_uavcan_node_status(ulog_t *log, ulog_msg_id_t id, const ulog_uavcan_node_status_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_UAVCAN_NODE_STATUS_H */