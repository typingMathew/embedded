// diese Datei ist vom Github Copilot erstellt wurden

void setup() {
    // Set the digital pins 0, 1, and 2 as output
    pinMode(0, OUTPUT);
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);
    
    // Initialize the random seed
    randomSeed(analogRead(0));
}

void loop() {
    // Generate random values for red, green, and blue
    int red = random(256);
    int green = random(256);
    int blue = random(256);
    
    // Set the RGB LED to the new color
    analogWrite(0, red);
    analogWrite(1, green);
    analogWrite(2, blue);
    
    // Delay for .5 seconds
    delay(500);
}