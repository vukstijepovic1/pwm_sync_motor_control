/**
 * @file    ftp_handler.h
 * @brief   Drivers for VESC.
 * @version 0.0.1
 * @date    12.08.2025
 * @author  BetaTehPro
 */

#ifndef VESC_H
#define VESC_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <stdint.h>
#include <stdbool.h>
#include "can.h"
#include "pwm.h"
#include "mav.h"
#include "uart.h"

/*******************************************************************************
 * Defines - Config
 ******************************************************************************/

#define UART_BAUD_RATE_ESC         1000000
#define MINE_CAN_ID                0   

#define KDE_CAN_HAL_INSTANCE       CAN_HAL_INSTANCE_0
#define KDE_W8_FOR_STATUS_RESP_MS  500 
#define KDE_CAN_TIMEOUT            10 //KDE_W8_FOR_STATUS_RESP_MS * 1000
#define KDE_CAN_RX_TIMEOUT         700 
#define KDE_MOTOR_POLES_NUMBER     42  
#define KDE_MINIMUM_PWM            1100
#define KDE_COEF_MUL_PWM           8.4f
#define KDE_BROADCAST_ID           1   
#define KDE_MAX_ESC                4

#define KDE_PWM_HAL_INSTANCE       PWM_HAL_INSTANCE_0
#define KDE_PWM_PERIOD_US          20000              /* 20ms => 50Hz, shared by all ESCs */
#define KDE_USE_PWM                1
#define KDE_TEST_PWM               1300



/*******************************************************************************
 * Enums
 ******************************************************************************/

typedef enum {
    CAN_OBJECT_GET_INFO           = 0,  // :)
    CAN_OBJECT_SET_PWM            = 1,  // :)
    CAN_OBJECT_GET_VOLTAGE        = 2,  // :)
    CAN_OBJECT_GET_CURRENT        = 3,  // :)
    CAN_OBJECT_GET_RPM            = 4,  // :)
    CAN_OBJECT_GET_TEMP           = 5,  // :)
    CAN_OBJECT_GET_THROTTLE_IN    = 6,  // :)
    CAN_OBJECT_GET_THROTTLE_OUT   = 7,  // :)
    CAN_OBJECT_GET_MCU_IDS        = 8,  //  SA VISE UREDJAJA
    CAN_OBJECT_UPDATE_NODE_ADDR   = 9,  //  SA VISE UREDJAJA
    CAN_OBJECT_START_ENUM         = 10, //  SA VISE UREDJAJA
    CAN_OBJECT_GET_BASE_STAT      = 11, // :)
    CAN_OBJECT_SET_DIRECTION      = 12, // :)
    CAN_OBJECT_GET_RAW_COUNT      = 13, // :)
    CAN_OBJECT_TURN_OFF           = 32, // :)
    CAN_OBJECT_RESTART            = 33, // :)
    CAN_OBJECT_GET_DEBUGG_INFO    = 34  //  ?
} object_numbers_e;

typedef enum {
    CAN_RETURN_TYPE_UINT8         = 0,
    CAN_RETURN_TYPE_INT8          = 1,
    CAN_RETURN_TYPE_UINT16        = 2,
    CAN_RETURN_TYPE_INT16         = 3
} kde_return_type_e;

typedef enum {
    KDE_DIR_FORWARD               = 1,
    KDE_DIR_REVERSE               = 2
} kde_dir_e;


typedef enum{
    CAD_FLAG_STALL_PROTECTION     = 0,
    CAD_FLAG_OVER_TEMPERATURE     = 1,
    CAD_FLAG_OVERLOAD_PROTECTION  = 2,
    CAD_FLAG_OVER_VOLTAGE         = 3,
    CAD_FLAG_LOW_VOLTAGE          = 4,
    CAD_FLAG_VOLTAGE_CUTOFF       = 5
} kde_warning_type_e;

/*******************************************************************************
 * Channel map
 ******************************************************************************/

static const struct {
    uint8_t           id;
    pwm_hal_channel_t ch;
}kde_pwm_channel_map[] = {
    {2, PWM_HAL_CHANNEL_1}, /* P1.18 */
    {3, PWM_HAL_CHANNEL_2}, /* P1. */
    {4, PWM_HAL_CHANNEL_3}, /* P1. */
    {5, PWM_HAL_CHANNEL_4}, /* P1. */
}; 

#define KDE_PWM_CHANNEL_PWM_LEN \
    (sizeof(kde_pwm_channel_map) / sizeof(kde_pwm_channel_map[0]))

/*******************************************************************************
 * Structs
 ******************************************************************************/


/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/**
 * @brief   Send a bare request frame (no payload) to an ESC.
 *
 * @details Fire-and-forget: only transmits the request. The ESC's reply is
 *          delivered asynchronously through the RX ISR -> queue_esc_rx and
 *          parsed in task_bridge, which writes the result into esc_fleet[].
 *
 * @param   esc_id      ESC node ID on CAN bus.
 * @param   object      Object number to request.
 *
 * @return  lStatus_t   Status of the CAN transmit only.
 */
lStatus_t kde_request(uint8_t esc_id, object_numbers_e object);

/**
 * @brief   Request ESC firmware, hardware version and operating mode info.
 *
 * @details Fire-and-forget; response handled in task_bridge.
 *
 * @param   esc_id      ESC node ID on CAN bus.
 *
 * @return  lStatus_t   Status of the CAN transmit only.
 */
lStatus_t kde_get_info(uint8_t esc_id);

/**
 * @brief   Initialize the local PWM peripheral used to mirror each ESC's
 *          throttle command onto its own dedicated physical PWM pin.
 *
 * @details Configures the shared period (channel 0) plus one duty-cycle
 *          match channel per ESC listed in kde.c's esc_id -> PWM channel
 *          map, starts every output at KDE_MINIMUM_PWM and activates the
 *          peripheral. Call once before kde_set_pwm().
 *
 * @return  lStatus_t   Status code indicating success or failure.
 */
lStatus_t kde_pwm_init(void);

/**
 * @brief   Set PWM duty cycle for the motor.
 *
 * @details Sends the command over CAN and, if esc_id has a mapped physical
 *          PWM pin (see kde.c), mirrors the same value onto it so both stay
 *          in sync. ESCs without a mapped pin are CAN-only.
 *
 * @param   esc_id      ESC node ID on CAN bus.
 * @param   pwm         PWM value to set.
 *
 * @return  lStatus_t   Status code indicating success or failure.
 */
lStatus_t kde_set_pwm(uint8_t esc_id, int16_t pwm);

/**
 * @brief   Set motor duty cycle.
 *
 * @param   esc_id      ESC node ID on CAN bus.
 * @param   duty        Motor duty cycle value to set.
 *
 * @return  lStatus_t   Status code indicating success or failure.
 */
lStatus_t kde_set_duty(uint8_t esc_id, int16_t duty);

/**
 * @brief   Set motor spin direction.
 *
 * @details The ESC only accepts this command while the motor is stopped.
 *          The command is rejected (echoes 0xFF) if the motor is spinning;
 *          that echo arrives asynchronously and is handled in task_bridge.
 *
 * @param   esc_id      ESC node ID on CAN bus.
 * @param   direction   KDE_DIR_FORWARD or KDE_DIR_REVERSE.
 *
 * @return  lStatus_t   Status of the CAN transmit only.
 */
lStatus_t kde_set_direction(uint8_t esc_id, uint8_t direction);

/**
 * @brief   Get the raw eRPM commutation-step counter.
 *
 * @details Free-running counter that increments on every commutation step
 *          and never resets except by overflow wrap-around. Use
 *          kde_raw_to_rpm() on two successive readings to compute RPM.
 *
 * @param   esc_id      ESC node ID on CAN bus.
 *
 * @return  lStatus_t   Status of the CAN transmit only.
 */
lStatus_t kde_get_raw_rpm(uint8_t esc_id);

/**
 * @brief   Convert two eRPM raw counter samples into a mechanical RPM value.
 *
 * @param   raw_prev     Previous raw counter reading.
 * @param   raw_curr     Current raw counter reading.
 * @param   dt_ms        Elapsed time between the two readings, in milliseconds.
 *
 * @return  float        Computed RPM, or 0.0f if dt_ms = 0.
 */
float kde_raw_to_rpm(uint32_t raw_prev, uint32_t raw_curr, uint32_t dt_ms);

/**
 * @brief   Get battery voltage measured by the ESC.
 *
 * @param   esc_id      ESC node ID on CAN bus.
 *
 * @return  lStatus_t   Status of the CAN transmit only.
 */
lStatus_t kde_get_voltage(uint8_t esc_id);

/**
 * @brief   Get motor current consumption.
 *
 * @param   esc_id      ESC node ID on CAN bus.
 *
 * @return  lStatus_t   Status of the CAN transmit only.
 */
lStatus_t kde_get_current(uint8_t esc_id);

/**
 * @brief   Get motor speed in revolutions per minute.
 *
 * @param   esc_id      ESC node ID on CAN bus.
 *
 * @return  lStatus_t   Status of the CAN transmit only.
 */
lStatus_t kde_get_rpm(uint8_t esc_id);

/**
 * @brief   Get ESC temperature.
 *
 * @param   esc_id      ESC node ID on CAN bus.
 *
 * @return  lStatus_t   Status of the CAN transmit only.
 */
lStatus_t kde_get_temp(uint8_t esc_id);

/**
 * @brief   Get input throttle command value.
 *
 * @param   esc_id          ESC node ID on CAN bus.
 *
 * @return  lStatus_t       Status of the CAN transmit only.
 */
lStatus_t kde_get_throttle_in(uint8_t esc_id);

/**
 * @brief   Get output throttle value after ESC processing.
 *
 * @param   esc_id           ESC node ID on CAN bus.
 *
 * @return  lStatus_t        Status of the CAN transmit only.
 */
lStatus_t kde_get_throttle_out(uint8_t esc_id);

/**
 * @brief   Start ESC enumeration.
 *
 * @details Sends a broadcast command to start the ESC enumeration process.
 *          During enumeration, ESCs can be identified by manually rotating
 *          each motor in turn.
 *
 * @param   timeout_ms  Duration of the enumeration window in milliseconds.
 *
 * @return  lStatus_t   Status code indicating success or failure.
 */
lStatus_t kde_start_enum(uint16_t timeout_ms);

/**
 * @brief   Receive an ESC enumeration response.
 *
 * @details Retrieves the MCU ID of the ESC whose motor was rotated during
 *          the enumeration process. This function should be called
 *          repeatedly during the enumeration window, once per motor.
 *
 * @note    Blocking read - only valid while the RX ISR forwarding to
 *          queue_esc_rx is disabled for the enum window.
 *
 * @param   mcu_ids     Buffer to store the 8-byte MCU ID.
 *
 * @return  lStatus_t   Status code indicating success or failure.
 */
lStatus_t kde_enum_receive(int8_t* mcu_ids);

/**
 * @brief   Assign a new CAN node address to an ESC.
 *
 * @param   new_node    New CAN node address to assign.
 * @param   mcu_ids     8-byte unique MCU ID of the target ESC.
 *
 * @return  lStatus_t   Status code indicating success or failure.
 */
lStatus_t kde_set_node_addr(uint8_t new_node, int8_t* mcu_ids);

/**
 * @brief   Request the unique MCU IDs from every ESC on the bus.
 *
 * @details Sent to the broadcast address; each ESC answers with its own
 *          source address. Replies handled in task_bridge.
 *
 * @return  lStatus_t   Status of the CAN transmit only.
 */
lStatus_t kde_get_mcu_ids(void);

/**
 * @brief   Get complete basic status information from the ESC.
 *
 * @details Requests voltage, current, RPM, temperature and warning flags in
 *          a single frame. The reply is parsed in task_bridge into
 *          esc_fleet[].msg_1 and pushed to queue_status_1.
 *
 * @param   esc_id      ESC node ID on CAN bus.
 *
 * @return  lStatus_t   Status of the CAN transmit only.
 */
lStatus_t kde_get_base_stat(uint8_t esc_id);

/**
 * @brief   Shut down the ESC and stop the motor.
 *
 * @param   esc_id      ESC node ID on CAN bus.
 *
 * @return  lStatus_t   Status code indicating success or failure.
 */
lStatus_t kde_shutdown(uint8_t esc_id);

/**
 * @brief   Restart the ESC.
 *
 * @param   esc_id      ESC node ID on CAN bus.
 *
 * @return  lStatus_t   Status code indicating success or failure.
 */
lStatus_t kde_reset(uint8_t esc_id);

/**
 * @brief   Request error/debug information from the ESC.
 *
 * @param   esc_id      ESC node ID on CAN bus.
 *
 * @return  lStatus_t   Status of the CAN transmit only.
 */
lStatus_t kde_get_error_info(uint8_t esc_id);


/**
 * @brief   Arm the ESC.
 *
 * @param   esc_id      ESC node ID on CAN bus.
 *
 * @return  lStatus_t   Status code indicating success or failure.
 */
lStatus_t kde_arming(uint8_t esc_id);

#ifdef __cplusplus
}
#endif

#endif /* VESC_H */