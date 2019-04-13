/*	Partner 1 Name & E-mail: Chris
 *	Partner 2 Name & E-mail: X
 *	Lab Section: 027
 *	Assignment: Lab #4  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>

enum States {Start, Init, Wait, Increment, WaitIn, Decrement, WaitDe, Reset, WaitRe} state;

void tick() {
	switch(state){ //transition
		
		case Start:
			state = Init;
			break;
			
		case Init:
			state = Wait;
			break;
			
		case Wait:
			if (PINA & 0x01)
				state = WaitIn;
			if (PINA & 0x02)
				state = WaitDe;
			break;
			
		case WaitIn:
			if (PINA & 0x01)
				state = Increment;
			if (PINA & 0x00)
				state = WaitIn;

			break;
			
		case Increment:
			if (PINA == 0x03)
				state = WaitRe;
			else if (PINA & 0x01)
				state = Increment;
			else
				state = Wait;
			
			break;
							
		case WaitDe:
			if (PINA & 0x03)
				state = WaitRe;
			if (PINA & 0x02)
			state = Decrement;
			if (PINA & 0x00)
				state = WaitDe;
			break;
		
		case Decrement:
			if (PINA == 0x03)
				state = WaitRe;
			else if (PINA & 0x02)
				state = Decrement;
			else
				state = Wait;
			break;
			
		case WaitRe:
			if (!(PINA & 0x03) )
				state = Reset;
			break;
			
		case Reset:
			state = Wait;
			break;
			
		default:
			state = Start;
	}

//Start, Init, Wait, Increment, WaitIn, Decrement, WaitDe
	
	switch (state) { //action
		
		case Start:
			break;
		case Init:
			PORTC = 0x07;
			break;
		case Wait:
			break;
		case WaitIn:
			if (PORTC < 0x09)
				PORTC = PORTC + 0x01;
			break;
		case Increment:
			break;
		case WaitDe:
			if (PORTC > 0x00)
				PORTC = PORTC - 0x01;
			break;
			
		case Decrement:
			break;
		
		case WaitRe:
			break;
			
		case Reset:
			PORTC = 0x00;
			break;	
	}
}

int main(void)
{
    DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	
	state = Start;
    while (1) 
    {
		tick();
    }
}

