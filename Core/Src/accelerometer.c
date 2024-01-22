/*
 * accelerometer.c
 *
 *  Created on: Jan 17, 2024
 *      Author: youto
 */

#include "accelerometer.h"

double z_gyro()
{
	double z_gyro;
	read_gyro_data();
	z_gyro = zg;
	z_gyro = ((0.01)*(z_gyro) + (1.0 - (0.01))* (pre_zg)); // lowpath filter
	pre_zg = z_gyro;

	return z_gyro;
}
