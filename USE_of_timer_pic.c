#include<pic18f4550.h>
#include <xc.h>
#include <stdio.h>
#define dso PORTAbits.RA0
void delay(int n)
{
 for (int i=0;i<n;i++)
 {
 TMR0H = 0xEC;
 TMR0L = 0x78;
 T0CONbits.TMR0ON = 1;
 while(INTCONbits.TMR0IF==0);
 T0CONbits.TMR0ON = 0;
 INTCONbits.TMR0IF=0;
 }
}
void main(void)
{
 TRISAbits.TRISA0 = 0;
 ADCON1 = 0X0F;
 T0CON = 0x07;
 dso = 0;
 while(1)
 {
 for(int i=20;i<=80;i++)
{
dso = 1;
delay(i);
dso = 0;
delay(100-i);
}
 }
 return;
}
