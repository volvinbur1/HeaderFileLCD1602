/* 
This header file is used to simplify working with LCD1602 in 4-bits mode

Standardly header file coordinate the LCD screen using port D and pins PD7-PD4 for data, PD2 - RS, PD3 - EN;
*/

#ifndef LCD4BITS_H_
#define LCD4BITS_H_

#define DATA_DIRETION DDRD
#define DATA_PORT PORTD

#define RS_PIN PD2
#define EN_PIN PD3

#include <util/delay.h>

/*data pins PD7-PD4
RS_PIN PD2 
EN_PIN PD3*/

void LCD_command(unsigned char cmnd) // send commands
{
	DATA_PORT &= ~(1<<RS_PIN); //RS = 0, send command data

	char upper_nibble = cmnd;
	char lower_nibble = cmnd << 4;
	
	upper_nibble &= 0xF0;
	lower_nibble &= 0xF0;
	
	DATA_PORT &= 0x0F;
	DATA_PORT |= upper_nibble; // sending upper nibble 
	DATA_PORT |= (1<<EN_PIN);
	
	_delay_us(150);
	
	DATA_PORT &= ~(1<<EN_PIN);

	_delay_us(150);
	
	DATA_PORT &= 0x0F;
	DATA_PORT |= lower_nibble; // sending lower nibble
	DATA_PORT |= (1<<EN_PIN);
	
	_delay_us(150);
	
	DATA_PORT &= ~(1<<EN_PIN);
	
	_delay_us(150);
}

void LCD_Initialization(void) // initialize a LCD
{
	DATA_DIRETION = 0xFC;
	
	_delay_ms(15);
	
	LCD_command(0x33);
	LCD_command(0x32);
	
	LCD_command(0x28); // initialization for 4-bit mode
	_delay_us(40);
	
	LCD_command(0x0C); // turn the cursor off
	_delay_us(40);
	
	LCD_command(0x06); // force the cursor to the left side of first raw
	_delay_us(40);
	
	LCD_command(0x01); // clear the screen
	_delay_ms(2);	
}

void LCD_dataCharacter(char character) // write a character
{
	DATA_PORT |= (1<<RS_PIN); //RS = 1, send text data
	
	char upper_nibble = character;
	char lower_nibble = character << 4;
		
	upper_nibble &= 0xF0;
	lower_nibble &= 0xF0;
		
	DATA_PORT &= 0x0F;
	DATA_PORT |= upper_nibble; // sending upper nibble
	DATA_PORT |= (1<<EN_PIN);
		
	_delay_us(150);
		
	DATA_PORT &= ~(1<<EN_PIN);

	_delay_us(150);
		
	DATA_PORT &= 0x0F;
	DATA_PORT |= lower_nibble; // sending lower nibble
	DATA_PORT |= (1<<EN_PIN);
		
	_delay_us(150);
		
	DATA_PORT &= ~(1<<EN_PIN);
		
	_delay_us(150);
}

void LCD_dataString(char* string) // write a string of data
{
	for(int i = 0; string[i] != 0; i ++)
	{
		LCD_dataCharacter(string[i]);
	}
}

void LCD_position(int row, int colom) // move the cursor for appropriate place
{
	if(row == 1 && colom >= 1 && colom <= 16)
	{
		LCD_command(0x80);
		_delay_us(40);
	}
	if(row == 2 && colom >= 1 && colom <= 16)
	{
		LCD_command(0xC0);	
		_delay_us(40);
	}
}

void LCD_clear(void) // clear the screen and force a cursor at the left side of first row
{
	LCD_command(0x01); // clear the screen
	_delay_ms(2);
	
	LCD_command(0x80); // force the cursor to the left side of first raw
	_delay_us(40);
}

void LCD_visibleCursor(short value) // 0 - cursor off, 1 - cursor on
{
	if(value == 0)
	{
		LCD_command(0x0C);
		_delay_us(40); 
	}
	else if(value == 1)
	{
		LCD_command(0x0E);
		_delay_us(40);
	}
}


#endif /* LCD4BITS_H_ */