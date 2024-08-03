// Autor: Matteo Orschewsky

// D0 --> Taster Tor hoch
const int TASTER_TOR_HOCH = PIN0;
// D1 --> Taster Tor runter
const int TASTER_TOR_RUNTER = PIN1;
// D2 --> Endschalter oben
const int ENDSCHALTER_OBEN = PIN2;
// D3 --> Endschalter unten
const int ENDSCHALTER_UNTEN = PIN3;
// D4 --> Ampel LED grün
const int AMPEL_LED_GRUEN = PIN4;
// D5 --> Ampel LED gelb
const int AMPEL_LED_GELB = PIN5;
// D6 --> Ampel LED rot
const int AMPEL_LED_ROT = PIN6;
// D7 --> Taster Notaus
const int TASTER_NOTAUS = PIN7;

// D8 - D11 --> 7-Segment-Decodierer der Einerstelle
// D12 - D13 --> 7-Segment-Decodierer der Zehnerstelle

// A0 für die H-Brücke Motor Tor hoch
const int MOTOR_TOR_HOCH = A0;
// A1 für die H-Brücke Motor Tor runter
const int MOTOR_TOR_RUNTER = A1;

volatile int timer_counter = 10;

void setup(){
    // setzen der 7-Segment-Dekodierer als Ausgänge
    DDRB = 0b00111111;
    // setzen der H-Brückensteuerung als Ausgänge
    DDRC = 0b00000011;
    // setzen der Taster, Endschalter und des Notaus als Eingänge und LEDs als Ausgänge
    DDRD = 0b01110000;
    // setzen der Pull-Up Widerstände für die Taster und Schalter
    PORTD = 0b10001111;

    // Timerkonfiguration für den 10s Timer
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
}

void loop(){

    // lesen Endschalter unten (ist Schranke unten?)
    if(digitalRead(ENDSCHALTER_UNTEN) == LOW){
        position_unten();
    }
    else{
        position_oben();
    }
}

void ten_second_timer(){
    // setzen des Timercounters auf 0
    timer_counter = 0;
    // aktivieren des Timers
    TCCR1B |= (1 << CS00);

    int counter = 10;
    while (counter > 0)
    {
        if (timer_counter >= 1000) {
            int segment;
            if (counter == 10) {
                // setzen der 7-Segment-Anzeige auf 10
                segment = 0b00010000;
                PORTB = segment;
                counter--;
            }
            else {
                segment = counter;
                PORTB = segment;
                counter--;
            }
            timer_counter = 0;
        }
        else{
            delay(100);
        }
    }
    // deaktivieren 7-Segment-Anzeige
    PORTB = 0;
    // deaktivieren des Timers
    TCCR1B &= !(1 << CS00);
            
}

void position_unten(){
    // Warten bis Taster Tor hoch gedrückt wird
    while (digitalRead(TASTER_TOR_HOCH) == HIGH) {
        delay(20);
    }
    // Motor Tor hoch fahren
    digitalWrite(MOTOR_TOR_HOCH, HIGH);
    // Warten bis Endschalter oben erreicht wird
    while (digitalRead(ENDSCHALTER_OBEN) == HIGH) {
        delay(20);
    }
    // Motor Tor stoppen
    digitalWrite(MOTOR_TOR_HOCH, LOW);
    position_oben();
}

void position_oben(){
    // Starten des 10s Timers
    ten_second_timer();
    // Motor Tor runter fahren
    digitalWrite(MOTOR_TOR_RUNTER, HIGH);
    // Warten bis Endschalter unten erreicht wird
    while (digitalRead(ENDSCHALTER_UNTEN) == HIGH) {
        delay(20);
    }
    // Motor Tor stoppen
    digitalWrite(MOTOR_TOR_RUNTER, LOW);
    position_unten();
}

ISR(TIMER1_COMPA_vect) {
    timer_counter++;
}