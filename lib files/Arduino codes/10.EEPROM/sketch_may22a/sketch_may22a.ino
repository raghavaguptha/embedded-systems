#include<EEPROM.h>
void setup()
{
  Serial.begin(9600);
  for (int i = 0; i <= 10; i++)
  {
    EEPROM.write(i, i+1000); delay(10);
  }
}
int j=0;
void loop() 
{
Serial.println(EEPROM.read(j)); delay(1000);
j++;
if(j==11)
  j=0;
}
