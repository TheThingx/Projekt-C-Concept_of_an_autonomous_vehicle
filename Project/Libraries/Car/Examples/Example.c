#include "car.h"

int main(void) {

    PWMInit(); // Inicializatzition for PWM

    // Car inicilalization, to wake up controler
    drive(true, 90);
    _delay_ms(100);
    drive(true, 70);


    while (1) { // driving in circles
        
    drive(true, 50); // Driving forward low speed
     // drive(driving direction (boool true - forward, false - backwards) , speed(uns_8b))
        
    steering(180); // steering fully to the right
     // steering(degrees(uns_8b) 90° to front)
     
    }

    return 0;
}