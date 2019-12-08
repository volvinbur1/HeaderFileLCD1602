# HeaderFileLCD1602
This header file with different function for LCD1602A using AVR ATmega328P


Using this set of fuctons you can simplify the procces of creating new projects with LCD screens. This header file was developed in Embedded C for AVR MCU\`s(this one was developed on AVR ATmega328P).
Current version use 4-bit mode for data transfer.
File use DDRD register as an output and PORTD for comunication with LCD screen(PD7-PD4 data pins, PD3 - enable pin, PD2 - Register Select(RS) pin) by default.

There are such fuction as: `LCD_Initialization(void), LCD_command(unsigned char), LCD_dataCharacter(char), LCD_dataString(char*), LCD_position(int, int), LCD_clear(void), LCD_visibleCursor(short)`.

-`LCD_Initialization(void)`
    this function must be called at the start of the program.
    Before using the LCD screen, it always should be initialized.

-`LCD_command(unsigned char)`
    this function execute all understudable for LCD module. The argument gets a command in hexdecimal format
    
-`LCD_dataCharacter(char)`
    this function write a character according its code in ASCII table
    
-`LCD_dataString(char*)`
    this function get a string as an array of the text and write each element one by one
    
-`LCD_position(int, int)`
    this function set a cursor at the received place (the first argumet is a row number(1,2), the second argument is a colom number(1-16)) 

-`LCD_clear(void)`
    this function just remove all text from LCD screen
   
-`LCD_visibleCursor(short)`
    this function turn the cursor on/off (the funtion get the state as an argument(0 - cursor is off, 1 - cursor in on))
    
The usage example is attached(UsingLCD folder)

LCD1602-A datasheet     https://cdn-shop.adafruit.com/datasheets/TC1602A-01T.pdf
