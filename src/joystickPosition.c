/*
 /*****************************************************************************
 *  Rosian Rad
 *  File name: joystickPosition.c
 *  Date: 8/3/2016
 *	Description: Resource file of the function that reads the joysticks position and returns a relevant number
 ******************************************************************************/


#include "DemoLPCExpresso2016.h"


char joystickPosition()
{
	char sendjoystickPosition = 0;     //Variable used to store the number returned by the function
	joystick_init();


	switch(joystick_read())
	{
	case JOYSTICK_UP:
		sendjoystickPosition = 1;	  //Returns 1 when the joystick is pressed up
		break;
	case JOYSTICK_DOWN:
		sendjoystickPosition = 3;     //Returns 3 when the joystick is pressed down
		break;
	case JOYSTICK_RIGHT:
		sendjoystickPosition = 2;     //Returns 2 when the joystick is pressed right
		break;
	case JOYSTICK_LEFT:
		sendjoystickPosition = 4;     //Returns 4 when the joystick is pressed left
		break;
	default:
		break;
	}

	return sendjoystickPosition;
}
