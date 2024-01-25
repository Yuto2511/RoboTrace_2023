/*
 * memory.c
 *
 *  Created on: Jan 22, 2024
 *      Author: youto
 */

#include "memory.h"

double route_calculation(uint8_t flag)
{
	double median, cal_speed, speed_1, speed_2;
	milage += ((SR + SL) / 2) * TIM05; // mm
	cal_speed = (SR + SL) / 2;
	gyro = (z_gyro() / 16.4) * M_PI / 180;
	scoretime += TIM05;

	switch(flag){
	 case 0:
		 milage = data_num = scoretime = 0;
		 return MIN_SPEED;
		 break;
	 case 1:
		 if(milage / 50 >= data_num){
			 write_data_sector11.Omega[data_num] = gyro * 1000;
			 write_data_sector11.speed_R[data_num] = SR * 1000;
			 write_data_sector11.speed_R[data_num] = SL * 1000;
			 write_data_sector10.time[data_num] = scoretime;
			 data_num++;
		 }
		 return MIN_SPEED;
		 break;
	 case 2:
		 if(milage >= (double)(section_milage[data_num])) data_num++;
		 // to curve
		 if(section_curvature[data_num] < section_curvature[data_num+1]){
			 speed_1 = Max_Speed + (double)read_curvature[data_num] * ((MIN_SPEED - Max_Speed) / 10);
			 speed_2 = Max_Speed + (double)read_curvature[data_num+1] * ((MIN_SPEED - Max_Speed) / 10);
			 median = (pow(speed_1, 2) - pow(speed_2, 2)) / (2 * ACC);
			 if(milage < median){
				 cal_speed += ACC * (TIM05/1000);
				 if(cal_speed >= speed_1) cal_speed = speed_1;
			 }
			 else if(milage >= median){
				 cal_speed -= ACC + (TIM05/1000);
				 if(cal_speed <= speed_2) cal_speed = speed_2;
			 }
		 }
		 // to straight
		 else if(section_curvature[data_num] >= section_curvature[data_num+1]){
			 speed_1 = Max_Speed + (double)read_curvature[data_num] * ((MIN_SPEED - Max_Speed) / 10);
			 if(cal_speed > speed_1) cal_speed -= ACC + (TIM05/1000);
			 else cal_speed = speed_1;
		 }
		 return cal_speed;
		 break;
	 default:
		 return 0;
		 break;
	}
}

void curvature_calucutation()
{
	double velocity, milage, angular_rate, curvature;
	int j = 0;

	for(int i = 0; i < CM_COUNT; i++){
		velocity = ( (double)read_data_sector11.speed_L[i] + (double)read_data_sector11.speed_R[i] ) / 2000;
		if(!i) milage = velocity * (double)read_data_sector10.time[i];	// mm
		else milage += velocity * ((double)read_data_sector10.time[i] - (double)read_data_sector10.time[i-1]);	// mm
		//angular_rate = ( (double)write_data_sector11.Omega[i] +
				//(((double)read_data_sector11.speed_R[i] - (double)read_data_sector11.speed_L[i]) / 0.098) ) / 2000;
		angular_rate = ((double)read_data_sector11.speed_R[i] - (double)read_data_sector11.speed_L[i]) / (0.098 * 1000);
		curvature = fabs(angular_rate / velocity);

		if(0 <= curvature && curvature < 1) read_curvature[i] = 0;
		else if(1 <= curvature && curvature < 2) read_curvature[i] = 1;
		else if(2 <= curvature && curvature < 3) read_curvature[i] = 2;
		else if(3 <= curvature && curvature < 4) read_curvature[i] = 3;
		else if(4 <= curvature && curvature < 5) read_curvature[i] = 4;
		else if(5 <= curvature && curvature < 6) read_curvature[i] = 5;
		else if(6 <= curvature && curvature < 7) read_curvature[i] = 6;
		else if(7 <= curvature && curvature < 8) read_curvature[i] = 7;
		else if(8 <= curvature && curvature < 9) read_curvature[i] = 8;
		else read_curvature[i] = 9;

		read_milage[i] = milage;
	}

	for(int i = 1; i < CM_COUNT-1; i++){
		if(read_curvature[i] == read_curvature[i-1] || read_curvature[i] == read_curvature[i+1]);
		else if(read_curvature[i-1] > read_curvature[i+1]) read_curvature[i] = read_curvature[i-1];
		else if(read_curvature[i-1] <= read_curvature[i+1]) read_curvature[i] = read_curvature[i+1];
	}

	for(int i = 0; i < CM_COUNT; i++){
		if(j > SECTION) break;
		if(read_curvature[i] != read_curvature[i+1]){
			section_curvature[j] = read_curvature[i];
			section_milage[j] = read_milage[i];
			j++;
		}
	}

}

// Erase Data to Flash
void eraseFlash(uint8_t sector)
{
	FLASH_EraseInitTypeDef erase;
	erase.TypeErase = FLASH_TYPEERASE_SECTORS;
	if(sector == 10) erase.Sector = FLASH_SECTOR_10;
	else if(sector == 11) erase.Sector = FLASH_SECTOR_11;
	erase.NbSectors = 1;
	erase.VoltageRange = FLASH_VOLTAGE_RANGE_3;

	uint32_t pageError = 0;

	HAL_FLASHEx_Erase(&erase, &pageError);
}

// Write Data to Flash
void writeFlash(uint32_t address, uint8_t *data, uint32_t size, uint8_t sector)
{
	HAL_FLASH_Unlock();
	eraseFlash(sector);

	for(uint32_t add = address; add < (address + size); add++)
	{
		HAL_FLASH_Program(FLASH_TYPEPROGRAM_BYTE, add, *data);
		data++;
	}

	HAL_FLASH_Lock();
}

// load Data from Flash
void loadFlash(uint32_t address, uint8_t *data, uint32_t size)
{
	memcpy(data, (uint8_t*)address, size);
}
