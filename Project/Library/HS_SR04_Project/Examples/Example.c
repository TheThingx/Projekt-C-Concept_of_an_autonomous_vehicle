#include <avr/io.h>
#include <avr/interrupt.h>
#include <uart.h>
#include "HC04.h"

char string[8]; // Pro převod čísla na řetězec

int main(void) {
    // Inicializace senzoru HC04
    HC04_Initialize();

    // Inicializace UART pro komunikaci
    uart_init(UART_BAUD_SELECT(115200, F_CPU));  // Inicializace UART na 115200 baud
    uart_puts("UART INITIALIZED\r\n");  // Oznámení o inicializaci UART
    sei();  // Povolení globálních přerušení

    while (1) {
        // Měření vzdálenosti
        float Distance = HC04_Measure_Distance();
        _delay_ms(400);  // Krátká pauza pro stabilitu

        // Převod vzdálenosti na řetězec a odeslání přes UART
        dtostrf(Distance, 4, 2, string); // Convert float to string
        uart_puts("Vzdálenost je: ");
        uart_puts(string);
        uart_puts(" mm\r\n");
    }

    return 0;
}
