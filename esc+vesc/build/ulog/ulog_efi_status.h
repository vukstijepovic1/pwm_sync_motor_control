/**
 * @file    ulog_efi_status.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_EFI_STATUS_H
#define ULOG_EFI_STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_efi_status_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t health; /* EFI health status */
    float ecu_index; /* ECU index */
    float rpm; /* RPM */
    float fuel_consumed; /* Fuel consumed [cm^3] */
    float fuel_flow; /* Fuel flow rate [cm^3/min] */
    float engine_load; /* Engine load [%] */
    float throttle_position; /* Throttle position [%] */
    float spark_dwell_time; /* Spark dwell time [ms] */
    float barometric_pressure; /* Barometric pressure [kPa] */
    float intake_manifold_pressure; /* Intake manifold pressure( [kPa] */
    float intake_manifold_temperature; /* Intake manifold temperature [degC] */
    float cylinder_head_temperature; /* Cylinder head temperature [degC] */
    float ignition_timing; /* Ignition timing (Crank angle degrees) [deg] */
    float injection_time; /* Injection time [ms] */
    float exhaust_gas_temperature; /* Exhaust gas temperature [degC] */
    float throttle_out; /* Output throttle [%] */
    float pt_compensation; /* Pressure/temperature compensation */
    float ignition_voltage; /* Supply voltage to EFI sparking system.  Zero in this value means "unknown", so if the supply voltage really is zero volts use 0.0001 instead. [V] */
    float fuel_pressure; /* Fuel pressure. Zero in this value means "unknown", so if the fuel pressure really is zero kPa use 0.0001 instead. [kPa] */
    
} ulog_efi_status_t;

/**
 * Defines Efi Status message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_efi_status(ulog_t *log);

/**
 * Subscribe Efi Status message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_efi_status(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Efi Status message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_efi_status(ulog_t *log, ulog_msg_id_t id, const ulog_efi_status_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_EFI_STATUS_H */