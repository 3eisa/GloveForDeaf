/*
 * DIO_Private.h
 *
 * Created: 11/3/2022 7:12:11 PM
 *  Author: Lenovo
 */ 



#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#include "DIO_Configuration.h"

void DIO_SetPin_Direction(DIO_PORT PORT, DIO_PIN PIN, DIO_STATE STATE);
void DIO_SetPin_Value(DIO_PORT PORT, DIO_PIN PIN, DIO_STATUS STATUS);
void DIO_TglPin_Value(DIO_PORT PORT, DIO_PIN PIN);

void DIO_SetPort_Direction(DIO_PORT PORT, DIO_STATE STATE);
void DIO_SetPort_Value(DIO_PORT PORT, DIO_STATUS STATUS);
void DIO_TglPort_Value(DIO_PORT PORT);

Uint8_t DIO_GetPin_Value(DIO_PORT PORT, DIO_PIN PIN);
Uint8_t DIO_GetPort_Value(DIO_PORT PORT);

void DIO_SetPin_PullUp(DIO_PORT PORT, DIO_PIN PIN);



#endif /* DIO_PRIVATE_H_ */