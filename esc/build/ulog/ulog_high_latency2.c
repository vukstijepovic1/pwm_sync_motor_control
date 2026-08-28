/**
 * @file    ulog_high_latency2.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_high_latency2.h"
#include "ulog_def.h"

const char ulog_high_latency2_format[] = "high_latency2:uint64_t timestamp;uint8_t type;uint8_t autopilot;uint16_t custom_mode;int32_t latitude;int32_t longitude;int16_t altitude;int16_t target_altitude;uint8_t heading;uint8_t target_heading;uint16_t target_distance;uint8_t throttle;uint8_t airspeed;uint8_t airspeed_sp;uint8_t groundspeed;uint8_t windspeed;uint8_t wind_heading;uint8_t eph;uint8_t epv;int8_t temperature_air;int8_t climb_rate;int8_t battery;uint16_t wp_num;uint16_t failure_flags;int8_t custom0;int8_t custom1;int8_t custom2;";
const char ulog_high_latency2_name[] = "high_latency2";

int32_t ulog_format_high_latency2(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_high_latency2_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_high_latency2_format, sizeof(ulog_high_latency2_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_high_latency2(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_high_latency2_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_high_latency2_name, sizeof(ulog_high_latency2_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_high_latency2(ulog_t *log, ulog_msg_id_t id, const ulog_high_latency2_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint16_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint16_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(int8_t)
                    + sizeof(int8_t)
                    + sizeof(int8_t)
                    + sizeof(uint16_t)
                    + sizeof(uint16_t)
                    + sizeof(int8_t)
                    + sizeof(int8_t)
                    + sizeof(int8_t)
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

    /* Type of the MAV (quadrotor, helicopter, etc.) */
    if (lfs_file_write(log->lfs, log->file, &src->type, sizeof(src->type)) < 0) {
        return 1;
    }

    /* Autopilot type / class. Use MAV_AUTOPILOT_INVALID for components that are not flight controllers. */
    if (lfs_file_write(log->lfs, log->file, &src->autopilot, sizeof(src->autopilot)) < 0) {
        return 1;
    }

    /* A bitfield for use for autopilot-specific flags (2 byte version). */
    if (lfs_file_write(log->lfs, log->file, &src->custom_mode, sizeof(src->custom_mode)) < 0) {
        return 1;
    }

    /* Latitude [degE7] */
    if (lfs_file_write(log->lfs, log->file, &src->latitude, sizeof(src->latitude)) < 0) {
        return 1;
    }

    /* Longitude [degE7] */
    if (lfs_file_write(log->lfs, log->file, &src->longitude, sizeof(src->longitude)) < 0) {
        return 1;
    }

    /* Altitude above mean sea level [m] */
    if (lfs_file_write(log->lfs, log->file, &src->altitude, sizeof(src->altitude)) < 0) {
        return 1;
    }

    /* Altitude setpoint [m] */
    if (lfs_file_write(log->lfs, log->file, &src->target_altitude, sizeof(src->target_altitude)) < 0) {
        return 1;
    }

    /* Heading [deg/2] */
    if (lfs_file_write(log->lfs, log->file, &src->heading, sizeof(src->heading)) < 0) {
        return 1;
    }

    /* Heading setpoint [deg/2] */
    if (lfs_file_write(log->lfs, log->file, &src->target_heading, sizeof(src->target_heading)) < 0) {
        return 1;
    }

    /* Distance to target waypoint or position [dam] */
    if (lfs_file_write(log->lfs, log->file, &src->target_distance, sizeof(src->target_distance)) < 0) {
        return 1;
    }

    /* Throttle [%] */
    if (lfs_file_write(log->lfs, log->file, &src->throttle, sizeof(src->throttle)) < 0) {
        return 1;
    }

    /* Airspeed [m/s*5] */
    if (lfs_file_write(log->lfs, log->file, &src->airspeed, sizeof(src->airspeed)) < 0) {
        return 1;
    }

    /* Airspeed setpoint [m/s*5] */
    if (lfs_file_write(log->lfs, log->file, &src->airspeed_sp, sizeof(src->airspeed_sp)) < 0) {
        return 1;
    }

    /* Groundspeed [m/s*5] */
    if (lfs_file_write(log->lfs, log->file, &src->groundspeed, sizeof(src->groundspeed)) < 0) {
        return 1;
    }

    /* Windspeed [m/s*5] */
    if (lfs_file_write(log->lfs, log->file, &src->windspeed, sizeof(src->windspeed)) < 0) {
        return 1;
    }

    /* Wind heading [deg/2] */
    if (lfs_file_write(log->lfs, log->file, &src->wind_heading, sizeof(src->wind_heading)) < 0) {
        return 1;
    }

    /* Maximum error horizontal position since last message [dm] */
    if (lfs_file_write(log->lfs, log->file, &src->eph, sizeof(src->eph)) < 0) {
        return 1;
    }

    /* Maximum error vertical position since last message [dm] */
    if (lfs_file_write(log->lfs, log->file, &src->epv, sizeof(src->epv)) < 0) {
        return 1;
    }

    /* Air temperature from airspeed sensor [degC] */
    if (lfs_file_write(log->lfs, log->file, &src->temperature_air, sizeof(src->temperature_air)) < 0) {
        return 1;
    }

    /* Maximum climb rate magnitude since last message [dm/s] */
    if (lfs_file_write(log->lfs, log->file, &src->climb_rate, sizeof(src->climb_rate)) < 0) {
        return 1;
    }

    /* Battery level (-1 if field not provided). [%] */
    if (lfs_file_write(log->lfs, log->file, &src->battery, sizeof(src->battery)) < 0) {
        return 1;
    }

    /* Current waypoint number */
    if (lfs_file_write(log->lfs, log->file, &src->wp_num, sizeof(src->wp_num)) < 0) {
        return 1;
    }

    /* Bitmap of failure flags. */
    if (lfs_file_write(log->lfs, log->file, &src->failure_flags, sizeof(src->failure_flags)) < 0) {
        return 1;
    }

    /* Field for custom payload. */
    if (lfs_file_write(log->lfs, log->file, &src->custom0, sizeof(src->custom0)) < 0) {
        return 1;
    }

    /* Field for custom payload. */
    if (lfs_file_write(log->lfs, log->file, &src->custom1, sizeof(src->custom1)) < 0) {
        return 1;
    }

    /* Field for custom payload. */
    if (lfs_file_write(log->lfs, log->file, &src->custom2, sizeof(src->custom2)) < 0) {
        return 1;
    }

    
    return 0;
}
