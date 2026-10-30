/**
 * @file    ulog_mount_orientation.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_MOUNT_ORIENTATION_H
#define ULOG_MOUNT_ORIENTATION_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_mount_orientation_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint32_t time_boot_ms; /* Timestamp (time since system boot). [ms] */
    float roll; /* Roll in global frame (set to NaN for invalid). [deg] */
    float pitch; /* Pitch in global frame (set to NaN for invalid). [deg] */
    float yaw; /* Yaw relative to vehicle (set to NaN for invalid). [deg] */
    float yaw_absolute; /* Yaw in absolute frame relative to Earth's North, north is 0 (set to NaN for invalid). [deg] */
    
} ulog_mount_orientation_t;

/**
 * Defines Mount Orientation message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_mount_orientation(ulog_t *log);

/**
 * Subscribe Mount Orientation message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_mount_orientation(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Mount Orientation message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_mount_orientation(ulog_t *log, ulog_msg_id_t id, const ulog_mount_orientation_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_MOUNT_ORIENTATION_H */