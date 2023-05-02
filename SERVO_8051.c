#include<reg51.h>
sbit pwm=P3^4;
void delay(int t)
{
int i,j;
for (i=0;i<t;i++)
for (j=0;j<1275;j++);
}
void delay_1_ms()
{
TH0 = 0xFC;
TL0 = 0x66;
TR0 = 1;
while(TF0 == 0);
TR0 = 0;
TF0 = 0;
}
void delay_1_5_ms()
{
TH0 = 0xFA;
TL0 = 0x99;
TR0 = 1;
while(TF0 == 0);
TR0 = 0;
TF0 = 0;
}
void delay_2_ms()
{
TH0 = 0xF8;
TL0 = 0xCD;
TR0 = 1;
while(TF0 == 0);
TR0 = 0;
TF0 = 0;
}
void delay_19_ms()
{
TH0 = 0xBB;
TL0 = 0x98;
TR0 = 1;
while(TF0 == 0);
TR0 = 0;
TF0 = 0;
}
void delay_18_5_ms()
{
TH0 = 0xBD;
TL0 = 0x65;
TR0 = 1;
while(TF0 == 0);
TR0 = 0;
TF0 = 0;
}
void delay_18_ms()
{
TH0 = 0xBF;
TL0 = 0x32;
TR0 = 1;
while(TF0 == 0);
TR0 = 0;
TF0 = 0;
}
void main()
{
while(1)
{
pwm=1;
delay_1_5_ms();
pwm=0;
delay_18_5_ms();
delay(100);
pwm=1;
delay_2_ms();
pwm=0;
delay_18_ms();
delay(100);
pwm=1;
delay_1_ms();
pwm=0;
delay_19_ms();
delay(100);
}
}