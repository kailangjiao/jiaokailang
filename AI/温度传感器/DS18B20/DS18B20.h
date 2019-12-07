#ifndef _ds18b20_H
#define _ds18b20_H
     
#include"reg51.h"

#ifndef u16
#define u16 unsigned int
#endif

#ifndef u8
#define u8 unsigned char
#endif

sbit dsport=P2^7; 

u16 ds18b20readtemp();

#endif
