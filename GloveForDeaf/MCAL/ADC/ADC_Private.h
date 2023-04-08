/*
 * ADC_Private.h
 *
 * Created: 9/30/2022 11:28:00 AM
 *  Author: karim
 */ 


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#include "ADC_Configuration.h"

void ADC_Initialization(ADC_Vref vref, ADC_Prescaler prescaler);
Uint16_t ADC_Read(ADC_Channel channel);



#endif /* ADC_PRIVATE_H_ */