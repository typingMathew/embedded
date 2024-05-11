// arduino uno programm
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


void setup(){
    // setzen der 7-Segment-Dekodierer als Ausgänge
    DDRB = 0b00111111;
    // setzen der H-Brückensteuerung als Ausgänge
    DDRC = 0b00000011;
    // setzen der Taster, Endschalter und des Notaus als Eingänge und LEDs als Ausgänge
    DDRD = 0b01110000;
    // setzen der Pull-Up Widerstände für die Taster und Schalter
    PORTD = 0b10001111;
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
    // setzen der 7-Segment-Anzeige auf 10
    int segment = 0b00010000;
    PORTB = segment;
    // warten 1s
    delay(1000);
    // zyklisches herunterzählen der 7-Segment-Anzeige
    for (int i = 9; i >= 0; i--)
    {
        segment = i;
        PORTB = segment;
        delay(1000);
    }
    
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
