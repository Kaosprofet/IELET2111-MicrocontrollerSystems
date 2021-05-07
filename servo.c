#include <avr/io.h>
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