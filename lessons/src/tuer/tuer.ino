// Creator: Matteo Orschewsky
#include<Servo.h>
#include<Adafruit_NeoPixel.h>


// PIN 0 --> Taster Tür öffnen
#define TASTER_TUER_OEFFNEN 0
// PIN 1 --> Taster Tür schließen
#define TASTER_TUER_SCHLIESSEN 1
// PIN 2 --> Ultraschallsensor Echo
#define ULTRASCHALL_ECHO 2
// PIN 3 --> Ultraschallsensor Trigger
#define ULTRASCHALL_TRIGGER 3
// PIN 4 --> Servomotor
#define SERVO_MOTOR 4
// PIN 5 --> 8fach LED Streifen
#define LED_STREIFEN 5

// Erstellen eines LED Streifen Objekts
Adafruit_NeoPixel led_streifen = Adafruit_NeoPixel(8, LED_STREIFEN, NEO_GRB + NEO_KHZ800);

// Erstellen eines Servo Objekts
Servo tuer_motor;

void setup() {
    // setzten der IO Pins
    DDRD = 0b00111000;
    // setzen der Pullup Widerstände
    PORTD = 0b00000111;
    // initialisieren des Servomotors
    tuer_motor.attach(SERVO_MOTOR);
    // Initialisieren des Servomotors auf 0°(Tür zu)
    tuer_motor.write(0);
}

void loop() {
    tuer_oeffnen(0);
}

bool objekt_in_tuerbereich() {
    // Ultraschallsensor auslesen
    long distance = read_ultrasonic_distance();
    // wenn ein Objekt näher als 2m aber weiter als 20cm entfernt ist
    if (distance > 20 && distance < 200) {
        return true;
    }
    return false;
}

long read_ultrasonic_distance() {
    // Clear the trigger
    digitalWrite(ULTRASCHALL_TRIGGER, LOW);
    delay(2);
    noInterrupts();
    // Set the trigger pin to HIGH state for 10 microseconds
    digitalWrite(ULTRASCHALL_TRIGGER, HIGH);
    delay(10);
    digitalWrite(ULTRASCHALL_TRIGGER, LOW);
    // Reads the echo pin, and returns the sound wave travel time in microseconds
    long travel_time = pulseIn(ULTRASCHALL_ECHO, HIGH);
    interrupts();
    // Calculating the distance in cm (Schallgeschwindigkeit: 343 m/s = 0.0343 cm/ms --> / 2 für Hin- und Rückweg)
    return (0.01723 * travel_time);
}

void tuer_oeffnen(int current_pos) {
    // Servomotor auf 90° drehen, dabei LED Streifen proportional zur Drehung färben
    move_servo(current_pos,90);
    
    // wenn der Taster zum Schließen der Tür gedrückt wird,
    // oder sich kein Objekt mehr im Türfeld befindet, wird Tür geschlossen
    while (bit_is_set(PIND, TASTER_TUER_SCHLIESSEN) && objekt_in_tuerbereich())
    {}
    tuer_schliessen(90);
}

void tuer_schliessen(int current_pos) {
    if (current_pos >= 90) {
        aight_sec_timer();
    }

    // Servomotor auf 0° drehen, dabei LED Streifen proportional zur Drehung färben
    move_servo(current_pos,0);

    // wenn der Taster zum Öffnen der Tür gedrückt wird 
    // oder der Ultraschallsensor eine Bewegung erkennt wird Tür geöffnet
    while (not (bit_is_clear(PIND, TASTER_TUER_OEFFNEN) || objekt_in_tuerbereich()))
    {}
    tuer_oeffnen(0);
}

void move_servo(int start, int end) {
    // Initialisieren der abstrahierten Servo Position für die LED Streifen
    int led_pos = -1;
    
    for (
        int i = start;
        (start < end) ? i <= end : i >= end;
        (start < end) ? i++ : i--)
    {
        if (bit_is_clear(PIND, (start < end) ? TASTER_TUER_SCHLIESSEN : TASTER_TUER_OEFFNEN))
        {
            (start < end) ? tuer_schliessen(i) : tuer_oeffnen(i);
        }
        
        delay(50);
        tuer_motor.write(i);

        // Belichtung des Leuchtstreifens
        if (led_pos == map(i, 0, 90, 0, 7)) {
            continue;
        }
        led_pos = map(i, 0, 90, 0, 7);
        led_streifen.setPixelColor(led_pos, led_streifen.Color(0, (start < end) ? 255 : 0, 0));
        led_streifen.show();
    }
}

void aight_sec_timer(){
    for (int i = 7; i >= 0; i--)
    {
        if (bit_is_clear(PIND, TASTER_TUER_OEFFNEN))
        {
            i = 7;
        }
        

        led_streifen.setPixelColor(i, led_streifen.Color(255, 0, 0));
        led_streifen.show();
        delay(1000);

        led_streifen.setPixelColor(i, led_streifen.Color(0, 255, 0));
        led_streifen.show();
    }
    
}
