#ifndef HC04_H
#define HC04_H

#include <avr/io.h>
#include <avr/interrupt.h>
#include "gpio.h"
#include "timer.h"
#include <util/delay.h>
#include <uart.h>

// Definice pinů
#define TRIGER 5
#define ECHO 4

#define Read_ECHO GPIO_read(&PINB, ECHO)

// Funkce pro inicializaci senzoru
void HC04_Initialize(void);

// Funkce pro měření vzdálenosti
float HC04_Measure_Distance(void);

// Pomocná funkce pro resetování časovače
void HC04_Reset_Timer(void);

#endif // HC04_H
