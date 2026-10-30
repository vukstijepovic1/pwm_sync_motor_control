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
#include "task_work.h"
#include "task_bridge.h"
#include "types.h"
#include "main.h"

/* Peripherals */
#include "gpio.h"
#include "kde.h"
#include "can.h"


/* Middleware */
#include "FreeRTOS.h"
#include "mav.h"
#include "queue.h"
#include "semphr.h"
#include "timers.h"
#include "udp_tl.h"
#include <mavlink_types.h>

/*******************************************************************************
 * Defines
 ******************************************************************************/

/* MAVLink heartbeat period [ms] */
#define MAV_HB_PERIOD_MS 1000

/* MAVLink client track count (ground station helicopter application) */
#define MAV_CLIENT_TRACK_COUNT 10

/*******************************************************************************
 * Variables
 ******************************************************************************/

extern QueueHandle_t queue_mav_hb;
extern QueueHandle_t queue_mav_ack;
extern QueueHandle_t queue_mav_act_data;
extern QueueHandle_t queue_mav_manual_ctrl;

/* command results from task_bridge (ReSendResp) -> COMMAND_ACK */
extern QueueHandle_t queue_resp;

/* ADC voltages from task_work -> ESC_STATUS */
extern QueueHandle_t queue_mav_esc;

/* command bridge queue - consumed by task_bridge (ProcessCmd) */
extern QueueHandle_t queue_cmd;

/* VESC command bridge queue - consumed by task_bridge (ProcessCommand) */
extern QueueHandle_t queue_vesc_cmd;

extern SemaphoreHandle_t mutex_mav;

/* guards the UDP stack (shared with task_work's udp_process) - see main.c */
extern SemaphoreHandle_t mutex_udp;


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
	 .compid = client_mav_compid},
	/* VESC command messages - bridged towards the VESC CAN bus */
	{.msgid = MAVLINK_MSG_ID_LISUM_VESC_SET_DUTY,
	 .sysid = client_mav_sysid,
	 .compid = client_mav_compid},
	{.msgid = MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT,
	 .sysid = client_mav_sysid,
	 .compid = client_mav_compid},
	{.msgid = MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_BRAKE,
	 .sysid = client_mav_sysid,
	 .compid = client_mav_compid},
	{.msgid = MAVLINK_MSG_ID_LISUM_VESC_SET_RPM,
	 .sysid = client_mav_sysid,
	 .compid = client_mav_compid},
	{.msgid = MAVLINK_MSG_ID_LISUM_VESC_SET_POS,
	 .sysid = client_mav_sysid,
	 .compid = client_mav_compid},
	{.msgid = MAVLINK_MSG_ID_LISUM_VESC_PING,
	 .sysid = client_mav_sysid,
	 .compid = client_mav_compid}};

static mav_t mav_handle;
static mav_link_t mav_link_udp;

/* --- debug counters for the ground-station -> ESC command path ---
 * Non-static and volatile so they survive optimisation and can be read from a
 * debugger / map file. */
volatile uint32_t dbg_cmd_long_rx = 0;  /* COMMAND_LONG accepted as ours    */
volatile uint32_t dbg_cmd_queued  = 0;  /* handed to task_bridge            */
volatile uint32_t dbg_cmd_dropped = 0;  /* queue_cmd was full               */

/* Scratch message for the outbound status stream. Only task_mav's loop touches
 * it, so a single file-scope instance keeps it off the (small) task stack. */
static mavlink_message_t mav_tx_msg;

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

/* encode-and-send helpers for the board's own outgoing messages */
static void mav_send_locked(void);
static void mav_send_heartbeat(const mavlink_heartbeat_t *hb);
static void mav_send_cmd_ack(const esc_comm_resp_t *resp);
static void mav_send_named_int(const char *prefix, uint8_t esc_id,
							   int32_t value);
static void mav_send_esc_debug(uint8_t esc_id, uint8_t warning);

/* queue a VESC command towards task_bridge / the VESC CAN bus */
static void mav_push_vesc_cmd(uint8_t vesc_id, command_numbers_e command_id,
							  float command_param);

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
		mavlink_heartbeat_t  hb;
		esc_comm_resp_t      resp;
		mavlink_esc_status_t esc;

		/* Board heartbeat (1 Hz, from timer_mav_hb_cb). */
		if (xQueueReceive(queue_mav_hb, &hb, 0) == pdPASS)
			mav_send_heartbeat(&hb);

		/* ADC voltages (10 Hz, from task_work) -> ESC_STATUS. */
		if (xQueueReceive(queue_mav_esc, &esc, 0) == pdPASS) {
			mavlink_msg_esc_status_encode(dev_mav_sysid, dev_mav_compid,
										  &mav_tx_msg, &esc);
			mav_send_locked();
		}

		/* Command results from task_bridge -> COMMAND_ACK. */
		while (xQueueReceive(queue_resp, &resp, 0) == pdPASS)
			mav_send_cmd_ack(&resp);

		/* Wait for any active KDE/VESC instance to post a status update. The
		 * 20 ms timeout also bounds the heartbeat/ACK latency above. */
		QueueSetMemberHandle_t q =
			xQueueSelectFromSet(queueset_status, pdMS_TO_TICKS(20));

		if (q == NULL)
			continue;

		/* Identify which per-instance queue fired and pull the update. */
		int     kind   = 0;   /* 1..6 VESC status N, 7 KDE base, 8 KDE throttle */
		uint8_t esc_id = 0;

		union {
			mavlink_lisum_vesc_status_1_t v1;
			mavlink_lisum_vesc_status_2_t v2;
			mavlink_lisum_vesc_status_3_t v3;
			mavlink_lisum_vesc_status_4_t v4;
			mavlink_lisum_vesc_status_5_t v5;
			mavlink_lisum_vesc_status_6_t v6;
			base_state_t                  kde;
			uint16_t                      thr;
		} in;

		for (int i = 0; i < VESC_MAX_VESC && kind == 0; i++) {
			vesc_instance_t *v = &vesc_fleet[i];
			if (!v->active) continue;

			if      (q == v->queue_status_1) { kind = 1; xQueueReceive(q, &in.v1, 0); }
			else if (q == v->queue_status_2) { kind = 2; xQueueReceive(q, &in.v2, 0); }
			else if (q == v->queue_status_3) { kind = 3; xQueueReceive(q, &in.v3, 0); }
			else if (q == v->queue_status_4) { kind = 4; xQueueReceive(q, &in.v4, 0); }
			else if (q == v->queue_status_5) { kind = 5; xQueueReceive(q, &in.v5, 0); }
			else if (q == v->queue_status_6) { kind = 6; xQueueReceive(q, &in.v6, 0); }
		}

		for (int i = 0; i < KDE_MAX_ESC && kind == 0; i++) {
			esc_instance_t *e = &esc_fleet[i];
			if (!e->activate) continue;

			if      (q == e->queue_status_1) { kind = 7; esc_id = e->esc_id; xQueueReceive(q, &in.kde, 0); }
			else if (q == e->queue_status_2) { kind = 8; esc_id = e->esc_id; xQueueReceive(q, &in.thr, 0); }
		}

		/* Encode the matching MAVLink message and push it out over UDP. */
		switch (kind) {
		case 1:
			mavlink_msg_lisum_vesc_status_1_encode(dev_mav_sysid, dev_mav_compid, &mav_tx_msg, &in.v1);
			break;
		case 2:
			mavlink_msg_lisum_vesc_status_2_encode(dev_mav_sysid, dev_mav_compid, &mav_tx_msg, &in.v2);
			break;
		case 3:
			mavlink_msg_lisum_vesc_status_3_encode(dev_mav_sysid, dev_mav_compid, &mav_tx_msg, &in.v3);
			break;
		case 4:
			mavlink_msg_lisum_vesc_status_4_encode(dev_mav_sysid, dev_mav_compid, &mav_tx_msg, &in.v4);
			break;
		case 5:
			mavlink_msg_lisum_vesc_status_5_encode(dev_mav_sysid, dev_mav_compid, &mav_tx_msg, &in.v5);
			break;
		case 6:
			mavlink_msg_lisum_vesc_status_6_encode(dev_mav_sysid, dev_mav_compid, &mav_tx_msg, &in.v6);
			break;
		case 7: {
			mavlink_lisum_esc_status_t e;
			memset(&e, 0, sizeof(e));
			e.index         = esc_id;
			e.voltage[0]    = in.kde.voltage;
			e.current[0]    = in.kde.current;
			e.rpm[0]        = in.kde.rpm;
			e.temp_motor[0] = (float)in.kde.temp;
			mavlink_msg_lisum_esc_status_encode(dev_mav_sysid, dev_mav_compid, &mav_tx_msg, &e);
			mav_send_locked();
			mav_send_esc_debug(esc_id, in.kde.warnning);
			continue;
		}
		default:
			/* kind 0 (stale/unknown queue) or 8 (KDE throttle has no dedicated
			 * message) - nothing to send */
			continue;
		}

		mav_send_locked();
	}
}

/* Send mav_tx_msg. Must hold mutex_udp: udp_send() shares udp.buffer with
 * udp_process() in task_work. */
static void mav_send_locked(void)
{
	xSemaphoreTake(mutex_udp, portMAX_DELAY);
	mav_send(&mav_handle, &mav_tx_msg);
	xSemaphoreGive(mutex_udp);
}

/* NAMED_VALUE_INT named "<prefix><esc_id>", e.g. "in2" (ids are < 100). */
static void mav_send_named_int(const char *prefix, uint8_t esc_id,
							   int32_t value)
{
	mavlink_named_value_int_t nv;
	size_t n = strlen(prefix);

	memset(&nv, 0, sizeof(nv));
	memcpy(nv.name, prefix, n);
	if (esc_id >= 10)
		nv.name[n++] = (char)('0' + (esc_id / 10) % 10);
	nv.name[n] = (char)('0' + esc_id % 10);

	nv.time_boot_ms = xTaskGetTickCount() * portTICK_PERIOD_MS;
	nv.value        = value;

	mavlink_msg_named_value_int_encode(dev_mav_sysid, dev_mav_compid,
									   &mav_tx_msg, &nv);
	mav_send_locked();
}

/* Debug stream sent right after each KDE LISUM_ESC_STATUS: what the ESC
 * itself reads on its throttle input (object 6), what it drives out
 * (object 7), and the BASE_STAT warning byte - LISUM_ESC_STATUS has no field
 * for any of them. */
static void mav_send_esc_debug(uint8_t esc_id, uint8_t warning)
{
	for (int i = 0; i < KDE_MAX_ESC; i++) {
		const esc_instance_t *e = &esc_fleet[i];

		if (!e->activate || e->esc_id != esc_id)
			continue;

		mav_send_named_int("in", esc_id, e->pwm_in);
		mav_send_named_int("out", esc_id, e->pwm_out);
		mav_send_named_int("warn", esc_id, warning);
		return;
	}
}

static void mav_send_heartbeat(const mavlink_heartbeat_t *hb)
{
	mavlink_msg_heartbeat_encode(dev_mav_sysid, dev_mav_compid, &mav_tx_msg,
								 hb);
	mav_send_locked();
}

static void mav_send_cmd_ack(const esc_comm_resp_t *resp)
{
	mavlink_command_ack_t ack;

	memset(&ack, 0, sizeof(ack));

	/* map the bridged object back to the MAVLink command that produced it
	 * (see mav_handle_cmd_long) */
	switch (resp->cmd.obj_id) {
	case CAN_OBJECT_ARM:
	case CAN_OBJECT_TURN_OFF:
		ack.command = MAV_CMD_COMPONENT_ARM_DISARM;
		break;
	case CAN_OBJECT_SET_DIRECTION:
		ack.command = MAV_CMD_DO_SET_REVERSE;
		break;
	case CAN_OBJECT_SET_PWM:
		ack.command = MAV_CMD_DO_SET_SERVO;
		break;
	default:
		return;
	}

	switch (resp->status) {
	case lStatus_Success:
		ack.result = MAV_RESULT_ACCEPTED;
		break;
	case lStatus_Busy:
		ack.result = MAV_RESULT_TEMPORARILY_REJECTED;
		break;
	default:
		ack.result = MAV_RESULT_FAILED;
		break;
	}

	ack.progress         = UINT8_MAX;
	ack.target_system    = client_mav_sysid;
	ack.target_component = client_mav_compid;

	mavlink_msg_command_ack_encode(dev_mav_sysid, dev_mav_compid, &mav_tx_msg,
								   &ack);
	mav_send_locked();
}

static void mav_recv_cb(mav_t *mav, mavlink_message_t *msg, void *arg)
{
	//xSemaphoreTake(mutex_mav, portMAX_DELAY);

	switch (msg->msgid) {
	case MAVLINK_MSG_ID_HEARTBEAT: {
		HAL_GPIO_SetPinValue(GPIO_HAL_INSTANCE_3, 25,
							 !HAL_GPIO_GetPinValue(GPIO_HAL_INSTANCE_3, 25));

		break;
	}
	case MAVLINK_MSG_ID_COMMAND_LONG: {

		mavlink_command_long_t cmd;

		mavlink_msg_command_long_decode(msg, &cmd);

		/* accept only commands addressed to us (0 == broadcast) */
		if ((cmd.target_system == 0 || cmd.target_system == mav->sysid) &&
			(cmd.target_component == 0 || cmd.target_component == mav->compid)) {
			dbg_cmd_long_rx++;

			/* Visible proof the UDP/MAVLink path is alive: esc_control.py
			 * never sends a HEARTBEAT, so the toggle below is the only thing
			 * that drives this LED during a test run. */
			HAL_GPIO_SetPinValue(
				GPIO_HAL_INSTANCE_3, 25,
				!HAL_GPIO_GetPinValue(GPIO_HAL_INSTANCE_3, 25));

			mav_handle_cmd_long(msg, &cmd);
		}

		break;
	}

	case MAVLINK_MSG_ID_LISUM_VESC_SET_DUTY: {
		mavlink_lisum_vesc_set_duty_t m;
		mavlink_msg_lisum_vesc_set_duty_decode(msg, &m);
		mav_push_vesc_cmd(m.vesc_id, CAN_PACKET_SET_DUTY, m.duty_cycle);
		break;
	}

	case MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT: {
		mavlink_lisum_vesc_set_current_t m;
		mavlink_msg_lisum_vesc_set_current_decode(msg, &m);
		mav_push_vesc_cmd(m.vesc_id, CAN_PACKET_SET_CURRENT, m.current);
		break;
	}

	case MAVLINK_MSG_ID_LISUM_VESC_SET_CURRENT_BRAKE: {
		mavlink_lisum_vesc_set_current_brake_t m;
		mavlink_msg_lisum_vesc_set_current_brake_decode(msg, &m);
		mav_push_vesc_cmd(m.vesc_id, CAN_PACKET_SET_CURRENT_BRAKE, m.current);
		break;
	}

	case MAVLINK_MSG_ID_LISUM_VESC_SET_RPM: {
		mavlink_lisum_vesc_set_rpm_t m;
		mavlink_msg_lisum_vesc_set_rpm_decode(msg, &m);
		mav_push_vesc_cmd(m.vesc_id, CAN_PACKET_SET_RPM, m.rpm);
		break;
	}

	case MAVLINK_MSG_ID_LISUM_VESC_SET_POS: {
		mavlink_lisum_vesc_set_pos_t m;
		mavlink_msg_lisum_vesc_set_pos_decode(msg, &m);
		mav_push_vesc_cmd(m.vesc_id, CAN_PACKET_SET_POS, m.pos);
		break;
	}

	case MAVLINK_MSG_ID_LISUM_VESC_PING: {
		mavlink_lisum_vesc_ping_t m;
		mavlink_msg_lisum_vesc_ping_decode(msg, &m);
		mav_push_vesc_cmd(m.vesc_id, CAN_PACKET_PING, 0.0f);
		break;
	}

	default:
		break;
	}
	//xSemaphoreGive(mutex_mav);
}

static void mav_handle_cmd_long(mavlink_message_t *msg,
								mavlink_command_long_t *cmd_long)
{
	esc_comm_msg_t comm;

	(void)msg;

	switch (cmd_long->command) {
	case MAV_CMD_DO_SET_SERVO: {
		/* param1: ESC id, param2: PWM [us] */
		int16_t pwm = (int16_t)cmd_long->param2;

		if (pwm < KDE_MINIMUM_PWM || pwm > 1900)
			return;

		comm.esc_id    = (uint8_t)cmd_long->param1;
		comm.obj_id    = CAN_OBJECT_SET_PWM;
		comm.comm_phar = (float)pwm;
		break;
	}

	case MAV_CMD_DO_SET_REVERSE:
		/* param1: reverse flag (0/1), param2: ESC id */
		comm.esc_id    = (uint8_t)cmd_long->param2;
		comm.obj_id    = CAN_OBJECT_SET_DIRECTION;
		comm.comm_phar = (cmd_long->param1 != 0.0f) ? (float)KDE_DIR_REVERSE
													: (float)KDE_DIR_FORWARD;
		break;

	case MAV_CMD_COMPONENT_ARM_DISARM:
		/* param1: arm flag (0/1). param2 is MAVLink's force magic (21196),
		 * not an ESC id - arm/disarm always applies to the whole fleet, so
		 * task_bridge gets the broadcast id. */
		comm.esc_id    = KDE_BROADCAST_ID;
		comm.obj_id    = (cmd_long->param1 != 0.0f) ? CAN_OBJECT_ARM
													: CAN_OBJECT_TURN_OFF;
		comm.comm_phar = 0.0f;
		break;

	default:
		return;
	}

	if (xQueueSendToBack(queue_cmd, &comm, 0) == pdPASS)
		dbg_cmd_queued++;
	else
		dbg_cmd_dropped++;
}

static void mav_push_vesc_cmd(uint8_t vesc_id, command_numbers_e command_id,
							  float command_param)
{
	/* command_param carries the raw MAVLink field value:
	 *   SET_DUTY          -> duty cycle [-1..1]
	 *   SET_CURRENT       -> current    (LISUM_VESC_SET_CURRENT field unit)
	 *   SET_CURRENT_BRAKE -> current    (LISUM_VESC_SET_CURRENT_BRAKE field unit)
	 *   SET_RPM           -> ERPM
	 *   SET_POS           -> position [deg]
	 *   PING              -> unused
	 * Apply any unit scaling here if the ground station and vesc_set_*()
	 * disagree on units. */
	vesc_command_message_t vcmd = {
		.vesc_id       = vesc_id,
		.command_id    = command_id,
		.command_param = command_param,
	};

	xQueueSendToBack(queue_vesc_cmd, &vcmd, 0);
}

static void timer_mav_hb_cb(TimerHandle_t xTimer)
{
	bool armed = (bridge_arm_state() == ESC_ARM_STATE_ARM);

	/* SAFETY_ARMED mirrors the bridge's arm state machine, so the ground
	 * station can see whether the last arm sequence actually completed. */
	mavlink_heartbeat_t mav_hb = {
		.type          = MAV_TYPE_GENERIC,
		.autopilot     = MAV_AUTOPILOT_GENERIC,
		.base_mode     = armed ? MAV_MODE_FLAG_SAFETY_ARMED : 0,
		.custom_mode   = 0,
		.system_status = armed ? MAV_STATE_ACTIVE : MAV_STATE_STANDBY};

	xQueueSendToBack(queue_mav_hb, &mav_hb, 0);
}


