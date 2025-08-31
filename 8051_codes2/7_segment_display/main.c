#include<reg51.h>
#define segment P2

void delay(int val);
void main()
{
segment = 0x3F; delay(100);
segment = 0x06; delay(100);
segment = 0x5b; delay(100);
segment = 0x4f; delay(100);
segment = 0x66; delay(100);
segment = 0x6d; delay(100);
segment = 0x7d; delay(100);
segment = 0x07; delay(100);
segment = 0x7f; delay(100);
segment = 0x6f; delay(100);
}

void delay(int val)
{
	int i,j=0;
	for(i=0;i<=val;i++)
	{
	 for(j=0;j<=1000;j++);
	}
}