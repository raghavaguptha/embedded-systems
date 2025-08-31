#include<LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
#define pir 8

#define in1 9
#define in2 10

void setup()
{
  lcd.begin(16, 2);
  pinMode(pir, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

void loop()
{
  int pir_data = digitalRead(pir);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("PIR:" + String(pir_data)); delay(200);
  if (pir_data == HIGH)
  {
    lcd.setCursor(0, 1);
    lcd.print("Sensor detected  "); delay(200);
    open_door(2000);
    lcd.setCursor(0, 1);
    lcd.print("Door Opened      "); delay(2000);
    while(digitalRead(pir) == HIGH);

    close_door(2000);
    lcd.setCursor(0, 1);
    lcd.print("Door Closed      "); delay(2000);
  }
  if (pir_data == LOW)
  {
    lcd.setCursor(0, 1);
    lcd.print("Sensor not detect"); delay(200);
  }
}


void open_door(int Time)
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  delay(Time);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

void close_door(int Time)
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  delay(Time);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}
