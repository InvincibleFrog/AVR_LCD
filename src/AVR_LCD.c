#include "AVR_LCD.h"
#include <avr/io.h>
#include <util/delay.h>

void lcd_command(unsigned char cmnd)
{
    LCD_DPRT = cmnd; // Set the data port to the command value
    LCD_CPRT &= ~(1<<LCD_RS); // Set RS (Register Select) pin low to indicate command mode
    LCD_CPRT |= (1<<LCD_EN); // Set EN (Enable) pin high to enable the LCD
    _delay_us(1); // Delay for the required pulse width
    LCD_CPRT &= ~(1<<LCD_EN); // Set EN (Enable) pin low to disable the LCD
    _delay_us(100); // Delay for settling time
}

void lcd_data(unsigned char data)
{
    LCD_DPRT = data; // Set the data port to the data value
    LCD_CPRT |= (1<<LCD_RS); // Set RS (Register Select) pin high to indicate data mode
    LCD_CPRT |= (1<<LCD_EN); // Set EN (Enable) pin high to enable the LCD
    _delay_us(1); // Delay for the required pulse width
    LCD_CPRT &= ~(1<<LCD_EN); // Set EN (Enable) pin low to disable the LCD
    _delay_us(100); // Delay for settling time
}

void lcd_init()
{
    LCD_DDDR = 0xFF; // Set all data port pins as output
    LCD_CDDR |= 0x03; // Set control port pins as output (EN, RS)
    LCD_CPRT &= ~(1<<LCD_EN); // Set EN (Enable) pin low to initialize LCD
    _delay_us(2000); // Delay for LCD initialization
    lcd_command(LCD_FUNCTIONSET); // Send command to configure LCD function set
    lcd_command(LCD_CURSOROFF); // Send command to disable cursor
    lcd_command(LCD_DISPLAYCLEAR); // Send command to clear the LCD display
    _delay_us(2000); // Delay after LCD initialization and display clear
}

void lcd_print(char* StringPtr)
{
    unsigned char i =0;
    while (StringPtr[i]!=0)
    {
        lcd_data(StringPtr[i]); // Send each character of the string
        i++; // Increment the counter to move to the next character in the string
    }
}

void lcd_clear()
{
    lcd_command(LCD_DISPLAYCLEAR); // clear display, set cursor position to zero
    _delay_ms(500);
}

void lcd_home()
{
    lcd_command(LCD_RETURNHOME); // clear display, set cursor position to zero
    _delay_ms(500);
}

void lcd_scrollDisplayLeft()
{
    lcd_command(LCD_DISPLAYSHIFTLEFT); // Shifts the entire display to the left
}

void lcd_setCursor(unsigned char col, unsigned char row)
{
    char rowLines[] = {LCD_CURSORLEFTFIRST, LCD_CURSORLEFTSECOND};
    lcd_command(rowLines[row]+col); // Calculate the appropriate command value based on the row and column positions
}

void lcd_blink()
{
    lcd_command(LCD_DISPLAYCONTROL); //Set the cursor blinking
}

void lcd_noBlink()
{
    lcd_command(LCD_SETLCD); //Resets the cursor blinking
}

void lcd_cursor()
{
    lcd_command(LCD_SETLCD); //Sets the cursor on
}

void lcd_noCursor()
{
    lcd_command(LCD_CURSOROFF); //Sets the cursor off
}

void lcd_display()
{
    lcd_command(LCD_CURSOROFF); //Turns on the display
}

void lcd_noDisplay()
{
    lcd_command(LCD_RESETLCD); //Turns off the display
}

void lcd_scrollDisplayRight()
{
    lcd_command(LCD_DISPLAYSHIFTRIGHT); // Shifts the entire display to the right
}

void lcd_autoscroll()
{
    lcd_command(LCD_SHIFTLEFT); // Shifts the contents of the display to the left
}

void lcd_noAutoscroll()
{
    lcd_command(LCD_RETURNHOME); // Displays the contents without shifting
}

void lcd_leftToRight()
{
    lcd_command(LCD_RETURNHOME); //Sets the direction from left to right
}

void lcd_rightToLeft()
{
    lcd_command(LCD_SHIFTRIGHT); //Sets the direction from right to left
    lcd_command(LCD_CURSORDEC); // Decrements the cursor position to the left
}
