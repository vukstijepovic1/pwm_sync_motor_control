/**
 * @file    ulog_lisum_power_hornet_act_data.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_LISUM_POWER_HORNET_ACT_DATA_H
#define ULOG_LISUM_POWER_HORNET_ACT_DATA_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_lisum_power_hornet_act_data_t {
    uint64_t timestamp; /* Timestamp [us] */
    float pos_act1; /* Position of Actuator 1 [mm] */
    float abs_pos_act1; /* Absolute Position of Actuator 1 [mm] */
    float vel_act1; /* Velocity of Actuator 1 [mm/s] */
    float curr_act1; /* Current of Actuator 1 [A] */
    uint16_t sw_act1; /* Statusword of Actuator 1 */
    uint16_t abs_enc_sw_act1; /* Absolute encoder statusword of Actuator 1 */
    float pos_act2; /* Position of Actuator 2 [mm] */
    float abs_pos_act2; /* Absolute Position of Actuator 2 [mm] */
    float vel_act2; /* Velocity of Actuator 2 [mm/s] */
    float curr_act2; /* Current of Actuator 2 [A] */
    uint16_t sw_act2; /* Statusword of Actuator 2 */
    uint16_t abs_enc_sw_act2; /* Absolute encoder statusword of Actuator 2 */
    float pos_act3; /* Position of Actuator 3 [mm] */
    float abs_pos_act3; /* Absolute Position of Actuator 3 [mm] */
    float vel_act3; /* Velocity of Actuator 3 [mm/s] */
    float curr_act3; /* Current of Actuator 3 [A] */
    uint16_t sw_act3; /* Statusword of Actuator 3 */
    uint16_t abs_enc_sw_act3; /* Absolute encoder statusword of Actuator 3 */
    float pos_act4; /* Position of Actuator 4 [mm] */
    float abs_pos_act4; /* Absolute Position of Actuator 4 [mm] */
    float vel_act4; /* Velocity of Actuator 4 [mm/s] */
    float curr_act4; /* Current of Actuator 4 [A] */
    uint16_t sw_act4; /* Statusword of Actuator 4 */
    uint16_t abs_enc_sw_act4; /* Absolute encoder statusword of Actuator 4 */
    
} ulog_lisum_power_hornet_act_data_t;

/**
 * Defines Lisum Power Hornet Act Data message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_lisum_power_hornet_act_data(ulog_t *log);

/**
 * Subscribe Lisum Power Hornet Act Data message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_lisum_power_hornet_act_data(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Lisum Power Hornet Act Data message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_lisum_power_hornet_act_data(ulog_t *log, ulog_msg_id_t id, const ulog_lisum_power_hornet_act_data_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_LISUM_POWER_HORNET_ACT_DATA_H */