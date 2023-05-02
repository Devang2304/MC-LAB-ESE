#include<lpc214x.h>
#include<stdio.h>
unsigned int adcread()
{
unsigned int data;
while(!(AD0GDR&(1<<31)));
data = AD0GDR;
data = (data>>6)&0x3FF;
return data;
}
int main(void)
{
unsigned int x;
PINSEL1 = 1<<24;
IODIR0 = 0x000003FF;
while(1)
{
AD0CR = 0x01200301;
x = adcread();
IOSET0 = x;
IOCLR0 = ~x;
}
}