/**
 * @file    ulog_memory_vect.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_memory_vect.h"
#include "ulog_def.h"

const char ulog_memory_vect_format[] = "memory_vect:uint64_t timestamp;uint16_t address;uint8_t ver;uint8_t type;int8_t[32] value;";
const char ulog_memory_vect_name[] = "memory_vect";

int32_t ulog_format_memory_vect(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_memory_vect_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_memory_vect_format, sizeof(ulog_memory_vect_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_memory_vect(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_memory_vect_name) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_SUBSCRIPTION,
    };

    if(log->state == ULOG_STATE_DEFINITIONS_CREATED)
        log->state = ULOG_STATE_WRITING_DATA;

    if(log->state != ULOG_STATE_WRITING_DATA)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, &multi_id, sizeof(multi_id)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, &log->msg_cnt, sizeof(log->msg_cnt)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_memory_vect_name, sizeof(ulog_memory_vect_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_memory_vect(ulog_t *log, ulog_msg_id_t id, const ulog_memory_vect_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint16_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(int8_t)*32
                    ,
        .msg_type = ULOG_DEF_MSG_TYPE_LOGGED_DATA,
    };

    if(log->state != ULOG_STATE_WRITING_DATA || id >= log->msg_cnt) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, &id, sizeof(id)) < 0) {
        return 1;
    }

    /* Timestamp [us] */
    if (lfs_file_write(log->lfs, log->file, &src->timestamp, sizeof(src->timestamp)) < 0) {
        return 1;
    }

    /* Starting address of the debug variables */
    if (lfs_file_write(log->lfs, log->file, &src->address, sizeof(src->address)) < 0) {
        return 1;
    }

    /* Version code of the type variable. 0=unknown, type ignored and assumed int16_t. 1=as below */
    if (lfs_file_write(log->lfs, log->file, &src->ver, sizeof(src->ver)) < 0) {
        return 1;
    }

    /* Type code of the memory variables. for ver = 1: 0=16 x int16_t, 1=16 x uint16_t, 2=16 x Q15, 3=16 x 1Q14 */
    if (lfs_file_write(log->lfs, log->file, &src->type, sizeof(src->type)) < 0) {
        return 1;
    }

    /* Memory contents at specified address */
    if (lfs_file_write(log->lfs, log->file, src->value, sizeof(src->value)) < 0) {
        return 1;
    }

    
    return 0;
}
