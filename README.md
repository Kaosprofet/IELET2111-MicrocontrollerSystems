# Repository for prosjekt i faget IELEG2111 - Mikrokontrollersystemer

> **AVRSensor3000** er en sensornode bygd på en Atmega328p, laget for å følge med på lys og temperatur i [Elektra Verksted](https://www.facebook.com/ElektraVerksted).
Sensornoden består av en lyssensor, en temperatursensor og en magnetsensor (for å følge med når døren åpnes og lukkes)

### Bruk:
Bruk koden sammen med *Microchip Studio* og last opp til din Atmega328p.
VKoble til mikrokontrolleren så skal temperatur og lyssensorverdier sendes via USART.

### Kode:
Koden i main.c kan endres, men største delen av koden ligger i de forskjellige \*.h filene.

### Kobling:

| Port | Sensor |
| --- | --- |
| ADC0 | Temperatursensor |
| ADC1 | Lyssensor |
| PORTD2 | Magnetsensor |
| PORTB1 | Servo |
