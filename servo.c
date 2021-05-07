
#ifndef F_CPU
#define F_CPU  16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>
#include "servo.h"

void timer1PWMInit(void) {
	DDRB = (1<<SERVO_PIN);										// Setting PB1 as output
	TCCR1A = (1<<COM1A1)|(0<<COM1A0)|(1<<WGM11)|(0<<WGM10);		// Setting fast PWM and non-inverting mode
	TCCR1B = (1<<CS11)|(1<<WGM13)|(1<<WGM12);					// Fast PWM and set prescaling
	ICR1 = SERVO_PERIOD;
}

void calServo(void) {
	OCR1A = SERVO_MIN;
	_delay_ms(1000);
	OCR1A = SERVO_MAX;
	_delay_ms(1000);
}

void runServo(uint16_t temp) {
	temp = 1023-temp;
	temp = (temp - ADC_MIN) * (SERVO_MAX - SERVO_MIN) / (ADC_MAX - ADC_MIN) + SERVO_MIN;	// Mapping value for servo
	OCR1A = temp;
}
