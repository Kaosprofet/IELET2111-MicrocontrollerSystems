#include <avr/interrupt.h>
#include "int.h"

void initInterupt(void){
	PORTD = (1<<intPin1)|(1<<intPin2);	// Internal pullup 
	EIMSK = (1<<INT0)|(1<<INT1);		// Enable interupt 0
	sei();								// Enable global interupts
}