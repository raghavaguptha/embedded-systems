#include<reg51.h>

#define port2 P2
#define port3 P3
void delay(int val);
void main()
{

	while(1)
	{
   int i=0;
   port2 = 0x00;
   port3 = 0x00;
   for(i=0;i<=5;i++)
   {
   port2 = ~port2;
   delay(100);
   }
   for(i=0;i<=5;i++)
   {
   port3 = ~port3;
   delay(100);
   }
	}
}

void delay(int val)
{
int a,b=0;
for(a=0;a<=val;a++)
	for(b=0;b<=1000;b++);
}