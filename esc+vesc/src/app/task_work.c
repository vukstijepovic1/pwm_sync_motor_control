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
#include "util.h"

/* External hardware drivers */
#include "ad7705.h"

/* Middleware */
#include "FreeRTOS.h"
#include "queue.h"
#include "semphr.h"
#include "task.h"

#include "mav.h"
#include "udp.h"

/*******************************************************************************
 * Defines
 ******************************************************************************/

 /* gratuitous ARP period [ms] */
#define ARP_GRAT_PERIOD_MS 10000

/* ADC voltage read period [ms] */
#define VOLTAGE_READ_PERIOD_MS 100

/* Two AD7705 parts with two channels each. voltage_v[] index is
 * part * 2 + channel, which is also the ESC_STATUS voltage[] slot. */
#define VOLTAGE_ADC_COUNT      2
#define VOLTAGE_ADC_CHANNELS   2
#define VOLTAGE_CHANNEL_COUNT  (VOLTAGE_ADC_COUNT * VOLTAGE_ADC_CHANNELS)

/* counts_per_V = raw / (V_at_input * gain). Taken over from ALIGN, where it
 * was trimmed against a 16.84 V battery check on the same kind of input. */
#define VOLTAGE_COUNTS_PER_V_AT_GAIN_1 12961.2

/* Reading at 0 V, in ADC counts. Zero: the part is unipolar, so its response
 * goes through the origin. */
#define VOLTAGE_OFFSET_COUNTS 0.0

/* External divider ahead of every input (ALIGN's VOLTAGE_DEVIDER). The
 * reported voltage is the input voltage scaled back up by this ratio. */
#define VOLTAGE_DIVIDER 20.4

/* Per-channel trim on top of the shared counts-per-volt above, gain only
 * (0 V reads 0). trim = V_real / V_reported, measured with all four inputs
 * on exactly 30.00 V, ADC 1 CH0 then re-trimmed at 53.4 V (read 54.39 V).
 * ADC 1 reads ~1.85x high: its divider is effectively
 * ~11 (100k/10k?), not VOLTAGE_DIVIDER, so its trim absorbs that too. */
static const float voltage_trim[VOLTAGE_CHANNEL_COUNT] = {
	0.530224f, /* ADC 1, CH0 */
	0.528870f, /* ADC 1, CH1 */
	0.992720f, /* ADC 2, CH0 */
	0.997340f  /* ADC 2, CH1 */
};

/*******************************************************************************
 * Variables
 ******************************************************************************/

extern udp_t udp;

/* guards udp (shared with task_mav's mav_send) - see main.c */
extern SemaphoreHandle_t mutex_udp;

/* ADC voltages -> MAVLink ESC_STATUS, sent by task_mav */
extern QueueHandle_t queue_mav_esc;

/* Voltage ADCs, both on SPI0 (main.c) */
extern ad7705_t              motor_voltage_1_adc;
extern ad7705_return_value_t motor_voltage_1_adc_status;

extern ad7705_t              motor_voltage_2_adc;
extern ad7705_return_value_t motor_voltage_2_adc_status;

static ad7705_t *const voltage_adc[VOLTAGE_ADC_COUNT] = {
	&motor_voltage_1_adc,
	&motor_voltage_2_adc
};

static ad7705_return_value_t *const voltage_adc_status[VOLTAGE_ADC_COUNT] = {
	&motor_voltage_1_adc_status,
	&motor_voltage_2_adc_status
};

/* Slot -> AD7705 channel, the same on both parts. */
static const uint8_t voltage_adc_channel[VOLTAGE_ADC_CHANNELS] = {
	AD7705_CHANNEL_0,
	AD7705_CHANNEL_1
};

/*******************************************************************************
 * Code
 ******************************************************************************/

void task_work(void *arg)
{
	TickType_t arp_grat_time = xTaskGetTickCount();
	TickType_t voltage_time  = xTaskGetTickCount();

	for (;;) {
		/* process UDP data. mav_recv_cb runs inside udp_process with the
		 * mutex held, so it must never send - replies go through
		 * task_mav instead. */
		xSemaphoreTake(mutex_udp, portMAX_DELAY);
		udp_process(&udp);
		xSemaphoreGive(mutex_udp);

		/* send gratuitous ARP */
		if (xTaskGetTickCount() - arp_grat_time >= ARP_GRAT_PERIOD_MS) {
			arp_grat_time = xTaskGetTickCount();

			xSemaphoreTake(mutex_udp, portMAX_DELAY);
			udp_arp_grat(&udp);
			xSemaphoreGive(mutex_udp);
		}

		/* ADC voltages -> MAVLink ESC_STATUS.
		 *
		 * Each part has one modulator serving both its inputs, so neither can
		 * sample its two channels at the same instant: one slot is read per
		 * tick and the other is selected right afterwards, which gives its
		 * filter a full period to settle before its own read. Both parts are
		 * stepped together, so a tick reads channel N of each. Every message
		 * carries all four voltages - the two just read are fresh, the other
		 * two are one period old. A failed read leaves the previous value. */
		if ((motor_voltage_1_adc_status == AD7705_OK ||
			 motor_voltage_2_adc_status == AD7705_OK) &&
			xTaskGetTickCount() - voltage_time >= VOLTAGE_READ_PERIOD_MS) {
			static float   voltage_v[VOLTAGE_CHANNEL_COUNT];
			static uint8_t slot;
			mavlink_esc_status_t esc = {0};
			uint16_t raw;

			voltage_time = xTaskGetTickCount();

			for (uint8_t a = 0; a < VOLTAGE_ADC_COUNT; a++) {
				uint8_t v = (uint8_t)(a * VOLTAGE_ADC_CHANNELS + slot);

				if (*voltage_adc_status[a] != AD7705_OK)
					continue;

				/* Raw counts, not ad7705_read_adc_result()'s volts: the
				 * scaling is calibrated against counts, not against vref. */
				if (ad7705_read_raw_adc_result(voltage_adc[a],
											   voltage_adc_channel[slot],
											   &raw) == AD7705_OK) {
					double counts_per_v =
						VOLTAGE_COUNTS_PER_V_AT_GAIN_1 *
						(double)ad7705_channel_gain(voltage_adc[a],
													voltage_adc_channel[slot]);

					voltage_v[v] =
						(float)(((double)raw - VOLTAGE_OFFSET_COUNTS) /
								counts_per_v * VOLTAGE_DIVIDER) *
						voltage_trim[v];
				}
			}

			/* rpm[] and current[] left zeroed - only voltages are measured */
			esc.index     = 0;
			esc.time_usec = HAL_GetTimeUS();

			for (uint8_t v = 0; v < VOLTAGE_CHANNEL_COUNT; v++)
				esc.voltage[v] = voltage_v[v];

			xQueueSendToBack(queue_mav_esc, &esc, 0);

			/* Step both parts to the next slot. The values read here still
			 * belong to the channels just left, and the filters have not
			 * settled on the new ones either, so they are discarded - the
			 * reads are only there to leave each part expecting a command
			 * byte rather than stopping mid-transfer. */
			slot = (uint8_t)((slot + 1U) % VOLTAGE_ADC_CHANNELS);

			for (uint8_t a = 0; a < VOLTAGE_ADC_COUNT; a++)
				if (*voltage_adc_status[a] == AD7705_OK)
					(void)ad7705_read_raw_adc_result(voltage_adc[a],
													 voltage_adc_channel[slot],
													 &raw);
		}
	}
}
