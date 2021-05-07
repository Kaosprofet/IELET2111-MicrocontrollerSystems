
#ifndef F_CPU                          
#define F_CPU  16000000UL
#endif

#define SERVO_PERIOD F_CPU/1000000*20000/T1_Prescale	// Calculates servo period in number of clock cycles
#define SERVO_MAX F_CPU/1000000*2500/T1_Prescale		// Servo max value
#define SERVO_MIN F_CPU/1000000*600/T1_Prescale			// Servo min value
#define ADC_MAX 1023									// ADC max value
#define ADC_MIN 0										// ADC min value
#define SERVO_PIN DDB1									// Servo pin B1 (pin 9)
#define T1_Prescale 8


void timer1PWMInit(void);
void calServo(void);
void runServo(uint16_t temp);