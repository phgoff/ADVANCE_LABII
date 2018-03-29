#include <avr/io.h>
int main()
{
unsigned char TB7SEG[] = {
0b00111111, 0b00000110, 0b01011011, 0b01001111,
0b01100110, 0b01101101, 0b01111101, 0b00000111,
0b01111111, 0b01101111, 0b01110111, 0b01111100,
0b00111001, 0b01011110, 0b01111001, 0b01110001,
0b01010010};

signed char display, x1,x2,mode,y;
DDRD = 0xFF; // output
DDRB = 0x00; // input
DDRC = 0x00;
while (1)
{ 
   x1 = PINB;
   x1 &= 0b00000111;
   
   x2 = PINB;
   x2 &= 0b00111000;
   x2 = x2 >> 3;
   
   mode = PINC;
   mode &= 0b00011000;
   mode = mode >> 3;
   
   if(mode == 0)
     y = x1;
   else if(mode == 1)
     y = x2;
   else if(mode == 2)
     y = x1+x2;
   else{
     y = x1-x2;
      if(y<0)
	 y = 16;
     }
      
     
  display = TB7SEG[y];
  PORTD = ~display;
    }
return 0;
}
