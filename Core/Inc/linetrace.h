/*
 * linetrace.h
 *
 *  Created on: 2024/01/19
 *      Author: youto
 */

#ifndef INC_LINETRACE_H_
#define INC_LINETRACE_H_

#include <stdio.h>
#include <math.h>

#include "speed.h"
#include "motor.h"
#include "analog.h"
#include "macro.h"

#define TREAD 50

void Trace_Init();
void LineTrace(uint8_t, uint8_t);

double Speed_input_R, Speed_input_L, Stearing_input, Turning_Radius, theta, degree;


#endif /* INC_LINETRACE_H_ */
