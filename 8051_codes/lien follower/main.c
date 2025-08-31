#include<reg51.h>

sbit in1 = P2^0;
sbit in2 = P2^1;
sbit in3 = P2^2;
sbit in4 = P2^3;

sbit ir1 = P3^0;
sbit ir2 = P3^1;

void front();
void back();
void left();
void right();
void stop();

void main()
{
	while(1)
	{
	 if(ir1 == 0 && ir2 == 0)
	 {
	  front();
	 }
	 if(ir1 == 1 && ir2 == 0)
	 {
	  left();
	 }
	 if(ir1 == 0 && ir2 == 1)
	 {
	  right();
	 }
	 if(ir1 == 1 && ir2 == 1)
	 {
	  stop();
	 }
	}
}

void front()
{
 in1=1;
 in2=0;
 in3=1;
 in4=0;
}

void back()
{
 in1=0;
 in2=1;
 in3=0;
 in4=1;
}	  

void left()
{
 in1=1;
 in2=0;
 in3=0;
 in4=1;
}

void right()
{
 in1=0;
 in2=1;
 in3=1;
 in4=0;
}

void stop()
{
 in1=0;
 in2=0;
 in3=0;
 in4=0;
}