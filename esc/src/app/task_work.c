/**
 * @file    task_work.c
 * @brief   Task work - process background tasks
 * @version 1.0.0
 * @date    26.02.2025
 * @author  LisumLab
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <stdint.h>

#include "task_work.h"

/* Peripherals */

/* External hardware drivers */

/* Lib */

/* Middleware */
#include "FreeRTOS.h"
#include "task.h"

#include "udp.h"

/*******************************************************************************
 * Defines
 ******************************************************************************/

/* gratuitous ARP period [ms] */
#define ARP_GRAT_PERIOD_MS 10000

/*******************************************************************************
 * Typedefs
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

extern udp_t udp;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

void task_work(void *arg)
{
	TickType_t arp_grat_time = xTaskGetTickCount();

	for (;;) {
		/* process UDP data */
		udp_process(&udp);

		/* send gratuitous ARP */
		if (xTaskGetTickCount() - arp_grat_time >= ARP_GRAT_PERIOD_MS) {
			arp_grat_time = xTaskGetTickCount();

			udp_arp_grat(&udp);
		}
	}
}
