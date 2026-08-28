/**
 * @file    ulog_manual_control.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_manual_control.h"
#include "ulog_def.h"

const char ulog_manual_control_format[] = "manual_control:uint64_t timestamp;uint8_t target;int16_t x;int16_t y;int16_t z;int16_t r;uint16_t buttons;uint16_t buttons2;uint8_t enabled_extensions;int16_t s;int16_t t;int16_t aux1;int16_t aux2;int16_t aux3;int16_t aux4;int16_t aux5;int16_t aux6;";
const char ulog_manual_control_name[] = "manual_control";

int32_t ulog_format_manual_control(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_manual_control_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_manual_control_format, sizeof(ulog_manual_control_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_manual_control(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_manual_control_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_manual_control_name, sizeof(ulog_manual_control_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_manual_control(ulog_t *log, ulog_msg_id_t id, const ulog_manual_control_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(uint8_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
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

    /* The system to be controlled. */
    if (lfs_file_write(log->lfs, log->file, &src->target, sizeof(src->target)) < 0) {
        return 1;
    }

    /* X-axis, normalized to the range [-1000,1000]. A value of INT16_MAX indicates that this axis is invalid. Generally corresponds to forward(1000)-backward(-1000) movement on a joystick and the pitch of a vehicle. */
    if (lfs_file_write(log->lfs, log->file, &src->x, sizeof(src->x)) < 0) {
        return 1;
    }

    /* Y-axis, normalized to the range [-1000,1000]. A value of INT16_MAX indicates that this axis is invalid. Generally corresponds to left(-1000)-right(1000) movement on a joystick and the roll of a vehicle. */
    if (lfs_file_write(log->lfs, log->file, &src->y, sizeof(src->y)) < 0) {
        return 1;
    }

    /* Z-axis, normalized to the range [-1000,1000]. A value of INT16_MAX indicates that this axis is invalid. Generally corresponds to a separate slider movement with maximum being 1000 and minimum being -1000 on a joystick and the thrust of a vehicle. Positive values are positive thrust, negative values are negative thrust. */
    if (lfs_file_write(log->lfs, log->file, &src->z, sizeof(src->z)) < 0) {
        return 1;
    }

    /* R-axis, normalized to the range [-1000,1000]. A value of INT16_MAX indicates that this axis is invalid. Generally corresponds to a twisting of the joystick, with counter-clockwise being 1000 and clockwise being -1000, and the yaw of a vehicle. */
    if (lfs_file_write(log->lfs, log->file, &src->r, sizeof(src->r)) < 0) {
        return 1;
    }

    /* A bitfield corresponding to the joystick buttons' 0-15 current state, 1 for pressed, 0 for released. The lowest bit corresponds to Button 1. */
    if (lfs_file_write(log->lfs, log->file, &src->buttons, sizeof(src->buttons)) < 0) {
        return 1;
    }

    /* A bitfield corresponding to the joystick buttons' 16-31 current state, 1 for pressed, 0 for released. The lowest bit corresponds to Button 16. */
    if (lfs_file_write(log->lfs, log->file, &src->buttons2, sizeof(src->buttons2)) < 0) {
        return 1;
    }

    /* Set bits to 1 to indicate which of the following extension fields contain valid data: bit 0: pitch, bit 1: roll, bit 2: aux1, bit 3: aux2, bit 4: aux3, bit 5: aux4, bit 6: aux5, bit 7: aux6 */
    if (lfs_file_write(log->lfs, log->file, &src->enabled_extensions, sizeof(src->enabled_extensions)) < 0) {
        return 1;
    }

    /* Pitch-only-axis, normalized to the range [-1000,1000]. Generally corresponds to pitch on vehicles with additional degrees of freedom. Valid if bit 0 of enabled_extensions field is set. Set to 0 if invalid. */
    if (lfs_file_write(log->lfs, log->file, &src->s, sizeof(src->s)) < 0) {
        return 1;
    }

    /* Roll-only-axis, normalized to the range [-1000,1000]. Generally corresponds to roll on vehicles with additional degrees of freedom. Valid if bit 1 of enabled_extensions field is set. Set to 0 if invalid. */
    if (lfs_file_write(log->lfs, log->file, &src->t, sizeof(src->t)) < 0) {
        return 1;
    }

    /* Aux continuous input field 1. Normalized in the range [-1000,1000]. Purpose defined by recipient. Valid data if bit 2 of enabled_extensions field is set. 0 if bit 2 is unset. */
    if (lfs_file_write(log->lfs, log->file, &src->aux1, sizeof(src->aux1)) < 0) {
        return 1;
    }

    /* Aux continuous input field 2. Normalized in the range [-1000,1000]. Purpose defined by recipient. Valid data if bit 3 of enabled_extensions field is set. 0 if bit 3 is unset. */
    if (lfs_file_write(log->lfs, log->file, &src->aux2, sizeof(src->aux2)) < 0) {
        return 1;
    }

    /* Aux continuous input field 3. Normalized in the range [-1000,1000]. Purpose defined by recipient. Valid data if bit 4 of enabled_extensions field is set. 0 if bit 4 is unset. */
    if (lfs_file_write(log->lfs, log->file, &src->aux3, sizeof(src->aux3)) < 0) {
        return 1;
    }

    /* Aux continuous input field 4. Normalized in the range [-1000,1000]. Purpose defined by recipient. Valid data if bit 5 of enabled_extensions field is set. 0 if bit 5 is unset. */
    if (lfs_file_write(log->lfs, log->file, &src->aux4, sizeof(src->aux4)) < 0) {
        return 1;
    }

    /* Aux continuous input field 5. Normalized in the range [-1000,1000]. Purpose defined by recipient. Valid data if bit 6 of enabled_extensions field is set. 0 if bit 6 is unset. */
    if (lfs_file_write(log->lfs, log->file, &src->aux5, sizeof(src->aux5)) < 0) {
        return 1;
    }

    /* Aux continuous input field 6. Normalized in the range [-1000,1000]. Purpose defined by recipient. Valid data if bit 7 of enabled_extensions field is set. 0 if bit 7 is unset. */
    if (lfs_file_write(log->lfs, log->file, &src->aux6, sizeof(src->aux6)) < 0) {
        return 1;
    }

    
    return 0;
}
