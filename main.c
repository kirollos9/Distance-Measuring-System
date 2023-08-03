/*
 * main.c
 *
 *  Created on: Oct 23, 2021
 *      Author: kirollos Gerges
*/
#include "lcd.h"
#include "ultra.h"
#include<avr/interrupt.h>
#include<util/delay.h>
int main()
{
	SREG|=(1<<7);
	Ultrasonic_init();
	LCD_init();
	LCD_displayString("Distance=   cm");
		while(1)
	{
			uint16 distance;
			distance = Ultrasonic_readDistance();


					LCD_moveCursor(0,9);
					if(distance >= 100)
					{
						LCD_intgerToString(distance);
					}
					else
					{
						LCD_intgerToString(distance);
						LCD_displayCharacter(' ');
					}
	}
	return 0;
}




