#define RedPin 11
#define GreenPin 10
#define BluePin 9
#define KeyboardPin A1
#define step 20

int RedBrightness, GreenBrightness, BlueBrightness, value;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  //Считывание значений
  value = analogRead(KeyboardPin);
  
  //Считывание значений с A1 для настройки граничных условий
  //Serial.println(analogRead(KeyboardPin));
  
  //Сравнивание значений
  if (value > 161 && value < 181)
  {RedBrightness += step;}
  else if (value > 195 && value < 215)
  {RedBrightness -= step;}
  if (value > 246 && value < 266)
  {GreenBrightness += step;}
  else if (value > 331 && value < 351)
  {GreenBrightness -= step;}
  if (value > 501 && value < 521)
  {BlueBrightness += step;}
  else if (value > 1013 && value < 1024)
  {BlueBrightness -= step;}
  
  //Настройка ограничений
  RedBrightness = constrain(RedBrightness, 0, 254);
  GreenBrightness = constrain(GreenBrightness, 0, 254);
  BlueBrightness = constrain(BlueBrightness, 0, 254);
  
  //Отправка ШИМ сигнала на пины светодиода
  analogWrite(RedPin, RedBrightness);
  analogWrite(GreenPin, GreenBrightness);
  analogWrite(BluePin, BlueBrightness);
  
  //Вывод значений яркости в монитор порта
  Serial.println("R: " + String(RedBrightness) + 
                 " | G: " + String(GreenBrightness) +
                 " | B: " + String(BlueBrightness));
  
  delay(100);
}