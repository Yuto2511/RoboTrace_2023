/*
 * ICM_20649.h
 *
 *  Created on: Jan 17, 2024
 *      Author: youto
 */

#ifndef INC_ICM_20649_H_
#define INC_ICM_20649_H_

#include "main.h"

extern SPI_HandleTypeDef hspi1;
// IMUから取得したデータ
extern volatile int16_t xa, ya, za; // 加速度(16bitデータ)
extern volatile int16_t xg, yg, zg;	// omega(16bitデータ)

#define CS_RESET HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_RESET)
#define CS_SET   HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_SET)

#ifdef __cplusplus
extern "C" {
#endif

uint8_t read_byte( uint8_t );
void write_byte( uint8_t, uint8_t);
uint16_t IMU_init(void);
void read_gyro_data(void);
void read_accel_data(void);

#ifdef __cplusplus
}
#endif

/*
Gyro		レンジ(dps)	スケールファクター(LSB/dps)
					±500				65.5
					±1000				32.8
					±2000				16.4
					±4000				8.2
Accel		レンジ(g)		スケールファクター(LSB/g)
					±4					8192
					±8					4096
					±16					2048
					±30					1024
*/


#endif /* INC_ICM_20649_H_ */
