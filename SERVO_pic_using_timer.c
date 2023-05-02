#include<pic18f4550.h>
#include <xc.h>
#include <stdio.h>
void delay(unsigned int t)
{
 unsigned int i, j;
 for(i=0;i<t;i++)
 for(j=0;j<500;j++);
}
void delay_1m()
{ 
 TMR0H = 0xFF;
 TMR0L = 0xED;
 T0CONbits.TMR0ON = 1;
 while(INTCONbits.TMR0IF==0);
 T0CONbits.TMR0ON = 0;
 INTCONbits.TMR0IF=0; 
}
void delay_1_5m()
{ 
 TMR0H = 0xFF;
 TMR0L = 0xE3;
 T0CONbits.TMR0ON = 1;
 while(INTCONbits.TMR0IF==0);
 T0CONbits.TMR0ON = 0;
 INTCONbits.TMR0IF=0; 
}
void delay_2m()
{ 
 TMR0H = 0xFF;
 TMR0L = 0xD9;
 T0CONbits.TMR0ON = 1;
 while(INTCONbits.TMR0IF==0);
 T0CONbits.TMR0ON = 0;
 INTCONbits.TMR0IF=0; 
}
void delay_19m()
{ 
 TMR0H = 0xFE;
 TMR0L = 0x8D;
 T0CONbits.TMR0ON = 1;
 while(INTCONbits.TMR0IF==0);
 T0CONbits.TMR0ON = 0;
 INTCONbits.TMR0IF=0; 
}
void delay_18_5m()
{ 
 TMR0H = 0xFE;
 TMR0L = 0x97;
 T0CONbits.TMR0ON = 1;
 while(INTCONbits.TMR0IF==0);
 T0CONbits.TMR0ON = 0;
 INTCONbits.TMR0IF=0; 
}
void delay_18m()
{ 
 TMR0H = 0xFE;
 TMR0L = 0xA0;
 T0CONbits.TMR0ON = 1;
 while(INTCONbits.TMR0IF==0);
 T0CONbits.TMR0ON = 0;
 INTCONbits.TMR0IF=0; 
}
void main(void) {
 TRISAbits.TRISA0 = 0; 
 ADCON1 = 0X0F;
 T0CON = 0x07;
 while(1)
 {
 PORTAbits.RA0=1;
 delay_1m();
 PORTAbits.RA0=0;
 delay_19m();
 delay(100);
 
 PORTAbits.RA0=1;
 delay_1_5m();
 PORTAbits.RA0=0;
 delay_18_5m();
 delay(100);
 
 PORTAbits.RA0=1;
 delay_2m();
 PORTAbits.RA0=0;
 delay_18m();
 delay(100);
 }
 
 return;
}
