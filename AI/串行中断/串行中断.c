#include"reg51.h"
typedef unsigned int u16;
typedef unsigned char u8;
void usartinit()
{
    TMOD=0X20;
	TH1=0XF3;
	TL1=0XF3;
	TR1=1;
	PCON=0x80;
	SCON=0X50;
	ES=1;
	EA=1;
}
void main()
{
    usartinit();
	while(1);
}
 void usart() interrupt 4
 {
 	 u8 a;
     RI=0;
	 a=SBUF;
	 SBUF=a;
	
	 while(!TI);
	 TI=0;
 }