/**
 * @file    kde_helper.h
 * @brief   Helper functions for kde library.
 * @version	0.0.1
 * @date    13.08.2025
 * @author  BetaTehPro
 */

#ifndef KDE_HELPER_H
#define KDE_HELPER_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <stdint.h>
#include "can.h"
#include "kde.h"

/*******************************************************************************
 * Defines
 ******************************************************************************/

/*******************************************************************************
 * Macro functions   
 ******************************************************************************/

#define GET_SRC(ID) (((uint32_t)(ID) >> 16) & 0xFF)
#define GET_DST(ID) (((uint32_t)(ID) >>  8) & 0xFF)
#define GET_OBJ(ID) (((uint32_t)(ID))       & 0xFF)  

 /*******************************************************************************
 * Typedefs
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * API
 ******************************************************************************/

/**
 * @brief   Prepare CAN message frame with KDE protocol formatting.
 * 
 * @param   msg         Pointer to CAN message structure to prepare
 * @param   object_num  Object number indicating operation type
 * @param   source_id   Source node ID
 * @param   dest_id     Destination ESC node ID
 * @param   length      Data payload length in bytes
 * @param   idFormat    CAN ID format (standard/extended)
 * @param   frameType   CAN frame type (data/RTR)
 * 
 * @return  void
 */
void prepare_tx_can_msg (can_hal_msg_t *msg, 
                        object_numbers_e object_num,
                        uint8_t source_id,
                        uint8_t dest_id,
                        uint8_t length,
                        can_hal_id_format_t idFormat,
                        can_hal_frame_t frameType);

/**
 * @brief   Receive and validate CAN response from ESC with timeout.
 * 
 * @param   esc_id      ESC node ID to receive from
 * @param   object      Expected object number in response
 * @param   rx_msg      Pointer to store received CAN message
 * 
 * @return  lStatus_t   Status code indicating success or failure
 */
lStatus_t kde_receive_response (uint8_t esc_id, 
                                uint8_t object, 
                                can_hal_msg_t *rx_msg);


/**
 * @brief   Request 32-bit unsigned integer value from ESC.
 * 
 * @param   esc_id      ESC node ID on CAN bus
 * @param   object      Object number to request
 * @param   out         Pointer to store retrieved 32-bit value
 * 
 * @return  lStatus_t   Status code indicating success or failure
 */
lStatus_t kde_get_u32(uint8_t esc_id, uint8_t object, uint32_t* out);

/**
 * @brief   Request 16-bit unsigned integer value from ESC.
 * 
 * @param   esc_id      ESC node ID on CAN bus
 * @param   object      Object number to request
 * @param   out         Pointer to store retrieved 16-bit value
 * 
 * @return  lStatus_t   Status code indicating success or failure
 */
lStatus_t kde_get_u16(uint8_t esc_id, uint8_t object, uint16_t* out);

/**
 * @brief   Request 8-bit unsigned integer value from ESC.
 * 
 * @param   esc_id      ESC node ID on CAN bus
 * @param   object      Object number to request
 * @param   out         Pointer to store retrieved 8-bit value
 * 
 * @return  lStatus_t   Status code indicating success or failure
 */
lStatus_t kde_get_u8(uint8_t esc_id, uint8_t object, uint8_t* out);

/**
 * @brief   Delay code for the x ms
 * 
 * @param   esc_id      Time of delay
 * 
 * @return  null
 */
void local_delay_ms(uint32_t ms);

#ifdef __cplusplus
}
#endif

#endif /* KDE_HELPER_H */