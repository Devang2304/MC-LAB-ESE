#include<PIC18F4550.h>
#define ldata PORTB
#define rs PORTAbits.RA0
#define en PORTAbits.RA1
void delay(unsigned int data)
{
 int i,j;
 for(i=0;i<data;i++)
 for(j=0;j<100;j++);
}
void lcdcmd(unsigned char value)
{
 rs=0;
 ldata=value;
 en=1;
 delay(50);
 en=0;
 delay(50);
}
void lcddata(unsigned char value)
{
 rs=1;
 ldata=value;
 en=1;
 delay(50);
 en=0;
 delay(50);
}
void main(void)
{
 char str[4] = {"EXTC "};
 TRISB=0x00;
 TRISAbits.RA0=0;
 TRISAbits.RA1=0;
 ADCON1=0X0F;
 lcdcmd(0x38); //8bit 2line display
 lcdcmd(0x06); //Entry mode
 lcdcmd(0x0C); //disp on cursor off
 lcdcmd(0x01); //clr display
 lcdcmd(0xC3);
 delay(100);
 for(int i=0;i<10;i++)
 {
 lcddata(str[i]);
 }
 while(1);
}