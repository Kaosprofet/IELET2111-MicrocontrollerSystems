
#include "adc.h"
#include <avr/io.h>

int adc_read(void) {
  ADCSRA |= (1<<ADSC);
  do {} while (ADCSRA & (1<<ADSC));
  return ADC;
}

void adc_init(int pin) {
  ADMUX = (1<<REFS0);
  DIDR0 |= (1<<ADC0D);
  ADCSRA = (1<<ADEN);

  DDRD = 0x00;
  DDRC = 0x00;
  PORTC |= (1<<pin);
  ACSR = (1<<ACBG);
}
