/*	Partner 1 Name & E-mail: Chris
 *	Partner 2 Name & E-mail: X
 *	Lab Section: 027
 *	Assignment: Lab #4  Exercise #4
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>


enum States {Start, Init, Wait, PressY, PressH, WaitY, Unlock, Lock, WaitH} state;

unsigned char tempA = PINA;
unsigned char lock = 1;
void tick() {
	
	tempA = PINA;
	
	switch (state) { //transitions
		
		case Start: 
			state = Init;
			break;
		
		case Init:
			state = Wait;
			break;
			
		case Wait:
			if (tempA & 0x04)
				state = PressH;
			else
				state = Wait;
			break;
			
		case PressH:
			(tempA == 0x04) ? (state = PressH) : (state = WaitH);
			break;
			
		case  WaitH:
			if (!(tempA == 0x00))
				state = WaitH;
			else
				state = WaitY;
			break;
				
		case WaitY:
			if (tempA == 0x00)
				state = WaitY;
			else if (tempA == 0x02)
				state = Unlock;
			else
				state = Start;
			break;
			
		case Unlock:
			
		default:
			state = Start;
			break;
		
	}
	
	//Start, Init, Wait, PressX, PressY, PressH, WaitH, WaitY, Unlock, Lock
	switch (state) {
		
		case Start:
			break;
			
		case Init:
			break;
			
		case Wait:
			if (tempA == 0x80){
				lock = 1;
				PORTB = 0x00;
			}
		
			break;
			
		case WaitH:
			break;	
		
		case PressH:
			break;
			
		case PressY:
			break;
			
		case WaitY:
			break;
			
		case Unlock:
			if (lock == 1) {
				PORTB = 0x01;
				lock = 0;
			}
			else if (lock == 0) {
				PORTB = 0x00;
				lock = 1;
			}
			break;
			
		default: 
			break;
	}
	
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

