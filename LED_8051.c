#include<reg51.h>
sbit led = P3^4;
sbit sw1 = P3^2;
sbit sw2 = P3^3;
void delay(int n)
{
int i,j;
for(i=0;i<n;i++)
for(j=0;j<1275;j++);
}
void main()
{
int d = 10;
led = 0;
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