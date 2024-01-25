/*
 * motor.c
 *
 *  Created on: Jan 17, 2024
 *      Author: youto
 */

#include "motor.h"
#include "macro.h"

#include <math.h>

void MotorStart()
{
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_1);

	HAL_TIM_Encoder_Start(&htim2,TIM_CHANNEL_ALL);
	HAL_TIM_Encoder_Start(&htim3,TIM_CHANNEL_ALL);
	HAL_TIM_Encoder_Start(&htim4,TIM_CHANNEL_ALL);
}

void motor_R( double duty )
{
	int countorperiod = 0;
	if( duty < 0 ){
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET);
		countorperiod = duty * -1;
	}
	else if( duty >= 0 ){
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_RESET);
		countorperiod = duty;
	}

	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, countorperiod);
}

void motor_L( double duty )
{
	int countorperiod = 0;
	if( duty < 0 ){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
		countorperiod = duty * -1;
	}
	else if( duty >= 0 ){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);
		countorperiod = duty;
	}

	__HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_1, countorperiod);
}

void motor_S( double duty )
{
	int countorperiod = 0;
	if( duty < 0 ){
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET);
		countorperiod = duty * -1;
	}
	else if( duty >= 0 ){
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET);
		countorperiod = duty;
	}

	__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_1, countorperiod);
}


// v = r * 2pi * (3/40960) * (dC/dt)
// m/s
double Speed_R()
{
	int Encoder = (TIM2 -> CNT) - 212483647;
	TIM2 -> CNT = 212483647;
	double speed = (7. * TIRE * M_PI * (double)Encoder) / (40960. * TIM05);
	return speed;
}

double Speed_L()
{
	int Encoder = (TIM3 -> CNT) - 32767;
	TIM3 -> CNT = 32767;
	double speed = (7. * TIRE * M_PI * (double)Encoder) / (40960. * TIM05);
	return speed;
}

double Degree_S()
{
	int initial_degree_value = 32767;
	//int Encoder = (TIM4 -> CNT) - initial_degree_value;
	int Encoder = TIM4 -> CNT;
	double degree = 360 * (Encoder / 65535);
	//return degree;
	return (double)Encoder;
}
