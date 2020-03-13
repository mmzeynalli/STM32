#ifndef DEFINES_H
#define DEFINES_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#ifdef US_DELAY
#include "tim.c"
#endif

typedef uint8_t  ui8;
typedef uint16_t ui16;
typedef uint32_t ui32;
typedef uint64_t ui64;

typedef int8_t  i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

#define delay_ms HAL_Delay

void just_delay();
int swap_bits(uint8_t x, uint8_t p1, uint8_t p2, uint8_t n);
uint8_t reverse_bits(uint8_t num);

#endif /* DEFINES_H */
