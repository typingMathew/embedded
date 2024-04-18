#define LED_GREEN 3
#define LED_YELLOW 4
#define LED_RED 5
#define ANALOG_INPUT A0

void setup(){
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_YELLOW, OUTPUT);
    pinMode(LED_RED, OUTPUT);
    pinMode(ANALOG_INPUT, INPUT);
}

void loop(){
    int value = analogRead(ANALOG_INPUT); // returns a number between 0 to 1023
    if(value < 341){
        digitalWrite(LED_GREEN, HIGH);
        digitalWrite(LED_YELLOW, LOW);
        digitalWrite(LED_RED, LOW);
    }else if(value < 682){
        digitalWrite(LED_GREEN, LOW);
        digitalWrite(LED_YELLOW, HIGH);
        digitalWrite(LED_RED, LOW);
    }else{
        digitalWrite(LED_GREEN, LOW);
        digitalWrite(LED_YELLOW, LOW);
        digitalWrite(LED_RED, HIGH);
    }
    delay(100);
}