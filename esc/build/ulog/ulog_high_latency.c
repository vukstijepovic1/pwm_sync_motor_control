/**
 * @file    ulog_high_latency.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_high_latency.h"
#include "ulog_def.h"

const char ulog_high_latency_format[] = "high_latency:uint64_t timestamp;uint8_t base_mode;uint32_t custom_mode;uint8_t landed_state;int16_t roll;int16_t pitch;uint16_t heading;int8_t throttle;int16_t heading_sp;int32_t latitude;int32_t longitude;int16_t altitude_amsl;int16_t altitude_sp;uint8_t airspeed;uint8_t airspeed_sp;uint8_t groundspeed;int8_t climb_rate;uint8_t gps_nsat;uint8_t gps_fix_type;uint8_t battery_remaining;int8_t temperature;int8_t temperature_air;uint8_t failsafe;uint8_t wp_num;uint16_t wp_distance;";
const char ulog_high_latency_name[] = "high_latency";

int32_t ulog_format_high_latency(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_high_latency_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_high_latency_format, sizeof(ulog_high_latency_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_high_latency(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_high_latency_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_high_latency_name, sizeof(ulog_high_latency_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_high_latency(ulog_t *log, ulog_msg_id_t id, const ulog_high_latency_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint8_t)
                    + sizeof(uint32_t)
                    + sizeof(uint8_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(uint16_t)
                    + sizeof(int8_t)
                    + sizeof(int16_t)
                    + sizeof(int32_t)
                    + sizeof(int32_t)
                    + sizeof(int16_t)
                    + sizeof(int16_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(int8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
                    + sizeof(int8_t)
                    + sizeof(int8_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)
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

    /* Bitmap of enabled system modes. */
    if (lfs_file_write(log->lfs, log->file, &src->base_mode, sizeof(src->base_mode)) < 0) {
        return 1;
    }

    /* A bitfield for use for autopilot-specific flags. */
    if (lfs_file_write(log->lfs, log->file, &src->custom_mode, sizeof(src->custom_mode)) < 0) {
        return 1;
    }

    /* The landed state. Is set to MAV_LANDED_STATE_UNDEFINED if landed state is unknown. */
    if (lfs_file_write(log->lfs, log->file, &src->landed_state, sizeof(src->landed_state)) < 0) {
        return 1;
    }

    /* roll [cdeg] */
    if (lfs_file_write(log->lfs, log->file, &src->roll, sizeof(src->roll)) < 0) {
        return 1;
    }

    /* pitch [cdeg] */
    if (lfs_file_write(log->lfs, log->file, &src->pitch, sizeof(src->pitch)) < 0) {
        return 1;
    }

    /* heading [cdeg] */
    if (lfs_file_write(log->lfs, log->file, &src->heading, sizeof(src->heading)) < 0) {
        return 1;
    }

    /* throttle (percentage) [%] */
    if (lfs_file_write(log->lfs, log->file, &src->throttle, sizeof(src->throttle)) < 0) {
        return 1;
    }

    /* heading setpoint [cdeg] */
    if (lfs_file_write(log->lfs, log->file, &src->heading_sp, sizeof(src->heading_sp)) < 0) {
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
    if (lfs_file_write(log->lfs, log->file, &src->altitude_amsl, sizeof(src->altitude_amsl)) < 0) {
        return 1;
    }

    /* Altitude setpoint relative to the home position [m] */
    if (lfs_file_write(log->lfs, log->file, &src->altitude_sp, sizeof(src->altitude_sp)) < 0) {
        return 1;
    }

    /* airspeed [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->airspeed, sizeof(src->airspeed)) < 0) {
        return 1;
    }

    /* airspeed setpoint [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->airspeed_sp, sizeof(src->airspeed_sp)) < 0) {
        return 1;
    }

    /* groundspeed [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->groundspeed, sizeof(src->groundspeed)) < 0) {
        return 1;
    }

    /* climb rate [m/s] */
    if (lfs_file_write(log->lfs, log->file, &src->climb_rate, sizeof(src->climb_rate)) < 0) {
        return 1;
    }

    /* Number of satellites visible. If unknown, set to UINT8_MAX */
    if (lfs_file_write(log->lfs, log->file, &src->gps_nsat, sizeof(src->gps_nsat)) < 0) {
        return 1;
    }

    /* GPS Fix type. */
    if (lfs_file_write(log->lfs, log->file, &src->gps_fix_type, sizeof(src->gps_fix_type)) < 0) {
        return 1;
    }

    /* Remaining battery (percentage) [%] */
    if (lfs_file_write(log->lfs, log->file, &src->battery_remaining, sizeof(src->battery_remaining)) < 0) {
        return 1;
    }

    /* Autopilot temperature (degrees C) [degC] */
    if (lfs_file_write(log->lfs, log->file, &src->temperature, sizeof(src->temperature)) < 0) {
        return 1;
    }

    /* Air temperature (degrees C) from airspeed sensor [degC] */
    if (lfs_file_write(log->lfs, log->file, &src->temperature_air, sizeof(src->temperature_air)) < 0) {
        return 1;
    }

    /* failsafe (each bit represents a failsafe where 0=ok, 1=failsafe active (bit0:RC, bit1:batt, bit2:GPS, bit3:GCS, bit4:fence) */
    if (lfs_file_write(log->lfs, log->file, &src->failsafe, sizeof(src->failsafe)) < 0) {
        return 1;
    }

    /* current waypoint number */
    if (lfs_file_write(log->lfs, log->file, &src->wp_num, sizeof(src->wp_num)) < 0) {
        return 1;
    }

    /* distance to target [m] */
    if (lfs_file_write(log->lfs, log->file, &src->wp_distance, sizeof(src->wp_distance)) < 0) {
        return 1;
    }

    
    return 0;
}
