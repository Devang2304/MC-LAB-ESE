// Interface DC motor with 8051 and control the motor with switch connected on Pin 
// 3.2. When pin is pressed them, the motor should run in clockwise manner and 
// when the pin is released motor should run in anticlockwise manner

#include<reg51.h>
sbit sw1=P3^2;
sbit m1 = P1^0;
sbit m2 = P1^1;
sbit en = P1^4;

voide delay(int time){
    unsigned int i,j;
    for(int i=0;i<time;i++){
        for(int j=0;j<1275;j++)
    }
}

int main(){
    en=1;
    while(1){
        if(sw1=0){
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
}