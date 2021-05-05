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
#define SERVO_MAX F_CPU/1000000*2500/T1_Prescale		// Servo max value
#define SERVO_MIN F_CPU/1000000*600/T1_Prescale			// Servo min value
#define ADC_MAX 1023									// ADC max value
#define ADC_MIN 0										// ADC min value
#define SERVO_PIN DDB1									// Servo pin B1 (pin 9)

uint16_t temp = 0;

void timer1PWMInit(void);
void calServo(void);
void runServo(uint16_t temp);

int main(void) {
    timer1PWMInit();
    while (1) {
		//calServo(); // Calibrate the servo to find min/max values
		
		temp = 1023; // Bytt ut med ACD lesing
		runServo(temp);
    }
}

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
	temp = 1023-temp;																// Compensating for physical dial
	temp = (temp - 0) * (SERVO_MAX - SERVO_MIN) / (ADC_MAX - ADC_MIN) + SERVO_MIN;	// Mapping value for servo
	OCR1A = temp;																	// Writing to servo
}