#include<pic18f4550.h>
#include <xc.h>
#include <stdio.h>
#define led PORTAbits.RA0
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
 led = 0;
 while(1)
 {
 for(int i=0;i<=100;i++)
{
led = 1;
delay(i);
led = 0;
delay(100);
}

 for(int i=100;i>=0;i--)
 {
 led = 1;
delay(i);
led = 0;
delay(100);
 }

 }
 return;
}
