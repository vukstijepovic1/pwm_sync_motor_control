/**
 * @file    ulog_scaled_imu3.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_SCALED_IMU3_H
#define ULOG_SCALED_IMU3_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_scaled_imu3_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint32_t time_boot_ms; /* Timestamp (time since system boot). [ms] */
    int16_t xacc; /* X acceleration [mG] */
    int16_t yacc; /* Y acceleration [mG] */
    int16_t zacc; /* Z acceleration [mG] */
    int16_t xgyro; /* Angular speed around X axis [mrad/s] */
    int16_t ygyro; /* Angular speed around Y axis [mrad/s] */
    int16_t zgyro; /* Angular speed around Z axis [mrad/s] */
    int16_t xmag; /* X Magnetic field [mgauss] */
    int16_t ymag; /* Y Magnetic field [mgauss] */
    int16_t zmag; /* Z Magnetic field [mgauss] */
    int16_t temperature; /* Temperature, 0: IMU does not provide temperature values. If the IMU is at 0C it must send 1 (0.01C). [cdegC] */
    
} ulog_scaled_imu3_t;

/**
 * Defines Scaled Imu3 message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_scaled_imu3(ulog_t *log);

/**
 * Subscribe Scaled Imu3 message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_scaled_imu3(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Scaled Imu3 message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_scaled_imu3(ulog_t *log, ulog_msg_id_t id, const ulog_scaled_imu3_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_SCALED_IMU3_H */