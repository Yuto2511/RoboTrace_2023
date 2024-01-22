/*
 * side_sensor.c
 *
 *  Created on: Jan 17, 2024
 *      Author: youto
 */

#include "side_sensor.h"

void stop_init()
{
	side_r_time = side_l_time = 0;
	side_r_flag = side_l_flag = 0;
	side_r_count = 0;
	Crossing_Flag = 0;
}

int start_stop()
{
	if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_12) == 0) side_r_flag = 1;
	else if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_12) != 0) side_r_flag = 0;

	if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == 0) side_l_flag = 1;
	else if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_12) != 0) side_l_flag = 0;

	if(side_r_flag) side_r_time++;
	if(side_l_flag) side_l_time++;

	if(!side_r_flag && !side_l_flag){
		if( side_r_time - side_l_time >= 20 ) side_r_count += 1;
		else if( side_l_time - side_r_time >= 20);
		else if( abs(side_l_time - side_r_time) < 15 && abs(side_l_time - side_r_time) > 0 ) Crossing_Flag++;
		side_r_time = side_l_time = 0;
	}

	if(side_r_count >= 2) return 2;
	else if(side_r_count >= 1) return 1;
	else return 0;
}
