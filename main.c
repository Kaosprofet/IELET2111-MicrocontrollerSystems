/*
 * AVRSensor3000.c
 *
 * Created: 23/04/2021 21:37:14
 * Author : Henrik M. Arnesen
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "adc.h"
#include "servo.h"

uint16_t temp = 0;

int main(void) {
    timer1PWMInit();
	adc_init();
    while (1) {
		//calServo(); // Calibrate the servo to find min/max values
		
		temp = 1023; // Bytt ut med ACD lesing
		runServo(temp);
    }
}