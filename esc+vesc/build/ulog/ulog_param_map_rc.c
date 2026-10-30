/**
 * @file    ulog_param_map_rc.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_param_map_rc.h"
#include "ulog_def.h"

const char ulog_param_map_rc_format[] = "param_map_rc:uint64_t timestamp;uint8_t target_system;uint8_t target_component;char[16] param_id;int16_t param_index;uint8_t parameter_rc_channel_index;float param_value0;float scale;float param_value_min;float param_value_max;";
const char ulog_param_map_rc_name[] = "param_map_rc";

int32_t ulog_format_param_map_rc(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_param_map_rc_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_param_map_rc_format, sizeof(ulog_param_map_rc_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_param_map_rc(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_param_map_rc_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_param_map_rc_name, sizeof(ulog_param_map_rc_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_param_map_rc(ulog_t *log, ulog_msg_id_t id, const ulog_param_map_rc_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(char)*16
                    + sizeof(int16_t)
                    + sizeof(uint8_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
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

    /* System ID */
    if (lfs_file_write(log->lfs, log->file, &src->target_system, sizeof(src->target_system)) < 0) {
        return 1;
    }

    /* Component ID */
    if (lfs_file_write(log->lfs, log->file, &src->target_component, sizeof(src->target_component)) < 0) {
        return 1;
    }

    /* Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string */
    if (lfs_file_write(log->lfs, log->file, src->param_id, sizeof(src->param_id)) < 0) {
        return 1;
    }

    /* Parameter index. Send -1 to use the param ID field as identifier (else the param id will be ignored), send -2 to disable any existing map for this rc_channel_index. */
    if (lfs_file_write(log->lfs, log->file, &src->param_index, sizeof(src->param_index)) < 0) {
        return 1;
    }

    /* Index of parameter RC channel. Not equal to the RC channel id. Typically corresponds to a potentiometer-knob on the RC. */
    if (lfs_file_write(log->lfs, log->file, &src->parameter_rc_channel_index, sizeof(src->parameter_rc_channel_index)) < 0) {
        return 1;
    }

    /* Initial parameter value */
    if (lfs_file_write(log->lfs, log->file, &src->param_value0, sizeof(src->param_value0)) < 0) {
        return 1;
    }

    /* Scale, maps the RC range [-1, 1] to a parameter value */
    if (lfs_file_write(log->lfs, log->file, &src->scale, sizeof(src->scale)) < 0) {
        return 1;
    }

    /* Minimum param value. The protocol does not define if this overwrites an onboard minimum value. (Depends on implementation) */
    if (lfs_file_write(log->lfs, log->file, &src->param_value_min, sizeof(src->param_value_min)) < 0) {
        return 1;
    }

    /* Maximum param value. The protocol does not define if this overwrites an onboard maximum value. (Depends on implementation) */
    if (lfs_file_write(log->lfs, log->file, &src->param_value_max, sizeof(src->param_value_max)) < 0) {
        return 1;
    }

    
    return 0;
}
