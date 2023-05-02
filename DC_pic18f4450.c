// Interface DC motor with PIC18F and Control the motor with switch connected on 
// Pin 3.2. When pin is pressed them, the motor should run in clockwise manner and 
// when the pin is released motor should run in anticlockwise manner. 

#include<PIC18F4550.h>
#define sw1 PORTAbits.RA2
#define m1 PORTCbits.RC1
#define m2 PORTCbits.RC2

void delay(unsigned int time){
    unsigned i,j;
    for(i=0;i<time;i++){
        for(j=0;j<100;j++)
    }
}

int main(){
    TRISAbits.RA2 = 1;
    TRISCbits.RC1 = 0;
    TRISCbits.RC2 = 0;
    ADCON1 = 0x0F;

    while(1){
        if(sw1==0){
            m1=0;
            m2=1;
            delay(1000);
        }
        else{
            m1=1;
            m2=0;
            delay(1000);
        }
    }
    return;
}