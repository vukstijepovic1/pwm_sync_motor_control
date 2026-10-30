/**
 * @file    ad7705.c
 * @brief   AD7705/AD7706 ADC Driver Source code.
 * @version 1.0.0
 * @date    17.10.2025
 * @author  LisumLab
 * @note    Converted from Arduino C++ to LPC1768 C implementation
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "ad7705.h"
#include "util.h"

/*******************************************************************************
 * Defines
 ******************************************************************************/

#define AD7705_RESET_SEQUENCE_SIZE 4

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

static ad7705_return_value_t ad7705_spi_write_byte(ad7705_t* ctx, uint8_t data);
static ad7705_return_value_t ad7705_spi_read_byte(ad7705_t* ctx, uint8_t* data);

/* Conversion wait budget configured for this device. */
static uint32_t ad7705_conversion_timeout_us(const ad7705_t* ctx);

/* Block until a conversion is available, or until timeout_us elapses. */
static ad7705_return_value_t ad7705_wait_data_ready(ad7705_t* ctx,
													uint8_t channel,
													uint32_t timeout_us);

/*******************************************************************************
 * API
 ******************************************************************************/

ad7705_return_value_t ad7705_init(ad7705_t* ctx)
{
	lStatus_t status;
	gpio_hal_cfg_type_t gpio_cfg;

	if (!ctx) {
		return AD7705_ERROR_CONFIG;
	}

	// The SPI peripheral is shared and is brought up by the application, not
	// here - see the note on spi_instance in ad7705.h. This function only
	// owns the three GPIOs.

	ctx->drdy_pin_faulty = false;

	// CS pin (output, push-pull). pinDir is the field that actually turns the
	// pad into an output; assigning the direction to pinMode (and then
	// overwriting it) left pinDir uninitialised, so CS and RESET stayed
	// floating inputs - the part was never selected, never released from
	// reset, and therefore never converted or asserted DRDY.
	gpio_cfg.pinDir = GPIO_HAL_OUTPUT;
	gpio_cfg.pinMode = GPIO_HAL_PINMODE_TRISTATE;
	gpio_cfg.openDrain = GPIO_HAL_OPENDRAIN_NORMAL;
	status = HAL_GPIO_Init(ctx->cs_port, ctx->cs_pin, &gpio_cfg);
	if (status != lStatus_Success) {
		return AD7705_ERROR_GPIO;
	}

	// Reset pin (output, push-pull)
	gpio_cfg.pinDir = GPIO_HAL_OUTPUT;
	gpio_cfg.pinMode = GPIO_HAL_PINMODE_TRISTATE;
	gpio_cfg.openDrain = GPIO_HAL_OPENDRAIN_NORMAL;
	status = HAL_GPIO_Init(ctx->reset_port, ctx->reset_pin, &gpio_cfg);
	if (status != lStatus_Success) {
		return AD7705_ERROR_GPIO;
	}

	// Set CS high (deselected) and Reset high (inactive). HAL_GPIO_Init()
	// drives every pin it configures low, so do this before anything else
	// talks to the part.
	AD7705_CS_DEASSERT(ctx);
	HAL_GPIO_SetPinValue(ctx->reset_port, ctx->reset_pin, GPIO_HAL_SET);

	// DRDY pin (input, pulled up). The pull-up makes an unwired DRDY read as
	// "not ready" instead of falsely announcing a conversion; with
	// AD7705_DRDY_AUTO the driver then notices the pin never asserts and
	// switches over to polling the RDY bit across SPI.
	gpio_cfg.pinDir = GPIO_HAL_INPUT;
	gpio_cfg.pinMode = GPIO_HAL_PINMODE_PULLUP;
	gpio_cfg.openDrain = GPIO_HAL_OPENDRAIN_NORMAL;
	status = HAL_GPIO_Init(ctx->drdy_port, ctx->drdy_pin, &gpio_cfg);
	if (status != lStatus_Success) {
		return AD7705_ERROR_GPIO;
	}

	ctx->initialized = true;

	return AD7705_OK;
}

ad7705_return_value_t ad7705_reset(ad7705_t* ctx)
{
	if (!ctx || !ctx->initialized) {
		return AD7705_ERROR_CONFIG;
	}

	HAL_GPIO_SetPinValue(ctx->reset_port, ctx->reset_pin, GPIO_HAL_RESET);

	HAL_DelayMS(10); // Wait for reset to complete

	HAL_GPIO_SetPinValue(ctx->reset_port, ctx->reset_pin, GPIO_HAL_SET);

	HAL_DelayMS(1000);

	AD7705_CS_ASSERT(ctx);

	// Send reset sequence (32 consecutive 1s)
	ad7705_return_value_t status = AD7705_OK;

	for (int i = 0; i < AD7705_RESET_SEQUENCE_SIZE; i++) {
		ad7705_return_value_t write_status = ad7705_spi_write_byte(ctx, 0xFF);

		if (write_status != AD7705_OK) {
			status = write_status;
		}
	}

	AD7705_CS_DEASSERT(ctx);

	HAL_DelayMS(1000);

	// The interface is back to its power-on state, so nothing is known about
	// the part's configuration any more.
	ctx->drdy_pin_faulty = false;

	return status;
}

ad7705_return_value_t ad7705_set_next_operation(ad7705_t* ctx, uint8_t reg,
												uint8_t channel,
												uint8_t read_write)
{
	if (!ctx || !ctx->initialized) {
		return AD7705_ERROR_CONFIG;
	}

	uint8_t comm_reg = 0;

	// Build communication register
	// Bit 7:   DRDY (status on read, written as 0)
	// Bit 6-4: RS2-RS0, register selection
	// Bit 3:   R/W (1 = read, 0 = write)
	// Bit 2:   STBY (written as 0, i.e. stay powered up)
	// Bit 1-0: CH1-CH0, channel selection

	comm_reg |= (read_write & 0x1) << 3;
	comm_reg |= (channel & 0x3);
	comm_reg |= (reg & 0x7) << 4;

	AD7705_CS_ASSERT(ctx);
	ad7705_return_value_t result = ad7705_spi_write_byte(ctx, comm_reg);
	AD7705_CS_DEASSERT(ctx);

	return result;
}

ad7705_return_value_t
ad7705_write_clock_register(ad7705_t* ctx, uint8_t clk_dis, uint8_t clk_div,
							uint8_t update_rate, uint8_t channel)
{
	if (!ctx || !ctx->initialized) {
		return AD7705_ERROR_CONFIG;
	}

	// Set communication register for clock register write
	ad7705_return_value_t status = ad7705_set_next_operation(
		ctx, AD7705_REG_CLOCK, channel, AD7705_COMM_WRITE);
	if (status != AD7705_OK) {
		return status;
	}

	uint8_t clock_reg = 0;

	// Build clock register
	// Bit 7-5: ZERO (must be written as 0)
	// Bit 4:   CLKDIS
	// Bit 3:   CLKDIV
	// Bit 2:   CLK
	// Bit 1-0: FS1, FS0
	// CLK:FS1:FS0 together select the update rate, which is why update_rate
	// is a three-bit field occupying bits 2-0.

	clock_reg |= (clk_dis & 0x1) << 4;
	clock_reg |= (clk_div & 0x1) << 3;
	clock_reg |= (update_rate & 0x7);

	AD7705_CS_ASSERT(ctx);
	status = ad7705_spi_write_byte(ctx, clock_reg);
	AD7705_CS_DEASSERT(ctx);

	if (status != AD7705_OK) {
		return status;
	}

	status = ad7705_set_next_operation(ctx, AD7705_REG_CLOCK, channel,
									   AD7705_COMM_READ);
	if (status != AD7705_OK) {
		return status;
	}

	uint8_t read = 0xFF;

	AD7705_CS_ASSERT(ctx);
	status = ad7705_spi_read_byte(ctx, &read);
	AD7705_CS_DEASSERT(ctx);

	if (status != AD7705_OK) {
		return status;
	}

	// Read back what was just written. The reserved bits always read 0, so an
	// exact match is expected; a mismatch means the part is not listening
	// (wiring, CS, or SPI mode) and is worth catching here rather than as a
	// stuck DRDY much later on.
	return (read == clock_reg) ? AD7705_OK : AD7705_ERROR;
}

ad7705_return_value_t
ad7705_write_setup_register(ad7705_t* ctx, uint8_t operation_mode, uint8_t gain,
							uint8_t unipolar, uint8_t buffered, uint8_t fsync,
							uint8_t channel)
{
	if (!ctx || !ctx->initialized) {
		return AD7705_ERROR_CONFIG;
	}

	// Set communication register for setup register write
	ad7705_return_value_t status = ad7705_set_next_operation(
		ctx, AD7705_REG_SETUP, channel, AD7705_COMM_WRITE);
	if (status != AD7705_OK) {
		return status;
	}

	uint8_t setup_reg = 0;

	// Build setup register
	// Bit 7-6: Operating mode
	// Bit 5-3: Gain
	// Bit 2: Unipolar/Bipolar
	// Bit 1: Buffered
	// Bit 0: FSYNC

	setup_reg |= (operation_mode & 0x3) << 6;
	setup_reg |= (gain & 0x7) << 3;
	setup_reg |= (unipolar & 0x1) << 2;
	setup_reg |= (buffered & 0x1) << 1;
	setup_reg |= (fsync & 0x1);

	AD7705_CS_ASSERT(ctx);
	status = ad7705_spi_write_byte(ctx, setup_reg);
	AD7705_CS_DEASSERT(ctx);

	if (status != AD7705_OK) {
		return status;
	}

	status = ad7705_set_next_operation(ctx, AD7705_REG_SETUP, channel,
									   AD7705_COMM_READ);
	if (status != AD7705_OK) {
		return status;
	}

	uint8_t read = 0xFF;

	AD7705_CS_ASSERT(ctx);
	status = ad7705_spi_read_byte(ctx, &read);
	AD7705_CS_DEASSERT(ctx);

	if (status != AD7705_OK) {
		return status;
	}

	// Read back what was just written, but ignore MD1:MD0 - a calibration
	// mode clears itself once the calibration finishes, so those two bits
	// legitimately differ from what was written.
	return ((read & 0x3F) == (setup_reg & 0x3F)) ? AD7705_OK : AD7705_ERROR;
}

ad7705_return_value_t ad7705_read_raw_adc_result(ad7705_t* ctx, uint8_t channel,
												 uint16_t* result)
{
	if (!ctx || !ctx->initialized || !result) {
		return AD7705_ERROR_CONFIG;
	}

	ad7705_return_value_t status = ad7705_wait_data_ready(
		ctx, channel, ad7705_conversion_timeout_us(ctx));
	if (status != AD7705_OK) {
		return status;
	}

	status = ad7705_set_next_operation(ctx, AD7705_REG_DATA, channel,
									   AD7705_COMM_READ);
	if (status != AD7705_OK) {
		return status;
	}

	uint8_t high_byte, low_byte;

	AD7705_CS_ASSERT(ctx);

	status = ad7705_spi_read_byte(ctx, &high_byte);
	if (status == AD7705_OK) {
		status = ad7705_spi_read_byte(ctx, &low_byte);
	}

	AD7705_CS_DEASSERT(ctx);

	if (status == AD7705_OK) {
		*result = ((uint16_t)high_byte << 8) | low_byte;
	}

	return status;
}

ad7705_return_value_t ad7705_read_adc_result(ad7705_t* ctx, uint8_t channel,
											 float ref_offset, double* result)
{
	if (!ctx || !ctx->initialized || !result) {
		return AD7705_ERROR_CONFIG;
	}

	uint16_t raw_result;
	ad7705_return_value_t status =
		ad7705_read_raw_adc_result(ctx, channel, &raw_result);

	if (status == AD7705_OK) {
		uint8_t polarity = ctx->channel_polarity[channel & 0x3];
		double gain = (double)ad7705_channel_gain(ctx, channel);
		double full_scale = ctx->vref / gain;

		if (polarity == AD7705_UNIPOLAR) {
			// Unipolar: 0 V .. +VREF/GAIN, Code = 65536 x AIN x GAIN / VREF
			*result =
				((double)raw_result / AD7705_FULL_SCALE_CODES) * full_scale +
				ref_offset;
		} else { // AD7705_BIPOLAR
			// Bipolar: -VREF/GAIN .. +VREF/GAIN. The coding is offset binary,
			// not two's complement - 0x0000 is negative full scale, 0x8000 is
			// 0 V, 0xFFFF is positive full scale - so casting to int16_t would
			// mirror the top and bottom halves of the range onto each other.
			*result = (((double)raw_result / AD7705_HALF_SCALE_CODES) - 1.0) *
						  full_scale +
					  ref_offset;
		}
	}

	return status;
}

uint8_t ad7705_channel_gain(const ad7705_t* ctx, uint8_t channel)
{
	if (!ctx) {
		return 1;
	}

	// The G2:G0 code is the base-two logarithm of the gain it selects.
	return (uint8_t)(1U << (ctx->channel_gain[channel & 0x3] & 0x7));
}

bool ad7705_data_ready(ad7705_t* ctx, uint8_t channel)
{
	(void)channel; // one DRDY pin covers every channel

	if (!ctx || !ctx->initialized) {
		return false;
	}

	// Check DRDY pin (active low)
	return (HAL_GPIO_GetPinValue(ctx->drdy_port, ctx->drdy_pin) ==
			GPIO_HAL_RESET);
}

ad7705_return_value_t ad7705_data_ready_via_comm(ad7705_t* ctx, uint8_t channel,
												 bool* ready)
{
	if (!ctx || !ctx->initialized || !ready) {
		return AD7705_ERROR_CONFIG;
	}

	ad7705_return_value_t status =
		ad7705_set_next_operation(ctx, AD7705_REG_CMM, channel,
								  AD7705_COMM_READ);
	if (status != AD7705_OK) {
		return status;
	}

	uint8_t comm_reg = 0xFF;

	AD7705_CS_ASSERT(ctx);
	status = ad7705_spi_read_byte(ctx, &comm_reg);
	AD7705_CS_DEASSERT(ctx);

	if (status == AD7705_OK) {
		// RDY is active low, exactly like the DRDY pin
		*ready = ((comm_reg & AD7705_COMM_RDY_MASK) == 0);
	}

	return status;
}

ad7705_return_value_t ad7705_init_channel(ad7705_t* ctx, uint8_t channel)
{
	// Initialize channel with default parameters. AD7705_UPDATE_RATE_100 is
	// only valid with a 1 MHz MCLK IN - pick the rate that matches the
	// crystal on the board via ad7705_init_channel_with_params().
	return ad7705_init_channel_with_params(ctx, channel, AD7705_CLK_DIV_1,
										   AD7705_BIPOLAR, AD7705_GAIN_1,
										   AD7705_UPDATE_RATE_100);
}

ad7705_return_value_t
ad7705_init_channel_with_params(ad7705_t* ctx, uint8_t channel,
								uint8_t clk_divider, uint8_t polarity,
								uint8_t gain, uint8_t update_rate)
{
	if (!ctx || !ctx->initialized) {
		return AD7705_ERROR_CONFIG;
	}

	ad7705_return_value_t status;

	// Write clock register
	status =
		ad7705_write_clock_register(ctx, 0, clk_divider, update_rate, channel);
	if (status != AD7705_OK) {
		return status;
	}

	HAL_DelayMS(100);

	// Write setup register. Buffering costs input range: with BUF=1 the
	// analog input must stay between AGND + 50 mV and AVDD - 1.5 V, so a
	// sensor whose output sits at or near ground reads as ~0 no matter what
	// it is actually doing. See ad7705_t::input_buffered.
	status = ad7705_write_setup_register(ctx, AD7705_MODE_NORMAL, gain,
										 polarity, ctx->input_buffered ? 1 : 0,
										 0, channel);
	if (status != AD7705_OK) {
		return status;
	}

	ctx->channel_polarity[channel & 0x3] = polarity;
	ctx->channel_gain[channel & 0x3] = gain;

	// Wait for setup to complete
	HAL_DelayMS(100);

	return AD7705_OK;
}

ad7705_return_value_t ad7705_self_calibration(ad7705_t* ctx, uint8_t channel,
											  uint8_t gain, uint8_t unipolar)
{
	if (!ctx || !ctx->initialized) {
		return AD7705_ERROR_CONFIG;
	}

	// 1. Pročitaj trenutni setup register da bi kalibracija tekla sa istim
	//    BUF i FSYNC bitovima sa kojima će kanal i raditi - kalibracija sa
	//    isključenim baferom ne poništava ofset bafera koji se posle koristi.
	ad7705_return_value_t status = ad7705_set_next_operation(
		ctx, AD7705_REG_SETUP, channel, AD7705_COMM_READ);
	if (status != AD7705_OK) {
		return status;
	}

	uint8_t current_setup = 0;

	AD7705_CS_ASSERT(ctx);
	status = ad7705_spi_read_byte(ctx, &current_setup);
	AD7705_CS_DEASSERT(ctx);

	if (status != AD7705_OK) {
		return status;
	}

	// 2. Postavi komunikacioni registar za upis u setup register
	status = ad7705_set_next_operation(ctx, AD7705_REG_SETUP, channel,
									   AD7705_COMM_WRITE);
	if (status != AD7705_OK) {
		return status;
	}

	// 3. Formiraj setup register za Self-Calibration
	// MD1=0, MD0=1 -> self-cal
	// gain, unipolar po parametrima; BUF i FSYNC zadržani iz trenutnog setup-a
	uint8_t setup_reg = 0;
	setup_reg |= (0x01 << 6);			 // MD1=0, MD0=1
	setup_reg |= (gain & 0x07) << 3;	 // G2-G0
	setup_reg |= (unipolar & 0x01) << 2; // B/U
	setup_reg |= (current_setup & 0x03); // BUF, FSYNC

	// 4. Pošalji setup register
	AD7705_CS_ASSERT(ctx);
	status = ad7705_spi_write_byte(ctx, setup_reg);
	AD7705_CS_DEASSERT(ctx);

	if (status != AD7705_OK)
		return status;

	// 5. Sačekaj da DRDY postane LOW (kalibracija završena). Self-kalibracija
	//    traje oko šest perioda konverzije, pa ima svoj, duži timeout - bez
	//    timeout-a jedan neispravan DRDY pin zaglavi ceo task zauvek.
	ctx->channel_polarity[channel & 0x3] = unipolar;
	ctx->channel_gain[channel & 0x3] = gain;

	if (ctx->drdy_mode == AD7705_DRDY_NONE) {
		// Nema šta da se anketira, a kalibracija se ne sme prekinuti drugim
		// pristupom registrima - zato se ovde čeka na slepo, duže nego što
		// kalibraciji može zatrebati i na najsporijoj izlaznoj brzini.
		HAL_DelayMS(AD7705_CALIBRATION_BLIND_WAIT_MS);
	} else {
		status =
			ad7705_wait_data_ready(ctx, channel, AD7705_CALIBRATION_TIMEOUT_US);
		if (status != AD7705_OK) {
			return status;
		}
	}

	// 6. Kalibracija završena, ADC se vraća u normal mode automatski
	return AD7705_OK;
}

/*******************************************************************************
 * Private Functions
 ******************************************************************************/

static uint32_t ad7705_conversion_timeout_us(const ad7705_t* ctx)
{
	return (ctx->timeout_us != 0U) ? ctx->timeout_us
								   : AD7705_DEFAULT_TIMEOUT_US;
}

/**
 * @brief   Wait for end of conversion without the risk of never returning.
 * @details The DRDY pin is tried first because it costs nothing to sample.
 *          If it never asserts - unwired pin, pin stuck high, ADC held in
 *          reset - AD7705_DRDY_AUTO gives up on it permanently and polls the
 *          RDY bit of the communication register over SPI instead, which
 *          carries the same information and needs no extra wire.
 *          AD7705_DRDY_NONE skips the whole question and reads whatever the
 *          data register currently holds.
 */
static ad7705_return_value_t ad7705_wait_data_ready(ad7705_t* ctx,
													uint8_t channel,
													uint32_t timeout_us)
{
	uint64_t start;

	if (ctx->drdy_mode == AD7705_DRDY_NONE) {
		return AD7705_OK;
	}

	if (ctx->drdy_mode != AD7705_DRDY_SPI && !ctx->drdy_pin_faulty) {
		start = HAL_GetTimeUS();

		while (!ad7705_data_ready(ctx, channel)) {
			if ((HAL_GetTimeUS() - start) >= timeout_us) {
				if (ctx->drdy_mode == AD7705_DRDY_PIN) {
					return AD7705_ERROR_TIMEOUT;
				}

				// AD7705_DRDY_AUTO: the pin had a full conversion period to
				// assert and did not, so stop trusting it from here on.
				ctx->drdy_pin_faulty = true;
				break;
			}
		}

		if (!ctx->drdy_pin_faulty) {
			return AD7705_OK;
		}
	}

	start = HAL_GetTimeUS();

	for (;;) {
		bool ready = false;
		ad7705_return_value_t status =
			ad7705_data_ready_via_comm(ctx, channel, &ready);

		if (status != AD7705_OK) {
			return status;
		}

		if (ready) {
			return AD7705_OK;
		}

		if ((HAL_GetTimeUS() - start) >= timeout_us) {
			return AD7705_ERROR_TIMEOUT;
		}
	}
}

static ad7705_return_value_t ad7705_spi_write_byte(ad7705_t* ctx, uint8_t data)
{
	lStatus_t status = HAL_SPI_Transmit(ctx->spi_instance, &data, 1, 1000);

	return (status == lStatus_Success) ? AD7705_OK : AD7705_ERROR_SPI;
}

static ad7705_return_value_t ad7705_spi_read_byte(ad7705_t* ctx, uint8_t* data)
{
	lStatus_t status = HAL_SPI_Receive(ctx->spi_instance, data, 1, 1000);

	return (status == lStatus_Success) ? AD7705_OK : AD7705_ERROR_SPI;
}