#include <LPC21xx.H>
typedef  unsigned char U8;
void i2c_conf(void)
{			  
	PINSEL0|=0X50;
	I2SCLL=75;
	I2SCLH=75;
    I2CONSET=1<<6;
}				

void i2c_start(void)
{
	I2CONSET=1<<5;
	while(((I2CONSET>>3)&1)==0);
	I2CONCLR=1<<5;
}
	
void i2c_stop(void)
{
	I2CONSET=1<<4;
	I2CONCLR=1<<3;
}

void i2c_restart(void)
{
	I2CONSET=1<<5;
	I2CONCLR=1<<3;
	while(((I2CONSET>>3)&1)==0);
	I2CONCLR=1<<5;
}

U8 i2c_nack(void)
{
	I2CONCLR=1<<3;
	while(((I2CONSET>>3)&1)==0);
	return I2DAT;
}

U8 i2c_ack(void)
{
	I2CONSET=1<<2;
	I2CONCLR=1<<3;
	while(((I2CONSET>>3)&1)==0);
	I2CONCLR=1<<2;
	return I2DAT;
}


void i2c_write(U8 data)
{
	I2DAT=data;
	I2CONCLR=1<<3;
	while(((I2CONSET>>3)&1)==0);
}

















