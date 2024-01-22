/*
 * Speed.c
 *
 *  Created on: Jan 17, 2024
 *      Author: youto
 */

#include "speed.h"


double SpeedContorol_R(double Speed_Ref)
{
	double PGain = 500.0, IGain = 0.0, duty;
	double delta_speed = Speed_Ref + SR;

	speedR_I_buff += delta_speed * TIM05 * 0.001;
	if(speedR_I_buff >= 1000000) speedR_I_buff = 1000000;
	if(speedR_I_buff <= -1000000) speedR_I_buff = -1000000;

	duty = ( delta_speed * PGain ) /*+ ( speedR_I_buff * IGain )*/;

	return duty;
}

double SpeedContorol_L(double Speed_Ref)
{
	double PGain = 500.0, IGain = 0.0, duty;
	double delta_speed = Speed_Ref - SL;

	speedL_I_buff += delta_speed * TIM05 * 0.001;
	if(speedL_I_buff >= 1000000) speedL_I_buff = 1000000;
	if(speedL_I_buff <= -1000000) speedL_I_buff = -1000000;

	duty = ( delta_speed * PGain ) /*+ ( speedL_I_buff * IGain )*/;

	return duty;
}

double banquet_art()
{
	double PGain = 0.50, IGain = 0.0, DGain = 0.0, value;
	double omega = (z_gyro() /16.4) * M_PI / 180;
	double delta = 0. - omega;

	banquet_I_buff += delta * TIM05 * 0.001;
	banquet_D_buff = (banquet_buff - delta) * TIM05 * 0.001;
	banquet_buff = delta;


	value = ( delta * PGain ) + ( banquet_I_buff * IGain ) - ( banquet_I_buff * DGain );

	return value;
}

double StearingContorol( double Delta )
{
	double PGain = 0.1, IGain = 0.0, DGain = 0.0, duty;

	stear_I_buff += Delta * TIM05 * 0.001;
	if(stear_I_buff >= 1000000) stear_I_buff = 1000000;
	if(stear_I_buff <= -1000000) stear_I_buff = -1000000;
	stear_D_buff = (stear_buff - Delta) * TIM05 * 0.001;
	stear_buff = Delta;

	duty = ( Delta * PGain ) + ( stear_I_buff * IGain ) - ( stear_D_buff * DGain );

	return duty;
}
