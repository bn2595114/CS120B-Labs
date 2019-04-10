/*	Partner 1 Name & E-mail: Chris
 *	Partner 2 Name & E-mail: X
 *	Lab Section: 027
 *	Assignment: Lab #3  Exercise #4
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>

// Bit-access function
unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
	return (b ? x | (0x01 << k) : x & ~(0x01 << k));
}
unsigned char GetBit(unsigned char x, unsigned char k) {
	return ((x & (0x01 << k)) != 0);
}


int main(void)
{
    DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	
	unsigned char i;
	unsigned char tempA = PINA;
	unsigned char tempB = PORTB;
	unsigned char tempC = PORTC;
    while (1) 
    {
		tempA = PINA;
		PORTB = PORTB;
		PORTC = PORTC;
		
		for (i=0; i<8; i++) {
			if (i<=3) {
				tempB = SetBit(tempB,i,GetBit(tempA,i));
			}
			else
				tempC = SetBit(tempC,i,GetBit(tempA,i));
		}
	PORTB = tempB;
	PORTC = tempC;
	
	tempB = 0x00;
	tempC = 0x00;
	}
}

