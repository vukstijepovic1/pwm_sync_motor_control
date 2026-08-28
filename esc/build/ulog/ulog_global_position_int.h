/**
 * @file    ulog_global_position_int.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_GLOBAL_POSITION_INT_H
#define ULOG_GLOBAL_POSITION_INT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_global_position_int_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint32_t time_boot_ms; /* Timestamp (time since system boot). [ms] */
    int32_t lat; /* Latitude, expressed [degE7] */
    int32_t lon; /* Longitude, expressed [degE7] */
    int32_t alt; /* Altitude (MSL). Note that virtually all GPS modules provide both WGS84 and MSL. [mm] */
    int32_t relative_alt; /* Altitude above home [mm] */
    int16_t vx; /* Ground X Speed (Latitude, positive north) [cm/s] */
    int16_t vy; /* Ground Y Speed (Longitude, positive east) [cm/s] */
    int16_t vz; /* Ground Z Speed (Altitude, positive down) [cm/s] */
    uint16_t hdg; /* Vehicle heading (yaw angle), 0.0..359.99 degrees. If unknown, set to: UINT16_MAX [cdeg] */
    
} ulog_global_position_int_t;

/**
 * Defines Global Position Int message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_global_position_int(ulog_t *log);

/**
 * Subscribe Global Position Int message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_global_position_int(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Global Position Int message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_global_position_int(ulog_t *log, ulog_msg_id_t id, const ulog_global_position_int_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_GLOBAL_POSITION_INT_H */