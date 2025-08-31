#include<reg51.h>

sbit e_red = P1^0;
sbit e_green = P1^1;
sbit e_yellow = P1^2;

sbit w_red = P1^3;
sbit w_green = P1^4;
sbit w_yellow = P1^5;

sbit n_red = P2^0;
sbit n_green = P2^1;
sbit n_yellow = P2^2;

sbit s_red = P2^3;
sbit s_green = P2^4;
sbit s_yellow = P2^5;


void delay(int val);
void get_ready_e();
void get_ready_w();
void get_ready_s();
void get_ready_n();

void allow_e();
void allow_w();
void allow_s();
void allow_n();


void main()
{
	while(1)
	{
	  allow_e(); delay(500);
	  get_ready_w();

	  allow_w(); delay(500);
	  get_ready_n();

	  allow_n(); delay(500);
	  get_ready_s();

	  allow_s(); delay(500);
	  get_ready_e();
	}
}

void allow_e()
{
  e_red = 0;
  e_green = 1;
  e_yellow = 0;

  w_red = 1;
  w_green = 0;
  w_yellow = 0;

  s_red = 1;
  s_green = 0;
  s_yellow = 0;

  n_red = 1;
  n_green = 0;
  n_yellow = 0;
}


void allow_w()
{
  e_red = 1;
  e_green = 0;
  e_yellow = 0;

  w_red = 1;
  w_green = 0;
  w_yellow = 0;

  s_red = 0;
  s_green = 1;
  s_yellow = 0;

  n_red = 1;
  n_green = 0;
  n_yellow = 0;
}

void allow_s()
{
  e_red = 1;
  e_green = 0;
  e_yellow = 0;

  w_red = 1;
  w_green = 0;
  w_yellow = 0;

  s_red = 0;
  s_green = 1;
  s_yellow = 0;

  n_red = 1;
  n_green = 0;
  n_yellow = 0;
}

void allow_n()
{
  e_red = 1;
  e_green = 0;
  e_yellow = 0;

  w_red = 1;
  w_green = 0;
  w_yellow = 0;

  s_red = 1;
  s_green = 0;
  s_yellow = 0;

  n_red = 0;
  n_green = 1;
  n_yellow = 0;
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

void get_ready_s()
{
    int a=0;
	for(a=0;a<=5;a++)
	{
	s_yellow = 1; 
	delay(50);
	s_yellow = 0; 
	delay(50);
	}
}

void get_ready_n()
{
    int a=0;
	for(a=0;a<=5;a++)
	{
	n_yellow = 1; 
	delay(50);
	n_yellow = 0; 
	delay(50);
	}
}