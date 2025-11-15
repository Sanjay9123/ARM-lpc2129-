#include "delay.h"
#include "4bit_lcd.h"
#include "spi.h"
#include "adc.h"

int main()
{
   lcd_init();
   spi_init();
   lcd_cmd(0x80);
   lcd_str("sanjay");
   delay_ms(2000);
   while(1)
   {	
   		float val;
		val=adc(2);
		lcd_cmd(0x01);
		lcd_cmd(0x80);
		lcd_float(val);
		delay_ms(1000);
   }


}