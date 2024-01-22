/*
 * memory.c
 *
 *  Created on: Jan 22, 2024
 *      Author: youto
 */

#include "memory.h"

double route_calculation(uint8_t flag)
{
	milage += ((-SR + SL) / 2) * TIM05; // mm
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
			 write_data_sector11.speed_R[data_num] = -SR * 1000;
			 write_data_sector11.speed_R[data_num] = SL * 1000;
			 write_data_sector10.time[data_num] = scoretime;
			 data_num++;
		 }
		 return MIN_SPEED;
		 break;
	 case 2:
		 return 0;
		 break;
	 default:
		 return 0;
		 break;
	}
}

void curvature_calucutation()
{

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
