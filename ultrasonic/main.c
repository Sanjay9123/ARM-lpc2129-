#include <LPC21xx.H>
#include "delay.h"
#include "v4bit_lcd.h"
int main()
{
 float time=0,dis;	
  lcd_init();
  IODIR0 |=1<<0;
  
  
 	  while(1)
	  {		  T1PR=15;
	    	  IOSET0=1<<0;
			  delay_us(10);
			  IOCLR0=1<<0;
			  while(((IOPIN0>>1)&1)==0);
			  T1TCR=1;
			  while(((IOPIN0>>1)&1)==1);
			  time=T1TC;
			  T1TCR=3;
			  T1TCR=0;	  
			  dis=time/58.0;
			  
			  lcd_cmd(0x80);
			  lcd_str("distance ");
			  lcd_float(dis); 
			  delay_ms(200); 
   	  }
}



