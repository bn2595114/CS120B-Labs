/*
 * bnguy097_lab2_part2.cpp
 *
 * Created: 4/4/2019 4:27:00 PM
 * Author : Bryan
 */ 

#include <avr/io.h>


int main(void)
{
	DDRA = 0x00; PORTA = 0x00;
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char cntavail = 0x00;

	while (1)
	{

		if (PINA == 0x01 || PINA == 0x02 || PINA == 0x04 || PINA == 0x08) {
			cntavail = 3;
		}
		else if(PINA == 0x03 || PINA == 0x05 || PINA == 0x06 || PINA == 0x09 || PINA == 0x0A || PINA == 0x0C) {
			cntavail = 2;
		}
		else if(PINA == 0x07 || PINA == 0x0B || PINA == 0x0D || PINA == 0x0E){
			cntavail = 1;
		}
		else if(PINA == 0x0F){
			cntavail = 0;
		}
		else{
			cntavail = 4;
		}
		PORTC = cntavail;

	}
}

