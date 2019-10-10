/*
 * print.c
 *
 *  Created on: Oct 7, 2019
 *      Author: Miradil Zeynalli
 */

#include "print.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "usart.h"
#include "stm32f1xx_hal.h"

static uint8_t vprint(UART_HandleTypeDef *huart, const char *fmt, va_list argp);

#ifdef UART1

extern UART_HandleTypeDef huart1;

uint8_t printf1(const char *fmt, ...)
{
	va_list argp;
	va_start(argp, fmt);

	uint8_t len = vprint(&huart1, fmt, argp);
	va_end(argp);

	return len;
}

#endif

#ifdef UART2

extern UART_HandleTypeDef huart2;

uint8_t printf2(const char *fmt, ...)
{
	va_list argp;
	va_start(argp, fmt);

	uint8_t len = vprint(&huart2, fmt, argp);
	va_end(argp);

	return len;
}

#endif


#ifdef UART3

extern UART_HandleTypeDef huart3;

uint8_t printf3(const char *fmt, ...)
{
	va_list argp;
	va_start(argp, fmt);

	uint8_t len = vprint(&huart3, fmt, argp);
	va_end(argp);

	return len;
}

#endif

#ifdef UART4

extern UART_HandleTypeDef huart4;

uint8_t printf4(const char *fmt, ...)
{
	va_list argp;
	va_start(argp, fmt);

	uint8_t len = vprint(&huart4, fmt, argp);
	va_end(argp);

	return len;
}

#endif

static uint8_t vprint(UART_HandleTypeDef *huart, const char *fmt, va_list argp)
{
	char str[50];

	uint8_t len = vsprintf(str, fmt, argp);

	if(0 < len) // build string
		HAL_UART_Transmit(huart, (uint8_t*) str, strlen(str), 0xFFFFFF); // send message via UART

	return len;
}
