/*
 * bnguy097_lab2_part1.cpp
 *
 * Created: 4/4/2019 12:46:37 PM
 * Author : Bryan
 */ 

#include <avr/io.h>


#include <avr/io.h>

int main(void)
{		
	DDRA = 0x00; PORTA = 0x00; // Configure port A's 8 pins as inputs
	DDRB = 0xF; PORTB = 0x0;   // Configure port B's 8 pins as outputs, initialize to 0s
	
	while(1) {
		if (PINA == 0x01)
			PORTB = 0x1;
		else
			PORTB = 0x0;
	}
	
	return 0;
}

