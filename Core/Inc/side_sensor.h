/*
 * side_sensor.h
 *
 *  Created on: Jan 17, 2024
 *      Author: youto
 */

#ifndef INC_SIDE_SENSOR_H_
#define INC_SIDE_SENSOR_H_

#include "stm32f4xx_hal.h"
#include "macro.h"
#include <stdlib.h>

int side_r_time, side_l_time, side_r_count, side_r_flag, side_l_flag;

void stop_init();
int start_stop();

#endif /* INC_SIDE_SENSOR_H_ */
