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

int temp = 0;

int main(void) {
    timer1PWMInit();
	adc_init(0);
	runServo(0);
	_delay_ms(1000);
	initInterupt();
    while (1) {
		//calServo(); // Calibrate the servo to find min/max values
		
		temp = adc_read();
		//runServo(temp);
		//_delay_ms(1000);
    }
}

ISR(INT0_vect) {
	runServo(255);
}

ISR(INT1_vect) {
	runServo(0);
}
