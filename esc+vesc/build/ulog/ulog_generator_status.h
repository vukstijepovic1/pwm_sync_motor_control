/**
 * @file    ulog_generator_status.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_GENERATOR_STATUS_H
#define ULOG_GENERATOR_STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_generator_status_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t status; /* Status flags. */
    uint16_t generator_speed; /* Speed of electrical generator or alternator. UINT16_MAX: field not provided. [rpm] */
    float battery_current; /* Current into/out of battery. Positive for out. Negative for in. NaN: field not provided. [A] */
    float load_current; /* Current going to the UAV. If battery current not available this is the DC current from the generator. Positive for out. Negative for in. NaN: field not provided [A] */
    float power_generated; /* The power being generated. NaN: field not provided [W] */
    float bus_voltage; /* Voltage of the bus seen at the generator, or battery bus if battery bus is controlled by generator and at a different voltage to main bus. [V] */
    int16_t rectifier_temperature; /* The temperature of the rectifier or power converter. INT16_MAX: field not provided. [degC] */
    float bat_current_setpoint; /* The target battery current. Positive for out. Negative for in. NaN: field not provided [A] */
    int16_t generator_temperature; /* The temperature of the mechanical motor, fuel cell core or generator. INT16_MAX: field not provided. [degC] */
    uint32_t runtime; /* Seconds this generator has run since it was rebooted. UINT32_MAX: field not provided. [s] */
    int32_t time_until_maintenance; /* Seconds until this generator requires maintenance.  A negative value indicates maintenance is past-due. INT32_MAX: field not provided. [s] */
    
} ulog_generator_status_t;

/**
 * Defines Generator Status message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_generator_status(ulog_t *log);

/**
 * Subscribe Generator Status message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_generator_status(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Generator Status message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_generator_status(ulog_t *log, ulog_msg_id_t id, const ulog_generator_status_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_GENERATOR_STATUS_H */