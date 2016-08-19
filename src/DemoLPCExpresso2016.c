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
	uint8_t disp_init= 1;
	uint8_t buzzer_init= 1;
	t = temp_conversion (read_button_status());

	t = temp_conversion (read_button_status());
	while(1)
	{
		switch(rotary_encoder())
		{
		case 0:
			/*Idle state*/
			rgb_stop();
			ledSet(0);
<<<<<<< HEAD
			disp_init= 1;
			buzzer_init= 1;
			stopMusic();
=======
>>>>>>> 8fbbc685ff1ec4b9acdc28c5a667f79e2cfc6dff
			break;

		case 1:
			/*RGB & SOUND*/
			rgbRainbow();
			ledSet(1);
			disp_init= 1;
			buzzer_init= 1;
			//rgb_stop();
			stopMusic();
			break;


		case 2:
					/*Temperature*/
<<<<<<< HEAD
			if(disp_init)
			{
			oled_init();
			disp_init = 0;

			}

			temp_display(t);
			ledSet(2);
			buzzer_init= 1;
			stopMusic();


					/*ADD OLED & TEMP SUPPORT*/
					break;
		case 3:
			if(buzzer_init)
						{
				init_buzzer();
				buzzer_init = 0;
				joystick_buzzer();
						}

			disp_init = 1;
=======
					ledSet(2);
					/*ADD OLED & TEMP SUPPORT*/
					break;

		case 3:
			/*Buzzer*/
			/*ADD BUZZER SUPPORT*/
>>>>>>> 8fbbc685ff1ec4b9acdc28c5a667f79e2cfc6dff
			ledSet(3);

			break;

		default:
			break;

		}
	}
}


