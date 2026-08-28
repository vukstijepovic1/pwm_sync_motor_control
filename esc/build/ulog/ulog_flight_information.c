/**
 * @file    ulog_flight_information.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_flight_information.h"
#include "ulog_def.h"

const char ulog_flight_information_format[] = "flight_information:uint64_t timestamp;uint32_t time_boot_ms;uint64_t arming_time_utc;uint64_t takeoff_time_utc;uint64_t flight_uuid;uint32_t landing_time;";
const char ulog_flight_information_name[] = "flight_information";

int32_t ulog_format_flight_information(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_flight_information_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_flight_information_format, sizeof(ulog_flight_information_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_flight_information(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_flight_information_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_flight_information_name, sizeof(ulog_flight_information_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_flight_information(ulog_t *log, ulog_msg_id_t id, const ulog_flight_information_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
                    + sizeof(uint64_t)
                    + sizeof(uint64_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
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

    /* Timestamp (time since system boot). [ms] */
    if (lfs_file_write(log->lfs, log->file, &src->time_boot_ms, sizeof(src->time_boot_ms)) < 0) {
        return 1;
    }

    /* Timestamp at arming (since system boot). Set to 0 on boot. Set value on arming. Note, field is misnamed UTC. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->arming_time_utc, sizeof(src->arming_time_utc)) < 0) {
        return 1;
    }

    /* Timestamp at takeoff (since system boot). Set to 0 at boot and on arming. Note, field is misnamed UTC. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->takeoff_time_utc, sizeof(src->takeoff_time_utc)) < 0) {
        return 1;
    }

    /* Flight number. Note, field is misnamed UUID. */
    if (lfs_file_write(log->lfs, log->file, &src->flight_uuid, sizeof(src->flight_uuid)) < 0) {
        return 1;
    }

    /* Timestamp at landing (in ms since system boot). Set to 0 at boot and on arming. [ms] */
    if (lfs_file_write(log->lfs, log->file, &src->landing_time, sizeof(src->landing_time)) < 0) {
        return 1;
    }

    
    return 0;
}
