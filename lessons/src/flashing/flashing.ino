#include <avr/io2313.h>
void setup() {
    DDRD = 0xFF;
}

void loop() {
    PORTD = 0xFF;
  	delay(200);
  	PORTD = 0x00;
    delay(200);
}