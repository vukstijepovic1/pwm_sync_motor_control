/**
 * @file    ftp.c
 * @brief   Drivers for KDE Direct.
 * @version	0.0.1
 * @date    12.08.2025
 * @author  BetaTehPro
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "kde.h"
#include "kde_helper.h"


#include "can.h"

#include "pwm.h"
#include "uart.h"
#include "util.h"

#include <string.h>


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
 * Private functions protothypes
 ******************************************************************************/
static lStatus_t kde_pwm_channel_for_esc(uint8_t esc_id, pwm_hal_channel_t* ch);

/*******************************************************************************
 * Code
 ******************************************************************************/

lStatus_t kde_request(uint8_t esc_id, object_numbers_e object){

    can_hal_msg_t tx;

    prepare_tx_can_msg(&tx,
                       object,
                       MINE_CAN_ID,
                       esc_id,
                       0,
                       CAN_HAL_ID_FORMAT_EXT,
                       CAN_HAL_DATA_FRAME);

    return HAL_CAN_SendMessage(KDE_CAN_HAL_INSTANCE, &tx, KDE_CAN_TIMEOUT);
}

lStatus_t kde_get_info(uint8_t esc_id){
    return kde_request(esc_id, CAN_OBJECT_GET_INFO);
}



lStatus_t kde_pwm_init(void)
{
    pwm_hal_cfg_t pwm_cfg;
    pwm_cfg.prescaleOption = PWM_HAL_PRESCALE_OPTION_USVAL;
    pwm_cfg.prescaleValue  = 1;
    HAL_PWM_Init(KDE_PWM_HAL_INSTANCE, &pwm_cfg);

    /* Channel 0 only defines the shared PWM period (TC resets to 0 on
     * match) - it is never enabled as an output. */
    pwm_hal_match_cfg_t pwm_period_cfg;
    pwm_period_cfg.matchChannel = PWM_HAL_CHANNEL_0;
    pwm_period_cfg.intOnMatch   = lFunctionalState_Disable;
    pwm_period_cfg.stopOnMatch  = lFunctionalState_Disable;
    pwm_period_cfg.resetOnMatch = lFunctionalState_Enable;
    HAL_PWM_ConfigMatch(KDE_PWM_HAL_INSTANCE, &pwm_period_cfg);

    HAL_PWM_MatchUpdate(KDE_PWM_HAL_INSTANCE, PWM_HAL_CHANNEL_0,
                        KDE_PWM_PERIOD_US, PWM_HAL_MATCH_UPDATE_NOW);

    /* One duty-cycle/output channel per ESC, all starting at minimum
     * throttle. */
    for (uint32_t i = 0; i < KDE_PWM_CHANNEL_PWM_LEN; i++) {
        pwm_hal_match_cfg_t pwm_out_cfg;
        pwm_out_cfg.matchChannel = kde_pwm_channel_map[i].ch;
        pwm_out_cfg.intOnMatch   = lFunctionalState_Disable;
        pwm_out_cfg.stopOnMatch  = lFunctionalState_Disable;
        pwm_out_cfg.resetOnMatch = lFunctionalState_Disable;
        HAL_PWM_ConfigMatch(KDE_PWM_HAL_INSTANCE, &pwm_out_cfg);

        HAL_PWM_MatchUpdate(KDE_PWM_HAL_INSTANCE, kde_pwm_channel_map[i].ch,
                            KDE_MINIMUM_PWM, PWM_HAL_MATCH_UPDATE_NOW);

        HAL_PWM_MatchChannelCmd(KDE_PWM_HAL_INSTANCE, kde_pwm_channel_map[i].ch,
                                lFunctionalState_Enable);
    }

    HAL_PWM_Activate(KDE_PWM_HAL_INSTANCE);

    return lStatus_Success;
}

lStatus_t kde_set_pwm(uint8_t esc_id, int16_t pwm)
{
#if KDE_USE_PWM
    /* Put the value on this ESC's dedicated PWM pin (if it has one),
     * glitch-free - NEXT_RST applies it at the next period rollover instead
     * of forcing an immediate counter reset. */
    {
        pwm_hal_channel_t ch;

        if(kde_pwm_channel_for_esc(esc_id, &ch) == lStatus_Success){
            HAL_PWM_MatchUpdate(KDE_PWM_HAL_INSTANCE, ch,
                                (uint32_t)pwm, PWM_HAL_MATCH_UPDATE_NEXT_RST);
        }
    }
#endif

#if KDE_USE_CAN_THROTTLE
    {
        can_hal_msg_t tx;

        /* DLC 8 like KDE's own arming example (04 4c 00 00 00 00 00 00);
         * bytes 2..7 are already zero from prepare_tx_can_msg's memset. */
        prepare_tx_can_msg(&tx,
                           CAN_OBJECT_SET_PWM,
                           MINE_CAN_ID,
                           esc_id,
                           8,
                           CAN_HAL_ID_FORMAT_EXT,
                           CAN_HAL_DATA_FRAME);

        tx.data[0] = (pwm >> 8) & 0xFF;
        tx.data[1] = (pwm >> 0) & 0xFF;

        return HAL_CAN_SendMessage(KDE_CAN_HAL_INSTANCE, &tx, KDE_CAN_TIMEOUT);
    }
#else
    (void)esc_id;
    (void)pwm;
    return lStatus_Success;
#endif
}



lStatus_t kde_set_direction(uint8_t esc_id, uint8_t direction){

    can_hal_msg_t tx;

    prepare_tx_can_msg(&tx,
                       CAN_OBJECT_SET_DIRECTION,
                       MINE_CAN_ID,
                       esc_id,
                       1,
                       CAN_HAL_ID_FORMAT_EXT,
                       CAN_HAL_DATA_FRAME);

    tx.data[0] = direction;

    return HAL_CAN_SendMessage(KDE_CAN_HAL_INSTANCE, &tx, KDE_CAN_TIMEOUT);
}

lStatus_t kde_get_raw_rpm(uint8_t esc_id){
    return kde_request(esc_id, CAN_OBJECT_GET_RAW_COUNT);
}

lStatus_t kde_get_voltage(uint8_t esc_id){
    return kde_request(esc_id, CAN_OBJECT_GET_VOLTAGE);
}

lStatus_t kde_get_current(uint8_t esc_id){
    return kde_request(esc_id, CAN_OBJECT_GET_CURRENT);
}

lStatus_t kde_get_rpm(uint8_t esc_id){
    return kde_request(esc_id, CAN_OBJECT_GET_RPM);
}

lStatus_t kde_get_temp(uint8_t esc_id){
    return kde_request(esc_id, CAN_OBJECT_GET_TEMP);
}

lStatus_t kde_get_throttle_in(uint8_t esc_id){
    return kde_request(esc_id, CAN_OBJECT_GET_THROTTLE_IN);
}

lStatus_t kde_get_throttle_out(uint8_t esc_id){
    return kde_request(esc_id, CAN_OBJECT_GET_THROTTLE_OUT);
}

lStatus_t kde_get_mcu_ids(void){

    can_hal_msg_t tx;

    /* Protocol requires this query to be sent to the broadcast address
     * (0x01) - all ESCs on the bus answer it, identified by their own
     * source address, not by who the request was addressed to. */
    prepare_tx_can_msg(&tx,
                       CAN_OBJECT_GET_MCU_IDS,
                       MINE_CAN_ID,
                       KDE_BROADCAST_ID,
                       0,
                       CAN_HAL_ID_FORMAT_EXT,
                       CAN_HAL_DATA_FRAME);

    return HAL_CAN_SendMessage(KDE_CAN_HAL_INSTANCE, &tx, KDE_CAN_TIMEOUT);
}

lStatus_t kde_start_enum(uint16_t timeout_ms){

    can_hal_msg_t tx;

    prepare_tx_can_msg(&tx,
                       CAN_OBJECT_START_ENUM,
                       MINE_CAN_ID,
                       KDE_BROADCAST_ID,
                       2,
                       CAN_HAL_ID_FORMAT_EXT,
                       CAN_HAL_DATA_FRAME);

    tx.data[0] = (timeout_ms >> 8) & 0xFF;
    tx.data[1] = (timeout_ms >> 0) & 0xFF;

    return HAL_CAN_SendMessage(KDE_CAN_HAL_INSTANCE, &tx, KDE_CAN_TIMEOUT);
}

lStatus_t kde_enum_receive(int8_t* mcu_ids){

    can_hal_msg_t rx;

    lStatus_t s = HAL_CAN_ReceiveMessage(KDE_CAN_HAL_INSTANCE, &rx, KDE_CAN_TIMEOUT);
    if (s!= lStatus_Success) return s;

    if (GET_OBJ(rx.messageId) != CAN_OBJECT_START_ENUM) return lStatus_Fail;

    for (int8_t i = 0; i < 8; i++)
    {
        mcu_ids[i] = (int8_t)rx.data[i];
    }

    return lStatus_Success;
}

lStatus_t kde_set_node_addr(uint8_t new_node, int8_t* mcu_ids){

    can_hal_msg_t tx;

    prepare_tx_can_msg(&tx,
                       CAN_OBJECT_UPDATE_NODE_ADDR,
                       MINE_CAN_ID,
                       new_node,
                       8,
                       CAN_HAL_ID_FORMAT_EXT,
                       CAN_HAL_DATA_FRAME);

    for (int8_t i = 0; i < 8; i++)
    {
        tx.data[i] = (int8_t)mcu_ids[i];
    }

    return HAL_CAN_SendMessage(KDE_CAN_HAL_INSTANCE, &tx, KDE_CAN_TIMEOUT);
}


lStatus_t kde_get_base_stat(uint8_t esc_id){
    return kde_request(esc_id, CAN_OBJECT_GET_BASE_STAT);
}

lStatus_t kde_shutdown(uint8_t esc_id){
    return kde_request(esc_id, CAN_OBJECT_TURN_OFF);
}

lStatus_t kde_reset(uint8_t esc_id){
    return kde_request(esc_id, CAN_OBJECT_RESTART);
}

lStatus_t kde_get_error_info(uint8_t esc_id){
    return kde_request(esc_id, CAN_OBJECT_GET_DEBUGG_INFO);
}

/*******************************************************************************
 * Blocking functions (use with care, or dont) and wrapers
 ******************************************************************************/

lStatus_t kde_arming(uint8_t esc_id){

    lStatus_t s = lStatus_Success;

    /* Object 32 (TURN_OFF) leaves the ESC idle with arming disabled "until
     * restart command is issued", so clear that first - otherwise a single
     * earlier shutdown makes every later arm silently impossible. Harmless on
     * an ESC that was never shut down. */
    kde_reset(esc_id);
    local_delay_ms(KDE_RESTART_SETTLE_MS);

    for (uint32_t i = 0; i < 600; i++) {
        s = kde_set_pwm(esc_id, KDE_MINIMUM_PWM);
        local_delay_ms(5);
    }

    return s;
}

lStatus_t kde_arm_all(void){

    lStatus_t s = lStatus_Success;
    lStatus_t r = lStatus_Success;

    /* See kde_arming(): re-enable arming on every ESC before holding idle. */
    for (uint32_t j = 0; j < KDE_PWM_CHANNEL_PWM_LEN; j++)
        kde_reset(kde_pwm_channel_map[j].id);

    local_delay_ms(KDE_RESTART_SETTLE_MS);

    for (uint32_t i = 0; i < 600; i++) {

        /* Only the last round decides the result, as in kde_arming(): early
         * frames can go unacknowledged while the ESCs are still booting
         * from the restart, which is not a failed arm. */
        s = lStatus_Success;

        for (uint32_t j = 0; j < KDE_PWM_CHANNEL_PWM_LEN; j++) {

            r = kde_set_pwm(kde_pwm_channel_map[j].id, KDE_MINIMUM_PWM);
            if (r != lStatus_Success) s = r;
        }
        local_delay_ms(5);
    }

    return s;
}

lStatus_t kde_set_duty(uint8_t esc_id, int16_t duty){

    int16_t pwm;

    pwm = KDE_MINIMUM_PWM + (int16_t)(KDE_COEF_MUL_PWM * duty);

    return kde_set_pwm(esc_id, pwm);
}

float kde_raw_to_rpm(uint32_t raw_prev, uint32_t raw_curr, uint32_t dt_ms){

    uint32_t raw_diff;

    if(dt_ms == 0) return 0.0f;

    if (raw_curr >= raw_prev) {
        /* Normal case: counter did not wrap between samples */
        raw_diff = raw_curr - raw_prev;
    } else {
        /* Counter overflowed (wrapped around) since the last sample */
        raw_diff = (UINT32_MAX - raw_prev) + raw_curr + 1;
    }

    return ((float)raw_diff / ((float)dt_ms / 1000.0f))
           * (2.0f / (float)KDE_MOTOR_POLES_NUMBER) * 60.0f / 6.0f;
}

/*******************************************************************************
 * Private functions 
 ******************************************************************************/

static lStatus_t kde_pwm_channel_for_esc(uint8_t esc_id, pwm_hal_channel_t* ch){

    uint32_t i;
    for (i = 0; i < KDE_PWM_CHANNEL_PWM_LEN;i++){

        if(kde_pwm_channel_map[i].id == esc_id){

            *ch = kde_pwm_channel_map[i].ch;
            return lStatus_Success;
        }
    }

    return lStatus_Fail;
}