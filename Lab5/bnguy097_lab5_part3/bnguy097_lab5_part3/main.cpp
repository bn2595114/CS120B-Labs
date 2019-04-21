/*	Partner 1 Name & E-mail: Chris
 *	Partner 2 Name & E-mail: X
 *	Lab Section: 027
 *	Assignment: Lab #5  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>

enum States {init, oddIn, evenIn, waitE, waitED, waitO, waitOD} state;

unsigned char tempB = 0x00;

void tick() {

	unsigned char press = ~PINA & 0x01;
	
	switch (state) {
		case init:
			tempB = 0x01;
			state = waitO;
			break;
		case oddIn:
			state = waitOD;
			break;
		case waitO:
			if (press)
				state = oddIn;
			else if (tempB & 0x40)
			{
				state = waitE;
				tempB = 0x02;
			}
			else
				state = waitO;
			break;		
		case waitOD:
			if(press)
				state = waitOD;
			else
				state = waitO;
			break;
		case evenIn:
			state = waitED;
			break;
			
		case waitE:
			if (press)
				state = evenIn;
			else if (tempB & 0x20)
			{
				state = waitO;
				tempB = 0x01;
			}
			else
				state = waitE;
			break;
			
		case waitED:
		if(press)
			state = waitED;
		else
			state = waitE;
		break;
			
		default:
			state = init;
			break;
	}

	//init, oddIn, evenIn, oddD, evenD
	
	switch (state) {
		case init:
			break;
		case oddIn:
			if(tempB & 0x20 )
				tempB = 0x01;
			else
				tempB = (tempB << 2);
			break;
		case evenIn:
			if((tempB & 0x10) )
				tempB = 0x02;
			else
				tempB = (tempB << 2);
			break;
		case waitE:
			break;
		case waitO:
			break;
		case waitOD:
			break;
			
	}
	PORTB = tempB;
}

int main(void)
{
    DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
    while (1) 
    {
		tick();
    }
}

