/*	Partner 1 Name & E-mail: X
 *	Partner 2 Name & E-mail: X
 *	Lab Section: 027
 *	Assignment: Lab #3  Exercise #1
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
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	
	unsigned char i;
	unsigned char count = 0;
	
	unsigned char tempA, tempB, tempC;

    /* Replace with your application code */
    while (1) 
    {
		tempA = PINA;
		tempB = PINB;
		
		for (i=0; i<8; i++) {
			if (GetBit(tempA,i))
				count++;
			if (GetBit(tempB,i))
				count++;
		}
		tempC = count;
		PORTC = tempC;
		count = 0;

	
	}
	return 0;
}