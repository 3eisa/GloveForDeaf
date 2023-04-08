/*
* LCD_Interface.c
*
* Created: 3/7/2022 9:05:08 PM
*  Author: MOHAMED
*/

#include "LCD_Private.h"

void LCD_Initialize(void)
{
	DIO_SetPin_Direction(LCD_CTRL_PRT, LCD_RS, LCD_OUT);
	DIO_SetPin_Direction(LCD_CTRL_PRT, LCD_RW, LCD_OUT);
	DIO_SetPin_Direction(LCD_CTRL_PRT, LCD_EN, LCD_OUT);
			  
	DIO_SetPin_Direction(LCD_DATA_PRT, LCD_D4, LCD_OUT);
	DIO_SetPin_Direction(LCD_DATA_PRT, LCD_D5, LCD_OUT);
	DIO_SetPin_Direction(LCD_DATA_PRT, LCD_D6, LCD_OUT);
	DIO_SetPin_Direction(LCD_DATA_PRT, LCD_D7, LCD_OUT);
	
	_delay_ms(2); //3shan mc bta3 kit asra3 mn mc bta3 lcd
	
	LCD_Write_Command(0x33);
	LCD_Write_Command(0x32);
	LCD_Write_Command(0x28);//4-Bit Mode
	LCD_Write_Command(0x01);//Clear Display
	LCD_Write_Command(0x02);//Return Home
	LCD_Write_Command(0x06);//Return Home
	LCD_Write_Command(0x0C);//Display on, Cursor off
	
	_delay_ms(5);
}
void LCD_Clear(void)
{
	LCD_Write_Command(0x01);//Clear Display
}
void LCD_Write_Command(uint8_t command)
{
	DIO_SetPin_Value(LCD_CTRL_PRT, LCD_RS, LCD_LOW);//Choose Control Register
	DIO_SetPin_Value(LCD_CTRL_PRT, LCD_RW, LCD_LOW);//Choose Write on LCD
	DIO_SetPin_Value(LCD_CTRL_PRT, LCD_EN, LCD_LOW);//Disable LCD
	_delay_ms(1);
	//Send High Nibble First
	PORTA = ((command)& 0xF0) | (PORTA & 0x0F);
	//Send High to Low Pulse
	DIO_SetPin_Value(LCD_CTRL_PRT, LCD_EN, LCD_HIGH);//Disable LCD
	_delay_ms(1); //3shan ydmn enha msh noise
	DIO_SetPin_Value(LCD_CTRL_PRT, LCD_EN, LCD_LOW);//Disable LCD
	//Send Low Nibble First
	PORTA = ((command<<4)& 0xF0) | (PORTA & 0x0F);
	//Send High to Low Pulse
	DIO_SetPin_Value(LCD_CTRL_PRT, LCD_EN, LCD_HIGH);//Disable LCD
	_delay_ms(1);
	DIO_SetPin_Value(LCD_CTRL_PRT, LCD_EN, LCD_LOW);//Disable LCD
	_delay_ms(2);
}
void LCD_Write_Character(uint8_t character)
{
		DIO_SetPin_Value(LCD_CTRL_PRT, LCD_RS, LCD_HIGH);//Choose Data Register
		DIO_SetPin_Value(LCD_CTRL_PRT, LCD_RW, LCD_LOW);//Choose Write on LCD
		DIO_SetPin_Value(LCD_CTRL_PRT, LCD_EN, LCD_LOW);//Disable LCD
		_delay_ms(1);
		//Send High Nibble First
		PORTA = ((character)& 0xF0) | (PORTA & 0x0F);
		//Send High to Low Pulse
		DIO_SetPin_Value(LCD_CTRL_PRT, LCD_EN, LCD_HIGH);//Disable LCD
		_delay_ms(1);
		DIO_SetPin_Value(LCD_CTRL_PRT, LCD_EN, LCD_LOW);//Disable LCD
		//Send Low Nibble First
		PORTA = ((character<<4)& 0xF0) | (PORTA & 0x0F);
		//Send High to Low Pulse
		DIO_SetPin_Value(LCD_CTRL_PRT, LCD_EN, LCD_HIGH);//Disable LCD
		_delay_ms(1);
		DIO_SetPin_Value(LCD_CTRL_PRT, LCD_EN, LCD_LOW);//Disable LCD
		_delay_ms(2);
}
void LCD_Write_String(uint8_t* str)
{
	while (*str != '\0')//Termination of any string, NULL character
	{
		LCD_Write_Character(*str);
		_delay_ms(2);
		str++;
	}
}
void LCD_Write_Number(uint32_t number)
{
	char num[10];
	ltoa(number, (uint8_t*)num, 10);  //long to ASCII 
	LCD_Write_String((uint8_t*) num);
}

void LCD_Custom_Char (uint8_t loc, uint8_t *msg)
{
	uint8_t i;
	if(loc<8)
	{
		LCD_Write_Command(0x40 + (loc*8));	/* Command 0x40 and onwards forces the device to point CGRAM address */
		for(i=0;i<8;i++)	/* Write 8 byte for generation of 1 character */
		LCD_Write_Character(msg[i]);
	}
}