/*****************************************************************************
 *  Rosian Rad
 *  File name: DemoLPCExpresso2016.c
 *  Date: 8/10/2016
 *	Description: Resource file of the main function for the final project
 ******************************************************************************/

#include "DemoLPCExpresso2016.h"

int main()
{
	DemoLPCExpresso2016_init();

	while(1)
	{
		switch(rotary_encoder())
		{
		case 0:
			/*Idle state*/
			ledSet(0);
			//oled_clearScreen(OLED_COLOR_BLACK);
			break;
		case 1:
			/*Temperature */
			//oled_clearScreen(OLED_COLOR_WHITE); /*Remove after adding oled module*/
			/*temp_display();*/
			ledSet(1);
			rgb_stop();
			break;
		case 2:
			/*RGB*/
			rgbRainbow();
			ledSet(2);
			break;
		case 3:
			/*Buzzer*/
			rgb_stop();
			//oled_clearScreen(OLED_COLOR_WHITE);
			ledSet(3);
			break;
		default:
			break;

		}
	}
}

