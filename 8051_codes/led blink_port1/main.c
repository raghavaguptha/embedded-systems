#include<reg51.h>
#define led P1
void delay(int val);
void main()
{
led = 0x01;
delay(100);
led = 0x02;
delay(100);
led = 0x04;
delay(100);
led = 0x08;
delay(100);
led = 0x10;
delay(100);
led = 0x20;
delay(1000);
led = 0x40;
delay(100);
led = 0x80;
delay(100);
}

void delay(int val)
{
    int i,j=0;
	for( i=0;i<=val;i++)
	{
	  for( j=0;j<=1000;j++);
	}
}


