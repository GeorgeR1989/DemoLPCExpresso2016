/*
 * rotary_encoder.c
 *
 *  Created on: Aug 3, 2016
 *      Author: dorin.deac
 */

#include "rotary_encoder.h"

/*****************************************************************************
** Function name:		rotary_encoder
**
** Descriptions:		Read the rotary position
**
** parameters:			None
**
** Returned value:		uint8_t, rotary encoder position, a value between
** 						0 and 3
**
*****************************************************************************/
uint8_t rotary_encoder(void){
	uint8_t state = 0;
	static uint8_t ch = MIN_VALUE;

	state = rotary_read();

	if (ROTARY_WAIT != state) {
		if (ROTARY_RIGHT == state) {
	    ch++;
	}
	else {
	    ch--;
	}
	if (MAX_VALUE < ch)
	    ch = MIN_VALUE;
	else if (MIN_VALUE > ch)
	    ch = MAX_VALUE;
	}
	return ch;
}

