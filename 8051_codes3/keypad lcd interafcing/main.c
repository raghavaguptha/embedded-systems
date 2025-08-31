#include<reg51.h>

sbit room_light = P1^2;
sbit hall_light = P1^3;

sbit r1 = P2^0;
sbit r2 = P2^1;
sbit r3 = P2^2;
sbit r4 = P2^3;

sbit c1 = P2^4;
sbit c2 = P2^5;
sbit c3 = P2^6;

#define lcd P3
sbit rs = P1^0;
sbit en = P1^1;
char read_keypad();
char get_key();
void lcd_cmd(unsigned char ch);
void lcd_data(unsigned char ch);
void lcd_init();
void delay(int val);
void display(unsigned char s[]);
void main()
{
	room_light=0;
	hall_light=0;
    lcd_init();
	lcd_cmd(0x01);
	lcd_cmd(0x80);
	display("Load_1:");
	lcd_cmd(0xC0);
	display("Load_2:");
	while(1)
	{
	 char new_key = get_key();
	 lcd_cmd(0x8f);
	 lcd_data(new_key);
	 if(new_key == '1'){room_light=1; lcd_cmd(0x88); display("ON ");}
	 if(new_key == '2'){room_light=0;lcd_cmd(0x88); display("OFF");}
	 if(new_key == '3'){hall_light=1;}
	 if(new_key == '4'){hall_light=0;}
	}
}


char read_keypad()
{
  r1=0;r2=1;r3=1;r4=1;
  if(c1==0){while(c1==0); return '1';}
  if(c2==0){while(c2==0); return '2';}
  if(c3==0){while(c3==0); return '3';}

  r1=1;r2=0;r3=1;r4=1;
  if(c1==0){while(c1==0); return '4';}
  if(c2==0){while(c2==0); return '5';}
  if(c3==0){while(c3==0); return '6';}

  r1=1;r2=1;r3=0;r4=1;
  if(c1==0){while(c1==0); return '7';}
  if(c2==0){while(c2==0); return '8';}
  if(c3==0){while(c3==0); return '9';}

    r1=1;r2=1;r3=1;r4=0;
  if(c1==0){while(c1==0); return '*';}
  if(c2==0){while(c2==0); return '0';}
  if(c3==0){while(c3==0); return '#';}

  return 'n';
}


char get_key()
{
 char key = 'n';
 while(key == 'n')
 {
   key = read_keypad();
 }
 return key;
}


void lcd_cmd(unsigned char ch)
{
rs = 0;
lcd = ch;
en=1;
delay(1);
en=0;
}

void lcd_data(unsigned char ch)
{
rs = 1;
lcd = ch;
en=1;
delay(1);
en=0;
}

void lcd_init()
{
    lcd_cmd(0x38);
	lcd_cmd(0x01);
	lcd_cmd(0x0E);
	lcd_cmd(0x06);
}

void delay(int val)
{
 int i,j=0;
 for(i=0;i<=val;i++)
 {
 for(j=0;j<=1000;j++);
 }
}


void display(unsigned char s[])
{
  int k=0;
  for(k=0;s[k]!='\0';k++)
  {
   lcd_data(s[k]);
  }
}

