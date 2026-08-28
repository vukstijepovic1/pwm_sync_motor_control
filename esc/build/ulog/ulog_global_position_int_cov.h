/**
 * @file    ulog_global_position_int_cov.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_GLOBAL_POSITION_INT_COV_H
#define ULOG_GLOBAL_POSITION_INT_COV_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_global_position_int_cov_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t time_usec; /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    uint8_t estimator_type; /* Class id of the estimator this estimate originated from. */
    int32_t lat; /* Latitude [degE7] */
    int32_t lon; /* Longitude [degE7] */
    int32_t alt; /* Altitude in meters above MSL [mm] */
    int32_t relative_alt; /* Altitude above ground [mm] */
    float vx; /* Ground X Speed (Latitude) [m/s] */
    float vy; /* Ground Y Speed (Longitude) [m/s] */
    float vz; /* Ground Z Speed (Altitude) [m/s] */
    float covariance[36]; /* Row-major representation of a 6x6 position and velocity 6x6 cross-covariance matrix (states: lat, lon, alt, vx, vy, vz; first six entries are the first ROW, next six entries are the second row, etc.). If unknown, assign NaN value to first element in the array. */
    
} ulog_global_position_int_cov_t;

/**
 * Defines Global Position Int Cov message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_global_position_int_cov(ulog_t *log);

/**
 * Subscribe Global Position Int Cov message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_global_position_int_cov(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Global Position Int Cov message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_global_position_int_cov(ulog_t *log, ulog_msg_id_t id, const ulog_global_position_int_cov_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_GLOBAL_POSITION_INT_COV_H */