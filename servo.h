/*
 * servo.h
 *
 * Created: 23/04/2021 21:46:43
 *  Author: Henrik M. Arnesen
 */ 

#ifndef SERVO_H
#define SERVO_H

#ifndef F_CPU											// if not defined in main
#define F_CPU  16000000UL								// set a safe default baud rate


#define T1_Prescale 8

#define SERVO_PERIOD F_CPU/1000000*20000/T1_Prescale	// Beregner periode i antall klokkesykluser
#define SERVO_MAX F_CPU/1000000*2100/T1_Prescale		// Teoretisk maks, må kanskje justeres
#define SERVO_MIN F_CPU/1000000*480/T1_Prescale			// Teoretisk min, må kanskje justeres


void timer1PWMInit(void);
void calServo(void);
void runServo(void);

#endif



#endif /* SERVO_H_ */