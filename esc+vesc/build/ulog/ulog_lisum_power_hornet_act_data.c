/**
 * @file    ulog_lisum_power_hornet_act_data.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_lisum_power_hornet_act_data.h"
#include "ulog_def.h"

const char ulog_lisum_power_hornet_act_data_format[] = "lisum_power_hornet_act_data:uint64_t timestamp;float pos_act1;float abs_pos_act1;float vel_act1;float curr_act1;uint16_t sw_act1;uint16_t abs_enc_sw_act1;float pos_act2;float abs_pos_act2;float vel_act2;float curr_act2;uint16_t sw_act2;uint16_t abs_enc_sw_act2;float pos_act3;float abs_pos_act3;float vel_act3;float curr_act3;uint16_t sw_act3;uint16_t abs_enc_sw_act3;float pos_act4;float abs_pos_act4;float vel_act4;float curr_act4;uint16_t sw_act4;uint16_t abs_enc_sw_act4;";
const char ulog_lisum_power_hornet_act_data_name[] = "lisum_power_hornet_act_data";

int32_t ulog_format_lisum_power_hornet_act_data(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_lisum_power_hornet_act_data_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_lisum_power_hornet_act_data_format, sizeof(ulog_lisum_power_hornet_act_data_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_lisum_power_hornet_act_data(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_lisum_power_hornet_act_data_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_lisum_power_hornet_act_data_name, sizeof(ulog_lisum_power_hornet_act_data_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_lisum_power_hornet_act_data(ulog_t *log, ulog_msg_id_t id, const ulog_lisum_power_hornet_act_data_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(float)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
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

    /* Position of Actuator 1 [mm] */
    if (lfs_file_write(log->lfs, log->file, &src->pos_act1, sizeof(src->pos_act1)) < 0) {
        return 1;
    }

    /* Absolute Position of Actuator 1 [mm] */
    if (lfs_file_write(log->lfs, log->file, &src->abs_pos_act1, sizeof(src->abs_pos_act1)) < 0) {
        return 1;
    }

    /* Velocity of Actuator 1 [mm/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vel_act1, sizeof(src->vel_act1)) < 0) {
        return 1;
    }

    /* Current of Actuator 1 [A] */
    if (lfs_file_write(log->lfs, log->file, &src->curr_act1, sizeof(src->curr_act1)) < 0) {
        return 1;
    }

    /* Statusword of Actuator 1 */
    if (lfs_file_write(log->lfs, log->file, &src->sw_act1, sizeof(src->sw_act1)) < 0) {
        return 1;
    }

    /* Absolute encoder statusword of Actuator 1 */
    if (lfs_file_write(log->lfs, log->file, &src->abs_enc_sw_act1, sizeof(src->abs_enc_sw_act1)) < 0) {
        return 1;
    }

    /* Position of Actuator 2 [mm] */
    if (lfs_file_write(log->lfs, log->file, &src->pos_act2, sizeof(src->pos_act2)) < 0) {
        return 1;
    }

    /* Absolute Position of Actuator 2 [mm] */
    if (lfs_file_write(log->lfs, log->file, &src->abs_pos_act2, sizeof(src->abs_pos_act2)) < 0) {
        return 1;
    }

    /* Velocity of Actuator 2 [mm/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vel_act2, sizeof(src->vel_act2)) < 0) {
        return 1;
    }

    /* Current of Actuator 2 [A] */
    if (lfs_file_write(log->lfs, log->file, &src->curr_act2, sizeof(src->curr_act2)) < 0) {
        return 1;
    }

    /* Statusword of Actuator 2 */
    if (lfs_file_write(log->lfs, log->file, &src->sw_act2, sizeof(src->sw_act2)) < 0) {
        return 1;
    }

    /* Absolute encoder statusword of Actuator 2 */
    if (lfs_file_write(log->lfs, log->file, &src->abs_enc_sw_act2, sizeof(src->abs_enc_sw_act2)) < 0) {
        return 1;
    }

    /* Position of Actuator 3 [mm] */
    if (lfs_file_write(log->lfs, log->file, &src->pos_act3, sizeof(src->pos_act3)) < 0) {
        return 1;
    }

    /* Absolute Position of Actuator 3 [mm] */
    if (lfs_file_write(log->lfs, log->file, &src->abs_pos_act3, sizeof(src->abs_pos_act3)) < 0) {
        return 1;
    }

    /* Velocity of Actuator 3 [mm/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vel_act3, sizeof(src->vel_act3)) < 0) {
        return 1;
    }

    /* Current of Actuator 3 [A] */
    if (lfs_file_write(log->lfs, log->file, &src->curr_act3, sizeof(src->curr_act3)) < 0) {
        return 1;
    }

    /* Statusword of Actuator 3 */
    if (lfs_file_write(log->lfs, log->file, &src->sw_act3, sizeof(src->sw_act3)) < 0) {
        return 1;
    }

    /* Absolute encoder statusword of Actuator 3 */
    if (lfs_file_write(log->lfs, log->file, &src->abs_enc_sw_act3, sizeof(src->abs_enc_sw_act3)) < 0) {
        return 1;
    }

    /* Position of Actuator 4 [mm] */
    if (lfs_file_write(log->lfs, log->file, &src->pos_act4, sizeof(src->pos_act4)) < 0) {
        return 1;
    }

    /* Absolute Position of Actuator 4 [mm] */
    if (lfs_file_write(log->lfs, log->file, &src->abs_pos_act4, sizeof(src->abs_pos_act4)) < 0) {
        return 1;
    }

    /* Velocity of Actuator 4 [mm/s] */
    if (lfs_file_write(log->lfs, log->file, &src->vel_act4, sizeof(src->vel_act4)) < 0) {
        return 1;
    }

    /* Current of Actuator 4 [A] */
    if (lfs_file_write(log->lfs, log->file, &src->curr_act4, sizeof(src->curr_act4)) < 0) {
        return 1;
    }

    /* Statusword of Actuator 4 */
    if (lfs_file_write(log->lfs, log->file, &src->sw_act4, sizeof(src->sw_act4)) < 0) {
        return 1;
    }

    /* Absolute encoder statusword of Actuator 4 */
    if (lfs_file_write(log->lfs, log->file, &src->abs_enc_sw_act4, sizeof(src->abs_enc_sw_act4)) < 0) {
        return 1;
    }

    
    return 0;
}
