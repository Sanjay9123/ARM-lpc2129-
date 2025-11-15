#include <LPC21xx.H>
#include "delay.h"

int pwm=0;
int main()
{
  PINSEL0|=0X8;

  PWMPR=15; //MICRO SECOND
  PWMMR0=1000;
  PWMMR3=pwm;
  PWMLER=1<<3|1<<0;
  PWMMCR=0X02;
  PWMPCR=1<<11;
  PWMTCR=0X09;
  while(1)
  {
      PWMMR3=pwm++;
      PWMLER=1<<3;
	  delay_ms(5);
	  if(pwm>1000)
	  pwm=0;

  }
} 
