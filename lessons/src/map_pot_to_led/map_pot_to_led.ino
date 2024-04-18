void setup(){
    // Digital PINs 0 to 7 are used for the LEDs
    for (int i = 0; i < 8; i++) {
        pinMode(i, OUTPUT);
    }
    // Analog PIN A0 is used for the potentiometer
    pinMode(A0, INPUT);
}

void loop(){
    // read analog value from potentiometer
    int value = analogRead(A0);
    // map the 10 Bit value to 8 Bit value
    int ledValue = map(value, 0, 1023, 0, 255);
    // display the 8 Bit value on the LEDs
    for (int i = 0; i < 8; i++) {
        digitalWrite(i, bitRead(ledValue, i));
    }
}