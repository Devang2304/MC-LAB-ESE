#include<lpc214x.h>
/*void set_pll() //to set CCLK = 60MHz
{
PLL0CFG = 0x24; //set up pll for 60MHz, P=2 and M=4(5-
1),P=Fcoc/(2*CCLK),Fcoc=156MHz-320MHz
PLL0CON = 0x01; //PLLE=1 and PLLC=0, enable pll but not connected
PLL0FEED = 0xAA;//feed sequence to configure pll
PLL0FEED = 0X55;
while((PLL0STAT&(1<<10)) == 0); //check whether pll has
configured desired freq. if 1 then process is done
PLL0CON = 0x03; //PLLE=1 and PLLC=1, enable pll connected to CPU
PLL0FEED = 0xAA;//feed sequence to configure pll
PLL0FEED = 0x55;
VPBDIV = 0x01; //to provide same output from pll to timer without any
division, i.e 60MHz to timeer
}*/
void delay_ms(unsigned int time)
{
T0CTCR= 0x00; //select timer and not counter
T0PR = 59999; //prescaler for 1ms in 1 pulse ((60MHz/1kHz)-1)
T0TC = 0; //reset timer
T0TCR = 0x01; //Timer On
while(T0TC<time);
T0TCR = 0x00; //timer off
}
int main(void)
{
VPBDIV = 0x01;
IO0DIR |= 0x01; //P0.0 as o/p
while(1)
{
IOSET0 |= (1<<0);
delay_ms(50);
IOCLR0 |= (1<<0);
delay_ms(50);
for(int i=0;i<5;i++)
{
IOSET0 |= (1<<0);
delay_ms(20);
IOCLR0 |= (1<<0);
delay_ms(20);
}
IOSET0 |= (1<<0);
delay_ms(50);
IOCLR0 |= (1<<0);
delay_ms(50);
}
}