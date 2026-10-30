/**
 * @file    ulog_lisum_gnss_recv_data.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_LISUM_GNSS_RECV_DATA_H
#define ULOG_LISUM_GNSS_RECV_DATA_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_lisum_gnss_recv_data_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t dev_id; /* Index of receiver */
    double lon; /* Longitude [deg] */
    double lat; /* Latitude [deg] */
    float alt; /* Altitude [m] */
    float head; /* Heading [deg] */
    float head_rtk; /* RTK Heading [deg] */
    float vel_ne; /* Planar velocity [m/s] */
    float vel_d; /* Vertical velocity [m/s] */
    uint8_t fix_type; /* Fix Type Flag */
    uint8_t carr_sol; /* Carrier phase solution type */
    uint8_t rtk_head_valid; /* RTK heading validity flag */
    uint8_t sv_num; /* Number of satellites */
    
} ulog_lisum_gnss_recv_data_t;

/**
 * Defines Lisum Gnss Recv Data message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_lisum_gnss_recv_data(ulog_t *log);

/**
 * Subscribe Lisum Gnss Recv Data message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_lisum_gnss_recv_data(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Lisum Gnss Recv Data message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_lisum_gnss_recv_data(ulog_t *log, ulog_msg_id_t id, const ulog_lisum_gnss_recv_data_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_LISUM_GNSS_RECV_DATA_H */