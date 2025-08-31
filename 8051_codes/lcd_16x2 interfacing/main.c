#include<reg51.h>

#define lcd P2

sbit rs = P3^0;
sbit en = P3^1;

void lcd_data(unsigned char ch);
void lcd_cmd(unsigned char ch);
void lcd_init();
void delay(int val);

void main()
{
    lcd_init();
	while(1)
	{
	   lcd_cmd(0x01);
	   lcd_cmd(0x80);
	   lcd_data('H');
	   lcd_data('I');
	   lcd_cmd(0xC0);
	   lcd_data('H');
	   lcd_data('E');
	   lcd_data('L');
	   lcd_data('L');
	   lcd_data('O');
	   delay(100);
	}

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
	rs=1;
	lcd = ch;
	en=1;
	delay(1);
	en=0;
}

void lcd_init()
{
lcd_cmd(0x38); //8bit 2 lines
lcd_cmd(0x01); //to clear screen
lcd_cmd(0x0E); //display on corsur on
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