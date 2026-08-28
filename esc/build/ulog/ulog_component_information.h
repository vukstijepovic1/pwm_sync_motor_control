/**
 * @file    ulog_component_information.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_COMPONENT_INFORMATION_H
#define ULOG_COMPONENT_INFORMATION_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_component_information_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint32_t time_boot_ms; /* Timestamp (time since system boot). [ms] */
    uint32_t general_metadata_file_crc; /* CRC32 of the general metadata file (general_metadata_uri). */
    char general_metadata_uri[100]; /* MAVLink FTP URI for the general metadata file (COMP_METADATA_TYPE_GENERAL), which may be compressed with xz. The file contains general component metadata, and may contain URI links for additional metadata (see COMP_METADATA_TYPE). The information is static from boot, and may be generated at compile time. The string needs to be zero terminated. */
    uint32_t peripherals_metadata_file_crc; /* CRC32 of peripherals metadata file (peripherals_metadata_uri). */
    char peripherals_metadata_uri[100]; /* (Optional) MAVLink FTP URI for the peripherals metadata file (COMP_METADATA_TYPE_PERIPHERALS), which may be compressed with xz. This contains data about "attached components" such as UAVCAN nodes. The peripherals are in a separate file because the information must be generated dynamically at runtime. The string needs to be zero terminated. */
    
} ulog_component_information_t;

/**
 * Defines Component Information message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_component_information(ulog_t *log);

/**
 * Subscribe Component Information message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_component_information(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Component Information message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_component_information(ulog_t *log, ulog_msg_id_t id, const ulog_component_information_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_COMPONENT_INFORMATION_H */