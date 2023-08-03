/*
 * ultra.c
 *
 *  Created on: Oct 23, 2021
 *      Author: Kirollos Gerges
 */

#include"ultra.h"
#include"icu.h"
#include<util/delay.h>
#include"std_types.h"
#include"gpio.h"
uint8 Count = 0;
uint16 time = 0;
void Ultrasonic_init(void)
{
	Icu_ConfigType Config = {F_CPU_8,RISING};
	Icu_init(&Config);//initializing ICU
	Icu_setCallBack(Ultrasonic_edgeProcessing);
	GPIO_setupPinDirection(PORTB_ID,PIN5_ID, PIN_OUTPUT);
}
void Ultrasonic_Trigger(void)
{
	GPIO_writePin(PORTB_ID,PIN5_ID, LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(PORTB_ID,PIN5_ID, LOGIC_LOW);
}
uint16 Ultrasonic_readDistance(void)
{
	uint16 distance =0;
	Ultrasonic_Trigger();
	distance = (uint16)(((float) time)/(58));
	return distance ;
}
void Ultrasonic_edgeProcessing(void)
{
	Count++;
	if(Count==1)
	{
		Icu_clearTimerValue();
		Icu_setEdgeDetectionType(FALLING);
	}
	else if (Count==2)
	{
		time=Icu_getInputCaptureValue();
		Icu_clearTimerValue();
		Icu_setEdgeDetectionType(RISING);
		Count=0;
	}
}




