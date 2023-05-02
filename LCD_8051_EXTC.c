#include<reg51.h>
sbit en=P3^5;
sbit rw=P3^6;
sbit rs=P3^7;
void delay(int t)
{
int i,j;
for (i=0;i<t;i++)
for (j=0;j<1275;j++);
}
void lcdcmd(unsigned char cmd)
{
    P2 = 0;
    rs = 0;
    rw = 0;
    P2 = cmd;
    en = 1;
    delay(10);
    en = 0;
    delay(10);
}
void lcddata(unsigned char ch)
{
    P2 = 0;
    rs = 1;
    rw = 0;
    P2 = ch;
    en = 1;
    delay(10);
    en = 0;
    delay(10);
}
void main()
{
int i;
unsigned char str[4] = {"EXTC"};
    lcdcmd(0x38);
    lcdcmd(0x06);
    lcdcmd(0x0C);
    lcdcmd(0x01);
    lcdcmd(0xC3);
    for(i=0;i<4;i++)
    lcddata(str[i]);
    delay(10);
    while(1);
}
