/*
 * LCD_Configuration.h
 *
 * Created: 3/7/2022 9:04:40 PM
 *  Author: MOHAMED
 */ 


#ifndef LCD_CONFIGURATION_H_
#define LCD_CONFIGURATION_H_
//Macros
#include "CPU_Configuration.h"
//Renaming Ports
#define LCD_CTRL_PRT DIO_PORTB
#define LCD_DATA_PRT DIO_PORTA

//Renaming Control Pins
#define LCD_RS DIO_PIN1 //Register select
#define LCD_RW DIO_PIN2 //Register read_write
#define LCD_EN DIO_PIN3 //Register enable

//Renaming Data Pins
#define LCD_D0 DIO_PIN0
#define LCD_D1 DIO_PIN1
#define LCD_D2 DIO_PIN2
#define LCD_D3 DIO_PIN3
#define LCD_D4 DIO_PIN4
#define LCD_D5 DIO_PIN5
#define LCD_D6 DIO_PIN6
#define LCD_D7 DIO_PIN7

//Renaming Status
#define LCD_LOW  DIO_LOW
#define LCD_HIGH DIO_HIGH

//Renaming State
#define LCD_OUT  DIO_OUTPUT

#endif /* LCD_CONFIGURATION_H_ */