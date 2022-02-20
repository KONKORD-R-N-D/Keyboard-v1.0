#define ButtonPin 2
#define LedPin 12

void setup()
{
  pinMode(LedPin, OUTPUT);
  pinMode(ButtonPin, INPUT);
}

void loop()
{
  if (digitalRead(ButtonPin) == HIGH)
  {
    digitalWrite(LedPin, HIGH);
  }
  else
  {
    digitalWrite(LedPin, LOW);
  }
  delay(100);
}