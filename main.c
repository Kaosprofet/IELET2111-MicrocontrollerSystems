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
#include "servo.h"

int main(void) {
    timer1PWMInit();
    while (1) {
		calServo(); // Calibrate the servo to find min/max values
    }
}

