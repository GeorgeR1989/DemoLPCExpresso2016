/*
===============================================================================
 Name        : rotary_encoder.c
 Author      : Dorin-Stefan Deac
 Version     : 1.0
 Date        : 8/3/2016
 Description : ROTARY_ENCODER module implementation
===============================================================================
*/

#include "DemoLPCExpresso2016.h"

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
	static uint8_t ROT_EN__u8rotPos = MIN_VALUE;

	switch(rotary_read())
	{
		case ROTARY_WAIT :
			break;
		case ROTARY_RIGHT :
			ROT_EN__u8rotPos++;
			break;
		case ROTARY_LEFT :
			ROT_EN__u8rotPos--;
			break;
		default :
			/*Intended fallthrough*/
			break;
	}
#ifdef OVERFLOW
	if (OVERFLOW == ROT_EN__u8rotPos)
		ROT_EN__u8rotPos = MAX_VALUE;
#endif
#ifndef OVERFLOW
	if (MIN_VALUE > ROT_EN__u8rotPos)
			ROT_EN__u8rotPos = MAX_VALUE;
#endif
	else if (MAX_VALUE < ROT_EN__u8rotPos)
		ROT_EN__u8rotPos = MIN_VALUE;

	return ROT_EN__u8rotPos;
}

