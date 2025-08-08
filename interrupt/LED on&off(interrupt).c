#include <LPC21xx.H>
int i=0;
void intrrupt(void) __irq
  {
	EXTINT=1;
		 if(i==0)
	    {
		  IOSET0=1;
		  i=1;
		}
		else
		{ IOCLR0=1;
           i=0;
		 }
	VICVectAddr=0;
}
int main()
{		unsigned int count=0;
        PINSEL1=1;
		IODIR0=1;
  		VICIntSelect=0;
		VICVectCntl0=0x20|14;
		VICVectAddr0=(int)intrrupt;
		EXTMODE=1;
	    EXTPOLAR=0;
		VICIntEnable=1<<14;
		while(1)
		count++;
		
}
