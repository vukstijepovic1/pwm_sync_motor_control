/**
 * @file    ulog_gimbal_device_information.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_GIMBAL_DEVICE_INFORMATION_H
#define ULOG_GIMBAL_DEVICE_INFORMATION_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_gimbal_device_information_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint32_t time_boot_ms; /* Timestamp (time since system boot). [ms] */
    char vendor_name[32]; /* Name of the gimbal vendor. */
    char model_name[32]; /* Name of the gimbal model. */
    char custom_name[32]; /* Custom name of the gimbal given to it by the user. */
    uint32_t firmware_version; /* Version of the gimbal firmware, encoded as: (Dev & 0xff) << 24 | (Patch & 0xff) << 16 | (Minor & 0xff) << 8 | (Major & 0xff). */
    uint32_t hardware_version; /* Version of the gimbal hardware, encoded as: (Dev & 0xff) << 24 | (Patch & 0xff) << 16 | (Minor & 0xff) << 8 | (Major & 0xff). */
    uint64_t uid; /* UID of gimbal hardware (0 if unknown). */
    uint16_t cap_flags; /* Bitmap of gimbal capability flags. */
    uint16_t custom_cap_flags; /* Bitmap for use for gimbal-specific capability flags. */
    float roll_min; /* Minimum hardware roll angle (positive: rolling to the right, negative: rolling to the left). NAN if unknown. [rad] */
    float roll_max; /* Maximum hardware roll angle (positive: rolling to the right, negative: rolling to the left). NAN if unknown. [rad] */
    float pitch_min; /* Minimum hardware pitch angle (positive: up, negative: down). NAN if unknown. [rad] */
    float pitch_max; /* Maximum hardware pitch angle (positive: up, negative: down). NAN if unknown. [rad] */
    float yaw_min; /* Minimum hardware yaw angle (positive: to the right, negative: to the left). NAN if unknown. [rad] */
    float yaw_max; /* Maximum hardware yaw angle (positive: to the right, negative: to the left). NAN if unknown. [rad] */
    uint8_t gimbal_device_id; /* This field is to be used if the gimbal manager and the gimbal device are the same component and hence have the same component ID. This field is then set to a number between 1-6. If the component ID is separate, this field is not required and must be set to 0. */
    
} ulog_gimbal_device_information_t;

/**
 * Defines Gimbal Device Information message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_gimbal_device_information(ulog_t *log);

/**
 * Subscribe Gimbal Device Information message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_gimbal_device_information(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Gimbal Device Information message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_gimbal_device_information(ulog_t *log, ulog_msg_id_t id, const ulog_gimbal_device_information_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_GIMBAL_DEVICE_INFORMATION_H */