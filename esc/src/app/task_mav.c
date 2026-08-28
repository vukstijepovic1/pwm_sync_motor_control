/**
 * @file    task_mav.c
 * @brief   Task MAV - handle MAVLink packets
 * @version 1.0.0
 * @date    26.02.2025
 * @author  LisumLab
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <stdint.h>

#include "task_mav.h"
#include "types.h"
#include "main.h"

/* Peripherals */
#include "gpio.h"
#include "kde.h"
#include "can.h"

/* External hardware drivers */

/* Lib */

/* Middleware */
#include "FreeRTOS.h"
#include "mav.h"
#include "queue.h"
#include "timers.h"
#include "udp_tl.h"
#include <mavlink_types.h>

/*******************************************************************************
 * Defines
 ******************************************************************************/

/* MAVLink heartbeat period [ms] */
#define MAV_HB_PERIOD_MS 1000

/* MAVLink client track count (ground station helicopter application) */
#define MAV_CLIENT_TRACK_COUNT 4

/*******************************************************************************
 * Typedefs
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

extern QueueHandle_t queue_mav_hb;
extern QueueHandle_t queue_mav_ack;
extern QueueHandle_t queue_mav_act_data;
extern QueueHandle_t queue_mav_manual_ctrl;
extern QueueSetHandle_t queueset_mav;

exter

extern udp_tl_t mav_udp_tl;

/* Extern temporary variables */
extern uint64_t boot_time_ms;



// MAVLink information
static const uint8_t dev_mav_sysid = 0;
static const uint8_t dev_mav_compid = MAV_COMP_ID_USER5;

static const uint8_t client_mav_sysid = 0;
static const uint8_t client_mav_compid = MAV_COMP_ID_USER52;

static const mav_track_t mav_client_tracks[MAV_CLIENT_TRACK_COUNT] = {
	{.msgid = MAVLINK_MSG_ID_HEARTBEAT,
	 .sysid = client_mav_sysid,
	 .compid = client_mav_compid},
	{.msgid = MAVLINK_MSG_ID_COMMAND_LONG,
	 .sysid = client_mav_sysid,
	 .compid = client_mav_compid},
	{.msgid = MAVLINK_MSG_ID_LISUM_MANUAL_CTRL_HORNET,
	 .sysid = client_mav_sysid,
	 .compid = client_mav_compid},
	{.msgid = MAVLINK_MSG_ID_COMMAND_LONG,
	 .sysid = client_mav_sysid,
	 .compid = client_mav_compid}};

static mav_t mav_handle;
static mav_link_t mav_link_udp;

/* MAVLink Component Information Basic defines */
static const char vendor_name[] = "BetaTechPRO";
static const char model_name[] = "HW_ACT_MASTER";
static const char software_version[] = "v1.0.0";
static const char hardware_version[] = "DEV-Board V0.2";
static const char serial_number[] = "S_N: 17";
static const uint32_t time_manufacture_s = BUILD_UNIX_TIMESTAMP;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/* MAVLink receive callback */
static void mav_recv_cb(mav_t *mav, mavlink_message_t *msg, void *arg);

/* heartbeat timer callback */
static void timer_mav_hb_cb(TimerHandle_t xTimer);

/* process received MAVLink command */
static void mav_handle_cmd_long(mavlink_message_t *msg,
								mavlink_command_long_t *cmd_long);

mavlink_component_information_basic_t make_comp_info_basic(void)
{
	mavlink_component_information_basic_t data;
	/* Initialized structure */
	memset(&data, 0, sizeof(data)); 

	strncpy(data.vendor_name, vendor_name,
			sizeof(data.vendor_name));

	strncpy(data.model_name, model_name,
			sizeof(data.model_name));

	strncpy(data.software_version, software_version,
			sizeof(data.software_version));

	strncpy(data.hardware_version, hardware_version,
			sizeof(data.hardware_version));

	strncpy(data.serial_number, serial_number,
			sizeof(data.serial_number));

	data.capabilities = 0;

	data.time_manufacture_s = time_manufacture_s;
	
	/* Conversion to ms */
	data.time_boot_ms = boot_time_ms;

	return data;
}
								


/*******************************************************************************
 * Code
 ******************************************************************************/

void task_mav(void *arg)
{
	QueueSetMemberHandle_t queue_member = NULL;
	mavlink_message_t msg;
	TimerHandle_t timer_mav_hb;

	/*--------------------------------- MAV ----------------------------------*/
	/* initialize MAVLink handle */
	mav_init(&mav_handle, dev_mav_sysid, dev_mav_compid);

	/* initialize MAVLink UDP link */
	mav_link_init(&mav_link_udp, MAVLINK_COMM_0, mav_recv_cb, NULL,
				  (tl_t *)&mav_udp_tl);

	/* connect MAVLink link to MAVLink handle */
	mav_link(&mav_handle, &mav_link_udp);

	/* track MAVLink client messages */
	for (uint8_t i = 0; i < MAV_CLIENT_TRACK_COUNT; i++) {
		mav_track_t *track;

		track = (mav_track_t *)&mav_client_tracks[i];
		mav_track(&mav_handle, track->msgid, track->sysid, track->compid);
	}

	/* create MAVLink heartbeat timer */
	timer_mav_hb = xTimerCreate("tim_mav_hb", pdMS_TO_TICKS(MAV_HB_PERIOD_MS),
								pdTRUE, NULL, timer_mav_hb_cb);

	/* start heartbeat timer */
	xTimerStart(timer_mav_hb, 0);

	for (;;) {
	
		

	}
}

static void mav_recv_cb(mav_t *mav, mavlink_message_t *msg, void *arg)
{
	xSemaphoreTake(mutex_mav, portMAX_DELAY);

	switch (msg->msgid) {
	case MAVLINK_MSG_ID_HEARTBEAT: {
		HAL_GPIO_SetPinValue(GPIO_HAL_INSTANCE_3, 25,
							 !HAL_GPIO_GetPinValue(GPIO_HAL_INSTANCE_3, 25));

		break;
	}
	case MAVLINK_MSG_ID_COMMAND_LONG: {
		
		mavlink_command_long_t data;

		break;
	}
	default:
		break;
	}
	xSemaphoreGive(mutex_mav);
}

static void timer_mav_hb_cb(TimerHandle_t xTimer)
{
	mavlink_heartbeat_t mav_hb = {.type = MAV_TYPE_GENERIC,
								  .autopilot = MAV_AUTOPILOT_GENERIC,
								  .base_mode = 0,
								  .custom_mode = 0,
								  .system_status = MAV_STATE_STANDBY};

	xQueueSendToBack(queue_mav_hb, &mav_hb, 0);
}


