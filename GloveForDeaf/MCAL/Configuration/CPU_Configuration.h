/*
 * CPU_Configration.h
 *
 * Created: 11/3/2022 7:10:58 PM
 *  Author: Lenovo
 */ 




#ifndef CPU_CONFIGRATION_H_
#define CPU_CONFIGRATION_H_

#include "Bit_Math.h"
#include "STD_Types.h"


#include "DIO_Private.h"
#include "ADC_Private.h"

#undef F_CPU                //Disable internal clock
#define F_CPU 16000000      //Enable external clock
#include <avr/io.h>         //Get all register the predefined for ATMEGA32
#include <avr/interrupt.h>  //Enable interrupts
#include <util/delay.h>     //Enable function-delay-ms()



#endif /* CPU_CONFIGRATION_H_ */