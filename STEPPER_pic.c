#include<PIC18F4550.h>
#define sw1 PORTAbits.RA2
void delay (unsigned int time)
{
 unsigned int i,j;
 for(i=0;i<time;i++)
 for(j=0;j<100;j++);
}
void main()
{
 TRISC=0;
 TRISAbits.RA2=1;
 TRISAbits.RA3=1;
 ADCON1 = 0x0F;
 unsigned char stepper[8] = {0x01,0x03,0x02,0x06,0x04,0x24,0x20,0x21};
 PORTC = 0x00;
 while(1)
 {
 if(sw1==0)
 {
 for(int i=0;i<8;i++)
 {
 PORTC = stepper[i];
 delay(500);
 } 
 }
 
 else
 {
 for(int i=7;i>=0;i--)
 {
 PORTC = stepper[i];
 delay(500);
 }
 }
 }
 return;
}
