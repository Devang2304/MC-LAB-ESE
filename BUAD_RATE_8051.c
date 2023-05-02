#include<reg51.h>
#define baudrate 19200
#define clk 11059200UL
int main(void)
{
int i;
unsigned char name[7] = {"DEV OZA"};
TMOD = 0x20;
SCON = 0x40;
TH1 = 256 - clk/(baudrate*32);
TL1 = TH1;
TR1 = 1;
while(1)
{
for(i=0;i<7;i++)
{
SBUF = name[i];
while(TI==0);
TI = 0;
}
}
}