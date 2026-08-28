/**
 * @file    ulog_utm_global_position.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_UTM_GLOBAL_POSITION_H
#define ULOG_UTM_GLOBAL_POSITION_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_utm_global_position_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t time; /* Time of applicability of position (microseconds since UNIX epoch). [us] */
    uint8_t uas_id[18]; /* Unique UAS ID. */
    int32_t lat; /* Latitude (WGS84) [degE7] */
    int32_t lon; /* Longitude (WGS84) [degE7] */
    int32_t alt; /* Altitude (WGS84) [mm] */
    int32_t relative_alt; /* Altitude above ground [mm] */
    int16_t vx; /* Ground X speed (latitude, positive north) [cm/s] */
    int16_t vy; /* Ground Y speed (longitude, positive east) [cm/s] */
    int16_t vz; /* Ground Z speed (altitude, positive down) [cm/s] */
    uint16_t h_acc; /* Horizontal position uncertainty (standard deviation) [mm] */
    uint16_t v_acc; /* Altitude uncertainty (standard deviation) [mm] */
    uint16_t vel_acc; /* Speed uncertainty (standard deviation) [cm/s] */
    int32_t next_lat; /* Next waypoint, latitude (WGS84) [degE7] */
    int32_t next_lon; /* Next waypoint, longitude (WGS84) [degE7] */
    int32_t next_alt; /* Next waypoint, altitude (WGS84) [mm] */
    uint16_t update_rate; /* Time until next update. Set to 0 if unknown or in data driven mode. [cs] */
    uint8_t flight_state; /* Flight state */
    uint8_t flags; /* Bitwise OR combination of the data available flags. */
    
} ulog_utm_global_position_t;

/**
 * Defines Utm Global Position message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_utm_global_position(ulog_t *log);

/**
 * Subscribe Utm Global Position message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_utm_global_position(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Utm Global Position message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_utm_global_position(ulog_t *log, ulog_msg_id_t id, const ulog_utm_global_position_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_UTM_GLOBAL_POSITION_H */