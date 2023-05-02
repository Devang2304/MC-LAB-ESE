#include<PIC18F4550.h>
#include<xc.h>
#include<stdio.h>
#define ldata PORTB
#define rs PORTAbits.RA0
#define en PORTAbits.RA1
#define sw1 PORTAbits.RA2
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
void lcd_init()
{
 TRISB=0x00;
 TRISAbits.RA0=0;
 TRISAbits.RA1=0;
 ADCON1=0X0F;
 lcdcmd(0x38); //8bit 2line display
 lcdcmd(0x06); //Entry mode
 lcdcmd(0x0C); //disp on cursor off
 lcdcmd(0x01); //clr display
 delay(100);
}
void ADC_INIT()
{
 TRISEbits.RE1=1;
 TRISEbits.RE2=1;
 ADCON1 = 0x07;
 ADCON2 = 0xAE;
}
unsigned short READ_ADC(unsigned char ch)
{
 ADCON0 = 0x01 | (ch<<2);
 GODONE = 1;
 while(GODONE==1);
 return ADRES;
}
void DISPLAY_RESULT(unsigned short ADCVAL)
{
 unsigned char i,text[16];
 unsigned short temp;
 temp = ADCVAL;
 lcdcmd(0x80);
 for(int i=0;i<10;i++)
 {
 if(temp & 0x200)
 lcddata('1');
 else
 lcddata('0');
 temp = temp<<1;
 }
 ADCVAL = (5000/1024)*ADCVAL;
 sprintf(text,"ADC value=%4dmV",ADCVAL);
 lcdcmd(0xC0);
 for(int i=0;i<16;i++)
 lcddata(text[i]);
}
void main()
{
 unsigned short ch_res;
 int choice=0;
 char arr1[4]={"POT1"};
 char arr2[4]={"POT2"};
 TRISB=0x00;
 TRISAbits.RA2=1;
 ADC_INIT();
 lcd_init();
 while(1)
 {
 if(sw1==0)
 {
 ++choice;
 choice=choice%2;
 }
 if(choice==0)
 {
 ch_res = READ_ADC(6);
 lcdcmd(0x8C);
 for(int i=0;i<4;i++)
 lcddata(arr1[i]);
 delay(50);
 }
 else if(choice==1)
 {
 ch_res = READ_ADC(7);
 lcdcmd(0x8C);
 for(int i=0;i<4;i++)
 lcddata(arr2[i]);
 delay(50);
 }
 DISPLAY_RESULT(ch_res);
 delay(100);
 }
}
