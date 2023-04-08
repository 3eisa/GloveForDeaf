/*
* DIO_Interface.h
*
* Created: 11/3/2022 7:11:59 PM
*  Author: Lenovo
*/

#include "DIO_Private.h"

void DIO_SetPin_Direction(DIO_PORT PORT, DIO_PIN PIN, DIO_STATE STATE)
{
	switch(STATE)
	{
		case DIO_OUTPUT:
		switch(PORT)
		{
			case DIO_PORTA:
			set_bit(DDRA, PIN);
			break;
			case DIO_PORTB:
			set_bit(DDRB, PIN);
			break;
			case DIO_PORTC:
			set_bit(DDRC, PIN);
			break;
			case DIO_PORTD:
			set_bit(DDRD, PIN);
			break;
		}
		break;
		case DIO_INPUT:
		switch(PORT)
		{
			case DIO_PORTA:
			clr_bit(DDRA, PIN);
			break;
			case DIO_PORTB:
			clr_bit(DDRB, PIN);
			break;
			case DIO_PORTC:
			clr_bit(DDRC, PIN);
			break;
			case DIO_PORTD:
			clr_bit(DDRD, PIN);
			break;
		}
	}
}

void DIO_SetPin_Value(DIO_PORT PORT, DIO_PIN PIN, DIO_STATUS STATUS)
{
	if(STATUS == DIO_HIGH)
	{
		switch(PORT)
		{
			case DIO_PORTA:
			set_bit(PORTA, PIN);
			break;
			case DIO_PORTB:
			set_bit(PORTB, PIN);
			break;
			case DIO_PORTC:
			set_bit(PORTC, PIN);
			break;
			case DIO_PORTD:
			set_bit(PORTD, PIN);
			break;
		}
	}
	else if(STATUS == DIO_LOW)
	{
		switch(PORT)
		{
			case DIO_PORTA:
			clr_bit(PORTA, PIN);
			break;
			case DIO_PORTB:
			clr_bit(PORTB, PIN);
			break;
			case DIO_PORTC:
			clr_bit(PORTC, PIN);
			break;
			case DIO_PORTD:
			clr_bit(PORTD, PIN);
			break;
		}
	}
}

void DIO_TglPin_Value(DIO_PORT PORT, DIO_PIN PIN)
{
	switch(PORT)
	{
		case DIO_PORTA:
		tgl_bit(PORTA, PIN);
		break;
		case DIO_PORTB:
		tgl_bit(PORTB, PIN);
		break;
		case DIO_PORTC:
		tgl_bit(PORTC, PIN);
		break;
		case DIO_PORTD:
		tgl_bit(PORTD, PIN);
		break;
	}
	
}

void DIO_SetPort_Direction(DIO_PORT PORT, DIO_STATE STATE)
{
	switch(PORT)
	{
		case DIO_PORTA:
		DDRA = STATE;
		break;
		case DIO_PORTB:
		DDRB=STATE;
		break;
		case DIO_PORTC:
		DDRC=STATE;
		break;
		case DIO_PORTD:
		DDRD=STATE;
		break;
	}
}

void DIO_SetPort_Value(DIO_PORT PORT, DIO_STATUS STATUS)
{
	switch (STATUS)
	{
		case DIO_LOW:
		switch(PORT)
		{
			case DIO_PORTA:
			DDRA = 0x00;
			break;
			case DIO_PORTB:
			DDRB = 0x00;
			break;
			case DIO_PORTC:
			DDRC = 0x00;
			break;
			case DIO_PORTD:
			DDRD = 0x00;
			break;
		}
		break;
		case DIO_HIGH:
		switch(PORT)
		{
			case DIO_PORTA:
			DDRA = 0xFF;
			break;
			case DIO_PORTB:
			DDRB = 0xFF;
			break;
			case DIO_PORTC:
			DDRC = 0xFF;
			break;
			case DIO_PORTD:
			DDRD = 0xFF;
			break;
		}
		break;
	}
}

Uint8_t DIO_GetPin_Value(DIO_PORT PORT, DIO_PIN PIN)
{
	uint8_t reading = 0;
	switch(PORT)
	{
		case DIO_PORTA:
		reading = get_bit(PINA, PIN);
		break;
		case DIO_PORTB:
		reading = get_bit(PINB, PIN);
		break;
		case DIO_PORTC:
		reading = get_bit(PINC, PIN);
		break;
		case DIO_PORTD:
		reading = get_bit(PIND, PIN);
		break;
	}
	return reading;
}

void DIO_SetPin_PullUp(DIO_PORT PORT, DIO_PIN PIN)
{
	switch(PORT)
	{
		case DIO_PORTA:
		set_bit(PORTA, PIN);
		break;
		case DIO_PORTB:
		set_bit(PORTB, PIN);
		break;
		case DIO_PORTC:
		set_bit(PORTC, PIN);
		break;
		case DIO_PORTD:
		set_bit(PORTD, PIN);
		break;
	}
}