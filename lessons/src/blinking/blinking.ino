
void setup() // wird nur einmal ausgeführt
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() // wird kontinuierlich ausgeführt
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
