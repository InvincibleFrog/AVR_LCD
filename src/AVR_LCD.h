#ifndef AVR_LCD_H
#define AVR_LCD_H

#include <stdint.h>

// LCD commands and their corresponding values

#define LCD_SETLCD 0x0E //Display on, cursor on
#define LCD_DISPLAYCLEAR 0x01 //Clear display screen
#define LCD_RETURNHOME 0x02 //Return home
#define LCD_CURSORDEC 0x04 //Decrement cursor
#define LCD_CURSORINC 0x06 //Increment cursor
#define LCD_SHIFTRIGHT 0x05 //Shift display right
#define LCD_SHIFTLEFT 0x07 //Shift display left
#define LCD_DISPLAYCONTROL 0x0F //Display on, cursor blinking
#define LCD_CURSORLEFTFIRST 0x80 //Force cursor to beginning of first line
#define LCD_CURSORLEFTSECOND 0xC0 //Force cursor to beginning of second line
#define LCD_FUNCTIONSET 0x38 //8-bit data, 2 display lines
#define LCD_FUNCTIONSET4 0x28 //4-bit data, 2 display lines
#define LCD_RESETLCD 0x08 //Display off, cursor off
#define LCD_CURSOROFF 0x0C //Display on, cursor off
#define LCD_DISPLAYSHIFTLEFT 0x18 //Shifts the entire display to left
#define LCD_DISPLAYSHIFTRIGHT 0x1C //Shifts the entire display to right

//LCD PORTS and PINS

#define LCD_DPRT PORTD //LCD DATA PORT
#define LCD_DDDR DDRD //LCD DATA DDR
#define LCD_DPIN PIND //LCD DATA PIN
#define LCD_CPRT PORTB //PORT for LCD Control Pins
#define LCD_CDDR DDRB //DDR for LCD Control Pins
#define LCD_CPIN PINB //PIN Reg for LCD Control Pins
#define LCD_RS 0 //LCD RS (RS is connected at PB4)
#define LCD_EN 1 //LCD EN (EN is connected at PB3)

// Function declarations for LCD operations

/**
 * @brief Send a command to the LCD module
 * @param cmnd The command to be sent
 */
void lcd_command(unsigned char cmnd);

/**
 * @brief Send data to the LCD module
 * @param data The data to be sent
 */
void lcd_data(unsigned char data);

/**
 * @brief Initialize the LCD module
 */
void lcd_init(void);

/**
 * @brief Clear the LCD display
 */
void lcd_clear(void);

/**
 * @brief Set the cursor to the home position (upper-left corner)
 */
void lcd_home(void);

/**
 * @brief Set the cursor position on the LCD display
 * @param col The column position (starting from 0) where the cursor should be placed
 * @param row The row position (starting from 0) where the cursor should be placed
 */
void lcd_setCursor(unsigned char col, unsigned char row);

/**
 * @brief Print a string on the LCD display
 * @param StringPtr Pointer to the string to be printed
 */
void lcd_print(char* StringPtr);

/**
 * @brief Turns on the cursor on the LCD display
 */
void lcd_cursor(void);

/**
 * @brief Turns off the cursor on the LCD display
 */
void lcd_noCursor(void);

/**
 * @brief Enable blinking cursor on the LCD display
 */
void lcd_blink(void);

/**
 * @brief Disable blinking cursor on the LCD display
 */
void lcd_noBlink(void);

/**
 * @brief Turn on the display (both display and cursor)
 */

void lcd_display(void);

/**
 * @brief Turn off the display (both display and cursor)
 */
void lcd_noDisplay(void);

/**
 * @brief Scroll the contents of the display to the left
 */
void lcd_scrollDisplayLeft();

/**
 * @brief Scroll the contents of the display to the right
 */
void lcd_scrollDisplayRight();

/**
 * @brief Scrolls the contents of the LCD display continuously to the left
 */
void lcd_autoscroll();

/**
 * @brief Stops the autoscroll feature and displays the contents without scrolling.
 */
void lcd_noAutoscroll();

/**
* @brief Sets the text direction from left to right.
*/
void lcd_leftToRight();

/**
* @brief Sets the text direction from right to left.
*/
void lcd_rightToLeft();

#endif // AVR_LCD_H
