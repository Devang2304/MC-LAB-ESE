#include<reg51.h>
sbit led = P1^2;
void delay_50_ms()
{
TH0 = 0x4B;
TL0 = 0xFD;
TR0 = 1;
while(TF0 == 0);
TR0 = 0;
TF0 = 0;
}
void delay_100_ms()
{
delay_50_ms();
delay_50_ms();
}
void delay(int n)
{
int i;
for (i=0;i<n;i++)
{
TH0 = 0xFC;
TL0 = 0x66;
TR0 = 1;
while(TF0 == 0);
TR0 = 0;
TF0 = 0;
}
}
void main()
{
int i;
led=0;
while(1)
{
for(i=0;i<=100;i++)
{
led = 1;
delay(i);
led = 0;
delay_100_ms();
}
for(i=100;i>=0;i--)
{
led = 1;
delay(i);
led = 0;
delay_100_ms();
}
}
}
