/*
 * print.h
 *
 *  Created on: Oct 7, 2019
 *      Author: Miradil Zeynalli
 */

#ifndef PRINT_H
#define PRINT_H

#include <stdint.h>

#define UART1
#define UART2
#define UART3
//#define UART4

#ifdef UART1
uint8_t printf1(const char *fmt, ...);
#endif

#ifdef UART2
uint8_t printf2(const char *fmt, ...);
#endif

#ifdef UART3
uint8_t printf3(const char *fmt, ...);
#endif

#ifdef UART4
uint8_t printf4(const char *fmt, ...);
#endif

#endif /* PRINT_H */
