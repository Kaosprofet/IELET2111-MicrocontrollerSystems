/*
 * AVRSensor3000.c
 *
 * Created: 23/04/2021 21:37:14
 * Author : Henrik M. Arnesen, Simen Eine, Simen Dager Sneve
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "adc.h"
#include "servo.h"
#include "int.h"
#include "usart.h"

uint16_t temp = 0;
uint16_t light = 0;

int main(void) {
    timer1PWMInit();
	adc_init();
	initUSART();
	runServo(0);
	_delay_ms(1000);
	initInterupt();
    while (1) {
		//calServo(); // Calibrate the servo to find min/max values
		
		temp = temp_adc_read();
		light = light_adc_read();
		runServo(temp);
		_delay_ms(1000);
	
		
		
    }
}

ISR(INT0_vect) {
	printString("Temp value:" );
	printWord(temp);
	crnl();
	printString("Light value:" );
	printWord(light);
	crnl();
}

ISR(INT1_vect) { // For senere bruk
	
}
