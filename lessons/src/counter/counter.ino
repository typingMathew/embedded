// Binary Counter using LEDs

// Pin numbers for the LEDs
const int ledPins[] = {0, 1, 2, 3, 4, 5, 6, 7};
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);

// Counter variable
int counter = 0;

void setup() {
    // Set the LED pins as OUTPUT
    for (int i = 0; i < numLeds; i++) {
        pinMode(ledPins[i], OUTPUT);
    }
}

void loop() {
    // Convert the counter value to binary and display it on the LEDs
    for (int i = 0; i < numLeds; i++) {
        digitalWrite(ledPins[i], bitRead(counter, i));
    }

    // Increment the counter
    counter++;

    // Delay between each count (adjust as needed)
    delay(200);
}