#include<lpc214x.h>
unsigned char receive()
{
while(!(U0LSR & 0x01)); //wait till receiving data
return (U0RBR);
}
void transmit(unsigned char ch)
{
while(!(U0LSR & 0x20)); //wait till previous data is transmitted
U0THR = ch;
}
int main(void)
{
unsigned char key;
PINSEL0 = 0x00000005;
U0LCR = 0x83; //enabling DLAB to set baudrate
U0DLM = 0x01; //(256*U0DLM+U0DLL) =
PCLK/(16*baudrate);
U0DLL = 135; //baut rate of 9600
U0LSR = 0x01; //Disabling DLAB
while(1)
{
key = receive();
 transmit(key);
}
}