//#define CS00 6
//#define CS01 4

void setup() {
    DDRD = B11111111;
}

void loop() {
    PORTD|=(1<<CS00); // CS00 ist ein Clock Select der den Wert 0 repräsentiert
    PORTD|=(1<<CS01); // CS01 ist ein Clock Select der den Wert 1 repräsentiert
}