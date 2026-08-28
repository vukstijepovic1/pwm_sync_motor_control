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
#include "task_mav.h"
#include "task_work.h"
#include "types.h"

/* Peripherals */
#include "can.h"
#include "common.h"
#include "eth.h"
#include "gpio.h"
#include "util.h"

/* External hardware drivers */
#include "kde.h"
/* Lib */

/* Middleware */
#include "FreeRTOS.h"
#include "queue.h"
#include "semphr.h"
#include "task.h"
#include "timers.h"

#include "udp.h"
#include "udp_tl.h"

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
const uint8_t dev_ip[4]  = {192,  168,  1,    104};

// UDP Client information
const uint8_t client_mac[6] = {0x4C, 0x50, 0x43, 0x01, 0x00, 0x00};
const uint8_t client_ip[4]  = {192,  168,  1,    100};
const uint16_t client_port = 1004;
const uint16_t client_local_port = 1004;

/* Transport layers */
eth_hal_phy_t eth_phy;
udp_tl_t mav_udp_tl;

/* UDP */
udp_t udp;

/* FreeRTOS */
uint8_t ucHeap[configTOTAL_HEAP_SIZE];
volatile uint32_t ulIdleCycleCount = 0UL;

// Mutexes
SemaphoreHandle_t mutex_mav;

// Queues
QueueHandle_t queue_comm;
QueueHandle_t queue_resp;
QueueHandle_t queue_mav_hb;
QueueHandle_t queue_esc_rx;

// QueueSets
QueueSetHandle_t queueset_mav;

// Handlers
TaskHandle_t xTaskBridgeHandle = NULL;

// Timers
TimerHandle_t timer_blinky;


/*******************************************************************************
 * Prototypes
 ******************************************************************************/

static void timer_blinky_cb(TimerHandle_t xTimer);

//cbs
void kdecan_cb(void *usr_arg, int32_t int_status);

/*******************************************************************************
 * Code
 ******************************************************************************/
int main()
{
	/*------------------------------- FreeRTOS -------------------------------*/
	/* Mutexes */
	mutex_mav  = xSemaphoreCreateMutex();
	
	/* Queues */
	queue_mav_hb = xQueueCreate(2, sizeof(mavlink_heartbeat_t));
	queue_comm   = xQueueCreate(2, sizeof(esc_comm_msg_t));
	queue_resp   = xQueueCreate(2, sizeof(esc_comm_msg_t));
	queue_esc_rx = xQueueCreate(40, sizeof(can_hal_msg_t));

	/* Queuesets */
	queueset_mav = xQueueCreateSet(20);

	xQueueAddToSet(queue_resp, queueset_mav);
	xQueueAddToSet(queue_mav_hb, queueset_mav);

	/*--------------------------------- NVIC ---------------------------------*/
	HAL_NVIC_SetPriority(SysTick_IRQn, 31);
	HAL_NVIC_SetPriority(PendSV_IRQn, 30);

	/*------------------------------- Dev Time -------------------------------*/
	HAL_DevTimeInit(TIM_HAL_INSTANCE_0);

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