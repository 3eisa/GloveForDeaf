/*
 * LCD_Private.h
 *
 * Created: 3/7/2022 9:04:54 PM
 *  Author: MOHAMED
 */ 


#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

#include "LCD_Configuration.h"


//from mazidi slide 440

void LCD_Initialize(void);
void LCD_Clear(void);
void LCD_Write_Command(uint8_t command);
void LCD_Write_Character(uint8_t character);
void LCD_Write_String(uint8_t* str);
void LCD_Write_Number(uint32_t number);



#endif /* LCD_PRIVATE_H_ */