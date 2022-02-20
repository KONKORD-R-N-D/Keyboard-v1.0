#define KeyboardPin A1
#define LedPin 11
#define step 20

int value;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  //Вывод значений с A1 в монитор порта
  //Serial.println(analogRaed(KeyboardPin));
  
  
  if (analogRead(KeyboardPin) > 501 && analogRead(KeyboardPin) < 521)
  {
    value += step;
  } 
  else if (analogRead(KeyboardPin) > 1013 && analogRead(KeyboardPin) < 1024)
  {
    value -= step;
  }
  
  value = constrain(value, 0, 254);
  analogWrite(LedPin, value);
  
  Serial.println(value);
  delay(100);
}