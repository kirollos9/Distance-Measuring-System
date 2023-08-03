/*
 * ultra.h
 *
 *  Created on: Oct 23, 2021
 *      Author: kirollos Gerges Sobhy
 */

#ifndef ULTRA_H_
#define ULTRA_H_
#include"std_types.h"


void Ultrasonic_init(void);


void Ultrasonic_Trigger(void);


uint16 Ultrasonic_readDistance(void);

void Ultrasonic_edgeProcessing(void);


#endif /* ULTRA_H_ */
