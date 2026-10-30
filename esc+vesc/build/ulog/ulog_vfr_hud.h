/**
 * @file    ulog_vfr_hud.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_VFR_HUD_H
#define ULOG_VFR_HUD_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_vfr_hud_t {
    uint64_t timestamp; /* Timestamp [us] */
    float airspeed; /* Vehicle speed in form appropriate for vehicle type. For standard aircraft this is typically calibrated airspeed (CAS) or indicated airspeed (IAS) - either of which can be used by a pilot to estimate stall speed. [m/s] */
    float groundspeed; /* Current ground speed. [m/s] */
    int16_t heading; /* Current heading in compass units (0-360, 0=north). [deg] */
    uint16_t throttle; /* Current throttle setting (0 to 100). [%] */
    float alt; /* Current altitude (MSL). [m] */
    float climb; /* Current climb rate. [m/s] */
    
} ulog_vfr_hud_t;

/**
 * Defines Vfr Hud message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_vfr_hud(ulog_t *log);

/**
 * Subscribe Vfr Hud message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_vfr_hud(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Vfr Hud message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_vfr_hud(ulog_t *log, ulog_msg_id_t id, const ulog_vfr_hud_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_VFR_HUD_H */