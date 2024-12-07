#include <uart.h>
#include "HC04.h"

char string[8]; // For uart printing

int main(void) {

    HC04_Initialize(); // Sensor inicialization

    // Uart inicialization
    uart_init(UART_BAUD_SELECT(115200, F_CPU));
    uart_puts("UART INITIALIZED\r\n");
    sei();  // interrupt enable

    while (1) {

        float Distance = HC04_Measure_Distance(); // Distance measuring
        _delay_ms(400);  // 400ms delay

        // Distance to char and to uart
        dtostrf(Distance, 4, 2, string); // Convert float to string
        uart_puts("Distance: ");
        uart_puts(string);
        uart_puts(" mm\r\n");
    }

    return 0;
}
