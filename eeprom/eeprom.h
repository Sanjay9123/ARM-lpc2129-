#include <LPC21xx.H>
#include "i2c.h"

void eeprom_write(U8 saddr,U8 waddr,U8 data)
{
	i2c_start();
	i2c_write(saddr<<1);
	i2c_write(waddr);
	i2c_write(waddr); // this is for seperate f24c256
	i2c_write(data);
	i2c_stop();
}

U8 eeprom_read(U8 saddr,U8 waddr)
{
	U8 read;
	i2c_start();
	i2c_write(saddr<<1);
	i2c_write(waddr);
	i2c_write(waddr);
	i2c_restart();
	i2c_write(saddr<<1|1);
	read =i2c_nack();
	i2c_stop();
	return read;
}

void eeprom_pread(U8 saddr,U8 waddr,U8 *data,U8 n)
{	U8 i;

	
	i2c_start();

	i2c_write(saddr<<1);
	
	i2c_write(waddr);
	
	i2c_restart();
	lcd_data('.');
	i2c_write(saddr<<1|1);
	lcd_data('.');
	delay_ms(10);
	for(i=0;i<n-1;i++){
	data[i]=i2c_ack();
	}
	data[i]=i2c_nack();
	i2c_stop();
}

void eeprom_pwrite(U8 saddr,U8 waddr,U8 *data,U8 n)
{	U8 i;
	i2c_start();
	i2c_write(saddr<<1);
	i2c_write(waddr);
	for(i=0;i<n;i++)
	i2c_write(data[i]);
	i2c_stop();
}



