/**
 * @file    ulog_autopilot_version.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_AUTOPILOT_VERSION_H
#define ULOG_AUTOPILOT_VERSION_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_autopilot_version_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t capabilities; /* Bitmap of capabilities */
    uint32_t flight_sw_version; /* Firmware version number */
    uint32_t middleware_sw_version; /* Middleware version number */
    uint32_t os_sw_version; /* Operating system version number */
    uint32_t board_version; /* HW / board version (last 8 bits should be silicon ID, if any). The first 16 bits of this field specify https://github.com/PX4/PX4-Bootloader/blob/master/board_types.txt */
    uint8_t flight_custom_version[8]; /* Custom version field, commonly the first 8 bytes of the git hash. This is not an unique identifier, but should allow to identify the commit using the main version number even for very large code bases. */
    uint8_t middleware_custom_version[8]; /* Custom version field, commonly the first 8 bytes of the git hash. This is not an unique identifier, but should allow to identify the commit using the main version number even for very large code bases. */
    uint8_t os_custom_version[8]; /* Custom version field, commonly the first 8 bytes of the git hash. This is not an unique identifier, but should allow to identify the commit using the main version number even for very large code bases. */
    uint16_t vendor_id; /* ID of the board vendor */
    uint16_t product_id; /* ID of the product */
    uint64_t uid; /* UID if provided by hardware (see uid2) */
    uint8_t uid2[18]; /* UID if provided by hardware (supersedes the uid field. If this is non-zero, use this field, otherwise use uid) */
    
} ulog_autopilot_version_t;

/**
 * Defines Autopilot Version message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_autopilot_version(ulog_t *log);

/**
 * Subscribe Autopilot Version message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_autopilot_version(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Autopilot Version message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_autopilot_version(ulog_t *log, ulog_msg_id_t id, const ulog_autopilot_version_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_AUTOPILOT_VERSION_H */