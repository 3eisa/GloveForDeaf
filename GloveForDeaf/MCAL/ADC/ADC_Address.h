/*
 * ADC_Address.h
 *
 * Created: 9/30/2022 11:27:38 AM
 *  Author: karim
 */ 


#ifndef ADC_ADDRESS_H_
#define ADC_ADDRESS_H_

/*
#define ADMUX  (*(volatile uint8_t*)(0x27))
#define ADCSRA (*(volatile uint8_t*)(0x26))
#define ADCL   (*(volatile uint8_t*)(0x24))
#define ADCH   (*(volatile uint8_t*)(0x25))
#define SFIOR  (*(volatile uint8_t*)(0x))
*/
#define ADC_DT (*(volatile uint16_t*)(0x24)) //n2ra 2 byte

#endif /* ADC_ADDRESS_H_ */