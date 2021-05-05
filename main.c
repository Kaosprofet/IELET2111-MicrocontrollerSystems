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

#define T1_Prescale 8

#define SERVO_PERIOD F_CPU/1000000*20000/T1_Prescale	// Calculates servo period in number of clock cycles
#define SERVO_MAX F_CPU/1000000*2100/T1_Prescale		// Servo max value
#define SERVO_MIN F_CPU/1000000*480/T1_Prescale			// Servo min value


void timer1PWMInit(void);
void calServo(void);
void runServo(void);

int main(void) {
    timer1PWMInit();
    while (1) {
		calServo(); // Calibrate the servo to find min/max values
    }
}

void timer1PWMInit(void) {
	DDRB = (1<<DDB1);											// Setting PB1 as output
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

void runServo(void) {
	
}

