#include "DHT.h"
#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 22  (AM2302), AM2321
DHT dht(DHTPIN, DHTTYPE);
#define buz 8
void setup() 
{
  Serial.begin(9600);
  dht.begin();
  pinMode(buz,OUTPUT);
}

void loop()
{
  delay(500);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  Serial.print ("temp:"+String(t));
  Serial.println("Hum:"+String(h));
  if(t>45)
  {
    digitalWrite(buz,HIGH); delay(1000); digitalWrite(buz,LOW);delay(1000);
    }
  
}
