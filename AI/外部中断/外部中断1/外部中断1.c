																#include"reg51.h"
sbit lsa=P2^2;
sbit lsb=P2^3;
sbit lsc=P2^4;
sbit k4=P3^3;
typedef unsigned char u8;
typedef unsigned int u16;
void delay(u16 i)
{
     while(i--);
}
u8 code smgduan[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,
0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
void int1init ()
{
    EA=1;
	EX1=1;
	IE0=1;

}
void main()
{
     lsa=0;
	 lsb=0;
	 lsc=0;
    int1init ();
    while(1);
}
void int1() interrupt 2
{
    delay(1000);
	if(k4==0)
	{
		u8 i;
	    P0=smgduan[i];
		i++;
	}
	while(!k4);

}