/* Author: Vlad Florica
 * File name: Seven_Segment.c
 * Date:8/4/2016
 * Description:7 Segment Display resource file
 */

#include "DemoLPCExpresso2016.h"


void ledSet(uint8_t rotVal)
{
	uint8_t Displayed_Number=0; // The value which will be displayed on segment display

	if(10 > rotVal)
	{
		Displayed_Number = rotVal + ASCII_Val_0;
		led7seg_setChar(Displayed_Number, 0); // Function which send the value using SPI Protocol to Shift_Register

	}
}
