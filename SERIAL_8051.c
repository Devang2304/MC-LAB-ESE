#include<reg51.h>
void delay(int t)
{
unsigned int i,j;
for(i=0;i<t;i++)
for(j=0;j<1275;j++);
}
void serial_init()
{
TMOD = 0x20;
TH1 = -6;
SCON = 0x50;
TR1 = 1;
}
void transmit(unsigned char ch)
{
SBUF = ch;
while(!TI);
TI = 0;
}
unsigned char receive()
{
while(!RI);
RI = 0;
return SBUF;
}
int main(void)
{
unsigned char ch;
serial_init();
while(1)
{
ch = receive();
transmit(ch);
delay(100);
}
}