/**
 * @file    ulog_uavcan_node_info.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_UAVCAN_NODE_INFO_H
#define ULOG_UAVCAN_NODE_INFO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_uavcan_node_info_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t time_usec; /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    uint32_t uptime_sec; /* Time since the start-up of the node. [s] */
    char name[80]; /* Node name string. For example, "sapog.px4.io". */
    uint8_t hw_version_major; /* Hardware major version number. */
    uint8_t hw_version_minor; /* Hardware minor version number. */
    uint8_t hw_unique_id[16]; /* Hardware unique 128-bit ID. */
    uint8_t sw_version_major; /* Software major version number. */
    uint8_t sw_version_minor; /* Software minor version number. */
    uint32_t sw_vcs_commit; /* Version control system (VCS) revision identifier (e.g. git short commit hash). 0 if unknown. */
    
} ulog_uavcan_node_info_t;

/**
 * Defines Uavcan Node Info message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_uavcan_node_info(ulog_t *log);

/**
 * Subscribe Uavcan Node Info message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_uavcan_node_info(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Uavcan Node Info message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_uavcan_node_info(ulog_t *log, ulog_msg_id_t id, const ulog_uavcan_node_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_UAVCAN_NODE_INFO_H */