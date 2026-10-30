/**
 * @file    main.c
 * @brief   
 * @details 
 * @version 1.0.0
 * @date    
 * @author  LisumLab
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <stdint.h>

#include "task_bridge.h"
#include "task_work.h"
#include "task_mav.h"
#include "types.h"

/* Peripherals */
#include "common.h"
#include "gpio.h"
#include "util.h"
#include "eth.h"
#include "spi.h"
#include "can.h"

/* External hardware drivers */
#include "ad7705.h"
#include "vesc.h"
#include "kde.h"

/* Lib */

/* Middleware */
#include "FreeRTOS.h"
#include "semphr.h"
#include "timers.h"
#include "queue.h"
#include "task.h"

#include "udp_tl.h"
#include "udp.h"

#include "mav.h"

/*******************************************************************************
 * Defines
 ******************************************************************************/

/*******************************************************************************
 * Typedefs
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/* Temporary variables */
uint64_t boot_time_ms = 0;

/* Device information */
// UDP
const uint8_t dev_mac[6] = {0x4C, 0x50, 0x43, 0x01, 0x00, 0x04};
const uint8_t dev_ip [4] = {192,  168,  1,    104};

// UDP Client information
const uint8_t client_mac[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
const uint8_t client_ip[4]  = {192,  168,  1,    155};
const uint16_t client_port = 1004;
const uint16_t client_local_port = 1004;

/* Transport layers */
eth_hal_phy_t eth_phy;
udp_tl_t mav_udp_tl;

/* UDP */
udp_t udp;

/* Motor Volatages */
ad7705_t              motor_voltage_1_adc;
ad7705_return_value_t motor_voltage_1_adc_status = AD7705_ERROR;

ad7705_t              motor_voltage_2_adc;
ad7705_return_value_t motor_voltage_2_adc_status = AD7705_ERROR;

/* FreeRTOS */
uint8_t ucHeap[configTOTAL_HEAP_SIZE];
volatile uint32_t ulIdleCycleCount = 0UL;

// Mutexes
SemaphoreHandle_t mutex_mav;
/* Serialises every user of the UDP stack. udp_process() (task_work) and
 * udp_send() (task_mav) share udp.buffer and the EMAC descriptors; without
 * this, an outgoing status frame overwrote an incoming command while it was
 * still being parsed, so ARM/SET_SERVO commands were silently lost. */
SemaphoreHandle_t mutex_udp;
// Queues
QueueHandle_t queue_cmd;
QueueHandle_t queue_vesc_cmd;
QueueHandle_t queue_resp;
QueueHandle_t queue_mav_hb;
QueueHandle_t queue_esc_rx;
QueueHandle_t queue_vesc_rx;
QueueHandle_t queue_mav_esc;


// Handlers
TaskHandle_t xTaskBridgeHandle = NULL;

// Timers
TimerHandle_t timer_blinky;


/*******************************************************************************
 * Prototypes
 ******************************************************************************/

static void timer_blinky_cb(TimerHandle_t xTimer);

//cbs
void kdecan_cb(void *usr_arg, uint32_t int_status);
void vesccan_cb(void *usr_arg, uint32_t int_status);

/*******************************************************************************
 * Code
 ******************************************************************************/
int main()
{
	/*------------------------------- FreeRTOS -------------------------------*/
	/* Mutexes */
	mutex_mav  = xSemaphoreCreateMutex();
	mutex_udp  = xSemaphoreCreateMutex();
	
	/* Queues  */
	queue_mav_hb   = xQueueCreate(2, sizeof(mavlink_heartbeat_t));
	queue_cmd      = xQueueCreate(8, sizeof(esc_comm_msg_t));
	queue_vesc_cmd = xQueueCreate(8, sizeof(vesc_command_message_t));
	queue_resp     = xQueueCreate(4, sizeof(esc_comm_resp_t));
	queue_esc_rx   = xQueueCreate(40, sizeof(can_hal_msg_t));
	queue_vesc_rx  = xQueueCreate(40, sizeof(can_hal_msg_t));
	queue_mav_esc  = xQueueCreate(2, sizeof(mavlink_esc_status_t));

	/* shared KDE/VESC status queue set - task_bridge fills its member queues,
	 * task_mav selects from it and forwards each update as MAVLink over UDP */
	init_status_queueset();

	/*--------------------------------- NVIC ---------------------------------*/
	HAL_NVIC_SetPriority(SysTick_IRQn, 31);
	HAL_NVIC_SetPriority(PendSV_IRQn, 30);

	/*------------------------------- Dev Time -------------------------------*/
	HAL_DevTimeInit(TIM_HAL_INSTANCE_0);

	/*--------------------------------- PWM ----------------------------------*/
	/* Before anything slow: the AD7705 bring-up below takes ~6 s, and until
	 * kde_pwm_init() the ESC throttle pins sit at their reset pull-up
	 * (constant high), so the ESCs saw no valid signal for that window. */
	kde_pwm_init();


	/*---------------------------------- SPI ---------------------------------*/
	spi_hal_cfg_t spi_cfg;
	HAL_SPI_ConfigStructInit(&spi_cfg);
	spi_cfg.mode      = SPI_HAL_MASTER_MODE;
	spi_cfg.databit   = SPI_HAL_DATABIT_8;
	spi_cfg.cpha      = SPI_HAL_CPHA_SECOND;
	spi_cfg.cpol      = SPI_HAL_CPOL_LO;
	spi_cfg.clockRate = 1000000U; /* 1MS*/
	HAL_SPI_Init(SPI_HAL_INSTANCE_0, &spi_cfg);

	/*-------------------------------- AD7705 --------------------------------*/
	/*  voltage 1 -> CS/RST/DRDY P0.6/P0.7/P0.8                               */
	/*  voltage 2 -> CS/DRDY P0.16/P0.22, RST shared with voltage 1           */

	motor_voltage_1_adc.spi_instance   = SPI_HAL_INSTANCE_0;
	motor_voltage_1_adc.spi_clock      = 1000000U;
	motor_voltage_1_adc.cs_port        = GPIO_HAL_INSTANCE_0;
	motor_voltage_1_adc.cs_pin         = 6;
	motor_voltage_1_adc.drdy_port      = GPIO_HAL_INSTANCE_0;
	motor_voltage_1_adc.drdy_pin       = 8;
	motor_voltage_1_adc.reset_port     = GPIO_HAL_INSTANCE_0;
	motor_voltage_1_adc.reset_pin      = 7;
	motor_voltage_1_adc.data_bits      = SPI_HAL_DATABIT_8;
	motor_voltage_1_adc.cpha           = SPI_HAL_CPHA_SECOND;
	motor_voltage_1_adc.cpol           = SPI_HAL_CPOL_LO;
	motor_voltage_1_adc.mode           = SPI_HAL_MASTER_MODE;
	motor_voltage_1_adc.vref           = 2.5;
	motor_voltage_1_adc.drdy_mode      = AD7705_DRDY_NONE;
	motor_voltage_1_adc.timeout_us     = 0;  
	motor_voltage_1_adc.input_buffered = 0;

	/* Same bus, timing and mode. CS and DRDY must be this part's own, or both
	 * parts answer the same frame / drive DRDY against each other. */
	motor_voltage_2_adc = motor_voltage_1_adc;
	motor_voltage_2_adc.cs_pin         = 16;
	motor_voltage_2_adc.drdy_pin       = 22;

	/* RST is shared, so ad7705_init()/ad7705_reset() hit both parts. Neither
	 * may be configured until both have been reset, or the second bring-up
	 * wipes the first one's channel setup. */
	motor_voltage_1_adc_status = ad7705_init(&motor_voltage_1_adc);
	motor_voltage_2_adc_status = ad7705_init(&motor_voltage_2_adc);

	if(motor_voltage_1_adc_status == AD7705_OK)
		motor_voltage_1_adc_status = ad7705_reset(&motor_voltage_1_adc);

	if(motor_voltage_2_adc_status == AD7705_OK)
		motor_voltage_2_adc_status = ad7705_reset(&motor_voltage_2_adc);

	/* Channel setup first, then self-calibration on that setup. */
	if(motor_voltage_1_adc_status == AD7705_OK)
		motor_voltage_1_adc_status = ad7705_init_channel_with_params(
			&motor_voltage_1_adc, AD7705_CHANNEL_0, AD7705_CLK_DIV_1,
			AD7705_UNIPOLAR, AD7705_GAIN_1, AD7705_UPDATE_RATE_50);

	if(motor_voltage_1_adc_status == AD7705_OK)
		motor_voltage_1_adc_status = ad7705_init_channel_with_params(
			&motor_voltage_1_adc, AD7705_CHANNEL_1, AD7705_CLK_DIV_1,
			AD7705_UNIPOLAR, AD7705_GAIN_1, AD7705_UPDATE_RATE_50);

	if(motor_voltage_1_adc_status == AD7705_OK)
		motor_voltage_1_adc_status = ad7705_self_calibration(
			&motor_voltage_1_adc, AD7705_CHANNEL_0,
			AD7705_GAIN_1, AD7705_UNIPOLAR);

	if(motor_voltage_1_adc_status == AD7705_OK)
		motor_voltage_1_adc_status = ad7705_self_calibration(
			&motor_voltage_1_adc, AD7705_CHANNEL_1,
			AD7705_GAIN_1, AD7705_UNIPOLAR);

	if(motor_voltage_2_adc_status == AD7705_OK)
		motor_voltage_2_adc_status = ad7705_init_channel_with_params(
			&motor_voltage_2_adc, AD7705_CHANNEL_0, AD7705_CLK_DIV_1,
			AD7705_UNIPOLAR, AD7705_GAIN_1, AD7705_UPDATE_RATE_50);

	if(motor_voltage_2_adc_status == AD7705_OK)
		motor_voltage_2_adc_status = ad7705_init_channel_with_params(
			&motor_voltage_2_adc, AD7705_CHANNEL_1, AD7705_CLK_DIV_1,
			AD7705_UNIPOLAR, AD7705_GAIN_1, AD7705_UPDATE_RATE_50);

	if(motor_voltage_2_adc_status == AD7705_OK)
		motor_voltage_2_adc_status = ad7705_self_calibration(
			&motor_voltage_2_adc, AD7705_CHANNEL_0,
			AD7705_GAIN_1, AD7705_UNIPOLAR);

	if(motor_voltage_2_adc_status == AD7705_OK)
		motor_voltage_2_adc_status = ad7705_self_calibration(
			&motor_voltage_2_adc, AD7705_CHANNEL_1,
			AD7705_GAIN_1, AD7705_UNIPOLAR);

	/*--------------------------------- GPIO ---------------------------------*/
	gpio_hal_cfg_type_t gpio_cfg;
	gpio_cfg.openDrain = GPIO_HAL_OPENDRAIN_NORMAL;
	gpio_cfg.pinMode = GPIO_HAL_PINMODE_PULLUP;
	gpio_cfg.pinDir = GPIO_HAL_OUTPUT;

	HAL_GPIO_Init(GPIO_HAL_INSTANCE_3, 25, &gpio_cfg);
	HAL_GPIO_Init(GPIO_HAL_INSTANCE_3, 26, &gpio_cfg);

	/*--------------------------------- ETH ----------------------------------*/
	HAL_ETH_Init(&eth_phy, dev_mac);

	/*--------------------------------- UDP ----------------------------------*/
	/* initialize UDP */
	udp_init(&udp, dev_mac, dev_ip, (udp_phy_t *)&eth_phy);

	/* add client MAC & IP to static ARP table */
	udp_arptab_add(&udp, client_mac, client_ip);

	/*-------------------------------- UDP TL --------------------------------*/
	udp_tl_init(&mav_udp_tl, &udp, (uint8_t *)client_ip, client_local_port,
				client_port);

	/*--------------------------------- CAN ----------------------------------*/
	HAL_CAN_Init(KDE_CAN_HAL_INSTANCE, 1000000);
	HAL_CAN_EnableInterrupt(KDE_CAN_HAL_INSTANCE, kdecan_cb, NULL);

	HAL_CAN_Init(VESC_CAN_HAL_INSTANCE, 1000000);
	HAL_CAN_EnableInterrupt(VESC_CAN_HAL_INSTANCE, vesccan_cb, NULL);

	/*------------------------------- FreeRTOS -------------------------------*/
	/* work task - lowest priority */
	xTaskCreate(task_work, "udp", 512, NULL, 1, NULL);

	/* Bridge task - high priority */
	xTaskCreate(task_bridge, "bridge", 512, NULL, 2, &xTaskBridgeHandle);

	/* MAVLink task - medium priority */
	xTaskCreate(task_mav, "mav", 512, NULL, 3, NULL);


	/* create blinky timer */
	timer_blinky = xTimerCreate("tim_blinky", pdMS_TO_TICKS(BLINKY_PERIOD_MS),
								pdTRUE, NULL, timer_blinky_cb);

	/* start heartbeat timer */
	xTimerStart(timer_blinky, 0);

	/* Time past from initialization (we will use as a boot time for MAV) */
	boot_time_ms = HAL_GetTimeUS() / 1000;
	
	vTaskStartScheduler();

	/* loop */
	while (1) {
	}
}

/* ================================== Tasks ================================= */

/* ============================= User Callbacks ============================= */

static void timer_blinky_cb(TimerHandle_t xTimer)
{
	HAL_GPIO_SetPinValue(GPIO_HAL_INSTANCE_3, 26,
						 !HAL_GPIO_GetPinValue(GPIO_HAL_INSTANCE_3, 26));
}

/* ============================ Private Functions =========================== */

/* ============================= FreeRTOS Hooks ============================= */

/* Increment a counter while Application is in Idle. */
void vApplicationIdleHook(void) { ulIdleCycleCount++; }

/* Callback to trap FreeRTOS Misconfiguration. */
void vAssertCalled(const char *pcFile, uint32_t ulLine)
{
	taskDISABLE_INTERRUPTS();
	for (;;)
		;
}

/* Callback to trap FreeRTOS stack overflow. */
void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName)
{
	taskDISABLE_INTERRUPTS();
	for (;;)
		;
}

/* Callback to trap FreeRTOS insufficient heap memory. */
void vApplicationMallocFailedHook(void)
{
	taskDISABLE_INTERRUPTS();
	for (;;)
		;
}

/* =============================    HARDFAULT    ============================= */

typedef struct {
    uint32_t r0;
    uint32_t r1;
    uint32_t r2;
    uint32_t r3;
    uint32_t r12;
    uint32_t lr;
    uint32_t pc;
    uint32_t psr;
} HardFaultStack_t;

volatile uint32_t fault_pc = 0;
volatile uint32_t fault_lr = 0;
volatile uint32_t fault_cfsr = 0;
volatile uint32_t fault_hfsr = 0;
volatile uint32_t fault_addr = 0;
volatile uint32_t fault_task_sp = 0;
volatile char fault_task_name[configMAX_TASK_NAME_LEN] = "Unknown";
void HardFault_Handler(void) {
    uint32_t lr_value;
    __asm volatile("mov %0, lr" : "=r"(lr_value));
    
    uint32_t sp;
    char temp_name[configMAX_TASK_NAME_LEN];
    unsigned int i;
    
    if (lr_value & 0x4) {
        sp = __get_PSP();
        fault_task_sp = sp;
        
        TaskHandle_t current_task = xTaskGetCurrentTaskHandle();
        if (current_task != NULL) {
            const char *name = pcTaskGetName(current_task);
            strncpy(temp_name, name, configMAX_TASK_NAME_LEN - 1);
            temp_name[configMAX_TASK_NAME_LEN - 1] = '\0';
            
            for(i = 0; i < configMAX_TASK_NAME_LEN; i++) {
                fault_task_name[i] = temp_name[i];
                if(temp_name[i] == '\0') break;
            }
        } else {
            char unknown[] = "Unknown";
            for(i = 0; i < sizeof(unknown); i++) {
                fault_task_name[i] = unknown[i];
            }
        }
    } else {
        sp = __get_MSP();
        fault_task_sp = sp;
        
        char kernel[] = "Kernel/ISR";
        for(i = 0; i < sizeof(kernel); i++) {
            fault_task_name[i] = kernel[i];
        }
    }
    
    HardFaultStack_t *stack = (HardFaultStack_t*)sp;
    
    fault_pc = stack->pc;
    fault_lr = stack->lr;
    fault_cfsr = SCB->CFSR;
    fault_hfsr = SCB->HFSR;
    
    if (SCB->CFSR & (1 << 7)) fault_addr = SCB->BFAR;
    if (SCB->CFSR & (1 << 15)) fault_addr = SCB->MMFAR;
    
    if (lr_value & 0x4) {
        UBaseType_t free_stack = uxTaskGetStackHighWaterMark(xTaskGetCurrentTaskHandle());
        if (free_stack < 20) {
            fault_cfsr |= 0x80000000;
        }
    }
    
    __disable_irq();

    
    while(1) {
        int delay = (lr_value & 0x4) ? 500000 : 2000000;
        for(i = 0; i < (unsigned int)delay; i++);
    }
}