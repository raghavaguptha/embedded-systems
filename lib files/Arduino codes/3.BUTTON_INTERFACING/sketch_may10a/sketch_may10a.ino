#define inc_button 8
#define dec_button 9
int count = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(inc_button, INPUT_PULLUP);
  pinMode(dec_button, INPUT_PULLUP);
}
void loop()
{
  if (digitalRead(inc_button) == 0)
  {
    while((digitalRead(inc_button) == 0));
    count++;
    Serial.println("Total_count:"+String(count));
  }
  if (digitalRead(dec_button) == 0)
  {
    while(digitalRead(dec_button) == 0);
    count--;
    Serial.println("Total_count:"+String(count));
  }
  
}
