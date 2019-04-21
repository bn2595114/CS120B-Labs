/*	Partner 1 Name & E-mail: Chris
 *	Partner 2 Name & E-mail: X
 *	Lab Section: 027
 *	Assignment: Lab #5  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>

enum States {Start, Init, Wait, Increment, WaitIn, Decrement, WaitDe, Reset, WaitRe} state;

unsigned char tempA = 0x00;
unsigned char tempB = 0x00;
void tick() {
	
	tempA = ~PINA & 0x03;
		
	switch(state){ //transition
		
		case Start:
			state = Init;
			break;
			
		case Init:
			state = Wait;
			break;
			
		case Wait:
			if (tempA & 0x01)
				state = WaitIn;
			if (tempA & 0x02)
				state = WaitDe;
			break;
			
		case WaitIn:
			if (tempA & 0x01)
				state = Increment;
			if (tempA & 0x00)
				state = WaitIn;

			break;
			
		case Increment:
			if (tempA == 0x03)
				state = WaitRe;
			else if (tempA & 0x01)
				state = Increment;
			else
				state = Wait;
			
			break;
							
		case WaitDe:
			if (tempA & 0x03)
				state = WaitRe;
			if (tempA & 0x02)
			state = Decrement;
			if (tempA & 0x00)
				state = WaitDe;
			break;
		
		case Decrement:
			if (tempA == 0x03)
				state = WaitRe;
			else if (tempA & 0x02)
				state = Decrement;
			else
				state = Wait;
			break;
			
		case WaitRe:
			if (!(tempA & 0x03) )
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
			tempB = 0x00;
			break;
		case Wait:
			break;
		case WaitIn:
			if (tempB < 0x09)
				tempB = tempB + 0x01;
			break;
		case Increment:
			break;
		case WaitDe:
			if (tempB > 0x00)
				tempB = tempB - 0x01;
			break;
			
		case Decrement:
			break;
		
		case WaitRe:
			break;
			
		case Reset:
			tempB = 0x00;
			break;	
	}
	PORTB = tempB;
}

int main(void)
{
    DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	
	state = Start;
    while (1) 
    {
		tick();
    }
}

