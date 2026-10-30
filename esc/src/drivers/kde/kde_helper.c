/*
 * @file    kde_helper.c
 * @brief   Helper functions for kde library.
 * @version	0.0.1
 * @date    13.08.2025
 * @author  BetaTehPro
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "kde_helper.h"
#include "util.h"
#include <string.h>

#include "FreeRTOS.h"
#include "task.h"

/*******************************************************************************
 * Defines
 ******************************************************************************/

/*******************************************************************************
 * Typedefs
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/


void prepare_tx_can_msg (can_hal_msg_t *msg, 
                         object_numbers_e object_num,
                         uint8_t source_id,
                         uint8_t dest_id,
                         uint8_t length,
                         can_hal_id_format_t idFormat,
                         can_hal_frame_t frameType){

    memset(msg,0,sizeof(*msg));
    msg->messageId = (((uint32_t)source_id  & 0xFF) << 16) |
                     (((uint32_t)dest_id    & 0xFF) <<  8) |
                     (((uint32_t)object_num & 0xFF) <<  0);

    msg->idFormat  = idFormat;
    msg->frameType = frameType;
    msg->length    = length;

}

lStatus_t kde_receive_response(uint8_t esc_id, uint8_t object, can_hal_msg_t *rx_msg)
{
    lStatus_t status = HAL_CAN_ReceiveMessage(KDE_CAN_HAL_INSTANCE, rx_msg, KDE_CAN_TIMEOUT);
    if (status != lStatus_Success) return status;

    uint32_t expected_id = (((uint32_t)esc_id      & 0xFF) << 16) |
                           (((uint32_t)MINE_CAN_ID & 0xFF) <<  8) |
                           (((uint32_t)object      & 0xFF));

    return (rx_msg->messageId == expected_id) ? lStatus_Success : lStatus_Fail;
}

lStatus_t kde_get_u32(uint8_t esc_id, uint8_t object, uint32_t* out){
    lStatus_t s;

    can_hal_msg_t tx;
    can_hal_msg_t rx;

    prepare_tx_can_msg(&tx,
                       object,
                       MINE_CAN_ID,
                       esc_id,
                       0,
                       CAN_HAL_ID_FORMAT_EXT,
                       CAN_HAL_DATA_FRAME);

    s = HAL_CAN_SendMessage(KDE_CAN_HAL_INSTANCE, &tx, KDE_CAN_TIMEOUT);
    if(s!= lStatus_Success) return s;

    s = kde_receive_response(esc_id, object, &rx);
    if(s!= lStatus_Success) return s;

    *out = (uint32_t)( rx.data[0] << 24 | rx.data[1] << 16 
                     | rx.data[2] << 8  | rx.data[3]);

    return lStatus_Success;
}


lStatus_t kde_get_u16(uint8_t esc_id, uint8_t object, uint16_t* out){
    lStatus_t s;

    can_hal_msg_t tx;
    can_hal_msg_t rx;

    prepare_tx_can_msg(&tx,
                       object,
                       MINE_CAN_ID,
                       esc_id,
                       0,
                       CAN_HAL_ID_FORMAT_EXT,
                       CAN_HAL_DATA_FRAME);

    s = HAL_CAN_SendMessage(KDE_CAN_HAL_INSTANCE, &tx, KDE_CAN_TIMEOUT);
    if(s!= lStatus_Success) return s;

    s = kde_receive_response(esc_id, object, &rx);
    if(s!= lStatus_Success) return s;

    *out = ((uint16_t)rx.data[0] << 8) | rx.data[1];

    return lStatus_Success;
}


lStatus_t kde_get_u8(uint8_t esc_id, uint8_t object, uint8_t* out){
    lStatus_t s;

    can_hal_msg_t tx;
    can_hal_msg_t rx;

    prepare_tx_can_msg(&tx,
                       object,
                       MINE_CAN_ID,
                       esc_id,
                       0,
                       CAN_HAL_ID_FORMAT_EXT,
                       CAN_HAL_DATA_FRAME);

    s = HAL_CAN_SendMessage(KDE_CAN_HAL_INSTANCE, &tx, KDE_CAN_TIMEOUT);
    if(s!= lStatus_Success) return s;

    s = kde_receive_response(esc_id, object, &rx);
    if(s!= lStatus_Success) return s;

    *out = rx.data[0];

    return lStatus_Success;
}
    
void local_delay_ms(uint32_t ms) {

    /* Once the scheduler runs, sleep instead of spinning. HAL_DelayMS is a
     * busy-wait, so kde_arm_all()'s ~3 s idle hold used to keep the calling
     * task (task_bridge, prio 2) on the CPU and starve task_work (prio 1):
     * the board stopped receiving UDP for the whole arm sequence. */
    if (xTaskGetSchedulerState() == taskSCHEDULER_RUNNING) {
        vTaskDelay(pdMS_TO_TICKS(ms));
        return;
    }

    /* Real millisecond delay off the device timer (HAL_DevTimeInit runs in
     * main). The old nop-loop was ~100x too short, so kde_arm_all()'s
     * 600 x 5 ms idle-throttle hold actually lasted only tens of ms. */
    HAL_DelayMS(ms);
}

/****************************** static functions ******************************/

/********************************* End Of File ********************************/