/**
 * @file    ulog_onboard_computer_status.c
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */
#include <stdint.h>

#include "ulog_onboard_computer_status.h"
#include "ulog_def.h"

const char ulog_onboard_computer_status_format[] = "onboard_computer_status:uint64_t timestamp;uint64_t time_usec;uint32_t uptime;uint8_t type;uint8_t[8] cpu_cores;uint8_t[10] cpu_combined;uint8_t[4] gpu_cores;uint8_t[10] gpu_combined;int8_t temperature_board;int8_t[8] temperature_core;int16_t[4] fan_speed;uint32_t ram_usage;uint32_t ram_total;uint32_t[4] storage_type;uint32_t[4] storage_usage;uint32_t[4] storage_total;uint32_t[6] link_type;uint32_t[6] link_tx_rate;uint32_t[6] link_rx_rate;uint32_t[6] link_tx_max;uint32_t[6] link_rx_max;";
const char ulog_onboard_computer_status_name[] = "onboard_computer_status";

int32_t ulog_format_onboard_computer_status(ulog_t *log)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(ulog_onboard_computer_status_format) - 1,
        .msg_type = ULOG_DEF_MSG_TYPE_FORMAT_DEFINITION,
    };

    if(log->state == ULOG_STATE_HEADER_CREATED)
        log->state = ULOG_STATE_DEFINITIONS_CREATED;

    if(log->state != ULOG_STATE_DEFINITIONS_CREATED)
        return 1;

    if (lfs_file_write(log->lfs, log->file, &header, sizeof(header)) < 0) {
        return 1;
    }

    if (lfs_file_write(log->lfs, log->file, ulog_onboard_computer_status_format, sizeof(ulog_onboard_computer_status_format) - 1) < 0) {
        return 1;
    }

    return 0;
}

int32_t ulog_subscribe_onboard_computer_status(ulog_t *log, uint8_t multi_id, uint16_t *id)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint8_t) + sizeof(uint16_t) + sizeof(ulog_onboard_computer_status_name) - 1,
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

    if (lfs_file_write(log->lfs, log->file, ulog_onboard_computer_status_name, sizeof(ulog_onboard_computer_status_name) - 1) < 0) {
        return 1;
    }

    *id = log->msg_cnt++;

    return 0;
}

int32_t ulog_write_onboard_computer_status(ulog_t *log, ulog_msg_id_t id, const ulog_onboard_computer_status_t *src)
{
    ulog_message_header_t header = {
        .msg_size = sizeof(uint16_t)
                    + sizeof(uint64_t)
                    + sizeof(uint64_t)
                    + sizeof(uint32_t)
                    + sizeof(uint8_t)
                    + sizeof(uint8_t)*8
                    + sizeof(uint8_t)*10
                    + sizeof(uint8_t)*4
                    + sizeof(uint8_t)*10
                    + sizeof(int8_t)
                    + sizeof(int8_t)*8
                    + sizeof(int16_t)*4
                    + sizeof(uint32_t)
                    + sizeof(uint32_t)
                    + sizeof(uint32_t)*4
                    + sizeof(uint32_t)*4
                    + sizeof(uint32_t)*4
                    + sizeof(uint32_t)*6
                    + sizeof(uint32_t)*6
                    + sizeof(uint32_t)*6
                    + sizeof(uint32_t)*6
                    + sizeof(uint32_t)*6
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

    /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    if (lfs_file_write(log->lfs, log->file, &src->time_usec, sizeof(src->time_usec)) < 0) {
        return 1;
    }

    /* Time since system boot. [ms] */
    if (lfs_file_write(log->lfs, log->file, &src->uptime, sizeof(src->uptime)) < 0) {
        return 1;
    }

    /* Type of the onboard computer: 0: Mission computer primary, 1: Mission computer backup 1, 2: Mission computer backup 2, 3: Compute node, 4-5: Compute spares, 6-9: Payload computers. */
    if (lfs_file_write(log->lfs, log->file, &src->type, sizeof(src->type)) < 0) {
        return 1;
    }

    /* CPU usage on the component in percent (100 - idle). A value of UINT8_MAX implies the field is unused. */
    if (lfs_file_write(log->lfs, log->file, src->cpu_cores, sizeof(src->cpu_cores)) < 0) {
        return 1;
    }

    /* Combined CPU usage as the last 10 slices of 100 MS (a histogram). This allows to identify spikes in load that max out the system, but only for a short amount of time. A value of UINT8_MAX implies the field is unused. */
    if (lfs_file_write(log->lfs, log->file, src->cpu_combined, sizeof(src->cpu_combined)) < 0) {
        return 1;
    }

    /* GPU usage on the component in percent (100 - idle). A value of UINT8_MAX implies the field is unused. */
    if (lfs_file_write(log->lfs, log->file, src->gpu_cores, sizeof(src->gpu_cores)) < 0) {
        return 1;
    }

    /* Combined GPU usage as the last 10 slices of 100 MS (a histogram). This allows to identify spikes in load that max out the system, but only for a short amount of time. A value of UINT8_MAX implies the field is unused. */
    if (lfs_file_write(log->lfs, log->file, src->gpu_combined, sizeof(src->gpu_combined)) < 0) {
        return 1;
    }

    /* Temperature of the board. A value of INT8_MAX implies the field is unused. [degC] */
    if (lfs_file_write(log->lfs, log->file, &src->temperature_board, sizeof(src->temperature_board)) < 0) {
        return 1;
    }

    /* Temperature of the CPU core. A value of INT8_MAX implies the field is unused. [degC] */
    if (lfs_file_write(log->lfs, log->file, src->temperature_core, sizeof(src->temperature_core)) < 0) {
        return 1;
    }

    /* Fan speeds. A value of INT16_MAX implies the field is unused. [rpm] */
    if (lfs_file_write(log->lfs, log->file, src->fan_speed, sizeof(src->fan_speed)) < 0) {
        return 1;
    }

    /* Amount of used RAM on the component system. A value of UINT32_MAX implies the field is unused. [MiB] */
    if (lfs_file_write(log->lfs, log->file, &src->ram_usage, sizeof(src->ram_usage)) < 0) {
        return 1;
    }

    /* Total amount of RAM on the component system. A value of UINT32_MAX implies the field is unused. [MiB] */
    if (lfs_file_write(log->lfs, log->file, &src->ram_total, sizeof(src->ram_total)) < 0) {
        return 1;
    }

    /* Storage type: 0: HDD, 1: SSD, 2: EMMC, 3: SD card (non-removable), 4: SD card (removable). A value of UINT32_MAX implies the field is unused. */
    if (lfs_file_write(log->lfs, log->file, src->storage_type, sizeof(src->storage_type)) < 0) {
        return 1;
    }

    /* Amount of used storage space on the component system. A value of UINT32_MAX implies the field is unused. [MiB] */
    if (lfs_file_write(log->lfs, log->file, src->storage_usage, sizeof(src->storage_usage)) < 0) {
        return 1;
    }

    /* Total amount of storage space on the component system. A value of UINT32_MAX implies the field is unused. [MiB] */
    if (lfs_file_write(log->lfs, log->file, src->storage_total, sizeof(src->storage_total)) < 0) {
        return 1;
    }

    /* Link type: 0-9: UART, 10-19: Wired network, 20-29: Wifi, 30-39: Point-to-point proprietary, 40-49: Mesh proprietary */
    if (lfs_file_write(log->lfs, log->file, src->link_type, sizeof(src->link_type)) < 0) {
        return 1;
    }

    /* Network traffic from the component system. A value of UINT32_MAX implies the field is unused. [KiB/s] */
    if (lfs_file_write(log->lfs, log->file, src->link_tx_rate, sizeof(src->link_tx_rate)) < 0) {
        return 1;
    }

    /* Network traffic to the component system. A value of UINT32_MAX implies the field is unused. [KiB/s] */
    if (lfs_file_write(log->lfs, log->file, src->link_rx_rate, sizeof(src->link_rx_rate)) < 0) {
        return 1;
    }

    /* Network capacity from the component system. A value of UINT32_MAX implies the field is unused. [KiB/s] */
    if (lfs_file_write(log->lfs, log->file, src->link_tx_max, sizeof(src->link_tx_max)) < 0) {
        return 1;
    }

    /* Network capacity to the component system. A value of UINT32_MAX implies the field is unused. [KiB/s] */
    if (lfs_file_write(log->lfs, log->file, src->link_rx_max, sizeof(src->link_rx_max)) < 0) {
        return 1;
    }

    
    return 0;
}
