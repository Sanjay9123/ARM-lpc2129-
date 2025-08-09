
//startup : comment the FIQ_Handler B FIQ_Handler 
//and add EXTERN FIQ_Handler

#include <LPC21xx.H>
int i=0;

void interrupt(void) __irq
  {
	EXTINT=1;
		 if(i==0)
	    {
		  IOSET0=1<<18;
		  i=1;
		}
		else
		{ IOCLR0=1<<18;
           i=0;
		 }
	VICVectAddr=0;
}
 void FIQ_Handler(void) __irq
{
		 EXTINT=2;
		 if(i==0)
	    {
		  IOSET0=1<<19;
		  i=1;
		}
		else
		{ IOCLR0=1<<19;
           i=0;
		 }
	VICVectAddr=0;
}
int main()
{		unsigned int count=0;
        PINSEL1=1;
		PINSEL0=1<<29;
		IODIR0=1<<18|1<<19;
		IOSET0=1<<18||1<<19;
  		VICIntSelect=1<<15;
		VICVectCntl0=0x20|14;
		VICVectAddr0=(int)interrupt;
		EXTMODE=3;
	    EXTPOLAR=0;
		VICIntEnable=1<<14|1<<15;
		while(1)
		count++;
		
}
