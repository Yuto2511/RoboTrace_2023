/*
 * wrapper.h
 *
 *  Created on: 2024/01/19
 *      Author: youto
 */

#ifndef INC_WRAPPER_H_
#define INC_WRAPPER_H_

#include <stdio.h>

#include "stm32f4xx_hal.h"

#include "macro.h"
#include "led.h"
#include "switch.h"
#include "ICM_20649.h"
#include "accelerometer.h"
#include "motor.h"
#include "analog.h"
#include "side_sensor.h"
#include "speed.h"
#include "memory.h"

#include "LineTrace.h"

uint8_t LineTrace_Flag;
uint8_t Start_Flag;
uint8_t Memory_Flag;
uint8_t State_Flag;
uint8_t Mode_Flag;

void init();
void main_loop();
void PeriodElapsed_005ms();
void PeriodElapsed_05ms();

#endif /* INC_WRAPPER_H_ */
