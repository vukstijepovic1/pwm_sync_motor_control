/**
 * @file    ad7705.h
 * @brief   AD7705/AD7706 ADC Driver Definitions.
 * @version 1.0.0
 * @date    17.10.2025
 * @author  LisumLab
 * @note    Converted from Arduino C++ to LPC1768 C implementation
 */

#ifndef AD7705_H
#define AD7705_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <stdbool.h>
#include <stdint.h>

// LPC1768 HAL includes
#include "ad7705_def.h"
#include "common.h"
#include "gpio.h"
#include "spi.h"

/*******************************************************************************
 * Defines
 ******************************************************************************/

/**
 * @brief Default time to wait for a conversion to finish [us].
 * @details Must cover a full output period, otherwise a healthy part times out
 * simply because the previous result was already collected: the slowest
 * selectable rate is 20 Hz, i.e. 50 ms per conversion. Override per device
 * with ad7705_t::timeout_us.
 */
#define AD7705_DEFAULT_TIMEOUT_US 60000U

/**
 * @brief Time to wait for a self-calibration to finish [us].
 * @details A self-calibration is a two-step process that takes on the order of
 * six output periods, so it needs a far longer budget than a conversion.
 */
#define AD7705_CALIBRATION_TIMEOUT_US 1000000U

/**
 * @brief Blind wait for a self-calibration [ms], used by AD7705_DRDY_NONE.
 * @details With no readiness signal to poll there is nothing to wait on, but
 * the calibration still must not be interrupted by another register access.
 * Six output periods at the slowest selectable rate (20 Hz) is 300 ms.
 */
#define AD7705_CALIBRATION_BLIND_WAIT_MS 300U

/*******************************************************************************
 * Typedefs
 ******************************************************************************/

/**
 * @brief Source the driver polls to learn that a conversion finished.
 */
typedef enum {
	/** Poll the DRDY pin, and if it never asserts fall back to the RDY bit of
	 *  the communication register for the rest of the device's lifetime. This
	 *  keeps the ADC usable when DRDY is unwired or the pin is stuck. */
	AD7705_DRDY_AUTO = 0,
	/** Poll the DRDY pin only; time out if it never asserts. */
	AD7705_DRDY_PIN,
	/** Poll the RDY bit over SPI only; the DRDY pin need not be wired. */
	AD7705_DRDY_SPI,
	/** Do not check readiness at all - read the data register straight away.
	 *  In continuous conversion mode it always holds the most recent result,
	 *  so this returns real data without DRDY ever being consulted. The cost
	 *  is that a read landing exactly while the part updates that register
	 *  can return one corrupted sample, and that the same conversion is
	 *  returned twice if polled faster than the output rate. */
	AD7705_DRDY_NONE
} ad7705_drdy_mode_t;

/**
 * @brief AD7705 Click context object.
 * @details Context object definition of AD7705 ADC driver.
 */
typedef struct {
	// SPI configuration.
	// NOTE: the SPI peripheral is shared with the other devices on the bus, so
	// the application - not ad7705_init() - has to bring it up, and it must be
	// configured for SPI mode 3 (SCK idle high, sample on the second edge;
	// SPI_HAL_CPOL_LO + SPI_HAL_CPHA_SECOND in this HAL) with 8-bit words.
	// Only spi_instance is used by the driver; the remaining fields below
	// record what the bus was set up for and are not applied here.
	spi_hal_instance_t spi_instance; /**< SPI instance to use */
	uint32_t spi_clock;				 /**< SPI clock frequency */

	// GPIO pin configuration
	gpio_hal_instance_t cs_port; /**< Chip Select pin GPIO port */
	uint8_t cs_pin;				 /**< Chip Select pin number */

	gpio_hal_instance_t drdy_port; /**< Data Ready pin GPIO port */
	uint8_t drdy_pin;			   /**< Data Ready pin number */

	gpio_hal_instance_t reset_port; /**< Reset pin GPIO port */
	uint8_t reset_pin;				/**< Reset pin number */

	// SPI configuration parameters
	uint8_t data_bits; /**< SPI data bits */
	uint8_t cpha;	   /**< SPI CPHA */
	uint8_t cpol;	   /**< SPI CPOL */
	uint8_t mode;	   /**< SPI mode */

	// ADC parameters
	double vref; /**< Reference voltage */

	/** How to detect end of conversion. Set before ad7705_init(); zero
	 *  (AD7705_DRDY_AUTO) is a sane default. */
	ad7705_drdy_mode_t drdy_mode;

	/** Conversion wait budget [us]. Set before ad7705_init(); 0 selects
	 *  #AD7705_DEFAULT_TIMEOUT_US. */
	uint32_t timeout_us;

	/** Non-zero enables the input buffer (BUF) in ad7705_init_channel*().
	 *  The buffer presents a high impedance to the source, but it narrows the
	 *  permitted input range to AGND + 50 mV .. AVDD - 1.5 V. A ground-
	 *  referenced sensor that idles near 0 V therefore reads as ~0 with the
	 *  buffer on; leave this at 0 for such inputs, where the range instead
	 *  extends from GND - 30 mV to VDD + 30 mV. */
	uint8_t input_buffered;

	uint8_t channel_polarity[4]; /**< Polarity for each channel */
	uint8_t channel_gain[4];	 /**< Gain for each channel, needed to scale
									  a raw code back to volts */

	// Initialization flag
	bool initialized;

	/** Set by AD7705_DRDY_AUTO once the DRDY pin has been found unusable.
	 *  Read-only for callers - useful to spot a DRDY wiring fault that the
	 *  driver has silently worked around. */
	bool drdy_pin_faulty;

} ad7705_t;

/**
 * @brief AD7705 Click return value data.
 * @details Predefined enum values for driver return values.
 */
typedef enum {
	AD7705_OK            =  0,
	AD7705_ERROR         = -1,
	AD7705_ERROR_SPI     = -2,
	AD7705_ERROR_GPIO    = -3,
	AD7705_ERROR_CONFIG  = -4,
	AD7705_ERROR_TIMEOUT = -5

} ad7705_return_value_t;

typedef enum {
	AD7705_CHANNEL_0 = 0,
	AD7705_CHANNEL_1 = 1,
	AD7705_CHANNEL_2 = 2,
	AD7705_CHANNEL_3 = 3
} ad7705_adc_channels_t;

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define AD7705_CS_ASSERT(ctx)                                                  \
	HAL_GPIO_SetPinValue((ctx)->cs_port, (ctx)->cs_pin, GPIO_HAL_RESET)
#define AD7705_CS_DEASSERT(ctx)                                                \
	HAL_GPIO_SetPinValue((ctx)->cs_port, (ctx)->cs_pin, GPIO_HAL_SET)

/*******************************************************************************
 * API
 ******************************************************************************/

/**
 * @brief AD7705 initialization function.
 * @details This function initializes all necessary pins and peripherals used
 * for AD7705 ADC. User must configure the context object before calling this
 * function.
 * @param[in,out] ctx : Click context object with pre-configured pins and
 * parameters. See #ad7705_t object definition for detailed explanation.
 * @return @li @c  AD7705_OK - Success,
 *         @li @c  AD7705_ERROR - Error.
 *
 * See #ad7705_return_value_t definition for detailed explanation.
 */
ad7705_return_value_t ad7705_init(ad7705_t* ctx);

/**
 * @brief AD7705 reset function.
 * @details This function performs a software reset of the AD7705.
 * @param[in] ctx : Click context object.
 * @return @li @c  AD7705_OK - Success,
 *         @li @c  AD7705_ERROR - Error.
 */
ad7705_return_value_t ad7705_reset(ad7705_t* ctx);

/**
 * @brief Set next operation function.
 * @details This function sets the next operation (read/write) for specified
 * register and channel.
 * @param[in] ctx : Click context object.
 * @param[in] reg : Register to access.
 * @param[in] channel : Channel to use.
 * @param[in] read_write : Read (1) or Write (0) operation.
 * @return @li @c  AD7705_OK - Success,
 *         @li @c  AD7705_ERROR - Error.
 */
ad7705_return_value_t ad7705_set_next_operation(ad7705_t* ctx, uint8_t reg,
												uint8_t channel,
												uint8_t read_write);

/**
 * @brief Write clock register function.
 * @details This function writes the clock register configuration.
 * @param[in] ctx : Click context object.
 * @param[in] clk_dis : Clock disable bit.
 * @param[in] clk_div : Clock divider.
 * @param[in] update_rate : Output update rate.
 * @param[in] channel : Channel to configure.
 * @return @li @c  AD7705_OK - Success,
 *         @li @c  AD7705_ERROR - Error.
 */
ad7705_return_value_t
ad7705_write_clock_register(ad7705_t* ctx, uint8_t clk_dis, uint8_t clk_div,
							uint8_t update_rate, uint8_t channel);

/**
 * @brief Write setup register function.
 * @details This function writes the setup register configuration.
 * @param[in] ctx : Click context object.
 * @param[in] operation_mode : Operating mode.
 * @param[in] gain : Gain setting.
 * @param[in] unipolar : Unipolar (0) or Bipolar (1).
 * @param[in] buffered : Buffer enable.
 * @param[in] fsync : FSYNC bit.
 * @param[in] channel : Channel to configure.
 * @return @li @c  AD7705_OK - Success,
 *         @li @c  AD7705_ERROR - Error.
 */
ad7705_return_value_t
ad7705_write_setup_register(ad7705_t* ctx, uint8_t operation_mode, uint8_t gain,
							uint8_t unipolar, uint8_t buffered, uint8_t fsync,
							uint8_t channel);

/**
 * @brief Read ADC result function.
 * @details This function reads the ADC conversion result and converts to
 * voltage.
 * @param[in] ctx : Click context object.
 * @param[in] channel : Channel to read from.
 * @param[in] ref_offset : Reference offset added to the converted value.
 * @param[out] result : Conversion result in volts, gain already divided out.
 * @return @li @c  AD7705_OK - Success,
 *         @li @c  AD7705_ERROR_TIMEOUT - No conversion within the budget,
 *         @li @c  AD7705_ERROR - Error.
 */
ad7705_return_value_t ad7705_read_adc_result(ad7705_t* ctx, uint8_t channel,
											 float ref_offset, double* result);

/**
 * @brief Read raw ADC result function.
 * @details Waits - bounded by ad7705_t::timeout_us - for a conversion to
 * finish, then reads the raw 16-bit code out of the data register.
 * @param[in] ctx : Click context object.
 * @param[in] channel : Channel to read from.
 * @param[out] result : Raw ADC result.
 * @return @li @c  AD7705_OK - Success,
 *         @li @c  AD7705_ERROR_TIMEOUT - No conversion within the budget,
 *         @li @c  AD7705_ERROR - Error.
 */
ad7705_return_value_t ad7705_read_raw_adc_result(ad7705_t* ctx, uint8_t channel,
												 uint16_t* result);

/**
 * @brief Numeric gain currently configured for a channel.
 * @details Turns the stored G2:G0 code into the factor it stands for, so a
 * caller scaling a raw code does not have to know how gain is encoded, and a
 * calibration expressed at unity gain stays valid when the gain is changed.
 * @param[in] ctx : Click context object.
 * @param[in] channel : Channel to query.
 * @return The gain as a plain multiplier: 1, 2, 4, 8, 16, 32, 64 or 128.
 *         1 if @p ctx is NULL.
 */
uint8_t ad7705_channel_gain(const ad7705_t* ctx, uint8_t channel);

/**
 * @brief Data ready check function, read from the DRDY pin.
 * @details Single non-blocking sample of the DRDY pin. Note that this reports
 * the pin only - if DRDY is not wired, use ad7705_data_ready_via_comm().
 * @param[in] ctx : Click context object.
 * @param[in] channel : Channel to check.
 * @return @li @c  true - Data ready,
 *         @li @c  false - Data not ready.
 */
bool ad7705_data_ready(ad7705_t* ctx, uint8_t channel);

/**
 * @brief Data ready check function, read over SPI instead of the DRDY pin.
 * @details Reads bit 7 (RDY) of the Communications Register - the same
 * ready/not-ready information the DRDY pin carries, but obtained purely
 * over SPI. Useful to tell a DRDY wiring fault apart from the ADC itself
 * never finishing a conversion.
 * @param[in] ctx : Click context object.
 * @param[in] channel : Channel to check.
 * @param[out] ready : Set to true if data is ready, false otherwise.
 * @return @li @c  AD7705_OK - Success,
 *         @li @c  AD7705_ERROR_* - Error (see #ad7705_return_value_t).
 */
ad7705_return_value_t ad7705_data_ready_via_comm(ad7705_t* ctx, uint8_t channel,
												 bool* ready);

/**
 * @brief Initialize channel function.
 * @details This function initializes a channel with default parameters.
 * @param[in] ctx : Click context object.
 * @param[in] channel : Channel to initialize.
 * @return @li @c  AD7705_OK - Success,
 *         @li @c  AD7705_ERROR - Error.
 */
ad7705_return_value_t ad7705_init_channel(ad7705_t* ctx, uint8_t channel);

/**
 * @brief Initialize channel with parameters function.
 * @details This function initializes a channel with specific parameters.
 * @param[in] ctx : Click context object.
 * @param[in] channel : Channel to initialize.
 * @param[in] clk_divider : Clock divider setting.
 * @param[in] polarity : Unipolar/Bipolar setting.
 * @param[in] gain : Gain setting.
 * @param[in] update_rate : Update rate setting.
 * @return @li @c  AD7705_OK - Success,
 *         @li @c  AD7705_ERROR - Error.
 */
ad7705_return_value_t
ad7705_init_channel_with_params(ad7705_t* ctx, uint8_t channel,
								uint8_t clk_divider, uint8_t polarity,
								uint8_t gain, uint8_t update_rate);

ad7705_return_value_t ad7705_self_calibration(ad7705_t* ctx, uint8_t channel,
											  uint8_t gain, uint8_t unipolar);

#ifdef __cplusplus
}
#endif

#endif // AD7705_H
