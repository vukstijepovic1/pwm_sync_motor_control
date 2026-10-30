/**
 * @file    ulog_estimator_status.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_ESTIMATOR_STATUS_H
#define ULOG_ESTIMATOR_STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_estimator_status_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t time_usec; /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    uint16_t flags; /* Bitmap indicating which EKF outputs are valid. */
    float vel_ratio; /* Velocity innovation test ratio */
    float pos_horiz_ratio; /* Horizontal position innovation test ratio */
    float pos_vert_ratio; /* Vertical position innovation test ratio */
    float mag_ratio; /* Magnetometer innovation test ratio */
    float hagl_ratio; /* Height above terrain innovation test ratio */
    float tas_ratio; /* True airspeed innovation test ratio */
    float pos_horiz_accuracy; /* Horizontal position 1-STD accuracy relative to the EKF local origin [m] */
    float pos_vert_accuracy; /* Vertical position 1-STD accuracy relative to the EKF local origin [m] */
    
} ulog_estimator_status_t;

/**
 * Defines Estimator Status message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_estimator_status(ulog_t *log);

/**
 * Subscribe Estimator Status message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_estimator_status(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Estimator Status message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_estimator_status(ulog_t *log, ulog_msg_id_t id, const ulog_estimator_status_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_ESTIMATOR_STATUS_H */