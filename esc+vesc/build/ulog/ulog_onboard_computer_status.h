/**
 * @file    ulog_onboard_computer_status.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_ONBOARD_COMPUTER_STATUS_H
#define ULOG_ONBOARD_COMPUTER_STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_onboard_computer_status_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint64_t time_usec; /* Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number. [us] */
    uint32_t uptime; /* Time since system boot. [ms] */
    uint8_t type; /* Type of the onboard computer: 0: Mission computer primary, 1: Mission computer backup 1, 2: Mission computer backup 2, 3: Compute node, 4-5: Compute spares, 6-9: Payload computers. */
    uint8_t cpu_cores[8]; /* CPU usage on the component in percent (100 - idle). A value of UINT8_MAX implies the field is unused. */
    uint8_t cpu_combined[10]; /* Combined CPU usage as the last 10 slices of 100 MS (a histogram). This allows to identify spikes in load that max out the system, but only for a short amount of time. A value of UINT8_MAX implies the field is unused. */
    uint8_t gpu_cores[4]; /* GPU usage on the component in percent (100 - idle). A value of UINT8_MAX implies the field is unused. */
    uint8_t gpu_combined[10]; /* Combined GPU usage as the last 10 slices of 100 MS (a histogram). This allows to identify spikes in load that max out the system, but only for a short amount of time. A value of UINT8_MAX implies the field is unused. */
    int8_t temperature_board; /* Temperature of the board. A value of INT8_MAX implies the field is unused. [degC] */
    int8_t temperature_core[8]; /* Temperature of the CPU core. A value of INT8_MAX implies the field is unused. [degC] */
    int16_t fan_speed[4]; /* Fan speeds. A value of INT16_MAX implies the field is unused. [rpm] */
    uint32_t ram_usage; /* Amount of used RAM on the component system. A value of UINT32_MAX implies the field is unused. [MiB] */
    uint32_t ram_total; /* Total amount of RAM on the component system. A value of UINT32_MAX implies the field is unused. [MiB] */
    uint32_t storage_type[4]; /* Storage type: 0: HDD, 1: SSD, 2: EMMC, 3: SD card (non-removable), 4: SD card (removable). A value of UINT32_MAX implies the field is unused. */
    uint32_t storage_usage[4]; /* Amount of used storage space on the component system. A value of UINT32_MAX implies the field is unused. [MiB] */
    uint32_t storage_total[4]; /* Total amount of storage space on the component system. A value of UINT32_MAX implies the field is unused. [MiB] */
    uint32_t link_type[6]; /* Link type: 0-9: UART, 10-19: Wired network, 20-29: Wifi, 30-39: Point-to-point proprietary, 40-49: Mesh proprietary */
    uint32_t link_tx_rate[6]; /* Network traffic from the component system. A value of UINT32_MAX implies the field is unused. [KiB/s] */
    uint32_t link_rx_rate[6]; /* Network traffic to the component system. A value of UINT32_MAX implies the field is unused. [KiB/s] */
    uint32_t link_tx_max[6]; /* Network capacity from the component system. A value of UINT32_MAX implies the field is unused. [KiB/s] */
    uint32_t link_rx_max[6]; /* Network capacity to the component system. A value of UINT32_MAX implies the field is unused. [KiB/s] */
    
} ulog_onboard_computer_status_t;

/**
 * Defines Onboard Computer Status message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_onboard_computer_status(ulog_t *log);

/**
 * Subscribe Onboard Computer Status message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_onboard_computer_status(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Onboard Computer Status message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_onboard_computer_status(ulog_t *log, ulog_msg_id_t id, const ulog_onboard_computer_status_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_ONBOARD_COMPUTER_STATUS_H */