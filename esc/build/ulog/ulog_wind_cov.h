/**
 * @file    ulog_wind_cov.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_WIND_COV_H
#define ULOG_WIND_COV_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_wind_cov_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t time_usec; /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    float wind_x; /* Wind in North (NED) direction (NAN if unknown) [m/s] */
    float wind_y; /* Wind in East (NED) direction (NAN if unknown) [m/s] */
    float wind_z; /* Wind in down (NED) direction (NAN if unknown) [m/s] */
    float var_horiz; /* Variability of wind in XY, 1-STD estimated from a 1 Hz lowpassed wind estimate (NAN if unknown) [m/s] */
    float var_vert; /* Variability of wind in Z, 1-STD estimated from a 1 Hz lowpassed wind estimate (NAN if unknown) [m/s] */
    float wind_alt; /* Altitude (MSL) that this measurement was taken at (NAN if unknown) [m] */
    float horiz_accuracy; /* Horizontal speed 1-STD accuracy (0 if unknown) [m/s] */
    float vert_accuracy; /* Vertical speed 1-STD accuracy (0 if unknown) [m/s] */
    
} ulog_wind_cov_t;

/**
 * Defines Wind Cov message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_wind_cov(ulog_t *log);

/**
 * Subscribe Wind Cov message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_wind_cov(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Wind Cov message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_wind_cov(ulog_t *log, ulog_msg_id_t id, const ulog_wind_cov_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_WIND_COV_H */