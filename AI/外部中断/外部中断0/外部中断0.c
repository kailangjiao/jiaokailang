#include"reg51.h"
sbit k3=P3^2;
sbit led=P2^7;
typedef unsigned int u16;
void delay(u16 i)
{
   while(i--);
}
void int0resp()
{
   EA=1;
   EX0=1;
   IT0=1;
}
void main()
{
   int0resp();
   while(1);
}
   void int0 () interrupt 0
  {  
   delay(1000);
   if(k3==0)
   {
      led=~led;
   }
   }
