#include "uart.h"
#include "car.h"
#include <oled.h>
#include "HC04.h"

#ifndef F_CPU
#define F_CPU 16000000 // CPU frequency in Hz required for UART_BAUD_SELECT
#endif

int pos = 0;
char string[10];

void line_handler()
{
  if (!left_sensor)
  {
    pos = 90;
    drive(true, 50);
    // steering(180);
    oled_gotoxy(0, 1);
    oled_puts("--->");
    uart_puts("--->");
  }

  if (!right_sensor)
  {
    pos = -90;

    // drive(true, 50);
    // steering(0);
    oled_gotoxy(0, 1);
    oled_puts("<---");
    uart_puts("<---");
  }

  if (right_sensor && left_sensor)
  {
    // drive(true, 70);
    pos = pos * 0.9;
    oled_gotoxy(0, 1);
    oled_puts(" ^^ ");
  }

  if (!right_sensor && !left_sensor)
  {
    drive(true, 0);
  }

  steering(90 + pos);
  drive(true, (80UL * abs(pos)) / 90UL);
}

void obstacle_handler()
{
  float Distance = HC04_Measure_Distance();
  dtostrf(Distance, 4, 2, string);
  oled_gotoxy(0, 2);
  oled_puts(string);

  if (Distance > 500 | Distance == 0)
  {
    steering(90);
    drive(true, 100);
  }
  else if (Distance > 300)
  {
    steering(90);
    drive(true, Distance * 120 / 500);
  }
  else
  {
    drive(false, 0);
    steering(0);
    _delay_ms(500);
    drive(false, 80);
    steering(0);
    _delay_ms(1000);
  }
}

int main(void)
{
  oled_init(OLED_DISP_ON);
  oled_clrscr();
  oled_gotoxy(0, 0);
  oled_puts("KITT V-1.0 ");
  oled_display();
  uart_init(UART_BAUD_SELECT(9600, F_CPU));
  PWMInit();
  HC04_Initialize();
  drive(true, 90);
  _delay_ms(100);
  drive(true, 70);

  while (1)
  {
    obstacle_handler();

    uart_putc((PINC & (1 << PC0)) ? 'W' : 'B');
    uart_puts(" ");
    uart_putc((PINC & (1 << PC1)) ? 'W' : 'B');
    uart_puts("\n");

    _delay_ms(50);
    oled_display();
  }
}
