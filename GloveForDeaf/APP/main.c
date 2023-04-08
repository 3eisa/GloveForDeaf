/*
 * GloveForDeaf.c
 *
 * Created: 2/4/2023 6:49:28 PM
 * Author : Lenovo
 */ 

#include "main.h"



int main(void)
{
	//Fingers
	 Uint16_t F1 = 0;
	 Uint16_t F2 = 0;
	 Uint16_t F3 = 0;
	 Uint16_t F4 = 0;
	 Uint16_t F5 = 0;
	 Uint16_t x = 0;

	//lcd init
	LCD_Initialize();
	LCD_Clear();
	
	///avcc
	//prescaler 128
	ADC_Initialization(AVCC, ADC_PRE128);
	
	DIO_SetPin_Direction(DIO_PORTC, DIO_PIN0, DIO_OUTPUT);
	DIO_SetPin_Direction(DIO_PORTC, DIO_PIN1, DIO_OUTPUT);
	DIO_SetPin_Direction(DIO_PORTC, DIO_PIN2, DIO_OUTPUT);
	DIO_SetPin_Direction(DIO_PORTC, DIO_PIN3, DIO_OUTPUT);
	DIO_SetPin_Direction(DIO_PORTC, DIO_PIN4, DIO_OUTPUT);
	DIO_SetPin_Direction(DIO_PORTC, DIO_PIN5, DIO_OUTPUT);
	DIO_SetPin_Value(DIO_PORTC, DIO_PIN5, DIO_HIGH);
	
    while (1) 
    {
		
		_delay_ms(400);
		LCD_Clear(); //clear display every loop
		
		//fingers readings
		
		
		//channel 1
		
		//finger 1
		DIO_SetPin_Value(DIO_PORTC, DIO_PIN0, DIO_HIGH);
		_delay_ms(100);
		x = (ADC_Read(ADC_CH3)*5)/1024;//neglect
		_delay_ms(1);
		F1 = (ADC_Read(ADC_CH3)*5)/1024;
		DIO_SetPin_Value(DIO_PORTC, DIO_PIN0, DIO_LOW);
		
		//finger 2
		DIO_SetPin_Value(DIO_PORTC, DIO_PIN1, DIO_HIGH);
		_delay_ms(100);
		x = (ADC_Read(ADC_CH3)*5)/1024;//neglect
		_delay_ms(1);
		F2 = (ADC_Read(ADC_CH3)*5)/1024;
		DIO_SetPin_Value(DIO_PORTC, DIO_PIN1, DIO_LOW);
		
		//finger 3
		DIO_SetPin_Value(DIO_PORTC, DIO_PIN2, DIO_HIGH);
		_delay_ms(100);
		x = (ADC_Read(ADC_CH3)*5)/1024;//neglect
		_delay_ms(1);
		F3 = (ADC_Read(ADC_CH3)*5)/1024;
		DIO_SetPin_Value(DIO_PORTC, DIO_PIN2, DIO_LOW);
		
		
		//finger 4
		DIO_SetPin_Value(DIO_PORTC, DIO_PIN3, DIO_HIGH);
		_delay_ms(100);
		x = (ADC_Read(ADC_CH3)*5)/1024;//neglect
		_delay_ms(1);
		F4 = (ADC_Read(ADC_CH3)*5)/1024;
		DIO_SetPin_Value(DIO_PORTC, DIO_PIN3, DIO_LOW);
		
		//finger 5
		DIO_SetPin_Value(DIO_PORTC, DIO_PIN4, DIO_HIGH);
		_delay_ms(100);
		x = (ADC_Read(ADC_CH3)*5)/1024;//neglect
		_delay_ms(1);
		F5 = (ADC_Read(ADC_CH3)*5)/1024;
		DIO_SetPin_Value(DIO_PORTC, DIO_PIN4, DIO_LOW);
		
		
		//display finger bend
		LCD_Write_Number(F1);
		LCD_Write_Number(F2);
		LCD_Write_Number(F3);
		LCD_Write_Number(F4);
		LCD_Write_Number(F5);
		
		
		//display lcd
		if(F1==0 && F2==0 && F3==0 && F4==0 && F5==0)
		{
			LCD_Write_Command(0xC0);
			LCD_Write_String((Uint8_t*)"HELLO");
		}
		else if(F1==0 && F2==0 && F3==4 && F4==4 && F5==0)
		{
			LCD_Write_Command(0xC0);
			LCD_Write_String((Uint8_t*)"I LOVE YOU");
		}
		else if(F1==0 && F2==0 && F3==0 && F4==4 && F5==0)
		{
			LCD_Write_Command(0xC0);
			LCD_Write_String((Uint8_t*)"I REALLY LOVE YOU");
		}
		else if(F1==4 && F2==0 && F3==4 && F4==4 && F5==4)
		{
			LCD_Write_Command(0xC0);
			LCD_Write_String((Uint8_t*)"YOU");
		}
		else if(F1==4 && F2==4 && F3==4 && F4==4 && F5==4)
		{
			LCD_Write_Command(0xC0);
			LCD_Write_String((Uint8_t*)"YES");
		}
		
		else if(F1==0 && (F2==1||F2==2||F2==3) && (F3==1 ||F3==2||F3==3) && F4==4 && F5==4)
		{
			LCD_Write_Command(0xC0);
			LCD_Write_String((Uint8_t*)"NO");
		}

		else if((F1==1||F1==2||F1==3) && (F2==1||F2==2||F2==3) && F3==0 && F4==0 && F5==0)
		{
			LCD_Write_Command(0xC0);
			LCD_Write_String((Uint8_t*)"PERFECT");
		}

		else if(F1==0 && F2==4 && F3==4 && F4==4 && F5==4)
		{
			LCD_Write_Command(0xC0);
			LCD_Write_String((Uint8_t*)"GOOD JOB");
		}
		
		else if(F1==4 && (F2==1||F2==2||F2==3) && F3==4 && F4==4 && F5==4)
		{
			LCD_Write_Command(0xC0);
			LCD_Write_String((Uint8_t*)"QESTION?");
		}
		
		else if(F1==4 && (F2==1||F2==2||F2==3) && (F3==1 ||F3==2||F3==3) && F4==4 && F5==4)
		{
			LCD_Write_Command(0xC0);
			LCD_Write_String((Uint8_t*)"QOUTES");
		}
		else
		{
			LCD_Write_Command(0xC0);
			LCD_Write_String((Uint8_t*)"Loading..");
		}
		
		//clean for next run
		F1=0;
		F2=0;
		F3=0;
		F4=0;
		F5=0;
		x = 0;
		
    }
}

