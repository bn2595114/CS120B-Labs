/*
 * bnguy097_lab2_part1.cpp
 *
 * Created: 4/8/2019 6:08:44 PM
 * Author : Bryan
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
    /* Replace with your application code */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char count = 0;
	unsigned char i;
    while (1) 
    {
		for (i=0; i<8; i++)
		{
			
		}
		
    }
}

