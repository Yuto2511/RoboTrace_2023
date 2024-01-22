/*
 * switch.c
 *
 *  Created on: Jan 17, 2024
 *      Author: youto
 */

#include "switch.h"

uint16_t switch_get()
{
	uint16_t value = 0;
	if(!HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12)) value |= 0x01;
	else if(!HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_10)) value |= 0x02;
	else if(!HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_2)) value |= 0x03;
	else value |= 0x00;

	return value;
}
