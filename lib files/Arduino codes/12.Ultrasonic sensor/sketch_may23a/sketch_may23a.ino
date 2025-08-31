#define trig 8
#define echo 9

double duration;
float distance;

void setup()
{

  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}


void loop()
{
  float d = get_distance(); 
  Serial.println("Dis:"+String(d)+"cm");
  delay(1000);
}


float get_distance()
{
  digitalWrite(trig, LOW);
  delay(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = duration * 0.0343 / 1;
  return distance;
}
