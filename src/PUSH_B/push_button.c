/*Brumar Florin - Ilie
File name: push_button.c
Date:8/5/2016
Description: push button module implementation file
*/

#include "push_button.h"


                 /*                Local variables                   */

volatile bool button_pressed = FALSE;    

/*............................................................................*/

/* Function name: read_button_status */
/* Description: the related function read the value from the adc channel , where the push button is connected */
/* and return true or false in button_pressed variabile if the button is pressed or not */

/*............................................................................*/
bool read_button_status()
{
	
/* if the button is pressed from the ADC channel 5 we will receive a value witch can be 9, 10 or 11*/

    switch (ADCRead(ADC_CHANNEL))
	{
		case (9):
		{
			button_pressed = TRUE;
			break;
		}
		case (10):
		{
			button_pressed = TRUE;
			break;
		}
		case (11):
		{
			button_pressed = TRUE;
			break;
		}
		default:
		{
			button_pressed = FALSE;
			break;
		}
	}
	return button_pressed;
}

/*.............................................................................*/