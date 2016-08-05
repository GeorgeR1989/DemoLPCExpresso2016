/* Author: Vlad Florica
 * File name: Seven_Segment.h
 * Date:8/4/2016
 * Description:7 Segment Display resource file
 */

#include "type.h"
#include "led7seg.h"
#include "stdio.h"
#include "gpio.h"
#include "ssp.h"

#define ASCII_Val_0 (48)

void ledSet(uint8_t value); // Function to write a value on the 7_Seg_Display

