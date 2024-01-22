/*
 * motor.h
 *
 *  Created on: Jan 17, 2024
 *      Author: youto
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

#include "stm32f4xx_hal.h"

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim8;
extern TIM_HandleTypeDef htim5;

extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;

void MotorStart();

void motor_R( double );
void motor_L( double );
void motor_S( double );

double Speed_R();
double Speed_L();
double Degree_S();

#endif /* INC_MOTOR_H_ */
