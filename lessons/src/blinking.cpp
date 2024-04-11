// C++ code
//
void setup() // wird nur einmal ausgeführt
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() // wird kontinuierlich ausgeführt
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}