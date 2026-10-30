/**
 * @file    ulog_terrain_check.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_TERRAIN_CHECK_H
#define ULOG_TERRAIN_CHECK_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_terrain_check_t {
    uint64_t timestamp; /* Timestamp [us] */
    int32_t lat; /* Latitude [degE7] */
    int32_t lon; /* Longitude [degE7] */
    
} ulog_terrain_check_t;

/**
 * Defines Terrain Check message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_terrain_check(ulog_t *log);

/**
 * Subscribe Terrain Check message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_terrain_check(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Terrain Check message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_terrain_check(ulog_t *log, ulog_msg_id_t id, const ulog_terrain_check_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_TERRAIN_CHECK_H */