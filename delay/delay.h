#ifndef DELAY_H
#define DELAY_H

#ifdef __cplusplus
extern "C" {
#endif


#include "stm32l1xx_hal.h"

/**
 * @brief  Initializes DWT_Cycle_Count for DWT_Delay_us function
 * @return Error DWT counter
 *         1: DWT counter Error
 *         0: DWT counter works
 */
uint32_t delay_init(void);

/**
 * @brief  This function turns microseconds to ticks/cycles
 * @param  microseconds: microseconds to convert
 */
__STATIC_INLINE uint32_t us_to_cycles(volatile uint32_t microseconds)
{
	return microseconds * (HAL_RCC_GetHCLKFreq() / 1000000.0);
}

/**
 * @brief  This function turns milliseconds to ticks/cycles
 * @param  milliseconds: milliseconds to convert
 */
__STATIC_INLINE uint32_t ms_to_cycles(volatile uint32_t milliseconds)
{
	return milliseconds * (HAL_RCC_GetHCLKFreq() / 1000.0);
}

/**
 * @brief  This function turns microseconds to ticks/cycles
 * @param  seconds: seconds to convert
 */
__STATIC_INLINE uint32_t s_to_cycles(volatile uint32_t seconds)
{
	return seconds * HAL_RCC_GetHCLKFreq();
}

/**
 * @brief  This function provides a delay (in microseconds)
 * @param  microseconds: delay in microseconds
 */
__STATIC_INLINE void delay_usec(volatile uint32_t microseconds)
{
	uint32_t clk_cycle_start = DWT->CYCCNT;

	/* Go to number of cycles for system */
	microseconds = us_to_cycles(microseconds);

	/* Delay till end */
	while ((DWT->CYCCNT - clk_cycle_start) < microseconds);
}

/**
 * @brief  This function provides a delay (in milliseconds)
 * @param  milliseconds: delay in milliseconds
 */
__STATIC_INLINE void delay_msec(volatile uint32_t milliseconds)
{
	delay_usec(milliseconds * 1000);
}

/**
 * @brief  This function provides a delay (in seconds)
 * @param  seconds: delay in seconds
 */
__STATIC_INLINE void delay_sec(volatile uint32_t seconds)
{
	delay_msec(seconds * 1000);
}

/**
 * @brief  This function returns current ticks
 * @param  void
 */
__STATIC_INLINE uint32_t ticks(void)
{
	return DWT->CYCCNT;
}

#ifdef __cplusplus
}
#endif

#endif /* DELAY_H */
