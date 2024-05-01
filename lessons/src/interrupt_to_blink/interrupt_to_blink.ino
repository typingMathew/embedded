// programm that blinks an LED at 1 Hz through an interrupt
volatile int timer_counter = 0;
int LED = 0;

void setup() {
    pinMode(LED, OUTPUT);

    // set the timer conf registers of TCNT1 to 0 
    TCCR1A = 0;
    TCCR1B = 0;
    // set the timer to 0
    TCNT1 = 0;
    // set the compare register (16 MHz / 16.000 tacts = 1 ms)
    OCR1A = 16000;
    // set the WGM12 setting (CTC - Clear Timer on Compare Match)
    // this resets the counter when it reaches the value of OCR1A
    TCCR1B |= (1 << WGM12);
    // configure the timer to compare mode (where it compares the value of TCNT1 with OCR1A)
    // throws an interrupt when the values are equal
    TIMSK1 |= (1 << OCIE1A);
    // start the timer with zero prescaling
    TCCR1B |= (1 << CS00);
}

void loop() {
    if (timer_counter >= 500) {
        if (digitalRead(LED) == HIGH) {
            digitalWrite(0, LOW);
        } else {
            digitalWrite(LED, HIGH);
        }
        timer_counter = 0;
    }
}

ISR(TIMER1_COMPA_vect) {
    timer_counter++;
}