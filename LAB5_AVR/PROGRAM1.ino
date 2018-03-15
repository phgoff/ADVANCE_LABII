#include <avr/io.h>       //input/output - library
int main(void)
{
	unsigned char TB7SEG[] = {
	0b00111111, 0b00000110, 0b01011011, 0b01001111,
	0b01100110, 0b01101101, 0b01111101, 0b00000111,
	0b01111111, 0b01101111, 0b01110111, 0b01111100,
	0b00111001, 0b01011110, 0b01111001, 0b01110001};
	unsigned char DISPLY;
	unsigned char SWITCH;

        DDRD = 0xFF; // output - all 1
	DDRB = 0x00; // input - all 0
	while(1)
	{
		SWITCH = PINB;  // input from PINB
		SWITCH &= 0b01111000; // 0 - 3 => 0b00001111
                SWITCH = SWITCH >> 3;  //shift switch
		DISPLY = TB7SEG[SWITCH];
		PORTD = ~DISPLY; //logic 1 (truth table) to 0 match with hardware
	}
}
