/*	Partner 1 Name & E-mail: Chris
 *	Partner 2 Name & E-mail: X
 *	Lab Section: 027
 *	Assignment: Lab #4  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>

enum States {Start, Init, OnOff, Wait1, OffOn, Wait2} state;

void tick() {
	
	switch(state) { //Transitions
		case Start:
			state = Init;
			break;
			
		case Init:
			state = OnOff;
			break;
			
		case OnOff:
			if (PINA & 0x01)
				state = Wait1;
			break;
			
		case Wait1:
			if (!(PINA & 0x01)) 
				state = OffOn;
			break;	
			
		case OffOn:
			if (PINA & 0x01)
				state = Wait2;
			break;
			
		case Wait2:
			if(!(PINA & 0x01))
				state = OnOff;
			break;
			
		default:
			state = Start;
	}
	
	switch(state) { //action
		case Start:
			break;
		case Init:
			PORTB = 0x01;
			break;
			
		case OnOff:
			break;
			
		case Wait1:
			PORTB = 0x02;
			break;
			
		case OffOn:
			break;
			
		case Wait2:
			PORTB = 0x01;
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

