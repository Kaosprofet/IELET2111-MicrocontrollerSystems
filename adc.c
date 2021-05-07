
#include <avr/io.h>
#include "adc.h"


uint16_t adc_read(void) {
  ADCSRA |= (1<<ADSC);
  do {} while (ADCSRA & (1<<ADSC));
  uint8_t temp_vall = ADCL;
  uint8_t temp_valh = ADCH;
  uint16_t temp_val = (temp_valh<<8) | (temp_vall);
  return temp_val;
}

void adc_init(int pin) {
  ADMUX = (1<<REFS0)|(0<<ADLAR);
  DIDR0 |= (1<<ADC0D);
  ADCSRA = (1<<ADEN) | (1<<ADPS0) | (1<<ADPS1) ;

  DDRD = 0x00;
  DDRC = 0x00;
  PORTC |= (1<<pin);
  ACSR = (1<<ACBG);
}
