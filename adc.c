
#include "adc.h"

#define SENSOR PC0

void adc_init(void);

int main(void) {
   DDRD = 0x00;
   DDRC = 0x00;
   PORTC |= (1<<SENSOR);
   ACSR = (1<<ACBG);
   adc_init();
   do {
     ADCSRA |= (1<<ADSC);
   } while(1);
}

void adc_init(void) {
  ADMUX = (1<<REFS0);
  DIDR0 |= (1<<ADC0D);
  ADCSRA = (1<<ADEN);
}
