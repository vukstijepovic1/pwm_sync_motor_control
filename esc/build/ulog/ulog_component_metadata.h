/**
 * @file    ulog_component_metadata.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_COMPONENT_METADATA_H
#define ULOG_COMPONENT_METADATA_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_component_metadata_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint32_t time_boot_ms; /* Timestamp (time since system boot). [ms] */
    uint32_t file_crc; /* CRC32 of the general metadata file. */
    char uri[100]; /* MAVLink FTP URI for the general metadata file (COMP_METADATA_TYPE_GENERAL), which may be compressed with xz. The file contains general component metadata, and may contain URI links for additional metadata (see COMP_METADATA_TYPE). The information is static from boot, and may be generated at compile time. The string needs to be zero terminated. */
    
} ulog_component_metadata_t;

/**
 * Defines Component Metadata message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_component_metadata(ulog_t *log);

/**
 * Subscribe Component Metadata message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_component_metadata(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Component Metadata message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_component_metadata(ulog_t *log, ulog_msg_id_t id, const ulog_component_metadata_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_COMPONENT_METADATA_H */