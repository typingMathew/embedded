
void setup() // wird nur einmal ausgeführt
{
  pinMode(PIN0, OUTPUT);
  pinMode(PIN1, OUTPUT);
  pinMode(PIN2, OUTPUT);
  pinMode(PIN3, OUTPUT);
  pinMode(PIN4, OUTPUT);
  pinMode(PIN5, OUTPUT);
  pinMode(PIN6, OUTPUT);
  pinMode(PIN7, OUTPUT);
}

void loop() // wird kontinuierlich ausgeführt
{
  digitalWrite(PIN6, LOW);
  digitalWrite(PIN0, HIGH);
  delay(1000);
  digitalWrite(PIN7, LOW);
  digitalWrite(PIN1, HIGH);
  delay(1000); 
  digitalWrite(PIN0, LOW);
  digitalWrite(PIN2, HIGH);
  delay(1000); 
  digitalWrite(PIN1, LOW);
  digitalWrite(PIN3, HIGH);
  delay(1000); 
  digitalWrite(PIN2, LOW);
  digitalWrite(PIN4, HIGH);
  delay(1000); 
  digitalWrite(PIN3, LOW);
  digitalWrite(PIN5, HIGH);
  delay(1000); 
  digitalWrite(PIN4, LOW);
  digitalWrite(PIN6, HIGH);
  delay(1000); 
  digitalWrite(PIN5, LOW);
  digitalWrite(PIN7, HIGH);
  delay(1000); 
  
}