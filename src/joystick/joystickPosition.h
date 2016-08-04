/*****************************************************************************
 *  Rosian Rad
 *  File name: joystickPosition.h
 *  Date: 8/3/2016
 *	Description: Header file of the function that reads the joysticks position and returns a relevant number
 ******************************************************************************/

#ifndef JOYSTICKPOSITION_H_
#define JOYSTICKPOSITION_H_

#include "type.h"
#include "gpio.h"
#include "joystick.h"

char joystickPosition(void);  //Returns a relevant number corresponding to the joysticks position

#endif /* JOYSTICKPOSITION_H_ */
