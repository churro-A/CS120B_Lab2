/*	Author: aalva058
 *  Partner(s) Name: Eduardo Rocha
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
        DDRA = 0x00; PORTA = 0xFF;
        DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF;		 // Configure port A's 8 pins as inputs
     	DDRD = 0xFF; PORTD = 0x00; // Configure port B's 8 pins as outputs
	
     unsigned short weight = 0x00; // Temporary variable to hold the value of B
//     unsigned short shift = 0x00;  // Temporary variable to hold the value of A

	
    /* Insert your solution below */
    	
	while (1) {
	
		weight = PINA + PINB + PINC;
		
	
		if(weight > 0x90){
			if(PINA >= PINC ){
				 
				if((PINA - PINC) > 0x50 ){
				
					PORTD = 0x03;
				
				}
				else{
					PORTD = 0x01;
				}
			}
			if(PINC >= PINA){
				if ((PINC - PINA ) > 0x50){

					PORTD = 0x03;

				}
				else{
					PORTD = 0x01;

				}
			}
		}
		else if (weight <= 0x90){
			 if(PINA >= PINC ){

                                if((PINA - PINC) > 0x50 ){

                                        PORTD = 0x03;

                                }
                                else{
                                        PORTD = 0x01;
                                }
                        }
                        if(PINC >= PINA){
                                if ((PINC - PINA ) > 0x50){

                                        PORTD = 0x03;

                                }
                                else{
                                        PORTD = 0x01;

                                }
                        }
	

		}
		else{
			PORTD = 0x00;
		}		
	
	}
    
	return 0;
}

