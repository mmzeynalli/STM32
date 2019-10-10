#include "defines.h"
#include "stm32f4xx_hal.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

volatile uint32_t delay = 0;

void just_delay()
{
	ui16 i;

	for(i = 0; i < 100; ++i)
	{
		// simple delay
	}
}

#ifdef US_DELAY
void delay_us(uint32_t us)
{
	delay = us;

	HAL_TIM_Base_Start_IT(&htim4);
	
	while(delay);

	HAL_TIM_Base_Stop_IT(&htim4);
}

void HAL_TIM_PeriodElapsedCallback()
{
	if (htim->Instance == TIM4)
		--delay;
}
#endif

char *multi_tok(char *input, char *delimiter)
{
	static char *string;

	if (input != NULL)
		string = input;

	if (string == NULL)
		return string;

	char *end = strstr(string, delimiter);

	if (end == NULL)
	{
		char *temp = string;
		string = NULL;
		return temp;
	}

	char *temp = string;

	*end = '\0';
	string = end + strlen(delimiter);

	return temp;
}

// swap places of two set of bits
int swap_bits(uint8_t x, uint8_t p1, uint8_t p2, uint8_t n)
{
    /* xor contains xor of two sets */
    uint8_t xor = ((x >> p1) ^ (x >> p2)) & ((1U << n) - 1);

    /* To swap two sets, we need to again XOR the xor with original sets */
    return x ^ ((xor << p1) | (xor << p2));
}

// reverse bits completely
uint8_t reverse_bits(uint8_t num)
{
    uint8_t NO_OF_BITS = sizeof(num) * 8;
    uint8_t reverse_num = 0;

    uint8_t i;

    for (i = 0; i < NO_OF_BITS; i++)
    {
        if((num & (1 << i)))
           reverse_num |= 1 << ((NO_OF_BITS - 1) - i);
   }
    return reverse_num;
}