void setup(){
    // set all pins of PORTD as output
    DDRD = 0xFF;
    // Analog PIN A0 is used for the potentiometer
    pinMode(A0, INPUT);

    // Dies ist auch direkt über das DDRC Register möglich:
    // DDRC = 0x00;
}

void loop(){
    // read analog value from potentiometer
    int value = analogRead(A0);
    // map the 10 Bit value to 8 Bit value
    int ledValue = map(value, 0, 1023, 0, 255);
    // display the 8 Bit value on the LEDs
    PORTD = ledValue;

    // Diese drei Befehle lassen sich auch zusammenfassen:
    // PORTD = map(analogRead(A0), 0, 1023, 0, 255);
}