#include"ds18b20.h"

void delay1ms(u16 y)
{
    u8 x;
	for(;y>0;y--)
	{
	    for(x=110;x>0;x--);

	}

}

u8 ds18b20init()
{
    u8 i;
	dsport=0;
    i=70;
	while(i--);
	i=0;
	dsport=1;
	while(dsport)
	{
	    delay1ms(1);
		i++;
		if(i>5)
		{
		    return 0;
		}
	}
	return 1;
}

void ds18b20writebyte(u8 dat)
{
	u8 i,j;
    
	 for(j=0;j<8;j++)
	 {
	   	  dsport=0;
	      i=3;
	 	  while(i--);
		  dsport=dat&0x01;
		  i=6;
		  while(i--);
		  dsport=1;
		  dat>>=1;	
	 }
}

u8 ds18b20readbyte()
{
    u8 i,j;
	u8 bi, byte;
	for	(i=0;i<8;i++)
	{
	    dsport=0;
		j++;
		dsport=1;
		j++;
		j++;
		bi=dsport;
		byte=((byte>>1)|(bi<<7));
		j=6;
		while(j--);
	}
	return byte;
}

void ds18b20changetemp()
{
	 ds18b20init();
	 delay1ms(1);
	 ds18b20writebyte(0xcc);
	 ds18b20writebyte(0x44);
}

void ds18b20readchangetemp()
{
	 ds18b20init();
	 delay1ms(1);
	 ds18b20writebyte(0xcc);
	 ds18b20writebyte(0xbe);
}

u16 ds18b20readtemp()
{	
	u8 thl,thh;
	u16 temp; 	
	 ds18b20changetemp();
	 ds18b20readchangetemp();
	 thl=ds18b20readbyte();
	 thh=ds18b20readbyte();
	 temp=thh;
	 temp<<=8;
	 temp|=thl;
	 return temp;
}


