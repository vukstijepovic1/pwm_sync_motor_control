/**
 * @file    ulog_storage_information.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_STORAGE_INFORMATION_H
#define ULOG_STORAGE_INFORMATION_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_storage_information_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint32_t time_boot_ms; /* Timestamp (time since system boot). [ms] */
    uint8_t storage_id; /* Storage ID (1 for first, 2 for second, etc.) */
    uint8_t storage_count; /* Number of storage devices */
    uint8_t status; /* Status of storage */
    float total_capacity; /* Total capacity. If storage is not ready (STORAGE_STATUS_READY) value will be ignored. [MiB] */
    float used_capacity; /* Used capacity. If storage is not ready (STORAGE_STATUS_READY) value will be ignored. [MiB] */
    float available_capacity; /* Available storage capacity. If storage is not ready (STORAGE_STATUS_READY) value will be ignored. [MiB] */
    float read_speed; /* Read speed. [MiB/s] */
    float write_speed; /* Write speed. [MiB/s] */
    uint8_t type; /* Type of storage */
    char name[32]; /* Textual storage name to be used in UI (microSD 1, Internal Memory, etc.) This is a NULL terminated string. If it is exactly 32 characters long, add a terminating NULL. If this string is empty, the generic type is shown to the user. */
    uint8_t storage_usage; /* Flags indicating whether this instance is preferred storage for photos, videos, etc.
        Note: Implementations should initially set the flags on the system-default storage id used for saving media (if possible/supported).
        This setting can then be overridden using MAV_CMD_SET_STORAGE_USAGE.
        If the media usage flags are not set, a GCS may assume storage ID 1 is the default storage for all media types. */
    
} ulog_storage_information_t;

/**
 * Defines Storage Information message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_storage_information(ulog_t *log);

/**
 * Subscribe Storage Information message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_storage_information(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Storage Information message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_storage_information(ulog_t *log, ulog_msg_id_t id, const ulog_storage_information_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_STORAGE_INFORMATION_H */