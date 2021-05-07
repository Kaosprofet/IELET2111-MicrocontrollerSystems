#include <avr/io.h>
#include "adc.h"


uint16_t temp_adc_read(void) {
  ADMUX = (ADMUX & 0xF0) | (0 & 0x0F);;
  ADCSRA |= (1<<ADSC);
  do {} while (ADCSRA & (1<<ADSC));
  uint8_t vall = ADCL;
  uint8_t valh = ADCH;
  uint16_t val = (valh<<8) | (vall);
  return val;
}

void adc_init(void) {
  ADMUX = (1<<REFS0)|(0<<ADLAR);
  DIDR0 |= (1<<ADC0D);
  ADCSRA = (1<<ADEN) | (1<<ADPS0) | (1<<ADPS1) ;

  DDRD = 0x00;
  DDRC = 0x00;
  PORTC |= (1<<0)|(1<<1);
  ACSR = (1<<ACBG);
}

uint16_t light_adc_read(void) {
  ADMUX = (ADMUX & 0xF0)|(1 & 0x0F);
  ADCSRA |= (1<<ADSC);
  do {} while (ADCSRA & (1<<ADSC));
  uint8_t vall = ADCL;
  uint8_t valh = ADCH;
  uint16_t val = (valh<<8) | (vall);
  return val;
}
