/*
 * rotary_encoder.h
 *
 *  Created on: Aug 3, 2016
 *      Author: dorin.deac
 */

#ifndef ROTARY_ENCODER_H_
#define ROTARY_ENCODER_H_


#include "type.h"
#include "rotary.h"


#define MIN_VALUE (0)
#define MAX_VALUE (3)

uint8_t rotary_encoder(void); /* Return position of rotary encoder module */

#endif /* ROTARY_ENCODER_H_ */
