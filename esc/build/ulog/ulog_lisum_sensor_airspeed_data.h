/**
 * @file    ulog_lisum_sensor_airspeed_data.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_LISUM_SENSOR_AIRSPEED_DATA_H
#define ULOG_LISUM_SENSOR_AIRSPEED_DATA_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_lisum_sensor_airspeed_data_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t id; /* Sensor ID. */
    float airspeed; /* Calibrated airspeed (CAS). [m/s] */
    int16_t temperature; /* Temperature. INT16_MAX for value unknown/not supplied. [cdegC] */
    float raw_press; /* Raw differential pressure. NaN for value unknown/not supplied. [hPa] */
    uint8_t flags; /* Airspeed sensor flags. */
    
} ulog_lisum_sensor_airspeed_data_t;

/**
 * Defines Lisum Sensor Airspeed Data message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_lisum_sensor_airspeed_data(ulog_t *log);

/**
 * Subscribe Lisum Sensor Airspeed Data message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_lisum_sensor_airspeed_data(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Lisum Sensor Airspeed Data message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_lisum_sensor_airspeed_data(ulog_t *log, ulog_msg_id_t id, const ulog_lisum_sensor_airspeed_data_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_LISUM_SENSOR_AIRSPEED_DATA_H */