#include<reg51.h>
#define segment P2

sbit seg1 = P3^0;
sbit seg2 = P3^1;

void delay(int val);
void main()
{
segment = 0x4f; seg1=0;	seg2=1;
delay(10);
segment = 0x6f; seg1=1;	seg2=0;
delay(10);

}

void delay(int val)
{
	int i,j=0;
	for(i=0;i<=val;i++)
	{
	 for(j=0;j<=1000;j++);
	}
}