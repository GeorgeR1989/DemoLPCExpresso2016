/*****************************************************************************
 *  Rosian Rad
 *  File name: joystickPosition_test.c
 *  Date: 8/5/2016
 *	Description: Resource file used to test the joystick module
 ******************************************************************************/

#include "joystickPosition.h"
#include "joystickPosition_test.h"


int main()
{
	GPIOInit();
	I2CInit( (uint32_t)I2CMASTER, 0 );
	pca9532_init();
	uint8_t output = 1;

	while(1)
	{
		switch(joystickPosition())
		{
		case 1:
			pca9532_setLeds(output<<1, 0xffff);
			break;
		case 2:
			pca9532_setLeds(output<<2, 0xffff);
			break;
		case 3:
			pca9532_setLeds(output<<3, 0xffff);
			break;
		case 4:
			pca9532_setLeds(output<<4, 0xffff);
			break;
		default:
			break;
		}
	}
}
