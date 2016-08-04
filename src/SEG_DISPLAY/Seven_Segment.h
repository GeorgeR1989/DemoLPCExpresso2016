/*
 * Seven_Segment.h
 *
 *  Created on: Aug 3, 2016
 *  Author: vlad.florica
 */

#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_

#define ASCII_Val_0 (48)
#include "type.h"
#include "led7seg.h"
#include "timer32.h"
#include "stdio.h"
#include "gpio.h"
#include "ssp.h"

void ledSet(uint8_t value); // Function to write a value on the 7_Seg_Display

#endif /* SEVEN_SEGMENT_H_ */
