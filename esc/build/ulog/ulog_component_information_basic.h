/**
 * @file    ulog_component_information_basic.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_COMPONENT_INFORMATION_BASIC_H
#define ULOG_COMPONENT_INFORMATION_BASIC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_component_information_basic_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint32_t time_boot_ms; /* Timestamp (time since system boot). [ms] */
    uint64_t capabilities; /* Component capability flags */
    uint32_t time_manufacture_s; /* Date of manufacture as a UNIX Epoch time (since 1.1.1970) in seconds. [s] */
    char vendor_name[32]; /* Name of the component vendor. Needs to be zero terminated. The field is optional and can be empty/all zeros. */
    char model_name[32]; /* Name of the component model. Needs to be zero terminated. The field is optional and can be empty/all zeros. */
    char software_version[24]; /* Software version. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros. */
    char hardware_version[24]; /* Hardware version. The recommended format is SEMVER: 'major.minor.patch'  (any format may be used). The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros. */
    char serial_number[32]; /* Hardware serial number. The field must be zero terminated if it has a value. The field is optional and can be empty/all zeros. */
    
} ulog_component_information_basic_t;

/**
 * Defines Component Information Basic message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_component_information_basic(ulog_t *log);

/**
 * Subscribe Component Information Basic message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_component_information_basic(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Component Information Basic message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_component_information_basic(ulog_t *log, ulog_msg_id_t id, const ulog_component_information_basic_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_COMPONENT_INFORMATION_BASIC_H */