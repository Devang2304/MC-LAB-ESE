#include<PIC18F4550.h>
#include<xc.h>
#define sw1 PORTAbits.RA2
#define sw2 PORTAbits.RA3
#define led PORTAbits.RA0
void delay (unsigned int time)
{
 unsigned int i,j;
 for(i=0;i<time;i++)
 for(j=0;j<100;j++);
}
void main()
{
 TRISAbits.RA2=1;
 TRISAbits.RA3=1;
 TRISAbits.RA0=0;
 ADCON1 = 0x0F;
 int d=10;
 led = 1;
while(1)
{
if(sw1 == 0)
{
if(d==100)
d = 10;
else
d += 10;
}
else if(sw2 == 0)
{
if(d==10)
d = 100;
else
d -= 10;
}
else
{
led = 1;
delay(d);
led = 0;
delay(d);
}
}
}