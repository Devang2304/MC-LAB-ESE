#include<reg51.h>
sbit dso = P1^2;
void delay(int n)
{
int i;
for (i=0;i<n;i++)
{
TH0 = 0xFA;
TL0 = 0xA4;
TR0 = 1;
while(TF0 == 0);
TR0 = 0;
TF0 = 0;
}
}
void main()
{
int i;
dso=0;
while(1)
{
for(i=20;i<=80;i++)
{
dso = 1;
delay(i);
dso = 0;
delay(100-i);
}
}
}