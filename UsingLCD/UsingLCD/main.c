#define F_CPU 16000000UL

#include <avr/io.h>
#include <stdlib.h>
#include "LCD4bits.h"

//#define data_direction DDRD
//#define data_ports PORTD

//#define RS PD2
//#define EN_pin PD3

int main(void)
{
	LCD_Initialization();
	//LCD_dataCharacter('t');
	LCD_dataString("All work well");

	int increments_Amount = 0;
	
    while (1) 
    {
		char showincrementiontimes [16];
		
		itoa(increments_Amount, showincrementiontimes, 10);

		LCD_position(2,1);		
		LCD_dataString("Sure   ");
		LCD_dataString(showincrementiontimes);
		LCD_dataString(" times");
		
		_delay_ms(1000);
		
		increments_Amount++;
    }
}

