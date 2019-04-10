/*	Partner 1 Name & E-mail: Chris
 *	Partner 2 Name & E-mail: X
 *	Lab Section: 027
 *	Assignment: Lab #3  Exercise #3
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
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char tempC = PORTC;
	/* Replace with your application code */
	while (1)
	{
		unsigned char tempA = PINA;
		
		if (GetBit(tempA,0) || GetBit(tempA,1))
		tempC = SetBit(tempC,5,1);
		if ( (GetBit(tempA,0) && GetBit(tempA,1)) || GetBit(tempA,2) ) {
			tempC = SetBit(tempC,5,1);
			tempC = SetBit(tempC,4,1);
		}
		if ((GetBit(tempA,2) && GetBit(tempA,0)) || (GetBit(tempA,2) && GetBit(tempA,1))) {
			tempC = SetBit(tempC,5,1);
			tempC = SetBit(tempC,4,1);
			tempC = SetBit(tempC,3,1);
		}
		if ((GetBit(tempA,2) && GetBit(tempA,1) && GetBit(tempA,0)) || (GetBit(tempA,3)) || (GetBit(tempA,3) && GetBit(tempA,0))) {
			tempC = SetBit(tempC,5,1);
			tempC = SetBit(tempC,4,1);
			tempC = SetBit(tempC,3,1);
			tempC = SetBit(tempC,2,1);
		}
		if ((GetBit(tempA,3) && GetBit(tempA,1)) || (GetBit(tempA,3) && GetBit(tempA,1) && GetBit(tempA,0)) || (GetBit(tempA,3) && GetBit(tempA,2)) ) {
			tempC = SetBit(tempC,5,1);
			tempC = SetBit(tempC,4,1);
			tempC = SetBit(tempC,3,1);
			tempC = SetBit(tempC,2,1);
			tempC = SetBit(tempC,1,1);
		}
		if ((GetBit(tempA,3) && GetBit(tempA,2) && GetBit(tempA,0)) || (GetBit(tempA,3) && GetBit(tempA,2) && GetBit(tempA,1)) || (GetBit(tempA,3) &&
			 GetBit(tempA,2) && GetBit(tempA,1) && GetBit(tempA,0))) {
			tempC = SetBit(tempC,5,1);
			tempC = SetBit(tempC,4,1);
			tempC = SetBit(tempC,3,1);
			tempC = SetBit(tempC,2,1);
			tempC = SetBit(tempC,1,1);
			tempC = SetBit(tempC,0,1);
		}
		if ((tempA & 0x0F) <= 0x04) {
			tempC = SetBit(tempC,6,1);
		}
		
		if (GetBit(tempA, 4) && GetBit(tempA,5) && !GetBit(tempA,6)) {
			tempC = SetBit(tempC,7,1);
		}
		PORTC = tempC;
		tempC = 0x00;
		

	}

}



