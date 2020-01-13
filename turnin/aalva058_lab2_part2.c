/*	Author: aalva058
 *  Partner(s) Name: Eduardo Rocha
 *	Lab Section:022
 *	Assignment: Lab #2  Exercise #2
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
     DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
     DDRC = 0xFF; PORTC = 0x00; // Configure port B's 8 pins as outputs
	
     unsigned char Aspace = 0x00; // Temporary variable to hold the value of B
     unsigned char tmpA = 0x00; // Temporary variable to hold the value of A

	
    /* Insert your solution below */
    	
	while (1) {
	
	tmpA = PINA & 0x0F;

	switch(tmpA){

	case 0x00:
		Aspace = 0x04;
		break;

	//4 space
	
	case 0x01:
	case 0x02:
	case 0x04:
	case 0x08:
		Aspace = 0x03;
		break;
	// 3 spaces ava
	case 0x03:
	case 0x06:
	case 0x0C:
	case 0x09:
	case 0x0A:
	case 0x05:
		Aspace = 0x02;
		break;
	// 2 space available
	//
	case 0x0E:
	case 0x0D:
	case 0x0B:
	case 0x07:
		Aspace = 0x01;
		break;
	// 1 space
	//
	case 0x0F:
		Aspace = 0x00;
		break;
	// 0 space
	
	default:
		Aspace = 0x04;
		break;
	}
	PORTC = Aspace;
	
    }
	return 0;
}
