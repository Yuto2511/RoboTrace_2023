/*
 * memory.h
 *
 *  Created on: Jan 22, 2024
 *      Author: youto
 */

#ifndef INC_MEMORY_H_
#define INC_MEMORY_H_

#include"stm32f4xx_hal.h"
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdint.h>
#include<stdlib.h>

#include "macro.h"
#include "motor.h"
#include "accelerometer.h"
#include "led.h"

double milage, scoretime, gyro;
int data_num;
uint16_t read_curvature[CM_COUNT];
uint32_t read_milage[CM_COUNT];
uint16_t section_curvature[SECTION];
uint32_t section_milage[SECTION];

double route_calculation(uint8_t flag);
void curvature_calucutation();

// Erase Data to Flash
void eraseFlash(uint8_t sector);
// Write Data to Flash
void writeFlash(uint32_t address, uint8_t *data, uint32_t size, uint8_t sector);
// load Data from Flash
void loadFlash(uint32_t address, uint8_t *data, uint32_t size);
void *memcpy(
		void * restrict buf1,
		const void * restrict buf2,
		size_t n
);

extern const uint32_t start_address_sector10;	//sector10 start address
extern const uint32_t end_address_sector10;	//sector10 end address
extern const uint32_t start_address_sector11;	//sector11 start address
extern const uint32_t end_address_sector11;	//sector11 end address

typedef struct
{
	int32_t Omega[CM_COUNT];
	uint32_t speed_R[CM_COUNT];
	uint32_t speed_L[CM_COUNT];
}WRITE_DATA_SECTOR11;

typedef struct
{
	int32_t Omega[CM_COUNT];
	uint32_t speed_R[CM_COUNT];
	uint32_t speed_L[CM_COUNT];
}READ_DATA_SECTOR11;

typedef struct
{
	uint32_t time[CM_COUNT];
}WRITE_DATA_SECTOR10;

typedef struct
{
	uint32_t time[CM_COUNT];
}READ_DATA_SECTOR10;

extern WRITE_DATA_SECTOR11 write_data_sector11;
extern READ_DATA_SECTOR11 read_data_sector11;
extern WRITE_DATA_SECTOR10 write_data_sector10;
extern READ_DATA_SECTOR10 read_data_sector10;



#endif /* INC_MEMORY_H_ */
