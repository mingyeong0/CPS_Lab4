// EX 4_1_B - Replace a 5V fan

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

// UNO R3: D9 = PB1
int main(void){
    DDRB  |= (1 << PB1);  
    PORTB &= ~(1 << PB1); 

    while (1){
        PORTB |=  (1 << PB1);  // Fan ON
        _delay_ms(3000);       
        PORTB &= ~(1 << PB1);  // Fan OFF
        _delay_ms(1000);       
    }
}

