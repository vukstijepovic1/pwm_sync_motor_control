/**
 * @file    ulog_lisum_vesc_set_rpm.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_LISUM_VESC_SET_RPM_H
#define ULOG_LISUM_VESC_SET_RPM_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_lisum_vesc_set_rpm_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t vesc_id; /* Target VESC ID. */
    float rpm; /* Motor speed [ERPM]. */
    
} ulog_lisum_vesc_set_rpm_t;

/**
 * Defines Lisum Vesc Set Rpm message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_lisum_vesc_set_rpm(ulog_t *log);

/**
 * Subscribe Lisum Vesc Set Rpm message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_lisum_vesc_set_rpm(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Lisum Vesc Set Rpm message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_lisum_vesc_set_rpm(ulog_t *log, ulog_msg_id_t id, const ulog_lisum_vesc_set_rpm_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_LISUM_VESC_SET_RPM_H */