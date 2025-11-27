// EX 4.1_A - Bare-metal code 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void) {

    DDRB |= (1 << PB1);

    while (1) {
        PORTB |= (1 << PB1);   // Transistor ON → LED ON
        _delay_ms(3000);       // 3s on
        PORTB &= ~(1 << PB1);  //  TransistorOFF → LED OFF
        _delay_ms(1000);       // 1s off
    }
}

