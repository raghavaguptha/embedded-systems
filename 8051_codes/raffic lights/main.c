#include<reg51.h>

sbit e_red = P1^0;
sbit e_green = P1^1;
sbit e_yellow = P1^2;

sbit w_red = P1^3;
sbit w_green = P1^4;
sbit w_yellow = P1^5;
void delay(int val);
void get_ready_e();
void get_ready_w();


void main()
{
while(1)
{
  e_red = 0;
  e_green = 1;
  e_yellow = 0;
  w_red = 1;
  w_green = 0;
  w_yellow = 0;
  delay(1000);

  get_ready_w();

   e_red = 1;
  e_green = 0;
  e_yellow = 0;
  w_red = 0;
  w_green = 1;
  w_yellow = 0;
  delay(1000);

  get_ready_e();
 
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

void get_ready_e()
{
    int a=0;
	for(a=0;a<=5;a++)
	{
	e_yellow = 1; 
	delay(50);
	e_yellow = 0; 
	delay(50);
	}
}

void get_ready_w()
{
    int a=0;
	for(a=0;a<=5;a++)
	{
	w_yellow = 1; 
	delay(50);
	w_yellow = 0; 
	delay(50);
	}
}