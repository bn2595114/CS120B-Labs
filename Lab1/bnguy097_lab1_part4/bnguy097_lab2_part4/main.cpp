/*
 * bnguy097_lab2_part4.cpp
 *
 * Created: 4/4/2019 9:31:08 PM
 * Author : Bryan
 */ 

#include <avr/io.h>
#include <stdlib.h>

int main(void)
{
    DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00;
	
	unsigned char totalw; // total weight
	
    while (1) 
    {
		if ((PINA + PINB + PINC) > 140) {
			PORTD = PORTD | 0x01;
		}
		if (abs(PINA - PINC) >80) {
			PORTD = PORTD | 0x02;
		}
		
		totalw = PINA + PINB + PINC;
		
		PORTD = PORTD | (totalw & 0xFC);
		
		
    }
}

