#include<LiquidCrystal.h> //header file for LCD
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); //rs,en,D4,D5,D6,D7

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WELCOME");
  lcd.setCursor(0, 1);
  lcd.print("Wireless Display");
  delay(2000);
  lcd.clear();
}
int i=0;
void loop()
{
  Serial.println("Enter your messgae");
  if (Serial.available() > 0)
  {
    String mydata = Serial.readString();
    lcd.clear();
    lcd.setCursor(15,i);
    lcd.print(mydata);
    i++;
    if(i>1)
    {
      i=0;
      }
  }
  lcd.scrollDisplayLeft();
  delay(200);
}
