#include <LPC21xx.H>


float adc(unsigned char ch)
{	
	unsigned char low,high;
	float val;
	IOCLR0=1;
	spio(0x06);
	high=spio(ch<<6);
	low=spio(0x00);
	IOSET0=1;
	val=((high&0x0f)<<8)|(low);
	return ((val*3.3)/4096);
}
