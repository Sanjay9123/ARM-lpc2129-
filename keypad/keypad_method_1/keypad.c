#include <LPC21xx.H>
#include "display.h"
void keypad();
#define c0 (IOPIN0>>4&1)
#define c1 (IOPIN0>>5&1)
#define c2 (IOPIN0>>6&1)
#define c3 (IOPIN0>>7&1)

#define	r0 1<<23
#define	r1 1<<24
#define	r2 1<<25
#define	r3 1<<26

unsigned char key[4][4]={{'1','2','3','a'},{'4','5','6','B'},{'7','8','9','C'},
{'*','0','#','D'}},col_s=0,row_s=0;

int main()
{
 lcd_init();
 lcd_cmd(0x80);
 lcd_str("keypad check");
 IODIR1=0XF<<23;
 IOCLR1=0XF<<23;
 while(1)
 keypad();

 
}

void keypad(){

 
 while((c0&&c1&&c2&&c3)==1);

//row 0
 IOCLR1=r0;
 IOSET1=r1|r2|r3;
 if((c0&&c1&&c2&&c3)==0)
	 row_s=0;

//row 1
 IOCLR1=r1;
 IOSET1=r0|r2|r3;
 if((c0&&c1&&c2&&c3)==0)
	 row_s=1;

//row 2
 IOCLR1=r2;
 IOSET1=r1|r0|r3;
 if((c0&&c1&&c2&&c3)==0)
	 row_s=2;

//row 3
 IOCLR1=r3;
 IOSET1=r1|r2|r0;
 if((c0&&c1&&c2&&c3)==0)
	 row_s=3;

IOCLR1=0XF<<23;
if(c0==0)
col_s=0;

if(c1==0)
col_s=1;

if(c2==0)
col_s=2;

 if(c3==0)
col_s=3;

while((c0&&c1&&c2&&c3)==0);

lcd_cmd(0xc0);
lcd_data(key[row_s][col_s]);
delay_ms(200);

}