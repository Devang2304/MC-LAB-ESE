#include<lpc214x.h>
#define LCD_PORT 0x00FF0000
#define rs (1<<11)
#define rw (1<<20)
#define en (1<<10)
void delay(int time)
{
for(int i=0;i<time;i++)
for(int j=0;j<100;j++);
}
void lcdcmd(unsigned char cmd)
{
IOCLR1 = LCD_PORT;
IOCLR0 = rs;
IOCLR0 = rw;
IOSET1 = (cmd<<16);
IOSET0 = en;
delay(100);
IOCLR0 = en;
}
void lcddata(unsigned char data)
{
IOCLR1 = LCD_PORT;
IOSET0 = rs;
IOCLR0 = rw;
IOSET1 = (data<<16);
IOSET0 = en;
delay(100);
IOCLR0 = en;
}
void lcdinit()
{
IODIR0 |= rs | en | rw;
IODIR1 |= LCD_PORT;
lcdcmd(0x38);
lcdcmd(0x0C);
lcdcmd(0x06);
lcdcmd(0x01);
delay(100);
}
int main(void)
{
unsigned char str[7] = {"S.P.I.T "};
PINSEL0 = 0;
PINSEL1 = 0;
PINSEL2 = 0;
lcdinit();
lcdcmd(0xC3);
for(int i=0;i<7;i++)
lcddata(str[i]);
while(1);
}
