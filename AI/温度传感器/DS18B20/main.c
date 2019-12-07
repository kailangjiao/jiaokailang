#include"reg51.h"
#include"ds18b20.h"

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

void delay(u16 i)
{
	while(i--);	
}


u8 code smgduan[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,
0x7d,0x07,0x7f,0x6f};

u8 DisplayData[8];

void datapros(int temp)
{
		float tp;
	if(temp<0)
	{
	    DisplayData[0]=0x40;
		temp=temp-1;
		temp=~temp;
		tp=temp;
		temp=tp*0.625*100+0.5;
	}
	else
	{
		DisplayData[0]=0x00;
		tp=temp;
		temp=tp*0.625*100+0.5;	
	}
		DisplayData[1]=smgduan[temp/10000];
		DisplayData[2]=smgduan[temp%10000/1000];
	    DisplayData[3]=smgduan[temp%10000%1000/100]|0x80;
		DisplayData[4] = smgduan[temp % 100 / 10];
		DisplayData[5] = smgduan[temp % 10];
	}

void digdisplay()
{
	u8 i;
	for(i=0;i<6;i++)
	{
		switch(i)
		{
			case 0:	LSA=0;LSB=0;LSC=0; break;
			case 1:	LSA=1;LSB=0;LSC=0; break;
			case 2:	LSA=0;LSB=1;LSC=0; break;
			case 3:	LSA=1;LSB=1;LSC=0; break;
			case 4:	LSA=0;LSB=0;LSC=1; break;
			case 5:	LSA=1;LSB=0;LSC=1; break;
		}
		P0=	DisplayData[5-i];
		delay(100);
		P0=0x00;
	}
}

void main()
{
	while(1)
	{
	datapros(ds18b20readtemp());
	digdisplay();	
	}
}

 