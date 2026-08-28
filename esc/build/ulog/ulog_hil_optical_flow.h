/**
 * @file    ulog_hil_optical_flow.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_HIL_OPTICAL_FLOW_H
#define ULOG_HIL_OPTICAL_FLOW_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_hil_optical_flow_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t time_usec; /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    uint8_t sensor_id; /* Sensor ID */
    uint32_t integration_time_us; /* Integration time. Divide integrated_x and integrated_y by the integration time to obtain average flow. The integration time also indicates the. [us] */
    float integrated_x; /* Flow in radians around X axis (Sensor RH rotation about the X axis induces a positive flow. Sensor linear motion along the positive Y axis induces a negative flow.) [rad] */
    float integrated_y; /* Flow in radians around Y axis (Sensor RH rotation about the Y axis induces a positive flow. Sensor linear motion along the positive X axis induces a positive flow.) [rad] */
    float integrated_xgyro; /* RH rotation around X axis [rad] */
    float integrated_ygyro; /* RH rotation around Y axis [rad] */
    float integrated_zgyro; /* RH rotation around Z axis [rad] */
    int16_t temperature; /* Temperature [cdegC] */
    uint8_t quality; /* Optical flow quality / confidence. 0: no valid flow, 255: maximum quality */
    uint32_t time_delta_distance_us; /* Time since the distance was sampled. [us] */
    float distance; /* Distance to the center of the flow field. Positive value (including zero): distance known. Negative value: Unknown distance. [m] */
    
} ulog_hil_optical_flow_t;

/**
 * Defines Hil Optical Flow message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_hil_optical_flow(ulog_t *log);

/**
 * Subscribe Hil Optical Flow message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_hil_optical_flow(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Hil Optical Flow message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_hil_optical_flow(ulog_t *log, ulog_msg_id_t id, const ulog_hil_optical_flow_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_HIL_OPTICAL_FLOW_H */