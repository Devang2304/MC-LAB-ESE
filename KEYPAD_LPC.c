#include<lpc214x.h>
#define LCD_PORT 0x00FF0000
#define EN 1<<10 //define RS pin    10000000000
#define RS 1<<11 //define EN pin    100000000000
#define RW 1<<20 //define RW pin
#define LCD_SHIFT 16 //shift data by LCD_SHIFT bits
 
#define  Col0 1<<12
#define  Col1 1<<13
#define  Col2 1<<14
#define  Col3 1<<15
#define  Row0 1<<16
#define  Row1 1<<17
#define  Row2 1<<18
#define  Row3 1<<19

unsigned int ROW[]={Row0,Row1,Row2,Row3};
unsigned int COL[]={Col0,Col1,Col2,Col3};
unsigned int KeyCodes[]={ '0','4','8','C',
           '1','5','9','D',
           '2','6','A','E',
           '3','7','B','F' };


void kbddelay(unsigned int time)
{
int i,j;
for(i=0;i<time;i++)
for(j=0;j<100;j++);
}

void kbdInit(void)
{
PINSEL0 &= 0x00FFFFFF; // set the pins function as GPIO.
PINSEL1 &= 0xFFFFFF00;
IODIR0 &= ~0x000FF000;   // FFF00FFF
IODIR0 |= 0x0000F000; // set the direction of pins COL as OUT and ROWS as IN.
IOSET0 = 0x0000F000;
}


unsigned char GetKey(void)
{
unsigned int col,rowdata,count=0;
unsigned char key;


for(col = 0 ; col < 4 ; col++)
{
IOCLR0 = COL[col] ; // set the column line low
rowdata = IOPIN0;
kbddelay(100);
rowdata = IOPIN0;
rowdata >>= 16;

if((rowdata & 0x0F)!=0x0F)
{
for(count = 0; count < 4 ; count++)
{
if((rowdata & 0x01)== 0)
{
key = KeyCodes[(col*4)+ count];
IOSET0 = COL[col] ; // set the column line HIGH
return key;
}
rowdata >>= 1;
}
}
IOSET0 = COL[col] ; // set the column line HIGH
}

return 0;
}

void delay(unsigned int time)
{
int i,j;
for(i=0;i<time;i++)
for(j=0;j<200;j++);
}

void LCD_strobe()   //Enable pulse
{
delay(100);
IOSET0 = EN;
delay(100);
IOCLR0 = EN;
delay(100);
}

void LCD_data(unsigned char ch)   //function to send data
{
IOCLR1 = LCD_PORT;   //clear LCD pins
IOSET1 = ch<<LCD_SHIFT;   //shift data and set only the data bits
IOSET0 = RS;   //RS =1
IOCLR0 = RW;   //RW = 0
LCD_strobe();   //EN pulse
}

void LCD_cmd(unsigned char ch)   //function to send command
{
IOCLR1 = LCD_PORT;
IOSET1 = ch<<LCD_SHIFT;
IOCLR0 = RS;  //RS = 0  
IOCLR0 = RW;  //RW = 0
LCD_strobe();  //EN pulse
}

void LCD_init(void)
{
PINSEL0 &= 0xFF0FFFFF;   //Pins P0.10 and P0.11 as GPIO
PINSEL1 &= 0xFFFFFCFF; //Pin P0.20 as GPIO
PINSEL2 &= 0xFFFFFFF3; //PORT1 as GPIO

IODIR0 |= RS | EN | RW; //set the pins as output
IODIR1 |= LCD_PORT;  

LCD_cmd(0x38); //8bit use both lines
LCD_cmd(0x06); //Entry mode
LCD_cmd(0x0C); //display ON cursor OFF
LCD_cmd(0x01); //Clear display
LCD_cmd(0x80); //cursor at 1st line 1st position
}

void LCD_display(int row, int pos,int length,unsigned char ch[])
{
unsigned char temp;

if(row==1)
{
temp = 0x80 ; //set cursor at 1st line pos position
}
else
{
temp = 0xC0 ; //set cursor at 2nd line pos position
}
LCD_cmd(temp);

for(int i=0;i<length;i++) {
LCD_data(ch[i]);
delay(5000);
}

}

int main(void) {
unsigned char a;
unsigned char word[1];
unsigned char b[] = "KEYPAD";
LCD_init();
kbdInit();

while(1) {
a = GetKey();
word[0] = a;
if ( a != 0) {
LCD_cmd(0x01);
LCD_display(1, 1, 6, b);
LCD_display(2, 1, 1, word);
delay(100);
}
}


}

