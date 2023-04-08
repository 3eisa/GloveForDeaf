/*
* ADC_Interface.c
*
* Created: 9/30/2022 11:28:10 AM
*  Author: karim
*/

#include "ADC_Private.h"

void ADC_Initialization(ADC_Vref vref, ADC_Prescaler prescaler)
{
	// Choose voltage reference
	switch(vref)
	{
		case AREF:
		clr_bit(ADMUX, REFS1);clr_bit(ADMUX, REFS0);
		break;
		case AVCC:
		clr_bit(ADMUX, REFS1);set_bit(ADMUX, REFS0);
		break;
		case INTERNAL:
		set_bit(ADMUX, REFS1);set_bit(ADMUX, REFS0);
		break;
	}
	// Choose prescaler
	switch (prescaler)
	{
		case ADC_PRE1:
		clr_bit(ADCSRA, ADPS2);clr_bit(ADCSRA, ADPS1);clr_bit(ADCSRA, ADPS0);
		break;
		case ADC_PRE2:
		clr_bit(ADCSRA, ADPS2);clr_bit(ADCSRA, ADPS1);set_bit(ADCSRA, ADPS0);
		break;
		case ADC_PRE4:
		clr_bit(ADCSRA, ADPS2);set_bit(ADCSRA, ADPS1);clr_bit(ADCSRA, ADPS0);
		break;
		case ADC_PRE8:
		clr_bit(ADCSRA, ADPS2);set_bit(ADCSRA, ADPS1);set_bit(ADCSRA, ADPS0);
		break;
		case ADC_PRE16:
		set_bit(ADCSRA, ADPS2);clr_bit(ADCSRA, ADPS1);clr_bit(ADCSRA, ADPS0);
		break;
		case ADC_PRE32:
		set_bit(ADCSRA, ADPS2);clr_bit(ADCSRA, ADPS1);set_bit(ADCSRA, ADPS0);
		break;
		case ADC_PRE64:
		set_bit(ADCSRA, ADPS2);set_bit(ADCSRA, ADPS1);clr_bit(ADCSRA, ADPS0);
		break;
		case ADC_PRE128:
		set_bit(ADCSRA, ADPS2);set_bit(ADCSRA, ADPS1);set_bit(ADCSRA, ADPS0);
		break;
	}
	// ADC Enable
	set_bit(ADCSRA, ADEN);
	// ADC interrupt disable
	clr_bit(ADCSRA, ADIE);
	// ADC auto trigger enable
	set_bit(ADCSRA, ADATE);
	// ADC Right adjust
	clr_bit(ADMUX, ADLAR);
}
Uint16_t ADC_Read(ADC_Channel channel)
{
	uint16_t reading = 0;
	// Choose channel
	switch (channel)
	{
		case ADC_CH0:
		clr_bit(ADMUX, MUX4);clr_bit(ADMUX, MUX3);clr_bit(ADMUX, MUX2);clr_bit(ADMUX, MUX1);clr_bit(ADMUX, MUX0);// 0 0 0 0 0
		break;
		case ADC_CH1:
		clr_bit(ADMUX, MUX4);clr_bit(ADMUX, MUX3);clr_bit(ADMUX, MUX2);clr_bit(ADMUX, MUX1);set_bit(ADMUX, MUX0);// 0 0 0 0 1
		break;
		case ADC_CH2:
		clr_bit(ADMUX, MUX4);clr_bit(ADMUX, MUX3);clr_bit(ADMUX, MUX2);set_bit(ADMUX, MUX1);clr_bit(ADMUX, MUX0);// 0 0 0 1 0
		break;
		case ADC_CH3:
		clr_bit(ADMUX, MUX4);clr_bit(ADMUX, MUX3);clr_bit(ADMUX, MUX2);set_bit(ADMUX, MUX1);set_bit(ADMUX, MUX0);// 0 0 0 1 1
		break;
		case ADC_CH4:
		clr_bit(ADMUX, MUX4);clr_bit(ADMUX, MUX3);set_bit(ADMUX, MUX2);clr_bit(ADMUX, MUX1);clr_bit(ADMUX, MUX0);// 0 0 1 0 0
		break;
		case ADC_CH5:
		clr_bit(ADMUX, MUX4);clr_bit(ADMUX, MUX3);set_bit(ADMUX, MUX2);clr_bit(ADMUX, MUX1);set_bit(ADMUX, MUX0);// 0 0 1 0 1
		break;
		case ADC_CH6:
		clr_bit(ADMUX, MUX4);clr_bit(ADMUX, MUX3);set_bit(ADMUX, MUX2);set_bit(ADMUX, MUX1);clr_bit(ADMUX, MUX0);// 0 0 1 1 0
		break;
		case ADC_CH7:
		clr_bit(ADMUX, MUX4);clr_bit(ADMUX, MUX3);set_bit(ADMUX, MUX2);set_bit(ADMUX, MUX1);set_bit(ADMUX, MUX0);// 0 0 1 1 1
		break;
	}
	// ADC Start conversion 
	set_bit(ADCSRA, ADSC);
	// wait until conversion finish
	while (get_bit(ADCSRA, ADIF) == 1)
	{
		
	}
	reading = ADC_DT;
	
	
	return reading;
}