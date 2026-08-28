/**
 * @file    ulog_param_map_rc.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_PARAM_MAP_RC_H
#define ULOG_PARAM_MAP_RC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_param_map_rc_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint8_t target_system; /* System ID */
    uint8_t target_component; /* Component ID */
    char param_id[16]; /* Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string */
    int16_t param_index; /* Parameter index. Send -1 to use the param ID field as identifier (else the param id will be ignored), send -2 to disable any existing map for this rc_channel_index. */
    uint8_t parameter_rc_channel_index; /* Index of parameter RC channel. Not equal to the RC channel id. Typically corresponds to a potentiometer-knob on the RC. */
    float param_value0; /* Initial parameter value */
    float scale; /* Scale, maps the RC range [-1, 1] to a parameter value */
    float param_value_min; /* Minimum param value. The protocol does not define if this overwrites an onboard minimum value. (Depends on implementation) */
    float param_value_max; /* Maximum param value. The protocol does not define if this overwrites an onboard maximum value. (Depends on implementation) */
    
} ulog_param_map_rc_t;

/**
 * Defines Param Map Rc message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_param_map_rc(ulog_t *log);

/**
 * Subscribe Param Map Rc message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_param_map_rc(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Param Map Rc message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_param_map_rc(ulog_t *log, ulog_msg_id_t id, const ulog_param_map_rc_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_PARAM_MAP_RC_H */