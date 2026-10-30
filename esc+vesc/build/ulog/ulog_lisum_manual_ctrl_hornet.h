/**
 * @file    ulog_lisum_manual_ctrl_hornet.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_LISUM_MANUAL_CTRL_HORNET_H
#define ULOG_LISUM_MANUAL_CTRL_HORNET_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_lisum_manual_ctrl_hornet_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t mode; /* Operational Mode */
    float pos_sp_act1; /* Position setpoint Actuator 1 [mm] */
    float pos_sp_act2; /* Position setpoint Actuator 2 [mm] */
    float pos_sp_act3; /* Position setpoint Actuator 3 [mm] */
    float pos_sp_act4; /* Position setpoint Actuator 4 [mm] */
    
} ulog_lisum_manual_ctrl_hornet_t;

/**
 * Defines Lisum Manual Ctrl Hornet message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_lisum_manual_ctrl_hornet(ulog_t *log);

/**
 * Subscribe Lisum Manual Ctrl Hornet message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_lisum_manual_ctrl_hornet(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Lisum Manual Ctrl Hornet message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_lisum_manual_ctrl_hornet(ulog_t *log, ulog_msg_id_t id, const ulog_lisum_manual_ctrl_hornet_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_LISUM_MANUAL_CTRL_HORNET_H */