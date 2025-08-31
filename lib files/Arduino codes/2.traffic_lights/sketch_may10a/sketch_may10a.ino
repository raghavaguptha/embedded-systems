#define ER 2
#define EG 3
#define EY 4

#define WR 5
#define WG 6
#define WY 7

#define SR 8
#define SG 9
#define SY 10

#define NR 11
#define NG 12
#define NY 13
void setup()
{
  for (int i = 2; i <= 13; i++)
  {
    pinMode(i, OUTPUT);
  }
}

void loop()
{
 e_allow(); delay(1000); n_ready();
 n_allow(); delay(1000); w_ready();
 w_allow(); delay(1000); s_ready();
 s_allow(); delay(1000); e_ready();
 }

void e_allow()
{
  digitalWrite(ER, LOW);
  digitalWrite(EG, HIGH);
  digitalWrite(EY, LOW);

  digitalWrite(WR, HIGH);
  digitalWrite(WG, LOW);
  digitalWrite(WY, LOW);

  digitalWrite(NR, HIGH);
  digitalWrite(NG, LOW);
  digitalWrite(NY, LOW);

  digitalWrite(SR, HIGH);
  digitalWrite(SG, LOW);
  digitalWrite(SY, LOW);
}

void w_allow()
{
  digitalWrite(ER, HIGH);
  digitalWrite(EG, LOW);
  digitalWrite(EY, LOW);

  digitalWrite(WR, LOW);
  digitalWrite(WG, HIGH);
  digitalWrite(WY, LOW);

  digitalWrite(NR, HIGH);
  digitalWrite(NG, LOW);
  digitalWrite(NY, LOW);

  digitalWrite(SR, HIGH);
  digitalWrite(SG, LOW);
  digitalWrite(SY, LOW);
}

void n_allow()
{
  digitalWrite(ER, HIGH);
  digitalWrite(EG, LOW);
  digitalWrite(EY, LOW);

  digitalWrite(WR, HIGH);
  digitalWrite(WG, LOW);
  digitalWrite(WY, LOW);

  digitalWrite(NR, LOW);
  digitalWrite(NG, HIGH);
  digitalWrite(NY, LOW);

  digitalWrite(SR, HIGH);
  digitalWrite(SG, LOW);
  digitalWrite(SY, LOW);
}

void s_allow()
{
  digitalWrite(ER, HIGH);
  digitalWrite(EG, LOW);
  digitalWrite(EY, LOW);

  digitalWrite(WR, HIGH);
  digitalWrite(WG, LOW);
  digitalWrite(WY, LOW);

  digitalWrite(NR, HIGH);
  digitalWrite(NG, LOW);
  digitalWrite(NY, LOW);

  digitalWrite(SR, LOW);
  digitalWrite(SG, HIGH);
  digitalWrite(SY, LOW);
}

void e_ready()
{
  for (int i = 0; i <= 5; i++)
  {
    digitalWrite(EY, HIGH);
    delay(250);
    digitalWrite(EY, LOW);
    delay(250);
  }
}

void w_ready()
{
  for (int i = 0; i <= 5; i++)
  {
    digitalWrite(WY, HIGH);
    delay(250);
    digitalWrite(WY, LOW);
    delay(250);
  }
}

void s_ready()
{
  for (int i = 0; i <= 5; i++)
  {
    digitalWrite(SY, HIGH);
    delay(250);
    digitalWrite(SY, LOW);
    delay(250);
  }
}

void n_ready()
{
  for (int i = 0; i <= 5; i++)
  {
    digitalWrite(NY, HIGH);
    delay(250);
    digitalWrite(NY, LOW);
    delay(250);
  }
}
