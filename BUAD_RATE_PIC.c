#include<PIC18F4550.h>
#include<xc.h>
#define serial PORTCbits.RC6
void delay (unsigned int time)
{
 unsigned int i,j;
 for(i=0;i<time;i++)
 for(j=0;j<100;j++);
}
void main()
{
 unsigned char name[7] = {"DEV OZA"};
 TRISCbits.RC6=0;
 ADCON1 = 0x0F;
 SPBRG = 0x0F; //spbrg = [clck/(64*baudrate)]-1,19200 baudrate
 TXSTA = 0x20;
 RCSTA = 0x80;
while(1)
{
for(int i=0;i<7;i++)
 {
 TXREG = name[i];
 while(PIR1bits.TXIF==0);
 PIR1bits.TXIF=0;
 delay(1000);
 }
}
}