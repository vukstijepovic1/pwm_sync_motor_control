/**
 * @file    ulog_highres_imu.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_HIGHRES_IMU_H
#define ULOG_HIGHRES_IMU_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_highres_imu_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t time_usec; /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    float xacc; /* X acceleration [m/s/s] */
    float yacc; /* Y acceleration [m/s/s] */
    float zacc; /* Z acceleration [m/s/s] */
    float xgyro; /* Angular speed around X axis [rad/s] */
    float ygyro; /* Angular speed around Y axis [rad/s] */
    float zgyro; /* Angular speed around Z axis [rad/s] */
    float xmag; /* X Magnetic field [gauss] */
    float ymag; /* Y Magnetic field [gauss] */
    float zmag; /* Z Magnetic field [gauss] */
    float abs_pressure; /* Absolute pressure [hPa] */
    float diff_pressure; /* Differential pressure [hPa] */
    float pressure_alt; /* Altitude calculated from pressure */
    float temperature; /* Temperature [degC] */
    uint16_t fields_updated; /* Bitmap for fields that have updated since last message */
    uint8_t id; /* Id. Ids are numbered from 0 and map to IMUs numbered from 1 (e.g. IMU1 will have a message with id=0) */
    
} ulog_highres_imu_t;

/**
 * Defines Highres Imu message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_highres_imu(ulog_t *log);

/**
 * Subscribe Highres Imu message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_highres_imu(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Highres Imu message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_highres_imu(ulog_t *log, ulog_msg_id_t id, const ulog_highres_imu_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_HIGHRES_IMU_H */