#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);

#define temp A0
#define ldr A1

void setup() 
{
lcd.begin(16,2); 
pinMode(temp,INPUT);
pinMode(ldr,INPUT);
}

void loop() 
{
  int temp_data = analogRead(temp);
  int ldr_data = analogRead(ldr);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("T:"+String(temp_data));

  lcd.setCursor(8,0);
  lcd.print("LDR:"+String(ldr_data));
  delay(200);
}
