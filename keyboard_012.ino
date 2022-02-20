#define ButtonPinA 2
#define ButtonPinB 4
#define LedPin 11
#define step 20

int value;

void setup()
{
  Serial.begin(9600);
  pinMode(ButtonPinA, INPUT);
  pinMode(ButtonPinB, INPUT);
}

void loop()
{
  if (digitalRead(ButtonPinA) == HIGH)
  {
    value += step;
  }
  if (digitalRead(ButtonPinB) == HIGH)
  {
    value -= step;
  }
  
  value = constrain(value, 0, 254);
  analogWrite(LedPin, value);
  
  Serial.println(value);
  delay(100);
}