#include<reg51.h>
sbit dso = P1^2;
void delay_50_ms()
{
TH0 = 0x4B;
TL0 = 0xFD;
TR0 = 1;
while(TF0 == 0);
TR0 = 0;
TF0 = 0;
}
void delay_20_ms()
{
TH0 = 0xB7;
TL0 = 0xFF;
TR0 = 1;
while(TF0 == 0);
TR0 = 0;
TF0 = 0;
}
void main()
{
int i;
TMOD = 0x01;
dso=0;
while(1)
{
dso = 1;
delay_50_ms();
dso = 0;
delay_50_ms();
for(i=0;i<5;i++)
{
dso = 1;
delay_20_ms();
dso = 0;
delay_20_ms();
}
dso = 1;
delay_50_ms();
dso = 0;
delay_50_ms();
}
}
