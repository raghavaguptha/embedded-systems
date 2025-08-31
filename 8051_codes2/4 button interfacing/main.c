#include<reg51.h>

sbit led_1 = P1^0;
sbit led_2 = P1^1;
sbit led_3 = P1^2;
sbit led_4 = P1^3;

sbit button_1 = P2^0;
sbit button_2 = P2^1;
sbit button_3 = P2^2;
sbit button_4 = P2^3;

void main()
{
	while(1)
	{
	if(button_2 == 0)
	{
	 led_2=1;
	}
	else
	{
	led_2=0;
	}

	if(button_3 == 0)
	{
	 led_3=1;
	}
	else
	{
	led_3=0;
	}

	if(button_4 == 0)
	{
	 led_4=1;
	}
	else
	{
	led_4=0;
	}

	if(button_1 == 0)
	{
	 led_1=1;
	}
	else
	{
	led_1=0;
	}
	}
}