
#include "servo.h"

void timer1PWMInit(void) {
	DDRB = (1<<DDB1);											// Setter PB1 som utgang
	TCCR1A = (1<<COM1A1)|(0<<COM1A0)|(1<<WGM11)|(0<<WGM10);		// Setter fast PWM og non-inverting mode
	TCCR1B = (1<<CS11)|(1<<WGM13)|(1<<WGM12);					// Fast PWM og setter prescaling
	ICR1 = SERVO_PERIOD;
}

void calServo(void) {
	OCR1A = SERVO_MIN;
	_delay_ms(1000);
	OCR1A = SERVO_MAX;
	_delay_ms(1000);
}

void runServo(void) {
	
}