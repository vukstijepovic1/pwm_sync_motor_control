/**
 * @file    ad7705_def.h
 * @brief   AD7705/AD7706 ADC Driver Definitions.
 * @version 1.0.0
 * @date    17.10.2025
 * @author  LisumLab
 * @note    Converted from Arduino C++ to LPC1768 C implementation
 */

#ifndef AD7705_DEF_H
#define AD7705_DEF_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdbool.h>
#include <stdint.h>

/******************************************************************************
 * Defines
 ******************************************************************************/

// Full scale of the 16-bit conversion result. Per the datasheet the unipolar
// transfer function is Code = 65536 x AIN x GAIN / VREF, and the bipolar one
// is Code = 32768 x [(AIN x GAIN / VREF) + 1].

#define AD7705_FULL_SCALE_CODES 65536.0
#define AD7705_HALF_SCALE_CODES 32768.0

// Register selection (RS2 RS1 RS0)
#define AD7705_REG_CMM    0x0 /* Communication register 8 bit */
#define AD7705_REG_SETUP  0x1 /* Setup register 8 bit */
#define AD7705_REG_CLOCK  0x2 /* Clock register 8 bit */
#define AD7705_REG_DATA   0x3 /* Data register 16 bit */
#define AD7705_REG_TEST   0x4 /* Test register 8 bit, POR 0x0 */
#define AD7705_REG_NOP    0x5 /* No operation */
#define AD7705_REG_OFFSET 0x6 /* Offset register 24 bit */
#define AD7705_REG_GAIN   0x7	  /**< Gain register 24 bit */

// Channel selection for AD7706 (for AD7705 use the first two channel
// definitions)            CH1 CH0
#define AD7705_CHN_AIN1 0x0 /* AIN1; calibration register pair 0 */
#define AD7705_CHN_AIN2 0x1 /* AIN2; calibration register pair 1 */
#define AD7705_CHN_COMM 0x2 /* Common; calibration register pair 0 */
#define AD7705_CHN_AIN3 0x3 /* AIN3; calibration register pair 2 */

// Output update rate (CLK FS1 FS0). The CLK bit tells the part which MCLK it
// is running from, so the first four values are only valid with a 1 MHz
// crystal and the last four only with a 2.4576 MHz one - picking a rate from
// the wrong group mis-scales the modulator and digital filter.
#define AD7705_UPDATE_RATE_20  0x0  /* 20 Hz, MCLK 1 MHz */
#define AD7705_UPDATE_RATE_25  0x1  /* 25 Hz, MCLK 1 MHz */
#define AD7705_UPDATE_RATE_100 0x2  /* 100 Hz, MCLK 1 MHz */
#define AD7705_UPDATE_RATE_200 0x3  /* 200 Hz, MCLK 1 MHz */
#define AD7705_UPDATE_RATE_50  0x4  /* 50 Hz, MCLK 2.4576 MHz */
#define AD7705_UPDATE_RATE_60  0x5  /* 60 Hz, MCLK 2.4576 MHz */
#define AD7705_UPDATE_RATE_250 0x6  /* 250 Hz, MCLK 2.4576 MHz */
#define AD7705_UPDATE_RATE_500 0x7  /* 500 Hz, MCLK 2.4576 MHz */

// Operating mode options (MD1 MD0)
#define AD7705_MODE_NORMAL         0x0 /* Normal mode */
#define AD7705_MODE_SELF_CAL       0x1 /* Self-calibration */
#define AD7705_MODE_ZERO_SCALE_CAL 0x2 /* Zero-scale system calibration */
#define AD7705_MODE_FULL_SCALE_CAL 0x3 /* Full-scale system calibration */

// Gain setting
#define AD7705_GAIN_1   0x0
#define AD7705_GAIN_2   0x1
#define AD7705_GAIN_4   0x2
#define AD7705_GAIN_8   0x3
#define AD7705_GAIN_16  0x4
#define AD7705_GAIN_32  0x5
#define AD7705_GAIN_64  0x6
#define AD7705_GAIN_128 0x7

// Polarity
#define AD7705_UNIPOLAR 0x1
#define AD7705_BIPOLAR  0x0

// Clock divider (CLKDIV). This is a single bit in the clock register, not a
// two-bit field: either MCLK IN is used as-is, or it is divided by two before
// it reaches the modulator. Divide only when MCLK IN is 4.9152 MHz / 2 MHz.

#define AD7705_CLK_DIV_1 0x0 /* MCLK IN used directly */
#define AD7705_CLK_DIV_2 0x1 /* MCLK IN divided by 2 */

// Communication register bits
#define AD7705_COMM_WRITE 0x0
#define AD7705_COMM_READ  0x1

/**< RDY, bit 7 of the communication register. Active low, and carries the
 *   same ready/not-ready information as the DRDY pin. */
#define AD7705_COMM_RDY_MASK 0x80


#ifdef __cplusplus
}
#endif

#endif // AD7705_DEF_H
