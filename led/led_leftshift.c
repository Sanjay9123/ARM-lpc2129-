#include <LPC21xx.H>
#include "delay.h"


int main()
{ int i;
 IODIR0=0xff;
 IOSET0=0XFF;
 while(1)
 {
   for(i=0;i<=7;i++)
   {
 	IOCLR0=1<<i;
	delayms(100);
 	IOSET0=1<<i;
	delayms(100);
   }
 }



}
