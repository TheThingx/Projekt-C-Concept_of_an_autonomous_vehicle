#ifndef HC04_H
#define HC04_H

#include <avr/io.h>
#include <avr/interrupt.h>
#include "gpio.h"
#include "timer.h"
#include <util/delay.h>
#include <uart.h>

// Pin definition
#define TRIGER 5
#define ECHO 4

#define Read_ECHO GPIO_read(&PINB, ECHO)

// Sensor inicialization
void HC04_Initialize(void);

// Distance measuring function
float HC04_Measure_Distance(void);

#endif // HC04_H
