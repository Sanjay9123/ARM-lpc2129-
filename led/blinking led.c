#include <LPC21xx.H>
void delayms(unsigned short int);

int main()
{
 IODIR0|=1;
 while(1)
 {	 
	 IOSET0=0xff;
	 delayms(1000);
	 IOCLR0=0xff;
	 delayms(1000);
 }
}
 void delayms(unsigned short int ms)
 {
T0PR=15000-1;
T0TCR=0x1;
while(T0TC<ms);
T0TCR=0x03;
T0TCR=0x00;
 }
