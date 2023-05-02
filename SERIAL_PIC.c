#include<PIC18F4550.h>
void delay(int t)
{
 for(int i=0;i<t;i++)
 for(int j=0;j<500;j++);
}
void serial_init()
{
 TRISCbits.RC6 = 0;
 TRISCbits.RC7 = 1;
 SPBRG = 64;
 TXSTA = 0x20;
 RCSTA = 0x80;
}
void transmit(unsigned char ch)
{
 TXREG = ch;
 while(PIR1bits.TXIF==0);
 PIR1bits.TXIF=0;
}
unsigned char receive()
{
 while(!(PIR1bits.RCIF));
 PIR1bits.RCIF =0;
 return RCREG;
}
void main()
{
 unsigned char ch;
 serial_init();
 while(1)
 {
 ch = receive();
 transmit(ch);
 }
}