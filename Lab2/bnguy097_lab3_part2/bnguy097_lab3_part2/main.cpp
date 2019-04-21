  #include <avr/io.h>
  
    int main(void)
    {
	    DDRA = 0x00; PORTA = 0xFF; 
	    DDRB = 0xFF; PORTB = 0x00; 
	    // initialize to 0s

	    unsigned char tmpA = 0x00; 
	    unsigned char tmpB = 0x00; 
	    while (1)
	    {
		    tmpB = 0x00;
		    tmpA = ~PINA & 0x0F;

		    if(tmpA == 1 || tmpA == 2){
			    tmpB = 0x20;
		    }

		    else if(tmpA == 3 || tmpA == 4){
			    tmpB = 0x30;
		    }

		    else if(tmpA == 5 || tmpA == 6){
			    tmpB = 0x38;
		    }

		    else if(tmpA == 7 || tmpA == 8 || tmpA == 9){
			    tmpB = 0x3C;
		    }

		    else if( tmpA == 10 || tmpA == 11 || tmpA == 12){
			    tmpB = 0x3E;
		    }

		    else if(tmpA == 13 || tmpA == 14 || tmpA == 15){
			    tmpB = 0x3F;
		    }
		    else{
			    tmpB = 0;
		    }

		    if(tmpA <= 4){
			    tmpB = tmpB | 0x40;
		    }

		    PORTB = tmpB;
	    }
    }