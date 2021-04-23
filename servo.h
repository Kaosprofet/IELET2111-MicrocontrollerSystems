/*
 * servo.h
 *
 * Created: 23/04/2021 21:46:43
 *  Author: Henrik M. Arnesen
 */ 

#ifndef SERVO_H
#define SERVO_H

#ifndef F_CPU											// Ff not defined in main
#define F_CPU  16000000UL								// Set a safe default baud rate


#define T1_Prescale 8

#define SERVO_PERIOD F_CPU/1000000*20000/T1_Prescale	// Calculates servo period in number of clock cycles
#define SERVO_MAX F_CPU/1000000*2100/T1_Prescale		// Servo max value
#define SERVO_MIN F_CPU/1000000*480/T1_Prescale			// Servo min value


void timer1PWMInit(void);
void calServo(void);
void runServo(void);

#endif



#endif /* SERVO_H_ */