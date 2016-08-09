/*
===============================================================================
 Name        : rotary_encoder.h
 Author      : Dorin-Stefan Deac
 Version     : 1.0
 Date        : 8/3/2016
 Description : ROTARY_ENCODER module - deliver the position of rotary encoder for
 	 	 	   a specified set of positions
===============================================================================
*/

#ifndef ROTARY_ENCODER_H_
#define ROTARY_ENCODER_H_


#include "type.h"
#include "rotary.h"


/* MIN_VALUE and MAX_VALUE represents the limits of the set which will be returned */
#define MIN_VALUE (0)
#define MAX_VALUE (3)
/*Use OVERFLOW when the includes 0 */
#define OVERFLOW  (255)

uint8_t rotary_encoder(void); /* Return position of rotary encoder module */

#endif /* ROTARY_ENCODER_H_ */
