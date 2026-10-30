/**
 * @file    ulog_memory_vect.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_MEMORY_VECT_H
#define ULOG_MEMORY_VECT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_memory_vect_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint16_t address; /* Starting address of the debug variables */
    uint8_t ver; /* Version code of the type variable. 0=unknown, type ignored and assumed int16_t. 1=as below */
    uint8_t type; /* Type code of the memory variables. for ver = 1: 0=16 x int16_t, 1=16 x uint16_t, 2=16 x Q15, 3=16 x 1Q14 */
    int8_t value[32]; /* Memory contents at specified address */
    
} ulog_memory_vect_t;

/**
 * Defines Memory Vect message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_memory_vect(ulog_t *log);

/**
 * Subscribe Memory Vect message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_memory_vect(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Memory Vect message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_memory_vect(ulog_t *log, ulog_msg_id_t id, const ulog_memory_vect_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_MEMORY_VECT_H */