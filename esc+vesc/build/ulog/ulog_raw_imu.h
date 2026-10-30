/**
 * @file    ulog_raw_imu.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_RAW_IMU_H
#define ULOG_RAW_IMU_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_raw_imu_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t time_usec; /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    int16_t xacc; /* X acceleration (raw) */
    int16_t yacc; /* Y acceleration (raw) */
    int16_t zacc; /* Z acceleration (raw) */
    int16_t xgyro; /* Angular speed around X axis (raw) */
    int16_t ygyro; /* Angular speed around Y axis (raw) */
    int16_t zgyro; /* Angular speed around Z axis (raw) */
    int16_t xmag; /* X Magnetic field (raw) */
    int16_t ymag; /* Y Magnetic field (raw) */
    int16_t zmag; /* Z Magnetic field (raw) */
    uint8_t id; /* Id. Ids are numbered from 0 and map to IMUs numbered from 1 (e.g. IMU1 will have a message with id=0) */
    int16_t temperature; /* Temperature, 0: IMU does not provide temperature values. If the IMU is at 0C it must send 1 (0.01C). [cdegC] */
    
} ulog_raw_imu_t;

/**
 * Defines Raw Imu message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_raw_imu(ulog_t *log);

/**
 * Subscribe Raw Imu message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_raw_imu(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Raw Imu message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_raw_imu(ulog_t *log, ulog_msg_id_t id, const ulog_raw_imu_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_RAW_IMU_H */