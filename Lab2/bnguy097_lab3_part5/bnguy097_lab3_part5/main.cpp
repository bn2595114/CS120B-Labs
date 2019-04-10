/*	Partner 1 Name & E-mail: Chris
 *	Partner 2 Name & E-mail: X
 *	Lab Section: 027
 *	Assignment: Lab #3  Exercise #5
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
    DDRB = 0xFE; PORTB = 0x00;
	DDRD = 0x00; PORTD = 0xFF;
	
	
    while (1) 
    {
		unsigned char tempB = PINB & 0x01;
		unsigned char tempD = PIND;
		unsigned short weight = 2*tempD + tempB;
		
		if (weight >= 0x46)
			tempB = SetBit(tempB,1,1);
		else if( (weight > 0x05) && (weight < 0x46) )
			tempB = SetBit(tempB,2,1);
		else
			{
				tempB = SetBit(tempB,2,0);
				tempB = SetBit(tempB,1,0);
			}
			
		PORTB = tempB;
		tempB = 0x00;
		
    }
}

