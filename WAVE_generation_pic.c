#include<pic18f4550.h>
#include <xc.h>
#include <stdio.h>
#define dso PORTAbits.RA0
void delay_10m()
{
 TMR0H = 0x3C;
 TMR0L = 0xB0;
 T0CONbits.TMR0ON = 1;
 while(INTCONbits.TMR0IF==0);
 T0CONbits.TMR0ON = 0;
 INTCONbits.TMR0IF=0;
}
void delay(unsigned int d)
{
 int i;
 for (i =0 ;i<d;i++)
 delay_10m();
}
void main(void) {
 TRISAbits.TRISA0 = 0;
 ADCON1 = 0X0F;
 T0CON = 0x07;
 dso = 0;
 while(1)
 {
 dso = 1;
 delay(5);
 dso = 0;
 delay(5);
 for(int i=0;i<5;i++)
 {
 dso = 1;
 delay(2);
 dso = 0;
 delay(2);
 }
 dso = 1;
 delay(5);
 dso = 0;
 delay(5);
 }

 return;
}
