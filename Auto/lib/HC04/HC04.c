#include "HC04.h"

// Funkce pro inicializaci senzoru
void HC04_Initialize(void) {
    GPIO_mode_output(&DDRB, TRIGER); // Nastav TRIGER pin jako výstup
    GPIO_write_low(&PORTB, TRIGER);  // Nastav TRIGER na LOW

    // Nastav časovač na požadovanou hodnotu
    TIM0_ovf_4ms(); // Timer 62,5KHz 4us ±4mm max_1ms
    TIM0_ovf_disable();
}

// Funkce pro měření vzdálenosti
float HC04_Measure_Distance(void) {
    HC04_Reset_Timer(); // Resetuj časovač

    // Generování 10us pulsu na TRIGER
    GPIO_write_high(&PORTB, TRIGER); // Nastav TRIGER na HIGH
    while (TCNT0 < 3) {};  // Počkej, až uplyne 10us
    GPIO_write_low(&PORTB, TRIGER); // Nastav TRIGER na LOW

    // Počkat, až se ECHO pin stane HIGH
    while (Read_ECHO == 0) {
        if (TCNT0 >= 230) { // Timeout při čekání na ECHO
            return 0;
        }
    }

    HC04_Reset_Timer(); // Resetuj časovač

    // Počkat, až ECHO pin opět přejde do LOW
    while (Read_ECHO == 1) {
        if (TCNT0 >= 230) { // Timeout při čekání na ECHO
            return 0;
        }
    }

    // Získání hodnoty časovače a výpočet vzdálenosti
    uint8_t time_elapsed = TCNT0;  // Čas, který uplynul během měření
    float distance = (27.44 * time_elapsed) / 10; // Vzdálenost v mm

    return distance;
}

// Pomocná funkce pro resetování časovače
void HC04_Reset_Timer(void) {
    TCNT0 = 0; // Resetování časovače 1
}
