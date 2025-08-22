#include <LPC21xx.H>
#include "display.h"

void KEYPAD(void);

#define	C0 ((IOPIN0>>4)&1)
#define	C1 ((IOPIN0>>5)&1)
#define	C2 ((IOPIN0>>6)&1)
#define	C3 ((IOPIN0>>7)&1)

#define	R0 ((IOPIN0>>0)&1)
#define	R1 ((IOPIN0>>1)&1)
#define	R2 ((IOPIN0>>2)&1)
#define	R3 ((IOPIN0>>3)&1)

//#define	C1 ((IOPIN1>>23)&1)
//#define	C2 ((IOPIN1>>24)&1)
//#define	C3 ((IOPIN1>>25)&1)
//#define	C4 ((IOPIN1>>26)&1)

#define keypad 0xff
#define row r0|r1|r2|r3
#define col c0|c1|c2|c3

#define r0 1<<0
#define r1 1<<1
#define r2 1<<2
#define r3 1<<3

#define c0 1<<4
#define c1 1<<5
#define c2 1<<6
#define c3 1<<7


char key_data[4][4]={{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'}};
int main()
{
 lcd_init();
 lcd_cmd(0x80);
 lcd_str("keypad status ");
 lcd_cmd(0xc0);
 while(1)
 
    KEYPAD();
}


 void KEYPAD(void)
 {
 int row_status,col_status;
  IODIR0=(IODIR0&(~keypad))|row;
  	while((C0&&C1&&C2&&C3)==1);
 if((C0&&C1&&C2&&C3)==0)
 {
    if(C0==0)
	col_status=0; 
	if(C1==0)
	col_status=1; 
	if(C2==0)
	col_status=2; 
	if(C3==0)
	col_status=3;
	
 IODIR0=(IODIR0&(~keypad))|col;
  	 
	if(R0==0)
	row_status=0; 
	if(R1==0)
	row_status=1; 
	if(R2==0)
	row_status=2; 
	if(R3==0)
	row_status=3;
 	while((R0&&R1&&R2&&R3)==0);
	 lcd_cmd(0xc0);
 	lcd_data(key_data[row_status][col_status]);
 
 }
 }

