/**
 * @file    ulog_lisum_vesc_status_4.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_lisum_vesc_status_4.h"
#include "ulog_def.h"

const char ulog_lisum_vesc_status_4_format[] = "lisum_vesc_status_4:uint64_t timestamp;uint8_t vesc_id;float pos;float current_in;float motor_temp;float fet_temp;";
const char ulog_lisum_vesc_status_4_name[] = "lisum_vesc_status_4";

int32_t ulog_format_lisum_vesc_status_4(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_lisum_vesc_status_4_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_lisum_vesc_status_4_format, sizeof(ulog_lisum_vesc_status_4_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_lisum_vesc_status_4(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_lisum_vesc_status_4_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_lisum_vesc_status_4_name, sizeof(ulog_lisum_vesc_status_4_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_lisum_vesc_status_4(ulog_t *log, ulog_msg_id_t id, const ulog_lisum_vesc_status_4_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
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

    /* Target VESC ID. */
    if (lfs_file_write(log->lfs, log->file, &src->vesc_id, sizeof(src->vesc_id)) < 0) {
        return 1;
    }

    /* Rotor position [deg]*50. */
    if (lfs_file_write(log->lfs, log->file, &src->pos, sizeof(src->pos)) < 0) {
        return 1;
    }

    /* Current In[A]*10. */
    if (lfs_file_write(log->lfs, log->file, &src->current_in, sizeof(src->current_in)) < 0) {
        return 1;
    }

    /* Motor temperature [°C]*10. */
    if (lfs_file_write(log->lfs, log->file, &src->motor_temp, sizeof(src->motor_temp)) < 0) {
        return 1;
    }

    /* FET temperature [°C]*10. */
    if (lfs_file_write(log->lfs, log->file, &src->fet_temp, sizeof(src->fet_temp)) < 0) {
        return 1;
    }

    
    return 0;
}
