#include<lpc214x.h>
#define led (1<<0)
#define sw1 (1<<1)
#define sw2 (1<<2)
void delay(int time)
{
for(int i=0;i<time;i++)
for(int j=0;j<100;j++);
}
int main(void)
{
PINSEL0 = 0;
IODIR0 |= 0x01;
int d = 0;
while(1)
{
if((IOPIN0&sw1)==0)
{
if(d==100)
d = 10;
else
d += 10;
}
else if((IOPIN0&sw2)==0)
{
if(d==10)
d = 100;
else
d -= 10;
}
else
{
IOSET0 = led;
delay(d);
IOCLR0 = led;
delay(d);
}
}
}