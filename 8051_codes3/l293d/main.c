#include<reg51.h>

sbit in1 = P2^0;
sbit in2 = P2^1;
sbit in3 = P2^2;
sbit in4 = P2^3;
void delay(int val);
void main()
{
  while(1)
  {
  in1=1; in2=0;
  in3=1; in4=0;
  delay(1000);

  in1=0; in2=1;
  in3=0; in4=1;
  delay(1000);

  in1=1; in2=0;
  in3=0; in4=1;
  delay(1000);

  in1=0; in2=1;
  in3=1; in4=0;
  delay(1000);

  in1=0; in2=0;
  in3=0; in4=0;
  delay(1000);

  }
}

void delay(int val)
{
  int i,j=0;
  for(i=0;i<=val;i++)
  {
  	for(j=0;j<=1000;j++);
  }
}