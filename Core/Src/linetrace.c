/*
 * linetrace.c
 *
 *  Created on: 2024/01/19
 *      Author: youto
 */

#include "linetrace.h"

void Trace_Init()
{
	//Time = Start_Flag = 0;
	Speed_Ref = 0;
}

void LineTrace(uint8_t state, uint8_t memory)
{

	degree = Degree_S();
	theta = (180 / M_PI) * degree;
	Turning_Radius = 60 / tan(theta);


	Speed_input_R = SpeedContorol_R( (Turning_Radius - TREAD) * (Speed_Ref / Turning_Radius) );
	Speed_input_L = SpeedContorol_L( (Turning_Radius + TREAD) * (Speed_Ref / Turning_Radius) );
	Stearing_input = StearingContorol( Line_Calib_R - Line_Calib_L );

	switch(state){
		case 0:
			motor_R(0);
			motor_L(0);
			Speed_Ref = 0;
			break;
		case 1:
			motor_R( Speed_input_R );
			motor_L( Speed_input_L );
			motor_S( Stearing_input );
			Speed_Ref += 0.002;
			if(Speed_Ref >= MIN_SPEED) Speed_Ref = MIN_SPEED;
			break;
		case 2:
			motor_R( Speed_input_R );
			motor_L( Speed_input_L );
			motor_S( Stearing_input );
			Speed_Ref = route_calculation(memory);
			break;
		case 3:
			motor_R( Speed_input_R );
			motor_L( Speed_input_L );
			motor_S( Stearing_input );
			Speed_Ref -= 0.004;
			if(Speed_Ref <= 0) Speed_Ref = 0.0;
			break;
		default:
			break;
	}

}
