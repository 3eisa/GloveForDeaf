/*
 * Bit_Math.h
 *
 * Created: 11/3/2022 7:10:31 PM
 *  Author: Lenovo
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

//macrolike functions
#define set_bit(reg,bit) reg|=(1<<bit)
#define clr_bit(reg,bit) reg&=~(1<<bit)
#define tgl_bit(reg,bit) reg^=(1<<bit)
#define get_bit(reg,bit) ((reg>>bit)&1)



#endif /* BIT_MATH_H_ */