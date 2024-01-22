/*
 * wrapper.c
 *
 *  Created on: 2024/01/19
 *      Author: youto
 */

#include "wrapper.h"

void init()
{
	IMU_init();
	ADCStart();
	MotorStart();
	Trace_Init();
	stop_init();
	LineTrace_Flag = 0;
	Start_Flag = 0;
	Mode_Flag = 0;
}

void main_loop()
{

	while(1){
		LineTrace_Flag = 0;
		if( switch_get() == SW_1 ){
			Mode_Flag--;
			if(Mode_Flag < 0) Mode_Flag = 9;
		}
		else if( switch_get() == SW_2 ){
			Mode_Flag++;
			if(Mode_Flag > 9) Mode_Flag = 0;
		}
		else if( switch_get() == SW_3 ) break;

		switch(Mode_Flag){
			case 0:
				led_num(0);
				printf("ADC_L -> %f,	ADC_R -> %f,	DEG_S -> %f\r\n", Line_Calib_L, Line_Calib_R, Degree_S());
				break;
			case 1:
				led_num(1);
				printf("Speed_L -> %f,	Speed_R -> %f\r\n", SL, SR);
				break;
			case 2:
				// Run only
				led_num(2);
				break;
			case 3:
				// Run & data flash
				led_num(3);
				break;
			case 4:
				// Speed Control speed1
				led_num(4);
				break;
			case 5:
				// Speed Control speed2
				led_num(5);
				break;
			case 6:
				// Speed Control speed3
				led_num(6);
				break;
			case 7:
				// Speed Control speed4
				led_num(7);
				break;
			case 8:
				// Speed Control speed5
				led_num(8);
				break;
			case 9:
				// Auto Run
				led_num(9);
				break;
			default:
				break;
		}

		HAL_Delay(100);
	}

	HAL_Delay(500);

	//LineTrace
	while(1){
		if(Mode_Flag == 9) break;
		Start_Flag = start_stop();

		switch(State_Flag){
			case 2:
				// Run only
				led_num(2);
				Memory_Flag = 0;
				break;
			case 3:
				// Run & data flash
				led_num(3);
				Memory_Flag = 1;
				break;
			case 4:
				// Speed Control speed1
				led_num(4);
				Memory_Flag = 2;
				Max_Speed = 2.5;
				break;
			case 5:
				// Speed Control speed2
				led_num(5);
				Memory_Flag = 2;
				Max_Speed = 2.5;
				break;
			case 6:
				// Speed Control speed3
				led_num(6);
				Memory_Flag = 2;
				Max_Speed = 2.5;
				break;
			case 7:
				// Speed Control speed4
				led_num(7);
				Memory_Flag = 2;
				Max_Speed = 2.5;
				break;
			case 8:
				// Speed Control speed5
				led_num(8);
				Memory_Flag = 2;
				Max_Speed = 2.5;
				break;
			default:
				LineTrace_Flag = 0;
				break;
		}
		if( Start_Flag == 0 ) LineTrace_Flag = 1;
		else if( Start_Flag == 1 ) LineTrace_Flag = 2;
		else if( Start_Flag == 2 ){
			LineTrace_Flag = 3;
			Trace_Init();
			stop_init();
			Start_Flag = 0;
			Mode_Flag = 0;
			// data write
			led_num(15);
			if(Memory_Flag == 1){

			}
			break;
		}
		HAL_Delay(0.5);
	}

	HAL_Delay(500);

}

void PeriodElapsed_005ms()
{
	adc_getValues();
}


void PeriodElapsed_05ms()
{
	updateValues();
	LineTrace( LineTrace_Flag , Memory_Flag);
	SR = Speed_R();
	SL = Speed_L();
}
