/*****************************************************************************
 *  Rosian Rad
 *  File name: joystickPosition.c
 *  Date: 8/3/2016
 *	Description: Resource file of the function that reads the joysticks position and returns a relevant number
 ******************************************************************************/


#include "joystickPosition.h"


uint8_t joystickState = 0;             //Variable used to store the joysticks current position
char sendjoystickPosition = 0;         //Variable used to store the number returned by the function


char joystickPosition()
{
	joystick_init();
	joystickState = joystick_read();

	if ((joystickState & JOYSTICK_DOWN) != 0)
	{
		sendjoystickPosition = 3;  					//Returns 3 when the joystick is pressed down
	}

	else if ((joystickState & JOYSTICK_UP) != 0)
	 {
		sendjoystickPosition = 1;				   //Returns 1 when the joystick is pressed up
	 }

	else if ((joystickState & JOYSTICK_LEFT) != 0)
	 {
		sendjoystickPosition = 4;				   //Returns 4 when the joystick is pressed left
	 }

	else if ((joystickState & JOYSTICK_RIGHT) != 0)
	 {
		sendjoystickPosition = 2;				  //Returns 2 when the joystick is pressed right
	 }

	return sendjoystickPosition;
}

