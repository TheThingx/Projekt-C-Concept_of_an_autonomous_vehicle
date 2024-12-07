#include "HC04.h"

#define RST_TIM0 TCNT0 = 0; // Timer0 Reset def

// Sensor Inicialization
void HC04_Initialize(void) {
    GPIO_mode_output(&DDRB, TRIGER); // TRIGGER as output   
    GPIO_write_low(&PORTB, TRIGER);  // TRIGGER set to low

    // Timer 0 Inicialization
    TIM0_ovf_4ms(); // Timer 16us ±4mm max_4ms
    TIM0_ovf_disable();
}

// Measuring distance
float HC04_Measure_Distance(void) {
    RST_TIM0; // Timer reset

    // Generation 10us pulse on TRIGER
    GPIO_write_high(&PORTB, TRIGER);
    while (TCNT0 < 3) {};
    GPIO_write_low(&PORTB, TRIGER);

    // Wait till ECHO goes high
    while (Read_ECHO == 0) {
        if (TCNT0 >= 230) { // Timeout waiting too long > 3,5ms
            return 0;
        }
    }

    RST_TIM0; // Timer reset

    // Wait till ECHO goes low
    while (Read_ECHO == 1) {
        if (TCNT0 >= 230) { // Timeout waiting too long > 3,5ms
            return 0;
        }
    }

    // Calculating distance
    uint8_t time_elapsed = TCNT0;  // Time of pulse
    float distance = (27.44 * time_elapsed) / 10; // Distance in mm

    return distance;
}
