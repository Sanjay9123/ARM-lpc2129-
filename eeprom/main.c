#include <LPC21xx.H>
#include "delay.h"
 #include "4bit_lcd.h"
#include "eeprom.h"


int main()
{
U8 ch ='a',ch1='d';
U8 ch0[100]="sanjay";
U8 test[100]={0};
  lcd_init();
  i2c_conf();
  lcd_cmd(0x80);
  lcd_str("begin...");
  lcd_cmd(0x01);
  lcd_cmd(0x80);
  lcd_data(ch);
  lcd_cmd(0xc0);
  lcd_data(ch1);
                       //delay_ms(2000);
  lcd_cmd(0x01);
  lcd_str("writting");
  //eeprom_pwrite(0x50,0x00,ch0,6);
  eeprom_write(0x50,0x00,ch);                             //delay_ms(2000);
  lcd_cmd(0x01);
  lcd_str("written");
                           //delay_ms(2000);
  lcd_cmd(0x01);
  lcd_str("reading");
  //eeprom_pread(0x50,0x00,test,6);
  ch1= eeprom_read(0x50,0x00);                        //delay_ms(2000);
  lcd_cmd(0x01);
  lcd_cmd(0x80);
  lcd_data(ch);
  lcd_cmd(0xc0);
  lcd_int(ch1);
  //lcd_str(test);
}




