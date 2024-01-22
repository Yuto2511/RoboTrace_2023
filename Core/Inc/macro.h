/*
 * macro.h
 *
 *  Created on: Jan 17, 2024
 *      Author: youto
 */

#ifndef INC_MACRO_H_
#define INC_MACRO_H_

#define SW_1 0x01
#define SW_2 0x02
#define SW_3 0x03

#define TIM05 0.5		//ms
#define TIM005 0.05 	//ms

#define TIRE 12.65

#define ADC_SENS 6

#define MAX_SPEED 2.5
#define MIN_SPEED 1.8
#define ACC 6

#define CM_COUNT 1200

double Max_Speed;
double Speed_Ref;
double SR, SL;

int Crossing_Flag;

#endif /* INC_MACRO_H_ */
