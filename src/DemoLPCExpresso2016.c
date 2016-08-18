/*****************************************************************************
 *  Rosian Rad
 *  File name: DemoLPCExpresso2016.c
 *  Date: 8/10/2016
 *	Description: Resource file of the main function for the final project
 ******************************************************************************/

#include "DemoLPCExpresso2016.h"
int32_t t = 0;
int main()
{
	DemoLPCExpresso2016_init();

	t = temp_conversion (read_button_status());
	while(1)
	{
		switch(rotary_encoder())
		{
		case 0:
			/*Idle state*/
			ledSet(0);
			break;

		case 1:
			/*RGB & SOUND*/
			rgbRainbow();
			ledSet(1);
			rgb_stop();
			break;


		case 2:
					/*Temperature*/
					ledSet(2);
					/*ADD OLED & TEMP SUPPORT*/
					break;

		case 3:
			/*Buzzer*/
			/*ADD BUZZER SUPPORT*/
			ledSet(3);
			break;

		default:
			break;

		}
	}
}


