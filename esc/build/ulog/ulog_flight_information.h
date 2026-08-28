/**
 * @file    ulog_flight_information.h
 * @brief   This file is auto-generated using ulog_gen.py
 * @author  LisumLab
 */

#ifndef ULOG_FLIGHT_INFORMATION_H
#define ULOG_FLIGHT_INFORMATION_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "ulog.h"

typedef struct ulog_flight_information_t {
    uint64_t timestamp; /* Timestamp [us] */
    uint32_t time_boot_ms; /* Timestamp (time since system boot). [ms] */
    uint64_t arming_time_utc; /* Timestamp at arming (since system boot). Set to 0 on boot. Set value on arming. Note, field is misnamed UTC. [us] */
    uint64_t takeoff_time_utc; /* Timestamp at takeoff (since system boot). Set to 0 at boot and on arming. Note, field is misnamed UTC. [us] */
    uint64_t flight_uuid; /* Flight number. Note, field is misnamed UUID. */
    uint32_t landing_time; /* Timestamp at landing (in ms since system boot). Set to 0 at boot and on arming. [ms] */
    
} ulog_flight_information_t;

/**
 * Defines Flight Information message name and its inner fields in a single string.
 *
 * @param[in] log ULog struct.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_format_flight_information(ulog_t *log);

/**
 * Subscribe Flight Information message by name and give it and id that is used in Logged data Message.
 * This must come before the first corresponding Logged data Message.
 *
 * @param[in] log ULog struct.
 * @param[in] multi_id Message instance.
 * @param[out] id Message ID assigned to subscribed message.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_subscribe_flight_information(ulog_t *log, uint8_t multi_id, uint16_t *id);

/**
 * Write Flight Information message data.
 *
 * @param[in] log ULog struct.
 * @param[in] id Message ID.
 * @param[in] src Message Data.
 * @return 0 for successful operation.
 * @return Non 0 otherwise.
 */
int32_t ulog_write_flight_information(ulog_t *log, ulog_msg_id_t id, const ulog_flight_information_t *src);

#ifdef __cplusplus
}
#endif

#endif /* ULOG_FLIGHT_INFORMATION_H */