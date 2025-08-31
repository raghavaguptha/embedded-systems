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

void loop()
{
  Serial.println("Enter your messgae");
  if (Serial.available() > 0)
  {
    String mydata = Serial.readString();
    Serial.println("Enter Row number");
    while(!Serial.available());
    Serial.println("Received");
    int row = Serial.parseInt();
    if(row == 0)
    {
    lcd.setCursor(0,row);
    lcd.print("                     ");
    lcd.setCursor(15,row);
    lcd.print(mydata);
    }
    if(row == 1)
    {
      lcd.setCursor(0,row);
    lcd.print("                     ");
    lcd.setCursor(15,row);
    lcd.print(mydata);
    }
    
  }
  lcd.scrollDisplayLeft();
  delay(200);
}
